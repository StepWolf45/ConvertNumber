#include <iostream>
#include <string>
#include<windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string form3(const string s1, const string form_odin, int size) {
	string result="";
	int carry = 0;
	for (int i = size-1; i>=0;i--)
	{
		int bit1 = s1.at(i) - '0';
		int bit2 = form_odin.at(i) - '0';
		char sum = (bit1 ^ bit2 ^ carry) + '0';
		result = sum + result;
		carry = (bit1 & carry) | (bit2 & carry) | (bit1 & bit2);
	}
	if (carry) {
		result = "1" + result;
	}
	return result;
}
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
		cout << "Произошло переполнение!! Некоторые элементы удалены !!" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		result_form_1 = binary.erase(0, length - size);
	}
	else if (size - length == 0) {
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Произошло переполнение!! Некоторые элементы удалены !!" << endl;
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
		if (size - length < 0) { 
			rejim = 0; 
		}
		else { 
			rejim = 1; 
			result_form_2 += "1";
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
		string odin = form1( "1", size, 1, 1);
		string dop = form3(result_form_2, odin, size);
		int length2 = dop.size();
	    if (size - length2 < 0) {
			dop = dop.erase(0, length2 - size);
		}
		cout << "Дополнительный код: " <<dop<<endl;

	}

	

}
