#ifndef SCALAR_SOURCE
#define SCALAR_SOURCE

#include "scalar.h"

namespace math{
	template<typename number> scalar<number>::scalar():address(new number){

	}

	template<typename number> scalar<number>::scalar(number* pointer):address(pointer){

	}

	template<typename number> scalar<number>::scalar(number value):address(new number(value)){

	}

	template<typename number> scalar<number>::scalar(const scalar<number>&):address(new number){

	}

	template<typename number> scalar<number>::~scalar(){
		delete address;
	}

	template<typename number> inline scalar<number>& scalar<number>::operator=(number n){
		*address = n;
	}
}

template<typename number=math::real> inline std::ostream& operator<<(std::ostream& out,math::scalar<number> const& s){
	return out << *(s.address);
}

#endif