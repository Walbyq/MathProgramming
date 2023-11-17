#include <iostream>
#include <iomanip>
#include <string>

/*

��������� �� �������� ��� �����, � �������:
- ���� ������������������;
- ���� � ������������� ����������� �������������.

��������� �� ��������� �� ������� � ������������� ������.

*/

//������
struct Cell {
	int cost; //�����
	int quantity; //���������� ������
	char mark; //���� (+ ��� -)
};

//���������
struct Producer {
	std::string name; //���
	int reserve; //������
	int reserve2; //������ ��� ������
	int potential; //���������
	bool pot; //�������� �� ���������
};

//�����������
struct Consumer {
	std::string name; //���
	int requirement; //�����������
	int requirement2; //������ ��� ������
	int potential; //���������
	bool pot; //�������� �� ���������
};

const int MAX = 10;
int m, n, k = 0, s = 0;
Cell x[MAX][MAX];
Producer a[MAX];
Consumer b[MAX];

//���������� ������
void input() {
	char ch;
	std::cout << "������� ����� �������: ";
	std::cin >> ch;

	switch(ch) {
	case '1': {
		m = 3, n = 4;

		//���������� �������
		int temp_cost[3][4] = {
			{2, 1, 3, 2},
			{2, 3, 3, 1},
			{3, 3, 2, 1}
		}; 
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].cost = temp_cost[i][j];

		//���������� ���������� ������
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].quantity = -1; //��������� ������ ��������� ��� -1

		//���������� �����������
		int temp_res[3] = {90, 70, 50};
		for (int i = 0; i < m; i++) {
			a[i].name = "A" + std::to_string(i + 1);
			a[i].reserve = temp_res[i];
			a[i].reserve2 = temp_res[i];
		}

		//���������� ������������
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

		//���������� �������
		int temp_cost[4][5] = {
			{7, 1, 4, 5, 2},
			{13, 4, 7, 6, 3},
			{3, 8, 0, 18, 12},
			{9, 5, 3, 4, 7}
		};
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].cost = temp_cost[i][j];

		//���������� ���������� ������
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].quantity = -1; //��������� ������ ��������� ��� -1

		//���������� �����������
		int temp_res[4] = {85, 112, 72, 120};
		for (int i = 0; i < m; i++) {
			a[i].name = "A" + std::to_string(i + 1);
			a[i].reserve = temp_res[i];
			a[i].reserve2 = temp_res[i];
		}

		//���������� ������������
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

		//���������� �������
		int temp_cost[4][5] = {
			{16, 30, 17, 10, 4},
			{30, 27, 26, 9, 23},
			{13, 4, 22, 3, 1},
			{3, 1, 5, 4, 24}
		};
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].cost = temp_cost[i][j];

		//���������� ���������� ������
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				x[i][j].quantity = -1; //��������� ������ ��������� ��� -1

		//���������� �����������
		int temp_res[4] = {4, 6, 10, 10};
		for (int i = 0; i < m; i++) {
			a[i].name = "A" + std::to_string(i + 1);
			a[i].reserve = temp_res[i];
			a[i].reserve2 = temp_res[i];
		}

		//���������� ������������
		int temp_req[5] = {7, 7, 7, 7, 2};
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

//����� ����� ������
int findSumRes() {
	int sum_res = 0;
	for (int i = 0; i < m; i++)
		sum_res += a[i].reserve;
	return sum_res;
}

//����� ����� �����������
int findSumReq() {
	int sum_req = 0;
	for (int j = 0; j < n; j++)
		sum_req += b[j].requirement;
	return sum_req;
}

//����� ������
void display() {

	//������� ������ ��� ������
	int sum_res = 0;
	for (int i = 0; i < m; i++)
		sum_res += a[i].reserve2;

	//������� ����������� ��� ������
	int sum_req = 0;
	for (int j = 0; j < n; j++)
		sum_req += b[j].requirement2;

	std::cout << std::endl;
	//����� ����������� ������������
	for (int j = 0; j < n; j++)
		std::cout << std::setw(14) << std::right << b[j].potential;
	std::cout << std::endl;

	//����� ���� ������������
	for (int j = 0; j < n; j++)
		std::cout << std::setw(14) << std::right << b[j].name;
	std::cout << std::endl;

	for (int i = 0; i < m; i++) {
		//����� ����������� �����������
		std::cout << std::setw(4) << std::left << a[i].potential;
		//����� ���� �����������
		std::cout << std::setw(2) << a[i].name;
		//����� �����
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(7) << std::right;
			if (x[i][j].quantity != -1)
				std::cout << x[i][j].quantity; //����� ���������� ������
			else
				std::cout << "  ";
			std::cout << std::setw(1) << "|" << std::setw(3) << std::left << x[i][j].cost; //����� ������
			if (x[i][j].mark == '+' || x[i][j].mark == '-')
				std::cout << "(" << x[i][j].mark << ")"; //����� ������
			else
				std::cout << "   ";
		}
		//����� �������
		std::cout << std::setw(7) << std::right << a[i].reserve2 << std::endl;
	}

	for (int j = 0; j < n; j++)
		std::cout << std::setw(14) << std::right << b[j].requirement2; //����� ������������
	std::cout << std::setw(13) << std::right << sum_res << "/" << sum_req; //����� ����� ������� � ������������

	//����� �������
	int f = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (x[i][j].quantity != -1)
				f += x[i][j].quantity * x[i][j].cost;
	std::cout << "\nf = " << f;
}

