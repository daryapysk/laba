#include "m1.h"
#include <iostream>
#include <fstream>
#include <sstream
using namespace std;


    MATRITSA::MATRITSA()
{ 
	//Конструктор по умолчанию, который устанавливает начальное положение объекта. Не принимает параметров 
        //str - строки
        //stlb - столбцы    
    str = stlb = 0;
    M = nullptr; 
}

MATRITSA::MATRITSA(int str_p, int stlb_p)
{
	//Конструктор принимает количество строк и столбцов матрицы и заполняет их случайными числами в диапазоне от -50 до 50
	
	str = str_p;
	stlb = stlb_p;

	M = new int* [str];
	for (int i = 0; i < str; i++)
		M[i] = new int[stlb];

	for (int i = 0; i < str; i++)
		for (int k = 0; k < stlb; k++)
			M[i][k] = rand() % 100 - 50;

	
}

MATRITSA::MATRITSA(const MATRITSA& _M)
{
	//Конструктор копирования создаёт новый объект и копирует в него другой, избегая проблем с памятью
        //_M - ссылка на второй объект копирования
	
	str = _M.str;
	stlb = _M.stlb;

	M = new int* [str];
	for (int i = 0; i < str; i++)
		M[i] = new int[stlb];

	for (int i = 0; i < str; i++)
		for (int k = 0; k < stlb; k++)
			M[i][k] = _M.M[i][k];

	
}

MATRITSA::~MATRITSA()
{
	//Деструктор освобождает память, выделенную для матрицы. Не принимает параметров
	if (str > 0)
	{
		for (int i = 0; i < str; i++)
		{
			delete[]M[i];
		}
	}

	if (stlb > 0)
	{
		delete[]M;
	}

}
    
bool MATRITSA::operator==(MATRITSA& _M)
{	
		//Перегрузка оператора сравнения осуществляется поэлементный сравнением матриц (соответствующих индексов)
		//_M - ссылка на вторую матрицу в сравнении на равенство
		//return возвращает true, если матрицы равны и false в ином случае
	
	if (this->str != _M.stroki() || this->stlb != _M.stolbtsy())
	{
		return false;
	}

	for (int i = 0; i < this->str; i++)
	{
		for (int k = 0; k < this->stlb; k++)
		{
			if (this->M[i][k] != _M.M[i][k])
			{
				return false;
			}
		}
	}

	return true;
}

ostream& operator<<(ostream& out, const MATRITSA& matr)
{

		//Перегрузка потокового оператора для вывода матрицы в консоль
		//out - ссылка на объект типа ostream, который выводится на экран
		//MATRITSA - матрица, которая выводится на экран
	        //return объект типа ostream, который выводится на экран
	
	cout << "-----------\n";
	for (int i = 0; i < matr.str; i++)
	{
		for (int k = 0; k < matr.stlb; k++)
			out << matr.M[i][k] << "\t";

		out << endl << endl;
	}

	return out;
}

istream& operator>>(istream& in, MATRITSA& matr)
{

		//Перегрузка потокового оператора для ввода матрицы вручную
		//in - объект типа istream, который принимает в себя значения, считываемые из клавиатуры при вводе в консоли
		//MATRITSA - матрица, элементы которой вводятся
		//return объект типа istream, который заполняет матрицу вводёнными числами
	
	cout << "Fill in the matrix: \n";
	for (int i = 0; i < matr.str; i++) {
		for (int k = 0; k < matr.stlb; k++)
			in >> matr.M[i][k];
	}
	return in;
}

// отличие префиксного инкремена(декремента) от постфиксного заключается в том, что префиксный инкремент(декремент) увеличивает(уменьшает) значение операнда на 1, после его возвращает,
// а постфиксный инкремент(декремент) возвращает значение операнда, после увеличивает(уменьшает) его на 1

void MATRITSA::incPr()
{
	//Префиксный инкремент увеличивает каждый элемент матрицы на единицу
	for (int i = 0; i < str; i++)
	{
		for (int k = 0; k < stlb; k++)
		{
			++M[i][k];
		}

	}
}


void MATRITSA::incPo()
{
	//Постфиксный инкремент увеличивает каждый элемент матрицы на единицу
	for (int i = 0; i < str; i++)
	{
		for (int k = 0; k < stlb; k++)
		{
			M[i][k]++;
		}

	}
}

void MATRITSA::dicPr()
{
	//Префиксный декремент уменьшает каждый элемент матрицы на единицу
	for (int i = 0; i < str; i++)
	{
		for (int k = 0; k < stlb; k++)
		{
			--M[i][k];
		}

	}
}


