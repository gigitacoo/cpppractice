/*
 * OverloadTest.cpp
 *
 *  Created on: 2021年3月14日
 *      Author: cuijk
 */

#include "OverloadTest.h"

OverloadTest::OverloadTest() {
	this->i = 1;
	this->str="cuijk";
}

OverloadTest::OverloadTest(int i, string str) {
	this->i = i;
	this->str=str;

}
OverloadTest::~OverloadTest() {
	// TODO Auto-generated destructor stub
}

OverloadTest::OverloadTest(const OverloadTest &other) {
	// TODO Auto-generated constructor stub

}

OverloadTest::OverloadTest(OverloadTest &&other) {
	// TODO Auto-generated constructor stub

}

OverloadTest& OverloadTest::operator=(const OverloadTest &other) {
	// TODO Auto-generated method stub

}

OverloadTest& OverloadTest::operator=(OverloadTest &&other) {
	// TODO Auto-generated method stub

}
void OverloadTest::printSelf(){
		cout<<"self is"<<"i="<<i<<"str="<<str<<endl;
}

int OverloadTest::funa(double a){
	return (int)a / 2;
}
int OverloadTest::funa(int a){
	return a * 2;
}
