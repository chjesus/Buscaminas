#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "Jugar.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x,y;
	int bomba=0;
	int tipo;
	int contAux=0;
	char tecla;
	Jugar *p = new Jugar();
	
	p->generarMatriz();
	p->generarNumero();
	do{	

	p->imprimir();
		p->posicion(1,1);cout<<"---Bienvenido al Buscaminas---";
		p->posicion(3,17);cout<<"1-Destapar casilla";
		p->posicion(3,18);cout<<"2-Marcar casilla";
		p->posicion(3,19);cout<<"3-Desmarcar Casilla";
		p->posicion(3,20);cout<<"Opcion a Elejir: ";
		tecla=getch();
		//cin>>tipo;
			switch(tecla){
				case '1':	
					p->posicion(1,1);cout<<"---Bienvenido al Buscaminas---";
					p->posicion(3,22);cout<<"Ingrese Filas (1-10): ";
					cin>>x;
					p->posicion(3,23);cout<<"Ingrese Columnas (1-10): ";
					cin>>y;	
					if(p->comprobarmarcado(x,y)==0){
						p->validar(x,y);
						p->validarCasillas();
						bomba=p->validarNumero(x,y);
						p->imprimir();
						cout<<endl<<"---------------------------------------------"<<endl;
					}
					system("cls");
					p->imprimir();
					break;

				case '2':
					do{
						p->posicion(1,1);cout<<"---Bienvenido al Buscaminas---";
						p->imprimir();
						
						p->posicion(3,22);cout<<"Ingrese Fila (1-10)";
						cin>>x;
						p->posicion(3,23);cout<<"Ingrese Columna (1-10): ";
						cin>>y;
						system("cls");
						p->posicion(3,21);cout<<"Coordenadas no Existentes!";
					}while((x<1 || x>10) && (y<1 || y>10));
				
					
					p->marcarMinas(x,y);
					system("cls");
					p->imprimir();
						cout<<endl<<"---------------------------------------------"<<endl;
					break;
				case '3':
					do{
						p->posicion(1,1);cout<<"---Bienvenido al Buscaminas---";
						p->imprimir();
					
						p->posicion(3,22);cout<<"Ingrese Fila (1-10): ";
						cin>>x;
						p->posicion(3,23);cout<<"Ingrese Columna (1-10): ";
						cin>>y;
						system("cls");
						p->posicion(3,21);cout<<"Coordenadas no Existentes!";
					}while((x<1 || x>10) && (y<1 || y>10));
					p->desmarcarMinas(x,y);
					system("cls");
					p->imprimir();
						cout<<endl<<"---------------------------------------------"<<endl;
					break;
					
				default:
					cout<<endl<<"Opcion Invalida";
					system("cls");
					break;
			}
	}while(bomba!=1 && p->getCont()!=10);
	
	if(p->getCont()==10){
		cout<<endl<<"Ganaste!";
	}else{
		cout<<endl<<"Perdiste!!!";
	}
	return 0;
}
