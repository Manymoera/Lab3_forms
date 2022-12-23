#include "Arithmetic.h"

Arithmetic::Arithmetic(std::string _str) {
	str = _str;
	poliz = new TPoliz(_str);
}

Arithmetic::Arithmetic(const Arithmetic& tmp) {
	str = tmp.str;
	poliz = tmp.poliz;
}

Arithmetic& Arithmetic::operator=(const Arithmetic& tmp) {
	if (&tmp == this) return *this;
	this->str = tmp.str;
	this->poliz = tmp.poliz;
	return *this;
}
Arithmetic::~Arithmetic() {
}
double Arithmetic::calculate() {
	Stack<double> s(poliz->get_tabl_variable()->get_count() + 5);

	double left, right;
	double res = 0;
	for (int i = 0; i < poliz->get_poliz_count(); i++) {
		int k = poliz->get_tabl_variable()->search_line(poliz->operator[](i));

		if (k == -2) continue;

		if (k != -1) {
			double value = poliz->get_tabl_variable()->operator[](k).get_value();
			s.push(value);
		}
		else {
			right = s.pop();
			left = s.pop();
			if (poliz->operator[](i) == "+") {
				double check = left + right;
				s.push(left + right);
			}
			else if (poliz->operator[](i) == "-") {
				s.push(left - right);
			}
			else if (poliz->operator[](i) == "^") {
				s.push(pow(left, right));
			}
			else if (poliz->operator[](i) == "*") {
				s.push(left * right);
			}
			else if (poliz->operator[](i) == "/") {
				s.push(left / right);
			}
		}
	}
	return s.pop();
}

TPoliz* Arithmetic::get_poliz() {
	return this->poliz;
}