#include <iostream>
#include <list>
#include <vector>

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

void print(std::vector<int> &l)
{
	std::cout << "Элементы листа:\n";
	for (int conclusion : l)
	{
		std::cout << conclusion << " ";
	}
	std::cout << std::endl;
}

void ins_sort(std::vector<int>& v)
{
	if (v.empty())
	{
		std::cout << "Вектор пуст!\n";
		return;
	}

	for (int i = 0; i < v.size() - 1; i++)
	{//1 3 3 4 5  i = 3
		int tmp = v[i + 1]; //3
		int j = i;// 3
		while (j >= 0 && v[j] > tmp)
		{
			v[j + 1] = v[j];
			--j;
		}
		v[j + 1] = tmp;
	}

}

int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<int> vector_for_sort;

	std::cout << "Введите размер листа: ";
	int size;
	std::cin >> size;
	size_check(size);

	std::cout << "Введите элементы листа.\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << "--> ";
		int input;
		std::cin >> input;
		error_num(input);
		vector_for_sort.push_back(input);
	}
	print(vector_for_sort);
	ins_sort(vector_for_sort);
	print(vector_for_sort);


	return 0;
}