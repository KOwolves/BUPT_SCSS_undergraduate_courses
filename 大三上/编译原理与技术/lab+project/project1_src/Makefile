CC=gcc
LEX=flex
YACC=bison

bin/bplc: syntax.tab.c parse_tree.c
	$(CC) -o ../bin/bplc -lfl -ly syntax.tab.c parse_tree.c

syntax.tab.c syntax.tab.h: syntax.y lex.yy.c parse_tree.h
	$(YACC) -t -d syntax.y

lex.yy.c: lex.l parse_tree.h
	$(LEX) lex.l

parse_tree.out: parse_tree.h parse_tree.c
	$(CC) -g -o tree.out parse_tree.c -D TREE_C_

.PHONY: clean all bplc test

clean:
	@rm -rf bin syntax.tab.c syntax.tab.h lex.yy.c parse_tree.out parse_tree.o test/*.out

all: bin/bplc parse_tree.out

bplc: bin/bplc

test:
	bash ./test.sh