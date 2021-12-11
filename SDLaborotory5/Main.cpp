#include <iostream>;
#include <time.h>
#include "HashTable.h"
using namespace std;


void PrintMenu()
{
	cout << endl;
	cout << "1. Add." << endl;
	cout << "2. Delete." << endl;
	cout << "3. Search." << endl;
	cout << "0. Exit." << endl;
}

// �������� ����������� ����� ������ � ����
//
int ChoiseVariant(int count)
{
	int variant;
	cout << "Chouse vairant: ";
	cin >> variant;
	while (variant < 0 or variant>3)
	{
		cout << "Incorrect input. Try again. " << endl;
		cout << "Chouse vairant: ";
		cin >> variant;
	}
	return variant;
}

void MainMenu()
{
	HashT map;
	string result;
	string element;
	string key;
	int count = 7; // ���������� ������� � ����
	int variant; // ����� ����, ��������� �������������

	do
	{
		system("cls");
		map.PrintMap();
		PrintMenu();
		variant = ChoiseVariant(3);
		switch (variant)
		{
		case 1:
			cout << "Enter key: ";
			cin >> key;
			cout << "Enter value: ";
			cin >> element;
			map.Add(key, element);
			break;
		case 2:
			cout << "Enter key: ";
			cin >> key;
			map.Delete(key);
			break;
		case 3:
			cout << "Enter key: ";
			cin >> key;
			result = map.Search(key);
			cout << "Value: " << result << endl;;
			system("pause");
			break;
		default:
			break;
		}
		if (variant == 0)
		{
			system("pause");
		}
	} while (variant != 0);
}

int main()
{
	srand(time(NULL));

	MainMenu();
	return 0;
}