#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

//empty constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < MAX_DAYS_SIZE; i++) {
		this->Days[i] = 0;
	}
	this->degree_program = UNDECIDED;
}

Student::Student(string ID, string firstName, string lastName, string emailAddress, int age, int Days[], DegreeProgram degree_program) {
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < MAX_DAYS_SIZE; i++) {
		this->Days[i] = Days[i];
	}
	this->degree_program = degree_program;
}

//getters
string Student::getStudentID(){
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

int Student::getAge() {
	return age;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int* Student::getDays() {
	return Days;
}

DegreeProgram Student::getDegreeProgram()
{
	return degree_program;
}


//setters

void Student::setStudentID(string ID) {
	studentID = ID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setDays(int days[]) {
	for (int i = 0; i < MAX_DAYS_SIZE; i++) {
		this->Days[i] = days[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degree_program) {
	this->degree_program = degree_program;
}

void Student::print() {
	cout << Student::getStudentID() << "\t"
		<< "First Name: " << Student::getFirstName() << "\t"
		<< "Last Name: " << Student::getLastName() << "\t"
		<< "Age: " << Student::getAge() << "\t"
		<< "daysInCourse: {" << Days[0] << " " << Days[1] << " " << Days[2] << "} "
		<< "Degree Program: " << degreeProgramStrings[(int)getDegreeProgram()] << ".";
}

Student::~Student() {

}