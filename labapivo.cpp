
#include <iostream>
#include <fstream>
#include <cstringt.h>
#include<ctime>

using namespace std;
class matritza
{
private:
	int** mass;
	int M;
	int N;
	
public:	
	matritza()
	{
		N = M = 0;
	}
	matritza(int _M,int _N)
	{
		M = _M;
		N = _N;
		mass = new int* [M];
		for (int i = 0; i < M; i++)
		{
			mass[i] = new int[N];
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				mass[i][j] = 0;
			}
		}
	}
	matritza(const matritza& _mass)//создаётся новый объект под который веляется память
	{
		M = _mass.M;
		N = _mass.N;
		mass = (int**)new int* [M];
		for (int i = 0; i < M; i++)
		{
			mass[i] = (int*) new int[N];
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; i < N; j++)
			{
				mass[i][j] = _mass.mass[i][j];
			}
		}
	} 
		void Print(const char* Objname)
		{
			cout << "Matrix:" << Objname << endl;
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; i < N; j++)
				{
					cout << mass[i][j] << "\t";
					cout << endl;
				}
				cout << endl;
			}
		}

	
		matritza operator=(const matritza& _mass)
		{
			if (M > 0)
			{
				for (int i = 0; i < M; i++)
				{
					delete[] mass[i];
				}
			}
			if (N > 0)
			{
				delete[] mass;
			}
			M = _mass.M;
			N = _mass.N;
			mass = (int**)new int* [M];
			for (int i = 0; i < M; i++)
			{
				mass[i] = (int*)new int[N];
			}
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; i < N; j++)
				{
					mass[i][j] = _mass.mass[i][j];
				}
			}
			return *this;
		}
		~matritza()
		{
			if (N > 0)
			{
				for (int i = 0; i < M; i++)
				{
					delete mass[i];
				}
			}
		}
		


};
