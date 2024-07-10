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
        cout << "\nNo se pueden agregar más productos, se ha alcanzado el límite." << endl;
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
        cout << "\nNo se pueden registrar más ventas, se ha alcanzado el límite." << endl;
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

void listarProductos(const Producto productos[], int totalProductos) {
    if (totalProductos == 0) {
        cout << "\nNo hay productos registrados." << endl;
        return;
    }
    cout << "\nLista de productos registrados:" << endl;
    for (int i = 0; i < totalProductos; i++) {
        cout << "Producto " << (i + 1) << ": " << endl;
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Precio: " << productos[i].precio << endl;
        cout << endl;
    }
}

int main() {
    Producto productos[maxProductos];
    Venta ventas[maxVentas];
    int totalProductos = 0;
    int totalVentas = 0;
    int idVentaActual = 1;
    int opcion;

    do {
        cout << "Menú de gestión de inventario y ventas" << endl;
        cout << "1. Agregar un nuevo producto" << endl;
        cout << "2. Registrar una venta" << endl;
        cout << "3. Listar productos registrados" << endl;
        cout << "4. Salir del programa" << endl;
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
                listarProductos(productos, totalProductos);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida, selecciona una opción del 1 al 4." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}
