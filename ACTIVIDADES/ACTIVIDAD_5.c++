#include <iostream>
#include <cmath>
using namespace std;
class FiguraGeometrica {
public:
    virtual double calcularArea() = 0;
    virtual double calcularPerimetro() = 0;
    virtual ~FiguraGeometrica() {} 
};
class Circulo : public FiguraGeometrica {
private:
    double radio;
public:
    Circulo(double radio) : radio(radio) {}
    double calcularArea() override {
        return radio * radio * M_PI;
    }
    double calcularPerimetro() override {
        return 2 * M_PI * radio;
    }
};
class Rectangulo : public FiguraGeometrica {
private:
    double base;
    double altura;
public:
    Rectangulo(double base, double altura) : base(base), altura(altura) {}
    double calcularArea() override {
        return base * altura;
    }
    double calcularPerimetro() override {
        return 2 * (base + altura);
    }
};
class Triangulo : public FiguraGeometrica {
private:
    double lado1;
    double lado2;
    double lado3;
public:
    Triangulo(double lado1, double lado2, double lado3) : lado1(lado1), lado2(lado2), lado3(lado3) {}
    double calcularArea() override {
        double s = calcularPerimetro() / 2.0;
        return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }
    double calcularPerimetro() override {
        return lado1 + lado2 + lado3;
    }
};
int main() {
    FiguraGeometrica* figuras[3];
    figuras[0] = new Circulo(5.0);
    figuras[1] = new Rectangulo(4.0, 6.0);
    figuras[2] = new Triangulo(3.0, 4.0, 5.0);

    for (int i = 0; i < 3; i++) {
        cout << "Figura " << i + 1 << ":" << endl;
        cout << "Area: " << figuras[i]->calcularArea() << endl;
        cout << "Perimetro: " << figuras[i]->calcularPerimetro() << endl;
    }
    for (int i = 0; i < 3; i++) {
        delete figuras[i];
    }
    return 0;
}