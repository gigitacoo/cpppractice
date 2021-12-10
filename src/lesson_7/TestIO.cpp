/*
 * TestIO.cpp
 *
 *  Created on: 2021年3月21日
 *      Author: cuijk
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class TestIO {
public:
	void testFreopen() {
		int x, y;
		cin >> x >> y;
		//重定向后所有对cout的输出都到文件中了
		freopen("/Users/cuijk/logs/test.txt", "w", stdout);
		if (y == 0) {
			cerr << "error.." << endl;
		} else {
			cout << x << "/" << y << "=" << x / y << endl;
		}
	}

	void testFreopenCin() {
		int x, count, sum = 0;
		//重定向后所有对cout的输出都到文件中了
		freopen("/Users/cuijk/logs/test.txt", "r", stdin);
		for (count = 0; count < 10; count++) {
			cin >> x;
			if (cin.eof())
				break; //判断输入流已经结束
			else
				sum += x;
		}
		cout << "前" << count << "avg=" << 1.0 * sum / count << endl;
	}
	void testCoutFunc() {
		double values[] = { 1.23, 20.3456, 300.456, 4000.54663, 50000.1234567 };
		cout.fill('*'); 	//设置填充字符
		for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
			cout << "values[" << i << "]=(";
			cout.width(10);	//设置输出宽度
			cout << values[i] << ")" << endl;
		}
		cout.fill(' ');		//设置填充空格
		for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
			cout << "values[" << i << "]=(";
			cout << cout.precision() << endl;		//输出当前数据精度
			cout.width(10);	//设置输出宽度
			cout.precision(i + 3);	//设置保留有效数字
			cout << values[i] << ")" << endl;
		}
	}
	void testChar() {
		char c = 'a', str[80] = "0123456789abcdefghijklmnopq";
		int x = 65;
		cout << "cout.put('a'):";
		cout.put('a');
		cout << "\ncout.put(c+25):";
		cout.put(c + 25);
		cout << "\ncout.put(x):";
		cout.put(x);
		cout << "\ncout.write(str,20):";
		cout.write(str, 20); //str输出前20个字符
	}
	void testCinfunc() {
	}

	void testprecision() {
		double x = 1234.56789;
		cout.width(10);
		cout << endl;
		cout << "#";
		cout << x << endl;
		cout.precision(5);
		cout << x << endl;	//1234.6  四舍五入5变6
		//输出符号
		cout.setf(ios::showpos);
		cout << x << endl;	//+1234.6 四舍五入5变6
		//科学计数法输出，保留五位有效数字1.2345,四舍五入5变6 +03即为乘1000
		cout.setf(ios::scientific);
		cout << x << endl;	//+1.23457e+03
	}

	void testprecision2() {
		double x = 1234.56789;

		//iomanip记得导入包
		cout << setiosflags(ios::fixed | ios::showpos) << x << endl;
		cout << setw(12) << setiosflags(ios::right) << setprecision(3) << -x
				<< endl;
		cout << resetiosflags(ios::fixed | ios::showpos)
				<< setiosflags(ios::scientific);
		cout << setprecision(5) << x << endl;

		double y = 3;
		resetiosflags(ios::basefield);
		cout << setprecision(7) << y << endl;
		cout << setprecision(1) << y << endl;
		cout << setiosflags(ios::showpos) << y << endl;

	}

	//反向输出
	void readline() {
		string str; //或者char str[10];
		cin >> str;
		cout << str << endl;
		for (int i = str.size() - 1; i >= 0; i--) {
			cout << str[i];
		}
		cout<<endl;
	}
};
