#include <iostream>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#define color SetConsoleTextAttribute

HANDLE hconsole = GetStdHandle( STD_OUTPUT_HANDLE );
using namespace std;

int aleatorio()
{
	return (1 + rand() % 5) ;
}

void vaciar_logros(int vector[5]){
	for(int i= 0 ; i<5 ; i++) vector[i] = 0;
}

void menu_habilidades(int eleccion)
{
	system("cls");
	cout << "+----------------------+" << endl;
	if(eleccion == 1){
		cout << "|  Eliminar una fila   |" << endl << "|";
		color(hconsole, 240);
		cout << " >Eliminar una columna";
		color(hconsole, 15);
		cout << "|" << endl;
	}else{
		cout << "|";
		color(hconsole, 240);
		cout << " >Eliminar una fila   ";
		color(hconsole, 15);
		cout << "|" << endl << "|  Eliminar una columna|" << endl;
	}
	cout << "+----------------------+" << endl;
}

void logros(int vector[5], int &score)
{
	int vec2[5];
	
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
{
	for(int i=0; i<10 ; i++)
	{
		for(int j=0 ; j<10 ; j++)
		{
			if(tablero[i][j] == 0) tablero[i][j] = aleatorio();
		}
	}
}

void vaciar(int tablero[10][10])
{
	for(int i=0; i<10 ; i++)
	{
		for(int j=0; j<10 ; j++)
		{
			tablero[i][j] = 0;
		}
	}
	cargar(tablero);
}

void romperCaramelos(int tablero[10][10], int &score, int record[5]) {
    bool hayRupturas = false, hayRuptura[2] = {true, true};
    
    while(hayRuptura[0] || hayRuptura[1])
    {
    	// Ruptura horizontal
   		for (int i = 0; i < 10; i++) {
        	for (int j = 2; j < 10; j++) {
            	if (tablero[i][j] == tablero[i][j-1] && tablero[i][j] == tablero[i][j-2]) {
                	record[tablero[i][j]-1] = record[tablero[i][j]-1] + 1;
					tablero[i][j] = 0;
                	tablero[i][j-1] = 0;
                	tablero[i][j-2] = 0;
                	hayRupturas = true;
                	hayRuptura[0] = true;
                	score  = score + 30;
            	}else hayRuptura[0] = false;
        	}
    	}
    
    	// Ruptura vertical
    	for (int j = 0; j < 10; j++) {
        	for (int i = 2; i < 10; i++) {
            	if (tablero[i][j] == tablero[i-1][j] && tablero[i][j] == tablero[i-2][j]) {
            		record[tablero[i][j]-1] = record[tablero[i][j]-1] + 1;
                	tablero[i][j] = 0;
                	tablero[i-1][j] = 0;
                	tablero[i-2][j] = 0;
                	hayRupturas = true;
                	hayRuptura[1] = true;
                	score = score + 30;
            	}else hayRuptura[1] = false;
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

void mostrar(int tablero[10][10], int cursi, int cursj, int cursi1, int cursj1, int movimientos, int &score, int vector[5])
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
	logros(vector, score);
	cout << "Movimientos: " << movimientos << endl;
	cout << "Score: " << score << endl;
}
