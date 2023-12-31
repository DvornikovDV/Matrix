﻿// Дворников Даниил
#include "Matrix_class.h"

/// Конструктор класса, выделяет память для матрицы размером n строк m столбцов
Matrix::Matrix(int n, int m) {
	matrix.resize(n);
	for (int i{}; i < n; i++) {
		matrix[i].resize(m);
	}
}

/// Меняет размер матрицы на n строк m столбцов
void Matrix::resize_mx(int n, int m) {
	matrix.resize(n);
	for (int i{}; i < n; i++) {
		matrix[i].resize(m);
	}
}

/// Заполнение всех элементов матрицы значением v
void Matrix::fill_one_value(double v) {
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] = v;
		}
	}
}

/// Заполнение матрицы случайными значениями
void Matrix::fill_rand() {
	srand(time(0));
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] = (rand() % 201 - 100) + (rand() % 101 / 100.0);
		}
	}
}

/// Заполнение матрицы через консоль
void Matrix::fill_hand() {
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			cin >> matrix[i][j];
		}
	}
}

/// Вывод матрицы
void Matrix::print_mx() {
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			cout << setw(12) << setprecision(3) << matrix[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

/// Сумма матриц текущего объекта и mx_1, результат сохраняется в поле текущего объекта
void Matrix::sum_mx(const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] += mx_1.matrix[i][j];
		}
	}
}

/// Сумма матриц текущего объекта и mx_1, возвращает объект класса - результирующую матрицу
Matrix Matrix::operator + (const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	Matrix mx_r(matrix.size(), matrix[0].size());
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			mx_r.matrix[i][j] = matrix[i][j] + mx_1.matrix[i][j];
		}
	}
	return mx_r;
}

/// Сумма матриц текущего объекта и mx_1, результат присваивается текущему объекту
Matrix Matrix::operator += (const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] += mx_1.matrix[i][j];
		}
	}
	return *this;
}

/// Разность матриц текущего объекта и mx_1, результат сохраняется в поле текущего объекта
void Matrix::dif_mx(const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] -= mx_1.matrix[i][j];
		}
	}
}

/// Разность матриц текущего объекта и mx_1, возвращает объект класса - результирующую матрицу
Matrix Matrix::operator - (const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	Matrix mx_r(matrix.size(), matrix[0].size());
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			mx_r.matrix[i][j] = matrix[i][j] - mx_1.matrix[i][j];
		}
	}
	return mx_r;
}

/// Разность матриц текущего объекта и mx_1, результат присваивается текущему объекту
Matrix Matrix::operator -= (const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] -= mx_1.matrix[i][j];
		}
	}
	return *this;
}

/// Произведение матрицы на число scalar
void Matrix::scalar_multiply(double scalar) {
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] *= scalar;
		}
	}
}

/// Произведение матриц текущего объекта и mx_1, результат сохраняется в поле текущего объекта
Matrix Matrix::matrix_multiply(const Matrix& mx_1) const {
	if (matrix[0].size() != mx_1.matrix.size()) throw invalid_argument("Количество столбцов первой матрицы не равно количеству строк второй матрицы.");

	Matrix mx_r(matrix.size(), mx_1.matrix[0].size());
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < mx_1.matrix[0].size(); j++) {
			for (int m{}; m < matrix.size(); m++) {
				mx_r.matrix[i][j] += matrix[i][m] * mx_1.matrix[m][j];
			}
		}
	}
	return mx_r;
}

/// Произведение матриц текущего объекта и mx_1, возвращает объект класса - результирующую матрицу
Matrix Matrix::operator * (const Matrix& mx_1) const {
	if (matrix[0].size() != mx_1.matrix.size()) throw invalid_argument("Количество столбцов первой матрицы не равно количеству строк второй матрицы.");
	
	Matrix mx_r(matrix.size(), mx_1.matrix[0].size());
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < mx_1.matrix[0].size(); j++) {
			for (int m{}; m < matrix.size(); m++) {
				mx_r.matrix[i][j] += matrix[i][m] * mx_1.matrix[m][j];
			}
		}
	}
	return mx_r;
}

/// Произведение матриц текущего объекта и mx_1, результат присваивается текущему объекту
Matrix Matrix::operator *= (const Matrix& mx_1) {
	if (matrix[0].size() != mx_1.matrix.size()) throw invalid_argument("Количество столбцов первой матрицы не равно количеству строк второй матрицы.");
	Matrix mx_r(matrix.size(), matrix[0].size());
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < mx_1.matrix[0].size(); j++) {
			for (int m{}; m < matrix.size(); m++) {
				mx_r.matrix[i][j] += matrix[i][m] * mx_1.matrix[m][j];
			}
		}
	}
	*this = mx_r;
	return *this;
}

