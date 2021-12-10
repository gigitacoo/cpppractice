/*
 * Practice2.h
 *
 *  Created on: 2021年3月15日
 *      Author: cuijk
 */

#ifndef SRC_LESSON_2_PRACTICE2_H_
#define SRC_LESSON_2_PRACTICE2_H_
#include <string>
#include <cstring>
#include <iostream>


using namespace std;
class Practice2 {
public:
	Practice2();
	Practice2(std::string name, int age);
	Practice2(const Practice2 &other);
	Practice2(Practice2 &&other);
	Practice2& operator=(const Practice2 &other);
	Practice2& operator=(Practice2 &&other);
	void printfln();
	
	Practice2(std::string n=""){
		name = n;
	}
private:
	std::string name;
	int age;
};
#endif /* SRC_LESSON_2_PRACTICE2_H_ */
