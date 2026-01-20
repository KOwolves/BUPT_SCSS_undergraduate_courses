#!/bin/sh
for src in `ls ../test/*.bpl`; do
    ../bin/bplc $src
# for src in `ls ../test/*.out`; do
#     rm $src
done