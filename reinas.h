#include<iostream>
#include<vector>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include<ctime>
using namespace std;

class reina{
	public:
		void pos(int xx,int yy);		
		bool atacaA(reina);				//devuelve true si las reinas se atacan
		int posx, posy;		
};

class tablero{
	public:
		tablero();
		void getNsol();
		void getSize();
		void generarReinas(int);
		void imprimirReinas();
		bool seAtacan();
		void encontrarSoluciones();
	private:
		vector<reina> reinas;
		int tam_tablero;
		int n;
};
