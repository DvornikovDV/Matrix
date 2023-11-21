// Дворников Даниил
#include "Matrix_class.h"

Matrix::Matrix(int n, int m) {
	matrix.resize(n);
	for (int i{}; i < n; i++) {
		matrix[i].resize(m);
	}
}

void Matrix::fill_one_value(double v) {
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] = v;
		}
	}
}

void Matrix::fill_rand() {
	srand(time(0));
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] = (rand() % 201 - 100) + (rand() % 101 / 100.0);
		}
	}
}

void Matrix::sum_mx(const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] += mx_1.matrix[i][j];
		}
	}
}

Matrix& Matrix::operator + (const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	Matrix mx_r(matrix.size(), matrix[0].size());
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			mx_r.matrix[i][j] = matrix[i][j] + mx_1.matrix[i][j];
		}
	}
	return mx_r;
}

Matrix& Matrix::operator += (const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] += mx_1.matrix[i][j];
		}
	}
	return *this;
}

void Matrix::dif_mx(const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] -= mx_1.matrix[i][j];
		}
	}
}

Matrix& Matrix::operator - (const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	Matrix mx_r(matrix.size(), matrix[0].size());
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			mx_r.matrix[i][j] = matrix[i][j] - mx_1.matrix[i][j];
		}
	}
	return mx_r;
}

Matrix& Matrix::operator -= (const Matrix& mx_1) {
	if (matrix.size() != mx_1.matrix.size() && matrix[0].size() != mx_1.matrix[0].size()) throw invalid_argument("Размеры матриц не равны.");
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] -= mx_1.matrix[i][j];
		}
	}
	return *this;
}

void Matrix::scalar_multiply(double scalar) {
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			matrix[i][j] *= scalar;
		}
	}
}

Matrix& Matrix::matrix_multiply(const Matrix& mx_1) const {
	if (matrix[0].size() != mx_1.matrix.size()) throw invalid_argument("Количество строк первой матрицы не равно количеству столбцов второй матрицы.");

	Matrix result(matrix.size(), mx_1.matrix[0].size());
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			for (int m{}; m < mx_1.matrix.size(); m++) {
				result.matrix[i][j] += matrix[i][m] * mx_1.matrix[m][j];
			}
		}
	}
	return result;
}

Matrix& Matrix::operator * (const Matrix& mx_1) const {
	if (matrix[0].size() != mx_1.matrix.size()) throw invalid_argument("Количество строк первой матрицы не равно количеству столбцов второй матрицы.");
	
	Matrix mx_r(matrix.size(), mx_1.matrix[0].size());
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			for (int m{}; m < mx_1.matrix.size(); m++) {
				mx_r.matrix[i][j] += matrix[i][m] * mx_1.matrix[m][j];
			}
		}
	}
	return mx_r;
}

Matrix& Matrix::operator *= (const Matrix& mx_1) {
	if (matrix[0].size() != mx_1.matrix.size()) throw invalid_argument("Количество строк первой матрицы не равно количеству столбцов второй матрицы.");
	Matrix mx_r(matrix.size(), matrix[0].size());
	for (int i{}; i < matrix.size(); i++) {
		for (int j{}; j < matrix[0].size(); j++) {
			for (int m{}; m < mx_1.matrix.size(); m++) {
				mx_r.matrix[i][j] += matrix[i][m] * mx_1.matrix[m][j];
			}
		}
	}
	*this = mx_r;
	return *this;
}

void Matrix::transposition_mx() {
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

double Matrix::determinant_mx() const {
	double tmp{};
	vector<vector<double>> mx_1(matrix.size(), vector<double>(matrix[0].size()));
	mx_1 = matrix;
	for (int k{}; k < matrix.size() - 1; k++) {
		for (int i{ k + 1 }; i < matrix.size(); i++) {
			tmp = -matrix[i][k] / matrix[k][k];
			for (int j{}; j < matrix.size(); j++) {
				mx_1[i][j] += matrix[k][j] * tmp;
			}
		}
	}

	tmp = 1;

	for (int i{}; i < mx_1.size(); i++) {
		tmp *= mx_1[i][i];
	}

	return tmp;
}

void Matrix::inverse_mx() {
	if (matrix.size() != matrix[0].size()) throw invalid_argument("Матрица должна быть квадратной");
	else if (this->determinant_mx() == 0) throw invalid_argument("Определитель равен нулю");

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