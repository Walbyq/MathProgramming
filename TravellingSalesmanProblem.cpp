#include <iostream>
#include <iomanip>
#include <string>

/*

Программа не работает для задач:
- с несбалансированным планом;
- с ограниченными пропускными способностями.

Программа не проверена на задачах с невырожденным планом.

*/

//ячейка
struct Cell {
	int cost; //тариф
	int quantity; //количество товара
	char mark; //знак (+ или -)
};

//поставщик
struct Producer {
	std::string name; //имя
	int reserve; //запасы
	int reserve2; //запасы для вывода
	int potential; //потенциал
	bool pot; //проверка на потенциал
};

//потребитель
struct Consumer {
	std::string name; //имя
	int requirement; //потребности
	int requirement2; //запасы для вывода
	int potential; //потенциал
	bool pot; //проверка на потенциал
};

const int MAX = 10;
int m, n, k = 0, s = 0;
Cell x[MAX][MAX];
Producer a[MAX];
Consumer b[MAX];

//заполнение данных
void input() {
	char ch;
	std::cout << "Введите номер примера: ";
	std::cin >> ch;

	switch(ch) {
	case '1': {
		m = 3, n = 4;

		//заполнение тарифов
		int temp_cost[3][4] = {
			{2, 1, 3, 2},
			{2, 3, 3, 1},
			{3, 3, 2, 1}
		}; 
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].cost = temp_cost[i][j];

		//заполнение количества товара
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].quantity = -1; //свободную ячейку обозначим как -1

		//заполнение поставщиков
		int temp_res[3] = {90, 70, 50};
		for (int i = 0; i < m; i++) {
			a[i].name = "A" + std::to_string(i + 1);
			a[i].reserve = temp_res[i];
			a[i].reserve2 = temp_res[i];
		}

		//заполнение потребителей
		int temp_req[4] = {80, 60, 40, 30};
		for (int j = 0; j < n; j++) {
			b[j].name = "a" + std::to_string(j + 1);
			b[j].requirement = temp_req[j];
			b[j].requirement2 = temp_req[j];
		}
		break;
	}
	case '2': {
		m = 4, n = 5;

		//заполнение тарифов
		int temp_cost[4][5] = {
			{7, 1, 4, 5, 2},
			{13, 4, 7, 6, 3},
			{3, 8, 0, 18, 12},
			{9, 5, 3, 4, 7}
		};
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].cost = temp_cost[i][j];

		//заполнение количества товара
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].quantity = -1; //свободную ячейку обозначим как -1

		//заполнение поставщиков
		int temp_res[4] = {85, 112, 72, 120};
		for (int i = 0; i < m; i++) {
			a[i].name = "A" + std::to_string(i + 1);
			a[i].reserve = temp_res[i];
			a[i].reserve2 = temp_res[i];
		}

		//заполнение потребителей
		int temp_req[5] = {75, 125, 64, 65, 60};
		for (int j = 0; j < n; j++) {
			b[j].name = "a" + std::to_string(j + 1);
			b[j].requirement = temp_req[j];
			b[j].requirement2 = temp_req[j];
		}
		break;
	}
	case '3': {
		m = 4, n = 5;

		//заполнение тарифов
		int temp_cost[4][5] = {
			{16, 30, 17, 10, 4},
			{30, 27, 26, 9, 23},
			{13, 4, 22, 3, 1},
			{3, 1, 5, 4, 24}
		};
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].cost = temp_cost[i][j];

		//заполнение количества товара
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].quantity = -1; //свободную ячейку обозначим как -1

		//заполнение поставщиков
		int temp_res[4] = {4, 6, 10, 10};
		for (int i = 0; i < m; i++) {
			a[i].name = "A" + std::to_string(i + 1);
			a[i].reserve = temp_res[i];
			a[i].reserve2 = temp_res[i];
		}

		//заполнение потребителей
		int temp_req[5] = {7, 7, 7, 7, 2};
		for (int j = 0; j < n; j++) {
			b[j].name = "a" + std::to_string(j + 1);
			b[j].requirement = temp_req[j];
			b[j].requirement2 = temp_req[j];
		}
		break;
	}
	case '4': {
		m = 4, n = 5;

		//заполнение тарифов
		int temp_cost[4][5] = {
			{22, 24, 25, 23, 29},
			{1, 21, 10, 7, 19},
			{2, 26, 18, 30, 27},
			{22, 10, 29, 26, 23}
		};
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].cost = temp_cost[i][j];

		//заполнение количества товара
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].quantity = -1; //свободную ячейку обозначим как -1

		//заполнение поставщиков
		int temp_res[4] = {24, 14, 19, 17};
		for (int i = 0; i < m; i++) {
			a[i].name = "A" + std::to_string(i + 1);
			a[i].reserve = temp_res[i];
			a[i].reserve2 = temp_res[i];
		}

		//заполнение потребителей
		int temp_req[5] = {22, 9, 12, 13, 18};
		for (int j = 0; j < n; j++) {
			b[j].name = "a" + std::to_string(j + 1);
			b[j].requirement = temp_req[j];
			b[j].requirement2 = temp_req[j];
		}
		break;
	}
	default:
		break;
	}
}

