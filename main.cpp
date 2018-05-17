#include <iostream>
#include <cassert>
using namespace std;
char nibble_to_hex(uint8_t i)
{
    assert(0x0 <= i && i <= 0xf);
    char digits[] = "0123456789abcdef";
    return digits[i];
}
void nibble_in_hex(uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4);
    cout << nibble_to_hex(byte & 0xf);
}


char bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}

void print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit > 0; bit--) {
        cout << bit_digit(byte, bit);
    }
    cout << bit_digit(byte,0);
}

const uint8_t* as_bytes(const void* data) {
    return reinterpret_cast<const uint8_t*>(data);
}

void print_in_hex(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        nibble_in_hex(bytes[i]);
        // Для удобства чтения: пробелы между байтам, по 16 байт на строку.
        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}

void print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);
        // Для удобства чтения: пробелы между байтами, по 4 байта на строку.
        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}

void test() {
    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');
}


struct Student{
    char name[17];
    uint32_t year;
    float srednBall;
    int sex:1;// :1 - означает, что переменная занимает только 1 бит
    uint8_t courses;
    Student *starosta;
};

int main()
{
    test;
    uint32_t u32 = 42;
    cout << "u32 bytes: ";
    print_in_binary(&u32, sizeof(u32));
    cout << '\n';

    uint8_t per=0b10101010;
print_in_hex(&per, sizeof(per));
    cout<<endl;

    Student Stud_array[3]={
            {"Oskar Yald",2017,4.4,1,7,&Stud_array[1]},
            {"Fedor Dostaevski",2017,4.7,1,7,nullptr},// nullptr - нулевой указатель
            {"Hunter Tompson",2017,4.2,1,7,&Stud_array[3]}
    };
//Напечатаем адресс и размер массива и его элементов
    cout<<"Address of array:"<<&Stud_array<<endl;
    cout<<"Size of array:"<<sizeof(Stud_array)<<endl;
    cout<<"Address of elem:\t Size of elem:\n";
    for(int j=0;j<3;j++){
        cout<<j<<":\t"<<&Stud_array[j]<<"\t"<<sizeof(Stud_array[j])<<endl;
    }
//для всех полей, кроме пола1, одного из элементов массива (не старосты):
// адрес, смещение от начала структуры, размер,
// шестнадцатеричное и двоичное представление;

    cout<<"FIRST ELEMENT\n";
    cout<<"Addres of field:\tSize of field:\toffset:\n";

    cout<<"NAME:\n";
    cout<<&Stud_array[0].name<<"\t"<< sizeof(Stud_array[0].name)<<"\t";
    cout<<offsetof(struct Student,name)<<endl;

    cout<<"YEAR:\n";
    cout<<&Stud_array[0].year<<"\t"<< sizeof(Stud_array[0].year)<<"\t";
    cout<<offsetof(struct Student,year)<<endl;

    cout<<"SRED_BALL:\n";
    cout<<&Stud_array[0].srednBall<<"\t"<< sizeof(Stud_array[0].srednBall)<<"\t";
    cout<<offsetof(struct Student,srednBall)<<endl;

    cout<<"COURSES:\n";
    cout<<&Stud_array[0].courses<<"\t"<< sizeof(Stud_array[0].courses)<<"\t";
    cout<<offsetof(struct Student,courses)<<endl;

    cout<<"NAME:\n";
    cout<<"BINARY:";
    print_in_binary(&Stud_array[0].name, sizeof(Stud_array[0].name));
    cout<<"HEX:";
    print_in_hex(&Stud_array[0].name, sizeof(Stud_array[0].name));
    cout<<endl;

    cout<<"YEAR:\n";
    cout<<"BINARY:";
    print_in_binary(&Stud_array[0].year, sizeof(Stud_array[0].year));
    cout<<"HEX:";
    print_in_hex(&Stud_array[0].year, sizeof(Stud_array[0].year));
    cout<<endl;

    cout<<"SRED_BALL:\n";
    cout<<"BINARY:";
    print_in_binary(&Stud_array[0].srednBall, sizeof(Stud_array[0].srednBall));
    cout<<"HEX:";
    print_in_hex(&Stud_array[0].srednBall, sizeof(Stud_array[0].srednBall));
    cout<<endl;

    cout<<"COURSES:\n";
    cout<<"BINARY:";
    print_in_binary(&Stud_array[0].courses, sizeof(Stud_array[0].courses));
    cout<<"HEX:";
    print_in_hex(&Stud_array[0].courses, sizeof(Stud_array[0].courses));
    cout<<endl;

};