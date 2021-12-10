/*
 * practice.cpp
 *
 *  Created on: 2021年3月12日
 *      Author: cuijk
 */

#include <iostream>
#include <string>
#include "../../sub/OverloadTest.h"
#include <cmath>
using namespace std;
class Practice{
public:

	void basicType(){
		int oneint1,oneint2;
		char strArr[20];
		string str;
		double onedouble;
		char onechar = 'a';
		//cin、cout分别是对象istream和ostream的对象；>> << 在头文件中进行了重载；endl作用是换行。
		cout<<"输入";
		cout<<"以tab结束"<<endl;
		cin>>oneint1>>oneint2>>onechar>>strArr>>onedouble;
		str = strArr;
		cout<<"输入的数据时："<<endl;
		cout<<"str: \t\t"<<str<<endl
				<<"intis: \t" << oneint1<<"int2is:\t"<<oneint2<<endl
				<<"charis: \t\t"<<onechar<<"\n"
				<<"floatis:\t\t"<<onedouble<<endl;


		const int*p = &oneint1;
		int *q;
		//q = p; //报错
		q = const_cast<int *> (p);//const_cast去除p的常量性赋值给q

		void defaultvalue1(int = 2,double = 3.0);
		void defaultvalue2(int a, double b = 3.0);
		//void defaultvalue3(int a = 2, double b);//错误，b必须给出默认值，从右到左给出
	}

	//C++支持值传递和引用传递，此时a会在main函数中也已修改。
	void testRef(int &a){
		a = 5;
	}

	//const在左侧数据是常量不可修改
	//const在右侧表示指针是个常量。
	void testConst(){
		const char* const cp = "ABCD";
		int a1 = 3;
		const int * a4 = &a1;//数据是常量*a4 = 5是错误的。
		int* const a5 = &a1;//指针是常量，不能修改指针，但能修改指针内容。a5 = &a2错误，*a5 = 5正确。
		cout<<cp<<a1<<*a4<<*a5<<endl;
	}
	//内联函数就是在调用的地方将函数体重写了一遍，是空间换时间的方式。
	inline void testInline(){
	}

	//函数重载
	double bigger(double a, double b){
		return a > b ? a : b;
	}
	int bigger(int a, int b){
		return a > b ? a : b;
	}
	//如果添加了此函数1.3就不会报错
	//int bigger(int a, double b){
	//	return a > b ? a : b;
	//}
	float bigger(float a, float b){
		return a > b ? a : b;
	}
	int f(int a){
		int b=0,c=1;
		b++;c++;
		return int(a+pow(double(b),2)+c);
	}
};
