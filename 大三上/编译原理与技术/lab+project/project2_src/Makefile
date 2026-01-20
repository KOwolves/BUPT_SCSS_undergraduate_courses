# 编译器和工具
CC = gcc
BISON = bison
FLEX = flex
CFLAGS = -g -w

# 目标文件
TARGET = bin/bplc
OBJS = syntax.tab.o lex.yy.o semantic.o symbol_table.o

# 默认目标
all: $(TARGET)

# 链接生成可执行文件
$(TARGET): $(OBJS)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lfl

# 编译 Bison 文件
syntax.tab.c syntax.tab.h: syntax.y
	$(BISON) -d syntax.y

syntax.tab.o: syntax.tab.c
	$(CC) $(CFLAGS) -c syntax.tab.c

# 编译 Flex 文件
lex.yy.c: lex.l syntax.tab.h
	$(FLEX) lex.l

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c

# 编译 C 源码
semantic.o: semantic.c semantic.h tree.h types.h symbol_table.h
	$(CC) $(CFLAGS) -c semantic.c

symbol_table.o: symbol_table.c symbol_table.h types.h
	$(CC) $(CFLAGS) -c symbol_table.c

# 清理
clean:
	rm -f $(TARGET) *.o syntax.tab.* lex.yy.c

.PHONY: all clean