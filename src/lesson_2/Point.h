/*
 * Point.h
 *
 *  Created on: 2021年3月15日
 *      Author: cuijk
 */

class Point {
public:
	Point();
	Point(int x, int y);
	//计算给点坐标到0,0的距离
	double lengthToZero();

	//计算两点间的距离
	double lengthWith2Point(Point p1, Point p2);
	
	//是否是三角形
	bool isTriangle(Point p1, Point p2, Point p3);
	
	//计算斜率
	double linePercent(Point p1, Point p2);
	
	//计算点是否在线上
	bool isOnline(Point p1);
private:
	int x;	//横坐标
	int y;	//纵坐标
};
