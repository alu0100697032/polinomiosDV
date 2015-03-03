/*
 * main.cpp
 *
 *  Created on: 01/03/2015
 *      Author: Victor
 */

#include "polinomio.h"

int main() {
	/*
	 * PRUEBAS CON POLINOMIOS
	 */
	char continuar;
	/*
	 * PRUEBAS DIVIDE Y VENCERAS
	 */
	polinomio x(4);
	cout << "Polinomio 1: " << x << endl;
	cin >> continuar;
	polinomio y(3);
	cout << "Polinomio 2: " << y << endl;
	cin >> continuar;
	polinomio t(x.getGrado() + y.getGrado());

	Context a;
	a.setstrategy(DV);
	cout << "DIVIDE Y VENCERAS" << endl;
	a.ContextInterface(t, x, y, x.getTerminos());
	cout << t << endl;

	a.setstrategy(T);
	cout << "ALGORITMO TRADICIONAL" << endl;
	a.ContextInterface(t, x, y, x.getTerminos());
	cout << t << endl;

	/*
	 * Introducir los polinomios de manera manual
	 */
	polinomio u;
 	polinomio v;
	cout << "Clasico" << u.multiplica(v) << endl;
	cout << "DV " << t.multiplicaDv(u, v, u.getTerminos()) << endl;
}
