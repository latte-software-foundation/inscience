#ifndef TYPES_H
#define TYPES_H

namespace math{
	typedef unsigned int natural;

	#ifdef DOUBLE_PRECISION
		typedef double real;
	#else
		typedef float real;
	#endif

	typedef int integer;
}


#endif