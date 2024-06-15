#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Empleado {
public:
    virtual ~Empleado() = default;
    virtual double calcular_salario() const = 0;
    virtual void mostrar_informacion() const = 0;
};
class Asalario : public Empleado {
private:
    double salario_mensual;
public:
    Asalario(double salario) : salario_mensual(salario) {}
    double calcular_salario() const override {
        return salario_mensual;
    }
    void mostrar_informacion() const override {
        cout << "Empleado asalariado: Salario mensual = " << salario_mensual << endl;
    }
};
class Por_hora : public Empleado {
private:
    double tarifa_de_hora;
    int horas_trabajadas;
public:
    Por_hora(double tarifa, int horas) : tarifa_de_hora(tarifa), horas_trabajadas(horas) {}
    double calcular_salario() const override {
        return tarifa_de_hora * horas_trabajadas;
    }
    void mostrar_informacion() const override {
        cout << "Empleado por hora: Tarifa por hora = " << tarifa_de_hora << ", Horas trabajadas = " << horas_trabajadas << endl;
    }
};
class Comisionista : public Empleado {
private:
    double ventas_mensuales;
    double tasa_de_comision;
public:
    Comisionista(double ventas, double tasa) : ventas_mensuales(ventas), tasa_de_comision(tasa) {}
    double calcular_salario() const override {
        return ventas_mensuales * tasa_de_comision;
    }
    void mostrar_informacion() const override {
        cout << "Empleado comisionista: Ventas mensuales = " << ventas_mensuales << ", Tasa de comision = " << tasa_de_comision << endl;
    }
};
int main() {
    using Empleados = vector<Empleado*>;
    Empleados empleados;
    int opcion;
    do {
        cout << "ingresar el tipo de empleado a agregar (1: Asalariado, 2: Por Hora, 3: Comisionista, 0: Salir): ";
        cin >> opcion;
        
        if (opcion == 1) {
            double salario_mensual;
            cout << "ingresar el salario mensual: ";
            cin >> salario_mensual;
            empleados.push_back(new Asalario(salario_mensual));
        } 
        else if (opcion == 2) {
            double tarifa_hora;
            int horas_trabajadas;
            cout << "ingresar la tarifa por hora: ";
            cin >> tarifa_hora;
            cout << "ingresar las horas trabajadas: ";
            cin >> horas_trabajadas;
            empleados.push_back(new Por_hora(tarifa_hora, horas_trabajadas));
        } 
        else if (opcion == 3) {
            double ventas_mensuales, tasa_de_comision;
            cout << "ingresar las ventas mensuales: ";
            cin >> ventas_mensuales;
            cout << "ingresar la tasa de comision: ";
            cin >> tasa_de_comision;
            empleados.push_back(new Comisionista(ventas_mensuales, tasa_de_comision));
        }
    } while (opcion != 0);
    cout << "\n--------- Informacion de Empleados --------\n";
    for (const auto& empleado : empleados) {
        empleado->mostrar_informacion();
        cout << "Salario calculado es: " << empleado->calcular_salario() << endl;
        cout << "---------------" << endl;
        delete empleado; 
    }
    return 0;
}