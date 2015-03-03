/*
 * polinomio.cpp
 *
 *  Created on: 01/03/2015
 *      Author: Victor
 */

#include "polinomio.h"

/*******************************
 * FUNCIONES DE LA CLASE MONOMIO*
 ********************************/

//CONSTRUCTORES
monomio::monomio() {
	coef = 1;
	exp = 1;
}

monomio::monomio(int c, int e) {
	coef = c;
	exp = e;
}
//no se que hay que implementar aqui
long int monomio::evaluar(int x) const {

}
/*
 * GETTERS Y SETTERS
 */
long int monomio::getCoef() const {
	return coef;
}
long int monomio::getExp() const {
	return exp;
}

void monomio::setCoef(int c) {
	coef = c;
}
void monomio::setExp(int e) {
	exp = e;
}
/*
 * SOBRECARGA DE OPERADORES DE EXTRACCI�N E INSERCI�N
 */
ostream & operator <<(ostream & sout, const monomio & s) {
	if (s.getExp() == 1 && s.getCoef() == 1) {
		sout << "x";
	} else if (s.getCoef() == 0) {

	} else if (s.getExp() == 1) {
		sout << s.getCoef() << "x";
	} else if (s.getExp() == 0) {
		sout << s.getCoef();
	} else if (s.getCoef() == 1) {
		sout << "x^" << s.getExp();
	} else {
		sout << s.getCoef() << "x^" << s.getExp();
	}
	return (sout);
}

istream & operator >>(istream & sin, monomio & r) {
	int c;
	int e;
	cout << "Introduzca un coeficiente" << endl;
	sin >> c;
	r.setCoef(c);
	cout << "Introduzca un exponente" << endl;
	sin >> e;
	r.setExp(e);
	return (sin);
}
/*
 * SOBRECARGA DEL OPERADOR SUMA
 */
monomio monomio::operator +(const monomio & y) {
	if (getExp() == y.getExp()) {
		monomio aux;
		aux.setCoef(getCoef() + y.getCoef());
		aux.setExp(getExp());
		return aux;
	}
}
monomio monomio::operator -(const monomio & y) {
	if (getExp() == y.getExp()) {
		monomio aux;
		aux.setCoef(getCoef() - y.getCoef());
		aux.setExp(getExp());
		return aux;
	}
}
monomio monomio::operator =(const monomio & y) {
	coef = y.getCoef();
	exp = y.getExp();
}
monomio monomio::operator *(const monomio & y) {
	monomio aux;
	aux.setExp(getExp() + y.getExp());
	aux.setCoef(getCoef() * y.getCoef());
	return aux;
}
/*********************************
 * FUNCIONES DE LA CLASE POLINOMIO*
 **********************************/

/*
 * CONSTRUCTORES
 */

polinomio::polinomio() {
	int c = 0;
	int e = 0;
	cout << "Introduzca el grado:" << endl;
	cin >> grado;
	cout << "Introduzca el numero de terminos:";
	cin >> terminos;
	poli = new monomio[terminos];
	for (int i = 0; i < terminos; i++) {
		cout << "Monomio coeficiente y grado " << i << endl;
		cin >> c;
		cin >> e;
		poli[i].setCoef(c);
		poli[i].setExp(e);
	}
	for (int i = 0; i < terminos; i++) {
		cout << poli[i] << " ";
	}
	cout << endl;
}
/*
 * POLINOMIO RAMDOM
 */

polinomio::polinomio(int g, const int t) {
	setGrado(g);
	setTerminos(t);
	poli = new monomio[t];
	srand(time(NULL));
	int c = rand() % 9 + 1;
	poli[0] = monomio(c, g);
	for (int i = 1; i < t; i++) {
		int e = rand() % (g - 1) + 0;
		int c = rand() % 9 + 1;
		poli[i] = monomio(c, e);
	}
}

