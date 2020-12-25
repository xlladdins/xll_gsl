// xll_gsl_vector.h - GSL vectors
#pragma once
#include <gsl/gsl_vector_double.h>

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
	struct vector : public gsl_vector {
		vector(X* pv)
			: gsl_vector{ static_cast<size_t>(pv->rows * pv->columns), 1, pv->array, nullptr, false }
		{ }
		~vector()
		{ }
	};

}

