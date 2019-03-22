#pragma once
#include "Student.h"

using namespace std;

class Student;

class Group {
private:
	string title;
	int num;
	vector<Student*>students;
	Student* head;
	double AVR;


public:
	Group(string k);
	void addStudent(Student* d);
	void setHead(int n);
	int searchStudent(string f);
	int searchStudent(int f);
	void avrGroup();
	void eraseStudent(string s);
	void eraseStudent(int s);
	string getTitle();
	int getNum();
	Student* getHead();
};