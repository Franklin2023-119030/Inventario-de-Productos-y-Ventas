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

void buscarProducto(Producto productos[], int totalProductos) {
    if (totalProductos == 0) {
        cout << "\nNo hay productos registrados." << endl;
        return;
    }
    string nombreBuscado;
    cout << "\nIngrese el nombre del producto a buscar: ";
    cin >> nombreBuscado;
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == nombreBuscado) {
            cout << "\nProducto encontrado:" << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Precio: " << productos[i].precio << endl;
            cout << endl;
            return;
        }
    }
    cout << "\nProducto no encontrado." << endl;
}

void actualizarProducto(Producto productos[], int totalProductos) {
    if (totalProductos == 0) {
        cout << "\nNo hay productos registrados." << endl;
        return;
    }
    string nombreActualizacion;
    cout << "\nIngrese el nombre del producto a actualizar: ";
    cin >> nombreActualizacion;
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == nombreActualizacion) {
            cout << "\nProducto encontrado:" << endl;
            cout << "Nombre actual: " << productos[i].nombre << endl;
            cout << "Precio actual: " << productos[i].precio << endl;

            cout << "\nIngrese el nuevo nombre del producto: ";
            cin >> productos[i].nombre;
            cout << "Ingrese el nuevo precio del producto: ";
            cin >> productos[i].precio;

            cout << "\nProducto actualizado exitosamente." << endl;
            cout << endl;
            return;
        }
    }
    cout << "\nProducto no encontrado." << endl;
}

void eliminarProducto(Producto productos[], int &totalProductos) {
    if (totalProductos == 0) {
        cout << "\nNo hay productos registrados." << endl;
        return;
    }
    string nombreEliminar;
    cout << "\nIngrese el nombre del producto a eliminar: ";
    cin >> nombreEliminar;

    int indiceEliminar = -1;
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == nombreEliminar) {
            indiceEliminar = i;
            break;
        }
    }

    if (indiceEliminar == -1) {
        cout << "\nProducto no encontrado." << endl;
        return;
    }

    for (int i = indiceEliminar; i < totalProductos - 1; i++) {
        productos[i] = productos[i + 1];
    }

    totalProductos--;
    cout << "\nProducto eliminado correctamente." << endl;
}

void listarVentas(const Venta ventas[], int totalVentas) {
    if (totalVentas == 0) {
        cout << "\nNo hay ventas registradas." << endl;
        return;
    }
    cout << "\nLista de ventas realizadas:" << endl;
    for (int i = 0; i < totalVentas; i++) {
        cout << "Venta " << (i + 1) << ": " << endl;
        cout << "ID de venta: " << ventas[i].idVenta << endl;
        cout << "Producto vendido: " << ventas[i].producto << endl;
        cout << "Cantidad vendida: " << ventas[i].cantidad << endl;
        cout << "Precio total: " << ventas[i].precioTotal << endl;
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
        cout << "4. Buscar un producto por nombre" << endl;
        cout << "5. Actualizar datos de un producto" << endl;
        cout << "6. Eliminar un producto" << endl;
        cout << "7. Listar ventas realizadas" << endl;
        cout << "8. Salir del programa" << endl;
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
                buscarProducto(productos, totalProductos);
                break;
            case 5:
                actualizarProducto(productos, totalProductos);
                break;
            case 6:
                eliminarProducto(productos, totalProductos);
                break;
            case 7:
                listarVentas(ventas, totalVentas);
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida, selecciona una opción del 1 al 8." << endl;
                break;
        }
    } while (opcion != 8);

    return 0;
}
