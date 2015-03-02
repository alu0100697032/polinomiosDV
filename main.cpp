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
	polinomio x(9);
	cout << "Polinomio 1: " << x << endl;
	cin >> continuar;
	polinomio y(9);
	cout << "Polinomio 2: " << y << endl;
	cin >> continuar;
	polinomio t(x.getGrado() + y.getGrado());
	t.setEstra(B);
	cout << "DIVIDE Y VENCERAS" << endl;
	float secs;
	clock_t dvcomienzo;
	clock_t dvfin;
	dvcomienzo = clock();
	t = t.algoritmo(x, y, x.getTerminos());
	//t.algoritmo(x, y, x.getTerminos());
	dvfin = clock();
	secs = (float) (dvfin - dvcomienzo) / CLOCKS_PER_SEC;
	cout << t << endl;
	cout << "Tiempo de ejecucion " << setprecision(5) << fixed << secs << endl;
	cout << endl;

	cout << "ALGORITMO CLASICO" << endl;
	x.setEstra(A);
	dvcomienzo = clock();
	t = x.algoritmo(x, y, x.getTerminos());
	//x.algoritmo(x, y, x.getTerminos());
	dvfin = clock();
	secs = (float) (dvfin - dvcomienzo) / CLOCKS_PER_SEC;
	cout << t << endl;
	cout << "Tiempo de ejecucion " << setprecision(5) << fixed << secs << endl;
	polinomio u;
	polinomio v;
	cout << "Clasico" << u.multiplica(v) << endl;
	cout << "DV " << t.multiplicaDv(u, v, u.getTerminos()) << endl;
	system("pause");
	return 0;
}
