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
	.Arguments({
		Arg(XLL_DOUBLE, "x", "is a value."),
		Arg(XLL_WORD, "[mode]", "is the mode."),
	})
	.FunctionHelp("Return the Airy function.")
	.Category(CATEGORY)
	.HelpTopic("http://www.gnu.org/software/gsl/doc/html/specfunc.html#airy-functions")
);
_FP12*  WINAPI xll_sf_airy_Ai(double x, gsl_mode_t mode)
{
#pragma XLLEXPORT
	static FPX result(1,2);

	try {
		gsl_sf_result sf_result;
		//mode = GSL_PREC_DOUBLE;
		int err = gsl_sf_airy_Ai_e(x, mode, &sf_result);
		ensure(err == GSL_SUCCESS);
		result[0] = sf_result.val;
		result[1] = sf_result.err;
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
		result[0] = result[1] = std::numeric_limits<double>::quiet_NaN();
	}

	return result.get();
}

AddIn xai_gsl_sf_beta(
	Function(XLL_DOUBLE, "xll_gsl_sf_beta", "GSL.SF.BETA")
	.Arguments({
		Arg(XLL_DOUBLE, "a", "is a parameter."),
		Arg(XLL_DOUBLE, "b", "is a parameter."),
		})
		.FunctionHelp("Return the beta function")
	.Category("GSL")
);
double WINAPI xll_gsl_sf_beta(double a, double b)
{
#pragma XLLEXPORT
	double result = std::numeric_limits<double>::quiet_NaN();

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
	.Arguments({
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
	double result = std::numeric_limits<double>::quiet_NaN();

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
	.Arguments({
		Arg(XLL_SHORT, "n", "is the derivative."),
		Arg(XLL_DOUBLE, "x", "is a number."),
	})
	.FunctionHelp("Return the derivatives of the digamma function.")
	.Category("GSL")
);
double WINAPI xll_gsl_sf_psi_n(SHORT n, double x)
{
#pragma XLLEXPORT
	double result = std::numeric_limits<double>::quiet_NaN();

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
	.Arguments({
		Arg(XLL_DOUBLE, "x", "is a value."),
	})
	.FunctionHelp("Return the zeta function.")
	.Category(CATEGORY)
	.HelpTopic("http://www.gnu.org/software/gsl/doc/html/specfunc.html#zeta-functions")
);
_FP12* WINAPI xll_sf_zeta(double x)
{
#pragma XLLEXPORT
	static FPX result(1,2);

	try {
		gsl_sf_result sf_result;
		int err = gsl_sf_zeta_e(x,&sf_result);
		ensure(err == GSL_SUCCESS);
		result[0] = sf_result.val;
		result[1] = sf_result.err;

	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());
		result[0] = result[1] = std::numeric_limits<double>::quiet_NaN();
	}

	return result.get();
}
