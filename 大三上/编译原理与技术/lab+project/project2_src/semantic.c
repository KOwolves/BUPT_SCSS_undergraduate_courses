#include "semantic.h"

Type* current_func_return_type = NULL;

/* 类型构造与辅助函数实现 */
Type* new_primitive_type(BasicType basic) {
    Type* t = (Type*)malloc(sizeof(Type));
    t->kind = PRIMITIVE;
    t->u.primitive = basic;
    return t;
}

Type* new_array_type(Type* elem, int size) {
    Type* t = (Type*)malloc(sizeof(Type));
    t->kind = ARRAY;
    t->u.array.elem = elem;
    t->u.array.size = size;
    return t;
}

Type* new_struct_type(char* name, FieldList* fields) {
    Type* t = (Type*)malloc(sizeof(Type));
    t->kind = STRUCTURE;
    if (name) strncpy(t->name, name, 31);
    else t->name[0] = '\0';
    t->u.structure = fields;
    return t;
}

Type* new_function_type(int paramNum, FieldList* params, Type* returnType) {
    Type* t = (Type*)malloc(sizeof(Type));
    t->kind = FUNCTION;
    t->u.function.paramNum = paramNum;
    t->u.function.params = params;
    t->u.function.returnType = returnType;
    return t;
}

/* 类型等价检查：用于表达式匹配、赋值与函数参数检查 */
int check_type_equivalence(Type* t1, Type* t2) {
    if (t1 == NULL || t2 == NULL) return 1; 
    if (t1->kind != t2->kind) return 0;

    if (t1->kind == PRIMITIVE) {
        return t1->u.primitive == t2->u.primitive;
    }
    if (t1->kind == ARRAY) {
        return check_type_equivalence(t1->u.array.elem, t2->u.array.elem);
    }
    if (t1->kind == STRUCTURE) {
        return strcmp(t1->name, t2->name) == 0;
    }
    return 1;
}

/* 树节点辅助函数 */
Node* new_node(char* name, int lineno) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->lineno = lineno;
    node->name = strdup(name);
    node->val.text = NULL;
    node->child = NULL;
    node->next = NULL;
    return node;
}

void report_error(int type, int lineno, char* msg) {
    printf("Error type %d at Line %d: %s\n", type, lineno, msg);
}

/* 语义分析 */
/*
 语义分析入口与遍历函数声明：
  - 下面是遍历 AST 的核心函数原型及实现，负责构建符号表、
    检查声明/赋值/函数调用等语义规则，并报告错误。
*/
void ExtDefList(Node* node);
void ExtDef(Node* node);
Type* Specifier(Node* node);
void CompSt(Node* node, Type* returnType);
void DefList(Node* node, FieldList** fields);
void Stmt(Node* node, Type* returnType);
Type* Exp(Node* node);
void Args(Node* node, FieldList* params);
FieldList* VarDec(Node* node, Type* specifier);
void FunDec(Node* node, Type* returnType, FieldList** params);

void semantic_analysis(Node* root) {
    if (!root) return;
    init_symbol_table();
    if (root->child)
        ExtDefList(root->child);
}

void ExtDefList(Node* node) {
    if (!node) return;
    ExtDef(node->child);
    if (node->child->next)
        ExtDefList(node->child->next);
}

void ExtDef(Node* node) {
    Type* specifierType = Specifier(node->child);
    Node* p = node->child->next;
    while (p) {
        if (strcmp(p->name, "ExtDecList") == 0) {
            Node* temp = p; 
            while (temp) {
                Node* varDec = temp->child;
                FieldList* field = VarDec(varDec, specifierType);
                if (insert_symbol(field->name, field->type) == 0) {
                    report_error(3, varDec->lineno, "Redefined variable");
                }
                if (temp->child->next) temp = temp->child->next->next;
                else break;
            }
        }
        else if (strcmp(p->name, "FunDec") == 0) {
            current_func_return_type = specifierType;
            FieldList* params = NULL;
            FunDec(p, specifierType, &params);
            
            Node* q = p->next;
            if (q && strcmp(q->name, "CompSt") == 0) {
                CompSt(q, specifierType);
            }
            
            exit_scope(); 
            current_func_return_type = NULL;
        }
        p = p->next;
    }
}

