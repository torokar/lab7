#include <iostream>
#include <Windows.h>
#include <vector>
#include <random>

int bin_search(std::vector<int>& vec, int target)
{
	if (vec.empty())
	{
		return -1;
	}

	std::sort(vec.begin(), vec.end());

	int l = 0, r = vec.size() - 1; //начало/конец вектора
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (vec[m] == target)
		{
			return m;
		}
		if (vec[m] < target)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}

	}

	return -1;
}


int main()
{
	setlocale(LC_ALL, "ru");

	
	std::cout << "введите размер вектора:--> ";
	int size;
	std::cin >> size;
	while (std::cin.fail() || size <= 0)
	{
		std::cout << "Ошибка ввода! Введите число.\n--> ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> size;
	}
	std::vector<int> vec;

	std::cout << "Введите элементы массива:\n--> ";
	for (int i = 0; i < size; ++i)
	{
		int input;
		std::cin >> input;
		while (std::cin.fail())
		{
			std::cout << "Ошибка ввода! Введите число.\n--> ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin >> input;
		}
		vec.push_back(input);
	}

	std::cout << "Введите какой элемент нужно найти: ";
	int key;
	std::cin >> key;
	while (std::cin.fail())
	{
		std::cout << "Ошибка ввода! Введите число.\n--> ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> key;
	}
	int result = bin_search(vec, key);
	std::cout << "Элемент " << key << " находится под индексом " << result << std::endl;

	return 0;
}