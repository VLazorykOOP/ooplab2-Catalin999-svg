#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr");
    // Задано цілі числа a, b, c, d
    int a = 5, b = 3, c = 2, d = 4;

    // Використання long long для запобігання переповненню
    long long part1 = ((b << 4) + b); // 17 * b = (b * 16 + b)
    long long part2 = ((a << 11) + (a << 9) + (a << 8) + (a << 7) + (a << 6) + (a << 2)); // 3012 * a

    long long numerator = part1 + part2;  // 17 * b + 3012 * a
    long long division = numerator >> 5; // Ділення на 32

    long long part3 = (c << 7) - (c << 3); // c * 120 = c * (128 - 8) = (c << 7) - (c << 3)
    long long part4 = (d << 7) - d;       // d * 127 = (d * 128 - d) = (d << 7) - d

    // Підсумковий результат
    long long result = division - part3 + part4;

    // Виведення результату
    cout << "Результат: " << result << endl;

    return 0;
}
