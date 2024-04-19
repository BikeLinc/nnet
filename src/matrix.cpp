#include "matrix.h"

template <typename T>
Mat<T>::Mat(uint _rows, uint _cols) : m_rows(_rows), m_cols(_cols), m_data(_rows* _cols) {}

template <typename T>
uint Mat<T>::rows() { return m_rows; }

template <typename T>
uint Mat<T>::cols() { return m_cols; }

template <typename T>
T& Mat<T>::operator()(uint i, uint j) {
	i--;
	j--;
	if (i < 0 || j < 0)
		throw std::out_of_range("Matrix index out of bounds");
	return m_data[i * m_cols + j];
}

template <typename T>
const T& Mat<T>::operator()(uint i, uint j) const {
	i--;
	j--;
	if (i < 0 || j < 0)
		throw std::out_of_range("Matrix index out of bounds");
	return m_data[i * m_cols + j];
}

template <typename T>
Mat<T> Mat<T>::operator+(Mat const& mat) {
	if (m_cols != mat.m_cols || m_rows != mat.m_rows)
		throw std::logic_error("Matrix dimensions incompatible");

	Mat res(m_rows, m_cols);
	for (uint i = 1; i < m_rows + 1; i++) {
		for (uint j = 1; j < m_cols + 1; j++) {
			res(i, j) = (*this)(i, j) + mat(i, j);
		}
	}
	return res;
}

template <typename T>
Mat<T> Mat<T>::operator*(T const& scalar) {
	Mat res(m_rows, m_cols);
	for (uint i = 1; i < m_rows; i++) {
		for (uint j = 1; j < m_cols; j++) {
			res(i, j) = (*this)(i, j) * scalar;
		}
	}
	return res;
}

template <typename T>
Mat<T> Mat<T>::operator*(Mat const& mat) {

	if (m_rows != mat.m_cols)
		throw std::logic_error("Matrix dimensions incompatible");

	Mat res(m_rows, mat.m_cols);
	for (uint i = 1; i < m_rows + 1; i++) {
		for (uint j = 1; j < mat.m_cols + 1; j++) {
			res(i, j) = 0;
			for (uint k = 1; k < m_cols + 1; k++) {
				res(i, j) += (*this)(i, k) * mat(k, j);
			}
		}
	}

	return res;

}

template <typename T>
Mat<T> Mat<T>::operator-(Mat const& mat) {
	if (m_cols != mat.m_cols || m_rows != mat.m_rows)
		throw std::logic_error("Matrix dimensions incompatible");

	Mat res = mat;
	res = res * -1;
	res = res + *this;
	return res;
}

template <typename T>
Mat<T> Mat<T>::transpose() const {
	Mat res(m_rows, m_cols);

	for (uint i = 1; i < m_rows + 1; i++) {
		for (uint j = 1; j < m_cols + 1; j++) {
			res(i, j) = (*this)(j, i);
		}
	}
	return res;
}

template <typename T>
void Mat<T>::print() {
	for (uint i = 1; i < m_rows + 1; i++) {
		std::cout << "[\t";
		for (uint j = 1; j < m_cols + 1; j++) {
			std::cout << std::fixed << std::setprecision(2) << (*this)(i, j) << "\t\t";
		}
		std::cout << "]\n";
	}
}

template <typename T>
Random<T>::Random(uint _rows, uint _cols) {
	Mat<T> res(_rows, _cols);
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<T> distribution(-1, 1); // 0 Mean, +/-1 Amplitude
	for (uint i = 1; i < _rows + 1; i++) {
		for (uint j = 1; j < _cols + 1; j++) {
			res(i, j) = distribution(generator);
		}
	}
	return res;
}

template <typename T>
Random<T>::Random(uint _rows, uint _cols, const T& minVal, const T& maxVal) {
	if (minVal >= maxVal)
		throw std::logic_error("Minimum value cannot be greater than maximum value");
	Mat<T> res(_rows, _cols);
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<T> distribution(minVal, maxVal); // 0 Mean, +/-1 Amplitude
	for (uint i = 1; i < _rows + 1; i++) {
		for (uint j = 1; j < _cols + 1; j++) {
			res(i, j) = distribution(generator);
		}
	}
	return res;
}

template <typename T>
Ones<T>::Ones(uint _rows, uint _cols) {
	Mat<T> res(_rows, _cols);
	for (uint i = 1; i < _rows + 1; i++) {
		for (uint j = 1; j < _cols + 1; j++) {
			res(i, j) = 1;
		}
	}
	return res;
}

template <typename T>
Zeros<T>::Zeros(uint _rows, uint _cols) {
	Mat<T> res(_rows, _cols);
	for (uint i = 1; i < _rows + 1; i++) {
		for (uint j = 1; j < _cols + 1; j++) {
			res(i, j) = 0;
		}
	}
	return res;
}

template <typename T>
Identity<T>::Identity(uint size) {
	Mat<T> res = Zeros<T>(size, size);
	for (uint i = 1; i < size + 1; i++) {
		res(i, i) = 1;
	}
	return res;
}