#include "Jugar.h"

using namespace std;

Jugar::Jugar(){
	cont=0;
}

int Jugar::TAM=12;

void Jugar::generar(){
	
	matrizB = new int*[TAM];
	matrizAux = new char*[TAM];
	
	for(int i=0;i<TAM;i++){
		matrizB[i]=new int[TAM];
		matrizAux[i]=new char[TAM];
	}

}
void Jugar::generarMatriz(){
	srand(time(NULL));
	contMinas=0;
	
	Jugar::generar();

	for(int i=0;i<TAM;i++){
		for(int j=0;j<TAM;j++){
			matrizB[i][j]=0;
			matrizAux[i][j]=254;
		}
	}
	
	int j=0;
	do{	
		matrizB[j][0]=7;
		matrizB[j][11]=7;
		matrizB[0][j]=7;
		matrizB[11][j]=7;
		
		matrizAux[j][0]=219;
		matrizAux[j][11]=219;
		matrizAux[0][j]=219;
		matrizAux[11][j]=219;
	j++;
	}while(j<12);
	
	do{
		variableI=rand()%10;
		variableJ=rand()%10;	
		if(variableI==0){
			variableI+=1;
		}
		if(variableJ==0){
			variableJ+=1;
		}
		if(variableI==12){
			variableI-=1;
		}
		if(variableJ==12){
			variableJ-=1;
		}		
			if(matrizB[variableI][variableJ]==0){
				matrizB[variableI][variableJ]=9;
				contMinas++;
			}
		variableI=0;
		variableJ=0;	
	}while(contMinas<10);

	Jugar::generarNumero();	
}
void Jugar::generarNumero(){
	
	int contMinasAux=0;
	
	for(int i=1;i<TAM-1;i++){ //validacion de esquinas
		for(int j=1;j<TAM-1;j++){
			contMinasAux=0;
			if(i==1 && j==1)
			{
				if(matrizB[i+1][j]==9)
				contMinasAux++;
				
				if(matrizB[i][j+1]==9)
				contMinasAux++;
				
				if(matrizB[i+1][j+1]==9)
				contMinasAux++;
				
				matrizB[i][j]=contMinasAux;
			}
			if(i==1 && j==10)
			{
				if(matrizB[i+1][j]==9)
				contMinasAux++;
				
				if(matrizB[i][j-1]==9)
				contMinasAux++;
				
				if(matrizB[i+1][j-1]==9)
				contMinasAux++;
				
				matrizB[i][j]=contMinasAux;
			}
			if(i==10 && j==1)
			{
				if(matrizB[i-1][j]==9)
				contMinasAux++;
				
				if(matrizB[i][j+1]==9)
				contMinasAux++;
				
				if(matrizB[i-1][j+1]==9)
				contMinasAux++;
				
				matrizB[i][j]=contMinasAux;
			}
			if(i==10 && j==10)
			{
				if(matrizB[i-1][j]==9)
				contMinasAux++;
				
				if(matrizB[i][j-1]==9)
				contMinasAux++;
				
				if(matrizB[i-1][j-1]==9)
				contMinasAux++;
				
				matrizB[i][j]=contMinasAux;
			}
				
			
			
		}
	}
	
	for(int j=2;j<TAM-2;j++){ //validacion de borde horizontal superior
		contMinasAux=0;
		if(matrizB[1][j]==0){
			if(matrizB[1][j-1]==9 ){
				contMinasAux++;
			}
			if(matrizB[1][j+1]==9){
				contMinasAux++;
			}
			if(matrizB[1+1][j]==9){
				contMinasAux++;
			}
			if(matrizB[1+1][j-1]==9){
				contMinasAux++;
			}
			if(matrizB[1+1][j+1]==9){
				contMinasAux++;
			}	
			matrizB[1][j]=contMinasAux;
		}
	}
	
	for(int j=2;j<TAM-2;j++){ //validacion de borde horizontal inferior
		contMinasAux=0;
		if(matrizB[10][j]==0){
			if(matrizB[10][j-1]==9){
				contMinasAux++;
			}
			if(matrizB[10][j+1]==9){
				contMinasAux++;
			}
			if(matrizB[10-1][j]==9){
				contMinasAux++;
			}
			if(matrizB[10-1][j-1]==9){
				contMinasAux++;
			}
			if(matrizB[10-1][j+1]==9){
				contMinasAux++;
			}	
			matrizB[10][j]=contMinasAux;
		}	
	}

	for(int i=2;i<TAM-2;i++){ //validacion de borde vertical izquierdo
		contMinasAux=0;
		if(matrizB[i][1]==0){
			if(matrizB[i-1][1]==9){
				contMinasAux++;
			}
			if(matrizB[i][1+1]==9){
				contMinasAux++;
			}
			if(matrizB[i+1][1]==9){
				contMinasAux++;
			}
			if(matrizB[i+1][1+1]==9){
				contMinasAux++;
			}
			if(matrizB[i-1][1+1]==9){
				contMinasAux++;
			}
			matrizB[i][1]=contMinasAux;
		}
	}

	for(int i=2;i<TAM-2;i++){ //validacion de borde vertical derecho
		contMinasAux=0;
		if(matrizB[i][10]==0){
			if(matrizB[i-1][10]==9){
				contMinasAux++;
			}
			if(matrizB[i][10-1]==9){
				contMinasAux++;
			}
			if(matrizB[i+1][10]==9){
				contMinasAux++;
			}
			if(matrizB[i-1][10-1]==9){
				contMinasAux++;
			}
			if(matrizB[i+1][10-1]==9){
				contMinasAux++;
			}
			matrizB[i][10]=contMinasAux;
		}
	}
		
	for(int i=2;i<TAM-2;i++){ //validacion del centro
		for(int j=2;j<TAM-2;j++){
			contMinasAux=0;
				if(matrizB[i][j]==0){
					if(matrizB[i-1][j-1]==9){
						contMinasAux++;
					}
					if(matrizB[i-1][j]==9){
						contMinasAux++;
					}
					if(matrizB[i-1][j+1]==9){
						contMinasAux++;
					}
					if(matrizB[i][j+1]==9){
						contMinasAux++;
					}
					if(matrizB[i+1][j+1]==9){
						contMinasAux++;
					}
					if(matrizB[i+1][j]==9){
						contMinasAux++;
					}
					if(matrizB[i+1][j-1]==9){
						contMinasAux++;
					}
					if(matrizB[i][j-1]==9){
						contMinasAux++;
					}
					matrizB[i][j]=contMinasAux;
				}
			}
		}
}

