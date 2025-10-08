#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include "./utils.hpp"

template <typename K>
struct Vector{
	std::vector<K> vec;

	static Vector<K>	from(std::initializer_list<K>);

	K&					at(const size_t);
	const K&			at(const size_t) const;
	const int			getSize() const;
	void				print();
	void				convertToMatrix();

	void				pushb(K);

	void				add(const Vector<K>&);
	void				sub(const Vector<K>&);
	void				scl(const K&);

    K                    dot(const Vector<K>&);

};

template <typename K>
Vector<K> Vector<K>::from(std::initializer_list<K> values) {
	cout << "A new vector is creating.." << endl;
	Vector<K> v;
	for (const K& val : values)
		v.pushb(val);
	return v;
}


// Utils
template <typename K>
K& Vector<K>::at(const size_t i) {
	return this->vec.at(i);
}

template <typename K>
const K& Vector<K>::at(const size_t i) const {
	return this->vec.at(i);
}

template <typename K>
const int Vector<K>::getSize() const {
	return this->vec.size();
}

template <typename K>
void Vector<K>::print() {
	for (const K& val : this->vec)
		cout << '[' << val << ']' << endl;
	cout << "------------" << endl;
}

template <typename K>
void Vector<K>::convertToMatrix() {
	cout << "convertToMatrix called\n";
}

template <typename K>
void Vector<K>::pushb(K val) {
	this->vec.push_back(val);
}

// Scalar
template <typename K>
void Vector<K>::add(const Vector<K>& vecTarget) {
	cout << "Add operation called" << endl;
	if (this->getSize() != vecTarget.getSize())
		fatalError("The size of the vectors are not equals for add operation");

	for (int i = 0 ; i < this->getSize(); i++) {
		this->vec.at(i) += vecTarget.vec.at(i);
	}
}

template <typename K>
void Vector<K>::sub(const Vector<K>& vecTarget) {
	cout << "Sub operation called " << endl;
	if (this->getSize() != vecTarget.getSize())
		fatalError("The size of the vectors are not equals for sub operation");

	for (int i = 0 ; i < this->getSize(); i++) {
		this->vec.at(i) -= vecTarget.vec.at(i);
	}
}

template <typename K>
void Vector<K>::scl(const K& scalar) {
	cout << "Scale operation called" << endl;
	for (int i = 0 ; i < this->getSize(); i++) {
		this->vec.at(i) *= scalar;
	}
}

//other
template <typename K>
K Vector<K>::dot(const Vector<K>& v2) {
    if (this->getSize() != v2.getSize())
        fatalError("The size of the vectors are not equals for dot operation");

    K result = 0;
    for (size_t i = 0 ; i < this->getSize(); i++) {
        result += this->vec.at(i) * v2.at(i);
    }
    return result;
}

#endif
