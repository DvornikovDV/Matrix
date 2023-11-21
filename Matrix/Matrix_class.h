// Дворников Даниил
#pragma once

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Matrix {
public:
	vector <vector <double> > matrix;

	Matrix(int n, int m);

	void fill_one_value(double v);

	void fill_rand();

	void sum_mx(const Matrix& mx_1);

	Matrix& operator + (const Matrix& mx_1);

	Matrix& operator += (const Matrix& mx_1);

	void dif_mx(const Matrix& mx_1);

	Matrix& operator - (const Matrix& mx_1);

	Matrix& operator -= (const Matrix& mx_1);

	void scalar_multiply(double scalar);

	Matrix& matrix_multiply(const Matrix& mx_1) const;

	Matrix& operator * (const Matrix& mx_1) const;

	Matrix& operator *= (const Matrix& mx_1);

	void transposition_mx();

	double determinant_mx() const;

	void inverse_mx();
};