#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;
class Animal{
    public:
    virtual void comer() const = 0;
    // {cout << "El animal come" << endl; }
    virtual void dormir()const = 0;
    // {cout << "El animal duerme" << endl;}
    virtual void moverse() const =0;
    // {cout << "El animal se mueve" << endl;}
};
class Mamifero : public Animal{
    public:
    void comer() const override{
        cout << "El mamifero come carne" << endl;
    }
    void dormir() const override{
        cout << "El mamifero duerme en una cueva" << endl;
    }
    void moverse() const override{
        cout << "El mamifero camina" << endl;
    }
};
class Ave : public Animal{
    public:
    void comer() const override{
        cout << "La ave come semillas" << endl;
    }
    void dormir() const override{
        cout << "La ave duerme en un nido" << endl;
    }
    void moverse() const override{
        cout << "La ave vuela" << endl;
    }
};
class Reptil : public Animal{
    public:
    void comer() const override{
        cout << "El reptil come insectos" << endl;
    }
    void dormir() const override{
        cout << "El reptil duerme en un agujero" << endl;
    }
    void moverse() const override{
        cout << "El reptil se arrastra" << endl;
    }
};
class SimuladorDeAnimales {
    private:
    vector<shared_ptr<Animal>> animales;
    public:
    void agregarAnimal(shared_ptr<Animal> animal) {
        animales.push_back(animal);
    }
    void simular() const {
        for (const auto& animal : animales) {
            animal->comer();
            animal->dormir();
            animal->moverse();
        }
    }
};
int main() {
    int opc;
    // Crear instancias
    shared_ptr<Animal> mamifero = make_shared<Mamifero>();
    shared_ptr<Animal> ave = make_shared<Ave>();
    shared_ptr<Animal> reptil = make_shared<Reptil>();
    SimuladorDeAnimales simulador;
    while (true){
    cout  << "Ingrese su opcion" <<endl;
    cout <<"MENU"
    <<"\n1. Agregar Mamifero"
    <<"\n2. Agregar Ave"
    <<"\n3. Agregar Reptil"
    <<"\n4. Simular"
    <<"\n5. Salir"<<endl;
    cin >> opc;
    switch (opc) {
    case 1:
        simulador.agregarAnimal(mamifero);
        break;
    case 2:
        simulador.agregarAnimal(ave);
        break;
    case 3:
        simulador.agregarAnimal(reptil);
        break;
    case 4:
        cout<<"***************************"<<endl;
        simulador.simular();
        cout<<"***************************"<<endl;
        break;
    default:
        break;
    }}    
    return 0;
}