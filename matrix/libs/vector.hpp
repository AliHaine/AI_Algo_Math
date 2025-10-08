#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include "./utils.hpp"

template <typename K>
struct Vector{
	std::vector<K> vec;

	static Vector<K>	from(std::initializer_list<K>);

	const int			getSize() const;
	void				print();
	void				convertToMatrix();

	void				pushb(K);

	void				add(const Vector<K>&);
	void				sub(const Vector<K>&);
	void				scl(const K&);

};

template <typename K>
Vector<K> Vector<K>::from(std::initializer_list<K> values) {
	std::cout << "A new vector is creating.." << std::endl;
	Vector<K> v;
	for (const K& val : values)
		v.pushb(val);
	return v;
}


// Utils
template <typename K>
const int Vector<K>::getSize() const {
	return this->vec.size();
}

template <typename K>
void Vector<K>::print() {
	for (const K& val : this->vec)
		std::cout << '[' << val << ']' << std::endl;
	std::cout << "------------" << std::endl;
}

template <typename K>
void Vector<K>::convertToMatrix() {
	std::cout << "convertToMatrix called\n";
}

template <typename K>
void Vector<K>::pushb(K val) {
	this->vec.push_back(val);
}

// Scalar
template <typename K>
void Vector<K>::add(const Vector<K>& vecTarget) {
	std::cout << "Add operation called" << std::endl;
	if (this->getSize() != vecTarget.getSize())
		fatalError("The size of the vectors are not equals for add operation");

	for (int i = 0 ; i < this->getSize(); i++) {
		this->vec.at(i) += vecTarget.vec.at(i);
	}
}

template <typename K>
void Vector<K>::sub(const Vector<K>& vecTarget) {
	std::cout << "Sub operation called " << std::endl;
	if (this->getSize() != vecTarget.getSize())
		fatalError("The size of the vectors are not equals for sub operation");

	for (int i = 0 ; i < this->getSize(); i++) {
		this->vec.at(i) -= vecTarget.vec.at(i);
	}
}

template <typename K>
void Vector<K>::scl(const K& scalar) {
	std::cout << "Scale operation called" << std::endl;
	for (int i = 0 ; i < this->getSize(); i++) {
		this->vec.at(i) *= scalar;
	}
}

#endif
