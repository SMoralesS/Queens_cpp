#include "reinas.h"

void reina::pos(int xx,int yy){
	/*Metodo para definir la posicion de reina*/
	posx = xx;
	posy = yy;
}

bool reina::atacaA(reina r2){
	/*Metodo que determina se reina ataca otra reina-r2*/
	if(posx==r2.posx or posy==r2.posy or r2.posy==((posy-posx)+r2.posx) or r2.posy==((posy+posx)-r2.posx)){
		return true;
	}
	else{
		return false;
	}
}

tablero::tablero(){
	cout << "\n\t********************************************\n"
		 << "\t************* Parcial 2 - FC2 **************\n"
		 << "\t********************************************\n"
		 << "\nEl codigo a continuacion encuentra configuraciones de n reinas t al que estas esten en un "
		 <<	"tablero n x n sin atacarse\n" << endl;
}

void tablero::getSize(){
	/*Metodo para que el usuario ingrese valores validos de tamanio de tablero*/
	string senuelo;
	while(true){
		try{
			cout << "Ingrese el tamanio del tablero (sugerencia: ingrese un numero < 12): ";
			getline(cin,senuelo);
			for(int i=0;i<int(senuelo.length());i++){
				if(!isdigit(senuelo.at(i))) throw senuelo;
			}
			tam_tablero = atoi(senuelo.c_str());
			if(tam_tablero<4) throw 1;
		}
		catch(int e){
			cout << "Para tableros con lado < 4 no hay soluciones.\nIngrese un numero mayor que 3." << endl;
			continue;
		}
		catch(string e){
			cout << "Ingrese un numero." << endl;
			continue;
		}
		break;
	}
}

void tablero::getNsol(){
	/*Metodo para que el usuario ingrese valores validos de n*/
	string senuelo;
	while(true){
		try{
			cout << "Ingrese el numero de soluciones que desea: ";
			getline(cin,senuelo);
			for(int i=0;i<int(senuelo.length());i++){
				if(!isdigit(senuelo.at(i))) throw senuelo;
			}
			n = atoi(senuelo.c_str());
			if(n<1) throw 1;
		}
		catch(int e){
			cout << "Ingrese un numero entero positivo." << endl;
			continue;
		}
		catch(string e){
			cout << "Ingrese un numero entero positivo." << endl;
			continue;
		}
		break;
	}
}

bool tablero::seAtacan(){
	/*Metodo que determina si las reinas en tablero se atacan*/
	for(int i=0;i<reinas.size();i++){
		for(int j=i+1;j<reinas.size();j++){
			int b = reinas[i].atacaA(reinas[j]);
			if(reinas[i].atacaA(reinas[j])){
				return true;
			}
		}
	}
	return false;
}

void tablero::generarReinas(int n){
	/*Metodo que genera n reinas y las guarda en el vector reinas*/
	int x,y;
	tam_tablero = n;
	reinas.clear();  					//limpia el vector de reinas del paso anterior
	reinas.resize(n);					//reasigna el tamanio de reinas en caso de que cambie					
	for(int i=0;i<n;i++){				
		y = 1+rand()%(n);				//Las columnas se asignan con el i porque sabemos que no pueden
		reinas[i].pos(i+1,y);			//haber 2 en misma,ahorra tiempo de computo (no sirve para prob.)
	}
}

void tablero::imprimirReinas(){
	int posiciones[tam_tablero][tam_tablero] = {}; //matriz tam_tableroxtam_tablero de ceros.

	cout << "\nPosicion de las reinas: "<<endl;
	for(int j=0;j<tam_tablero;j++){
		posiciones[tam_tablero-reinas[j].posy][reinas[j].posx-1] = 1; //unos donde hay reinas
	}
	for(int j=0;j<tam_tablero;j++){
		for(int l=0;l<tam_tablero;l++){
			cout << posiciones[j][l] <<" ";
		}
		cout << "\n";
	}
}

void tablero::encontrarSoluciones(){
	/*Metodo que encuentra las n soluciones en el tablero de tamanio tam_tablero*/
	int cont=0;
	while(cont<n){
		generarReinas(tam_tablero); 				//Genera tam_tablero reinas no completamente aleatorias
		if(!seAtacan()){							//ya que presupone que no hay 2 en la misma columna.
			cont++;
			imprimirReinas();
		}
	}
}
