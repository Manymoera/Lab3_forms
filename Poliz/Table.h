#pragma once
#include<iomanip>
#include"Line.h"
template<class T>
class Table {
private:
	Line<T> *mem;
	int size;
	int count;
public:
	Table<T>(int _size = 0);
	~Table<T>();
	Table<T>(const Table<T> & tmp);
	Table<T> &operator=(const Table<T> & tmp);
	void push(Line<T> tmp);
	void erase(const std::string & name);
	T search(const std::string & name);
	int search_line(const std::string & name);
	Line<T> &operator[](const int k);
	bool empty();
	bool full();
	int get_count() {
		return this->count;
	}
	int get_size() {
		return this->size;
	}
};

template<class T>
inline Table<T>::Table(int _size) {
	size = _size;
	mem = new Line<T>[size];
	for (int i = 0; i < size; i++) {
		mem[i] = Line<T>();
	}
	count = 0;
}

template<class T>
inline Table<T>::~Table() {
	delete[] mem;
}

template<class T>
inline Table<T>::Table(const Table<T>& tmp) {
	size = tmp.size;
	mem = new Line<T>[size];
	count = tmp.count;
	for (int i = 0; i < size; i++) {
		mem[i] = tmp.mem[i];
	}
}

template<class T>
inline Table<T>& Table<T>::operator=(const Table<T>& tmp) {
	if (this == &tmp) return *this;
	if (size != tmp.size) {
		if (size) {
			delete[] mem;
		}
		size = tmp.size;
		mem = new Line<T>[size];
	}
	count = tmp.count;
	for (int i = 0; i < size; i++) {
		mem[i] = tmp.mem[i];
	}
	return *this;
}

template<class T>
inline void Table<T>::push(Line<T> tmp) {
	int pos = search_line(tmp.get_name());
	if (pos == -1) {
		if (count == size) throw 1;
		mem[count++] = tmp;
	}
	else {
		mem[pos] = tmp;
	}
}

template<class T>
inline void Table<T>::erase(const std::string & name) {
	int pos = search_line(name);
	if (pos == -1) throw 1;
	mem[pos] = mem[--count];
}

template<class T>
inline T Table<T>::search(const std::string & name) {
	int pos = search_line(name);
	if (pos == -1) throw - 1;
	return mem[pos].get_value();
}

template<class T>
inline int Table<T>::search_line(const std::string & name) {
	int pos = -1;
	int i = 0;
	while (i < count && pos == -1) {
		if (name == mem[i].get_name()) pos = i;
		++i;
	}
	return pos;
}

template<class T>
inline Line<T>& Table<T>::operator[](const int k) {
	if (k < 0 || k >= size) throw 1;
	return mem[k];
}

template<class T>
inline bool Table<T>::empty() {
	return count == 0;
}

template<class T>
inline bool Table<T>::full() {
	return count == size;
}
