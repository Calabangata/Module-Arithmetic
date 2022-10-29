#include "Userio.h"

int PrintMenu() {
	using namespace std;
	

	cout << "0. Изход" << endl;
	cout << "1. Запълване на масив с елементите на остатъчния пръстен Zn (Задача 1)" << endl;
	cout << "2. Събиране на елементи от остатъчния пръстен Zn (Задача 2)" << endl;
	cout << "3. Изваждане на елементи от остатъчния пръстен Zn (Задача 3)" << endl;
	cout << "4. Умножение на елементу от остатъчния пръстен Zn (Задача 4)" << endl;
	cout << "5. Намиране на двойките реципрочни елементи в Zn (Задача 5)" << endl;
	cout << "6. Да се намери реципрочен (обратен) на зададен от потребителя елемент от Zn (Задача 6) " << endl;
	cout << "7. Да се намери реципрочен елемент от Zn, използвайки тъждеството на Безу (Задача 7)" << endl;
	cout << "8. Деление на елементи от Zn (Задача 8)" << endl;
	cout << "9. Бързо степенуване на число (1-ви метод) (Задача 9)" << endl;
	cout << "10. Бързо степенуване на число (2-ри метод) (Задача 10)" << endl;
	cout << "11. Проверка дали едно число от Zn е примитивен корен (Задача 11)" << endl;
	cout << "12. Намиране на всички примитивни корени в Zn (Задача 12)" << endl;
	cout << "13. Изчисляване на дискретен логаритъм в Zn (Задача 13)" << endl;
	cout << "14. Проверка дали Zn е остатъчно поле (Задача 14)" << endl;

	
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
	system("cls"); //("clear") за Linux
	int a, b;

	if (arr[0] == nullptr&&option > 1) {
		cout << "Липсва стойност за остатъчен пръстен Zn (Задача 1)" << endl;
		return 1;
	}
	switch (option) {
	case 1: zad1(arr[0], n);
		break;

	case 2:cout << "Въведете стойност за а: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "Въведете стойност за b: " << endl;
		EnterNumber(b, 0, n - 1);
		zad2(n, a, b);
		break;

	case 3:cout << "Въведете стойност за а: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "Въведете стойност за b: " << endl;
		EnterNumber(b, 0, n - 1);
		zad3(n, a, b);
		break;

	case 4:cout << "Въведете стойност за а: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "Въведете стойност за b: " << endl;
		EnterNumber(b, 0, n - 1);
		zad4(n, a, b);
		break;

	case 5:zad5(arr[1], n);
		break;

	case 6:cout << "Въведете число: ";
		EnterNumber(a, 0, n - 1);
		zad6(arr[1], n, a);
		break;

	case 7:
		cout << "Въведете число: ";
		EnterNumber(a, 0, n - 1);
		zad7(n, a);
		break;

	case 8:cout << "Въведете първото число: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "Въведете второто число: " << endl;
		EnterNumber(b, 0, n - 1);
		zad8(arr[1], n, a, b);
		break;

	case 9:cout << "Въведете база: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "Въведете степен: " << endl;
		EnterNumber(b, INT32_MIN, INT32_MAX);
		zad9(arr[1], n, a, b);
		break;

	case 10:cout << "Не е завършена! :(" << endl;
		break;

	case 11:cout << "Не е завършена :(" << endl;
		break;

	case 12:
		cout << "Не е завършена :(" << endl;
		break;

	case 13:
		cout << "Не е завършена :(" << endl;
		break;

	case 14:zad14(n);
		break;



	default:cout << "Довиждане! :D" << endl;
		return 0;
	}


	
		

	return 1;
}