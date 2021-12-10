/*
 * Point.cpp
 *
 *  Created on: 2021年3月15日
 *      Author: cuijk
 */

#include "Point.h"
#include <cmath>
using namespace std;
Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}
double Point::lengthToZero(){
	double len = sqrt(this->x * this->x + this->y * this->y);
	return len;
}
double Point::lengthWith2Point(Point p1, Point p2){
	int x = abs(double(p1.x - p2.x));
	int y = abs(double(p1.y - p2.y));
	double len = sqrt(x*x + y*y);
	return len;
}

bool Point::isTriangle(Point p1, Point p2, Point p3){
	double x = lengthWith2Point(p1,p2);
	double y = lengthWith2Point(p1,p3);
	double z = lengthWith2Point(p2,p3);
	if(x + y < z || x + z < y || z+y < x){
		return false;
	}
	return true;
}
double Point::linePercent(Point p1, Point p2){
	//斜率计算公式d=y1-y2/x1-x2
	double d = (p2.y - p1.y) / (p2.x - p1.x);
	return d;
}

bool Point::isOnline(Point p1){
	//斜率计算公式d=y1-y2/x1-x2
	double d = 0;
	return d;
}
