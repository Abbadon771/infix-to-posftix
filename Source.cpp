//CPSC 3383/CPSC 5399: Language Structure
//Fall 2017
//Project 1: A Command Interpreter of Arithmetic Expressions
//Name: James Norcross
//T-number: 9666
/*Desctiption of the program:  the follwing program is a command interpreter that has a user input an arithmetic expression and 2-3 
varaibles and evaluates it.  The program turns the infix expression into a postfix expression, acquires the varaibles a user inputs
the is calculates the final value.*/
//Date Written: 09/10/2017
//Date Revised: 09/17/2017

#include<string>
#include<iostream>
#include "Algorithms.h"


using namespace std;


float returnValue(char* varia, int sizeOf)
{
	float sum = 0.0;
	char value;
	int bufferSize = sizeOf - 4;
	char* buffer = new char[bufferSize];
	int counter = 0;
	int i = 0;
	int l = 0;
	for (int i = 0; i < sizeOf; i++)
	{
		if (varia[i] != 'x' && varia[i] != 'y' && varia[i] != 'z' && varia[i] != char(32) && varia[i] != '=')
		{
			l = i;
			break;
		}
	}

	for (int m = 0; m < bufferSize; m++)
	{
		buffer[m] = varia[l];
		l = l + 1;
	}

	// get the integer part of the value
	char character = NULL;
	int decimal = 0;
	int k = 0;
	for (int j = 0; j < bufferSize; j++)
	{
		character = buffer[k];
		if (buffer[j] == '.')
		{
			decimal = j;
			break;
		}
		else {
			sum = sum * 10.0 + character - '0';
		}
		k = k + 1;
	}



	// get the decimal part of the value
	float deciValue = 0.0;

	for (int l = bufferSize - 1; l > decimal; l--)
	{
		character = buffer[l];
		deciValue = deciValue * 1 / 10.0 + (character - '0') * 1 / 10.0;
	}
	// combine them together
	sum = sum + deciValue;

	return sum;

}
int main() {
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
	float totalVal = 0.0;
	int testRun = 0;
	int numVariables;
	int varSize;
	int expressionSize;
	std::string varValue;
	std::string expression;
	std::string postfixExp;
	//input the amount of varaibles your code will havel ike if you have x and y, you would input 2
	cout << "how many variables does your espression have: ";
	cin >> numVariables;
	cin.ignore();
	if (numVariables > 0)
	{
		//input the variable and what it is equal to. Ex: x = 10.0
		cout << "input variable and what it is equalled to" << endl;
		for (int i = 0; i < numVariables; i++)
		{
			cout << "> ";
			getline(cin, varValue);
			varSize = varValue.length();
			char *varString = _strdup(varValue.c_str());
			//if the value is an x value
			if (varString[0] == 'x')
			{
				x = returnValue(varString, varSize);
				cout << "exrpession is: " << varValue << endl;
				cout << "and the x number is: " << x << endl;
			}
			//if the value is a y value
			if (varString[0] == 'y')
			{
				y = returnValue(varString, varSize);
				cout << "exrpession is: " << varValue << endl;
				cout << "and the y number is: " << y << endl;
			}
			//if the value is a z value
			if (varString[0] == 'z')
			{
				z = returnValue(varString, varSize);
			}
			//cout << varValue << endl;
			//for (int i = 0; i < varValue.length(); i++)
			//{
			//cout << varValue[i] << endl;
			//}*/
			//testRun = returnValue(varString, varSize);
			//cout << testRun << endl;
			delete[] varString;
		}
	}
	cout << x << " " << y << " " << z << endl;
	//input mathematical expression
	cout << "input mathematical expression: ";
	getline(cin, expression);
	cout << "infix expression: " << expression << endl;
	//convert to postfix
	postfixExp = convertToPostfix(expression);
	cout << "postfix expression: " << postfixExp << endl;
	//calculate postfix expression
	totalVal = calculatePostfix(postfixExp, x, y, z);
	cout << "the total of the postfix expression: " << totalVal << endl;
	
	system("pause");
	return 0;
}