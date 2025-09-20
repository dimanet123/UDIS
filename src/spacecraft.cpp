#include "spacecraft.h"

namespace spaft {

void Spacecraft::setInertiaMatrix(const Eigen::Matrix3d& I_body) {
	I_ = I_body;
	I_inv_ = I_.inverse();
}

void Spacecraft::setInertiaDiagonal(float Ixx, float Iyy, float Izz) {
	Eigen::VectorXd d(3);
	d << Ixx, Iyy, Izz;

	I_ = d.asDiagonal();
	I_inv_ = I_.inverse();
};

void Spacecraft::setInertiaCuboid(float density, float a, float b, float c) {
	float V = a*b*c;
	mass = V*density;
	
	float Ixx = 1.0/12*mass*(b*b+c*c);
	float Iyy = 1.0/12*mass*(a*a+c*c);
	float Izz = 1.0/12*mass*(a*a+b*b);

	Eigen::VectorXd d(3);
	d << Ixx, Iyy, Izz;

	I_ = d.asDiagonal();
	I_inv_ = I_.inverse();
};
}
