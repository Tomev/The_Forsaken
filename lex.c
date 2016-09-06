#include <stdio.h>

#include "grammar.tab.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(void)
{
	int token;// = yylex();

	while(token = yylex())
	{
		printf("%d.%s\n", token, yytext);
	}

	return 0;
}