#include <iostream>
#include <vector>
#define DEBU
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

void quic_sort(std::vector<int>& list, int left, int right)
{
	if (list.empty())
	{
		std::cout << "Лист пуст!\n\n";
		return;
	}
	if (left > right)
	{
		return;
	}

	int pivon = list[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (list[i] < pivon) ++i;
		while (list[j] > pivon) --j;
		if (i <= j)
		{
			int tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;
			++i;
			--j;

		}
	}
	quic_sort(list, left, j);
	quic_sort(list, i, right);
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
	int left = 0;
	int right = list.size() - 1;

#ifdef DEBUG
	std::cout << "Левый элемент: " << left << std::endl;
	std::cout << "Правый элемент: " << right << std::endl;
#endif // DEBUG


	quic_sort(list, left, right);
	
	std::cout << "Отсортированный вектор:\n";
	print(list, list.size());


	return 0;
}