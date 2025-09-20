#pragma once
#include <Eigen/Core>
#include <Eigen/Geometry>

namespace spaft{

class Spacecraft{
public:

	// В функции передается ссылка на вектора и матрицы, чтобы не создавать новый объект
	void setInertiaMatrix(const Eigen::Matrix3d& I_body);
	void setInertiaDiagonal(float Ixx, float Iyy, float Izz); // Задать диагональный тензор инерции
	void setInertiaCuboid(float density, float a, float b, float c); // Тензор инерции прямоугольника
	
	void setOreintationMatrix(const Eigen::Matrix3d& R); // Задать новую матрицу поворота
	void setAngularVelocityMatrix(const Eigen::Matrix3d& W); // Задать новую угловую скорость

	void setInternalMoment(const Eigen::Vector3d& int_moment); // Задать внутренний момент
	void setExternalMoment(const Eigen::Vector3d& ext_moment); // Задать внешний момент
	
	const Eigen::Matrix3d& I() const { return I_;}
	const Eigen::Matrix3d& Iinv() const {return I_inv_;}
	const Eigen::Matrix3d& R() const {return R_;}
	const Eigen::Vector3d& W() const {return W_;}


private:
	std::string name = "Spacecraft";
	float mass = 0;
	Eigen::Matrix3d I_ = Eigen::Matrix3d::Identity(); // Тензор инерции в собственных координатах КА
	Eigen::Matrix3d I_inv_ = Eigen::Matrix3d::Identity(); // Обратный тензор инерции в координатах КА

	Eigen::Matrix3d R_ = Eigen::Matrix3d::Identity(); // Матрица поворота
	Eigen::Vector3d W_ = Eigen::Vector3d::Zero(); // Вектор угловой скорости
	Eigen::Vector3d L_ = Eigen::Vector3d::Zero(); // Вектор кинетического момента

	Eigen::Vector3d intM = Eigen::Vector3d::Zero();
	Eigen::Vector3d extM = Eigen::Vector3d::Zero();
};
}
