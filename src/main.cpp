#include <vector>
#include <iostream>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanery.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");



	Deanery k;

	k.createGroup("PMI.txt");
	k.createGroup("BI.txt");
	k.createGroup("MEN.txt");
	k.randMarks();
	k.changeGroup("Евсеев Алексей Сергеевич", "BI");
	k.choiceHead();
	k.badMarks();
//	k.getStatistics();
	k.newFile("newPMI.txt");


	getchar();
	return 0;
}

