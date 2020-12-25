// xll_gsl_matrix.h - GSL matrixs
#pragma once
#include <gsl/gsl_matrix_double.h>

typedef struct _FP
{
	unsigned short int rows;
	unsigned short int columns;
	double array[1];        /* Actually, array[rows][columns] */
} FP;

typedef struct _FP12
{
	signed int rows;
	signed int columns;
	double array[1];        /* Actually, array[rows][columns] */
} FP12;

namespace xll::gsl {

	template<class X = FP12>
	struct matrix : public gsl_matrix {
		matrix(X* pm, size_t tda = static_cast<size_t>(pm->rows))
			: gsl_matrix{ static_cast<size_t>(pm->rows), static_cast<size_t>(pm->columns),
			  tda, pm->array, nullptr, false }
		{ }
		~matrix()
		{ }
	};

}