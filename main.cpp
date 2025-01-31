#include <iostream>
	#include <locale>
	#include <fstream>
	#include <ctime>

	using namespace std;
	// Funkcja do poprawnego wyświetalnia polskich symboli
	void initLocal(){
		setlocale(LC_ALL, "pol");
		system("chcp 65001 > nul");
	}
	// Funkcja z główną częścią kodu
	void base1(bool** Tab, int row, int col, ofstream& MyFile) {
		// Obliczanie znaków 'plus'
		int plus = 0;
		for (int r = 1; r < row - 1; r++) {
			for (int c = 1; c < col - 1; c++) {
				if (Tab[r][c] == 1 &&
				Tab[r - 1][c] == 1 &&
				Tab[r + 1][c] == 1 &&
				Tab[r][c - 1] == 1 &&
				Tab[r][c + 1] == 1) {
					if (Tab[r - 1][c - 1] == 0 &&
					Tab[r - 1][c + 1] == 0 &&
					Tab[r + 1][c - 1] == 0 &&
					Tab[r + 1][c + 1] == 0) {
						if ((r >= 2 && Tab[r - 2][c] == 0) || r < 2) {
							if ((r + 2 < row && Tab[r + 2][c] == 0) || r + 2 >= row) {
								if ((c >= 2 && Tab[r][c - 2] == 0) || c < 2) {
									if ((c + 2 < col && Tab[r][c + 2] == 0) || c + 2 >= col) {
										plus++;
									}
								}
							}
						}
					}
				}
			}
		}
		// Wyświetlanie wyjścia
		cout << "Wyjście: " << plus << endl;
		MyFile << "Wyjście: " << plus << endl;
	}
	void base2(bool** Tab, int row, int col, ofstream& MyFile) {
		int plus = 0;
		for (int r = 1; r < row - 1; r++) {
			for (int c = 1; c < col - 1; c++) {
				if (Tab[r][c] == 1 &&
				Tab[r - 1][c] == 1 && Tab[r + 1][c] == 1 &&
				Tab[r][c - 1] == 1 && Tab[r][c + 1] == 1) {
					if (Tab[r - 1][c - 1] == 1 || Tab[r - 1][c + 1] == 1 ||
					Tab[r + 1][c - 1] == 1 || Tab[r + 1][c + 1] == 1) {
						continue;
					}
					if ((r - 2 >= 0 && Tab[r - 2][c] == 1) ||
					(r + 2 < row && Tab[r + 2][c] == 1)) {
						continue;
					}
					if ((c - 2 >= 0 && Tab[r][c - 2] == 1) ||
					(c + 2 < col && Tab[r][c + 2] == 1)) {
						continue;
					}
					plus++;
				}
			}
		}
		cout << "Wyjście: " << plus << endl;
		MyFile << "Wyjście: " << plus << endl;
	}
	void base3(bool** Tab, int row, int col, ofstream& MyFile) {
		int plus = 0;
		for (int r = 1; r < row - 1; r++) {
			for (int c = 1; c < col - 1; c++) {
				if (Tab[r][c] == 1 &&
				Tab[r][c - 1] == 1 &&
				Tab[r][c + 1] == 1 &&
				Tab[r - 1][c] == 1 &&
				Tab[r + 1][c] == 1 &&
				Tab[r - 1][c - 1] == 0 &&
				Tab[r - 1][c + 1] == 0 &&
				Tab[r + 1][c - 1] == 0 &&
				Tab[r + 1][c + 1] == 0 &&
				(c < 2 || Tab[r][c - 2] == 0) &&
				(c >= col - 2 || Tab[r][c + 2] == 0) &&
				(r < 2 || Tab[r - 2][c] == 0) &&
				(r >= row - 2 || Tab[r + 2][c] == 0)) {
					plus++;
				}
			}
		}
		cout << "Wyjście: " << plus << endl;
		MyFile << "Wyjście: " << plus << endl;
	}
	int main() {
		srand(time(NULL));
		// Pobieranie znacznika czasu dla bieżącej daty i godziny
		time_t timestamp;
		time(&timestamp);
		ofstream MyFile("Log.txt", ios::app);
		MyFile << endl << ctime(&timestamp) << endl;
		initLocal();
		bool matrix1[3][3] = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
		bool matrix2[3][3] = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
		bool matrix3[3][3] = {{0, 1, 0}, {1, 1, 1}, {0, 1, 1}};
		bool matrix4[4][4] = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
		bool matrix5[4][4] = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};
		for (int j = 1; j <= 6; j++) {
			int row = 0, col = 0;
			bool** Tab = nullptr;
			// Wypełnienie tablicy
			switch (j) {
				case 1:
				row = 3; col = 3;
				Tab = new bool*[row];
				for (int i = 0; i < row; i++) Tab[i] = new bool[col];
				for (int r = 0; r < row; r++)
				for (int c = 0; c < col; c++)
				Tab[r][c] = matrix1[r][c];
				break;
				case 2:
				row = 3; col = 3;
				Tab = new bool*[row];
				for (int i = 0; i < row; i++) Tab[i] = new bool[col];
				for (int r = 0; r < row; r++)
				for (int c = 0; c < col; c++)
				Tab[r][c] = matrix2[r][c];
				break;
				case 3:
				row = 3; col = 3;
				Tab = new bool*[row];
				for (int i = 0; i < row; i++) Tab[i] = new bool[col];
				for (int r = 0; r < row; r++)
				for (int c = 0; c < col; c++)
				Tab[r][c] = matrix3[r][c];
				break;
				case 4:
				row = 4; col = 4;
				Tab = new bool*[row];
				for (int i = 0; i < row; i++) Tab[i] = new bool[col];
				for (int r = 0; r < row; r++)
				for (int c = 0; c < col; c++)
				Tab[r][c] = matrix4[r][c];
				break;
				case 5:
				row = 4; col = 4;
				Tab = new bool*[row];
				for (int i = 0; i < row; i++) Tab[i] = new bool[col];
				for (int r = 0; r < row; r++)
				for (int c = 0; c < col; c++)
				Tab[r][c] = matrix5[r][c];
				break;
				case 6:
				row = 2; col = 2;
				break;
			}
			// Ograniczenia
			if (row < 3 || col < 3) {
				MyFile << "Aby wykryć kształt plusa, liczba wierszy i kolumn musi wynosić co najmniej 3!" << endl;
				cout << "Aby wykryć kształt plusa, liczba wierszy i kolumn musi wynosić co najmniej 3!" << endl;
				MyFile.close();
				return 0;
			}

			// Wyświetlanie wejścia
			MyFile << "Wejście:" << endl;
			cout << "Wejście:" << endl;
			for (int r = 0; r < row; r++) {
				MyFile << "[ ";
				cout << "[ ";
				for (int c = 0; c < col; c++) {
					MyFile << Tab[r][c] << " ";
					cout << Tab[r][c] << " ";
				}
				MyFile << "]" << endl;
				cout << "]" << endl;
			}
			// Wywołanie funkcji 1
			base1(Tab, row, col, MyFile);
			// Wywołanie funkcji 2
			base2(Tab, row, col, MyFile);
			// Wywołanie funkcji 3
			base3(Tab, row, col, MyFile);
			// Uwolnienie pamięci
			for (int i = 0; i < row; i++) { delete[] Tab[i]; }
			delete[] Tab;
		}
		// Zamykanie pliku
		MyFile.close();
		return 0;
	}