polinomio::polinomio(int g) {
	setTerminos(g + 1);
	setGrado(g);
	poli = new monomio[getTerminos()];
	srand(time(NULL));
	for (int i = 0; i < getTerminos(); i++) {
		int c = rand() % 9 + 1;
		poli[i] = monomio(c, i);
	}
}
/*
 * DEVUELVE EL GRADO DEL POLINOMIO
 */
long int polinomio::getGrado() const {
	return grado;
}
void polinomio::setGrado(int g) {
	grado = g;
}
/*
 * DEVUELVE EL NUMERO DE TERMINOS DEL POLINOMIO
 */
long int polinomio::getTerminos() const {
	return terminos;
}
void polinomio::setTerminos(int t) {
	terminos = t;
}
/*
 * DEVUELVE UN MONOMIO DEL POLINOMIO
 */
monomio polinomio::getMon(int i) const {
	return poli[i];
}
/*
 * SOBRECARGA DEL OPERADOR *
 */

polinomio & polinomio::operator *(const polinomio & y) {
	polinomio aux((getGrado() * y.getGrado()),
			(getTerminos() * y.getTerminos()));
	int acc = 0; //recorrer polinomio
	for (int i = 0; i < y.getTerminos(); i++) {
		for (int j = 0; j < getTerminos(); j++) {
			if (i == 0 && j == 0) {
				aux.poli[acc] = getMon(j) * y.getMon(i);
				//cout << aux.poli[acc];
			} else {
				aux.poli[acc] = getMon(j) * y.getMon(i);
				//cout << " + " << aux.poli[acc];
			}
			acc++;
		}
	}
	return aux;
}
/*
 * SOBRECARGA DEL OPERADOR =
 */

polinomio & polinomio::operator =(const polinomio & y) {
	for (int i = 0; i < y.getTerminos(); i++) {
		poli[i] = y.poli[i];
	}
	terminos = y.getTerminos();
	grado = y.getGrado();
}

/*
 * SOBRECARGA DEL OPERADOR EXTRACCION
 */
ostream & operator <<(ostream & sout, const polinomio & y) {
	for (int i = 0; i < y.getTerminos(); i++) {
		if (i == 0) {
			sout << y.getMon(i);
		} else {
			if (y.getMon(i).getCoef() == 0) {

			} else {
				sout << " + " << y.getMon(i);
			}
		}
	}
	return (sout);
}
/************************************
 *************************************
 *************************************
 * M�TODOS PRACTICA DIVIDE Y VENCER�S*
 *************************************
 *************************************
 *************************************/
/*
 * METODO PARA OBTENER LA PARTE IZQUIERDA DE UN POLINOMIO DADO
 */
polinomio polinomio::obtener_pi() {

	int mitad = 0;
	if (getTerminos() % 2 == 0)
		mitad = getTerminos() / 2;
	else
		mitad = getTerminos() / 2 + 1;
	polinomio aux(getGrado(), mitad);
	for (int i = 0; i < mitad; i++) {
		aux.poli[i] = poli[i];
	}
	return aux;
}
/*
 * METODO PARA OBTENER LA PARTE DERECHA DE UN POLINOMIO DADO
 */
polinomio polinomio::obtener_pd() {

	int mitad = 0;
	if (getTerminos() % 2 == 0)
		mitad = getTerminos() / 2;
	else
		mitad = getTerminos() / 2 + 1;
	polinomio aux(getGrado(), mitad);
	for (int i = 0; i < mitad; i++) {
		aux.poli[i] = poli[i + mitad];
	}
	return aux;
}
/*
 * METODO PARA SUMAR DOS POLINOMIOS
 */
