#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "tree.h"
#include "symbol_table.h"

/* 语义分析入口函数 */
void semantic_analysis(Node* root);

/* 错误报告辅助函数 */
void report_error(int type, int lineno, char* msg);

#endif