#include <iostream>
#include <ctime>

using namespace std;
void FillArray(int** arr, size_t rows, size_t cols);
void ShowArray(const int* const* arr, size_t rows, size_t cols);
void DeleteArray(int** arr, size_t rows);
int** CreateArray(size_t rows, size_t cols);
int** AddMatrix(int** arr, int** arr2, size_t rows, size_t cols);

int main()
{
	srand(time(nullptr));
	int firstRows, firstCols, secRows, secCols;
	cout << "Enter rows and columm of first array: ";
	cin >> firstRows >> firstCols;
	cout << "Enter rows and columm of second array: ";
	cin >> secRows >> secCols;
	if (firstRows == secRows && firstCols == secCols)
	{
		int** arr = CreateArray(firstRows, firstCols);
		int** secArr = CreateArray(secRows, secCols);
		FillArray(arr, firstRows, firstCols);
		ShowArray(arr, firstRows, firstCols);
		FillArray(secArr, secRows, secCols);
		ShowArray(secArr, secRows, secCols);
		int** matrix = AddMatrix(arr, secArr, firstRows, firstCols);
		ShowArray(matrix, firstRows, firstCols);
		DeleteArray(arr, firstRows);
		DeleteArray(secArr, secRows);
		DeleteArray(matrix, firstRows);
	}
	else
		cout << "Wrong size of matrixes\n";

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

int** CreateArray(size_t rows, size_t cols)
{
	int** ptr = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		ptr[i] = new int[cols];
	}
	return ptr;
}

int** AddMatrix(int** arr, int** arr2, size_t rows, size_t cols)
{
	int** matrix = CreateArray(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = arr[i][j] + arr2[i][j];
		}
	}
	return matrix;
	DeleteArray(matrix, rows);
}