polinomio polinomio::suma(const polinomio & x) {
	if (getGrado() < x.getGrado()) {
		polinomio aux(x.getGrado());
		//Ponemos todos los coeficientes a cero
		for (int i = 0; i < aux.getTerminos(); i++) {
			aux.poli[i].setCoef(0);
		}
		//Sumamos el primer polinomio
		for (int i = 0; i < aux.getTerminos(); i++) {
			for (int j = 0; j < getTerminos(); j++) {
				if (aux.getMon(i).getExp() == getMon(j).getExp()) {
					aux.poli[i] = aux.getMon(i) + getMon(j);
				}
			}
		}
		//Sumamos el segundo polinomio
		for (int i = 0; i < aux.getTerminos(); i++) {
			for (int j = 0; j < x.getTerminos(); j++) {
				if (aux.getMon(i).getExp() == x.getMon(j).getExp()) {
					aux.poli[i] = aux.getMon(i) + x.getMon(j);
				}
			}
		}
		return aux;
	} else {
		polinomio aux(getGrado());
		//Ponemos todos los coeficientes a cero
		for (int i = 0; i < aux.getTerminos(); i++) {
			aux.poli[i].setCoef(0);
		}
		//Sumamos el primer polinomio
		for (int i = 0; i < aux.getTerminos(); i++) {
			for (int j = 0; j < getTerminos(); j++) {
				if (aux.getMon(i).getExp() == getMon(j).getExp()) {
					aux.poli[i] = aux.getMon(i) + getMon(j);
				}
			}
		}
		//Sumamos el segundo polinomio
		for (int i = 0; i < aux.getTerminos(); i++) {
			for (int j = 0; j < x.getTerminos(); j++) {
				if (aux.getMon(i).getExp() == x.getMon(j).getExp()) {
					aux.poli[i] = aux.getMon(i) + x.getMon(j);
				}
			}
		}
		return aux;
	}
}
/*
 * METODO RESTAR DOS POLINOMIOS
 */

polinomio polinomio::resta(const polinomio & x) {
	for (int i = 0; i < getTerminos(); i++) {
		for (int j = 0; j < x.getTerminos(); j++) {
			if (getMon(i).getExp() == x.getMon(j).getExp()) {
				poli[i] = poli[i] - x.poli[j];
			}
		}
	}
	return *this;
}

/*
 * METODO PARA DESPLAZAR LOS GRADOS DE UN POLINOMIO A LA IZQUIERDA
 */
polinomio polinomio::desplaza(int n) {
	for (int i = 0; i < getTerminos(); i++) {
		poli[i].setExp(poli[i].getExp() + n);
	}
	return *this;
}
/*
 * MULTIPLICACION TRADICIONAL DE POLINOMIOS
 */
polinomio polinomio::multiplica(const polinomio & y) {
	polinomio aux(getGrado() + y.getGrado());
	for (int i = 0; i < aux.getTerminos(); i++) {
		aux.poli[i].setCoef(0);
	}
	for (int i = 0; i < getTerminos(); i++) {
		for (int j = 0; j < y.getTerminos(); j++) {
			aux.poli[poli[i].getExp() + y.poli[j].getExp()] =
					aux.poli[poli[i].getExp() + y.poli[j].getExp()]
							+ (poli[i] * y.poli[j]);
		}
	}
	return aux;
}

void polinomio::coefCero() {
	for (int i = 0; i < getTerminos(); i++) {
		poli[i].setCoef(0);
	}
}
/*******************************************************************
 * MULTIPLICACION DE POLINOMIOS MEDIANTE ALGORITMO DIVIDE Y VENCERAS*
 ********************************************************************/

polinomio polinomio::multiplicaDv(polinomio & x, polinomio & y, int n) {
	if (n == 1) {
		return x.multiplica(y);
	} else {
		polinomio xi = x.obtener_pi();
		polinomio xd = x.obtener_pd();
		polinomio yi = y.obtener_pi();
		polinomio yd = y.obtener_pd();
		polinomio s1 = xi.suma(xd);
		polinomio s2 = yi.suma(yd);
		polinomio p = multiplicaDv(xi, yi, n / 2);
		polinomio q = multiplicaDv(xd, yd, n / 2);
		polinomio r = multiplicaDv(s1, s2, n / 2);
		polinomio aux1 = r.resta(p).resta(q);
		polinomio z = p.suma(aux1).suma(q);
		return z;
	}
}