/// Транспонирование матрицы
void Matrix::transposition_mx() {
	if (matrix.size() == matrix[0].size()) {
		double temp{};

		for (int i{}; i < matrix.size(); i++) {
			for (int j{}; j < matrix[0].size(); j++) {
				if (i != j) {
					temp = matrix[i][j];
					matrix[i][j] = matrix[j][i];
					matrix[j][i] = temp;
				}
			}
		}
	}
	else {
		int m = matrix.size(); int n = matrix[0].size();
		vector<double> tmp(m * n);

		for (int i{}; i < m; i++) {
			for (int j{}; j < n; j++) {
				tmp[i * n + j] = matrix[i][j];
			}
		}

		this->resize_mx(n, m);

		for (int i{}; i < n; i++) {
			for (int j{}; j < m; j++) {
				matrix[i][j] = tmp[i * m + j];
			}
		}

		tmp.clear();
	}
}

/// Вычисление определителя матрицы, возвращает число
double Matrix::determinant_mx() const {
	if (matrix.size() != matrix[0].size()) throw invalid_argument("Матрица должна быть квадратной.");
	int m = matrix.size();
	if (m == 0) return 0;
	if (m == 1) return matrix[0][0];
	if (m == 2) return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);

	double tmp{};
	vector<vector<double>> mx_1(matrix.size(), vector<double>(matrix[0].size()));
	mx_1 = matrix;
	for (int k{}; k < matrix.size() - 1; k++) {
		for (int i{ k + 1 }; i < matrix.size(); i++) {
			tmp = -mx_1[i][k] / mx_1[k][k];
			for (int j{}; j < matrix.size(); j++) {
				mx_1[i][j] += mx_1[k][j] * tmp;
			}
		}
	}

	tmp = 1;

	for (int i{}; i < mx_1.size(); i++) {
		tmp *= mx_1[i][i];
	}

	return tmp;

	mx_1.clear();
}

/// Вычисление обратной матрицы, замена старой на обратную
void Matrix::inverse_mx() {
	if (matrix.size() != matrix[0].size()) throw invalid_argument("Матрица должна быть квадратной.");
	else if (this->determinant_mx() == 0) throw invalid_argument("Определитель равен нулю.");

	int n = matrix.size();

	vector<vector<double>> l(n, vector<double>(n));
	vector<vector<double>> u(n, vector<double>(n));
	vector<vector<double>> x(n, vector<double>(n));
	vector<vector<double>> y(n, vector<double>(n));
	vector<vector<double>> mx_inv(n, vector<double>(n));

	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			i == j ? u[i][j] = 1 : u[i][j] = 0;
		}
	}

	for (int i{}; i < n; i++) {
		l[i][0] = matrix[i][0];
	}

	for (int j{ 1 }; j < n; j++) {
		u[0][j] = matrix[0][j] / l[0][0];
	}

	for (int k{ 1 }; k < n; k++) {
		for (int i{ k }; i < n; i++) {
			l[i][k] = matrix[i][k];
			for (int m{}; m < k; m++) {
				l[i][k] -= l[i][m] * u[m][k];
			}
		}
		if (k <= n - 2) {
			for (int j{ k + 1 }; j < n; j++) {
				u[k][j] = matrix[k][j];
				for (int m{}; m < k; m++) {
					u[k][j] -= l[k][m] * u[m][j];
				}
				u[k][j] /= l[k][k];
			}
		}
	}

	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			if (j > i) {
				y[i][j] = 0;
			}
			else if (j == i) {
				y[i][j] = 1 / l[i][i];
			}
			else if (j < i) {
				y[i][j] = 0;
				for (int m{ j }; m < i; m++) {
					y[i][j] -= l[i][m] * y[m][j];
				}
				y[i][j] /= l[i][i];
			}
		}
	}

	for (int i{ n - 1 }; i >= 0; i--) {
		for (int j{ n - 1 }; j >= 0; j--) {
			if (j < i) {
				x[i][j] = 0;
			}
			else if (j == i) {
				x[i][j] = 1;
			}
			else if (j > i) {
				x[i][j] = 0;
				for (int m{ i + 1 }; m <= j; m++) {
					x[i][j] -= u[i][m] * x[m][j];
				}
			}
		}
	}

	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			mx_inv[i][j] = 0;
			for (int m{}; m < n; m++) {
				mx_inv[i][j] += x[i][m] * y[m][j];
			}
		}
	}

	matrix = mx_inv;

	l.clear();
	u.clear();
	x.clear();
	y.clear();
	mx_inv.clear();
}

