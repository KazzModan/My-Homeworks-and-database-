#include <iostream>
#include <ctime>
using namespace std;

void FillArray(int** arr, size_t rows, size_t cols);
void ShowArray(const int* const* arr, size_t rows, size_t cols);
void DeleteArray(int** arr, size_t rows);
int** CreateArray(size_t rows, size_t cols);
bool isOdd(int numb);
bool isSimple(int numb);
bool isZero(int numb);
void Do(int** arr, bool(*predicate)(int), size_t rows, size_t cols);
int main()
{
	srand(time(nullptr));
	int rows = 2, cols = 5;
	int** arr = CreateArray(rows, cols);
	FillArray(arr, rows, cols);
	ShowArray(arr, rows, cols);

	cout << "Odd Numbers: "; Do(arr, isOdd, rows, cols);
	cout << "Simple Numbers: "; Do(arr, isOdd, rows, cols);
	cout << "Zero Numbers: "; Do(arr, isZero, rows, cols);
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

bool isOdd(int numb)
{
	if (numb == 0)
		return false;
	int count = 0;
	if (numb % 2 == 0)
		return false;
	else
		return true;
}

bool isSimple(int numb)
{
	int c = 0;
	cin >> numb;
	for (int i = 2; i <= numb; i++)
	{
		if (numb % i == 0)
			c++;
	}
	if (c < 2)
		cout << "Simple";
	return true;
}

bool isZero(int numb)
{
	return numb == 0 ? true : false;
}

void Do(int** arr, bool(*predicate)(int), size_t rows, size_t cols)
{
	int count = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (predicate(arr[i][j]))
				count++;
		}
	}
	cout << count << endl;
}
