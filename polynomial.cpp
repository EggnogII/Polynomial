// Name: Imran Irfan
//Student ID: 910013902
//Email: imranbirfan@gmail.com or iirfan@sfsu.edu
//Compiler: Visual Studios 2013
#include "polynomial.h"
polynomial::polynomial(const int s){
	size = s;
	poly.resize(s);
	poly.clear();
}

void polynomial::printPoly(){
	for (int j=size-1;j>=0;j--){
		cout << poly[j] << "x^" << j << ' ';
	}
	cout << endl;
}

void polynomial::degree(){
	cout << "Degree of " << size-1 << endl;
}

int polynomial::deg(){
	return size-1;
}

void polynomial::coefficient(int pwr){
	
	cout << "Enter degree for coefficient: ";
	cin >> pwr;
	if (pwr > size-1){
		cout << "Invalid entry" << endl;
		}
	else {
	cout << "Coefficient of x^" << pwr << " is " << poly[pwr] << endl;
	}
}

int polynomial::rPos(int p){
	return poly[p];
}
void polynomial::setPoly(){
	int x;
	int temp;
	cout << "Terms?: ";
	cin >> x;
	poly.resize(x);
	size = x;
	cout << endl;
	
	for (int i=x-1;i>=0;i--){
		cout << "Enter coefficient for the " << i << " degree: ";
		cin >> temp;
		poly[i] = temp;
	}
	cout << endl;
}

int polynomial::sPos(int p,int v){
	poly[p] = v;
	return poly[p];
}

void polynomial::multiplyC(){
	int c;
	cout << "Enter scalar to multiply polynomial by: ";
	cin >> c;
	cout << endl;
	for (int i=size-1;i>=0;i--){
		poly[i] = c*poly[i];
		}
}

void polynomial::changeCoefficient(int c, int pwr){
	cout << "Enter degree for coefficient to change: ";
	cin >> pwr;
	if (pwr > size-1){
		cout << "Invalid" << endl;
		}
	else {
		cout << "Change coefficient to: ";
		cin >> c;
		poly[pwr] = c;
		}
}

void polynomial::addPoly(polynomial p2){
	for (int i=size;i>=0;i--){
		for (int j=p2.size;j>=0;j--){
			if (i == j){
				poly[i] = poly[i] + p2.poly[j];
			}
		}
	}
}

//overloaded operators
polynomial operator/(polynomial &p1, int divisor){
	int x;
	for (int j=p1.deg();j>=0;j--){
		x = p1.rPos(j);
		x = x / divisor;
		p1.sPos(j, x);
	}
	return p1;
}

polynomial operator-(polynomial &p1, polynomial p2){
	int x;
	int y;
	int z;
	for (int i=p1.deg();i>=0;i--){
		for (int j=p2.deg();j>=0;j--){
			if (i==j){
				x = p1.rPos(i);
				y = p2.rPos(j);
				z = x-y;
				p1.sPos(i, z);
			}
		}
	}
	
	return p1;
}

polynomial operator-(polynomial &p1){
	int x;
	int y;
	for (int i=p1.deg();i>=0;i--){
		x=p1.rPos(i);
		x = x * -1;
		p1.sPos(i, x);
	}
	return p1;
}

ostream& operator<<(ostream& out, polynomial p1){
	for (int i=p1.deg();i>=0;i--){
		out << p1.rPos(i) << "x^" << i << " ";
	}
	cout << endl;
	return out;
}