#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "types.h"

#define HASH_TABLE_SIZE 0x3fff // 哈希表大小，使用 16383 大小足够

/* 符号表节点 */
typedef struct SymbolNode {
    char* name;         // 符号名 (变量名/函数名)
    Type* type;         // 符号类型
    struct SymbolNode* next; // 哈希冲突时的链表指针
} SymbolNode;

/* 符号表操作函数声明 */

// 初始化符号表
void init_symbol_table();

// 计算哈希值 (PJW 算法)
unsigned int hash_pjw(char* name);

// 插入符号 (如果成功返回 1，失败/重复定义返回 0)
int insert_symbol(char* name, Type* type);

// 查找符号 (如果找到返回指针，否则返回 NULL)
SymbolNode* lookup_symbol(char* name);

void enter_scope(); // 进入新作用域
void exit_scope();  // 退出当前作用域

#endif