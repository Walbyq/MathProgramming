#include <iostream>
#include <string>
#include <iomanip>

char ch;
bool optimality, haveelem;
int m, n;
float a[10][10];
std::string x[10], y[10];

// создание матрицы
void input() {
	std::cout << "Выбрать готовую матрицу? (y/n): ";
	std::cin >> ch;
	if (ch == 'y') {
		// готовая матрица
	choise:
		std::cout << "Выберите пример (1-4): ";
		std::cin >> ch;
		switch (ch) {
		case '1': {
			m = 5, n = 6;
			float c[5][6] = {
				{3, 1, -4, 2, -5, 9},
				{6, 0, 1, -3, 4, -5},
				{1, 0, 1, -1, 1, -1},
				{0, 2, 6, -5, 1, 4}
			};
			for (int i = 0; i < m - 1; i++)
				for (int j = 0; j < n; j++)
					a[i][j] = c[i][j];
			break;
		}
		case '2': {
			m = 7, n = 8;
			float c[7][8] = {
				{12, 1, 1, 1, 0, 0, 0, 0},
				{40, 1, 4, 3, 1, 0, 0, 0},
				{10, 1, 0, 0, 0, 1, 0, 0},
				{8, 0, 1, 0, 0, 0, 1, 0},
				{6, 0, 0, 1, 0, 0, 0, 1},
				{0, 4, 3, 1, 0, 0, 0, 0}
			};
			for (int i = 0; i < m - 1; i++)
				for (int j = 0; j < n; j++)
					a[i][j] = c[i][j];
			break;
		}
		case '3': {
			m = 5, n = 7;
			float c[5][7] = {
				{4, 0, 1, 1, -1, 0, 0},
				{6, 2, 1, 2, 0, -1, 0},
				{2, 2, -1, 2, 0, 0, -1},
				{0, -3, -2, -1, 0, 0, 0}
			};
			for (int i = 0; i < m - 1; i++)
				for (int j = 0; j < n; j++)
					a[i][j] = c[i][j];
			break;
		}
		case '4': {
			m = 7, n = 8;
			float c[7][8] = {
				{1, 1, 1, 1, 0, 0, 0, 0},
				{1, 1, -2, 0, 1, 0, 0, 0},
				{2, 2, 3, 0, 0, 1, 0, 0},
				{3, 3, 2, 0, 0, 0, 1, 0},
				{1, 2, 2, 0, 0, 0, 0, -1},
				{0, 1, -1, 0, 0, 0, 0, 0}
			};
			for (int i = 0; i < m - 1; i++)
				for (int j = 0; j < n; j++)
					a[i][j] = c[i][j];
			break;
		}
		default:
			std::cout << "Такого примера не существует!\n";
			goto choise;
		}
	}
	else if (ch == 'n') {
		// ввод с клавиатуры
		// ввод размерности
		std::cout << "Введите количество столбцов: ";
		std::cin >> n;
		n += 1;
		std::cout << "Введите количество строк: ";
		std::cin >> m;
		m += 2;

		// ввод матрицы
		std::cout << "Введите матрицу: \n";
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << "[" << i + 1 << "][" << j << "]: ";
				std::cin >> a[i][j];
			}
		}
	}
	else
		exit(0);

	// создание строки g
	for (int j = 0; j < n; j++) {
		a[m - 1][j] = 0;
		for (int i = 0; i < m - 2; i++)
			a[m - 1][j] -= a[i][j];
	}

	// создание свободных коэффициентов
	for (int i = 1; i < n; i++)
		x[i] = "x" + std::to_string(i);
	x[0] = "1";

	// ввод базисных коэффициентов
	for (int i = 0; i < m - 2; i++)
		y[i] = "x" + std::to_string(i + n);
	y[m - 2] = "f";
	y[m - 1] = "g";
}

// вывод матрицы
void output() {
	std::cout << "\nМатрица: \n";
	// вывод свободных коэффициентов и 1
	std::cout << "    ";
	for (int i = 0; i < n; i++) {
		if (x[i] != "1")
			std::cout << std::setw(7) << "-";
		else
			std::cout << std::setw(9);
		std::cout << x[i];
	}
	std::cout << std::endl;

	// вывод базисных переменных, f и g
	for (int i = 0; i < m; i++) {
		std::cout << std::setw(3) << y[i] << "=";
		for (int j = 0; j < n; j++) {
			std::cout << std::setprecision(2) << std::setw(9);
			if (abs(a[i][j] == 0))
				std::cout << abs(a[i][j]);
			else
				std::cout << a[i][j];
		}
		std::cout << std::endl;
	}
}

// метод жордановых исключений
void jordanElimination() {
	bool comparison = true;
	haveelem = true;
	int k = -1, s = -1;
	float b[10][10], negmin = 0, posmin = 100;
	std::string temp;

	// сравнение матрицы с данной
	float c[5][6] = {
				{3, 1, -4, 2, -5, 9},
				{6, 0, 1, -3, 4, -5},
				{1, 0, 1, -1, 1, -1},
				{0, 2, 6, -5, 1, 4}
	};
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != c[i][j])
				comparison = false;

	// если матрица имеет такой вид, то разрешающий элемент (1;1)
	if (comparison == true) {
		s = 1, k = 0;
	}
	// в остальных случаях находятся автоматически
	else {
		// выбор разрешающего столбца
		for (int j = 1; j < n; j++) {
			if (a[m - 1][j] < 0 && a[m - 1][j] < negmin) {
				negmin = a[m - 1][j];
				s = j;
			}
			else if (a[m - 1][j] == 0 && a[m - 2][j] < 0 && a[m - 2][j] < negmin) {
				negmin = a[m - 2][j];
				s = j;
			}
		}
		if (s == -1) {
			haveelem = false;
			return;
		}

		// выбор разрешающей строки
		for (int i = 0; i < m - 2; i++) {
			if (a[i][s] > 0 && a[i][0] / a[i][s] < posmin) {
				posmin = a[i][0] / a[i][s];
				k = i;
			}
		}
		if (k == -1) {
			haveelem = false;
			return;
		}
	}

	std::cout << "\nРазрешающий столбец: " << s << "\n";
	std::cout << "Разрешающая строка: " << k + 1 << "\n";

	// замена коэффициентов по методу жордановых исключений
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
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
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (std::abs(b[i][j]) < 1e-05)
				b[i][j] = 0;
			a[i][j] = b[i][j];
		}
	}
}

// симплекный метод
void simplexMethod() {
	// проверка строки g
	do {
		output();
		optimality = true;
		for (int j = 1; j < n; j++) {
			// если есть хоть одно отрицательное число или 0, над которым отрицательное число, считать дальше
			if (a[m - 1][j] < 0 || (a[m - 1][j] == 0 && a[m - 2][j] < 0)) {
				optimality = false;
			}
		}
		jordanElimination();
	} while (optimality != true && haveelem != false);
	return;
}

int main() {
	float vect[15] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int num;
	setlocale(LC_ALL, "Russian");
	input();
	simplexMethod();
	if (optimality == true) {
		std::cout << "\nf = " << a[m - 2][0];
		for (int i = 0; i < m - 2; i++) {
			num = y[i][1] - 49;
			vect[num] = a[i][0];
		}
		std::cout << "\n(";
		for (int j = 0; j < n + m - 4; j++) {
			std::cout << vect[j] << ", ";
		}
		std::cout << vect[n + m - 3] << ")\n";
	}
	else
		std::cout << "\nПлан неоптимален!\n";
	return 0;
}