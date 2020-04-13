#include <iostream>
#include <ctime>

using namespace std;
void FillArray(int** arr, size_t rows, size_t cols);
void ShowArray(const int* const* arr, size_t rows, size_t cols);
void DeleteArray(int** arr, size_t rows);
int** CreateArray(int rows, int cols);
int** addRows(int** arr, int cols, int& rows);
int** addCols(int** arr, int& cols, int rows);
int** SubsractRows(int** arr, int cols, int& rows);
int** SubsractCols(int** arr, int& cols, int rows);
int main()
{
	srand(time(nullptr));
	int rows = 3;
	int cols = 3;
	int choose = 0;
	int** arr = CreateArray(rows, cols);
	int& rowsL = rows;
	int& colsL = cols;
	FillArray(arr, rows, cols);
	bool IsCorrect = false;
	while (!IsCorrect)
	{
		cout << "Enter your choose\n";
		cout << "1- Show array\n";
		cout << "2- Add row to array\n";
		cout << "3- Substract row from array\n";
		cout << "4- Add collum to array\n";
		cout << "5- Substract collum from array\n";
		cout << "6- Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			ShowArray(arr, rows, cols);
			break;
		case 2:
			arr = addRows(arr, cols, rowsL);
			break;
		case 3:
			arr = SubsractRows(arr, cols, rowsL);
			break;
		case 4:
			arr = addCols(arr, colsL, rows);
			break;
		case 5:
			arr = SubsractCols(arr, cols, rows);
			break;
		case 6:
			IsCorrect = true;
		}
	}

	system("pause");
	return 0;
}

void FillArray(int** arr, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}

void ShowArray(const int* const* arr, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------------------------\n";
}

void DeleteArray(int** arr, size_t rows)
{
	for (size_t i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
}

int** CreateArray(int rows, int cols)
{
	int** ptr = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		ptr[i] = new int[cols];
	}
	return ptr;
}

int** addRows(int** arr, int cols, int& rows)
{
	int** newArr = CreateArray(rows + 1, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			newArr[i][j] = arr[i][j];
	for (size_t i = rows; i < rows + 1; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			newArr[i][j] = rand() % 10;
		}
	}
	rows += 1;
	return newArr;
}

int** SubsractCols(int** arr, int& cols, int rows)
{
	int** newArr = CreateArray(rows, cols - 1);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols - 1; j++)
			newArr[i][j] = arr[i][j];
	cols -= 1;
	return newArr;
}

int** SubsractRows(int** arr, int cols, int& rows)
{
	int** newArr = CreateArray(rows - 1, cols);
	for (int i = 0; i < rows - 1; i++)
		for (int j = 0; j < cols; j++)
			newArr[i][j] = arr[i][j];
	rows -= 1;
	return newArr;
}

int** addCols(int** arr, int& cols, int rows)
{
	int** newArr = CreateArray(rows, cols + 1);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			newArr[i][j] = arr[i][j];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = cols; j < cols + 1; j++)
		{
			newArr[i][j] = rand() % 10;
		}
	}
	cols += 1;
	return newArr;
}






