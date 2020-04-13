#include <iostream>
#include <ctime>

using namespace std;
void FillArray(int** arr, size_t rows, size_t cols);
void ShowArray(const int* const* arr, size_t rows, size_t cols);
void DeleteArray(int** arr, size_t rows);
int** CreateArray(size_t rows, size_t cols);
int** MultiplyMatrix(int** arr, int** arr2, size_t rows, size_t cols1, size_t cols2);

int main()
{
	srand(time(nullptr));
	int firstRows, firstCols, secRows, secCols;
	cout << "Enter rows and columm of first array: ";
	cin >> firstRows >> firstCols;
	cout << "Enter rows and columm of second array: ";
	cin >> secRows >> secCols;
	if (firstRows == secCols)
	{
		int** arr = CreateArray(firstRows, firstCols);
		int** secArr = CreateArray(secRows, secCols);
		FillArray(arr, firstRows, firstCols);
		ShowArray(arr, firstRows, firstCols);
		FillArray(secArr, secRows, secCols);
		ShowArray(secArr, secRows, secCols);
		int** matrix = MultiplyMatrix(arr, secArr, firstRows, firstCols, secCols);
		ShowArray(matrix, firstRows, secCols);
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

int** MultiplyMatrix(int** arr, int** arr2, size_t rows, size_t cols1, size_t cols2)
{
	int** matrix = CreateArray(rows, cols2);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols2; j++)
		{
			matrix[i][j] = 0;
			for (size_t k = 0; k < cols1; k++)
				matrix[i][j] += arr[i][k] * arr2[k][j];
		}
	}
	return matrix;
}