Type* Specifier(Node* node) {
    Node* child = node->child;
    if (strcmp(child->name, "TYPE") == 0) {
        if (strcmp(child->val.text, "int") == 0) return new_primitive_type(TYPE_INT);
        if (strcmp(child->val.text, "float") == 0) return new_primitive_type(TYPE_FLOAT);
        if (strcmp(child->val.text, "char") == 0) return new_primitive_type(TYPE_CHAR);
    }
    else if (strcmp(child->name, "StructSpecifier") == 0) {
        Node* stChild = child->child;
        Node* tag = NULL;
        Node* defList = NULL;
        int isDef = 0; 

        while (stChild) {
            if (strcmp(stChild->name, "OptTag") == 0) { tag = stChild; isDef = 1; }
            else if (strcmp(stChild->name, "Tag") == 0) { tag = stChild; }
            else if (strcmp(stChild->name, "DefList") == 0) { defList = stChild; isDef = 1; }
            else if (strcmp(stChild->name, "LC") == 0) { isDef = 1; }
            stChild = stChild->next;
        }

        if (isDef) {
            char* structName = NULL;
            if (tag && tag->child) structName = tag->child->val.text;
            
            FieldList* fields = NULL;
            if (defList) {
                DefList(defList, &fields);
            }
            Type* structType = new_struct_type(structName, fields);

            if (structName) {
                if (lookup_symbol(structName)) {
                    report_error(15, child->lineno, "Redefined struct");
                } else {
                    insert_symbol(structName, structType);
                }
            }
            return structType;
        } else {
            if (tag && tag->child) {
                char* name = tag->child->val.text;
                SymbolNode* sym = lookup_symbol(name);
                if (!sym || sym->type->kind != STRUCTURE) {
                    report_error(17, child->lineno, "Undefined structure");
                    return NULL;
                }
                return sym->type;
            }
        }
    }
    return NULL;
}

void FunDec(Node* node, Type* returnType, FieldList** params) {
    char* funcName = node->child->val.text;

    Type* funcType = new_function_type(0, NULL, returnType);
    
    if (insert_symbol(funcName, funcType) == 0) {
        report_error(4, node->lineno, "Redefined function");
    }
    
    enter_scope();
    
    int paramNum = 0;
    Node* p = node->child->next; 
    
    while(p) {
        if (strcmp(p->name, "VarList") == 0) {
             Node* varList = p;
             while (varList) {
                Node* paramDec = varList->child;
                Type* paramType = Specifier(paramDec->child);
                FieldList* pField = VarDec(paramDec->child->next, paramType);
                
                if (insert_symbol(pField->name, pField->type) == 0) {
                    report_error(3, paramDec->lineno, "Redefined variable in param");
                }

                pField->next = *params;
                *params = pField;
                paramNum++;

                if (varList->child->next) varList = varList->child->next->next;
                else break;
            }
            break;
        }
        p = p->next;
    }

    funcType->u.function.paramNum = paramNum;
    funcType->u.function.params = *params;
}

FieldList* VarDec(Node* node, Type* specifier) {
    if (strcmp(node->child->name, "ID") == 0) {
        FieldList* f = (FieldList*)malloc(sizeof(FieldList));
        strncpy(f->name, node->child->val.text, 31);
        f->type = specifier;
        f->next = NULL;
        return f;
    } else {
        return VarDec(node->child, new_array_type(specifier, node->child->next->next->val.int_val));
    }
}


