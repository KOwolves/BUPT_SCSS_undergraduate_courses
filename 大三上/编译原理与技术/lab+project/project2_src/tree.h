#ifndef TREE_H
#define TREE_H

/* 树节点结构定义 */
typedef struct Node {
    int lineno;         // 行号
    char* name;         // 节点类型名称
    
    /* 语义值 */
    union {
        char* text;     // 存储标识符名字 (ID) 或 类型名 (TYPE)
        int int_val;    // 存储整型字面量
        float float_val;// 存储浮点型字面量
    } val;

    /* 树形结构指针 */
    struct Node* child;
    struct Node* next;
} Node;

/* 创建新节点 */
Node* new_node(char* name, int lineno);

#endif