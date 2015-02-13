#include <iostream>
#include "math/scalar.h"
#define DOUBLE_PRECISION
int main(int argc, char const *argv[]){
	math::scalar<float> f(4.5f);
	math::scalar<> d(3.75);
	math::scalar<math::natural> r(4.5f);
	math::scalar<int> k;
	k = 63;
	std::cout << r << std::endl;
	r = 10;
	std::cout << d << " " << r << " " << f << " " << k << std::endl;
	return 0;
}