//������ ��������� ������� ���� ������� ������������ ������
void minTariff() {
	const int MAX_COST = 100;
	int step = 1;
	int counter = 0;
	while (1) {
		switch (step) {

		//��� 1: ������� ����������� �����
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

		//��� 2: ���������� � ��������� ������ ����������� ��������� ���������� ������
		case 2: {
			if (a[k].reserve < b[s].requirement)
				x[k][s].quantity = a[k].reserve;
			else if (b[s].requirement <= a[k].reserve)
				x[k][s].quantity = b[s].requirement;
			counter++;
			step++;
			break;
		}

		//��� 3: �������� ��� �������� �� ������� � ������������
		case 3: {
			a[k].reserve -= x[k][s].quantity;
			b[s].requirement -= x[k][s].quantity;
			step++;
			break;
		}

		//��� 4: ���� ������ � ������ ������ ����� 0 -> ��� 7
		case 4: {
			if (a[k].reserve == 0)
				step = 7;
			else
				step++;
			break;
		}

		//��� 5: ���� ����� ����������� ����� 0 -> ��� 9
		case 5: {
			if (findSumReq() == 0)
				step = 9;
			else
				step++;
			break;
		}

		//��� 6: � ������ ������ ���� ������� � ����������� ������� � -> ��� 2
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

		//��� 7: ���� ����� ������ ����� 0 -> ��� 10
		case 7: {
			if (findSumRes() == 0)
				step = 10;
			else
				step++;
			break;
		}

		//��� 8: � ������� ������ ���� ������ � ����������� ������� � -> ��� 2
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

		//��� 9: ����������� �������������
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
		//��� 10: ����������� �������������
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
	//��� 1: ���� ����������
	bool search_pots; //��������, ����� �� ������ ����������

	//�������� ����������
	for (int i = 0; i < m; i++) {
		a[i].potential = 0;
		a[i].pot = false;
	}
	for (int j = 0; j < n; j++) {
		b[j].potential = 0;
		b[j].pot = false;
	}

	//������� �� ��� ���, ���� �� �������� ��� ����������
	do {
		//������ ���������� ��� ���� �����, � ������� �������� ���� �� ���
		do {
			search_pots = false;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (x[i][j].quantity != -1) { //������� ������ �������� ������
						// ���� ����� u, ���� v
						if (a[i].pot == true && b[j].pot == false) {
							b[j].potential = x[i][j].cost - a[i].potential;
							b[j].pot = true;
							search_pots = true;
						}
						// ���� ����� v, ���� u
						else if (b[j].pot == true && a[i].pot == false) {
							a[i].potential = x[i][j].cost - b[j].potential;
							a[i].pot = true;
							search_pots = true;
						}
					}
		} while (search_pots);
		//���������, ���� �� ������, � ������� ���������� �� ���� �� �����������
		search_pots = false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (x[i][j].quantity != -1 && a[i].pot == false && b[j].pot == false) { //���� ����� �������,
					a[i].potential = 0;													//�� ��������� u[i], ������ 0
					a[i].pot = true;
					search_pots = true;
					break;
				}
			}
			if (search_pots)
				break;
		}
	} while (search_pots);

	//��� 2: ��������� ���� �� �������������
	bool optimality = true;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (x[i][j].quantity == -1 && (x[i][j].cost - (a[i].potential + b[j].potential) < 0))
				optimality = false;
	return optimality;
}

//�������� ��������� �����
void improvePlan() {
	//���� ���� �� ���������, �������� ���
	while (checkOptimality() == false) {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				x[i][j].mark = NULL;
			}
		//��� 1: ���� ���������� �������� �����������, �.�. ������ �������
		int min = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				//������� ������ ��������� ������
				if (x[i][j].quantity == -1 && (x[i][j].cost - (a[i].potential + b[j].potential) < min)) {
					min = x[i][j].cost - (a[i].potential + b[j].potential);
					k = i;
					s = j;
				}
		x[k][s].mark = '+';

		//��� 2: �������� ������
		bool all_marks_found = false; //��� ����� �������
		bool mark_found; //������ ��������� ����

		while (!all_marks_found) {
			mark_found = false;

			//����������� ������
			if (x[k][s].mark == '+') {
				for (int i = 0; i < m; i++) {
					if (x[i][s].quantity != -1 && i != k) {
						for (int j = 0; j < n; j++) {
							if (x[i][j].quantity != -1 && j != s) {
								k = i;
								x[k][s].mark = '-';
								mark_found = true;
								break;
							}
						}
						for (int j = 0; j < n; j++) {
							if (x[i][j].quantity == -1 && j != s && x[i][j].mark == '+') {
								k = i;
								x[k][s].mark = '-';
								s = j;
								all_marks_found = true;
								break;
							}
						}
						if (mark_found || all_marks_found)
							break;
					}
				}
			}

			//����������� �����
			else if (x[k][s].mark == '-') {
				for (int j = 0; j < n; j++) {
					if (x[k][j].quantity != -1 && j != s) {
						for (int i = 0; i < m; i++) {
							if (x[i][j].quantity != -1 && i != k) {
								s = j;
								x[k][s].mark = '+';
								mark_found = true;
								break;
							}
						}
						if (mark_found)
							break;
					}
				}
			}
		}
		display();
		x[k][s].quantity = 0;

		//��� 3: ����� ����� �� ������ "-" ���� �����, ��� ���������� ���������� ������
		const int MAX_QUANTITY = 10000;
		int a = MAX_QUANTITY;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (x[i][j].mark == '-' && x[i][j].quantity < a) {
					a = x[i][j].quantity;
					k = i;
					s = j;
				}

		//��� 4: ���������� ��������� ����� � ������� �� ������ "+" � �������� � ������� �� ������ "-"
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (x[i][j].mark == '+')
					x[i][j].quantity += a;
				else if (x[i][j].mark == '-') {
					x[i][j].quantity -= a;
				}

		x[k][s].quantity = -1;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	input();
	minTariff();
	improvePlan();
	display();
	std::cout << "\n���� ���������!\n";
	return 0;
}