#include <iostream>
#include <string>
#include<windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string form1(string binary, int size, int length,int number) {
	string result_form_1 = "";
	if (size - length > 0) {
		if (number >= 0) {
			result_form_1 = string((size - length), '0') + binary;
		}
		else {
			result_form_1 = '1'+string((size - length-1), '0') + binary;
		}
	}
	else if (size - length < 0) {
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Произошло переполнение!! Некоторые элемент удалены !!" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		result_form_1 = binary.erase(0, length - size);
	}
	else if (size - length == 0) {
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Произошло переполнение!! Некоторые элемент удалены !!" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		result_form_1 = binary;
	}
	return result_form_1;
}

string to_binary_string(int n)
{
	string result="";
	do
	{
		result += char('0' + n % 2); 
		n = n / 2;
	} while (n > 0);
	return string(result.crbegin(), result.crend());
}

int main(){
	setlocale(LC_ALL, "Russian");

	int number, size;
	string binary = "";
	int rejim;
	cout << "Введите число для перевода: ";
	cin >> number;
	cout << "Cколько бит на его хранение: ";
	cin >> size;
	if (number < 0) {
		binary = to_binary_string(-number);
	}
	else {
		binary = to_binary_string(number);
	}

	string result_form_1= "";
	string result_form_2= "";
	string result_form_3= "";
	int length = binary.size();

	cout << endl;
	cout << "Двоичная форма числа: " << binary << endl;
	// Прямой код
	result_form_1 = form1(binary, size, length, number);
	cout << "Прямой код: " << result_form_1 << endl;

	if (number < 0) {
		if (size - length < 0) { rejim = 0; }
		else { rejim = 1; result_form_2 += "1";
		}

		for (int i = rejim; i < size; i++) {
			if (result_form_1[i] == '0') {
				result_form_2 += '1';
			}
			else {
				result_form_2 += '0';
			}
		}
		cout << "Обратный код: "<<result_form_2<<endl;
	}
	

}