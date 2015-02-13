#include <iostream>
#include "math/scalar.h"

int main(int argc, char const *argv[]){
	math::scalar<> f(4.5f);
	math::scalar<math::natural> r(4.5f);
	r = 10;
	std::cout << r << " " << f << std::endl;
	return 0;
}