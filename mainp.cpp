/*
 * mainp.cpp
 *
 *  Created on: 3/3/2015
 *      Author: alu4406
 */


/*#include "polinomio.h"

int main() {

	char continuar;
	//PRUEBAS DIVIDE Y VENCERAS
	polinomio x(9);
	cout << "Polinomio 1: " << x << endl;
	cin >> continuar;
	polinomio y(9);
	cout << "Polinomio 2: " << y << endl;
	cin >> continuar;
	polinomio t(x.getGrado() + y.getGrado());

	Context a;
	a.setstrategy(DV);

	cout << "DIVIDE Y VENCERAS" << endl;
	float secs;
	clock_t dvcomienzo;
	clock_t dvfin;
	dvcomienzo = clock();
	a.ContextInterface(t, x, y, x.getTerminos());
	dvfin = clock();
	secs = (float) (dvfin - dvcomienzo) / CLOCKS_PER_SEC;
	cout << t << endl;
	cout << "Tiempo de ejecucion " << setprecision(5) << fixed << secs << endl;
	cout << endl;

	a.setstrategy(T);
	cout << "ALGORITMO TRADICIONAL" << endl;

	dvcomienzo = clock();
	a.ContextInterface(t, x, y, x.getTerminos());
	dvfin = clock();
	secs = (float) (dvfin - dvcomienzo) / CLOCKS_PER_SEC;
	cout << t << endl;
	cout << "Tiempo de ejecucion " << setprecision(5) << fixed << secs << endl;
	//Polinomios manual
	polinomio u;
	polinomio v;
	cout << "Clasico" << u.multiplica(v) << endl;
	cout << "DV " << t.multiplicaDv(u, v, u.getTerminos()) << endl;
	system("pause");
	return 0;
}*/


