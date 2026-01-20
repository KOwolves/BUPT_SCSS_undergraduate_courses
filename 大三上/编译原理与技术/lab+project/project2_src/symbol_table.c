/* symbol_table.c */
#include "symbol_table.h"

/* 定义哈希表数组 */
SymbolNode* hash_table[HASH_TABLE_SIZE];

typedef struct ScopeList {
    char* name;             // 记录插入的符号名
    int depth;              // 记录该符号所属的深度
    struct ScopeList* next; // 链表指针
} ScopeList;

ScopeList* scope_stack = NULL; // 符号历史栈
int current_depth = 0;         // 当前作用域深度

void init_symbol_table() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    scope_stack = NULL;
    current_depth = 0;
}

unsigned int hash_pjw(char* name) {
    unsigned int val = 0, i;
    for (; *name; ++name) {
        val = (val << 2) + *name;
        if ((i = val & ~HASH_TABLE_SIZE)) 
            val = (val ^ (i >> 12)) & HASH_TABLE_SIZE;
    }
    return val;
}

/* 进入新作用域 */
void enter_scope() {
    current_depth++;
}

/* 退出当前作用域：核心清理逻辑 */
void exit_scope() {
    // 弹出所有属于当前深度的符号
    while (scope_stack && scope_stack->depth == current_depth) {
        // 1. 获取要删除的符号名
        char* name = scope_stack->name;
        unsigned int index = hash_pjw(name);
        
        // 2. 从哈希表中移除该符号 (移除链表头部的节点，因为头插法保证了头部就是最新的)
        SymbolNode* head = hash_table[index];
        if (head && strcmp(head->name, name) == 0) {
            SymbolNode* temp = head;
            hash_table[index] = head->next; // 指向下一个同名符号(如果有)或NULL
            // 释放内存 (注：Type* 通常不在这里释放，因为可能被AST引用)
            free(temp->name);
            free(temp);
        }

        // 3. 从栈中移除记录
        ScopeList* temp_stack = scope_stack;
        scope_stack = scope_stack->next;
        free(temp_stack->name);
        free(temp_stack);
    }
    current_depth--;
}

/* symbol_table.c */

int insert_symbol(char* name, Type* type) {
    // 1. 查重：只检查【当前作用域】是否有同名符号
    ScopeList* s = scope_stack;
    while (s && s->depth == current_depth) {
        if (strcmp(s->name, name) == 0) {
            return 0; // 当前作用域重复定义，报错
        }
        s = s->next;
    }

    // 2. 插入哈希表 (代码不变)
    unsigned int index = hash_pjw(name);
    SymbolNode* new_node = (SymbolNode*)malloc(sizeof(SymbolNode));
    new_node->name = strdup(name);
    new_node->type = type;
    new_node->next = hash_table[index]; 
    hash_table[index] = new_node;

    // 3. 记录到作用域栈 (代码不变)
    ScopeList* new_stack_node = (ScopeList*)malloc(sizeof(ScopeList));
    new_stack_node->name = strdup(name);
    new_stack_node->depth = current_depth;
    new_stack_node->next = scope_stack;
    scope_stack = new_stack_node;

    return 1;
}

SymbolNode* lookup_symbol(char* name) {
    unsigned int index = hash_pjw(name);
    SymbolNode* current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}