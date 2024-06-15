#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Producto {
private:
    string nombre;
    double precio;
    string codigo;
    static double porcentajeDescuento;
public:
    Producto(string nombre, double precio, string codigo) : nombre(nombre), precio(precio), codigo(codigo) {}
    virtual void mostrarDetalles() = 0;
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    string getCodigo() const { return codigo; }
    static void setPorcentajeDescuento(double porcentaje) { porcentajeDescuento = porcentaje; }
    static double getPorcentajeDescuento() { return porcentajeDescuento; }
    double getPrecioConDescuento() const
    {
        return precio * (1.0 - porcentajeDescuento / 100.0);
    }
    virtual ~Producto() {}
};
double Producto::porcentajeDescuento = 10.0;
class Libros : public Producto {
private:
    string autor;
    int numPaginas;
public:
    Libros(string nombre, double precio, string codigo, string autor, int numPaginas) : Producto(nombre, precio, codigo), autor(autor), numPaginas(numPaginas) {}

    void mostrarDetalles() override
    {
        cout << "Libro: " << getNombre() << ", Precio: $" << getPrecioConDescuento() << " (Precio original: $" << getPrecio() << "), Codigo: " << getCodigo() << ", Autor: " << autor << ", Numero de Paginas: " << numPaginas << endl;
    }

    ~Libros() {}
};
class Electronicos : public Producto {
private:
    string marca;
    int garantia;
public:
    Electronicos(string nombre, double precio, string codigo, string marca, int garantia)
        : Producto(nombre, precio, codigo), marca(marca), garantia(garantia) {}

    void mostrarDetalles() override
    {
        cout << "Electronico: " << getNombre() << ", Precio: $" << getPrecioConDescuento() << " (Precio original: $" << getPrecio() << "), Codigo: " << getCodigo() << ", Marca: " << marca << ", Garantia: " << garantia << " meses" << endl;
    }
    ~Electronicos() {}
};
class Ropa : public Producto {
private:
    string talla;
    string color;
public:
    Ropa(string nombre, double precio, string codigo, string talla, string color)
        : Producto(nombre, precio, codigo), talla(talla), color(color) {}

    void mostrarDetalles() override
    {
        cout << "Ropa: " << getNombre() << ", Precio: $" << getPrecioConDescuento() << " (Precio original: $" << getPrecio() << "), Codigo: " << getCodigo() << ", Talla: " << talla << ", Color: " << color << endl;
    }
    ~Ropa() {}
};
class GestorInventario {
private:
    vector<Producto *> productos;
public:
    GestorInventario(vector<Producto *> _prodcutos) : productos(_prodcutos){};
    double getValorTotal() const
    {
        double valorTotal = accumulate(productos.begin(), productos.end(), 0.0, [](double total, const Producto *producto)
            { return total + producto->getPrecio(); });
        return valorTotal;
    }
    double getValorTotalConDescuento() const
    {
        double valorTotal = accumulate(productos.begin(), productos.end(), 0.0, [](double total, const Producto *producto)
            { return total + producto->getPrecioConDescuento(); });
        return valorTotal;
    }
    ~GestorInventario()
    {
        for (Producto *producto : productos)
        {
            delete producto;
        }
    }
};
int main() {
    vector<Producto *> productos;
    productos.push_back(new Libros("El Quijote", 15.99, "L001", "Miguel de Cervantes", 1023));
    productos.push_back(new Electronicos("iPhone", 999.99, "E001", "Apple", 24));
    productos.push_back(new Ropa("Camiseta", 19.99, "R001", "M", "Rojo"));
    for (Producto *producto : productos)
    {
        producto->mostrarDetalles();
    }
    GestorInventario inventario(productos);
    cout << "Valor total del inventario: $" << inventario.getValorTotal() << endl;
    Producto::setPorcentajeDescuento(20);
    cout << "Valor total del inventario con descuento (" << Producto::getPorcentajeDescuento() << "%): $" << inventario.getValorTotalConDescuento() << endl;
    return 0;
}