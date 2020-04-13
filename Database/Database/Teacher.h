
#pragma once
struct Teacher
{
	char name[100] = "";
	char surname[100] = "";
	int age;
	char email[100] = "";

};
void CreateNewTeacher(Teacher& teacher);
Teacher* AddNewTeacher(Teacher* teacher, size_t& size, const Teacher& newTeacher);
void ShowTeacher(const Teacher& teacher);
void ShowAllteachers(const Teacher* teacher, size_t size);
void SortTeachers(Teacher* teacher, size_t size);
void EditTeacher(Teacher* teeacher, size_t size);
Teacher* DeleteTeacher(Teacher* teacher, size_t& size);