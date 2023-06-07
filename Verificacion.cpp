#include <iostream>
using namespace std;

int fila, columna, tablero[8][10];

bool verificacion (){
	for (columna=0; columna<10; columna++){
		if (tablero[fila][columna]!=1){
			return false;
		}
	}
	return true;
}

int main(){
	for (fila = 0; fila < 8; fila++) {
        if (verificacion()) {
            cout << "La fila " << fila << " contiene solo unos." << endl;
        } else {
            cout << "La fila " << fila << " contiene elementos diferentes de uno." << endl;
        }
    }
}
