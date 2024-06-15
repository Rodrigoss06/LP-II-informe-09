#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Figura {
public:
    virtual double calcularArea() = 0;
    virtual string getNombreClase()=0;
};
class Circulo: public Figura {
private:
    double radio;
public:
    Circulo(double radio) : radio(radio) {}

    double calcularArea() override {
        return (3.1416)* pow(radio,2);
    }
    string getNombreClase() override{
        return "Circulo";
    }
};
class Rectangulo : public Figura {
private:
    double largo;
    double ancho;
    
public:
    Rectangulo(double largo, double ancho): largo(largo),ancho(ancho) {}
    double calcularArea() override {
        return largo*ancho;
    }
    string getNombreClase() override{
        return "Rectangulo";
    }
};
class Triangulo : public Figura {
private:
    double base;
    double altura;
public:
    Triangulo(double base, double altura): base(base),altura(altura) {}
    double calcularArea() override {
        return (base*altura)/2;
    }
    string getNombreClase() override{
        return "Triangulo";
    }

};
int main(){
    Figura* arreglo[3]={new Circulo(2),new Rectangulo(4,5),new Triangulo(3,4)};
    for (int i=0;i<3;i++){
        cout<<"El area del "<<arreglo[i]->getNombreClase()<<" es: "<< arreglo[i]->calcularArea()<<endl;
    }
    return 0;
}