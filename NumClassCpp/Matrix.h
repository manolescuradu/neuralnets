#pragma once

#include <iostream>
#include <cstdint>
#include <vector>

class Matrix
{
public:
	Matrix(uint32_t rows, uint32_t cols);
	Matrix(uint32_t rows, uint32_t cols, const std::vector<float>& in);

	float& at(uint32_t x, uint32_t y);

	Matrix operator*(Matrix& v);

	void Matrix::print();

	uint32_t rows() { return rows_; }
	uint32_t cols() { return cols_; }

private:
	uint32_t rows_;
	uint32_t cols_;

	std::vector<float> m_;
};