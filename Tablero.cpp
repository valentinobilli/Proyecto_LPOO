#include <iostream>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#define color SetConsoleTextAttribute
#define posicion SetConsoleCursorPosition

HANDLE hconsole = GetStdHandle( STD_OUTPUT_HANDLE );
using namespace std;

int aleatorio()	/*genera un nuemro aleatorio entre 1 y 5*/
{
	return (1 + rand() % 5) ;
}

void vaciar_logros(int vector[5]){	/*vacia todos los logros*/
	for(int i= 0 ; i<5 ; i++) vector[i] = 0;
}


void menu_habilidades(int eleccion, COORD coordenadas)	/*diseño grafico del menu de la habilidad de 3500 puntos*/
{
	coordenadas.X = 2;
	coordenadas.Y = 2;
	posicion(hconsole, coordenadas);
	cout << "+----------------------+" << endl;
	if(eleccion == 1){
		
		coordenadas.X = 2;
		coordenadas.Y = 3;
		posicion(hconsole, coordenadas);
		cout << "|  Eliminar una fila   |" ;
		coordenadas.X = 2;
		coordenadas.Y = 4;
		posicion(hconsole, coordenadas);
		cout << "|";
		color(hconsole, 240);
		cout << " >Eliminar una columna";
		color(hconsole, 15);
		cout << "|";
	}else{
		coordenadas.X = 2;
		coordenadas.Y = 3;
		posicion(hconsole, coordenadas);
		cout << "|";
		color(hconsole, 240);
		cout << " >Eliminar una fila   ";
		color(hconsole, 15);
		cout << "|" ;
		coordenadas.X = 2;
		coordenadas.Y = 4;
		posicion(hconsole, coordenadas);
		cout << "|  Eliminar una columna|";
	}
	coordenadas.X = 2;
	coordenadas.Y = 5;
	posicion(hconsole, coordenadas);
	cout << "+----------------------+" << endl;
}

