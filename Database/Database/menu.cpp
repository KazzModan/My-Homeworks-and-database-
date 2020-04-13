#include <iostream>
#include "menu.h"

using namespace std;
void ShowTeacherMenu()
{
	cout << "(1) Add new teacher\n";
	cout << "(2) Show all teachers\n";
	cout << "(3) Sort teachets by surname\n";
	cout << "(4) Delete teacher\n";
	cout << "(5) Edit teacher\n";
	cout << "(0) Exit\n";
	cout << "-------------------------\n";
}
void ShowMainMenu()
{
	cout << "What do you want?\n";
	cout << "(1) Work with teachers\n";
	cout << "(2) Work with students\n";
	cout << "(3) Work with lessons\n";
}
void ClearBuffer()
{
	system("cls");
	while (cin.get() != '\n')
		continue;
}
void ShowStudentMenu()
{
	cout << "(1) Add new student\n";
	cout << "(2) Show all students\n";
}