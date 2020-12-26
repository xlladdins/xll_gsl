// xll_gsl_sf.cpp - special functions
#include "xll_gsl.h"
#include "xll_gsl_sf.h"
#include <gsl/gsl_sf_airy.h>
#include <gsl/gsl_sf_zeta.h>

using namespace xll;

AddIn xai_gsl_sf_airy_Ai(
	Function(XLL_FP, "xll_sf_airy_Ai", "GSL.SF.airy_Ai")
	.Args({
		Arg(XLL_DOUBLE, "x", "is a value."),
		Arg(XLL_WORD, "[mode]", "is the mode."),
	})
	.FunctionHelp("Return the Airy function.")
	.Category(CATEGORY)
	.HelpTopic("http://www.gnu.org/software/gsl/doc/html/specfunc.html#airy-functions")
);
_FPX*  WINAPI xll_sf_airy_Ai(double x, gsl_mode_t mode)
{
#pragma XLLEXPORT
	static FPX_<2> result;

	try {
		gsl_sf_result sf_result;
		//mode = GSL_PREC_DOUBLE;
		int err = gsl_sf_airy_Ai_e(x, mode, &sf_result);
		ensure(err == GSL_SUCCESS);
		result.array[0] = sf_result.val;
		result.array[1] = sf_result.err;
		
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
	}

	return &result;
}

AddIn xai_gsl_sf_zeta(
	Function(XLL_FP, "xll_sf_zeta", "GSL.SF.zeta")
	.Args({
		Arg(XLL_DOUBLE, "x", "is a value."),
	})
	.FunctionHelp("Return the zeta function.")
	.Category(CATEGORY)
	.HelpTopic("http://www.gnu.org/software/gsl/doc/html/specfunc.html#zeta-functions")
);
_FPX* WINAPI xll_sf_zeta(double x)
{
#pragma XLLEXPORT
	static FPX_<2> result;

	try {
		gsl_sf_result sf_result;
		int err = gsl_sf_zeta_e(x,&sf_result);
		ensure(err == GSL_SUCCESS);
		result.array[0] = sf_result.val;
		result.array[1] = sf_result.err;

	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
		result.array[0] = result.array[1] = XLL_NAN;
	}

	return &result;
}