void logros(int vector[5], int &score, COORD coordenadas)	/*Muestra los logros y tu avance en los mismos*/
{
	int vec2[5];
	
	coordenadas.X = 25;
	coordenadas.Y = 1;
	posicion(hconsole, coordenadas);
	if(vector[0] < 5) cout << "Rompe 5 combinaciones de caramelos @\t\t" << vector[0] << "/5" << endl;
	else if(vector[0]>=5 && vector[0]<10){
		cout << "Rompe 10 combinaciones de caramelos @\t\t" << vector[0] << "/10" << endl;
		if(vec2[0]!=1){
			vec2[0] = 1;
			score = score + 10;
		}
	}else if(vector[0]>=10 && vector[0]<20){
		cout << "Rompe 20 combinaciones de caramelos @\t\t" << vector[0] << "/20" << endl;
		if(vec2[0]!=2){
			vec2[0] = 2;
			score = score + 20;
		}
	}else{
		cout << "Ya todo logrado con los caramelos @. Ya rompiste: " << vector[0] << endl;
		if(vec2[0]!=3){
			vec2[0] = 3;
			score = score + 40;
		}
	}
	
	coordenadas.X = 25;
	coordenadas.Y = 2;
	posicion(hconsole, coordenadas);
	if(vector[1]<5) cout << "Rompe 5 combinaciones de caramelos #\t\t" << vector[1] << "/5" << endl;
	else if(vector[1]>=5 && vector[1]<10){
		cout << "Rompe 10 combinaciones de caramelos #\t\t" << vector[1] << "/10" << endl;
		if(vec2[1] != 1){
			vec2[1] = 1;
			score = score + 10;
		}
	}else if(vector[1]>=10 && vector[1]<20){
		cout << "Rompe 20 combinaciones de caramelos #\t\t" << vector[1] << "/20" << endl;
		if(vec2[1] != 2){
			vec2[1] = 2;
			score = score + 20;
		}
	}else{
		cout << "Ya todo logrado con los caramelos #" << endl;
		if(vec2[1] != 3){
			vec2 [1]= 3;
			score = score + 40;
		}
	}
	
	coordenadas.X = 25;
	coordenadas.Y = 3;
	posicion(hconsole, coordenadas);
	if(vector[2]<5) cout << "Rompe 5 combinaciones de caramelos X\t\t" << vector[2] << "/5" << endl;
	else if(vector[2]>=5 && vector[2]<10){
		cout << "Rompe 10 combinaciones de caramelos X\t\t" << vector[2] << "/10" << endl;
		if(vec2[2] != 1){
			vec2[2] = 1;
			score = score + 10;
		}
	}else if(vector[2]>=10 && vector[2]<20){
		cout << "Rompe 20 combinaciones de caramelos X\t\t" << vector[2] << "/20" << endl;
		if(vec2[2] != 2){
			vec2[2] = 1;
			score = score + 20;
		}
	}else{
		cout << "Ya todo logrado con los caramelos X" << endl;
		if(vec2[2] != 3){
			vec2[2] = 3;
			score = score + 40;
		}
	}
	
	coordenadas.X = 25;
	coordenadas.Y = 4;
	posicion(hconsole, coordenadas);
	if(vector[3] < 5) cout << "Rompe 5 combinaciones de caramelos H\t\t" << vector[3] << "/5" << endl;
	else if(vector[3]>=5 && vector[3]<10){
		cout << "Rompe 10 combinaciones de caramelos H\t\t" << vector[3] << "/10" << endl;
		if(vec2[3]!=1){
			vec2[3] = 1;
			score = score + 10;
		}
	}else if(vector[3]>=10 && vector[3]<20){
		cout << "Rompe 20 combinaciones de caramelos H\t\t" << vector[3] << "/20" << endl;
		if(vec2[3]!=2){
			vec2[3] = 2;
			score = score + 20;
		}
	}else{
		cout << "Ya todo logrado con los caramelos H. Ya rompiste: " << vector[3] << endl;
		if(vec2[3]!=3){
			vec2[3] = 3;
			score = score + 40;
		}
	}
	
	coordenadas.X = 25;
	coordenadas.Y = 5;
	posicion(hconsole, coordenadas);
	if(vector[4] < 5) cout << "Rompe 5 combinaciones de caramelos C\t\t" << vector[4] << "/5" << endl;
	else if(vector[4]>=5 && vector[4]<10){
		cout << "Rompe 10 combinaciones de caramelos C\t\t" << vector[4] << "/10" << endl;
		if(vec2[4]!=1){
			vec2[4] = 1;
			score = score + 10;
		}
	}else if(vector[4]>=10 && vector[4]<20){
		cout << "Rompe 20 combinaciones de caramelos C\t\t" << vector[4] << "/20" << endl;
		if(vec2[4]!=2){
			vec2[4] = 2;
			score = score + 20;
		}
	}else{
		cout << "Ya todo logrado con los caramelos C. Ya rompiste: " << vector[4] << endl;
		if(vec2[4]!=3){
			vec2[4] = 3;
			score = score + 40;
		}
	}
}

void cargar(int tablero[10][10])
{/*Llena toda la matriz de numeros aleatoreos del 1 al 5, que luego seran tomados como fichas, siempre y cuando haya un hueco que valga 0*/
	for(int i=0; i<10 ; i++)
	{
		for(int j=0 ; j<10 ; j++)
		{
			if(tablero[i][j] == 0) tablero[i][j] = aleatorio();	/*Si el valor de el hueco es 0 se igualara a un numero aleatorio del 1 al 5*/
		}
	}
}

void vaciar(int tablero[10][10])	/*vacia todo el taclero*/
{
	for(int i=0; i<10 ; i++)
	{
		for(int j=0; j<10 ; j++)
		{
			tablero[i][j] = 0;	/*Iguala todo el tablero a 0*/
		}
	}
	cargar(tablero);
}

