#include"pch.h"
#include<iostream> 
#include<iomanip> 
#include<cmath> 
using namespace std;
const int n = 1000;
void mas_input(int mas[n], int a);
void mas_rand_input(int mas[n], int a);
int count(int mas[n], int a);
int min_search(int mas[n], int a);
void mas_output(int mas[n], int a);
int ref(int mas[n], int x);
void sort(int mas[n], int a);
int main()
{
	setlocale(LC_ALL, "Rus");
	int mas[n] = { '\0' };
	int a, choose;
	cout << "Доброго времени суток. Будьте добры, выберить один из предложенных вариантов: \n 1 - Ввод элементов массива вручную. \n 2 - Ввод элементов рандомно." << endl;
	do {
		cin >> choose;
		if (choose != 1 && choose != 2)
		{
			cout << "Проверьте введенные данные, пожалуйста." << endl;
		}

	} while (choose != 1 && choose != 2);

	switch (choose)
	{
	case 1:
	{
		do
		{
			cout << "Введите число заполняемых яйчеек массива: ";
			cin >> a;
			cout << endl;
			if (a < 1)
			{
				cout << "Ошибка! Число должно быть больше единицы." << endl;
			}
		} while (a < 1);
		mas_input(&mas[n], a);
		break;
	}
	case 2:
	{
		do
		{
			cout << "Введите число заполняемых яйчеек массива: ";
			cin >> a;
			cout << endl;
			if (a < 1 || a >= 1000)
			{
				cout << "Ошибка!!! Число должно быть больше единицы и меньше тысячи" << endl;
			}
		} while (a < 1 || a >= 1000);
		mas_rand_input(&mas[n], a);
		break;
	}
	};

	mas_output(&mas[n], a);
	cout << "Количество различных элеменов массави = " << count(&mas[n], a) << endl;
	int b = min_search(&mas[n], a);
	cout << "Произведение элементов = " << ref(&mas[n], b) << endl;
	sort(&mas[n], a);
	mas_output(&mas[n], a);
	system("pause");
	return 0;
}
void mas_input(int mas[n], int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << "mas[" << i << "] = ";
		cin >> mas[i];
		cout << endl;
	}
}
void mas_rand_input(int mas[n], int a)
{
	srand(time(NULL));
	for (int i = 0; i < a; i++)
	{
		mas[i] = rand() % (-201) + (-1)*101;
	}
}
int count(int mas[n], int a)
{
	int count = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (mas[i] == mas[j] && i != j)
			{
				count++;
				break;
			}

		}
	}
	return a - count;
}
int min_search(int mas[n], int a)
{
	int min, number;
	min = abs(mas[0]);
	number = 0;
	for (int i = 1; i < a; i++)
	{
		if (abs(mas[i]) < min)
		{
			min = abs(mas[i]);
			number = i;
		}
	}
	return number;
}
void sort(int mas[n], int a)
{
	int temp;
	for (int i = 1; i < a; i++)
	{
		if (mas[i] <= 0 && i != 0)
		{
			for (int j = i; j > 0; j--)
			{
				temp = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = temp;
			}
		}

	}
}
void mas_output(int mas[n], int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << mas[i] << "\t";
	}
	cout << endl;
}
int ref(int mas[n], int x)
{
	int ref = 1;
	for (int i = 0; i < x; i++)
	{
		ref *= mas[i];
	}
	return ref;
}