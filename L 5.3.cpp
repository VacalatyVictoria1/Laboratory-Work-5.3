
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
/* 
Файл состоит из k компонентов структуры, где каждая компонента
содержит две матрицы: первая размерность m x n, вторая
размерности m x l. Получить произведение соответствующих матриц
и записать их во второй файл. Вывести на экран содержимое первого
и второго файлов.
*/
using namespace std;

int const M = 4;
int const N = 3;
int const L = 4;

struct Arrays
{
	int arr1[M][N];
	int arr2[N][L];
};

struct Array
{
	int arr[M][L];
};

void Multiply(Arrays* object, Array* res, int k)
{
	for (size_t t = 0; t < k; t++)
	{
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < L; j++)
			{
				res[t].arr[i][j] = 0;
				for (size_t l = 0; l < N; l++)
				{
					res[t].arr[i][j] += object[t].arr1[i][l] * object[t].arr2[l][j];
				}
			}
		}
	}
}

void Write_To_File_Result(ofstream& out2, Array* res, int k)
{
	for (int m = 0; m < k; m++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < L; j++)
			{
				out2 << "\t" << res[m].arr[i][j];
			}
			out2 << "\n";
		}
		out2 << "__________________________________________________\n";
	}
}

void Read_Array(ifstream& fin, Arrays* object, int k)
{
	for (size_t i = 0; i < k; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			for (size_t m = 0; m < N; m++)
			{
				fin >> object[i].arr1[j][m];
			}
		}

		for (int n = 0; n < N; n++)
		{
			for (int j = 0; j < L; j++)
			{
				fin >> object[i].arr2[n][j];
			}
		}
	}
}

void Print_Console_file1(Arrays* object, int k)
{
	for (int m = 0; m < k; m++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << "\t" << object[m].arr1[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < L; j++)
			{
				cout << "\t" << object[m].arr2[i][j];
			}
			cout << "\n";
		}
		cout << "__________________________________________________\n";
	}
}

void Print_Console_file2(Array* res, int k)
{
	for (int m = 0; m < k; m++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < L; j++)
			{
				cout << "\t" << res[m].arr[i][j];
			}
			cout << "\n";
		}
		cout << "__________________________________________________\n";
	}
}

int main()
{
	srand(time(NULL));
	ofstream out, out2;
	ifstream fin;
	int k = 3;

	fin.open("Текст.txt");
	out2.open("Текст1.txt");

	Arrays* object = new Arrays[k];
	Array* res = new Array[k];

	if (!fin.is_open())
		cout << "Error!" << endl;
	else
	{
		Read_Array(fin, object, k);
	}
	fin.close();
	cout << "Data from the File 1" << endl << endl;
	Print_Console_file1(object, k);

	;	if (!out2.is_open())
		cout << "Error!" << endl;
	else
	{
		Multiply(object, res, k);
		Write_To_File_Result(out2, res, k);
		cout << "File writing was successful" << endl;
		cout << "Data from the File 2" << endl << endl;
		Print_Console_file2(res, k);
	}
	out2.close();
	system("Pause");
	return 0;
}