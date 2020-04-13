#include <iostream>

using namespace std;

int main()
{
    int arr[5] = { 2,1,3,5,4 };

    for (int i = 0; i < 5; i++)
    {
        int min = arr[i];
        for (int j = i + 1; j < 5; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i];
    }
    return 0;
}