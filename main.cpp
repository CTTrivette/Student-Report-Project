#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

int main() {
	//print application, course title, prog. lang. used, studentID, and name
	cout << "Application used: Visual Studio\t"
		<< "Course title: C867: Scripting and Programming - Applications\t"
		<< "Programming language used: C++\t"
		<< "Student ID: 001307104\t"
		<< "Name: Christian Trivette" << endl;

	int numStudents = 5;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Christian,Trivette,ctrive1@wgu.edu,21,15,20,30,SOFTWARE"
	};

	Roster* classRoster = new Roster(numStudents);

	//parse data and add students
	for (int i = 0; i < numStudents; i++) {
		classRoster->parseThenAdd(studentData[i]);
	}

	//display all students
	cout << "Displaying all students..." << endl;
	classRoster->printAll();
	cout << "Done!\n" << endl;

	classRoster->printInvalidEmails();
	cout << endl;

	//print average days in course for all students
	cout << "Displaying averages days spent in a course for all students..." << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->getStudentID());
	}
	cout << endl;


	//print students belonging to the software degree program
	cout << "Printing students in the degree program: SOFTWARE" << endl;
	classRoster->printByDegreeProgram(SOFTWARE);

	//remove student A3, repeat twice to ensure error is thrown
	cout << "Removing student with studentID A3..." << endl;
	classRoster->remove("A3");
	numStudents--;
	classRoster->printAll();
	cout << endl;

	cout << "\nRemoving student with StudentID A3..." << endl;
	classRoster->remove("A3");
	cout << endl;
	

	system("pause");
	return 0;
}

