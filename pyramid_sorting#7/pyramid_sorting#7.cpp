#include <iostream>
#include <vector>
#include "Heap.h"

int error_num(int& num)
{
	while (std::cin.fail())
	{
		std::cout << "Ошибка! Некорректный ввод!\n--> ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> num;
	}
	return num;
}

int size_check(int& size)
{
	while (size <= 0)
	{
		std::cout << "Ошибка! Размер листа не может быть меньше '0'\n--> ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> size;
		error_num(size);
	}
	return size;
}

void print(std::vector<int>& l, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << l[i] << " ";
	}

	std::cout << std::endl;
}


int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<int> list;
	int size;
	std::cout << "Введите размер листа\n--> ";
	std::cin >> size;
	size_check(size);
	std::cout << "Введите элементы листа:\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << "--> ";
		int n;
		std::cin >> n;
		error_num(n);
		list.push_back(n);
	}

	system("cls");
	std::cout << "Полученный массив:\n";
	print(list, list.size());


	return 0;
}