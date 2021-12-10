/*
 * TestVirtual.cpp
 *
 *  Created on: 2021年3月20日
 *      Author: cuijk
 */
#include <iostream>
using namespace std;
class CBase{
public:
	void func1(){
		cout<<"cbase::func1"<<endl;
		func2();
		func3();
	}
	virtual void func2(){
		cout<<"Cbase::func2"<<endl;
		
	}
	void func3(){
		cout<<"Cbase::func3"<<endl;
		
	}
};
class Cdrived : public CBase{
public:
	virtual void func2(){
		cout<<"cdrived::func2"<<endl;
	}
	void func3(){
		cout<<"cdrived::func3"<<endl;
	}
};



