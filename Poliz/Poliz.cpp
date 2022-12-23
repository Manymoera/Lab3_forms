#include "Poliz.h"
#include"Line.h"
#include <string>
#include <iostream>
void delenie_stroki_razn_delit(std::string *w, std::string st, std::string zn, int &k) {
	int L;
	for (int i = 0; i < int(st.size()); i++) {
		L = zn.find(st[i]);
		if ((L <= 0) && (L >= zn.size())) {
			w[k] += st[i];
		}
		else {
			if (st[i] != ' ') {
				if (w[k] != "") {
					w[++k] = st[i];

				}
				else {
					w[k] = st[i];
				}
				w[++k] = "";
			}
		}
	}
}


void Poliz::make_poliz(std::string & tmp) {
	std::string *lex;
	lex = new std::string[tmp.size() + 2];
	int k = 0;
	delenie_stroki_razn_delit(lex, tmp, "+-*/^)( ", k);
	poliz_count = 0;
	for (int i = 0; i <= k; i++) {
		if (lex[i] == "(") {
			left_bracket();
		}
		else if (lex[i] == ")") {
			right_bracket();
		}
		else {
			int l;
			l = tabl_priority->search_line(lex[i]);
			if (l != -1) {
				operation(Line<int>(lex[i], tabl_priority->search(lex[i])));
			}

			else operand(lex[i]);
		}
	}
	end_of_string();
}

void Poliz::make_tabl_priority() {
	tabl_priority = new Table<int>(5);
	tabl_priority->push(Line<int>("+", 1));
	tabl_priority->push(Line<int>("-", 1));
	tabl_priority->push(Line<int>("*", 2));
	tabl_priority->push(Line<int>("/", 2));
	tabl_priority->push(Line<int>("^", 3));
}

void Poliz::left_bracket() {
	if (stack_priority.full() == 0) stack_priority.push(Line<int>("("));
}

void Poliz::right_bracket() {
	while (stack_priority.top().get_name() != "(") {
		poliz[poliz_count++] = stack_priority.pop().get_name();
	}
	stack_priority.pop();
}

void Poliz::operand(const std::string &tmp) {
	if (tmp[0] >= '0' && tmp[0] <= '9') {
		tabl_variable->push(Line<double>(tmp, atof(tmp.c_str())));
	}
	else {
		tabl_variable->push(Line<double>(tmp));
	}
	poliz[poliz_count++] = tmp;
}

void Poliz::operation(Line<int>  tmp) {
	while ((stack_priority.empty() != 1) && (stack_priority.top().get_value() >= tmp.get_value())) {
		poliz[poliz_count++] = stack_priority.pop().get_name();
	}
	stack_priority.push(tmp);
}
void Poliz::end_of_string() {
	while (stack_priority.empty() != 1) {
		poliz[poliz_count++] = stack_priority.pop().get_name();
	}
}

Poliz::Poliz(std::string str) {
	poliz_size = int(str.size() + 1);
	poliz = new std::string[poliz_size];
	poliz_count = 0;
	make_tabl_priority();
	tabl_variable = new Table<double>(poliz_size / 2);
	stack_priority = Stack<Line<int> >(poliz_size);
	make_poliz(str);
}

Poliz::Poliz(const Poliz & tmp) {
	poliz_size = tmp.poliz_size;
	poliz = new std::string[poliz_size];
	poliz_count = tmp.poliz_count;
	make_tabl_priority();
	tabl_variable = new Table<double>(poliz_size / 2);
	(*tabl_variable) = (*(tmp.tabl_variable));
	stack_priority = Stack<Line<int> >(poliz_size);
	for (int i = 0; i < poliz_count; i++) {
		poliz[i] = tmp.poliz[i];
	}
}

Poliz::~Poliz() {
	delete[] poliz;
	delete tabl_priority;
	delete tabl_variable;
}

Poliz & Poliz::operator=(const Poliz & tmp) {
	if (this == &tmp)return *this;
	if (poliz_size != tmp.poliz_size) {
		if (poliz_size != 0) {
			delete[]poliz;
		}
		poliz_size = tmp.poliz_size;
		poliz = new std::string[poliz_size];
	}
	poliz_count = tmp.poliz_count;
	for (int i = 0; i < poliz_count; i++) {
		poliz[i] = tmp.poliz[i];
	}
	make_tabl_priority();
	delete tabl_variable;
	tabl_variable = new Table<double>(poliz_size);
	(*tabl_variable) = (*(tmp.tabl_variable));
	stack_priority = Stack<Line<int> >(poliz_size);
	return *this;
}

std::string Poliz::get_poliz() {
	std::string res = "";
	for (int i = 0; i < poliz_count; i++) {
		res += poliz[i] + " ";
	}
	return res;
}

std::string Poliz::operator[](const int k) {
	if (k >= 0 && k < poliz_count) return poliz[k];
	else return "";
}

int Poliz::get_poliz_count() {
	return poliz_count;
}

Table<double>* Poliz::get_tabl_variable() {
	return tabl_variable;
}
