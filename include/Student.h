#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Group.h"

using namespace std; 

class Group; 

class Student {
private:
	int id;
	string fio;
	Group* group;
	vector<int> marks;
	int num;
	double avr;
	void Avr();

public:

	Student(int id, string fio);
	void addMark(int m);
	void printSt();
	void setGroup(Group* a);
	string getFio();
	int getId();
	double getAvr();
	Group* getGroup();
};
