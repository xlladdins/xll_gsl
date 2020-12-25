#!/usr/bin/python3
# Generate C++ files to be used with the xll_gsl library

# texi document directory
gsl_doc = '/mnt/c/Users/kalx/source/repos/gsl/doc/'

def xll_prolog(pre):
	return f'''// xll_{pre}.cpp - Excel add-in for functions in the {cat} category.
// Uncomment to build for pre 2007 Excel
//#define XLOPERX XLOPER
#include <cmath>
#include "xll/xll/xll.h"
using namespace xll;
	'''

def xll_gsl_sf_addin(ret, name, *args):
	namehelp = []
	for arg in args:
		xllarg.append(f'{xlname(arg), {argname}, {arghelp})') 

	return f'''
AddIn xai_gsl_{name}(
	Function(xll_typ[ret], xll_gsl_sf_{name}, "GSL.SF.{name})
	.Args({
		{join(',\n', namehelp)}
	})
	.FunctionHelp({help})
	.Category({cat})
	.Documentation({doc})
);
	'''

def xll_gsl_sf_function(ret, name, *args):
	namehelp = []
	for arg in args:
		xllarg.append(f'xlname(arg) {argname}') 

	return f'''
{xll_type(ret) WINAPI xll_gsl_sf_{name}({join ...})
{
#pragma XLLEXPORT
	double result = XLL_NAN;

	try {
	}
	catch (const std::exception& er) {
		XLL_ERROR(ex.what());
	}

	return result;
}
	'''

def xll_gsl_sf(ret, name, *args):

