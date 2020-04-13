#include <iostream>
#include "Teacher.h"
#include "menu.h"
#include "Student.h"

using namespace std;

int main()
{

	size_t sizeTeacher = 0;
	Teacher* teachers = nullptr;
	Teacher newTeacher;
	size_t sizeStudent = 0;
	Student* students = nullptr;
	Student newStudent;
	int i = 0;
	int choose;
	char checkLog[100];
	int checkPass;
	char login[100] = "Demian";
	int password = 4660;
	int count = 0;
	do
	{
		if (count > 0)
		{
			if (3 - count == 0)
				cout << "Bye bye\n";
			else
			{
				cout << "Wrong login, or password. Enter thy again\n";
				cout << "You have " << 3 - count << " attempts\n";
			}
		}
		if (count > 2)
			return 0;
		cout << "Enter login:\n ";
		cout << "Notice: Login is name of my teacher\n";
		cout << "Login: ";
		cin >> checkLog;
		cout << "enter password\n";
		cout << "Notice: password is quantity hours,that he played in dota 2\n";
		cout << "Password: ";
		cin >> checkPass;
		count++;
	} while (strcmp(login, checkLog) != 0 || password != checkPass);
	cout << "Hello, budy\n";
	ShowMainMenu();
	cin >> choose;
	ClearBuffer();
	switch (choose)
	{
	case 1:
		do
		{
			ShowTeacherMenu();
			cin >> choose;
			ClearBuffer();

			switch (choose)
			{
			case 1:
				CreateNewTeacher(newTeacher);
				teachers = AddNewTeacher(teachers, sizeTeacher, newTeacher);
				break;
			case 2:
				ShowAllteachers(teachers, sizeTeacher);
				break;
			case 3:
				SortTeachers(teachers, sizeTeacher);
				break;
			case 4:
				teachers = DeleteTeacher(teachers, sizeTeacher);
				break;
			case 5:
				EditTeacher(teachers, sizeTeacher);
				break;
			case 0:
				cout << "Goodbye, see you next time\n";
				break;
			default:
				cout << "Incorrect choose, choose again\n";
				break;
			}
		} while (choose != 0);
		break;
	
	case 2:
		do
		{
			ShowStudentMenu();
			cin >> choose;
			ClearBuffer();
			switch (choose)
			{
			case 1:
				CreateStudent(newStudent);
				students = AddNewStudent(students, sizeStudent, newStudent);
				break;
			case 2:
				ShowAllStudents(students, sizeStudent);
				break;
			default:
				break;
			}
		} while (choose != 0);
	default:
		break;
	}

	delete[] teachers;
	teachers = nullptr;
	return 0;
}