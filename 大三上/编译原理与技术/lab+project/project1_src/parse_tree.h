#ifndef TREE_H_
#define TREE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdio.h>

typedef struct Head {
    char *type;
    size_t line_no;
    char *property;
    struct Head *child, *sibling;
} *Node, *Tree;

Node new_node(const char *type, size_t line_no, const char *property, Node child, Node sibling);
void print_tree(FILE *restrict stream, Tree tree, size_t indent);
void empty_tree(Tree tree);

#ifndef ERRLIST_H_
#define ERRLIST_H_

#define LEXEME_ERROR 'A'
#define SYNTAX_ERROR 'B'

enum Error {
    ILLEGAL_CHARSET = LEXEME_ERROR,
    ILLEGAL_HEX     = LEXEME_ERROR,
    ILLEGAL_CHAR    = LEXEME_ERROR,
    ILLEGAL_ID      = LEXEME_ERROR,
    ILLEGAL_OP      = LEXEME_ERROR,
    MISSING_SEMI    = SYNTAX_ERROR,
    MISSING_CLOSING = SYNTAX_ERROR,
    DEF_AFTER_STMT  = SYNTAX_ERROR,
};

#endif

#ifdef __cplusplus
}
#endif

#endif
