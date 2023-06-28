#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include "Tablero.cpp"
#include <stdio.h>
#include <windows.h>

using namespace std;

void habilidades(int tablero[10][10], int &score, int cursi, int cursj, COORD coordenadas)
{
	char tecla3 = 'f';	/*En caso de tener mas de 3500 puntos la habilidad da dos opciones, para seleccionar que opcion se usa esta tecla*/
	bool eleccion;	/*Esta es la bandera de la seleccion de el tipo de la misma*/
	
	if(score < 1000){	/*Si el usuario no tiene habilidades disponibles, se imprime el mensaje*/
		system("cls");	
		cout << "No hay habilidades disponibles" << endl;
		system("pause");
	}else if(score >= 1000 && score < 3500){	/*Si el usuario usa la habilidad teniendo mas de 1000 puntos y hasta 3500 puntos*/
		tablero[cursi][cursj] = 0;	/*Se elimina un caramelo*/
		score = score + 10;			/*Se le suma 10 puntoas por haber roto un caramelo*/
	}else if(score >= 3500 && score < 10000){	/*si el usuario tiene mas de 3500 puntos y hasta 10000 puntos*/
		while(tecla3 != 13){	/*Inicio de ciclo de repeticion de menu de seleccion*/
			menu_habilidades(eleccion, coordenadas);	/*Situa el menu en unas coordenadas especificas*/
			tecla3 = getch();		/*le asigna a tecla el caracter apretado en el teclado como un valor en ascii*/
			
			switch(tecla3){		/*Compara la tecla apretada con algunos casos*/
				case 72:	/*En caso de apretar la tecla de "ABAJO"*/
					if(eleccion == 1) eleccion = 0;	/*Si esta en el maximo posible se camba la eleccion al minimo posible*/
					else eleccion = 1;	/*Sino se cambia a la maxima posible*/
					break;
				case 80:	/*En caso de apretar la tecla de "ARRIBA"*/
					if(eleccion == 0) eleccion = 1;	/*Si esta en el menorposible cambia la seleccion al maximo posible*/
					else eleccion = 0;	/*Sino se cambia a la minimaposible*/
					break;
				case 13:
					if(eleccion == 1){
						for(int i=0 ; i<10 ; i++){	/*En caso de seleccionar "Eliminar toda una fila"*/
							tablero[i][cursj] = 0;	/*Iguala todos los valores de la fila a 0, para que se reemplazen por caramelos*/
						}
					}else{
						for(int j=0 ; j<10 ; j++){  /*En caso de seleccionar "Eliminar toda una columna"*/
							tablero[cursi][j] = 0;	/*Iguala todos los valores de la columna a 0, para que se reemplazen por caramelos*/
						}
					}
					score = score + 100;	/*Te suma 10 por caramelo destruido(10) ==> 10*10 ==> 100*/
					break;
			}
		}
	}else vaciar(tablero);	/*En el caso de que tenga mas de 10000 puntos se elimina todo el tablero*/
}

int main()
{
	char tecla, tecla1;
	/*
		tecla ==>	las teclas de primera seleccion de tablero
		tecla1 ==> 	las teclas de segunda seleccion de tablero
	*/
	int cursi, cursj, cursi1, cursj1, aux, score, movimientos=0, record[5];
	/*	
		cursi ==>	ubicacion de la eleccion 1 en columna
		cursj ==>	ubicacion de la eleccion 1 en fila
		cursi1 ==>	ubicacion de la eleccion 2 en columna
		cursj1 ==>	ubicacion de la eleccion 2 en fila
		aux ==> 	usado para el intercambio de las fichas luego de la seguna selecion
		score ==>	acumulador puntos a lo largo del juego
		movimientos ==>	contador de movimientos
		record[5] ==> para los logros
	*/
	
	COORD coordenadas;
	/*	COORD ==> Utilizacion de la  libreria <windows.h> para poder situar dode se requiere un caracter
		coordenadas ==> para poder usar las posiciones en la windows.h se debe usuar una veriable(que en realidad es una estructura) y
						se le pasa la variable para la horientacion en x y el valor para la horientacion en y
						nombre.Y y nombre.X
	*/

	srand(time(NULL));
	/*	Creacion de la semilla para lso numeros random*/
	
	int tablero[10][10];
	/*	tablero[10][10] ==> Creacion del tablero*/

	vaciar(tablero);	/*se le envia a la funcion "vaciar" la matriz tablero*/
	
	cursi = cursj = 0;
	/*Iguala los cursores i y j a 0 para que comineze la seleccion de el primer movimento empieze de la primera casilla*/
	
	while(1)	/*Inicio del juego*/
	{
		romperCaramelos(tablero, score, record);
		if(movimientos == 0){
			vaciar_logros(record);
			score = 0;
		}
		cargar(tablero);
		cursi1 = cursj1 = -1;
		system("cls");
		mostrar(tablero, cursi, cursj, cursi1, cursj1, movimientos, score, record, coordenadas);
		
		tecla = getch();
		
		switch(tecla)
		{
			case 'e'://Habilidad
				habilidades(tablero, score, cursi, cursj, coordenadas);
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
			
			case 27://ESC
				system("cls");
				cout << "PUNTAJE FINAL " << score;
				return 0;
				
			case 'r':
				movimientos = 1;
				score = 3501;
				break;
			
			case 13://ENTER
				tecla1=10;
				cursi1 = cursi;
				cursj1 = cursj;
				while(tecla1!=13)
				{
					system("cls");
					mostrar(tablero, cursi, cursj, cursi1, cursj1, movimientos, score, record, coordenadas);
					
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
