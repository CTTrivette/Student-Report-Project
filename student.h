#pragma once
#include "degree.h"
#include <string>

using namespace std;

class Student {
public:
	static const int MAX_DAYS_SIZE = 3;

	//setters
	void setStudentID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram degree_program);

	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();
	void print();

	//empty constructor
	Student();

	//constructor
	Student(string ID, string firstName, string lastName, string emailAddress, int age, int Days[], DegreeProgram degree_program);

	//destructor
	~Student();

private: //attributes of Student
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int Days[MAX_DAYS_SIZE];
	DegreeProgram degree_program;
};
