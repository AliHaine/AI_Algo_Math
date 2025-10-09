# Matrix

Learn, understand and create programs that transform matrices and linear transformations through vectors and spaces.

## 🚀 Main goals
- Understand the basic notions of matrices.
- Manipulate vectors and linear transformations.
- Implement functions for matrix calculations.

## 📂 Contents
- Basic operations (addition, multiplication, transposition, etc.)
- Determinant and inverse calculation.
- Applications to geometric transformations.

Mathematical concept used for this project [Vector](https://github.com/AliHaine/AI_Algo_Math/tree/main/notebook/Vector.md), [SetBuilder](https://github.com/AliHaine/AI_Algo_Math/tree/main/notebook/SetBuilder.md), [BigO](https://github.com/AliHaine/AI_Algo_Math/tree/main/notebook/BigO.md)

## ex00 : add, subtract and scale

_Write functions that can add and subtract two vectors, or two matrices, of the
same size; and a function to multiply a vector, or a matrix, by a scalar._

This is a basic exercise where we implement fundamental operations for the basic operator for vectors and matrices. These methods will be very useful for the following exercises

### Examples

#### Addition

Let vecA = [1, 2] and vecB = [3, 4].

The addition of these vectors results in a new vector vecC = [4, 5]

#### Substraction

Let vecA = [3, 4] and vecB = [1, 2].

The substraction of these vectors results in a new vector vecC = [2, 2]

#### Scalar

Let vecA = [2, 3] and S = 2 as our scalar.

Multiplying gives a new vector vecS = [4, 6]

## ex01 : Linear combination

_Write a function that computes a linear combination of the vectors provided,
using the corresponding scalar coefficients._

The prototype function to write (Rust)

fn linear_combination::<K>(u: &[Vector<K>], coefs: &[K]) -> Vector<K>;

The equivalent in CPP

Vector<K> linear_combination(const initializer_list<Vector<K>>& vectors, const initializer_list<K>& coefs)

