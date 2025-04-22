#include <iostream>  


int main() {
 
    setlocale(LC_ALL, "ru");
    int x = 0;
    x |= (1 << 0);
    std::cout << x << std::endl;

    x &= ~(1 << 0);
    std::cout << x << std::endl;

    //-------------------------------------------------------------
    int x1;
    std::cout << "Введите число: "; std::cin >> x1; //10 1010 0010
    int bi;
    std::cout << "Введите номер бита: "; std::cin >> bi; //2

    int bit = (x1 >> bi) & 1;

    std::cout << "Бит под номером " << bi << ": " << bit << std::endl;

    //-------------------------------------------------------------

    int n = 0;
    std::cout << "введите число: ";
    std::cin >> n;
    int posision = 0;
    std::cout << "Введите позицию: ";
    std::cin >> posision;
    int bit_ = (n >> posision) & 1;
    //--------------------------------------------------------------

    int a, b;

    // Ввод двух чисел
    std::cout << "Введите два целых числа: ";
    std::cin >> a >> b;

    // Алгоритм Евклида
    while (b != 0) {
        int r = a % b;  // Вычисляем остаток от деления a на b
        a = b;          // Теперь a принимает значение b
        b = r;          // b становится равным остатку
    }

    // Когда b станет равным 0, значение a и есть НОД
    std::cout << "Наибольший общий делитель: " << a << std::endl;

    //--------------------------------------------------------------
    std::string hexToBin[16] = {
        "0000", "0001", "0010", "0011",  // 0 - 3
        "0100", "0101", "0110", "0111",  // 4 - 7
        "1000", "1001", "1010", "1011",  // 8 - B
        "1100", "1101", "1110", "1111"   // C - F
    };

    std::string hex;
    std::cout << "Введите шестнадцатеричное число (без 0x): ";
    std::cin >> hex;

    std::string binary = "";
    for (char c : hex) {
        c = toupper(c);
        int index;
        if (c >= '0' && c <= '9') index = c - '0';
        else if (c >= 'A' && c <= 'F') index = c - 'A' + 10;
        else {
            std::cout << "Недопустимый символ: " << c << std::endl;
            return 1;
        }
        binary += hexToBin[index];
    }

    std::cout << "Двоичное представление: " << binary << std::endl;

    //--------------------------------------------------------------

    unsigned char byte;

    std::cout << "Введите целое число от 0 до 255: ";
    int input;
    std::cin >> input;

    if (input < 0 || input > 255) {
        std::cout << "Ошибка: число вне диапазона!" << std::endl;
        return 1;
    }

    byte = static_cast<unsigned char>(input);

    std::cout << "Биты байта: ";
    for (int i = 7; i >= 0; --i) {
        std::cout << ((byte >> i) & 1);
    }
    std::cout << std::endl;
    //--------------------------------------------------------------

    int n;
    std::cout << "Введите длину двоичных строк: ";
    std::cin >> n;

    int total = pow(2, n);  // Всего 2^n строк

    for (int i = 0; i < total; ++i) {
        std::string binStr = "";
        for (int j = n - 1; j >= 0; --j) {
            binStr += ((i >> j) & 1) ? '1' : '0';
        }
        std::cout << binStr << std::endl;
    }

    //--------------------------------------------------------------
    int n;
    std::cout << "Введите номер числа Фибоначчи (n >= 0): ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Ошибка: n должно быть неотрицательным!" << std::endl;
        return 1;
    }

    if (n == 0) {
        std::cout << "F(0) = 0" << std::endl;
    }
    else if (n == 1) {
        std::cout << "F(1) = 1" << std::endl;
    }
    else {
        long long prev = 0, curr = 1;
        for (int i = 2; i <= n; ++i) {
            long long next = prev + curr;
            prev = curr;
            curr = next;
        }
        std::cout << "F(" << n << ") = " << curr << std::endl;
    }


    return 0;
}