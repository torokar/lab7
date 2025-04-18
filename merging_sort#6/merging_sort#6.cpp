#include <iostream>
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

void print(std::vector<int>& l)
{
	std::cout << "Элементы листа:\n";
	for (int conclusion : l)
	{
		std::cout << conclusion << " ";
	}
	std::cout << std::endl;
}

void merge_sort(std::vector<int>& vec, int left, int right)
{
	if (right - left < 2) return;

	if (right - left == 2) // если два элемента их сравниваем и меняем при необходимости 
	{
		if (vec[left] > vec[left + 1])
			std::swap(vec[left], vec[left + 1]);
		return;
	}

	merge_sort(vec, left, left + (right - left) / 2);  //левая часть  4,  5  43,  76,  правая часть  1  13, ,3, 99
	merge_sort(vec, left + (right - left) / 2, right); 

	std::vector<int> merged;  // Массив для хранения объединённых элементов
	size_t leftIndex = left;  // Индекс для левой половины  0
	size_t middle = left + (right - left) / 2;  // Индекс середины  4
	size_t rightIndex = middle;  // Индекс для правой половины 4

	while (merged.size() < right - left)  // Пока не собрали все элементы
	{
		// Если левая половина закончилась, берем из правой
		if (leftIndex >= middle || (rightIndex < right && vec[rightIndex] < vec[leftIndex]))
		{
			merged.push_back(vec[rightIndex]);  // Берём из правой половины
			++rightIndex;  // Двигаем индекс правой половины
		}
		else  // Иначе берём из левой половины
		{
			merged.push_back(vec[leftIndex]);  // Берём из левой половины
			++leftIndex;  // Двигаем индекс левой половины
		}
	}

	// Переносим отсортированные данные обратно в исходный вектор
	for (int i = 0; i < merged.size(); i++)
	{
		vec[left + i] = merged[i];
	}

}

int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<int> vec = { 4, 5, 76,43,13,1,3,99 };
	std::cout << "Введите размер вектора: ";
	int size;
	//std::cin >> size;
	//size_check(size);
	//std::cout << "Введите элементы вектора:\n";
	//for (int i = 0; i < size; i++)
	//{
	//	int tmp;
	//	std::cout << "--> ";
	//	std::cin >> tmp;
	//	error_num(tmp);
	//	vec.push_back(tmp);
	//}
	std::cout << "Полученный вектор:\n";
	print(vec);

	merge_sort(vec, 0, vec.size());
	print(vec);



	return 0;
}