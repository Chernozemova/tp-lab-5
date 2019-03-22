#include "Student.h"

using namespace std;





Student::Student(int a, string f) {
	id = a;
	fio = f;
	num = 0;
}
void Student::addMark(int m) {
	marks.push_back(m);
	num++;
	Avr();
}

void Student::Avr() {
	int sum = 0;
	for (int i = 0; i < num; i++)
		sum = sum + marks[i];
	avr = (double)sum / ((double)num);
}

void Student::printSt() {
	cout << " fio: " << fio;
	//for (int n : marks)
	//	cout << n << ' ';
	cout << ", avr: " << avr << endl;
}

void Student::setGroup(Group* a) {
	group = a;
}

string Student::getFio(){
	return fio;
}
int Student::getId() {
	return id;
}
double Student::getAvr() {
	return avr;
}

Group * Student::getGroup()
{
	return group;
}
