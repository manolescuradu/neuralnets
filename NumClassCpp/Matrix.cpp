#include "Matrix.h"

#include <iomanip>
#include <sstream>
#include <exception>
#include <cassert>

Matrix::Matrix(uint32_t rows, uint32_t cols)
	: rows_(rows), cols_(cols), m_()
{
	m_.resize(rows_ * cols_);
}

Matrix::Matrix(uint32_t rows, uint32_t cols, const std::vector<float>& in)
	: Matrix(rows, cols)
{
	assert(in.size() == rows * cols);
	std::copy(in.begin(), in.end(), m_.begin());
}

float& Matrix::at(uint32_t x, uint32_t y)
{
	assert(x >= 0 && x < rows_ && y >= 0 && y < cols_);

	return m_[x * cols_ + y];
}

Matrix Matrix::operator*(Matrix& v)
{
	assert(cols_ == v.rows_);

	Matrix prod(rows_, v.cols_);

	for (uint32_t i = 0; i < prod.rows_; ++i)
		for (uint32_t j = 0; j < prod.cols_; ++j)
			for (uint32_t k = 0; k < cols_; ++k)
				prod.at(i, j) += this->at(i, k)* v.at(k, j);

	return prod;
}

void Matrix::print()
{
	for (int x = 0; x < m_.size(); ++x) {
		if (x % cols_ == 0)
			std::cout << std::endl;
		std::cout << std::setw(4) << m_[x];
	}
	std::cout << std::endl;
}