void MATRITSA::dicPo()
{
   //Постфиксный декремент уменьшает каждый элемент матрицы на единицу
	for (int i = 0; i < str; i++)
	{
		for (int k = 0; k < stlb; k++)
		{
			M[i][k]--;
		}

	}
}


void MATRITSA::create()
{ 
	//создание матрицы с заданием параметров пользователем
	cout << "Enter coloms: " << endl;
	cin >> stlb;
	cout << "Enter lines: " << endl;
	cin >> str;
	cout << "col= " << stlb << " lines= " << str << endl;
	for (int i = 0; i < str; i++)
	{
		M[i] = new int[stlb];
		for (int k = 0; k < stlb; k++)
		{
			M[i][k] = rand() % 10;
		}
	}
}

void MATRITSA::print()
{
	// вывод матрицы
	for (int i = 0; i < str; i++)
	{
		for (int k = 0; k < stlb; k++)
		{
			cout << M[i][k] << "\t";
		}
		cout << endl;
	}
}

void MATRITSA::resize(int nstlb, int nstr)
{
	// изменение размера матрицы
	//nstlb - новое число столбцов
	//nstr - новое число строк
	int** Mn = new int* [nstr];
	for (int i = 0; i < nstr; i++)
		Mn[i] = new int[nstlb];

	if (nstlb < stlb || nstr < str)
	{
		for (int i = 0; i < nstr; i++)
		{
			for (int k = 0; k < nstlb; k++)
			{
				Mn[i][k] = M[i][k];
			}
		}

	}
	else
	{
		for (int i = 0; i < nstr; i++)
		{
			if (i < str)
			{
				for (int k = 0; k < nstlb; k++)
				{
					if (k < stlb)
					{
						Mn[i][k] = M[i][k];
					}
					else Mn[i][k] = rand() % 10;
				}
			}
			else
				for (int k = 0; k < nstlb; k++)
				{
					Mn[i][k] = rand() % 10;
				}
		}

	}

	for (int i = 0; i < nstr; i++)
	{
		for (int k = 0; k < nstlb; k++)
		{
			cout << Mn[i][k] << "\t";
		}
		cout << endl;
	}
	this->M = Mn;
	this->stlb = nstlb;
	this->str = nstr;
	delete[] Mn;
}

MATRITSA MATRITSA::subMATRITSA(unsigned int str, unsigned int stlb)
{
	        // для выделения подматрицы
		// Новая матрицы получается путём "обрезания" данной. Элементы и индексы сохраняются, если они соответсвуют новым заданным размерам
		//return объект матрицы, которая является подматрицей исходной матрицы
	
	if (str > this->str || stlb > this->stlb || str <= 0 || stlb <= 0)
		throw "Index out of bounds!";

	MATRITSA newMATRITSA(str, stlb);

	for (int i = 0; i < str; i++)
		for (int j = 0; j < stlb; j++)
			newMATRITSA[i][j] = M[i][j];

	return newMATRITSA;
}


void MATRITSA::transpon(const MATRITSA& _M)
{
	//транспонировка матрицы
	int ctlb = _M.stlb;
	int str = _M.str;
	int** Mtr = new int* [str];
	for (int i = 0; i < stlb; i++)
		Mtr[i] = new int[stlb];

	for (int i = 0; i < str; i++)
	{
		for (int k = 0; k < stlb; k++)
		{
			Mtr[i][k] = _M.M[k][i];
		}
	}

	for (int i = 0; i < str; i++)
	{
		for (int k = 0; k < stlb; k++)
		{
			cout << Mtr[i][k] << "\t";
		}
		cout << endl;
	}
}

