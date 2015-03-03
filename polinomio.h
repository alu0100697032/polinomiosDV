/*
 * polinomio.h
 *
 *  Created on: 01/03/2015
 *      Author: Victor
 */

#ifndef POLINOMIO_H_
#define POLINOMIO_H_

#include <iostream>
#include <stdlib.h>
#include <ctime>
//#include <conio.h>
#include <iomanip>

using namespace std;

enum TYPESTRATEGY {
	T, DV
};

/*
 * CLASE MONOMIO
 */

class monomio {
	//atributos
private:
	long int coef;
	long int exp;
	//metodos
public:
	//constructores
	monomio();
	monomio(int c, int e);
	//getters y setters
	long int evaluar(int x) const;
	long int getCoef() const;
	long int getExp() const;
	void setCoef(int c);
	void setExp(int e);
	//sobrecarga de los operadores de inserci�n y estracci�n
	friend ostream & operator <<(ostream &sout, const monomio &s);
	friend istream & operator >>(istream &sin, monomio &r);
	//sobrecarga de operadores aritm�ticos
	monomio operator +(const monomio & y);
	monomio operator -(const monomio & y);
	monomio operator =(const monomio & y);
	monomio operator *(const monomio & y);
};
/*
 * CLASE POLINOMIO
 */
class polinomio {
	//atributos
private:
	long int grado;
	long int terminos;
	monomio* poli;
	//METODOS
public:
	//CONSTRUCTORES
	polinomio();
	polinomio(int gr);
	polinomio(int gr, const int ter);
	//SETTERS Y GETTERS
	long int getTerminos() const;
	long int getGrado() const;
	void setTerminos(int t);
	void setGrado(int g);
	monomio getMon(int i) const;
	//sobrecarga de operadores aritmeticos
	polinomio & operator *(const polinomio & y);
	polinomio & operator =(const polinomio & y);
	polinomio multiplica(const polinomio & y);
	//sobrecarga del operador <<
	friend ostream & operator <<(ostream &sout, const polinomio & y);
	//DV
	polinomio obtener_pi();
	polinomio obtener_pd();
	polinomio multiplicaDv(polinomio & x, polinomio & y, int n);
	polinomio suma(const polinomio & x);
	polinomio resta(const polinomio & x);
	polinomio desplaza(int n);
	void coefCero();
};

/*
 * INTERFAZ ESTRATEGIA
 */
class Strategy {
public:
	virtual void AlgorithmInterface(polinomio & t, polinomio & x, polinomio & y,
			int n) = 0;
};

//ALGORITMO TRADICIONAL
class ConcreteStrategyT: public Strategy {
	void AlgorithmInterface(polinomio & t, polinomio & x, polinomio & y,
			int n) {
		t = x.multiplica(y);
		//cout << t << endl;
	}
};
//DIVIDE Y VENCERAS
class ConcreteStrategyDV: public Strategy {
	void AlgorithmInterface(polinomio & t, polinomio & x, polinomio & y,
			int n) {
		t = t.multiplicaDv(x, y, n);
		//cout << t << endl;
	}
};

class Context {
private:
	Strategy *_strategy;
public:
	// Constructor
	Context() {
		_strategy = NULL;
	}
	// Constructor
	Context(Strategy *strategy) {
		_strategy = strategy;
	}

	void setstrategy(TYPESTRATEGY type) {
		delete _strategy;
		if (type == T)
			_strategy = new ConcreteStrategyT();
		else if (type == DV)
			_strategy = new ConcreteStrategyDV();
		else
			cout << "ERROR: Stratey not known" << endl;
	}

	void setstrategy(Strategy *strategy) {
		delete _strategy;
		_strategy = strategy;
	}
	void ContextInterface(polinomio & t, polinomio & x, polinomio & y, int n) {
		_strategy->AlgorithmInterface(t, x, y, n);
	}

};
#endif /* POLINOMIO_H_ */
