#include "Userio.h"

int PrintMenu() {
	using namespace std;
	

	cout << "0. �����" << endl;
	cout << "1. ��������� �� ����� � ���������� �� ���������� ������� Zn (������ 1)" << endl;
	cout << "2. �������� �� �������� �� ���������� ������� Zn (������ 2)" << endl;
	cout << "3. ��������� �� �������� �� ���������� ������� Zn (������ 3)" << endl;
	cout << "4. ��������� �� �������� �� ���������� ������� Zn (������ 4)" << endl;
	cout << "5. �������� �� �������� ���������� �������� � Zn (������ 5)" << endl;
	cout << "6. �� �� ������ ���������� (�������) �� ������� �� ����������� ������� �� Zn (������ 6) " << endl;
	cout << "7. �� �� ������ ���������� ������� �� Zn, ����������� ����������� �� ���� (������ 7)" << endl;
	cout << "8. ������� �� �������� �� Zn (������ 8)" << endl;
	cout << "9. ����� ����������� �� ����� (1-�� �����) (������ 9)" << endl;
	cout << "10. ����� ����������� �� ����� (2-�� �����) (������ 10)" << endl;
	cout << "11. �������� ���� ���� ����� �� Zn � ���������� ����� (������ 11)" << endl;
	cout << "12. �������� �� ������ ���������� ������ � Zn (������ 12)" << endl;
	cout << "13. ����������� �� ��������� ��������� � Zn (������ 13)" << endl;
	cout << "14. �������� ���� Zn � ��������� ���� (������ 14)" << endl;

	
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
		cout << "������ �������� �� ��������� ������� Zn (������ 1)" << endl;
		return 1;
	}
	switch (option) {
	case 1: zad1(arr[0], n);
		break;

	case 2:cout << "�������� �������� �� �: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "�������� �������� �� b: " << endl;
		EnterNumber(b, 0, n - 1);
		zad2(n, a, b);
		break;

	case 3:cout << "�������� �������� �� �: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "�������� �������� �� b: " << endl;
		EnterNumber(b, 0, n - 1);
		zad3(n, a, b);
		break;

	case 4:cout << "�������� �������� �� �: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "�������� �������� �� b: " << endl;
		EnterNumber(b, 0, n - 1);
		zad4(n, a, b);
		break;

	case 5:zad5(arr[1], n);
		break;

	case 6:cout << "�������� �����: ";
		EnterNumber(a, 0, n - 1);
		zad6(arr[1], n, a);
		break;

	case 7:
		cout << "�������� �����: ";
		EnterNumber(a, 0, n - 1);
		zad7(n, a);
		break;

	case 8:cout << "�������� ������� �����: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "�������� ������� �����: " << endl;
		EnterNumber(b, 0, n - 1);
		zad8(arr[1], n, a, b);
		break;

	case 9:cout << "�������� ����: " << endl;
		EnterNumber(a, 0, n - 1);
		cout << "�������� ������: " << endl;
		EnterNumber(b, INT32_MIN, INT32_MAX);
		zad9(arr[1], n, a, b);
		break;

	case 10:cout << "�� � ���������! :(" << endl;
		break;

	case 11:cout << "�� � ��������� :(" << endl;
		break;

	case 12:
		cout << "�� � ��������� :(" << endl;
		break;

	case 13:
		cout << "�� � ��������� :(" << endl;
		break;

	case 14:zad14(n);
		break;



	default:cout << "���������! :D" << endl;
		return 0;
	}


	
		

	return 1;
}