/// Тестирование методов класса
void test_Matrix_class() {
	{
		Matrix mx_1{ 2, 3 };
		Matrix mx_2{ 2, 3 };
		Matrix mx_3{ 2, 3 };

		mx_1.fill_one_value(2.3);
		cout << "mx_1 = \n";
		mx_1.print_mx();

		mx_2.fill_one_value(3.2);
		cout << "mx_2 = \n";
		mx_2.print_mx();

		mx_1.sum_mx(mx_2);
		assert(abs(mx_1.matrix[0][0] - 5.5) < eps);
		cout << "mx_1 = mx_1 + mx_2 = \n";
		mx_1.print_mx();

		mx_1.dif_mx(mx_2);
		assert(abs(mx_1.matrix[0][0] - 2.3) < eps);
		cout << "mx_1 = mx_1 - mx_2 = \n";
		mx_1.print_mx();

		mx_3 = mx_1 + mx_2;
		assert(abs(mx_3.matrix[0][0] - 5.5) < eps);
		cout << "mx_3 = mx_1 + mx_2 = \n";
		mx_3.print_mx();

		mx_3 -= mx_2;
		assert(abs(mx_3.matrix[0][0] - 2.3) < eps);
		cout << "mx_3 -= mx_2 = \n";
		mx_3.print_mx();

		mx_3 += mx_2;
		assert(abs(mx_3.matrix[0][0] - 5.5) < eps);
		cout << "mx_3 += mx_2 = \n";
		mx_3.print_mx();

		mx_3 = mx_2 - mx_1;
		assert(abs(mx_3.matrix[0][0] - 0.9) < eps);
		cout << "mx_3 = mx_2 - mx_1 = \n";
		mx_3.print_mx();

		mx_1.scalar_multiply(2);
		assert(abs(mx_1.matrix[0][0] - 4.6) < eps);
		cout << "mx_1 * 2 = \n";
		mx_1.print_mx();

		mx_1.transposition_mx();
		assert(abs(mx_1.matrix[2][1] - 4.6) < eps);
		cout << "transposed mx_1 = \n";
		mx_1.print_mx();
	}
	
	{
		Matrix mx_4{ 2, 2 };
		vector<vector<double>> l{ vector<double>{ 1, 2 }, vector<double>{ 2, 1 } };
		mx_4.matrix = l;
		cout << "mx_4 = \n";
		mx_4.print_mx();

		Matrix mx_5{ 2, 2 };
		vector<vector<double>> h{ vector<double>{ 3, 2 }, vector<double>{ 2, 3 } };
		mx_5.matrix = h;
		cout << "mx_5 = \n";
		mx_5.print_mx();

		Matrix mx_6{ 2, 2 };

		mx_6 = mx_4.matrix_multiply(mx_5);
		assert(abs(mx_6.matrix[0][0] - 7) < eps && abs(mx_6.matrix[0][1] - 8) < eps);
		cout << "mx_6 = mx_4.matrix_multiply(mx_5) = \n";
		mx_6.print_mx();
		
		mx_6 = mx_4 * mx_5;
		assert(abs(mx_6.matrix[0][0] - 7) < eps && abs(mx_6.matrix[0][1] - 8) < eps);
		cout << "mx_6 = mx_4 * mx_5 = \n";
		mx_6.print_mx();

		mx_4 *= mx_5;
		assert(abs(mx_6.matrix[0][0] - 7) < eps && abs(mx_6.matrix[0][1] - 8) < eps);
		cout << "mx_4 *= mx_5 = \n";
		mx_4.print_mx();
	}
	
	{
		Matrix mx_7{ 3, 3 };
		vector<vector<double>> temp{ vector<double>{ 1, 2, 3 }, vector<double>{ 2, 1, 3 }, vector<double>{ 4, 4, 7 } };
		mx_7.matrix = temp;
		cout << "mx_7 = \n";
		mx_7.print_mx();

		double det = mx_7.determinant_mx();
		assert(abs( det - 3.0) < eps);
		cout << "determinant(mx_7) = " << det << "\n";

		mx_7.inverse_mx();
		assert(abs(mx_7.matrix[0][2] - 1) < eps);
		cout << "Inverse mx_7 = \n";
		mx_7.print_mx();
	}
}