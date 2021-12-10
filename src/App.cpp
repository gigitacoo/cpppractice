/*
 * practice.cpp
 *
 *  Created on: 2021年3月12日
 *      Author: cuijk
 */
#include "lesson_1/practice.cpp"
#include "lesson_2/Practice2.h"
#include "lesson_3/Practice3.h"
#include "lesson_2/Point.h"
#include "lesson_2/Cylinder.h"
#include "lesson_3/cpConstruct.cpp"
#include "lesson_6/TestVirtual.cpp"
#include "lesson_7/TestIO.cpp"
#include "lesson_8/FileTest.cpp"
#include "lesson_9/TemplateTest.cpp"

class Aton {
public:
	int X, Y;
	int zx, zy;
	void init(int i, int j) {
		zx = i;
		zy = j;
	}
	Aton(int i, int j, int n = 0, int m = 0) {
		X = i;
		Y = j;
		zx = m;
		zy = n;
	}
};

//
class Location {
public:
	int x, y;
	void init(int initx, int inity);
	int getxx();
	int getyx();
};
void Location::init(int ix, int iy) {
	x = ix;
	y = iy;
}
int Location::getxx() {
	return x;
}
int Location::getyx() {
	return y;
}
void display(Location &l) {
	cout << l.getxx() << "  " << l.getyx() << endl;
}

//强制类型转换符重载
class myComplex {
	double real, imag;
public:
	myComplex(double r = 0, double i = 0) {
		real = r;
		imag = i;
	}
	operator double();
	//如果是有元类型则实现方法里不加作用域		myComplex::
	//friend myComplex operator*(myComplex &mc, myComplex &mc1);
	myComplex operator*(myComplex &mc);
};
myComplex::operator double() {
	return real;
}
//如果是有元类型则实现方法里不加作用域		myComplex::

myComplex myComplex::operator *(myComplex &mc) {
	double rs = mc.real * this->real;
	double rs1 = mc.imag * this->imag;
	return myComplex(rs, rs1);
}
//集合类
class Set {
	int entry[];
	Set operator+(Set &s); //集合的并集
	Set operator-(Set &s); //集合的差
	Set operator*(Set &s); //集合的交集
	bool operator<(const Set &s); //是否是真子集
	bool operator==(const Set &s); //两个子集是否相等
	bool operator!=(const Set &s); //是否不相等
	static int dd;
};
//静态属性初始化
int Set::dd = 1;

