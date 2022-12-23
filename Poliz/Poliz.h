#pragma once
#include <string>
#include"Table.h"
#include"Stack.h"

class Poliz {
private:
	std::string *poliz;
	int poliz_size;
	int poliz_count;
	Table<double> *tabl_variable;
	Table<int> *tabl_priority;
	void make_tabl_priority();
	void left_bracket();
	void right_bracket();
	void operand(const std::string &tmp);
	void operation(Line<int> tmp);
	void end_of_string();
	void make_poliz(std::string &tmp);
	Stack <Line<int> > stack_priority;
public:
	Poliz(std::string str = " ");
	Poliz(const Poliz &tmp);
	~Poliz();
	Poliz &operator=(const Poliz &tmp);
	std::string get_poliz();
	std::string operator[](const int k);
	int get_poliz_count();
	Table<double>* get_tabl_variable();
};