void CompSt(Node* node, Type* returnType) {
    enter_scope();

    Node* child = node->child->next;
    
    while (child && strcmp(child->name, "RC") != 0) {
        if (strcmp(child->name, "DefList") == 0) {
            DefList(child, NULL);
        }
        else if (strcmp(child->name, "StmtList") == 0) {
            Node* stmtList = child;
            while (stmtList && stmtList->child) {
                Stmt(stmtList->child, returnType);
                stmtList = stmtList->child->next;
            }
        }
        child = child->next;
    }

    exit_scope();
}

void DefList(Node* node, FieldList** fields) {
    while (node) {
        if (strcmp(node->name, "DefList") != 0) break;
        Node* def = node->child;
        Type* type = Specifier(def->child);
        Node* decList = def->child->next;
        
        while (decList) {
            Node* dec = decList->child; 
            Node* varDec = dec->child;
            FieldList* field = VarDec(varDec, type);
            
            if (fields) { 
                FieldList* curr = *fields;
                int dup = 0;
                while(curr) {
                    if (strcmp(curr->name, field->name) == 0) {
                        report_error(15, varDec->lineno, "Redefined field");
                        dup = 1; break;
                    }
                    curr = curr->next;
                }
                if (!dup) {
                    field->next = *fields;
                    *fields = field; 
                }
            }
            else { 
                if (insert_symbol(field->name, field->type) == 0) {
                    report_error(3, varDec->lineno, "Redefined variable");
                }
                if (dec->child->next) { // 初始化
                    Type* expType = Exp(dec->child->next->next);
                    if (!check_type_equivalence(field->type, expType)) {
                        report_error(5, dec->lineno, "Type mismatch for assignment");
                    }
                }
            }
            
            if (decList->child->next) decList = decList->child->next->next;
            else break;
        }
        node = node->child->next;
    }
}

void Stmt(Node* node, Type* returnType) {
    Node* child = node->child;
    if (strcmp(child->name, "Exp") == 0) {
        Exp(child);
    }
    else if (strcmp(child->name, "CompSt") == 0) {
        CompSt(child, returnType);
    }
    else if (strcmp(child->name, "RETURN") == 0) {
        Type* actual = Exp(child->next);
        if (!check_type_equivalence(returnType, actual)) {
            report_error(8, node->lineno, "Type mismatch for return");
        }
    }
    else if (strcmp(child->name, "IF") == 0) {
        Node* exp = child->next->next; 
        Exp(exp);
        Node* stmt1 = exp->next->next; 
        Stmt(stmt1, returnType);
        if (stmt1->next && strcmp(stmt1->next->name, "ELSE") == 0) {
            Stmt(stmt1->next->next, returnType);
        }
    }
    else if (strcmp(child->name, "WHILE") == 0) {
        Exp(child->next->next);
        Stmt(child->next->next->next->next, returnType);
    }
}