class BaseClass {
private:
	int v1, v2;
public:
	BaseClass(int i, int j) {
		v1 = i;
		v2 = j;
	}
};
class DrivedClass: public BaseClass {
	int v3;
public:
	//当基类类没提供默认构造函数时必须在派生类中调用基类的构造函数
	DrivedClass(int i, int j) :
			BaseClass(i, j) {
		v3 = i;
	}
	void test() {
		//错误，不能访问父类的private成员
//		v3 = BaseClass::v1 + BaseClass::v2;
	}
};
int main() {
	DrivedClass dc(1, 2);
	dc.test();
	Aton At(25, 20, 3, 5);
	At.zy = At.zy + 6;
	cout << At.zx << At.zy << endl;

	/**
	 * lesson 1
	 */
	Practice practice1;
	//1.0
	//basicType();

	//1.1
	//int i = 1;
	//testRef(i);
	//cout<<i<<endl;

	//1.2
	//void testConst();
	practice1.testConst();

	//1.3 当实参一个int和一个double时产生二义性，编译错误。
	//cout<<practice1.bigger(1,2.2)<<endl;

	//1.4  计算数组元素个数
	int arr[] = { 2, 23, 1, 255 };
	int len = sizeof(arr) / sizeof(*arr);
	cout << len << endl;

	//1.5	new 需要delete
	int *intp = new int[20];
	delete[] intp;
	int *inp = NULL;
	delete inp;

	//1.6
	//sizeof(sting)内存首地址都是一样长的，一个string对象的大小是固定的。
	//string citys[] = {"Beijing","ShangHai"};
	//sizeof(citys) / sizeof(string) 输出数组元素个数

	//1.7	string常用函数
	string str;
	if (str.empty()) {
		cout << "empty str" << endl;
	}
	str = str.append("abcdefg");
	//返回char数组,abcdefg
	const char *chp = str.c_str();
	printf("%s\n", chp);
	string str2 = "iuyyy";
	//abcdefg	7	7	bc	3
	cout << str << "\t" << str.size() << "\t" << str.length() << "\t"
			<< str.substr(1, 2) << "\t" << str.find("de", 0) << endl;
	//iuyyy
	str.swap(str2);
	cout << str << endl;

	//1.8  类定义和函数重载
	OverloadTest ot;
	ot.printSelf();
	OverloadTest opt(5, "cjccjjc");
	opt.printSelf();
	cout << opt.funa(6.0) << endl;
	cout << opt.funa(2) << endl;

	//1.9	引用
	int oneint = 1;
	int &ref = oneint;
	ref = 2;
	//2	2
	cout << ref << "\t" << oneint << endl;
	int *p = &ref;
	*p = 5;
	//5	5 5
	cout << ref << "\t" << oneint << "\t" << *p << endl;

	//1.10
	for (int i = 0; i < 3; i++) {
		//3
		//4
		//5
		cout << practice1.f(i) << endl;
	}

	//1.11 程序设计
	/*
	 int NUM,max=0,min=0,totallen=0;
	 cin>>NUM;
	 string sarr[NUM];

	 for(int i = 0;i < NUM; i++){
	 cin>>sarr[i];
	 }
	 for(int i = 0;i < NUM; i++){
	 int len = sarr[i].length();
	 if(len > sarr[max].length()){
	 max=i;
	 }else if(len < sarr[min].length()){
	 min=i;
	 }
	 totallen += len;
	 }
	 cout<<"最长的是:"<<sarr[max]<<endl;
	 cout<<"最短的是:"<<sarr[min]<<endl;
	 cout<<"平均长度是:"<<totallen/NUM<<endl;
	 *
	 */

	/**
	 * lesson 2
	 */
	Practice2 stu("23sad", 21);
	stu.printfln();
	//2.1
	//成员函数和普通函数一样在内存中只有一份。
	//成员函数被分配到存储空间中的一个公共区域，由该类的所有对象共享。
	//new创建的是一个对象指针,要用delete回收内存
	Practice2 *p1 = new Practice2("231311", 11);
	p1->printfln();
	delete p1;
	//2.2
	//private属性不能直接通过.printfln()调用。
	//指针对象不能用.去调用函数，只能用->
	Practice2 *p2 = &stu;
	p2->printfln();
	//2.3
	//如果属性没有指定访问限制，默认是private的。
	//成员函数可以在类体外定义！！！

	class A {
	public:
		int m;
		int *p = &m;
	};
	A A1;
	//2.4
	//通过p给m赋值,记得指针写在前面！！：
	*A1.p = 10;
	cout << A1.m << endl;

	//2.5
	//类C中不可以定义类C的成员变量。可以定义引用或指针。

	//2.6
	int *pp;
	int **pp1 = &pp;
	int b = 20;
	pp = &b;
	cout << "pp1<<" << **pp1 << endl;	//20

	//2.7	程序设计，坐标轴
	Point point1(1, 2);
	Point point2(3, 5);
	Point point3(7, 9);
	double d = point1.lengthToZero();
	cout << d << endl;
	double lenp = point1.lengthWith2Point(point1, point2);
	cout << lenp << endl;
	bool ist = point1.isTriangle(point1, point2, point3);
	cout << ist << endl;

	//2.8 直线斜率。判断点是否在线上，还是使用坐标即可
	//斜率计算公式d=y1-y2/x1-x2
	//计算点是否在线上，直接计算点到线的距离即可。

	//2.9 计算圆柱体
	Cylinder cylinder;

	cout << "------lesson_" << 3.0 << "------" << endl;
	//对象的构造函数
	//AB a(4), b[3], *p 对象AB的构造调用了4次，a一次，数组3次，p只是声明为指针
	Practice3 p3[] = { Practice3(), Practice3("456") };
	Practice3 p3tmp;
	//此时放到pp3	数组的p3是p3数组的第一个元素！！！
	//不能将p3tmp直接放到指针数组中，应加&代表地址
	Practice3 *pp3[] = { &p3tmp, new Practice3("123"), p3 };
	p3[0].setAge(5);	//和pp3[2]用的是同一个地址值。会同时改变
	p3tmp.setAge(7);	//和pp3[0]用的是同一地址值。会同时改变
	p3tmp.println();	//	practice3	7
	pp3[0]->println();	//	practice3	7
	pp3[1]->println();	//	practice3	3	123
	pp3[2]->println();	//	practice3	5
	//pp3[3]->println();//不存在,会让程序停止。

	cout << "------lesson_" << 3.1 << "------" << endl;
	Practice3 p3arr[] = { Practice3(), p3tmp };
	p3arr[0].println();	//practice3	435178384
	p3arr[1].println();	//practice3	0
	p3tmp.setAge(8);
	p3tmp.println();	//practice3	8
	p3arr[1].println();	//practice3	0 说明p3tmp和数组中的已经内存分离，数组只是用p3tmp的属性做了初始化

	cout << "------lesson_" << 3.2 << "------" << endl;
	//拷贝构造函数 一个对象可以写两个复制构造函数，一个带const一个不带，通常都用带的。
	//Practice3(const Practice3 &other);
	Practice3 p3tmp2(p3tmp);
	p3tmp.println();	//practice3	8
	p3tmp2.println();	//practice3	8
	p3tmp.setAge(13);	//两个复制出来的对象相互间无影响。const
	p3tmp2.println();	//practice3	8
	//自动调用复制构造函数的3种情况：
	//1: A a1(a2) OR A a1 = a2; 2:如果函数F的参数是类A的对象，那么当调用F时会调用类A的复制构造函数，作为形参的对象使用复制构造函数初始化的。3:函数返回值是类A的对象时也是通过复制构造函数初始化的。

	cpcst cp1;
	cpcst cp2 = cpcst(cp1);
	cout << &cp1 << &cp2 << endl; //0x7ffee18411b00x7ffee18411a8

	cout << "------lesson_" << 3.3 << "------" << endl;
	cout << "如果构造函数只有一个参数，则可以看作是类型转换构造函数" << endl;
	//例如Demo d4(4); d4 = 6;即将6转为一个对象。
	cout << "析构函数没有参数，没有返回值，一个类只能有一个析构函数，类销往时自动调用析构函数，通过new创建的对象，可在析构函数中delete"
			<< endl;
	cout << "类的静态成员用static修饰，作用域仅在定义变量的源文件中有效，其他文件中不能调用。静态变量存储在全局数据区，只初始化一次"
			<< endl;
	cout
			<< "静态成员为该类所有对象共享，不能在静态函数访问非静态函数，反之可以。静态成员变量必须在类体外初始化：int classA::num=5。 sizeof计算类占用的空间时不会算上静态成员变量"
			<< endl;
	cout << "静态函数可以通过对象调用也可以通过类名调用，obj.staticMethod(), Obj::staticMethod()"
			<< endl;

	cout << "------lesson_" << 3.4 << "------" << endl;
	cout << "Demo d4(4); d4=7 生成对象并立即消亡，temp.id=7,7销往，d4最后消亡" << endl;
	cout << "静态成员程序运行完消亡：static Demo d6(1); 全局变量最后消亡。" << endl;
	cout << "常量成员函数和非常量成员函数都可以调用静态成员函数" << endl;

	/* void Sample::getValue() const{
	 * 	 //常量函数只能调用常量成员
	 * }
	 * void Sample::getValue(){
	 * 	 //非常量成员函数与常量函数形成重载。
	 * }
	 * const CDemo Obj;//常量对象也只能调用常量函数
	 * obj.setValue() //错误常量对象不能改属性
	 */
	cout << "执行封闭类的构造函数时先执行成员对象的构造函数，消亡时先执行封闭类的析构函数，在执行成员对象的构造函数" << endl;
//	class CCar{
//		CType ctype;
//	};
//	CCar::CCar(int p,int tr,int tw):price(p),ctype(tr,tw){
//
//	}
	cout << "------lesson_" << 3.4 << "------" << endl;
	cout << "友元函数" << endl;
	cout << "友元函数可以直接访问私有成员，友元函数不是类的成员函数 " << endl;
	cout << "如果类A是B的友元成员对象，则A的所有函数都是B的友元函数：friend class Line " << endl;
	cout << "友元函数和静态函数没有this指针 " << endl;

	cp1.youyuan(1, 2);
//	cpcst cp3,cp4;
//	cp3.f(2.2);
//	cp4.f(3.3);
//	cout<<max(cp3,cp4)<<endl;
	cout << "调用友元函数不通过类对象，但是需要在当前类文件中调用" << endl;
	float f1 = 3.5;
	cout << (int) f1 << endl; //3
	cout << "const成员函数必须在构造函数的初始化列表中初始化" << endl;
	cout << "静态成员变量在类体外初始化时：int classA::num=0;" << endl;
	cout << "const函数声明时const放后面：int getX const {return x} " << endl;

	//练习指针
	Location A[5] = { { 5, 5 }, { 3, 3 }, { 1, 1 }, { 2, 2 }, { 4, 4 } };
	Location *ra = A;
	A[3].init(7, 3);
	ra->init(7, 8);
	for (int i = 0; i < 5; i++) {
		display(*(ra++));
	}
//	7  8
//	3  3
//	1  1
//	7  3
//	4  4
	cout << "------lesson_" << 4.1 << "------" << endl;
	//重载运算符：
	/*
	 * myComplex operator-(const myComplex &c);
	 * myComplex myComplex::operator-(const myComplex c&){
	 * 	return myComplext(this->real - c.real,this->imag-c.imag)
	 * }
	 * myComplex c1(1,2),c2(3,4),res;
	 * res = c1 + c2;
	 *
	 * 友元重载运算
	 * myComplex operator-(double r);
	 * 该函数可以实现 res = c1-2;但是不能2-c1;
	 * friend myComplex operator-(const myComplex &c,const myComplex &c1); 友元函数需要传入两个对象，因为友元没有this指针
	 * friend myComplex operator-(const myComplex &c, double r);
	 * friend myComplex operator-(double r, const myComplex &c);
	 *
	 * =只能重载为成员函数
	 * myComplex operator=(double d);
	 * 如果没重载赋值运算符则 res = 7; res = (1+2)会报错
	 */
	cout << "=相当于值的拷贝，是浅拷贝 " << endl;
	/*
	 * pointer p1;
	 * pointer p2(p1);
	 * pointer p3 = p1;
	 * 三个对象共享一个地址，一个修改其他都修改，浅拷贝会带来程序上的错误，重复释放同一个空间会产生错误。
	 * 深拷贝的实现：
	 * int a;
	 * int *p;
	 * pointer(const pointer & tp){
	 * 	if(this != tp){//判断是否同一个对象
	 * 	 a= tp.a;
	 * 	 p = new int();
	 * 	 *p = *tp.p;//赋值地址内容给新的指针。
	 * 	}
	 * }
	 * ～pointer(){
	 * 	if(p!=NULL){delete p;} // 析构里回收并判断NULL
	 * }
	 */
	cout << "cout是ostream的对象， cin是istream的对象 " << endl;
	cout << "重载流运算符必须重载为友元函数，因为流是标准类库，只能继承不能修改 " << endl;
	/*
	 * istream & input = cin; //input是个别名
	 * friend ostream & operator<<(ostream & os, const myComplex &c);
	 * ostream & operator<<(ostream & os, const myComplex &c){
	 * 	os<<c.real<<"-----"<<endl;//自定义输出格式
	 * }
	 *
	 *
	 * 强制类型转换、(),[],->,= 只能重载为成员函数
	 * 前置++ --调用无形参的函数obj.operator--()，后置会生成两个形参的函数并调用：operator--(obj,0)
	 * CDemo & CDemo::operator++(){
	 * 	return this;
	 * }
	 */
	myComplex mc(1.2, -3.4);
	cout << (double) mc << endl;
	double n = 12 + mc;
	cout << n << endl;
	myComplex mc1(2, 3);
	//重载*
	myComplex mc2 = mc * (mc1);
	cout << (double) mc2 << endl;

	cout << "------lesson_" << 5.1 << "------" << endl;
	/*	class BaseClass{
	 * 		int v1,v2;
	 *  }
	 *  classDrivedClass : public BaseClass{
	 *  	int v3;
	 *  }
	 *
	 */
	cout << "基类的友元不一定是派生类的友元，如果基类是某类的友元，则这种友元关系是被继承的 " << endl;
	cout << "基类的成员函数是其他类的友元函数时，是可以被继承的" << endl;
	cout << "派生类不能访问基类的私有成员，可以访问protected成员" << endl;
	cout << "多重继承调用： 	cdrived.CBase::func2();,调用基类CB1的函数" << endl;
	cout
			<< "如果派生类新增了同名成员则直接覆盖父类成员，通过：派生类对象名.成员名调用。如果派生类没有新增同名成员但是多个基类中有重名成员则通过：ext.base::v1调用成员"
			<< endl;
	cout << "当派生类重写了基类的成员函数，则通过基类名::成员函数名调用。" << endl;
	cout << "共有派生3条规则：1.派生类的对象可以赋值给基类，2.派生类对象可以用来初始化基类引用，3.派生类指针可以赋值给基类指针"
			<< endl;
	cout << "私有继承：基类的共有成员和保护成员被继承后作为派生类的私有成员，在派生类中可以直接访问但是在类外通过派生类的对象无法直接访问。"
			<< endl;
	cout << "定义派生类不加继承方式说明符，默认是private" << endl;
	cout << "在执行派生类的构造函数之前总是先执行基类的构造函数，消亡时先执行派生类的析构函数再执行基类的析构函数。" << endl;
	cout << "class CD: public CB, public CC{} 则构造函数是 CB>CC>CD,析构则反过来" << endl;
	cout
			<< "封闭类：CA:CA(int i):CB(int y),CC(int z){...} 封闭类即有另一个类对象成员。构造函数调用：CB>>CC>>CA 析构则相反"
			<< endl;
	cout
			<< "循环依赖问题：A>B>A,通过前向引用解决 提前声明 class B; 使用指针在类A中定义B *b = NULL; 在main方法中如下： B cb; a.b = &cb"
			<< endl;
	cout
			<< "派生类对象可以赋值给基类对象，指针也是可以的，但即使指针指向的是一个派生类对象也不能调用基类中没有的成员函数，即使派生类和基类中都有同名函数，基类指针调用的也是基类中的函数"
			<< endl;

	cout << "------lesson_" << 6.1 << "------" << endl;
	cout << "多态分编译时多态和运行时多态，编译时指函数的重载，根据实参确定调用哪个函数，运行时则是继承，虚函数等概念" << endl;
	cout << "实现动态绑定必须声明虚函数，通过基类类型的引用或指针调用虚函数" << endl;
	//virtual void testVirtual(); 虚函数只能在类定义中的成员函数声明处声明，不能再类外写
	cout << "静态成员函数和友元不能定义为虚函数" << endl;
	cout << "最好将基类的析构函数声明为虚函数" << endl;
	cout << "每一个虚函数的类都有一个虚函数表，该类的所有对象都保存有一份指向虚函数表的指针，所以虚函数类的对象占用空间都会增大" << endl;
	Cdrived cdrived;
	cdrived.func1();
	cdrived.CBase::func2();
	//func1中调用func2,func3相当于this指针调用两个对象，因为this是基类的所以调用func2可以实现多态
	//由于func1不是虚函数，派生类也没重写，所以直接调用基类的func1。
	//又因为cbase是派生类对象并且func2是虚函数，所以func1中调用派生类的func2
	//随后func3不是虚函数所以this指针会直接调用基类的func3
//	cbase::func1
//	cdrived::func2
//	Cbase::func3
	cout << "------lesson_" << 6.2 << "------" << endl;
	cout << "构造函数和析构函数中调用虚函数不会实现多态" << endl;
	cout << "使用虚析构函数的目的是为了在对象消亡时实现多态。" << endl;
	//virtual void testVirtual(int i) = 0;
	cout << "纯虚函数没有函数体，要求派生类中必须重写这个函数，就是抽象函数。" << endl;
	cout << "纯虚函数所在的类是抽象类，不能直接实例化，必须被派生类重写后才可以。" << endl;
	cout
			<< "如果B>A<C，BC继承自A，B<D>C D继承BC，则会产生二义性，通过虚继承让D只保留一个版本的继承 即class B: virtual public A, class C: virtual public A, class d: public B, public C"
			<< endl;

	cout << "------lesson_" << 7.1 << "------" << endl;
	cout << "istream,ifstream; ostream,ofstream;iostream,fstream" << endl;
	cout << "(cin,cout)标准输入输出流；cerr(非缓冲错误输出流)，clog（缓冲错误输出流）。cerr、clog不能被重定向"
			<< endl;

	TestIO tio;
	//重定向cout为输出到文件
//	tio.testFreopen();
	//重定向cin为从文件读取
//	tio.testFreopenCin();
//	cout << "12321" << endl;
//	while(toupper(ch) != 'Q'){}
//	if(cin.eof()){break;}
	//cin.clear();状态字清0
	tio.testCoutFunc();
	tio.testChar();

	//while((ch=cin.get()) != EOF){}
	//cin通过EOF判断是否结束 或者cin.eof()
	//char buf[10]; while(cin.getline(buf,10)){cout<<buf<<endl;} //如果超过9个会报错
	//cin.ignore(10,':')//跳过':'之前的全部字符
	//while((cin=cin,peek()) != EOF){//取输入流的第一个字符查看}

	//ios
	tio.testprecision();
	tio.testprecision2();
	//tio.readline(); //倒序输出字符串
	cout << "------lesson_" << 8.1 << "------" << endl;
	FileTest ft;
	ft.testif();
	cout << "c++中将文件看成顺序有序的无结构字节流，对于长度为N的文件来说，字节号是0～N-1" << endl;
	cout << "EOF=0x1A,关闭文件流时自动追加到" << endl;
	//ft.insertFile();//linux需要输入Ctrl+D
	//ft.coutWithLineNum();
	//ft.binaryFileOut();
	//ft.binaryFileRead();
	cout << "iofile.tellg()//返回读指针当前位置" << endl;
	cout
			<< "移动读指针：iofile.seekg(20,ios::beg/cur/end) 以开始位置为基准后移20个字节，（-10）以当前为基准前移10指针，以结尾为基准前移10"
			<< endl;
	cout
			<< "移动写指针：iofile.seekp(20,ios::beg/cur/end) 以开始位置为基准后移20个字节，（-10）以当前为基准前移10指针，以结尾为基准前移10"
			<< endl;
	cout << "cout,cerr,clog是ostream的对象，cerr不带缓冲，clog带缓冲" << endl;
	cout << "文件的I/O由ifstream ofstream fstream3个类提供" << endl;
	cout << "头文件fstream.h 包含了处理用户控制的文件操作所需的信息" << endl;
	ft.pract();

	cout << "------lesson_" << 9.1 << "------" << endl;
	cout << "函数模版本身在编译时不会产生任何代码，只有当通过模版生成函数实现时会生成目标代码" << endl;
	cout << "函数指针也只能指向模版的实例，不能指向模版本身" << endl;
	int intabs = abs(-1);
	cout << intabs << endl;
	myComplex at1(1.2, 2.3), at2(2.4, 3.5);
	cout << (double) at1 << endl;
	cout << (double) at2 << endl;
	swapClass(at1, at2); //自动生成函数
	cout << (double) at1 << endl;
	cout << (double) at2 << endl;

	cout << "通过类模版实现范型功能" << endl;
	//学生
	Pair<string, int> stu1("Tom", 3);
	Pair<string, int> stu2("Jack", 5);
	//坐标
	Pair<int, int> pointpp(10, 5);
	//字典
	Pair<string, string> pointpp1("word", "单词");
	bool rb = stu1 < stu2;
	cout << rb << endl;

	return 0;
}
