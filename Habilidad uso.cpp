#include <iostream>
using namespace std;
    
void UsoHabilidad(int Nivel, int tecla, int fila, int columna, int tablero[10][10], int mov_restantes)
{
	int x, y;
	bool flag;
	if (tecla = 99 && mov_restantes==0); // Para poder usar la habilidad debe tocar la letra c y que el contador de habilidades sea 0
	{
		switch (Nivel)
		{
			case 0: //Al no tener habilidades ponemos flag en 1
				flag=1;
				break;
			case 1: 
				flag=0; //Ponemos flag en 0 dando a entender que ya tiene una habilidad
				x=fila; //Guardamos la posicion de la fila en la que se encuentra en x
				y=columna; //Guardamos la posicion de la columna en la que se encuentra en y
				tablero[x][y]=0; //Elimina la ficha que se encuentre en la posicion dada x las variables x e y
				break;
			case 2:
				y=columna; //Guardamos la posicion de la columna en la que se encuentra en y
				x=fila; //Guardamos la posicion de la fila en la que se encuentra en x
				for(x=fila-1;x<fila+2<x++) //Hacemos el for para que valla dsd la posicion a la izquierda de x hacia la que esta a su derecha
				{
					tablero[x][y]=0; //Guarda 0 en la posicion que marca x e y
				}
				break;
			case 3:
				y=columna; //Guardamos la posicion de la columna en la que se encuentra en y
				x=fila; //Guardamos la posicion de la fila en la que se encuentra en x
				//Este for sirve para que todas las posiciones alrededor de la que se selocciono(esta incluida) se vuelvan 0
				for(y=columna-1;y<columna+2;y++)
				{
					for(x=fila-1;x<fila+2;x++)
					{
						tablero[x][y]=0;
					}
				}
				break;
			case 4:
				x=fila; //Guardamos la posicion de la columna en la que se encuentra en x
				for(y=0;y<10;y++)
				{
					tablero[x][y]=0; //Elimina toda la fila en la que se encuentra la ficha seleccionada
				}
				break;
			case 5:
				for(x=fila-1;x<fila+2;x++) // Recorre la fila de arriba, la fila en la que se encuentra la ficha y la fila de abajo
				{
					for(y=0;y<10;y++) // Recorre las columnas desde la primera hasta la ultima
					{
						tablero[x][y]=0; //Elimina toda la fila en la que se encuentra la ficha seleccionada y la fila de arriba y de abajo
					}
				}
				break;
			case 6:
				for(x=fila-2;x<fila+3;x++) // Recorre dos filas de arriba, la fila en la que se encuentra la ficha y dos filas de abajo
				{
					for(y=0;y<10;y++) // Recorre las columnas desde la primera hasta la ultima
					{
						tablero[x][y]=0; //Elimina toda la fila en la que se encuentra la ficha seleccionada, y dos filas superiores y dos inferiores
					}
				}
				break;
			case 7:
				for(x=0;x<10;x++) //Recorre todas las filas
				{
					for(y=0;y<10:y++) // Recorre todas las columnas
					{
						tablero[x][y]=0; //Elimina todo el tablero
					}
				}
				break;
		}
	}
	else if (mov_restantes<0) // If para ir restando movimientos
	{
		mov_restantes--; // Resta de movimientos
	}
}

int main(){
	int Nivel=0, mov_restantes=0, fila, columna, tablero[10][10];
	char tecla = 'c';
    int valor = static_cast<int>(tecla); // Pasar de char a valor numerico una letra
    UsoHabilidad(Nivel, tecla, mov_restantes, fila, columna, tablero[10][10]);
}
