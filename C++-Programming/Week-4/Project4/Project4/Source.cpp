#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class BigInt {
private:
	string num;
	char sign;
public:
	BigInt(string n = "0");
	BigInt operator+(const BigInt& bi);
	BigInt operator-(const BigInt& bi);
	BigInt operator*(const BigInt& bi);
	BigInt operator/(const BigInt& bi);
	friend ostream& operator<<(ostream& o, const BigInt& b);
};

BigInt::BigInt(string n) {
	if (n[0] == '-') {
		sign = '-';
		num = n.substr(1, n.length() - 1);
	}
	else {
		sign = '+';
		num = n;
	}
}

BigInt BigInt::operator+(const BigInt& bi) {
	string operand1 = num;
	string operand2 = bi.num;

	int maxLength = operand1.length() > operand2.length() ? operand1.length() : operand2.length();
	while (operand2.length() < operand1.length()) {
		operand2.insert(0, "0");
	}
	while (operand1.length() < operand2.length()) {
		operand1.insert(0, "0");
	}
	char* result = new char[maxLength + 1];
	result[maxLength] = '\0';
	int carry = 0;
	for (int i = maxLength - 1; i >= 0; i--) {
		int add1 = operand1[i] - '0'; //Compute value based on ASCII
		int add2 = operand2[i] - '0';
		int add = (add1 + add2 + carry) % 10;
		result[i] = '0' + add;
		carry = (add1 + add2 + carry) / 10;
	}
	BigInt tmp(result);
	if (carry) {
		tmp.num = "1" + tmp.num;
	}
	tmp.sign = sign;
	return tmp;
}

BigInt BigInt::operator-(const BigInt& bi) {
	string operand1 = num;
	string operand2 = bi.num;
	BigInt tmp;
	if (operand1 == operand2) {
		tmp.num = "0";
		tmp.sign = '+';
		return tmp;
	}
	int maxLength = 0;
	char tmpSign = '+';
	// '<' in string: compare two strings (by ASCII) character by character from the left to the right until 
	// different characters appear or '\0' is encountered.
	if (operand1.length() < operand2.length() || (operand1.length() == operand2.length() && operand1 < operand2)) {
		tmpSign = '-';
		// string::swap: Exchanges the content of the container by the content of str, which is another string object. Lengths may differ.
		swap(operand1, operand2);
	}
	maxLength = operand1.length();
	while (operand2.length() < operand1.length()) {
		operand2.insert(0, "0");
	}
	char* result = new char[maxLength + 1];
	result[maxLength] = '\0';
	int borrow = 0;
	for (int i = maxLength - 1; i >= 0; i--) {
		int minus1 = operand1[i] - '0';
		int minus2 = operand2[i] - '0';
		int minus = minus1 - minus2 - borrow;
		if (minus < 0) {
			minus += 10;
			borrow = 1;
		}
		else {
			borrow = 0;
		}
		result[i] = '0' + minus;
	}
	tmp.num = result;
	while (tmp.num[0] == '0') {
		// std::string::begin returns an iterator pointing to the first character of the string.
		// std::string::erase erases part of the string, reducing its length: erases the character pointed by p.
		tmp.num.erase(tmp.num.begin());
	}
	tmp.sign = tmpSign;
	return tmp;
}

BigInt BigInt::operator*(const BigInt& bi) {
	string operand1 = num;
	string operand2 = bi.num;
	BigInt tmp;
	BigInt result;
	result.sign = '+';

	for (int i = 0; i < operand2.length(); i++) {
		tmp.num = "0";
		for (int j = 0; j < operand2[i] - '0'; j++) {
			tmp = tmp + *this;
		}
		tmp.num.resize(tmp.num.length() + i, '0');
		result = result + tmp;
	}
	return result;
}

BigInt BigInt::operator/(const BigInt& bi) {
	string operand1 = num;
	string operand2 = bi.num;
	BigInt quotient;
	quotient.sign = '+';
	if (operand1.length() < operand2.length()) {
		quotient.num = "0";
		return quotient;
	}
	int m = operand1.length() - operand2.length();
	operand2.resize(operand1.length(), '0');
	BigInt dividend(operand1);
	BigInt divisor(operand2);
	for (int i = 0; i <= m; i++) {
		int tmp = 0;
		while ((dividend - divisor).sign != '-') {
			tmp++;
			dividend = dividend - divisor;
		}
		quotient.num += ('0' + tmp);
		divisor.num.resize(divisor.num.length() - 1);
	}
	while (quotient.num[0] == '0') {
		quotient.num.erase(quotient.num.begin());
	}
	return quotient;
}

ostream& operator<<(ostream& o, const BigInt& b) {
	if (b.sign == '+') {
		o << b.num;
	}
	else if (b.sign == '-') {
		o << "-" << b.num;
	}
	return o;
}

int main() {
	string s1, s2;
	char Operator;
	cin >> s1 >> Operator >> s2;
	BigInt a(s1);
	BigInt b(s2);
	BigInt result;

	switch (Operator) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	}
	cout << result << endl;
	return 0;
}