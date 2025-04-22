//Линейный поск
#include <iostream>
#include <string>
#include <Windows.h>

int LineFaind(int* mas, int size, int key);
void print(int* mas, int size);
int error_input(int &input);
int get_positive_size();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //Кодировка 1251 русский текст и ввод в консоли 


	std::cout << "Введите размер массива:\n--> ";
	int size = get_positive_size();
	
	error_input(size);
	if (size == 0)
	{
		std::cout << "Массив пуст!\n";
		return 1;
	}
	int* mas = new int[size]; //динамический массив 


	for (int i = 0; i < size; i++)
	{
		std::cout << "Введите элементы массива: " << i + 1 << std::endl << "--> ";
		int input_in_mas;
		std::cin >> input_in_mas;
		error_input(input_in_mas);
		mas[i] = input_in_mas; //Запись элементов в массив
	}
	print(mas, size);

	std::cout << "\nВведите элемент для поиск:\n--> ";
	int key;
	std::cin >> key;
	int result = LineFaind(mas, size, key);

	if (result == -1) { std::cout << "Данного элемента нет.\n"; }
	else{std::cout << "Искомый элемент стоит на позиции " << result << std::endl; }


	delete[] mas; //Освобождение памяти

	return 0;
}

int LineFaind(int* mas, int size, int key) // Сам алгоритм линейного поиска
{
	int pos = 0;
	while (pos < size && mas[pos] != key) { pos++; }
	if (pos == size) //Условие если элемент не найден
	{
		pos = -1;
	}
	return pos;
}

void print(int* mas, int size)
{
	std::cout << "Элементы массива:\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << mas[i] << " ";
	}
}

int error_input(int &input)
{
	int reset;
	while (std::cin.fail())
	{
		std::cerr << "Ошибка: Введите целое число без букв или символов!\n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "--> ";
		std::cin >> input;
	}
	return input;
}

int get_positive_size()
{
	int input;
	std::cin >> input;
	error_input(input);
	while (input < 0)
	{
		std::cerr << "Ошибка: значение должно быть положительным\n--> ";
		std::cin >> input;
		error_input(input);
	}
	return input;
}
