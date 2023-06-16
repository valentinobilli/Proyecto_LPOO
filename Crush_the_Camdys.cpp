#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include "Tablero.cpp"
#include <stdio.h>
#include <windows.h>

using namespace std;

void habilidades(int tablero[10][10], int &score, int cursi, int cursj)
{
	char tecla3 = 'f';
	bool eleccion;
	
	if(score < 1000){
		cout << "No hay habilidades disponibles" << endl;
		system("pause");
	}else if(score >= 1000 && score < 3500){
		tablero[cursi][cursj] = 0;
		score = score + 10;
	}else if(score >= 3500 && score < 10000){
		while(tecla3 != 13){
			menu_habilidades(eleccion);
			tecla3 = getch();
			
			switch(tecla3){
				case 72:
					if(eleccion == 1) eleccion = 0;
					else eleccion = 1;
					break;
				case 80:
					if(eleccion == 0) eleccion = 1;
					else eleccion = 0;
					break;
				case 13:
					if(eleccion == 1){
						for(int i=0 ; i<10 ; i++){
							tablero[i][cursj] = 0;
						}
					}else{
						for(int j=0 ; j<10 ; j++){
							tablero[cursi][j] = 0;
						}
					}
					score = score + 1000;
					break;
			}
		}
	}else vaciar(tablero);
}

int main()
{
	char tecla, tecla1;
	int cursi, cursj, cursi1, cursj1, aux, score, movimientos=0, record[5];
	bool flag;
	
	srand(time(NULL));
	
	int tablero[10][10];
	vaciar(tablero);
	
	while(1)
	{
		romperCaramelos(tablero, score, record);
		if(movimientos == 0){
			vaciar_logros(record);
			score = 0;
		}
		cargar(tablero);
		cursi1 = cursj1 = -1;
		system("cls");
		mostrar(tablero, cursi, cursj, cursi1, cursj1, movimientos, score, record);
		
		tecla = getch();
		
		switch(tecla)
		{
			case 'e'://Habilidad
				habilidades(tablero, score, cursi, cursj);
				break;
			case 72://FLECHA DE ABAJO
				if(cursi==0) cursi = 9;
				else cursi --;
				break;
				
			case 80://FLECHA DE ARRIBA
				if(cursi==9) cursi = 0;
				else cursi ++;
				break;
				
			case 75://FLECHA DE LA IZQUIERDA
				if(cursj==0) cursj == 9;
				else cursj --;
				break;
			
			case 77://FLECHA DE LA DERECHA
				if(cursj==9) cursj == 0;
				else cursj ++;
				break;
			
			case 'r':
				movimientos = 1;
				score = 100000;
				break;
			
			case 13://ENTER
				tecla1=10;
				cursi1 = cursi;
				cursj1 = cursj;
				while(tecla1!=13)
				{
					system("cls");
					mostrar(tablero, cursi, cursj, cursi1, cursj1, movimientos, score, record);
					
					tecla1 = getch();
				
					switch(tecla1)	//HABIENDO SELECCIONADO UNA FICHA TOCA SELECCIONAR LA SEGUNDA
					{
						case 72://FLECHA DE ARRIBA
							if(cursi1==0) cursi1 = 9;
							else if(cursi - 1 != cursi1) cursi1 --;
							break;
					
						case 80://FLECHA DE ABAJO
							if(cursi1==9) cursi1 = 0;
							else if(cursi + 1 != cursi1) cursi1 ++;
							break;
				
						case 75://FLECHA DE LA IZQUIERDA
							if(cursj1==0) cursj1 = 9;
							else if(cursj - 1 != cursj1) cursj1 --;
							break;
			
						case 77://FLECHA DE LA DERECHA
							if(cursj1==9) cursj1 = 0;
							else if(cursj + 1 != cursj1) cursj1 ++;
							break;
							
						case 13://ENTER
							aux = tablero[cursi1][cursj1];
							tablero[cursi1][cursj1] = tablero[cursi][cursj];
							tablero[cursi][cursj] = aux;
							if(cursi != cursi1 || cursj != cursj1) movimientos ++;
							break;
					}
				}
				break;
		}
	}
}
