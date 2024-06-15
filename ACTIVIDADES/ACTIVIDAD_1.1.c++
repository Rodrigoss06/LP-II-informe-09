#include <iostream>
using namespace std;
//temprano
class Animal{
    public:
    void hacer_sonido(){
        cout << "el animal hace un sonido" << endl;
    }
};
class Perro : public Animal{
    public:
    void hacer_sonido(){
        cout << "el perro ladra" << endl;
    }
};
int main(){
    Animal*mi_mascota = new Perro();
    mi_mascota->hacer_sonido();
    delete mi_mascota;
    return 0;
}