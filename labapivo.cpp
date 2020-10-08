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
		//_M ссылка на второй объект копирования
	
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
		//\_M ссылка на вторую матрицу в сравнении на равенство
		//\return возвращает true, если матрицы равны и false в ином случае
	
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
		//\return объект типа ostream, который выводится на экран
		//\param out ссылка на объект типа ostream, который выводится на экран
		//\param MATRITSA матрица, которая выводится на экран
	
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
		//\param in объект типа istream, который принимает в себя значения, считываемые из клавиатуры при вводе в консоли
		//\param MATRITSA матрица, элементы которой вводятся
		//\return объект типа istream, который заполняет матрицу вводёнными числами
	
	cout << "Fill in the matrix: \n";
	for (int i = 0; i < matr.str; i++) {
		for (int k = 0; k < matr.stlb; k++)
			in >> matr.M[i][k];
	}
	return in;
}
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

    void dowland_from_file()
    {
        //Создаем файловый поток и связываем его с файлом
        ifstream in("input.txt");
        if (in.is_open())

        {
            //Если открытие файла прошло успешно

            //Вначале посчитаем сколько чисел в файле
            int count = 0;// число чисел в файле
            int temp;//Временная переменная

            while (!in.eof())// пробегаем пока не встретим конец файла eof
            {
                in >> temp;//в пустоту считываем из файла числа
                count++;// увеличиваем счетчик числа чисел
            }

            //Число чисел посчитано, теперь нам нужно понять сколько
            //чисел в одной строке
            //Для этого посчитаем число пробелов до знака перевода на новую строку 

            //Вначале переведем каретку в потоке в начало файла
            in.seekg(0, ios::beg);
            in.clear();

            //Число пробелов в первой строчке вначале равно 0
            int count_space = 0;
            char symbol;
            while (!in.eof())//на всякий случай цикл ограничиваем концом файла
            {
                //теперь нам нужно считывать не числа, а посимвольно считывать данные
                in.get(symbol);//считали текущий символ
                if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
                if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
            }
            //cout << count_space << endl;

            //Опять переходим в потоке в начало файла
            in.seekg(0, ios::beg);
            in.clear();

            //Теперь мы знаем сколько чисел в файле и сколько пробелов в первой строке.
            //Теперь можем считать матрицу.

            int m = count / (count_space + 1);//число строк
            int n = count_space + 1;//число столбцов на единицу больше числа пробелов
            T** x;
            x = (T**) new T * [m];
            for (int i = 0; i < m; i++) x[i] = (T*) new T[n];

            //Считаем матрицу из файла
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    in >> x[i][j];

            //Выведем матрицу
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << x[i][j] << "\t";
                cout << "\n";
            }

            for (int i = 0; i < m; i++) delete[] x[i];
            delete[] x;

            in.close();//под конец закроем файла
        }
        else
        {
            //Если открытие файла прошло не успешно
            cout << "Файл не найден.";
        }

        system("pause");

    }

};

void main()
{
    // тест для класса MATRIX
    MATRIX<int> M(2, 3);
    M.Print("M");

    // Заполнить матрицу значеннями по формуле
    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            M.SetMij(i, j, i + j);

    M.Print("M");

    MATRIX<int> M2 = M; // вызов конструктора копирования
    M2.Print("M2");

    MATRIX<int> M3; // вызов оператора копирования - проверка
    M3 = M;
    M3.Print("M3");

    MATRIX<int> M4;
    M4 = M3 = M2 = M; // вызов оператора копирования в виде "цепочки"
    M4.Print("M4");
   
    M.dowland_from_file();
}
