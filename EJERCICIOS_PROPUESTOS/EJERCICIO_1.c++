#include <iostream>
#include <cmath>
using namespace std;
class Figura {
public:
    virtual double calcularArea() = 0;
    virtual double calcularPerimetro()=0;
    virtual void getInformacion()=0;
};
class Circulo: public Figura {
private:
    double radio;
public:
    Circulo(double radio) : radio(radio) {}

    double calcularArea() override {
        return (3.1416)* pow(radio,2);
    }
    double calcularPerimetro() override{
        return 2 *(3.1416)*(radio);
    }
    void getInformacion() override{
        cout << "Circulo con radio: " << radio << endl;
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
    double calcularPerimetro() override{
        return 2 *largo+2*ancho;
    }
    void getInformacion() override{
        cout << "Rectangulo con largo: " << largo << " y ancho: "<< ancho <<endl;
    }
};
class Triangulo : public Figura {
private:
    double lado1;
    double lado2;
    double lado3;
    double altura;
public:
    Triangulo(double lado1,double lado2,double lado3, double altura): lado1(lado1), lado2(lado2),lado3 (lado3),altura(altura) {}
    double calcularArea() override {
        double s=(lado1+lado2+lado3)/2; 
        return sqrt(s*(s-lado1)*(s-lado2)*(s-lado3));
    }
    double calcularPerimetro() override{
        return lado1 +lado2 + lado3 ;
    }
    void getInformacion() override{
        cout << "Triangulo con lado 1: " << lado1 << ", lado 2: "<<lado2<<", lado 3: "<< lado3 <<" y altura: "<<altura<<endl;
        }
};
class Cuadrado : public Figura {
private:
    double lado;
public:
    Cuadrado(double lado): lado(lado) {}
    double calcularArea() override {
        return pow(lado,2); 
    }
    double calcularPerimetro() override{
        return 4*lado;
    }
    void getInformacion() override{
        cout << "Cuadrado con lado: " << lado <<endl;
        }
};
class Pentagono : public Figura {
private:
    double lado;
    double apotema;
public:
    Pentagono(double lado, double apotema): lado(lado), apotema(apotema) {}
    double calcularArea() override {
        return ((5*lado)*apotema)/2; 
    }
    double calcularPerimetro() override{
        return 5*lado;
    }
    void getInformacion() override{
        cout << "Pentagono con lado: " << lado << " apotema: "<<apotema<<endl;
        }
};
void menu(){
    cout<<"-------AREA Y PERIMETRO-------"<<endl;
    cout<<"1.Circulo"<<endl;
    cout<<"2.Rectangulo"<<endl;
    cout<<"3.Triangulo"<<endl;
    cout<<"4.Cuadrado"<<endl;
    cout<<"5.Pentagono"<<endl;
    cout<<"6.Salir"<<endl;
}
int main(){
    int opc;
    double valor1,valor2,valor3,valor4;
    bool h=true;
    do{
        menu();
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        if (opc==1){
            cout<<"Ingrese el radio del circulo:";
            cin>>valor1;
            Figura* figura1 = new Circulo(valor1);
            figura1->getInformacion();
            cout << "El area del circulo es: " << figura1->calcularArea() << endl;
            cout << "El perimetro del circulo es: " << figura1->calcularPerimetro() << endl;

        }
        if (opc==2){
            cout<<"Ingrese el largo y ancho del rectangulo, respectivamente:";
            cin>>valor1;
            cin>>valor2;
            Figura* figura2 = new Rectangulo(valor1,valor2);
            figura2->getInformacion();
            cout << "El area del rectangulo es: " << figura2->calcularArea() << endl;
            cout << "El perimetro del rectangulo es: " << figura2->calcularPerimetro() <<endl;
        }
        if (opc==3){
            cout<<"Ingrese los lados del triangulo:";
            cin>>valor1;
            cin>>valor2;
            cin>>valor3;
            cout<<"Ingrese la altura del triangulo:";
            cin>>valor4;
            Figura* figura3 = new Triangulo(valor1,valor2,valor3,valor4);
            figura3->getInformacion();
            cout << "El area del triangulo es: " << figura3->calcularArea() << endl;
            cout << "El perimetro del triangulo es: " << figura3->calcularPerimetro() << endl;
        }
        if (opc==4){
            cout<<"Ingrese el lado del cuadrado:";
            cin>>valor1;
            Figura* figura4 = new Cuadrado(valor1);
            figura4->getInformacion();
            cout << "El area del cuadrado es: " << figura4->calcularArea() << endl;
            cout << "El perimetro del cuadrado es: " << figura4->calcularPerimetro() << endl;
        }
        if (opc==5){
            cout<<"Ingrese un lado y el apotema del pentagono, respectivamente:";
            cin>>valor1;
            cin>>valor2;
            Figura* figura5 = new Pentagono(valor1,valor2);
            figura5->getInformacion();
            cout << "El area del pentagono es: " << figura5->calcularArea() << endl;
            cout<< "El perimetro del pentagono es: " << figura5->calcularPerimetro() << endl;
        }
        if(opc==6){
            cout<<"Saliendo del programa";
            h=false;
        }
    }while (h);
    return 0;
}