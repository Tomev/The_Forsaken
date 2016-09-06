%code requires
{
	#include "SyntaxTree.hpp"
}

%{
	extern "C"
	{
		//int yylex(void);
		int yyparse(void);	
		void yyerror(char* s);
	} 

	extern int yylex();
	extern char* yytext;

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include <iostream>
	#include "Includes.hpp"
	#include <memory>

	using namespace compiler;


	std::unique_ptr<SyntaxTree> root;

%}
%define api.value.type {compiler::SyntaxTree*}

%start Program

%token		MINUS		IF			WHILE			ASSIGN					PRINT		INTEGER
%token		ADD			SUBSTRACT	VAR				OPEN_PARENTHESIS		CLOSE_PARENTHESIS	FALSE
%token		SEMICOLON	NUL			FORSAKEN_BEGIN	FORSAKEN_END			DIVIDE		EQUAL	LT
%token		OPEN_BRACES				CLOSE_BRACES	MULTIPLY	EXIT		ABSOLUTE	SIN		GT
%token		SQRT 		COS 		NEGATIVE 		REAL		INPUT		TRUE		INICIALIZE

%left 		EQUAL		GT			LT
%left		MINUS		NEGATIVE	SIN		COS 	SQRT 	ABSOLUTE
%left		ADD			SUBSTRACT
%left 		MULTIPLY 	DIVIDE	

%%

/* Symbol			Description																							Action*/

Program				: Function_Main Functions_List																		{ root.reset(new Input($1, $2)); }
					;
						
Functions_List		: /*empty*/																							{ $$ = nullptr; }
					;

Function_Main		: FORSAKEN_BEGIN Statements FORSAKEN_END															{ $$ = new Function_Main($2); }
					;
					
Statements			: Instruction Statements																			{ $$ = new Statements($1, $2); }
					| /*empty*/																							{ $$ = nullptr; }
					;

Instruction			: Computable SEMICOLON																				{ $$ = new Semicolon_Expression($1); }
					| WHILE OPEN_PARENTHESIS Boolean_Operation CLOSE_PARENTHESIS OPEN_BRACES Statements CLOSE_BRACES	{ $$ = new While_Statement($3, $6); }
					| IF OPEN_PARENTHESIS Boolean_Operation CLOSE_PARENTHESIS OPEN_BRACES Statements CLOSE_BRACES		{ $$ = new If_Statement($3, $6); }
					| ASSIGN Var Expression SEMICOLON																	{ $$ = new Semicolon_Expression(new Assign_Statement($2, $3)); }
					| PRINT OPEN_PARENTHESIS Computable CLOSE_PARENTHESIS SEMICOLON										{ $$ = new Semicolon_Expression(new Print_Statement($3)); }
					| INICIALIZE Var Computable SEMICOLON																{ $$ = new Semicolon_Expression(new Initialization_Statement($2, $3)); }
					| INPUT Var	SEMICOLON																				{ $$ = new Semicolon_Expression(new Input_Statement($2)); }
					| EXIT Integer SEMICOLON																			{ $$ = new Semicolon_Expression(new Exit_Statement($2)); }
					;
					
Computable			: Expression																						{ $$ = $1; }
					| Boolean_Operation																					{ $$ = $1; }
					| /*empry*/																							{ $$ = nullptr; }
					;
					
Boolean_Operation	: Bool																								{ $$ = $1; }
					| NEGATIVE OPEN_PARENTHESIS Boolean_Operation CLOSE_PARENTHESIS										{ $$ = new Unary_Expression(new Name(std::string("!(")),$3); }
					| Expression Boolean_Bin_Op Expression																{ $$ = new Binary_Expression($1, $2, $3); }
					| OPEN_PARENTHESIS Boolean_Operation CLOSE_PARENTHESIS												{ $$ = new Parenthesis_Expression($2); }
					| Boolean_Operation EQUAL Bool																		{ $$ = new Binary_Expression($1, new Name(std::string("==")), $3); }
					;
					
Bool				: TRUE																								{ $$ = new Name(std::string("true")); }
					| FALSE																								{ $$ = new Name(std::string("false")); }
					;
					
Boolean_Bin_Op		: EQUAL																								{ $$ = new Name(std::string("==")); }
					| LT																								{ $$ = new Name(std::string("<")); }
					| GT																								{ $$ = new Name(std::string(">")); }
					;

Expression 			: OPEN_PARENTHESIS MINUS Expression CLOSE_PARENTHESIS												{ $$ = new Unary_Expression(new Name(std::string("(-")), $3); }
					| Unary_Operator OPEN_PARENTHESIS Expression CLOSE_PARENTHESIS										{ $$ = new Unary_Expression($1, $3); } 
					| Unary_Operator OPEN_PARENTHESIS Term CLOSE_PARENTHESIS											{ $$ = new Unary_Expression($1, $3); } 
					| Expression Binary_Operator Expression																{ $$ = new Binary_Expression($1, $2, $3); }
					| Unary_Operator OPEN_PARENTHESIS Term CLOSE_PARENTHESIS Binary_Operator Expression					{ $$ = new Binary_Expression($1, $2, $3); }
					| OPEN_PARENTHESIS Expression CLOSE_PARENTHESIS														{ $$ = new Parenthesis_Expression($2); }
					| Term
					;
					
Var					: VAR																								{ $$ = new Name(std::string(yytext)); }
					;
					
Term 				: VAR																								{ $$ = new Name(std::string(yytext)); }
					| Number																							{ $$ = $1; }
					| NUL																								{ $$ = new Name(std::string("0")); }
					;
					
Integer				: INTEGER																							{ $$ = new Name(std::string(yytext)); }
					;
					
Number				: INTEGER																							{ $$ = new Name(std::string(yytext)); }
					| REAL																								{ $$ = new Name(std::string(yytext)); }
					;
					
Unary_Operator		: ABSOLUTE 																							{ $$ = new Name(std::string("abs(")); }
					| SIN 																								{ $$ = new Name(std::string("sin(")); }
					| COS 																								{ $$ = new Name(std::string("cos(")); }
					| SQRT 																								{ $$ = new Name(std::string("sqrt(")); }
					;

Binary_Operator		: ADD																								{ $$ = new Name(std::string("+")); }
					| SUBSTRACT																							{ $$ = new Name(std::string("-")); }
					| MULTIPLY																							{ $$ = new Name(std::string("*")); }
					| DIVIDE																							{ $$ = new Name(std::string("/")); }
					;
%%

void yyerror(char* s)
{
	printf("Error %s\n", s);
	exit(1);
}