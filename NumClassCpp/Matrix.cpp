#include "Matrix.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <exception>

Matrix::Matrix(uint32_t rows, uint32_t cols)
	: rows_(rows), cols_(cols), m_()
{
	m_.resize(cols_ * rows_);
}

float& Matrix::at(int x, int y)
{
	if (x < 0 || x > rows_ || y < 0 || y > cols_) {
		std::ostringstream oss;
		oss << "Invalid coordinates " << x << "," << y
			<< " for matrix of size " << rows_ << "," << cols_ << "!\n";

		throw std::runtime_error(oss.str());
	}

	return m_[x * cols_ + y];
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
