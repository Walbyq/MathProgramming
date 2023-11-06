#include <iostream>
#include <string>
#include <iomanip>

char ch;
bool optimality, haveelem;
int m, n;
float a[10][10];
std::string x[10], y[10];

// ñîçäàíèå ìàòðèöû
void input() {
	std::cout << "Âûáðàòü ãîòîâóþ ìàòðèöó? (y/n): ";
	std::cin >> ch;
	if (ch == 'y') {
		// ãîòîâàÿ ìàòðèöà
	choise:
		std::cout << "Âûáåðèòå ïðèìåð (1-4): ";
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
			std::cout << "Òàêîãî ïðèìåðà íå ñóùåñòâóåò!\n";
			goto choise;
		}
	}
	else if (ch == 'n') {
		// ââîä ñ êëàâèàòóðû
		// ââîä ðàçìåðíîñòè
		std::cout << "Ââåäèòå êîëè÷åñòâî ñòîëáöîâ: ";
		std::cin >> n;
		n += 1;
		std::cout << "Ââåäèòå êîëè÷åñòâî ñòðîê: ";
		std::cin >> m;
		m += 2;

		// ââîä ìàòðèöû
		std::cout << "Ââåäèòå ìàòðèöó: \n";
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << "[" << i + 1 << "][" << j << "]: ";
				std::cin >> a[i][j];
			}
		}
	}
	else
		exit(0);

	// ñîçäàíèå ñòðîêè g
	for (int j = 0; j < n; j++) {
		a[m - 1][j] = 0;
		for (int i = 0; i < m - 2; i++)
			a[m - 1][j] -= a[i][j];
	}

	// ñîçäàíèå ñâîáîäíûõ êîýôôèöèåíòîâ
	for (int i = 1; i < n; i++)
		x[i] = "x" + std::to_string(i);
	x[0] = "1";

	// ââîä áàçèñíûõ êîýôôèöèåíòîâ
	for (int i = 0; i < m - 2; i++)
		y[i] = "x" + std::to_string(i + n);
	y[m - 2] = "f";
	y[m - 1] = "g";
}

// âûâîä ìàòðèöû
void output() {
	std::cout << "\nÌàòðèöà: \n";
	// âûâîä ñâîáîäíûõ êîýôôèöèåíòîâ è 1
	std::cout << "    ";
	for (int i = 0; i < n; i++) {
		if (x[i] != "1")
			std::cout << std::setw(7) << "-";
		else
			std::cout << std::setw(9);
		std::cout << x[i];
	}
	std::cout << std::endl;

	// âûâîä áàçèñíûõ ïåðåìåííûõ, f è g
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

// ìåòîä æîðäàíîâûõ èñêëþ÷åíèé
void jordanElimination() {
	haveelem = true;
	int k = -1, s = -1;
	float b[10][10], negmin = 0, posmin = 100;
	std::string temp;

	// âûáîð ðàçðåøàþùåãî ñòîëáöà
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

	// âûáîð ðàçðåøàþùåé ñòðîêè
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

	std::cout << "\nÐàçðåøàþùèé ñòîëáåö: " << s << "\n";
	std::cout << "Ðàçðåøàþùàÿ ñòðîêà: " << k + 1 << "\n";

	// çàìåíà êîýôôèöèåíòîâ ïî ìåòîäó æîðäàíîâûõ èñêëþ÷åíèé
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == k && j == s) {
				b[k][s] = 1 / a[k][s]; // ðàçðåøàþùèé ýëåìåíò ñòàíîâèòñÿ 1, äåëåííîé íà ðàçðåøàþùèé ýëåìåíò
			}
			else if (i == k && j != s) {
				b[i][j] = a[i][j] / a[k][s]; // ýëåìåíòû ðàçðåøàþùåé k ñòðîêè äåëÿòñÿ íà ðàçðåøàþùèé ýëåìåíò
			}
			else if (i != k && j == s) {
				b[i][j] = -a[i][j] / a[k][s]; // ýëåìåíòû ðàçðåøàþùåãî s ñòîëáöà ìåíÿþò ñâîé çíàê íà ïðîòèâîïîëîæíûé è äåëÿòñÿ íà ðàçðåøàþùèé ýëåìåíò
			}
			else
				b[i][j] = (a[i][j] * a[k][s] - a[i][s] * a[k][j]) / a[k][s]; // âñå îñòàëüíûå ýëåìåíòû ñ÷èòàþòñÿ ïî ïðàâèëó ïðÿìîóãîëüíèêà è äåëÿòñÿ íà ðàçðåøàþùèé ýëåìåíò
		}
	}

	// ñìåíà çàâèñèìîãî è íåçàâèñèìîãî ïåðåìåííûõ
	temp = x[s];
	x[s] = y[k];
	y[k] = temp;

	// êîïèðîâàíèå ìàòðèöû b â ìàòðèöó a
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (std::abs(b[i][j]) < 1e-05)
				b[i][j] = 0;
			a[i][j] = b[i][j];
		}
	}
}

// ñèìïëåêíûé ìåòîä
void simplexMethod() {
	// ïðîâåðêà ñòðîêè g
	do {
		output();
		optimality = true;
		for (int j = 1; j < n; j++) {
			// åñëè åñòü õîòü îäíî îòðèöàòåëüíîå ÷èñëî èëè 0, íàä êîòîðûì îòðèöàòåëüíîå ÷èñëî, ñ÷èòàòü äàëüøå
			if (a[m - 1][j] < 0 || (a[m - 1][j] == 0 && a[m - 2][j] < 0)) {
				optimality = false;
			}
		}
		jordanElimination();
	} while (optimality != true && haveelem != false);
	return;
}

int main() {
	float vect[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int num;
	setlocale(LC_ALL, "Russian");
	input();
	simplexMethod();
	if (optimality == true) {
		std::cout << "\nf = " << a[m - 2][0];
		for (int i = 0; i < m - 2; i++) {
			num = y[i][1] - 48;
			vect[num] = a[i][0];
		}
		std::cout << "\n(";
		for (int j = 0; j < n + m - 4; j++) {
			std::cout << vect[j] << ", ";
		}
		std::cout << vect[n + m - 3] << ")\n";
	}
	else
		std::cout << "\nÏëàí íåîïòèìàëåí!\n";
	return 0;
}