//найти общие запасы
int findSumRes() {
	int sum_res = 0;
	for (int i = 0; i < m; i++)
		sum_res += a[i].reserve;
	return sum_res;
}

//найти общие потребности
int findSumReq() {
	int sum_req = 0;
	for (int j = 0; j < n; j++)
		sum_req += b[j].requirement;
	return sum_req;
}

//вывод данных
void display() {

	//считаем запасы для вывода
	int sum_res = 0;
	for (int i = 0; i < m; i++)
		sum_res += a[i].reserve2;

	//считаем потребности для вывода
	int sum_req = 0;
	for (int j = 0; j < n; j++)
		sum_req += b[j].requirement2;

	std::cout << std::endl;
	//вывод потенциалов потребителей
	for (int j = 0; j < n; j++)
		std::cout << std::setw(14) << std::right << b[j].potential;
	std::cout << std::endl;

	//вывод имен потребителей
	for (int j = 0; j < n; j++)
		std::cout << std::setw(14) << std::right << b[j].name;
	std::cout << std::endl;

	for (int i = 0; i < m; i++) {
		//вывод потенциалов поставщиков
		std::cout << std::setw(4) << std::left << a[i].potential;
		//вывод имен поставщиков
		std::cout << std::setw(2) << a[i].name;
		//вывод ячеек
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(7) << std::right;
			if (x[i][j].quantity != -1)
				std::cout << x[i][j].quantity; //вывод количества товара
			else
				std::cout << "  ";
			std::cout << std::setw(1) << "|" << std::setw(3) << std::left << x[i][j].cost; //вывод тарифа
			if (x[i][j].mark == '+' || x[i][j].mark == '-')
				std::cout << "(" << x[i][j].mark << ")"; //вывод знаков
			else
				std::cout << "   ";
		}
		//вывод запасов
		std::cout << std::setw(7) << std::right << a[i].reserve2 << std::endl;
	}

	for (int j = 0; j < n; j++)
		std::cout << std::setw(14) << std::right << b[j].requirement2; //вывод потребностей
	std::cout << std::setw(13) << std::right << sum_res << "/" << sum_req; //вывод общих запасов и потребностей

	//вывод решения
	int f = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (x[i][j].quantity != -1)
				f += x[i][j].quantity * x[i][j].cost;
	std::cout << "\nf = " << f;
}

