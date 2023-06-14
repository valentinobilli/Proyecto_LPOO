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

void romperCaramelos(int tablero[10][10], int &score) {
    bool hayRupturas = false;
    
    // Ruptura horizontal
    for (int i = 0; i < 10; i++) {
        for (int j = 2; j < 10; j++) {
            if (tablero[i][j] == tablero[i][j-1] && tablero[i][j] == tablero[i][j-2]) {
                tablero[i][j] = 0;
                tablero[i][j-1] = 0;
                tablero[i][j-2] = 0;
                hayRupturas = true;
                score  = score + 30;
            }
        }
    }
    
    // Ruptura vertical
    for (int j = 0; j < 10; j++) {
        for (int i = 2; i < 10; i++) {
            if (tablero[i][j] == tablero[i-1][j] && tablero[i][j] == tablero[i-2][j]) {
                tablero[i][j] = 0;
                tablero[i-1][j] = 0;
                tablero[i-2][j] = 0;
                hayRupturas = true;
                score = score + 30;
            }
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

void mostrar(int tablero[10][10], int cursi, int cursj, int cursi1, int cursj1, int movimientos, int score)
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
	cout << "Movimientos: " << movimientos << endl;
	cout << "Score: " << score << endl;
}
