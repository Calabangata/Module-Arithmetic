#include "Userio.h"

int PrintMenu() {
	using namespace std;
	

	cout << "0. Exit" << endl;
	cout << "1. Fill an array with the elements of the ring (task 1)" << endl;
	cout << "2. Addition of two elements in the ring (task 2)" << endl;
	cout << "3. Substraction of two elements in the ring (task 3)" << endl;
	cout << "4. Multiplication of two elements in the ring (task 4)" << endl;
	cout << "5. Find the reciprocal of the numbers (task 5)" << endl;
	cout << "6. Find the reciprocal of a specific number in the ring (task 6)" << endl;
	cout << "7. Find the reciprocal using Bezu's equation (task 7)" << endl;
	cout << "8. Divide two numbers in the ring (task 8)" << endl;
	cout << "9. Exponentiation of a number using method 1 (task 9)" << endl;
	cout << "10. Exponentiation of a number using method 2 (task 10)" << endl;
	cout << "11. Check if a number is a primitive root in Zn (task 11)" << endl;
	cout << "12. Find all the primitive roots in Zn (task 12)" << endl;
	cout << "13. Calculate discrete logarithm in Zn (task 13)" << endl;
	cout << "14. Check if Zn is a finite field" << endl;

	
	cout << endl;
	return 0;
}
int PrintArray(int**arr, int n) {
	using namespace std;
	if (arr != nullptr&&n > 0 && arr[0] != nullptr&&arr[1] != nullptr) {
		for (int i = 0; i < n; i++) {
			if (arr[1][i] != -1) {
				cout << "1/" << arr[0][i] << " = " << arr[1][i] << endl;
			}
			else {
				cout << "1/" << arr[0][i] << " is not divisible " << endl;
			}
		}
	}
	cout << endl;
	return 0;
}

int EnterNumber(int &number, int minimum, int maximum) {
	using namespace std;

	char ch[60];
	bool correct = true;
	int i = 0;
	do {
		do {
			correct = true;
			cin.getline(ch, 60);
			if (strlen(ch) == 0) {
				correct = false;
				continue;
			}
			i = 0;
			if (ch[0] == '-'&&strlen(ch) > 1) i++;
			for (; i<int(strlen(ch)); i++) {
				if (!(ch[i] >= '0'&&ch[i] <= '9')) {
					correct = false;
					break;
				}
			}
			if (!correct) cout << "Incorrect number!" << endl;

		} while (!correct);
		number = 0;
		i = 0;
		if (ch[0] == '-')i++;
		for (; i<int (strlen(ch)); i++){
			number = number * 10 + (ch[i] - '0');
		}
		if (ch[0] == '-') number *= -1;
		if (!(number >= minimum && number <= maximum)) cout << "The value can not be " << number << endl;

	} while (!(number >= minimum && number <= maximum));
	return 0;
}

bool Menu(int option, int**&arr, int &n) {
	using namespace std;
	system("cls"); //("clear") �� Linux
	int a, b;

	if (arr[0] == nullptr&&option > 1) {
		cout << "The array is not initialized yet! (task 1)" << endl;
		return 1;
	}
	switch (option) {
	case 1: zad1(arr[0], n);
		break;

	case 2:cout << "Enter value for a: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "Enter value for b: " << endl;
		EnterNumber(b, 0, n - 1);
		zad2(n, a, b);
		break;

	case 3:cout << "Enter value for a: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "Enter value for b: " << endl;
		EnterNumber(b, 0, n - 1);
		zad3(n, a, b);
		break;

	case 4:cout << "Enter value for a: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "Enter value for b: " << endl;
		EnterNumber(b, 0, n - 1);
		zad4(n, a, b);
		break;

	case 5:zad5(arr[1], n);
		break;

	case 6:cout << "Enter a number: ";
		EnterNumber(a, 0, n - 1);
		zad6(arr[1], n, a);
		break;

	case 7:
		cout << "Enter a number: ";
		EnterNumber(a, 0, n - 1);
		zad7(n, a);
		break;

	case 8:cout << "Enter the first number: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "Enter the second number: " << endl;
		EnterNumber(b, 0, n - 1);
		zad8(arr[1], n, a, b);
		break;

	case 9:cout << "Enter the base: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "Enter the exponent: " << endl;
		EnterNumber(b, INT32_MIN, INT32_MAX);
		zad9(arr[1], n, a, b);
		break;

	case 10:cout << "Not completed! :(" << endl;
		break;

	case 11:cout << "Not completed :(" << endl;
		break;

	case 12:
		cout << "Not completed :(" << endl;
		break;

	case 13:
		cout << "Not completed :(" << endl;
		break;

	case 14:zad14(n);
		break;



	default:cout << "Goodbye! :D" << endl;
		return 0;
	}


	
		

	return 1;
}