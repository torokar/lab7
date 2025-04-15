#include <iostream>
#include <string>

void bubl_sort(int *mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				std::swap(mas[j], mas[j + 1]);
			}
		}
	}
}
void print(int* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;
}



int main()
{
	setlocale(LC_ALL, "ru");
	int size;
	std::cout << "Введите размер массива: ";
	std::cin >> size;
	while (std::cin.fail() || size <= 0)
	{
		std::cout << "Ошибка 'size' не может быть отрицательным или буквенным значением!\n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> size;
	}
	int* mas = new int[size];
	

	std::cout << "Введите элементы массива:\n";
	for (int i = 0; i < size; i++)
	{
		int input;
		std::cin >> input;
		while (std::cin.fail())
		{
			std::cout << "Ошибка! Элемент массива не может быть буквенным значением!\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin >> input;
		}
		mas[i] = input;
	}
	std::cout << "Полученный массив:\n";
	system("cls");
	print(mas, size);
	std::cout << "\nОтсортированный массив:\n";
	bubl_sort(mas, size);
	print(mas, size);


	delete[] mas;

	return 0;
}