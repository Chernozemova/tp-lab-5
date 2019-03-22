#include "Deanery.h"



void Deanery::createStudents(string name) {

	ifstream file(name);
	string lineFio;

	while (getline(file, lineFio)) {
		students.push_back(new Student(id, lineFio)); //засовываем студента, созданного по имени, в вектор
		id++;
		} 
	file.close();
}

void Deanery::createGroup(string name) {
	string groupName = name.substr(0, name.size() - 4); //обрезаем имя файла (без .txt)
	groups.push_back( new Group(groupName));

	int start = id;

	createStudents(name);

	int n = groups.size() - 1;
	int end = students.size();

	for (int i = start; i < end; i++)
		groups[n]->addStudent((students[i]));
}

void Deanery::randMarks() {
	srand(time(NULL));
	int n = students.size();
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		k = rand() % 3 + 3;
		for (int j = 0; j < k; j++)
			students[i]->addMark(rand() % 10 + 1);
	}	
}

void Deanery::changeGroup(string st, string newGr)
{
	int n = groups.size();
	int newGrNum = 0;
	for (int i = 0; i < n; i++) {
		if (groups[i]->getTitle() == newGr)
			newGrNum = i;
	}

	n = students.size();
	for (int i = 0; i < n; i++) {
		if (students[i]->getFio() == st) {
			(students[i]->getGroup())->eraseStudent(st);
			groups[newGrNum]->addStudent(students[i]);
			break;
		}
	}
}

void Deanery::badMarks(){
	int n = students.size();
	for (int i = 0; i < n; i++) {
		if (students[i]->getAvr() < 4) {
			students[i]->getGroup()->eraseStudent(students[i]->getFio());
			students.erase(students.begin()+i);
			n--;
		}
	}
}

void Deanery::choiceHead(){
	int n = groups.size();
	srand(time(NULL));
	int t;
	for (int i = 0; i < n; i++) {
		t = rand() % groups[i]->getNum();
		groups[i]->setHead(t);
	}
}

void Deanery::getStatistics(){
	int n = groups.size();
	int t;
	for (int i = 0; i < n; i++) {
		cout <<"title: "<< groups[i]->getTitle() << endl;
		cout << "kol-vo students: " << groups[i]->getNum() << endl;
		cout << "head: " << groups[i]->getHead()->getFio() << endl;
		t = groups[i]->getNum();
		for (int j = 0; j < t; j++) {
			cout << students[j]->getId() << " ";
			students[j]->printSt();
		}
		cout << endl;
	}
}

void Deanery::newFile(string fileName){
	ofstream out;
	out.open(fileName);
	string groupName = fileName.substr(3, fileName.size() - 7); 
	if (out.is_open())
	{
		int n = students.size();
		int t;
		for (int i = 0; i < n; i++) {
			if (students[i]->getGroup()->getTitle() == groupName)
			{
				out << students[i]->getFio() << " " << students[i] ->getAvr() <<endl;
			}
		}
	}
}

