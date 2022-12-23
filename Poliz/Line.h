#pragma once
#include <string>
template <class T>
class Line {
private:
	std::string name;
	T value;
public:
	Line <T>(std::string _nameT, T _value = T(0));
	Line<T> &operator=(const Line<T> & tmp);
	Line <T>(T _value = T(0));
	Line <T>(const Line <T> &tmp);
	~Line<T>();
	std::string get_name()const;
	T get_value()const;
	void set_value(const T &tmp);
};

template<class T>
inline Line<T>::Line(std::string _name, T _value) {
	name = _name;
	value = _value;
}

template<class T>
inline Line<T>::Line(T _value) {
	name = " ";
	value = _value;
}

template<class T>
inline Line<T>::Line(const Line<T>& tmp) {
	name = tmp.name;
	value = tmp.value;
}

template<class T>
inline Line<T>::~Line() {
}

template<class T>
inline Line<T>& Line<T>::operator=(const Line<T>& tmp) {
	if (this == &tmp) return *this;
	name = tmp.name;
	value = tmp.value;
	return *this;
}

template<class T>
inline std::string Line<T>::get_name() const {
	return this->name;
}

template<class T>
inline T Line<T>::get_value()const {
	return this->value;
}

template<class T>
inline void Line<T>::set_value(const T & tmp) {
	value = tmp;
}
