#include <iostream>
#include <bitset>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr");

    // Вхідні дані
    unsigned int a = 12;   // 4 біти (0-15)
    unsigned int b = 9;    // 4 біти (0-15)
    unsigned int c = 2065; // 12 бітів (0-4095)
    unsigned int d = 31;   // 5 бітів (0-31)
    unsigned int e = 1;    // 1 біт (0-1)

    // Компактне збереження
    uint32_t compact = 0;
    compact |= (a & 0b1111) << 28;  // Зберігаємо 4 біти для a у старші біти (28-31)
    compact |= (b & 0b1111) << 24;  // Зберігаємо 4 біти для b (24-27)
    compact |= (c & 0b111111111111) << 12; // Зберігаємо 12 бітів для c (12-23)
    compact |= (d & 0b11111) << 7;  // Зберігаємо 5 бітів для d (7-11)
    compact |= (e & 0b1);           // Зберігаємо 1 біт для e (0)

    // Виведення компактної змінної
    cout << "Компактне представлення: " << bitset<32>(compact) << endl;

    // Витяг значень
    unsigned int extracted_a = (compact >> 28) & 0b1111;         // Витягуємо 4 біти для a
    unsigned int extracted_b = (compact >> 24) & 0b1111;         // Витягуємо 4 біти для b
    unsigned int extracted_c = (compact >> 12) & 0b111111111111; // Витягуємо 12 бітів для c
    unsigned int extracted_d = (compact >> 7) & 0b11111;         // Витягуємо 5 бітів для d
    unsigned int extracted_e = compact & 0b1;                    // Витягуємо 1 біт для e

    // Виведення витягнутих значень
    cout << "Витягнуті значення:" << endl;
    cout << "a = " << extracted_a << endl;
    cout << "b = " << extracted_b << endl;
    cout << "c = " << extracted_c << endl;
    cout << "d = " << extracted_d << endl;
    cout << "e = " << extracted_e << endl;

    return 0;
}
