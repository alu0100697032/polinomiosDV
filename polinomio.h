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
#include <conio.h>
#include <iomanip>
using namespace std;
enum TYPESTRATEGY{A, B};

/*
* INTERFAZ ESTRATEGIA
*/
class Strategy {
    public:
	virtual int AlgorithmInterface() = 0;
 };
/*
* CLASES QUE REPRESENTAN LAS DIFERENTES ESTRATEGIAS
*/
//ALGORITMO TRADICIONAL
class ConcreteStrategyA : public Strategy  {
    int AlgorithmInterface() {
     return 1;
    }
};
//DIVIDE Y VENCERAS
class ConcreteStrategyB : public Strategy  {
    int AlgorithmInterface() {
     return 2;
    }
};
/*
* CLASE MONOMIO
*/

class monomio{
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
        long int getCoef()const;
        long int getExp()const;
        void setCoef(int c);
        void setExp(int e);
        //sobrecarga de los operadores de inserción y estracción
        friend ostream & operator << (ostream &sout, const monomio &s);
        friend istream & operator >> (istream &sin, monomio &r);
        //sobrecarga de operadores aritméticos
        monomio operator + (const monomio & y);
        monomio operator - (const monomio & y);
        monomio operator = (const monomio & y);
        monomio operator * (const monomio & y);
};
/*
* CLASE POLINOMIO
*/
class polinomio{
    //atributos
    protected:
	 Strategy *_strategy; //OBJETO ESTRATEGIA
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
        long int getTerminos()const;
        long int getGrado()const;
        void setTerminos(int t);
        void setGrado(int g);
        monomio getMon(int i)const;
        //sobrecarga de operadores aritmeticos
        polinomio & operator * (const polinomio & y);
        polinomio & operator = (const polinomio & y);
        polinomio multiplica(const polinomio & y);
        //sobrecarga del operador <<
        friend ostream & operator << (ostream &sout, const polinomio & y);
        //Métodos práctica 4
        polinomio obtener_pi();
        polinomio obtener_pd();
        polinomio multiplicaDv(polinomio & x, polinomio & y, int n);
        polinomio suma(const polinomio & x);
        polinomio resta(const polinomio & x);
        polinomio desplaza(int n);
        void coefCero();
        /*
        * METODOS PARA EL PATRON DE ESTRATEGIA
        */
        void setEstra(TYPESTRATEGY type );
        int getEstra();
        polinomio algoritmo(polinomio & x, polinomio & y, int n);
};







#endif /* POLINOMIO_H_ */
