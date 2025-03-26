// xll_gsl_sf.cpp - special functions
#include "xll_gsl.h"
#include "xll_gsl_sf.h"
#include <gsl/gsl_sf_airy.h>
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_sf_psi.h>
#include <gsl/gsl_sf_zeta.h>

using namespace xll;

AddIn xai_gsl_sf_airy_Ai(
	Function(XLL_FP, "xll_sf_airy_Ai", "GSL.SF.AIRY_AI")
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

c
AddIn xai_gsl_sf_beta(
	Function(XLL_DOUBLE, "xll_gsl_sf_beta", "GSL.SF.BETA")
	.Args({
		Arg(XLL_DOUBLE, "a", "is a parameter."),
		Arg(XLL_DOUBLE, "b", "is a parameter."),
		})
		.FunctionHelp("Return the beta function")
	.Category("GSL")
);
double WINAPI xll_gsl_sf_beta(double a, double b)
{
#pragma XLLEXPORT
	double result = XLL_NAN;

	try {
		result = gsl_sf_beta(a, b);
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
	}

	return result;
}

AddIn xai_gsl_sf_beta_inc(
	Function(XLL_DOUBLE, "xll_gsl_sf_beta_inc", "GSL.SF.BETA_INC")
	.Args({
		Arg(XLL_DOUBLE, "a", "is a parameter."),
		Arg(XLL_DOUBLE, "b", "is a parameter."),
		Arg(XLL_DOUBLE, "u", "is a number."),
		})
		.FunctionHelp("Return the incomplete beta function")
	.Category("GSL")
);
double WINAPI xll_gsl_sf_beta_inc(double a, double b, double u)
{
#pragma XLLEXPORT
	double result = XLL_NAN;

	try {
		result = gsl_sf_beta_inc(a, b, u);
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
	}

	return result;
}

AddIn xai_gsl_sf_psi(
	Function(XLL_DOUBLE, "xll_gsl_sf_psi_n", "GSL.SF.PSI")
	.Args({
		Arg(XLL_SHORT, "n", "is the derivative."),
		Arg(XLL_DOUBLE, "x", "is a number."),
	})
	.FunctionHelp("Return the derivatives of the digamma function.")
	.Category("GSL")
);
double WINAPI xll_gsl_sf_psi_n(SHORT n, double x)
{
#pragma XLLEXPORT
	double result = XLL_NAN;

	try {
		result = gsl_sf_psi_n(n, x);
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
	}

	return result;
}


AddIn xai_gsl_sf_zeta(
	Function(XLL_FP, "xll_sf_zeta", "GSL.SF.ZETA")
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
