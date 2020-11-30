#pragma once
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

class Calculator
{
	//������ ��� ��������� �������, ����., (2+2*2)/3
	string infix;
	//������ ��� ����������� �������
	string postfix;// 2 3 +

	//���� ��� �������� (������)
	Stack<char> st_c;
	//���� ��� �����
	Stack<double> st_d;

	int Priority(char elem);

public:

	Calculator(string s = "0") : st_c(100), st_d(100) {
		infix = s;
		postfix = " ";
	}

	void Setinfix(string str)
	{
		infix = str;
	}

	void SetPostfix(string str) {
		postfix = str;
	}

	//�������� ������ � ���������
	bool CheckBrackets();

	//������� ��������� �� ��������� � ����������� �����
	void ToPostfix();
	//���������� ��������� �� ����������� �����
	double CalcPostxif();
	//���������� �� ���� ������
	double Calc();
};


bool Calculator::CheckBrackets()
{
	// (2+3
	Stack<char> st;

	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == '(') {
			st.push('(');
		}
		if (infix[i] == ')') {
			if (st.empty()) { return false; }
			st.pop();
		}
	}
	return st.empty();
}

void Calculator::ToPostfix() {
	postfix = " ";
}


// st_d - ���� �����, st_c - ���� ��������
double Calculator::CalcPostxif() {
	unsigned int i = 0;
	st_d.Clear();
	while (i < postfix.size()) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
			double k2 = st_d.pop();
			double k1 = st_d.pop();
			switch (postfix[i]) {
				case '+': {st_d.push(k1 + k2); break;}
				case '-': {st_d.push(k1 - k2); break; }
				case '*': {st_d.push(k1 * k2); break; }
				case '/': {st_d.push(k1 / k2); break; }
			}
		}
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			double tmp = postfix[i] - '0';
			st_d.push(tmp);
		}
		i++;
	}
	
	double res = st_d.pop();
	
	if (!st_d.empty()) { throw 0; }
	return res;
}