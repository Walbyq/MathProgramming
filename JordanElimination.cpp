#include <iostream>
#include <iomanip>
#include <string>

int i, j, m = 3, n = 4, k, s;
float a[10][10], b[10][10];
char ch;
std::string x[10], y[10], z[10], temp;

// ââîä ìàòðèöû
void input() {
	// ñîçäàíèå ïåðåìåííûõ x è y
	x[0] = "1";
	y[0] = "0";
	for (i = 1; i < 10; i++) {
		x[i] = "x" + std::to_string(i);
		y[i] = "0";
	}
	std::cout << "Âûáðàòü ãîòîâóþ ìàòðèöó? (y/n): ";
	std::cin >> ch;
	if (ch == 'y') {
		// ãîòîâàÿ ìàòðèöà
		float c[3][4];
		std::cout << "Âûáåðèòå ïðèìåð (1, 2, 3): ";
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
		// ââîä ñ êëàâèàòóðû
		std::cout << "Ââåäèòå êîëè÷åñòâî ñòðîê: ";
		std::cin >> m;
		std::cout << "Ââåäèòå êîëè÷åñòâî ñòîëáöîâ: ";
		std::cin >> n;
		n++;
		std::cout << "Ââåäèòå ìàòðèöó: \n";
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (j == 0)
					std::cout << i + 1 << " áàçèñíàÿ ïåðåìåííàÿ: ";
				else
					std::cout << "a[" << i + 1 << "][" << j << "]: ";
				std::cin >> a[i][j];
			}
		}
	}
}

// ìåòîä æîðäàíîâûõ èñêëþ÷åíèé
void jordanElimination() {
t:
	// âûáîð ðàçðåøàþùåãî ýëåìåíòà
	std::cout << "\nÂûáåðèòå ñòðîêó ðàçðåøàþùåãî ýëåìåíòà: ";
	std::cin >> k;
	k--;
	std::cout << "Âûáåðèòå ñòîëáåö ðàçðåøàþùåãî ýëåìåíòà: ";
	std::cin >> s;
	if ((k > m) || (s > n) || (k < 0) || (s < 0)) {
		std::cout << "\nÐàçðåøàþùèé ýëåìåíò çà ïðåäåëàìè ìàòðèöû.\n";
		goto t;
	}
	if (a[k][s] == 0) {
		std::cout << "\nÐàçðåøàþùèé ýëåìåíò íå ìîæåò áûòü íóëåâûì.\n";
		goto t;
	}
	std::cout << "Ðàçðåøàþùèé ýëåìåíò: " << a[k][s] << "\n";
	// çàìåíà êîýôôèöèåíòîâ ïî ìåòîäó æîðäàíîâûõ èñêëþ÷åíèé
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
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
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = b[i][j];
		}
	}
}

// âûâîä ìàòðèöû
void display() {
	std::cout << "\nÌàòðèöà: \n";
	// âûâîä çàâèñèìûõ ïåðåìåííûõ
	std::cout << "   ";
	for (j = 0; j < n; j++) {
		if (x[j] != "0" && x[j] != "1")
			std::cout << std::setw(7) << "-";
		else
			std::cout << std::setw(9);
		std::cout << x[j];
	}
	std::cout << std::endl;
	// âûâîä íåçàâèñèìûõ ïåðåìåííûõ è êîýôôèöèåíòîâ
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

// âûâîä ñèñòåìû
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

// ïðîâåðêà íà ðàçðåøèìîñòü
void solvability() {
	bool solv = false;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (x[j] != "0" && y[i] == "0" && a[i][0] != 0 && a[i][j] == 0) {
				solv = true;
			}
	if (solv == true) {
		std::cout << "\nÑèñòåìà íåñîâìåñòíà.\n";
	}
	else {
		std::cout << "\nÑèñòåìà ñîâìåñòíà:";
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
		std::cout << "Ïðîäîëæèòü? (y/n): ";
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
