// Calculadora.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "conio.h"//Para habilitar enyrada de datos en la terminal
#include "stdio.h"
#include "stdlib.h"
#include "iostream"

using namespace std;

float sumar(float a, float b){//luego hay que ponerlo como flotante
	float result = 0.00;
	__asm {
		FLD dword ptr[a] // guardo temporamente en el stack el valor flotante de a
		FLD dword ptr[b]// guardo temporamente en el stack el valor flotante de b
		FADD // sumo los ultimos dos valores guardados en el stack
		FSTP dword ptr[result] // traigo el resulto y lo alamaceno en la variable
	}
	return result;
}

float resta(float a, float b) {
	float result;
	__asm {
		FLD DWORD PTR[a] // guardo temporamente en el stack el valor flotante de a
		FLD DWORD PTR[b] // guardo temporamente en el stack el valor flotante de b
		FSUB // resto los ultimos dos valores guardados en el stack
		FSTP DWORD PTR[result]// traigo el resulto y lo alamaceno en la variable
	}
	return result;
}

float multiplicacion(float a, float b) {
	float result;
	__asm {
		FLD DWORD PTR[a]
		FLD DWORD PTR[b]
		FMUL
		FSTP DWORD PTR[result]
	}
	return result;
}

float division(float a, float b) {
	float cero = 0.0;
	float result;
	__asm {
		FLD DWORD PTR[b]
		FLD DWORD PTR[cero]
		FCOMIP ST(0), ST(1)
		JE divCero
		FLD DWORD PTR[a]
		FLD DWORD PTR[b]
		FDIV
		FSTP DWORD PTR[result]
	}
	printf("Respuesta= : %.2f\n", result);
	return 0.0;
divCero:
	cout << "|<     Division por cero     >|" << endl;
	return 0.0;
}

float raiz(float x) {
	float result;
	__asm {
		FLD DWORD PTR[x]
		FSQRT
		FSTP DWORD PTR[result]
	}
	return result;
}

float seno(float x) {
	__asm {

	}
	return 0.0;
}

float coseno(float x) {
	__asm {

	}
	return 0;
}

float tangente(float x) {
	__asm {
		
	}
	return 0;
}


	


int main()
{
menu:int op;
	float a, b;
	cout << "|   CALCULADORA CIENTIFICA    |" << endl;
	cout << "|-----------------------------|" << endl;
	cout << "| OPERACIONES SOPORTADAS:     |" << endl;
	cout << "|_____________________________|" << endl;
	cout << "|>SUMA                     1  |" << endl;
	cout << "|>RESTA                    2  |" << endl;
	cout << "|>MULTIPLICACION           3  |" << endl;
	cout << "|>DIVISION                 4  |" << endl;
	cout << "|>SENO                     5  |" << endl;
	cout << "|>COSENO                   6  |" << endl;
	cout << "|>TANGENTE                 7  |" << endl;
	cout << "|>RAIZ CUADRADA            8  |" << endl;
	cout << "|>EXPONENTE                9  |" << endl;
	cout << "|>LOG BASE 2              10  |" << endl;
	cout << "|>LOG BASE 10             11  |" << endl;
	cout << "|>e^x                     12  |" << endl;
	cout << "|>FACTORIAL               13  |" << endl;
	cout << "|DIGITE OPCION:               |" << endl;
	cout << "|_____________________________|" << endl;
	cin >> op;

	switch (op){
		case 1:
			cout << "|             SUMA            |" << endl;
			cout << "|-----------------------------|" << endl;
			cout << "| Digite primer numero:";
			cin >> a;
			cout << "| Digite segundo numero:";
			cin >> b;
			cout << "| Respuesta = " << sumar(a, b)<<endl;
			goto seguir;
		case 2:
			cout << "|            RESTA            |" << endl;
			cout << "|-----------------------------|" << endl;
			cout << "| Digite primer numero:";
			cin >> a;
			cout << "| Digite segundo numero:";
			cin >> b;
			cout << "| Respuesta = " << resta(a, b) << endl;
			goto seguir;
		case 3:
			cout << "|       MULTIPLICACION        |" << endl;
			cout << "|-----------------------------|" << endl;
			cout << "| Digite primer numero:";
			cin >> a;
			cout << "| Digite segundo numero:";
			cin >> b;
			cout << "| Respuesta = " << multiplicacion(b, a) << endl;
			goto seguir;
		case 4:
			cout << "|           DIVISION          |" << endl;
			cout << "|-----------------------------|" << endl;
			cout << "| Digite primer numero:";
			cin >> a;
			cout << "| Digite segundo numero:";
			cin >> b;
			division(a,b);
			goto seguir;
		case 5:
			cout << "|              SENO           |" << endl;
			cout << "|-----------------------------|" << endl;
			cout << "| Digite  numero:";
			cin >> a;
			cout << "| Respuesta = " << seno(a) << endl;
			goto seguir;
		case 6:
			cout << "|            COSENO           |" << endl;
			cout << "|-----------------------------|" << endl;
			cout << "| Digite  numero:";
			cin >> a;
			cout << "| Respuesta = " << coseno(a) << endl;
			goto seguir;
		case 7:
			cout << "|          TANGENTE           |" << endl;
			cout << "|-----------------------------|" << endl;
			cout << "| Digite  numero:";
			cin >> a;
			cout << "| Respuesta = " << tangente(a) << endl;
			goto seguir;
		case 8:
			cout << "|       RAIZ CUADRADA         |" << endl;
			cout << "|-----------------------------|" << endl;
			cout << "| Digite  numero:";
			cin >> a;
			cout << "| Respuesta = " << raiz(a) << endl;
			goto seguir;

		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		default:
			break;
	}

seguir:op = 0;
	cout << "|-----------------------------|" << endl;
	cout << "|Desea continuar si(1) - No(0)|" << endl;
	cin >> op;
	if (op == 1){
		goto menu;
	}
	return 0;
}

