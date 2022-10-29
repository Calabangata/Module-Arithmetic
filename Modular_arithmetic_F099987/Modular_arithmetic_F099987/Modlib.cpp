#include"Modlib.h"

void zad1(int*&arr, int&n) {
	std::cout << "Enter n: ";
	EnterNumber(n, 1, INT32_MAX);

	if (arr != nullptr) {
		delete[]arr;
		arr = nullptr;
	}
	arr = new int[n];
	if (arr != nullptr) {
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}

	}
	else {
		n = 0;
		std::cout << "" << std::endl;
	}
	//return 0;
}

void zad2(int n, int&a, int&b) {
	std::cout << a << " + " << b << " = " << (a + b) % n << std::endl;
	//return 0;
}

void zad3(int n, int&a, int&b) {
	int result = a - b;
	std::cout << result << std::endl;
	if (result < 0) result = result + n;
	std::cout << a << " - " << b << " = " << (a - b) % n << std::endl;
	//return 0;
}
void zad4(int n, int&a, int&b) {
	std::cout << a << " * " << b << " = " << (a*b) % n << std::endl;
	//return 0;
}

void  zad5_1(int*&array, int n) {
	if (array != nullptr) {
		delete[]array;
		array = nullptr;
	}
		array = new int[n];
		if (array != nullptr) {
			for (int i = 0; i < n; i++) {
				array[i] = -1;
			}
			for (int i = 1; i < n; i++) {
				if (array[i] != -1) continue;
				for (int j = 0; j < n; j++) {
					if ((i*j) % n == 1) {
						array[i] = j;
						array[j] = i;
					}
				}
			}
		}
		else {
			std::cout << "Could not allocate memory!" << std::endl;
			}
	//return 0;
}
void zad5(int*&array, int n) {
	zad5_1(array, n);

	if (array != nullptr) {
		for (int i = 0; i < n; i++) {
			if (array[i] != -1) {
				std::cout << 1 << "/" << i << " = " << array[i] << std::endl;
			}
			else {
				std::cout <<1<< "/"<<i<<" is not divisible!" << std::endl;
			}
		}
	}
	else {
		std::cout << "Could not allocate memory!" << std::endl;
	}
	//return 0;
}
void zad6(int*array, int n, int a) {
	if (array == nullptr) zad5_1(array, n);
	if (array != nullptr) {
		if (array[a] != -1) {
			std::cout << "1/" << a << " = " << array[a] << std::endl;
		}
		else {
			std::cout << "1/" << a << " is not divisible!" << std::endl;
		}
	}
	else {
		std::cout << "Could not allocate memory!" << std::endl;
	}
	//return 0;
}
void zad7(int n, int a){

	int tmp = n, tmp1 = n, tmp2 = a;
	unsigned cnt = 0;

	do {
		tmp = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp % tmp1;
		if (tmp2 == 0) break;
		cnt++;
	} while (tmp1 % tmp2 != 0);

	int* table[4];
	for (int i = 0; i < 4; i++) table[i] = new int[cnt + 2]{ 0 };
	if (table[0] && table[1] && table[2] && table[3]) {

		table[0][0] = n;
		table[0][1] = a;
		table[1][1] = n / a;
		table[2][0] = table[3][1] = 1;

		for (int i = 2; i < cnt + 2; i++) {
			table[0][i] = table[0][i - 2] % table[0][i - 1];
			table[1][i] = table[0][i - 1] / table[0][i];
			table[2][i] = table[1][i - 1] * table[2][i - 1] + table[2][i - 2];
			table[3][i] = table[1][i - 1] * table[3][i - 1] + table[3][i - 2];
		}

		if (table[0][cnt + 1] == 1 && table[3][cnt + 1] != -1) {
			std::cout << "1/" << a << " = " << table[3][cnt + 1] << std::endl;
		}
		else {
			std::cout << "1/" << a << " is not divisible!" << std::endl;
		}

		for (int i = 0; i < 4; i++) {
			delete[]table[i];
			table[i] = nullptr;
		}

	}
	else {
		std::cout << "Problem with memory allocation!" << std::endl;
	}

}
void zad8(int*&array, int n, int a, int b) {
	if (array == nullptr)zad5_1(array, n);

	if (array != nullptr) {
		if (array[b] != -1) {
			std::cout << a << "/" << b << " = " << (a*(array[b])%n) % n << std::endl;
		}
		else {
			std::cout << "-1" << std::endl;
		}
	}
	else {
		std::cout << "Could not allocate memory!" << std::endl;
	}
	//return 0;
}

void zad9(int *arr, int n, int num, int exponent){

	if (arr == nullptr)zad5_1(arr, n);

	if (arr != nullptr) {

		int new_num;
		bool negative = (exponent < 0) ? true : false;
		if (negative) {
			exponent *= -1;
		}

		if (num == 1 || exponent == 1) {
			if (n == 1) {
				std::cout << "Can not be calculated!" << std::endl;
				return;
			}
			new_num = 1;
		}
		else if (num == 0) {
			new_num = 0;
		}
		else if (exponent == 1) {
			new_num = num;
		}
		else if (exponent == 0) {
			new_num = 1;
		}
		else {
			int k = 2, tmp = (num * num) % n;

			while (tmp != 1) {
				if (k == exponent) break;
				tmp = (tmp * num) % n;
				k++;
			}
			tmp = num;
			if (k == exponent) {
				for (int i = 0; i < exponent - 1; i++) {
					tmp = (tmp * num) % n;
				}
			}
			else {
				for (int i = 0; i < (exponent % k) - 1; i++) {
					tmp = (tmp * num) % n;
				}
			}
			new_num = tmp;
		}
		if (negative) {
			if (arr[new_num] == -1) {
				std::cout << "Can not be calculated!" << std::endl;
				return;
			}
			else {
				new_num = arr[new_num];
			}

		}
		std::cout << num << " to the power of " << ((negative) ? "-" : "") << exponent << " is: " << new_num << std::endl;

	}
	else {
		std::cout << "Could not allocate memory!" << std::endl;
	}
	return;
}

void zad14(int n) {
	bool prime = true;
	for (int i = 2; i < n; i++) {
		if (n % 1 == 0) {
			prime = false;
			break;
		}
	}
	std::cout << "Z(" << n << ") " << ((prime) ? "is " : "is not ") << "finite field!\n";
	//return 0;
}