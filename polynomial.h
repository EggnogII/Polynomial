// Name: Imran Irfan
//Student ID: 910013902
//Email: imranbirfan@gmail.com or iirfan@sfsu.edu
//Compiler: Visual Studios 2013
#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 1000;

class polynomial{
	private:
	//data members go here
		vector<int> poly;
		int size;
	public:
	//constructors
		//default constructor
		polynomial(const int s);
		//initialization constructor
		
	//accessors
		//print polynomial
		void printPoly();
		//return degree function
		void degree();
		int deg();
		//return coefficient
		void coefficient(int pwr);
		//return position
		int rPos(int p);
	//mutators or changers
		//set polynomial
		void setPoly();
		//set a specific value to an position in the polynomial
		int sPos(int p, int v);
		//multiply polynomial by scalar
		void multiplyC();
		//change coefficient of a term
		void changeCoefficient(int c, int pwr);
		//add polynomial
		void addPoly(polynomial p2);
		
	
};

//overloaded operators
polynomial operator/(polynomial &p1, int divisor);
polynomial operator-(polynomial &p1, polynomial p2);
polynomial operator-(polynomial &p1);
ostream& operator<<(ostream& out, polynomial p1);

#endif