#pragma once
#include <string>
using namespace std;

class MATRITSA {

public:
	MATRITSA();
	MATRITSA(int str, int stlb);
	MATRITSA(const MATRITSA& _M);
	~MATRITSA();
	MATRITSA operator == (const MATRITSA& _M);
	void incPr();
	void incPo();
	void dicPr();
	void dicPo();
	void create();
	void print();
	bool operator==(MATRITSA& _M);
	int* operator[](unsigned int index);
	void resize(int nstlb, int nstr);
	void loadFromFile(const string& filepath);
	MATRITSA subMATRITSA(unsigned int str, unsigned int stlb);
	string getType(const MATRITSA& matr);
	
	void transpon(const MATRITSA& _M);
	int stroki();
	int stolbtsy();
	friend bool squareT(const MATRITSA& matr);
	friend bool diagonalT(const MATRITSA& matr, bool square);
	friend bool identityT(const MATRITSA& matr, bool diagonal);
	friend bool nullT(const MATRITSA& matr);
	friend bool symmetricT(const MATRITSA& matr, bool square);
	friend bool upTriangleT(const MATRITSA& matr, bool square);
	friend bool downTriangleT(const MATRITSA& matr, bool square);
	friend ostream& operator << (ostream& out, const MATRITSA& matr);
	friend istream& operator >> (istream& in, MATRITSA& matr);
	

private:
	int str;
	int stlb;
	int** M;

};
 
	
