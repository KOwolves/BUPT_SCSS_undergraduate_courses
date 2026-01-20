#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    PRIMITIVE,
    ARRAY,
    STRUCTURE,
    FUNCTION
} Kind;

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR
} BasicType;

typedef struct Type Type;
typedef struct FieldList FieldList;

struct Type {
    char name[32];
    Kind kind;
    union {
        BasicType primitive;
        struct {
            Type* elem;
            int size;
        } array;
        FieldList* structure;
        struct {             //  函数结构的详细信息
            Type* returnType; // 返回值类型
            FieldList* params;// 参数列表 (复用 FieldList)
            int paramNum;     // 参数个数
        } function;
    } u;
};

struct FieldList {
    char name[32];
    Type* type;
    FieldList* next;
};

/* 辅助函数声明 */
Type* new_primitive_type(BasicType basic);
Type* new_array_type(Type* elem, int size);
Type* new_struct_type(char* name, FieldList* fields);
Type* new_function_type(int paramNum, FieldList* params, Type* returnType); // [新增]
int check_type_equivalence(Type* t1, Type* t2);
void delete_type(Type* t); 

#endif