bool squareT(const MATRITSA& matr)
{
	
		// функция определяет, является ли матрица квадратной, путём сравнения количества строк и столбцов
		
	if (matr.stlb == matr.str)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool diagonalT(const MATRITSA& matr, bool square)
{
	//  функция определяет, является ли матрица диагональной, путём сравнения количества нулей в матрице
	// матрица называется диагональной, если она квадратная и все её элементы, кроме главной диагонали, равны нулю
		
	if (!square)
	{
		return false;
	}
	else
	{
		int zeros = 0;
		for (int i = 0; i < matr.str; i++)
		{
			for (int k = 0; k < matr.stlb; k++)
			{
				if (i == k)
				{
					continue;
				}

				if (matr.M[i][k] == 0)
				{
					zeros++;
				}
			}
		}

		if (zeros == matr.str * matr.stlb - matr.stlb)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool identityT(const MATRITSA& matr, bool diagonal)
{
	
		// функция определяет, является ли матрица единичной, путём сравнения единиц в диагональной матрице
		// матрица называется единичной, если она диагональная и все её элементы на главной диагонали равны единице
		
	if (diagonal)
	{
		int ones = 0;
		int k = 0;
		for (int i = 0; i < matr.str; i++)
		{
			if (matr.M[i][k] == 1)
			{
				ones++;
			}
			k++;
		}

		if (ones == matr.stlb)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool nullT(const MATRITSA& matr)
{

		// функция определяет, является ли матрица нулевой, путём сравнения количества нулей в матрице
		//матрица называется нулевой, если все её равны нулю
		
	for (int i = 0; i < matr.str; i++)
	{
		for (int k = 0; k < matr.stlb; k++)
		{
			if (matr.M[i][k] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

bool symmetricT(const MATRITSA& matr, bool square)
{
	
		// функция определяет, является ли матрица симметричной, путём сравнения елементов с обратными индексами
		// матрица называется симметричной, если транспанированная матрица равна исходной
		
	if (square)
	{
		for (int i = 0; i < matr.str; i++)
		{
			for (int j = 0; j < matr.stlb; j++)
			{
				if (i == j)
				{
					continue;
				}

				if (matr.M[j][i] != matr.M[i][j])
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool upTriangleT(const MATRITSA& matr, bool square)
{
	// функция определяет, является ли матрица верхней треугольной, путём сравнения елементов выше главой диагонали с нулём
	//матрица называется верхней треугольной, если её элементы ниже главной диагонали равны нулю
		
	if (square)
	{
		for (int i = 0; i < matr.str; i++)
		{
			for (int j = 0; j < matr.stlb; j++)
			{
				if (i > j&& matr.M[i][j] != 0)
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool downTriangleT(const MATRITSA& matr, bool square)
{
	//функция определяет, является ли матрица нижней треугольной, путём сравнения елементов ниже главой диагонали с нулём
	// матрица называется нижней треугольной, если её элементы выше главной диагонали равны нулю
		
	if (square)
	{
		for (int i = 0; i < matr.str; i++)
		{
			for (int j = 0; j < matr.stlb; j++)
			{
				if (i < j && matr.M[i][j] != 0)
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

string MATRITSA::getType(const MATRITSA& matr)
{
	
	string result = "";
	bool square = squareT(matr);
	bool diagonal = diagonalT(matr, square);
	bool identity = identityT(matr, diagonal);
	bool nullM = nullT(matr);
	bool symmetricM = symmetricT(matr, square);
	bool upTriangle = upTriangleT(matr, square);
	bool downTriangle = downTriangleT(matr, square);

	if (downTriangle && !nullM)
	{
		result += "Down Triangle ";
	}
	else if (upTriangle && !nullM)
	{
		result += "UpperTriangle ";
	}

	if (symmetricM && !diagonal)
	{
		result += "Symmetric ";
	}

	if (identity)
	{
		result += "Identity ";
	}

	if (nullM)
	{
		result = "Null ";
	}

	if (diagonal && !nullM && !identity)
	{
		result += "Diagonal ";
	}

	if (square && !diagonal && !identity && !symmetricM && !downTriangle && !upTriangle)
	{
		result += "Square ";
	}

	if (result == "")
	{
		result = "None";
	}

	return "Matrix type is " + result + "\n";
}


    void Matrix::dowland_from_file()
    {
        //Создаем файловый поток и связываем его с файлом
        ifstream in("input.txt");
        if (in.is_open())

        {
            //Вначале посчитаем сколько чисел в файле
            int count = 0;
            int temp;

            while (!in.eof())
            {
                in >> temp;
                count++;// увеличиваем счетчик числа чисел
            }
		
            in.seekg(0, ios::beg);
            in.clear();

            //Число пробелов в первой строчке вначале равно 0
            int count_space = 0;
            char symbol;
            while (!in.eof())
            {
                in.get(symbol);//считали текущий символ
                if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
                if (symbol == '\n') break;
            }

            in.seekg(0, ios::beg);
            in.clear();

            int m = count / (count_space + 1);//число строк
            int n = count_space + 1;//число столбцов на единицу больше числа пробелов
		
	    int **x;
            x = new int*[m];
	    for (int i = 0; i<m; i++)
			x[i] = new int[n];	
	

            //Считаем матрицу из файла
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    in >> x[i][j];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << x[i][j] << "\t";
                cout << "\n";
            }

            for (int i = 0; i < m; i++) 
		    delete[] x[i];
            delete[] x;

            in.close();
        }
        else
        {
          
            cout << "file not found";
        }

        system("pause");

    }

