/*
 * OverloadTest.h
 *
 *  Created on: 2021年3月14日
 *      Author: cuijk
 */

#ifndef OVERLOADTEST_H_
#define OVERLOADTEST_H_
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class OverloadTest {
private:
	int i;
	string str;
public:
	OverloadTest();
	OverloadTest(int i, string str);
	virtual ~OverloadTest();
	OverloadTest(const OverloadTest &other);
	OverloadTest(OverloadTest &&other);
	OverloadTest& operator=(const OverloadTest &other);
	OverloadTest& operator=(OverloadTest &&other);
	void printSelf();
	int funa(double);
	int funa(int);
};

#endif /* OVERLOADTEST_H_ */
