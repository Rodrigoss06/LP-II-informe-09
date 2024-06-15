#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;
class Personaje {
public:
    virtual ~Personaje() {}
    virtual void atacar() const = 0;
    virtual void defender() const = 0;
    virtual void usarHabilidadEspecial() const = 0;
};
class Guerrero : public Personaje {
public:
    void atacar() const override {
        cout << "El Guerrero ataca con su espada!" << endl;
    }
    
    void defender() const override {
        cout << "El Guerrero se defiende con su escudo!" << endl;
    }
    
    void usarHabilidadEspecial() const override {
        cout << "El Guerrero usa Furia de Batalla!" << endl;
    }
};
class Mago : public Personaje {
public:
    void atacar() const override {
        cout << "El Mago lanza un hechizo de fuego!" << endl;
    }
    
    void defender() const override {
        cout << "El Mago crea un escudo mágico!" << endl;
    }
    
    void usarHabilidadEspecial() const override {
        cout << "El Mago usa Bola de Fuego!" << endl;
    }
};
class Arquero : public Personaje {
public:
    void atacar() const override {
        cout << "El Arquero dispara una flecha!" << endl;
    }
    
    void defender() const override {
        cout << "El Arquero esquiva el ataque!" << endl;
    }
    
    void usarHabilidadEspecial() const override {
        cout << "El Arquero usa Flecha Explosiva!" << endl;
    }
};
int main() {
    vector<unique_ptr<Personaje>> personajes;
    personajes.push_back(make_unique<Guerrero>());
    personajes.push_back(make_unique<Mago>());
    personajes.push_back(make_unique<Arquero>());
    for (const auto& personaje : personajes) {
        personaje->atacar();
        personaje->defender();
        personaje->usarHabilidadEspecial();
        cout << endl;
    }
    return 0;
}
