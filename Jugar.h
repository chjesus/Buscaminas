#ifndef JUGAR_H
#define JUGAR_H

#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

class Jugar{
	int **matrizB;
	char **matrizAux;
	
	static int TAM;
	
	int variableI;
	int variableJ;
	int contMinas;
	int cont;
	public:
		Jugar();
		void pedirDatos(); 
		void generar(); //Da memoria a la matriz
		void generarMatriz(); //LLena matriz con ceros, genera el marco e imprime 
		void generarNumero(); //Colocar numeros alrededor de las bombas
		void validar(int,int); //Recursividad
		void validarCasillas();
		int validarMarcado(int,int);
		void desmarcarMinas(int,int);
		int comprobarmarcado(int ,int);
		void marcarMinas(int,int);
		int validarNumero(int,int); //imprime las casillas distintas de 0,8 y 9
		void recursividad_V(int,int);
		void recursividad_H(int,int);
		
		int getCont();
		void posicion(int,int);
		void imprimir();
};

#endif
