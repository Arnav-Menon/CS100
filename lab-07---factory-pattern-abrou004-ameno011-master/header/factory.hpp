#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "div.hpp"

#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include <typeinfo>

using namespace std;

class Base; // forward declaration;

class Factory {
	public:
		Factory() { }
		Base* parse(char** input, int length) { 
			queue<char*> operands; // queue of all the operands (numbers)
			stack<char*> operations; // stack of all the operations (+,-,/,*,**)
			string s;
			for (int i = 1; i < length; i++) {
				s = static_cast<string>(input[i]);
				if (isdigit(s.at(0))) { // if it is a  positive number 
					operands.push(input[i]);
				}
				else if (s == "+" || s == "-" || s == "*" || s == "\\*" || s == "/" || s == "**" || s == "\\*\\*") {
					while (!operations.empty()) {
						operands.push(operations.top());
						operations.pop();
					}
					operations.push(input[i]);
				}
				else if (s.at(0) == '-') { // negative number
					operands.push(input[i]);
				}
				else {
				//	cout << "Invalid input. Please try again" << endl;
					return nullptr;
				}
			}

			while (!operations.empty()) {
				operands.push(operations.top());
				operations.pop();
			}

			queue<Base*> operation_objects; // queue of Base* objects (Add(), Sub(), Div(), Mult(), Pow(), Op())
			Base* temp1;
			Base* temp2;
			Base* temp3;
			double op;
			while (!operands.empty()) {
				s = static_cast<string>(operands.front());
				// initiate factory design!!
				if (s == "+") {
					temp2 = operation_objects.front();
					operation_objects.pop();
					temp3 = operation_objects.front();
					operation_objects.pop();
					temp1 = new Add(temp2, temp3);
					operation_objects.push(temp1);	
					operands.pop();
				}
				else if (s == "-") {
					temp2 = operation_objects.front();
					operation_objects.pop();
					temp3 = operation_objects.front();
					operation_objects.pop();
					temp1 = new Sub(temp2, temp3);
					operation_objects.push(temp1);
					operands.pop();
				}
				else if (s == "*" || s == "\\*") {
					temp2 = operation_objects.front();
					operation_objects.pop();
					temp3 = operation_objects.front();
					operation_objects.pop();	
					temp1 = new Mult(temp2, temp3);
					operation_objects.push(temp1);
					operands.pop();
				}
				else if (s == "/") {
					temp2 = operation_objects.front();
					operation_objects.pop();
					temp3 = operation_objects.front();
					operation_objects.pop();
					temp1 = new Div(temp2, temp3);
					operation_objects.push(temp1);
					operands.pop();
				}
				else if (s == "**" || s == "\\*\\*") {
					temp2 = operation_objects.front();
					operation_objects.pop();
					temp3 = operation_objects.front();
					operation_objects.pop();
					temp1 = new Pow(temp2, temp3);
					operation_objects.push(temp1);
					operands.pop();
				}
				else {
					op = stod(s); // string to digit
					temp1 = new Op(op);
					operands.pop();
					operation_objects.push(temp1);
				}
			}

			return operation_objects.front();
		}
};

#endif // __FACTORY_HPP__
