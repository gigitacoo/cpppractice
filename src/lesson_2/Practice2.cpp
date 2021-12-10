/*
 * Practice2.cpp
 *
 *  Created on: 2021年3月15日
 *      Author: cuijk
 */

#include "Practice2.h"

Practice2::Practice2(string name, int age){
	this->name = name;
	this->age = age;
}
void Practice2::printfln(){
	cout<<this->name<<"\t"<<this->age<<"\t"<<endl;
}
