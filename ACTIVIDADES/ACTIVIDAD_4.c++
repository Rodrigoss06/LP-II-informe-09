#include <iostream>
#include <vector>
using namespace std;
class Animal {
    public:
        virtual void hacerSonido() = 0;
};
class Perro : public Animal {
    public:
        void hacerSonido() override {
            cout << "Woof" << endl;
        }
};
class Gato : public Animal {
    public:
    void hacerSonido() override {
        cout << "Nyaaaa" << endl;
    }
};
class Vaca : public Animal {
    public:
        void hacerSonido() override {
            cout << "Muuu" << endl;
            }
};
int main()  {
        Animal *ptrObj[5]={new Gato, new Perro, new Gato, new Vaca, new Perro};
        for(int i=0; i <5; i++)
            ptrObj[i]->hacerSonido();
        return 0;
}