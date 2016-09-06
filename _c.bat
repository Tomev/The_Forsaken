bis3 -d grammar.y

flex3 --nounput lex.l

g++ -std=gnu++11 -Wall -Wno-write-strings lex.yy.c grammar.tab.c main.c -o _cCompiler