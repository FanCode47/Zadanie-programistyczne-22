#include <iostream>
	#include <locale>
	#include <fstream>
	#include <ctime>
	#include <chrono>
	using namespace std;
	// Funkcja do poprawnego wyświetalnia polskich symboli
	void initLocal(){
		setlocale(LC_ALL, "pol");
		system("chcp 65001 > nul");}
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
	}
	void base2(bool** Tab, int row, int col, ofstream& MyFile){
		// Obliczanie znaków 'plus'
		int plus = 0;
		for (int r = 1; r < row - 1; r++)
		{for (int c = 1; c < col - 1; c++) {
				if(Tab[r][c] == 1 &&
				Tab[r-1][c] == 1 && Tab[r+1][c] == 1 &&
				Tab[r][c-1] == 1 && Tab[r][c+1] == 1){
					if(Tab[r-1][c-1] == 1 || Tab[r-1][c+1] == 1 ||
					Tab[r+1][c-1] == 1 || Tab[r+1][c+1] == 1){
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
	}
	void base3(bool** Tab, int row, int col, ofstream& MyFile){
		// Obliczanie znaków 'plus'
		int plus = 0;
		for (int r = 1; r < row - 1; r++)
		{
			for (int c = 1; c < col - 1; c++)
			{
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
				(r >= row - 2 || Tab[r + 2][c] == 0))
				{plus++;}
			}
		}
	}
	int main() {
		srand(time(NULL));
		// Pobieranie znacznika czasu dla bieżącej daty i godziny
		time_t timestamp;
		time(&timestamp);
		// Tworzenie i otwieranie pliku tekstowego
		ofstream MyFile("Log.txt", ios::app);
		MyFile << endl << ctime(&timestamp) << endl;
		initLocal();
		// Wymiary tablicy
		int row, col;
		cout << "Podaj liczbę wierszy: ";
		cin >> row;
		cout << "Podaj liczbę kolumn: ";
		cin >> col;
		// Ograniczenia
		if (row < 3 || col < 3)
		{   MyFile << "Aby wykryć kształt plusa, liczba wierszy i kolumn musi wynosić co najmniej 3!" << endl;
			cout << "Aby wykryć kształt plusa, liczba wierszy i kolumn musi wynosić co najmniej 3!" << endl;
			MyFile.close();
			return 0;}
		// Inicjalizacja dynamicznej tablicy dwuwymiarowej
		bool** Tab = new bool*[row];
		for (int i = 0; i < row; i++) {Tab[i] = new bool[col];}
		// Wypełnienie tablicy
		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
			{Tab[r][c] = rand() % 2;}
		}
		// Wyświetlanie wejścia
		MyFile << "Liczba elementów w tablicy:" << row * col << endl;
		cout << "Liczba elementów w tablicy:" << row * col << endl;
		// Wyznaczanie liczby powtórzeń
		int lp = 100000000/ (row * col);
		// Wywołanie funkcji 1
		MyFile << endl << "1 algorytm" << endl;
		cout << endl << "1 algorytm" << endl;
		auto start1 = chrono::high_resolution_clock::now();
		for (int i = 0; i < lp; ++i){
			base1(Tab, row, col, MyFile);}
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed1 = 1.0*(end1 - start1) / lp;
		MyFile << "Czas wykonania: " << elapsed1.count() << " ms" << endl;
		cout << "Czas wykonania: " << elapsed1.count() << " ms" << endl;
		// Wywołanie funkcji 2
		MyFile << endl << "2 algorytm" << endl;
		cout << endl << "2 algorytm" << endl;
		auto start2 = chrono::high_resolution_clock::now();
		for (int i = 0; i < lp; ++i){
			base2(Tab, row, col, MyFile);}
		auto end2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed2 = 1.0*(end2 - start2) / lp;
		MyFile << "Czas wykonania: " << elapsed2.count() << " ms" << endl;
		cout << "Czas wykonania: " << elapsed2.count() << " ms" << endl;
		// Wywołanie funkcji 3
		MyFile << endl << "3 algorytm" << endl;
		cout << endl << "3 algorytm" << endl;
		auto start3 = chrono::high_resolution_clock::now();
		for (int i = 0; i < lp; ++i){
			base3(Tab, row, col, MyFile);}
		auto end3 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> elapsed3 = 1.0*(end3 - start3) / lp;
		MyFile << "Czas wykonania: " << elapsed3.count() << " ms" << endl;
		cout << "Czas wykonania: " << elapsed3.count() << " ms" << endl;
		// Uwolnienie pamięci
		for (int i = 0; i < row; i++) {delete[] Tab[i];}
		delete[] Tab;
		// Zamykanie pliku
		MyFile.close();
		return 0;
	}
