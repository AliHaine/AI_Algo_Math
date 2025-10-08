#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp"

template <typename K>
struct Matrix{
	Vector<Vector<K>>	mat;
	size_t				length;

	static Matrix<K>	from(initializer_list<initializer_list<K>>);

	const size_t		getSize() const;
	void				print();
	void				convertToMatrix();
	bool				isSquare();

	void				pushb(const Vector<K>&);

	void				add(const Matrix<K>&);
	void				sub(const Matrix<K>&);
	void				scl(const K&);
};

template <typename K>
Matrix<K> Matrix<K>::from(initializer_list<initializer_list<K>> initializers) {
	Matrix<K> m;
	m.length = initializers.begin()->size();
	cout << "A new Matrix is creating.. with row size " << m.length << endl;
	for (const initializer_list<K>& initializer : initializers) {
		Vector<K> newVec;
		for (const K& val : initializer) {
			newVec.pushb(val);
		}
		if (newVec.getSize() != m.length)
			fatalError("The size of rows are not equals in a matrix");
		m.pushb(newVec);
	}
	return m;
}


// Utils
template <typename K>
const size_t Matrix<K>::getSize() const {
	return this->mat.vec.size();
}

template <typename K>
void Matrix<K>::print() {
	for (int y = 0; y < this->mat.getSize(); y++) {
		cout << '[';
		const Vector<K> xVec = this->mat.vec.at(y);
		for (size_t x = 0; x < xVec.vec.size(); ++x) {
			cout << xVec.vec[x];
			if (x != xVec.vec.size() - 1)
				cout << ", ";
		}
		cout << ']' << endl;
	}
}

template <typename K>
void Matrix<K>::pushb(const Vector<K>& newVec) {
	this->mat.pushb(newVec);
}

// Scalar
template <typename K>
void Matrix<K>::add(const Matrix<K>& matTarget) {
	if (matTarget.getSize() != this->getSize())
		fatalError("The size of these two matrix are not the same..");
	if (matTarget.length != this->length)
		fatalError("The length of these two matrix rows are not the same..");

	for (size_t i = 0; i < this->getSize(); i++) {
		Vector<K>& currVec = this->mat.at(i);
		currVec.add(matTarget.mat.at(i));
	}
}

template <typename K>
void Matrix<K>::sub(const Matrix<K>& matTarget) {
	if (matTarget.getSize() != this->getSize())
		fatalError("The size of these two matrix are not the same..");
	if (matTarget.length != this->length)
		fatalError("The length of these two matrix rows are not the same..");

	for (size_t i = 0; i < this->getSize(); i++)
		this->mat.at(i).sub(matTarget.mat.at(i));
}

template <typename K>
void Matrix<K>::scl(const K& scalar) {
	for (size_t i = 0; i < this->getSize(); i++)
		this->mat.at(i).scl(scalar);
}

#endif