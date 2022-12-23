#pragma once
#include <string>
#include"Table.h"
#include"Stack.h"

class TPoliz {
private:
	std::string *poliz;//��������� �� ������
	int poliz_size;//������ ������
	int poliz_count;
	Stack <Line<int> > stack_priority;//���� �����������
	Table<double> *tabl_variable;//��������� �� ������� ���������� 
	Table<int> *tabl_priority;//��������� �� ������� �����������
	void make_tabl_priority();//��������� ������� �����������
	void left_bracket();//���������� ������� �����������, ���� ��������� ����� ������
	void right_bracket();////���������� ������� �����������, ���� ��������� ������ ������
	void operand(const std::string &tmp);//�������� ������� � �����
	void operation(Line<int> tmp);//���������� ��������� � �����, �������� �� ���� �����������
	void end_of_string();//���������� � ����� ����� ������(���, ��� ��������)
	void make_poliz(std::string &tmp);//��������� �����
	
public:
	TPoliz(std::string str = " ");
	TPoliz(const TPoliz &tmp);
	~TPoliz();
	TPoliz &operator=(const TPoliz &tmp);
	std::string get_poliz();
	std::string operator[](const int k);
	int get_poliz_count();
	Table<double>* get_tabl_variable();
};

