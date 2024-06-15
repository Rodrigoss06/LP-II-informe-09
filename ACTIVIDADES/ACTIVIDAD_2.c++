#include <iostream>
using namespace std;

class Calculadora {
public:
    int sumar(int a, int b) {
        return a + b;
    }

    double sumar(double a, double b) {
        return a + b;
    }

    int sumar(int a, int b, int c) {
        return a + b + c;
    }
};
int main() {
    Calculadora calculadora;
    int opcion;
    cout << "Seleccione la operacion que desea realizar:" << endl;
    cout << "1. Suma de dos enteros" << endl;
    cout << "2. Suma de dos doubles" << endl;
    cout << "3. Suma de tres enteros" << endl;
    cout << "Ingrese un numero de la opciones: ";
    cin >> opcion;
    switch (opcion) {
        case 1: {
            int a, b;
            cout << "Ingrese el primer entero: ";
            cin >> a;
            cout << "Ingrese el segundo entero: ";
            cin >> b;
            int resultado = calculadora.sumar(a, b);
            cout << "La suma de " << a << " y " << b << " es: " << resultado << endl;
            break;
        }
        case 2: {
            double a, b;
            cout << "Ingrese el primer double: ";
            cin >> a;
            cout << "Ingrese el segundo double: ";
            cin >> b;
            double resultado = calculadora.sumar(a, b);
            cout << "La suma de " << a << " y " << b << " es: " << resultado << endl;
            break;
        }
        case 3: {
            int a, b, c;
            cout << "Ingrese el primer entero: ";
            cin >> a;
            cout << "Ingrese el segundo entero: ";
            cin >> b;
            cout << "Ingrese el tercer entero: ";
            cin >> c;
            int resultado = calculadora.sumar(a, b, c);
            cout << "La suma de " << a << ", " << b << " y " << c << " es: " << resultado << endl;
            break;
        }
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
    return 0;
}