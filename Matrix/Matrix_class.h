// Дворников Даниил
#pragma once

#include <iostream>
#include <vector>
#include <time.h>
#include <iomanip>

// Pаскомментировать строку ниже, чтобы отключить assert()
//#define NDEBUG
#include <cassert>

using namespace std;

// Погрешность вычислений для проверки работы программы
const double eps = 1e-4;

class Matrix { /// Класс для работы с матрицами, созданный на основе класса Vector
public:
	// Поле matrix - матрица, возможен доступ к элементам и строкам ( mx.matrix[i][j] или mx.matrix[i] )
	vector <vector <double> > matrix;

	/// Конструктор класса, выделяет память для матрицы размером n строк m столбцов
	Matrix(int n, int m);

	/// Меняет размер матрицы на n строк m столбцов
	void resize_mx(int n, int m);

	/// Заполнение всех элементов матрицы значением v
	void fill_one_value(double v);

	/// Заполнение матрицы случайными значениями
	void fill_rand();

	/// Заполнение матрицы через консоль
	void fill_hand();

	/// Вывод матрицы
	void print_mx();

	/// Сумма матриц текущего объекта и mx_1, результат сохраняется в поле текущего объекта
	void sum_mx(const Matrix& mx_1);

	/// Сумма матриц текущего объекта и mx_1, возвращает объект класса - результирующую матрицу
	Matrix operator + (const Matrix& mx_1);

	/// Сумма матриц текущего объекта и mx_1, результат присваивается текущему объекту
	Matrix operator += (const Matrix& mx_1);

	/// Разность матриц текущего объекта и mx_1, результат сохраняется в поле текущего объекта
	void dif_mx(const Matrix& mx_1);

	/// Разность матриц текущего объекта и mx_1, возвращает объект класса - результирующую матрицу
	Matrix operator - (const Matrix& mx_1);

	/// Разность матриц текущего объекта и mx_1, результат присваивается текущему объекту
	Matrix operator -= (const Matrix& mx_1);

	/// Произведение матрицы на число scalar
	void scalar_multiply(double scalar);

	/// Произведение матриц текущего объекта и mx_1, результат сохраняется в поле текущего объекта
	Matrix matrix_multiply(const Matrix& mx_1) const;

	/// Произведение матриц текущего объекта и mx_1, возвращает объект класса - результирующую матрицу
	Matrix operator * (const Matrix& mx_1) const;

	/// Произведение матриц текущего объекта и mx_1, результат присваивается текущему объекту
	Matrix operator *= (const Matrix& mx_1);

	/// Транспонирование матрицы
	void transposition_mx();

	/// Вычисление определителя матрицы, возвращает число
	double determinant_mx() const;

	/// Вычисление обратной матрицы, замена старой на обратную
	void inverse_mx();
};

/// Тестирование методов класса
void test_Matrix_class();