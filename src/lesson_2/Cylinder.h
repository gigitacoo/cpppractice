/*
 * Cylinder.h
 *	圆柱体
 *  Created on: 2021年3月16日
 *      Author: cuijk
 */

#ifndef SRC_LESSON_2_CYLINDER_H_
#define SRC_LESSON_2_CYLINDER_H_

class Cylinder {
public:
	Cylinder();
	//圆面积 pi*r*r
	double cycleArea();
	//圆周长2*pi*r
	double cycleLength();
	//圆柱体积 pi*r*r * h
	double cylinderVolume();
	//圆柱面积 2*pi*r * h
	double cylinderArea();
private:
	//底圆半径
	double r;
	//圆柱高
	double h;
};

#endif /* SRC_LESSON_2_CYLINDER_H_ */