Type* Exp(Node* node) {
    Node* child = node->child;
    
    if (strcmp(child->name, "Exp") == 0) {
        if (strcmp(child->next->name, "ASSIGN") == 0) {
            Node* left = child;
            int isLValue = 0;
            if (strcmp(left->child->name, "ID") == 0 && !left->child->next) isLValue = 1;
            else if (left->child->next && strcmp(left->child->next->name, "LB") == 0) isLValue = 1;
            else if (left->child->next && strcmp(left->child->next->name, "DOT") == 0) isLValue = 1;

            if (!isLValue) {
                report_error(6, child->lineno, "The left-hand side of an assignment must be a variable");
                return NULL;
            }
            Type* t1 = Exp(child);
            Type* t2 = Exp(child->next->next);
            if (!check_type_equivalence(t1, t2)) {
                report_error(5, child->lineno, "Type mismatch for assignment");
                return NULL;
            }
            return t1;
        }
        if (child->next && (
            strcmp(child->next->name, "PLUS") == 0 || 
            strcmp(child->next->name, "MINUS") == 0 ||
            strcmp(child->next->name, "STAR") == 0 ||
            strcmp(child->next->name, "DIV") == 0 ||
            strcmp(child->next->name, "RELOP") == 0 ||
            strcmp(child->next->name, "AND") == 0 ||
            strcmp(child->next->name, "OR") == 0)) 
        {
            Type* t1 = Exp(child);
            Type* t2 = Exp(child->next->next);
            if (!t1 || !t2) return NULL;
            if (t1->kind != PRIMITIVE || t2->kind != PRIMITIVE) {
                report_error(7, child->lineno, "Type mismatch for operands");
                return NULL;
            }
            if (t1->u.primitive != t2->u.primitive) {
                report_error(7, child->lineno, "Type mismatch for operands");
                return NULL;
            }
            if (strcmp(child->next->name, "RELOP") == 0 || 
                strcmp(child->next->name, "AND") == 0 || 
                strcmp(child->next->name, "OR") == 0) {
                return new_primitive_type(TYPE_INT); 
            }
            return t1;
        }
        if (strcmp(child->next->name, "LB") == 0) {
            Type* t1 = Exp(child);
            Type* t2 = Exp(child->next->next);
            
            // 优先处理空指针，防止级联报错或段错误
            if (!t1) return NULL; 
            
            if (t1->kind != ARRAY) {
                report_error(10, child->lineno, "Not an array");
                return NULL;
            }
             if (!t2 || t2->kind != PRIMITIVE || t2->u.primitive != TYPE_INT) {
                 report_error(12, child->lineno, "Array index is not an integer");
                 return t1->u.array.elem; 
             }
             return t1->u.array.elem;
        }
        if (strcmp(child->next->name, "DOT") == 0) {
            Type* t1 = Exp(child);
            if (!t1) return NULL; 
            
            if (t1->kind != STRUCTURE) {
                report_error(13, child->lineno, "Illegal use of .");
                return NULL;
            }
            char* fieldName = child->next->next->val.text;
            FieldList* f = t1->u.structure;
            while(f) {
                if (strcmp(f->name, fieldName) == 0) return f->type;
                f = f->next;
            }
            report_error(14, child->lineno, "Non-existent field");
            return NULL;
        }
    }
    else if (strcmp(child->name, "LP") == 0) {
        return Exp(child->next);
    }
    else if (strcmp(child->name, "MINUS") == 0 || strcmp(child->name, "NOT") == 0) {
        return Exp(child->next);
    }
    else if (strcmp(child->name, "ID") == 0 && child->next) {
        char* name = child->val.text;
        SymbolNode* sym = lookup_symbol(name);
        if (!sym) {
            report_error(2, child->lineno, "Undefined function");
            return NULL;
        }
        if (sym->type->kind != FUNCTION) {
            report_error(11, child->lineno, "Not a function");
            return NULL;
        }
        if (strcmp(child->next->next->name, "Args") == 0) {
            Args(child->next->next, sym->type->u.function.params);
        } else {
            if (sym->type->u.function.params != NULL) 
                report_error(9, child->lineno, "Arguments mismatch");
        }
        return sym->type->u.function.returnType;
    }
    else if (strcmp(child->name, "ID") == 0) {
        SymbolNode* sym = lookup_symbol(child->val.text);
        if (!sym) {
            report_error(1, child->lineno, "Undefined variable");
            return NULL;
        }
        return sym->type;
    }
    else if (strcmp(child->name, "INT") == 0) return new_primitive_type(TYPE_INT);
    else if (strcmp(child->name, "FLOAT") == 0) return new_primitive_type(TYPE_FLOAT);

    return NULL;
}

void Args(Node* node, FieldList* params) {
    Node* temp = node;
    FieldList* p = params;
    while(temp) {
        if (!p) {
            report_error(9, node->lineno, "Too many arguments");
            return;
        }
        Type* t = Exp(temp->child);
        if (!check_type_equivalence(t, p->type)) {
            report_error(9, node->lineno, "Arguments mismatch");
            return;
        }
        p = p->next;
        if (temp->child->next) temp = temp->child->next->next;
        else temp = NULL;
    }
    if (p != NULL) {
        report_error(9, node->lineno, "Too few arguments");
    }
}