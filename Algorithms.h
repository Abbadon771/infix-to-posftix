#ifndef Algorithms_H
#define Algorithms_H
#include<string>

//convert infix to postfix
std::string convertToPostfix(std::string);
//acquires the value of an operator's precedence
int getPrecedencevalue(char);
//compares the precedence of two values
bool hasHighPreced(char, char);
//calculates the value of the postfix expression
float calculatePostfix(std::string, float, float, float);



#endif