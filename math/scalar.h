#ifndef SCALAR_H
#define SCALAR_H

#include "types.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

namespace math{
	template<typename number> class scalar;
}

template<typename number=math::real> std::ostream& operator<<(std::ostream& output,math::scalar<number> const& value);

namespace math{
	template<typename number=real> class scalar{
		public:
			scalar();
			scalar(number* pointer);
			scalar(number value);
			scalar(const scalar<number>&);
			~scalar();
			scalar<number>& operator=(number value);
		//friends:
			template<typename Number> friend std::ostream& ::operator<<(std::ostream&,const scalar<Number>&);
		private:
			number* address;
	};
}


#include "scalar.cpp"
#endif