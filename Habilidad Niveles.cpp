#include <iostream>
using namespace std;

int Nivel = 0;
string Poder[7] = {"Nivel 1: Elimina un espacio", "Nivel 2: Elimina 3 espacios juntos en una fila", "Nivel 3: Elimina un 3x3 utilizando como centro el espacio seleccionado", "Nivel 4: Elimina una fila completa", "Nivel 5: Elimina 3 filas juntas, usando como centro la fila del espacio seleccionado", "Nivel 6: Elimina 5 filas juntas, usando como centro la fila del espacio seleccionado", "Nivel 7: Borra todo el tablero"};

/* Tipos de PowerUp:
		Nivel 1: Elimina un espacio
		Nivel 2: Elimina 3 espacios juntos en una fila
		Nivel 3: Elimina un 3x3 utilizando como centro el espacio seleccionado
		Nivel 4: Elimina una fila completa
		Nivel 5: Elimina 3 filas juntas, usando como centro la fila del espacio seleccionado
		Nivel 6: Elimina 5 filas juntas, usando como centro la fila del espacio seleccionado
		Nivel 7: Borra todo el tablero
*/
// Funcion con el cambio de niveles
void PowerUp(int scoring){
	switch (scoring){
		case 2: // Igualamos Nivel a 1 y cambia el Poder
			Nivel=1;
			Poder[Nivel];
			cout << endl << Poder[Nivel] << endl << Nivel;
			break;
		case 5: // Igualamos Nivel a 2 y cambia el Poder
			Nivel=2;
			Poder[Nivel];
			cout << endl << Poder[Nivel] << endl << Nivel;
			break;
		case 9: // Igualamos Nivel a 3 y cambia el Poder
			Nivel=3;
			Poder[Nivel];
			cout << endl << Poder[Nivel] << endl << Nivel;
			break;
		case 14: // Igualamos Nivel a 4 y cambia el Poder
			Nivel=4;
			Poder[Nivel];
			cout << endl << Poder[Nivel] << endl << Nivel;
			break;
		case 20: // Igualamos Nivel a 5 y cambia el Poder
			Nivel=5;
			Poder[Nivel];
			cout << endl << Poder[Nivel] << endl << Nivel;
			break;
		case 26: // Igualamos Nivel a 6 y cambia el Poder
			Nivel=6;
			Poder[Nivel];
			cout << endl << Poder[Nivel] << endl << Nivel;
			break;
	}
}


