#pragma once
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

class Roster {
private:
	int lastIndex;
	int capacity;

public:
	//empty constructor
	Roster();

	//constructor with a size constraint
	Roster(int capacity);
	
	Student* getStudentAt(int index);

	void parseThenAdd(string datarow);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	Student** classRoster;

	//destructor
	~Roster();

};
