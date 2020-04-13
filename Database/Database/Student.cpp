#include <iostream>
#include "Student.h"

using namespace std;

void CreateStudent(Student& student)
{
	cout << "Enter student's name: ";
	cin >> student.name;
	cout << "Enter student's surname: ";
	cin >> student.surname;
	cout << "Enter student's form (number-letter): ";
	cin >> student.form;
	cout << "Enter studet's phone number: ";
	cin >> student.phNumberStudent;
	cout << "Enter phone number of his/her parents: ";
	cin >> student.phNumbParents;
	cout << "Enter student's email: ";
	cin >> student.email;
}
Student* AddNewStudent(Student* student, size_t& size,const Student& newStudent)
{
	if (student == nullptr || size == 0)
	{
		student = new Student[1];
		student[0] = newStudent;
		size = 1;
		return student;
	}
	Student* nStudent = new Student[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		nStudent[i] = student[i];
	}
	nStudent[size] = newStudent;
	size++;
	return nStudent;
}
void ShowStudent(const Student& student)
{
	cout << "Student's name: " << student.name<<endl;
	cout << "Student's surname: " << student.surname << endl;
	cout << "Student's form:  " << student.form << endl;
	cout << "Student's phone number: " << student.phNumberStudent << endl;
	cout << "His/her parents phone number: " << student.phNumbParents << endl;
	cout << "Student's mail: " << student.email << endl;
}
void ShowAllStudents(const Student* student, size_t size)
{
	if (size == 0 || student == nullptr)
	{
		cout << "List is empy\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		ShowStudent(student[i]);
	}
}