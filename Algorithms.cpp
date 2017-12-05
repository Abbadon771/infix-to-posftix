#include "Algorithms.h"
#include<stack>
#include<string>
#include<iostream>

//gives an operator a value to dtermine its precedence
int getPrecedencevalue(char oper)
{
	if (oper == '+' || oper == '-')
	{
		return 1;
	}
	else if (oper == '*' || oper == '/')
	{
		return 2;
	}
	else
	{
		return 0;
	}
}
//compares the precedence of two operators
bool hasHighPreced(char op1, char op2) {
	int op1Prec = getPrecedencevalue(op1);
	int op2Prec = getPrecedencevalue(op2);
	if (op1Prec >= op2Prec)
	{
		return true;
	}
	else {
		return false;
	}

}
std::string convertToPostfix(std::string expression)
{
	int postfixSize = 0;
	std::stack<char> operators;
	std::string postfixExp = "";
	for (int i = 0; i < expression.length(); i++)
	{
		//if their is a space, continue on
		if (expression[i] == ' ') {
			continue;
		}
		//these two 'else if' statments deal with expression of [i] if it is a '(', or ')'
		else if (expression[i] == '(')
		{
			operators.push(expression[i]);
		}
		else if (expression[i] == ')')
		{
			while (!operators.empty() && operators.top() != '(') {
				postfixExp += operators.top();
				operators.pop();
			}
			operators.pop();
		}
		//if expression[i] is an operator
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
		{
			while (!operators.empty() && operators.top() != '(' && hasHighPreced(operators.top(), expression[i]))
			{
				postfixExp += operators.top();
				operators.pop();
			}
			operators.push(expression[i]);
		}
		//if expression[i] is a varaible either x, y or z
		else {
			postfixExp += expression[i];
		}
	}
	//the operators that had lower precedence
	while (!operators.empty()) {
		postfixExp += operators.top();
		operators.pop();
	}

	return postfixExp;

}

//calculates the value of a postfix expression
float calculatePostfix(std::string expression, float x, float y, float z)
{
	std::stack<float> numbers;
	char placeHolder = NULL;
	float xVal = x;
	float yVal = y;
	float zVal = z;
	float num1 = 0.0;
	float num2 = 0.0;
	float sum = 0.0;
	for (int i = 0; i < expression.length(); i++)
	{
		//if you encounter an operator, pop the first two values in the numbers stack, calculate the value
		//then add it to the stack
		if (expression[i] == '+')
		{
			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			sum = num1 + num2;
			numbers.push(sum);
		}
		else if (expression[i] == '-')
		{
			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			sum = num1 - num2;
			numbers.pop();
			numbers.push(sum);
		}
		else if (expression[i] == '*')
		{
			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			sum = num1 * num2;
			numbers.push(sum);
		}
		else if (expression[i] == '/')
		{
			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			sum = num1 / num2;
			numbers.push(sum);
		}
		//if expression[i] is x, y, or z, the program will push its value onto the stack
		else if (expression[i] == 'x')
		{
			numbers.push(xVal);
		}
		else if (expression[i] == 'y')
		{
			numbers.push(yVal);
		}
		else
		{
			numbers.push(zVal);
		}
	}
	return numbers.top();
}