void romperCaramelos(int tablero[10][10], int &score, int record[5]) {
    bool hayRupturas = false, hayRuptura[2] = {true, true};
    /*	hayRupturas ==>		Flag usada para saber si c rompieron caramelos
		hayRuptura[2] ==>	un vector de 2 banderas para guardar en que seccion se rompieron caramelos*/
    while(hayRuptura[0] || hayRuptura[1])
    {
    	// Ruptura horizontal
   		for (int i = 0; i < 10; i++) {
        	for (int j = 2; j < 10; j++) {
            	if (tablero[i][j] == tablero[i][j-1] && tablero[i][j] == tablero[i][j-2]) {	/*Si hay 3 valores consecutivos iguales*/
                	record[tablero[i][j]-1] = record[tablero[i][j]-1] + 1;	/*Aumenta el logro respectivo en 1*/
					tablero[i][j] = 0;
                	tablero[i][j-1] = 0;
                	tablero[i][j-2] = 0;
					/*	Iguala los tres valores del tblero a 0*/
                	hayRupturas = true;
                	hayRuptura[0] = true;
					/*cambia las banderas correspondientes a true*/
                	score  = score + 30;
					/*Suma 10 puntos por caramelo roto*/
            	}else hayRuptura[0] = false;	/*si no se rompieron caramelos durante este ciclo cambia la bandera del mismo a false*/
        	}
    	}
    
    	// Ruptura vertical
    	for (int j = 0; j < 10; j++) {
        	for (int i = 2; i < 10; i++) {
            	if (tablero[i][j] == tablero[i-1][j] && tablero[i][j] == tablero[i-2][j]) {	/*Si hay 3 valores consecutivos iguales*/
            		record[tablero[i][j]-1] = record[tablero[i][j]-1] + 1;/*Aumenta el logro respectivo en 1*/
                	tablero[i][j] = 0;
                	tablero[i-1][j] = 0;
                	tablero[i-2][j] = 0;
					/*	Iguala los tres valores del tblero a 0*/
                	hayRupturas = true;
                	hayRuptura[1] = true;
					/*cambia las banderas correspondientes a true*/
                	score = score + 30;
					/*Suma 10 puntos por caramelo roto*/
            	}else hayRuptura[1] = false;/*si no se rompieron caramelos durante este ciclo cambia la bandera del mismo a false*/
        	}
    	}
    
    	// Si se produjeron rupturas, colapsar los caramelos hacia abajo
    	if (hayRupturas) {
        	for (int j = 0; j < 10; j++) {
            	for (int i = 10 - 1; i >= 0; i--) {
                	if (tablero[i][j] == 0) {
                    	// Buscar el caramelo más cercano por encima y colapsar hacia abajo
                    	int k = i - 1;
                    	while (k >= 0 && tablero[k][j] == 0) {
                        	k--;
                    	}
                    	if (k >= 0) {
                    	    tablero[i][j] = tablero[k][j];
                        	tablero[k][j] = 0;
                    	}
                	}
            	}
        	}	
    	}
	}
}

void mostrar(int tablero[10][10], int cursi, int cursj, int cursi1, int cursj1, int movimientos, int &score, int vector[5], COORD coordenadas)
{
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	for(int i=0; i<10 ; i++)
	{
		printf("%c", 186);
		for(int j=0 ; j<10 ; j++)
		{	
			color(hconsole, 15);
			cout << " ";
			
			if(i==cursi1 && j==cursj1) color(hconsole, 31);
			else if(i==cursi && j==cursj) color(hconsole, 240);
			else color(hconsole, 15);
			
			if(tablero[i][j]==1) cout << "@";
			else if(tablero[i][j]==2) cout << "#";
			else if(tablero[i][j]==3) cout << "X";
			else if(tablero[i][j]==4) cout << "H";
			else if(tablero[i][j]==5) cout << "C";
			else cout << "0";
		}
		color(hconsole, 15);
		printf(" %c\n", 186);
		if(i!=9) printf("%c                     %c\n", 186, 186);
	}
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	logros(vector, score, coordenadas);
	coordenadas.X = 25;
	coordenadas.Y = 6;
	posicion(hconsole, coordenadas);
	cout << "Movimientos: " << movimientos;
	coordenadas.X = 25;
	coordenadas.Y = 7;
	posicion(hconsole, coordenadas);
	cout << "Score: " << score;
	coordenadas.X = 25;
	coordenadas.Y = 8;
	posicion(hconsole, coordenadas);
	cout << "ESC = SALIR";
	coordenadas.X = 25;
	coordenadas.Y = 9;
	posicion(hconsole, coordenadas);
	cout << "E = HABILIDAD";
	coordenadas.X = 25;
	coordenadas.Y = 10;
	posicion(hconsole, coordenadas);
	cout << "FLECHAS = MOVIMIENTO";
	coordenadas.X = 25;
	coordenadas.Y = 11;
	posicion(hconsole, coordenadas);
	cout << "ENTER = SELECCIONAR";
	coordenadas.X = 0;
	coordenadas.Y = 0;
	posicion(hconsole, coordenadas);
}
