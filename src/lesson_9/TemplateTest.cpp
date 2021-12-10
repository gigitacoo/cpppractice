/*
 * TemplateTest.cpp
 *
 *  Created on: 2021年3月21日
 *      Author: cuijk
 */
#include <iostream>
using namespace std;

//模版定义
template <typename T>
//函数实现
T abs(T x){
	return x < 0 ? -x : x;
}

template <class T1>
void swapClass(T1 &t1, T1 &t2){
	T1 tmp = t1;
	t1 = t2;
	t2 = tmp;
}


//声明多个类型参数
template <class T1, class T2>
void printclass(T1 &t1, T2 &t2){
	cout << t1 << t2 << endl;
}

template <typename TN>
int myCompare(const TN & tn1, const TN &tn2){
	return tn1 > tn2;
}

//模版可以重载，只要形参表不同即可
template <typename TN>
int myCompare(const TN & tn1, const TN &tn2, const TN &tn3){
	return tn1 > tn2;
}

//类模版实现类似Key-Value结构类
template <class T1, class T2>
class Pair{
public:
	T1 first;
	T2 second;
	
	T1 buffer[10];
	
	
	Pair(T1 k, T2 v) : first(k),second(v){
		
	}
	//重载<
	bool operator< (const Pair<T1,T2> & p) const{
		return first < p.first;
	}
	
	T1 /*Pair<T1> ::*/ getData(int j){
		return *(buffer + j);
	}
	
	//在类模版中使用函数模版
	template <class T>
	void print(T x){
		cout<<x<<endl;
	}
};
//实现函数还需要再定义一次模版,可以直接在类中实现
/*
template <class T1, class T2>
bool Pair<T1,T2> :: operator< (const Pair<T1,T2> & p) const{
	return first < p.first;
}
*/

