// xll_gsl.cpp - GSL add-in
#include <gsl/gsl_errno.h>
#include "xll_gsl.h"

void xll_gsl_handler(const char* reason, const char* file, int line, int gsl_errno)
{
	static char buf[1024];

	sprintf_s(buf, "GSL error[%d]: file: %s line: %d reason: %s", gsl_errno, file, line, reason);

	throw std::runtime_error(buf);
}
int handler = [](){ gsl_set_error_handler(xll_gsl_handler); return 0; }();

using namespace xll;

#ifdef _DEBUG
#include <cassert>
#include <gsl/gsl_sf_exp.h>
int test_gsl()
{
	{
		gsl_sf_result result;
		double x = 1;
		int err = gsl_sf_expm1_e(x, &result);
		assert(err == GSL_SUCCESS);
		assert(result.val == gsl_sf_expm1(x));
	}

	return 0;
}
int test_gsl_ = test_gsl();
#endif // _DEBUG