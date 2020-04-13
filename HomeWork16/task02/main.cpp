#include <iostream>
#include <ctime>
using namespace std;
enum Week
{
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};
Week GetDay(int number);
int RandomNumberDay();
void AnalyzeDay(Week day);
void ShowFiveDays();
int main()
{
	srand(time(nullptr));
	Week today = GetDay(RandomNumberDay());
	AnalyzeDay(today);
	cout << endl;
	ShowFiveDays();

	return 0;
}

Week GetDay(int number)
{
	return Week(number);
}

int RandomNumberDay()
{
	int numb;
	numb = rand() % 7 + 1;

	return numb;
}

void AnalyzeDay(Week day)
{
	switch (day)
	{
	case Monday:
		cout << "Monday\n";
		break;
	case Tuesday:
		cout << "Tuesday\n";
		break;
	case Wednesday:
		cout << "Wednesday\n";
		break;
	case Thursday:
		cout << "Thursday\n";
		break;
	case Friday:
		cout << "Friday\n";
		break;
	case Saturday:
		cout << "Saturday\n";
		break;
	case Sunday:
		cout << "Sunday\n";
		break;
	default:
		break;
	}
}

void ShowFiveDays()
{
	const int SIZE = 5;
	Week days[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		days[i] = GetDay(RandomNumberDay());
		AnalyzeDay(days[i]);
	}
}
