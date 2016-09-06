%{
	#include "grammar.tab.h"
	#include "Includes.hpp"
	//int yylineno = 0;
%}

%%

Dark_Lady_Watch_Over_You																	{return FORSAKEN_BEGIN;}

;																							{return SEMICOLON;}
[1-9][0-9]*																					{return INTEGER;}
0																							{return INTEGER;}
[0-9]+\.[0-9]+																				{return REAL;}
May_My_Aim_Be_True																			{return TRUE;}	
Of_Course_Not																				{return FALSE;}

I_Deserve_Clean_Death																		{return EXIT;}
I_Get_What_I_Want																			{return INPUT;}
Rise																						{return INICIALIZE;}
Have_Something_For_Me																		{return ASSIGN;}
Is_There_A_Problem																			{return IF;}
Let_None_Survive																			{return WHILE;}
Speak_Quickly																				{return PRINT;}
A_Long_Dead_Memory																			{return NUL;}
I_Have_No_Time_For_Games																	{return FORSAKEN_END;}

"-"																							{return MINUS;}
Betray																						{return NEGATIVE;}
Absolute																					{return ABSOLUTE;}
[sS][iI][nN]																				{return SIN;}
[cC][oO][sS]																				{return COS;}
[sS][qQ][rR][tT]																			{return SQRT;}

Resurrect																					{return ADD;}
Slaughter																					{return SUBSTRACT;}
Procreate																					{return MULTIPLY;}
Enslave																						{return DIVIDE;}
Join_The_Horde_As_Equals																	{return EQUAL;}
We_Are_The_Forsaken																			{return GT;}
Enemies_Abound																				{return LT;}


"(" 																						{return OPEN_PARENTHESIS;}
")"																							{return CLOSE_PARENTHESIS;}
"{"																							{return OPEN_BRACES;}
"}"																							{return CLOSE_BRACES;}

[a-zA-Z]																					{return VAR;}

[ \t]																						;
[\n]																						{ yylineno++; }
.																							{printf("Lex: Unexpected character %s.\n", yytext ); return 0;}

	
%%

int yywrap(void)
{
	return 1;
}