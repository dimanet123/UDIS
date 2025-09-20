#include "spacecraft.h"
#include <iostream>

int main() {
	spaft::Spacecraft sc;

	sc.setInertiaCuboid(2700.0, 1.0, 2.0, 3.0);

	std::cout << "Mass		" << sc.I() << std::endl;

	return 0;
}

