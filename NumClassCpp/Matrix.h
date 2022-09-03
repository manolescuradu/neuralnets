#pragma once

#include <cstdint>
#include <vector>

class Matrix
{
public:
	Matrix(uint32_t rows, uint32_t cols);

	float& at(int x, int y);

	void Matrix::print();
private:
	uint32_t rows_;
	uint32_t cols_;

	std::vector<float> m_;
};