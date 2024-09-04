#include <iostream>
#include <iomanip>
#include <string>

int i, j, m = 3, n = 4, k, s;
float a[10][10], b[10][10];
char ch;
std::string x[10], y[10], z[10], temp;

// ввод матрицы
void input() {
	// создание переменных x и y
	x[0] = "1";
	y[0] = "0";
	for (i = 1; i < 10; i++) {
		x[i] = "x" + std::to_string(i);
		y[i] = "0";
	}
	std::cout << "Выбрать готовую матрицу? (y/n): ";
	std::cin >> ch;
	if (ch == 'y') {
		// готовая матрица
		float c[3][4];
		std::cout << "Выберите пример (1, 2, 3): ";
		std::cin >> ch;
		switch (ch) {
		case '1': {
			n = 5;
			float c[3][5] = {
			{4, 1, 2, 1, 0},
			{6, 1, 1, 0, 1},
			{10, 1, -1, -2, 3}
			};
			for (i = 0; i < m; i++)
				for (j = 0; j < n; j++)
					a[i][j] = c[i][j];
			break;
		}
		case '2': {
			float c[3][4] = {
			{1, 1, 2, 3},
			{1, 1, 1, 1},
			{2, -1, 0, -1}
			};
			for (i = 0; i < m; i++)
				for (j = 0; j < n; j++)
					a[i][j] = c[i][j];
			break;
		}
		case '3': {
			float c[3][4] = {
			{1, 1, 2, -4},
			{-1, 2, 1, -5},
			{1, -1, -1, 3}
			};
			for (i = 0; i < m; i++)
				for (j = 0; j < n; j++)
					a[i][j] = c[i][j];
			break;
		}
		default:
			break;
		}
	}
	else {
		// ввод с клавиатуры
		std::cout << "Введите количество строк: ";
		std::cin >> m;
		std::cout << "Введите количество столбцов: ";
		std::cin >> n;
		n++;
		std::cout << "Введите матрицу: \n";
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (j == 0)
					std::cout << i + 1 << " базисная переменная: ";
				else
					std::cout << "a[" << i + 1 << "][" << j << "]: ";
				std::cin >> a[i][j];
			}
		}
	}
}

// метод жордановых исключений
void jordanElimination() {
t:
	// выбор разрешающего элемента
	std::cout << "\nВыберите строку разрешающего элемента: ";
	std::cin >> k;
	k--;
	std::cout << "Выберите столбец разрешающего элемента: ";
	std::cin >> s;
	if ((k > m) || (s > n) || (k < 0) || (s < 0)) {
		std::cout << "\nРазрешающий элемент за пределами матрицы.\n";
		goto t;
	}
	if (a[k][s] == 0) {
		std::cout << "\nРазрешающий элемент не может быть нулевым.\n";
		goto t;
	}
	std::cout << "Разрешающий элемент: " << a[k][s] << "\n";
	// замена коэффициентов по методу жордановых исключений
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (i == k && j == s) {
				b[k][s] = 1 / a[k][s]; // разрешающий элемент становится 1, деленной на разрешающий элемент
			}
			else if (i == k && j != s) {
				b[i][j] = a[i][j] / a[k][s]; // элементы разрешающей k строки делятся на разрешающий элемент
			}
			else if (i != k && j == s) {
				b[i][j] = -a[i][j] / a[k][s]; // элементы разрешающего s столбца меняют свой знак на противоположный и делятся на разрешающий элемент
			}
			else
				b[i][j] = (a[i][j] * a[k][s] - a[i][s] * a[k][j]) / a[k][s]; // все остальные элементы считаются по правилу прямоугольника и делятся на разрешающий элемент
		}
	}
	// смена зависимого и независимого переменных
	temp = x[s];
	x[s] = y[k];
	y[k] = temp;
	// копирование матрицы b в матрицу a
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = b[i][j];
		}
	}
}

// вывод матрицы
void display() {
	std::cout << "\nМатрица: \n";
	// вывод зависимых переменных
	std::cout << "   ";
	for (j = 0; j < n; j++) {
		if (x[j] != "0" && x[j] != "1")
			std::cout << std::setw(7) << "-";
		else
			std::cout << std::setw(9);
		std::cout << x[j];
	}
	std::cout << std::endl;
	// вывод независимых переменных и коэффициентов
	for (i = 0; i < m; i++) {
		std::cout << std::setw(2) << y[i] << "=";
		for (j = 0; j < n; j++) {
			if (abs(a[i][j] == 0))
				std::cout << std::setprecision(2) << std::setw(9) << abs(a[i][j]);
			else
				std::cout << std::setprecision(2) << std::setw(9) << a[i][j];
		}
		std::cout << std::endl;
	}
}

// вывод системы
void sistemOfLE() {
	for (i = 0; i < m; i++)
		if (y[i] != "0") {
			std::cout << std::endl << y[i] << " = " << a[i][0];
			for (j = 1; j < n; j++)
				if (x[j] != "0" && a[i][j] != 0) {
					if (a[i][j] < 0) {
						std::cout << " + ";
					}
					if (a[i][j] > 0)
						std::cout << " - ";
					std::cout << abs(a[i][j]) << "*" << x[j];
				}
		}
	for (j = 0; j < n; j++)
		if (x[j] != "0" && x[j] != "1")
			std::cout << std::endl << z[j] << " = " << x[j] << std::endl;
}

// проверка на разрешимость
void solvability() {
	bool solv = false;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (x[j] != "0" && y[i] == "0" && a[i][0] != 0 && a[i][j] == 0) {
				solv = true;
			}
	if (solv == true) {
		std::cout << "\nСистема несовместна.\n";
	}
	else {
		std::cout << "\nСистема совместна:";
		sistemOfLE();
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	input();
	display();
	do {
		jordanElimination();
		display();
		std::cout << "Продолжить? (y/n): ";
		std::cin >> ch;
	} while (ch == 'y');
	for (j = 0; j < n; j++)
		if (x[j] != "0" && x[j] != "1") {
			z[j] = x[j];
			x[j][0] = 'a';
		}
	solvability();
	return 0;
}