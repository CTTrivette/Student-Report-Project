#include <string>
#include <iostream>
#include <iomanip>
#include "student.h"
#include "roster.h"
#include "degree.h"
#define NULL 0
using namespace std;

//empty constructor
Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRoster = nullptr;
}

//constructor with size limitation
Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRoster = new Student* [capacity];
}

Student * Roster::getStudentAt(int index) {
	return classRoster[index];
}

void Roster::parseThenAdd(string row) {
	if (lastIndex < capacity) {
		lastIndex++;
	}

	//read studentID
	int rightSide = row.find(",");
	string studentID = row.substr(0, rightSide);

	//read firstName
	int leftSide = rightSide + 1;
	rightSide = row.find(",", leftSide);
	string firstName = row.substr(leftSide, rightSide - leftSide);

	//read lastName
	leftSide = rightSide + 1;
	rightSide = row.find(",", leftSide);
	string lastName = row.substr(leftSide, rightSide - leftSide);

	//read emailAddress
	leftSide = rightSide + 1;
	rightSide = row.find(",", leftSide);
	string emailAddress = row.substr(leftSide, rightSide - leftSide);

	//read age
	leftSide = rightSide + 1;
	rightSide = row.find(",", leftSide);
	int age = stoi(row.substr(leftSide, rightSide - leftSide));

	//read daysInCourse1
	leftSide = rightSide + 1;
	rightSide = row.find(",", leftSide);
	int daysInCourse1 = stoi(row.substr(leftSide, rightSide - leftSide));

	//read daysInCourse2
	leftSide = rightSide + 1;
	rightSide = row.find(",", leftSide);
	int daysInCourse2 = stoi(row.substr(leftSide, rightSide - leftSide));

	//read daysInCourse3
	leftSide = rightSide + 1;
	rightSide = row.find(",", leftSide);
	int daysInCourse3 = stoi(row.substr(leftSide, rightSide - leftSide));

	//read degreeProgram
	leftSide = rightSide + 1;
	rightSide = row.find(",", rightSide);
	DegreeProgram degree_program;
	string degreeString = row.substr(leftSide, rightSide - leftSide);
	if (degreeString == "NETWORK") {
		degree_program = DegreeProgram::NETWORK;
	}
	else if (degreeString == "SOFTWARE") {
		degree_program = DegreeProgram::SOFTWARE;
	}
	else if (degreeString == "SECURITY") {
		degree_program = DegreeProgram::SECURITY;
	}
	else {
		degree_program = DegreeProgram::UNDECIDED;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree_program);

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	//array to get daysInCourse variables into contructor
	int daysInCourse[Student::MAX_DAYS_SIZE];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	//note: may have to change classRoster to just roster
	classRoster[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
}

void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; i++) {
		classRoster[i]->Student::print();
		cout << endl;
	}
}

void Roster::remove(string studentID) {
	for (int i = 0; i <= lastIndex; i++) {
		 if (this->classRoster[i]->getStudentID() == studentID) {
			delete this->classRoster[i];
			//ensure there are no gaps in the array
			this->classRoster[i] = this->classRoster[lastIndex];
			//decrement lastIndex since it is now 1 size smaller
			lastIndex--;
			cout << "Student removed!" << endl;
			break;
		 }
		 else if (i == lastIndex && this->classRoster[i]->getStudentID() != studentID) {
			 cout << "Student with this ID does not exist in the array" << endl;
		 }
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		string tempID = classRoster[i]->getStudentID();
		if (tempID == studentID) {
			int average = (((classRoster[i]->getDays()[0]) + (classRoster[i]->getDays()[1]) + (classRoster[i]->getDays()[2]))/3);
			cout << "Student ID " << studentID << " average days spent in a course is: " << average << "." << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram d){
	for (int i = 0; i < 5; i++) {
		DegreeProgram tempDegree = classRoster[i]->getDegreeProgram();
		if (tempDegree == d) {
			classRoster[i]->print();
			cout << endl;
		}
	}
	cout << endl;
}

void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails..." << endl;
	for (int i = 0; i <= lastIndex; i++) {
		string tempEmail = classRoster[i]->getEmailAddress();
		if (tempEmail.find(" ") != string::npos || tempEmail.find("@") == string::npos || tempEmail.find(".") == string::npos) {
			cout << classRoster[i]->getEmailAddress();
			cout << "\t is an invalid email" << endl;
		}
	}
}

//destructor
Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
		delete this->classRoster[i];
	}
	delete classRoster;
}