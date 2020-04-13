#pragma once
struct Student
{
	char name[100] = "";
	char surname[100] = "";
	char form[100] = "";
	char phNumbParents[100] = "";
	char phNumberStudent[100] = "";
	char email[100] = "";
};
Student* AddNewStudent(Student* student, size_t& size, const Student& newStudent);
void CreateStudent(Student& student);
void ShowStudent(const Student& student);
void ShowAllStudents(const Student* student, size_t size);