#pragma once

template <class T>
class Stack {
private:
	T* mem;
	int size;
	int last;
public:
	Stack<T>(int _size = 0);
	Stack<T>(const Stack<T>& tmp);
	Stack<T>& operator=(const Stack<T>& tmp);
	~Stack<T>();
	void push(const T tmp);
	T pop();
	T top();
	int empty();
	int full();

};

template<class T>
inline Stack<T>::Stack(int _size) {
	size = _size;
	last = 0;
	mem = new T[size];
	for (int i = 0; i < size; i++) {
		mem[i] = T(0);
	}
}

template<class T>
inline Stack<T>::Stack(const Stack<T>& tmp) {
	size = tmp.size;
	last = tmp.last;
	mem = new T[size];
	for (int i = 0; i < size; i++) {
		mem[i] = tmp.mem[i];
	}
}

template<class T>
inline Stack<T>::~Stack() {
	delete[]mem;
}

template<class T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& tmp) {
	if (this == &tmp) return *this;
	if (size != tmp.size) {
		if (size) {
			delete[]mem;
		}
		size = tmp.size;
		mem = new T[size];
	}
	last = tmp.last;
	for (int i = 0; i < size; i++) {
		mem[i] = tmp.mem[i];
	}
	return *this;
}

template<class T>
inline void Stack<T>::push(const T tmp) {
	if (last < size) mem[last++] = tmp;
	else throw - 1;
}

template<class T>
inline T Stack<T>::pop() {
	if (last > 0) return mem[--last];
	else throw - 1;
}

template<class T>
inline int Stack<T>::empty() {
	if (last == 0)return 1;
	else return 0;
}

template<class T>
inline int Stack<T>::full() {
	if (last < (size - 1))return 0;
	else return 1;
}
template<class T>
inline T Stack<T>::top() {
	if (last > 0) return mem[last - 1];
	else throw - 1;
}