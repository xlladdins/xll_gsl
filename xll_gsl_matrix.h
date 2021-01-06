// xll_gsl_matrix.h - GSL matrixs
#pragma once
#include <gsl/gsl_matrix_double.h>

namespace xll::gsl {

	template<class X>
	struct matrix : public gsl_matrix {
		// construct from FP type
		matrix(X* pm, size_t tda = static_cast<size_t>(pm->rows))
			: gsl_matrix{ static_cast<size_t>(pm->rows), static_cast<size_t>(pm->columns),
			  tda, pm->array, nullptr, false }
		{ }
		matric(const matric&) = default;
		matric& operator=(const matric&) = default;
		~matrix()
		{ }
	};

}