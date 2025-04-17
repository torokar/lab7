#include <iostream>
#include <list>
#define DEBUG

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

void print(std::list<int>& l)
{
	std::list<int>::iterator it = l.begin();
	for (it; it != l.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "Элементы листа:\n";

	std::cout << std::endl;
}

void quic_sort(std::list<int>& list, std::list<int>::iterator left,
	std::list<int>::iterator right, int size)
{
	if (list.empty())
	{
		std::cout << "Лист пуст!\n\n";
		return;
	}
	int med = size / 2;
	std::list<int>::iterator it = list.begin();
	std::advance(it, med);
#ifdef DEBUG
	std::cout << "Средний элемент: " << *it << std::endl;
#endif // DEBUG
	

}

int main()
{
	setlocale(LC_ALL, "ru");
	std::list<int> list;
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
	print(list);
	quic_sort(list, list.begin(), list.end(), list.size());


	return 0;
}