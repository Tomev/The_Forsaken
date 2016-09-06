%{
	#include "grammar.tab.h"
	#include "Includes.hpp"
	//int yylineno = 0;
%}

%%

Dark_Lady_Watch_Over_You																	{ printf("Lex: BEGIN\n"); return FORSAKEN_BEGIN;}

;																							{ printf("Lex: SEMICOLON\n"); return SEMICOLON;}
[1-9][0-9]*																					{ printf("Lex: INTEGER\n"); return INTEGER;}
0																							{ printf("Lex: ZERO\n"); return INTEGER;}
[0-9]+\.[0-9]+																				{ printf("Lex: REAL\n"); return REAL;}
May_My_Aim_Be_True																			{ printf("Lex: TRUE\n"); return TRUE;}	
Of_Course_Not																				{ printf("Lex: FALSE\n"); return FALSE;}

I_Deserve_Clean_Death																		{ printf("Lex: EXIT\n"); return EXIT;}
I_Get_What_I_Want																			{ printf("Lex: INPUT\n"); return INPUT;}
Rise																						{ printf("Lex: INICIALIZE\n"); return INICIALIZE;}
Have_Something_For_Me																		{ printf("Lex: ASSIGN\n"); return ASSIGN;}
Is_There_A_Problem																			{ printf("Lex: IF\n"); return IF;}
Let_None_Survive																			{ printf("Lex: WHILE\n"); return WHILE;}
Speak_Quickly																				{ printf("Lex: PRINT\n"); return PRINT;}
A_Long_Dead_Memory																			{ printf("Lex: NUL\n"); return NUL;}
I_Have_No_Time_For_Games																	{ printf("Lex: END\n"); return FORSAKEN_END;}

"-"																							{ printf("Lex: MINUS\n"); return MINUS;}
Betray																						{ printf("Lex: NEGATIVE\n"); return NEGATIVE;}
Absolute																					{ printf("Lex: ABSOLUTE\n"); return ABSOLUTE;}
[sS][iI][nN]																				{ printf("Lex: SIN\n"); return SIN;}
[cC][oO][sS]																				{ printf("Lex: COS\n"); return COS;}
[sS][qQ][rR][tT]																			{ printf("Lex: SQRT\n"); return SQRT;}

Resurrect																					{ printf("Lex: ADD\n"); return ADD;}
Slaughter																					{ printf("Lex: SUBSTRACT\n"); return SUBSTRACT;}
Procreate																					{ printf("Lex: MULTIPLY\n"); return MULTIPLY;}
Enslave																						{ printf("Lex: DIVIDE\n"); return DIVIDE;}
Join_The_Horde_As_Equals																	{ printf("Lex: EQUAL\n"); return EQUAL;}
We_Are_The_Forsaken																			{ printf("Lex >"); return GT;}
Enemies_Abound																				{ printf("Lex <"); return LT;}


"(" 																						{ printf("Lex: (\n"); return OPEN_PARENTHESIS;}
")"																							{ printf("Lex: )\n"); return CLOSE_PARENTHESIS;}
"{"																							{ printf("Lex: {\n"); return OPEN_BRACES;}
"}"																							{ printf("Lex: }\n"); return CLOSE_BRACES;}

[a-zA-Z]																					{ printf("Lex: VAR\n"); return VAR;}

[ \t]																						;
[\n]																						{ yylineno++; }
.																							{printf("Lex: Unexpected character %s.\n", yytext ); return 0;}

	
%%

int yywrap(void)
{
	return 1;
}