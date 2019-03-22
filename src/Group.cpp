#include "Group.h"

Group::Group(string k) {
	title = k;
	num = 0;
}

void Group::addStudent(Student* d) {
	students.push_back(d); //добавляем студента в группу 
	d->setGroup(this); // добавляем группу у студента
	num++;
}
void Group::setHead(int n) {
	head = students[n];
}
int Group::searchStudent(string f) {
	for (int i = 0; i < num; i++) {
		if ((students[i]->getFio() == f)) {
			//cout << "Founded" << endl;
			return i;
		}
	}
		//cout << "Not founded";
		return -1;
	
}
int Group::searchStudent(int f) {
	for (int i = 0; i < num; i++) {
		if ((students[i]->getId() == f)) {
			//cout << "Founded" << endl;
			return i;
		}
		else
			//cout << "Not founded";
		return -1;
	}
}
void Group::avrGroup() {
	double sum = 0;
	for (int i = 0; i < num; i++) {
		sum = sum + (students[i]->getAvr());
	}
		AVR = sum / num;
		cout << AVR;
}
void Group::eraseStudent(string s) {
	int t = searchStudent(s);
	if (t != -1){
		students.erase(students.begin() + t);
		num--;
	}
	else
		cout << "Not founded"<<endl;
}
void Group::eraseStudent(int s) {
	int t = searchStudent(s);
	if (t != -1) {
		students.erase(students.begin() + t);
		num--;
	}
	else
		cout << "Not founded" << endl;
}

string Group::getTitle()
{
	return title;
}

int Group::getNum()
{
	return num;
}



Student * Group::getHead()
{
	return head ;
}
