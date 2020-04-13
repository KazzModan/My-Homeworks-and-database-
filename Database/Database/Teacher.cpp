#include <iostream>
#include "Teacher.h"

using namespace std;

void CreateNewTeacher(Teacher& teacher)
{
	cout << "Enter name of new Teacher: ";
	cin.getline(teacher.name, 100);
	cout << "Enter surnaname of new teacher: ";
	cin.getline(teacher.surname, 100);
	cout << "Enter teacher mail: ";
	cin.getline(teacher.email, 100);
	cout << "Enter Teacher age: ";
	cin >> teacher.age;
	cin.ignore();
}




void ShowAllteachers(const Teacher* teacher, size_t size)
{
	if (teacher == nullptr || size == 0)
	{
		cout << "List is empy\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		ShowTeacher(teacher[i]);
	}
}

void ShowTeacher(const Teacher& teacher)
{
	cout << "Teacher's name: " << teacher.name << endl;
	cout << "Teacher's surname: " << teacher.surname << endl;
	cout << "Teacher's age: " << teacher.age << endl;
	cout << "Teacher's mail " << teacher.email << endl;
}

Teacher* AddNewTeacher(Teacher* teacher, size_t& size, const Teacher& nTeacher)
{
	if (teacher == nullptr || size == 0)
	{
		teacher = new Teacher[1];
		teacher[0] = nTeacher;
		size = 1;

		return teacher;
	}

	Teacher* newTeacher = new Teacher[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newTeacher[i] = teacher[i];
	}
	newTeacher[size] = nTeacher;
	delete[] teacher;
	size++;
	return newTeacher;
}
void SortTeachers(Teacher* teacher, size_t size)
{
	if (teacher == nullptr || size == 0)
	{
		cout << "List is empy\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		char min[100] = "";
		char minName[100] = "";
		strcpy_s(min, 100, teacher[i].surname);
		strcpy_s(minName, 100, teacher[i].name);
		for (size_t j = i + 1; j < size; j++)
		{
			if (strcmp(min, teacher[j].surname) == 1)
			{
				strcpy_s(min, 100, teacher[i].surname);
				swap(teacher[i], teacher[j]);
			}
			else if (strcmp(min, teacher[j].surname) == 0)
			{
				if (strcmp(minName, teacher[j].name) == 1)
				{
					strcpy_s(minName, 100, teacher[i].name);
					swap(teacher[i], teacher[j]);
				}
			}
		}
	}
}
Teacher* DeleteTeacher(Teacher* teacher, size_t& size)
{
	if (teacher == nullptr || size == 0)
	{
		cout << "List is empy\n";
		return teacher;
	}
	char name[100] = "";
	char surname[100] = "";
	int count = -1;

	cout << "Enter name of this teacher: ";
	cin >> name;
	cout << "Enter surname of this teacher: ";
	cin >> surname;
	Teacher* newTeacher = new Teacher[size - 1];
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(name, teacher[i].name) && strcmp(surname, teacher[i].surname));
		count = i;
	}
	if (count == -1)
	{
		cout << "I didnt find this teacher\n";
		return teacher;
	}
	for (size_t i = 0; i < count; i++)
	{
		newTeacher[i] = teacher[i];
	}
	for (size_t i = count = 1; i < size; i++)
	{
		newTeacher[i - 1] = teacher[i];
	}
	delete[] teacher;
	size -= 1;
	return newTeacher;
}
void EditTeacher(Teacher* teacher, size_t size)
{
	if (teacher == nullptr || size == 0)
	{
		cout << "List is empy\n";
		return;
	}
	char name[100] = "";
	char surname[100] = "";
	int count = -1;
	cout << "Enter name of this teacher: ";
	cin >> name;
	cout << "Enter surname of this teacher: ";
	cin >> surname;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(name, teacher[i].name) == 0 && strcmp(surname, teacher[i].surname) == 0)
			count = i;
	}
	if (count == -1)
	{
		cout << "I didnt find this teacher\n";
		return;
	}
	cout << "Enter new name of this teacher: ";
	cin >> teacher[count].name;
	cout << "Enter new surname of this teacher: ";
	cin >> teacher[count].surname;
	cout << "Enter new email of this teacher: ";
	cin >> teacher[count].email;
	cout << "Enteer new age of this teacher: ";
	cin >> teacher[count].age;
}