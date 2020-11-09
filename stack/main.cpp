﻿// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "stack.h"

#include <string>



class Calculator
{
	//Строка для исходной формулы, напр., (2+2*2)/3
	std::string formula;
	//Стек для символов (скобок)
	Stack<char> st_c;
	//Стек для чисел
	Stack<double> st_d;
	//Строка для инфиксной формулы
	std::string infix;//2 2 3 + *

public:

	void SetFormula(std::string str)
	{
		formula = str;
	}
	bool CheckBrackets();

};

bool Calculator::CheckBrackets()
{
	// (2+3
	int i = 0;
	formula.size();

	formula[i];


	return true;
}

/*
	4+(1+2)/(2+3)
	
	4 1 2 + 2 3 + / +
	

*/


int main()
{
	Calculator calc;

	calc.SetFormula("2+2*2");

	if (calc.CheckBrackets() == true)
	{
		//Скобки расставлены верно
	}
	else
	{
		//ошибка в расстановке скобок
	}

}