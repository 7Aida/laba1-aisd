#include "set.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	int col, d;
	int* a;
	cout << "Введите количество строк в первой матрице" << endl;
	cin >> n;
	a = new int[n];
	cout << "Введите элементы первой матрицы" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	se m1(a, n);

	cout << "Введите количество строк во второй матрице" << endl;
	cin >> m;
	a = new int[m];
	cout << "Введите элементы второй матрицы" << endl;

	for (int i = 0; i < m; i++)
	{

		cout << "a[" << i << "]=";
		cin >> a[i];
	}

	se m2(a, m);
	cout << "Исходные матрицы" << endl;
	cout << m1 << endl;
	cout << m2 << endl;
	do {
		cout << "Введите индекс  " << endl;
		cin >> col;
	} while (col >= n);
	cout << "Вывод числа по индексу  " << endl;
	cout << m1(col) << endl;
	cout << "Введите число " << endl;
	cout << "Результат вычитания числа из  матрицы" << endl;
	cin >> d;
	cout << m1 / d << endl;
	cout << "Результат добавления числа в матрицу" << endl;
	cout << m1 % d << endl;
	cout << "Результат сложения матриц" << endl;
	cout << m1 + m2 << endl;
	cout << "Результат вычитания  матриц" << endl;
	cout << m1 - m2 << endl;
	cout << "Результат пересечение матриц" << endl;
	cout << m1 * m2 << endl;
	system("pause");
	return 0;
}