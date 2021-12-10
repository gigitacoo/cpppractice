/*
 * FileTest.cpp
 *
 *  Created on: 2021年3月21日
 *      Author: cuijk
 */
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class CStudent{
public:
	char id[11];
	char name[21];
	int score;
};
class FileTest{
public:
	void testif(){
		ifstream ifs;
		ifs.open("/Users/cuijk/logs/test.txt", ios::in);
		ifs.close();
		fstream ioFile;
		//windows中D:\\Users\\test.txt
		ioFile.open("/Users/cuijk/logs/test.txt",ios::in|ios::out|ios::trunc);//以读写和创建的方式打开一个文件
		if(!ioFile){
			//
		} else {
			ioFile.close();
		}
	}
	void insertFile(){
		char id[11],name[21];
		int score;
		fstream ioFile;
		/*
		ioFile.open("/Users/cuijk/logs/test1.txt",ios::in|ios::out|ios::trunc);
		if(!ioFile){
			cout<<"err"<<endl;
			return;
		}
		cout<<"请输入：学号 姓名 成绩（以Ctrl+Z结束输入,linux需要输入Ctrl+D）"<<endl;
		while(cin>>id>>name>>score){
			ioFile<<id<<" "<<name<<" "<<score<<endl;
		}
		*/

		//不要轻易使用trunc 会覆盖源文件
		ioFile.open("/Users/cuijk/logs/test1.txt",ios::in/*|ios::out|ios::trunc*/);
		while(ioFile >> id >> name >> score){
			cout << left << setw (10) << id <<" "<< setw(20) << name << " "<<setw(3) << right <<score << endl;
		}
		//while(ioFile >> id >> name >> score() //ioFile可以像cin一样把内容输入到文件
		
		ioFile.close();
		return;
	}
	
	void coutWithLineNum(){
		char ch, filename[40]="/Users/cuijk/logs/test1.txt";
		int count = 0;//行号
		bool newline = true;
		cout<<"输入文件名"<<endl;
		//cin >> filename;
		// filename =  
		fstream infile;
		infile.open(filename,ios::in);
		if(!infile){//
		}
		while((ch = infile.get()) != EOF){
			if(newline){
				cout << setw(4) << ++count<<':';
				newline = false;
			}
			if(ch == '\n'){
				newline = true;
			}
			cout << ch;
		}
		infile.close();
	}
	
	void binaryFileOut(){
		CStudent stu;
		fstream outfile("/Users/cuijk/logs/stu.txt", ios::out|ios::binary);//写入二进制需要binary,同时ios::app用于向后追加
		if(!outfile){
			//
		}
		cout << "请输入id，姓名，分数";
		while (cin >> stu.id >> stu.name>>stu.score){
			outfile.write((char *)&stu,sizeof(stu));//转成二进制写入文件
		}
		outfile.close();
	}
	//file.get()
	//ostream & file.put(char ch);

	void binaryFileRead(){
		CStudent stu;
		fstream infile("/Users/cuijk/logs/stu.txt", ios::in|ios::binary);
		if(!infile){
			//
		}
		cout << "id，姓名，分数"<<endl;
		while (infile.read((char *)&stu, sizeof(stu))){
			cout<<left<<setw(10)<<stu.id<<" "<<setw(20)<<stu.name<<" "<<setw(3)<<right<<stu.score<<endl;
		}
		infile.close();
	}
	

	void pract(){
		ofstream of;
		of.open("/Users/cuijk/logs/pra.txt",ios::out);
		of << "fdfsfs";
		of.close();
		ifstream inf;
		inf.open("/Users/cuijk/logs/pra.txt");
		char str[100];
		for(int i = 0; i< 100;i++){
			if((str[i] = inf.get()) == EOF){
				break;
			}
		}
		string k = str;
		cout <<k<< endl;
	}
};


