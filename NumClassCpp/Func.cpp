#include "Func.h"
#include "Matrix.h"

#include <cmath>
#include <cassert>

Matrix softmax(Matrix& in)
{
	assert(in.cols() == 1);

	Matrix out = in;

	float sum_exp = 0;
	for (int i = 0; i < out.rows(); ++i)
		sum_exp += exp(out.at(i, 0));

	for (int i = 0; i < out.rows(); ++i)
		out.at(i, 0) = exp(out.at(i, 0)) / sum_exp;

	return out;
}
