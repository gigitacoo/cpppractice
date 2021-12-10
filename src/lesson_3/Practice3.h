/*
 * Practice3.h
 *
 *  Created on: 2021年3月16日
 *      Author: cuijk
 */

#ifndef SRC_LESSON_3_PRACTICE3_H_
#define SRC_LESSON_3_PRACTICE3_H_
#include <string>
#include <cstring>
#include <iostream>
//#include "cpConstruct.cpp"

using namespace std;

class Practice3 {
private:
	int age;
	std::string name;
public:
	//无参构造函数
	Practice3();
	//一个构造函数,类体内实现构造函数类体外需要在前面加Practice3::
	//生成对象时，对象分配的内存空间由构造函数初始化完成
	Practice3(std::string name):age(3){
		this->name = name;
	}
	virtual ~Practice3();
	Practice3(const Practice3 &other);
	Practice3(Practice3 &&other);
	Practice3& operator=(const Practice3 &other);
	Practice3& operator=(Practice3 &&other);
	
	void println(){
		cout<<"practice3"<<"\t"<<age<<"\t"<<name<<"\t"<<endl;
	}
	void setAge(int i){
		age = i;
	}
	//friend void cpcst::youyuan(int i, int y);
};

#endif /* SRC_LESSON_3_PRACTICE3_H_ */
