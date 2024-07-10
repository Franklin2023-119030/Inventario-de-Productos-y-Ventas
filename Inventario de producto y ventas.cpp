#include <iostream>
using namespace std;

const int maxProductos = 100;
const int maxVentas = 100;

struct Producto {
    string nombre;
    float precio;
};

struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

void agregarProducto(Producto productos[], int &totalProductos) {
    if (totalProductos >= maxProductos) {
        cout << "\nNo se pueden agregar mas productos, se ha alcanzado el limite." << endl;
        return;
    }
    cout << "\nIntroduce el nombre del producto: ";
    cin >> productos[totalProductos].nombre;
    cout << "Introduce el precio del producto: ";
    cin >> productos[totalProductos].precio;
    cout << "Producto agregado exitosamente." << endl;
    cout << endl;
    totalProductos++;
}

void agregarVenta(Venta ventas[], int &totalVentas, int &idVentaActual) {
    if (totalVentas >= maxVentas) {
        cout << "\nNo se pueden registrar mas ventas, se ha alcanzado el limite." << endl;
        return;
    }
    ventas[totalVentas].idVenta = idVentaActual++;
    cout << "\nIntroduce el nombre del producto vendido: ";
    cin >> ventas[totalVentas].producto;
    cout << "Introduce la cantidad vendida: ";
    cin >> ventas[totalVentas].cantidad;
    cout << "Introduce el precio total de la venta: ";
    cin >> ventas[totalVentas].precioTotal;
    cout << endl;
    totalVentas++;
}

int main() {
    Producto productos[maxProductos];
    Venta ventas[maxVentas];
    int totalProductos = 0;
    int totalVentas = 0;
    int idVentaActual = 1;
    int opcion;

    do {
        cout << "Menu de gestión de inventario y ventas" << endl;
        cout << "1. Agregar un nuevo producto" << endl;
        cout << "2. Registrar una venta" << endl;
        cout << "3. Salir del programa" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProducto(productos, totalProductos);
                break;
            case 2:
                agregarVenta(ventas, totalVentas, idVentaActual);
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no válida, selecciona una opcion del 1 al 3." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}
