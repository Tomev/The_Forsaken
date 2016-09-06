#define A_Long_Dead_Memory 0
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(void){
float a = 0.0;
float b = 0.0;
float c = 0.0;
float D = 0.0;
std::cin >> a;
std::cin >> b;
std::cin >> c;
std::cout << std::endl;
D=( b*b-( 4*a*c ) );
if(D<0)
{
std::cout << false;
}
if(D==0)
{
if(a==0)
{
if(!(c==0))
{
std::cout << false;
}
std::cout << true;
}
if(!(a==0))
{
float x = 0.0;
x=( (-b)/( 2*a ) );
std::cout << x;
std::cout << std::endl;
std::cout << x;
}
}
if(D>0)
{
if(a==0)
{
float x = 0.0;
x=( (-c)/b );
std::cout << x;
std::cout << std::endl;
std::cout << x;
}
if(!(a==0))
{
float x = 0.0;
float y = 0.0;
x=( ( (-b)-sqrt(D) )/( 2*a ) );
y=( ( (-b)+sqrt(D) )/( 2*a ) );
std::cout << x;
std::cout << std::endl;
std::cout << y;
}
}
std::cout << std::endl;
std::cout << std::endl;
system("PAUSE");
return 0;
}