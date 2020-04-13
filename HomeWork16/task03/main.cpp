#include <iostream>

using namespace std;

struct Teacher
{
	char name[100] = "";
	char surmane[100] = "";
	int age;
	char email[100] = "";

};
void CreateNewTeacher(Teacher& Teacher);
void ShowAllTeachers(const Teacher* Teacher, size_t size);
void ShowTeacher(const Teacher& Teacher);
Teacher* AddNewTeacher(Teacher* еeacher, size_t& size, const Teacher& newTeacher);
void ShowMenu();
void FindByName(const Teacher* Teacher, size_t size);
void ClearBuffer();
void ShowTeacherByCreators(const Teacher*, size_t size);
void ShowTeacherByStyle(const Teacher* Teacher, size_t size);
void ShowTeacherInDiap(const Teacher* Teacher, size_t  size);
Teacher* DeleteTeacher(Teacher* Teacher, size_t& size);
int main()
{
	size_t size = 0;
	Teacher* teachers = nullptr;
	Teacher newTeacher;
	int i = 0;
	int choose;
	do
	{
		ShowMenu();
		cin >> choose;
		ClearBuffer();

		switch (choose)
		{
		case 1:
			ShowAllTeachers(teachers, size);
			break;
		case 2:
			FindByName(teachers, size);
			break;
		case 3:
			ShowTeacherByCreators(teachers, size);
			break;
		case 4:
			ShowTeacherByStyle(teachers, size);
			break;
		case 5:
			ShowTeacherInDiap(teachers, size);
			break;
		case 6:
			CreateNewTeacher(newTeacher);
			teachers = AddNewTeacher(teachers, size, newTeacher);
			break;
		case 7:
			teachers = DeleteTeacher(teachers, size);
			break;
		case 0:
			cout << "Goodbay,see you next time\n";
			break;
		default:
			cout << "Incorrect choose, choose again\n";
			break;
		}
	} while (choose != 0);



	delete[] teachers;
	teachers = nullptr;
	return 0;

}

void CreateNewTeacher(Teacher& Teacher)
{
	cout << "Enter name of new Teacher: ";
	cin.getline(Teacher.name, 100);
	cout << "Enter surnaname of new teacher: ";
	cin.getline(Teacher.surmane, 100);
	cout << "Enter teacher mail: ";
	cin.getline(Teacher.email, 100);
	cout << "Enter Teacher age: ";
	cin >> Teacher.age;
	cin.ignore();
}

void ShowMenu()
{
	cout << "(1) Show all teachers\n";
	cout << "(2) Find Teacher by name\n";
	cout << "(3) Show Teacher by developers\n";
	cout << "(4) Show Teacher by genre\n";
	cout << "(5) Show teachers by prices\n";
	cout << "(6) Add new Teacher\n";
	cout << "(7) Delete Teacher by name\n";
	cout << "(0) Exit\n";
	cout << "-------------------------\n";
}

void FindByName(const Teacher* Teacher, size_t size)
{
	if (Teacher == nullptr || size == 0)
	{
		cout << "List is empy\n";
		return;
	}
	char nameOfTeacher[100]{ "" };
	cout << "Enter name of Teacher,which you find: ";
	cin.getline(nameOfTeacher, 100);
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(Teacher[i].name, nameOfTeacher) == 0)
		{
			ShowTeacher(Teacher[i]);
		}
	}

}

void ShowAllteachers(const Teacher* Teacher, size_t size)
{
	if (Teacher == nullptr || size == 0)
	{
		cout << "List is empy\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		ShowTeacher(Teacher[i]);
	}
}

void ShowTeacher(const Teacher& Teacher)
{
	cout << "Name of Teacher: " << Teacher.name << endl;
	cout << "Creator name: " << Teacher.surmane << endl;
	cout << "Teacher age: " << Teacher.age << endl;
	cout << "Teacher mail " << Teacher.email << endl;
	cout << "----------------------------\n";
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

void ClearBuffer()
{
	system("cls");
	while (cin.get() != '\n')
		continue;
}

//void ShowTeacherByCreators(const Teacher* Teacher, size_t size)
//{
//	if (Teacher == nullptr || size == 0)
//	{
//		cout << "List is empy\n";
//		return;
//	}
//	char creatorName[100]{ "" };
//	bool isFound = false;
//	cout << "enter name of creator,which you want find\n";
//	cin.getline(creatorName, 100);
//	for (size_t i = 0; i < size; i++)
//	{
//		if (strcmp(Teacher[i].creatorName, creatorName) == 0)
//		{
//			ShowTeacher(Teacher[i]);
//			isFound = true;
//		}
//	}
//
//	if (!isFound)
//		cout << "List doesn't include this developer.\n";
//}
//
//void ShowTeacherByStyle(const Teacher* Teacher, size_t size)
//{
//	if (Teacher == nullptr || size == 0)
//	{
//		cout << "List is empy\n";
//		return;
//	}
//	bool isFoud = false;
//	char styleOfTeacher[100]{ "" };
//	cout << "Enter name of Teacher,which you find: ";
//	cin.getline(styleOfTeacher, 100);
//	for (size_t i = 0; i < size; i++)
//	{
//		if (strcmp(Teacher[i].teacherstyle, styleOfTeacher) == 0)
//		{
//			ShowTeacher(Teacher[i]);
//			isFoud = true;
//		}
//	}
//	if (!isFoud)
//		cout << "List doesn't intclude this style\n";
//}
//
//void ShowTeacherInDiap(const Teacher* Teacher, size_t size)
//{
//	if (Teacher == nullptr || size == 0)
//	{
//		cout << "List is empy\n";
//		return;
//	}
//	int min, max;
//	cout << "Enter start and end of diapasone: ";
//	cin >> min >> max;
//	if (min > max)
//		swap(min, max);
//	bool isFound = false;
//	for (size_t i = 0; i < size; i++)
//	{
//		if (Teacher[i].TeacherPrice >= min && Teacher[i].TeacherPrice <= max)
//		{
//			isFound = true;
//			cout << "--- Teacher #" << i + 1 << " ---:\n";
//			ShowTeacher(Teacher[i]);
//		}
//	}
//	if (!isFound)
//		cout << "List doesn't include teachers with prices in your diapasone.\n";
//}
//
//Teacher* DeleteTeacher(Teacher* Teacher, size_t& size)
//{
//	if (Teacher == nullptr || size == 0)
//	{
//		cout << "Is is empy\n";
//		return nullptr;
//	}
//	Teacher* nTeacher = new Teacher[size - 1];
//	char nameOfTeacher[100]{ "" };
//	size_t delInd;
//	bool isFound = false;
//	int count = 0;
//	cout << "Enter name of Teacher, which you want delete";
//	cin.getline(nameOfTeacher, 100);
//
//	for (size_t i = 0; i < size; i++)
//	{
//		if (strcmp(Teacher[i].name, nameOfTeacher) != 0)
//		{
//			delInd = i;
//			isFound = true;
//			break;
//		}
//	}
//	if (isFound == false)
//	{
//		cout << "I didn't found your Teacher\n";
//		return Teacher;
//	}
//	for (size_t i = 0; i < delInd; i++)
//		nTeacher[count++] = Teacher[i];
//	for (size_t i = delInd + 1, coutn = 0; i < size; i++)
//		nTeacher[count++] = Teacher[i];
//
//	delete[] Teacher;
//	size--;
//	return nTeacher;
//}