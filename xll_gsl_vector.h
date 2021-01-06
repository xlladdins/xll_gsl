// xll_gsl_vector.h - GSL vectors
#pragma once
#include <gsl/gsl_vector_double.h>
#include "xll_gsl.h"

namespace xll::gsl {

	template<class X>
	struct vector : public gsl_vector {
		// construct from FP type
		vector(X* pv)
			: gsl_vector{ static_cast<size_t>(pv->rows * pv->columns), 1, pv->array, nullptr, false }
		{ }
		vector(const vector&) = default;
		vector& operator=(const vector&) = default;
		~vector()
		{ }
	};

}

