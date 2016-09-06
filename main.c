#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory>
#include "Includes.hpp"
#include <iostream>
#include "SyntaxTree.hpp"

extern "C"
{
	int yylex();
	int yyparse();	
	void yyerror(char* s);
}

extern int yylineno;
extern std::unique_ptr<compiler::SyntaxTree> root;

int main ()
{
	int result = yyparse();

	/*if(result == 0)
		printf("\nInput is valid.\n");
	else
		printf("\nInput is not valid.\n");

	printf("Line number: %d.\n\n", ++yylineno);
	*/
	
	std::cout << root->toCode();

	return result;
}