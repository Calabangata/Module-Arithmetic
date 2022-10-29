#include<iostream>
#include<clocale>
#include"Userio.h"
#include"Modlib.h"
using namespace std;
int main() {
	//setlocale(LC_ALL, "bulgarian");
	int option, n = 0;
	int**arr = new int*[2];
	arr[0] = arr[1] = nullptr;

	if (arr != nullptr) {
		do {
			PrintMenu();
			cout << "Enter option: ";
			EnterNumber(option);
		} while (Menu(option, arr, n));

		if (arr[0] != nullptr) {
			delete[]arr[0];
			arr[0] = nullptr;
		}
		if (arr[1] != nullptr) {
			delete[]arr[1];
			arr[1] = nullptr;
		}
		
		delete[]arr;
		arr = nullptr;
	}
	else {
		cout << "Could not allocate memory!" << endl;
	}
	return 0;
}