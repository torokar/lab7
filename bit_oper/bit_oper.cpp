﻿#include <iostream>


int main() {
    setlocale(LC_ALL, "ru");
    int n;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cout << (3 << n) << std::endl;

    std::cout << "Введите m: ";
    int m;
    std::cin >> m;
    std::cout << (2 << n )+( 2 << m);

    return 0;
}