void Jugar::recursividad_V(int a,int b){
	
		if(matrizB[a][b]==0){
			matrizB[a][b]=8;
				if(matrizB[a-1][b]==0){	
					Jugar::recursividad_V(a-1,b);	
				}
				if(matrizB[a][b-1]==0){
					Jugar::recursividad_H(a,b-1);	
				}
				if(matrizB[a][b+1]==0){
					Jugar::recursividad_H(a,b+1);	
				}
		}
		a++;
		if(matrizB[a][b]==0 || matrizB[a][b]==8){	
			matrizB[a][b]=8;
				if(matrizB[a+1][b]==0 || matrizB[a+1][b]==8){
					Jugar::recursividad_V(a+1,b);
				}
				if(matrizB[a][b-1]==0 ){
					Jugar::recursividad_H(a,b-1);	
				}
				if(matrizB[a][b+1]==0){
					Jugar::recursividad_H(a,b+1);
				}
		}
}
void Jugar::recursividad_H(int a,int b){
		
		if(matrizB[a][b]==0 || matrizB[a][b]==8){
			matrizB[a][b]=8;
				if(matrizB[a][b-1]==0){
					Jugar::recursividad_H(a,b-1);
				}

				if(matrizB[a-1][b]==0){
					Jugar::recursividad_V(a-1,b);	
				}
				if(matrizB[a+1][b]==0){
					Jugar::recursividad_V(a+1,b);	
				}
		}
		b++;
		if(matrizB[a][b]==0){	
			matrizB[a][b]=8;
				if(matrizB[a][b+1]==0){
					Jugar::recursividad_H(a,b+1);	
				}
				if(matrizB[a+1][b]==0 || matrizB[a][b-1]==0){
					Jugar::recursividad_H(a+1,b);	
				}	
				if(matrizB[a-1][b]==0 || matrizB[a][b-1]==0){
					Jugar::recursividad_H(a-1,b);	
				}
		}	
}
void Jugar::validar(int a,int b){
	Jugar::recursividad_V(a,b);
}