//строим начальный опорный план методом минимального тарифа
void minTariff() {
	const int MAX_COST = 100;
	int step = 1;
	int counter = 0;
	while (1) {
		switch (step) {

		//шаг 1: находим минимальный тариф
		case 1: {
			int min_cost = MAX_COST;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (x[i][j].cost < min_cost) {
						min_cost = x[i][j].cost;
						k = i;
						s = j;
					}
			step++;
			break;
		}

		//шаг 2: записываем в найденную ячейку максимально возможное количество товара
		case 2: {
			if (a[k].reserve < b[s].requirement)
				x[k][s].quantity = a[k].reserve;
			else if (b[s].requirement <= a[k].reserve)
				x[k][s].quantity = b[s].requirement;
			counter++;
			step++;
			break;
		}

		//шаг 3: вычитаем это значение из запасов и потребностей
		case 3: {
			a[k].reserve -= x[k][s].quantity;
			b[s].requirement -= x[k][s].quantity;
			step++;
			break;
		}

		//шаг 4: если запасы в строке ячейки равны 0 -> шаг 7
		case 4: {
			if (a[k].reserve == 0)
				step = 7;
			else
				step++;
			break;
		}

		//шаг 5: если общие потребности равны 0 -> шаг 9
		case 5: {
			if (findSumReq() == 0)
				step = 9;
			else
				step++;
			break;
		}

		//шаг 6: в строке ячейки ищем столбец с минимальным тарифом и -> шаг 2
		case 6: {
			int min_cost = MAX_COST;
			for (int j = 0; j < n; j++)
				if (x[k][j].cost < min_cost && x[k][j].quantity == -1 && b[j].requirement != 0) {
					min_cost = x[k][j].cost;
					s = j;
				}
			step = 2;
			break;
		}

		//шаг 7: если общие запасы равны 0 -> шаг 10
		case 7: {
			if (findSumRes() == 0)
				step = 10;
			else
				step++;
			break;
		}

		//шаг 8: в столбце ячейки ищем строку с минимальным тарифом и -> шаг 2
		case 8: {
			int min_cost = MAX_COST;
			for (int i = 0; i < m; i++)
				if (x[i][s].cost < min_cost && x[i][s].quantity == -1 && a[i].reserve != 0) {
					min_cost = x[i][s].cost;
					k = i;
				}
			step = 2;
			break;
		}

		//шаг 9: исправление вырожденности
		case 9: {
			if (counter < m + n - 1) {
				int min_cost = MAX_COST;
				for (int j = 0; j < n; j++)
					if (x[k][j].cost < min_cost && x[k][j].quantity == -1 && b[j].requirement != 0) {
						min_cost = x[k][j].cost;
						s = j;
					}
				x[k][s].quantity = 0;
			}
			return;
		}
		//шаг 10: исправление вырожденности
		case 10: {
			if (counter < m + n - 1) {
				int min_cost = MAX_COST;
				for (int i = 0; i < m; i++)
					if (x[i][s].cost < min_cost && x[i][s].quantity == -1 && a[i].reserve != 0) {
						min_cost = x[i][s].cost;
						k = i;
					}
				x[k][s].quantity = 0;
			}
			return;
		}
		}
	}
}

bool checkOptimality() {
	//шаг 1: ищем потенциалы
	bool search_pots; //проверка, стоит ли искать потенциалы

	//обнуляем потенциалы
	for (int i = 0; i < m; i++) {
		a[i].potential = 0;
		a[i].pot = false;
	}
	for (int j = 0; j < n; j++) {
		b[j].potential = 0;
		b[j].pot = false;
	}

	//считаем до тех пор, пока не найдутся все потенциалы
	do {
		//вводим потенциалы для всех ячеек, у которых известен один из них
		do {
			search_pots = false;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (x[i][j].quantity != -1) { //обходим только базисные ячейки
						// если знаем u, ищем v
						if (a[i].pot == true && b[j].pot == false) {
							b[j].potential = x[i][j].cost - a[i].potential;
							b[j].pot = true;
							search_pots = true;
						}
						// если знаем v, ищем u
						else if (b[j].pot == true && a[i].pot == false) {
							a[i].potential = x[i][j].cost - b[j].potential;
							a[i].pot = true;
							search_pots = true;
						}
					}
		} while (search_pots);

		//проверяем, есть ли ячейки, у которых неизвестен ни один из потенциалов
		search_pots = false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (x[i][j].quantity != -1 && a[i].pot == false && b[j].pot == false) { //если такая найдена,
					a[i].potential = 0;													//то принимаем u[i], равным 0
					a[i].pot = true;
					search_pots = true;
					break;
				}
			}
			if (search_pots)
				break;
		}
	} while (search_pots);

	//шаг 2: проверяем план на оптимальность
	bool optimality = true;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (x[i][j].quantity == -1 && (x[i][j].cost - (a[i].potential + b[j].potential) < 0))
				optimality = false;
	return optimality;
}

