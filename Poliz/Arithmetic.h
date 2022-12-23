#pragma once
#include"TPoliz.h"
#include"Stack.h"
class Arithmetic {
private:
	std::string str;//входная строка
	TPoliz* poliz;//указатель на полиз
public:
	Arithmetic(std::string _str);
	Arithmetic(const Arithmetic & tmp);
	Arithmetic &operator=(const Arithmetic & tmp);
	~Arithmetic();
	double calculate();//вычисление выражения
	TPoliz* get_poliz();//возвращает указатель на полиз
};