void Jugar::validarCasillas(){
	for(int i=0;i<TAM-1;i++){
		for(int j=0;j<TAM-1;j++){
			if(matrizB[i][j]==8){
				if(matrizB[i-1][j-1]==1){
					matrizAux[i-1][j-1]='1';
				}
				if(matrizB[i-1][j-1]==2){
					matrizAux[i-1][j-1]='2';
				}
				if(matrizB[i-1][j-1]==3){
					matrizAux[i-1][j-1]='3';
				}
				if(matrizB[i-1][j-1]==4){
					matrizAux[i-1][j-1]='4';
				}
				if(matrizB[i-1][j-1]==5){
					matrizAux[i-1][j-1]='5';
				}
				/*-----------------------------*/
				if(matrizB[i-1][j]==1){
					matrizAux[i-1][j]='1';
				}
				if(matrizB[i-1][j]==2){
					matrizAux[i-1][j]='2';
				}
				if(matrizB[i-1][j]==3){
					matrizAux[i-1][j]='3';
				}
				if(matrizB[i-1][j]==4){
					matrizAux[i-1][j]='4';
				}
				if(matrizB[i-1][j]==5){
					matrizAux[i-1][j]='5';
				}
				/*-----------------------------*/
				if(matrizB[i-1][j+1]==1){
					matrizAux[i-1][j+1]='1';
				}
				if(matrizB[i-1][j+1]==2){
					matrizAux[i-1][j+1]='2';
				}
				if(matrizB[i-1][j+1]==3){
					matrizAux[i-1][j+1]='3';
				}
				if(matrizB[i-1][j+1]==4){
					matrizAux[i-1][j+1]='4';
				}
				if(matrizB[i-1][j+1]==5){
					matrizAux[i-1][j+1]='5';
				}
				/*-----------------------------*/
				if(matrizB[i][j+1]==1){
					matrizAux[i][j+1]='1';
				}
				if(matrizB[i][j+1]==2){
					matrizAux[i][j+1]='2';
				}
				if(matrizB[i][j+1]==3){
					matrizAux[i][j+1]='3';
				}
				if(matrizB[i][j+1]==4){
					matrizAux[i][j+1]='4';
				}
				if(matrizB[i][j+1]==5){
					matrizAux[i][j+1]='5';
				}
				/*----------------------------*/
				if(matrizB[i+1][j+1]==1){
					matrizAux[i+1][j+1]='1';
				}
				if(matrizB[i+1][j+1]==2){
					matrizAux[i+1][j+1]='2';
				}
				if(matrizB[i+1][j+1]==3){
					matrizAux[i+1][j+1]='3';
				}
				if(matrizB[i+1][j+1]==4){
					matrizAux[i+1][j+1]='4';
				}
				if(matrizB[i+1][j+1]==5){
					matrizAux[i+1][j+1]='5';
				}
				/*----------------------------*/
				if(matrizB[i+1][j]==1){
					matrizAux[i+1][j]='1';
				}
				if(matrizB[i+1][j]==2){
					matrizAux[i+1][j]='2';
				}
				if(matrizB[i+1][j]==3){
					matrizAux[i+1][j]='3';
				}
				if(matrizB[i+1][j]==4){
					matrizAux[i+1][j]='4';
				}
				if(matrizB[i+1][j]==5){
					matrizAux[i+1][j]='5';
				}
				/*---------------------------*/
				if(matrizB[i+1][j-1]==1){
					matrizAux[i+1][j-1]='1';
				}
				if(matrizB[i+1][j-1]==2){
					matrizAux[i+1][j-1]='2';
				}
				if(matrizB[i+1][j-1]==3){
					matrizAux[i+1][j-1]='3';
				}
				if(matrizB[i+1][j-1]==4){
					matrizAux[i+1][j-1]='4';
				}
				if(matrizB[i+1][j-1]==5){
					matrizAux[i+1][j-1]='5';
				}
				/*---------------------------*/
				if(matrizB[i][j-1]==1){
					matrizAux[i][j-1]='1';
				}
				if(matrizB[i][j-1]==2){
					matrizAux[i][j-1]='2';
				}
				if(matrizB[i][j-1]==3){
					matrizAux[i][j-1]='3';
				}
				if(matrizB[i][j-1]==4){
					matrizAux[i][j-1]='4';
				}
				if(matrizB[i][j-1]==5){
					matrizAux[i][j-1]='5';
				}
				/*---------------------------*/
				if(matrizB[i][j]==8){
					matrizAux[i][j]=32;
				}
			}

		}
	}
}
int Jugar::validarNumero(int i,int j){
				if(matrizB[i][j]==1){
					matrizAux[i][j]='1';
					return 0;
				}
				if(matrizB[i][j]==2){
					matrizAux[i][j]='2';
					return 0;
				}
				if(matrizB[i][j]==3){
					matrizAux[i][j]='3';
					return 0;
				}
				if(matrizB[i][j]==4){
					matrizAux[i][j]='4';
					return 0;
				}
				if(matrizB[i][j]==5){
					matrizAux[i][j]='5';
					return 0;
				}
				
				if(matrizB[i][j]==9){
					matrizAux[i][j]='B';
					return 1;
				}
}
int Jugar::comprobarmarcado(int a,int b){
	if(matrizAux[a][b]==42)
	{
		return 1;
	}
	else 
	return 0;
}
int Jugar::validarMarcado(int i,int j){
	if(matrizB[i][j]==8 || matrizAux[i][j]=='1' || matrizAux[i][j]=='2' || matrizAux[i][j]=='3' || matrizAux[i][j]=='4' || matrizAux[i][j]=='5'){
		return 1;
	}else {
		return 0;
	}
}
void Jugar::desmarcarMinas(int i,int j){
	if(Jugar::validarMarcado(i,j)==0){
		matrizAux[i][j]=254;
		cont--;
	}
}

void Jugar::marcarMinas(int i,int j){

	if(Jugar::validarMarcado(i,j)==0){
		matrizAux[i][j]=42;
	}
	if(matrizAux[i][j]==42){
		if(matrizB[i][j]==9){
			cont++;
		}
	}
}

int Jugar::getCont(){
	return cont;
}
void Jugar::posicion(int x,int y){

      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X= x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
    
}
void Jugar::imprimir(){
	int a=3;
	int b=2;
	/*Mostrar matriz resultante*/
	/*for(int i=0;i<TAM;i++){
		Jugar::posicion(15,b++);
		for(int j=0;j<TAM;j++){	
			cout<<" "<<matrizB[i][j];
		}
		cout<<endl;
	}*/
	
	for(int i=0;i<TAM;i++){
		Jugar::posicion(10,a++);
		for(int j=0;j<TAM;j++){	
			
			//cout<<" "<<matrizB[i][j];
			cout<<""<<matrizAux[i][j];
		}
		cout<<endl;
	}
}

