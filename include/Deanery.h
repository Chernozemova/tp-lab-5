#pragma once
#include "Group.h"
#include<fstream> 
#include <ctime>

class Deanery {
private:
	vector<Student*>students;
	vector<Group*>groups;
	int id = 0;


public:

	void createStudents(string name);
	void createGroup(string name);
	void randMarks();
	void changeGroup(string st, string gr);
	void badMarks();
	void choiceHead();
	void getStatistics();
	void newFile(string fileName);
};