//алгоритм улучшения плана
void improvePlan() {
	//пока план не оптимален, улучшаем его
	while (checkOptimality() == false) {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].mark = NULL;

		//шаг 1: ищем наименьшую разность потенциалов, т.е. начало контура
		int min = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (x[i][j].quantity == -1 && (x[i][j].cost - (a[i].potential + b[j].potential) < min)) {
					min = x[i][j].cost - (a[i].potential + b[j].potential);
					k = i;
					s = j;
				}
		x[k][s].mark = '+';

		//шаг 2: намечаем контур
		bool all_marks_found = false; //все знаки найдены
		bool mark_found; //найден следующий знак
		bool line_erased = true; //строка или столбец стерлись
		bool row[MAX], column[MAX];

		//все строки и столбцы изначально доступны
		for (int i = 0; i < m; i++)
			row[i] = true;
		for (int j = 0; j < n; j++)
			column[j] = true;

		//"метод тряпки"
		int counter = 0;
		int counter2 = 0;
		//стираем, пока стирается
		while (line_erased) {
			counter2++;
			line_erased = false;
			//стираем строки
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (row[i] && column[j] && (x[i][j].quantity != -1 || x[i][j].mark == '+')) {
						counter++;	
					}
				}
				if (counter < 2) {
					row[i] = false;
					if (counter == 1)
						line_erased = true;
				}
				counter = 0;
			}
			//стираем столбцы
			for (int j = 0; j < n; j++) {
				for (int i = 0; i < m; i++) {
					if (row[i] && column[j] && (x[i][j].quantity != -1 || x[i][j].mark == '+')) {
						counter++;
					}
				}
				if (counter < 2) {
					column[j] = false;
					if (counter == 1)
						line_erased = true;
				}
				counter = 0;
			}
		}

		//намечаем контур, пока все знаки не будут расставлены
		while (!all_marks_found) {
			mark_found = false;

			//расставляем минусы
			if (x[k][s].mark == '+') {
				for (int i = 0; i < m; i++) {
					if (row[i] && x[i][s].quantity != -1 && i != k) {
						for (int j = 0; j < n; j++) {
							if (column[j] && x[i][j].quantity != -1 && j != s) {
								k = i;
								x[k][s].mark = '-';
								mark_found = true;
								break;
							}
						}
						for (int j = 0; j < n; j++) {
							if (column[j] && x[i][j].quantity == -1 && j != s && x[i][j].mark == '+') {
								k = i;
								x[k][s].mark = '-';
								s = j;
								all_marks_found = true;
								break;
							}
						}
						if (mark_found || all_marks_found) break;
					}
				}
			}

			//расставляем плюсы
			else if (x[k][s].mark == '-') {
				for (int j = 0; j < n; j++) {
					if (column[j] && x[k][j].quantity != -1 && j != s) {
						for (int i = 0; i < m; i++) {
							if (row[i] && x[i][j].quantity != -1 && i != k) {
								s = j;
								x[k][s].mark = '+';
								mark_found = true;
								break;
							}
						}
						if (mark_found) break;
					}
				}
			}
		}
		display();
		x[k][s].quantity = 0;

		//шаг 3: среди ячеек со знаком "-" ищем такую, где наименьшее количество товара
		const int MAX_QUANTITY = 10000;
		int a = MAX_QUANTITY;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (x[i][j].mark == '-' && x[i][j].quantity < a) {
					a = x[i][j].quantity;
					k = i;
					s = j;
				}

		//шаг 4: прибавляем найденное число в клетках со знаком "+" и убавляем в клетках со знаком "-"
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (x[i][j].mark == '+')
					x[i][j].quantity += a;
				else if (x[i][j].mark == '-') 
					x[i][j].quantity -= a;

		x[k][s].quantity = -1;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	input();
	minTariff();
	improvePlan();
	display();
	std::cout << "\nПлан оптимален!\n";
	return 0;
}
