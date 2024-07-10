#include <iostream>
using namespace std;

const int limiteProductos=100;
const int limiteVentas=100;

struct Producto{
	string nombre;
	float precio;
};
struct Venta{
	int idVenta;
	string producto;
	int cantidad;
    float precioTotal;
};

void registrarProducto(Producto articulo[],int &numeroProducto){
	if (numeroProducto>=limiteProductos){
        cout<<"\nlimite de productos alcanzado, no es posible registrar mas productos"<<endl;
        return;
	}
	cout<<"\nIngrese el nombre del producto: ";
	cin>>articulo[numeroProducto].nombre;
	cout<<"Ingrese el precio del producto: ";
	cin>>articulo[numeroProducto].precio;
	cout<<"Producto registrado con exito"<<endl;
	cout<<endl;
	numeroProducto++;
}
int main(){
	Producto articulo[limiteProductos];
	Venta transaccion[limiteVentas];
	int numeroProducto=0;
	int opcion;
	do{
		cout<<"Menu de inventario y ventas"<<endl;
		cout<<"1. Registrar un nuevo producto"<<endl;
		cout<<"2. Salir del programa"<<endl;
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		switch (opcion){
			case 1:
				registrarProducto(articulo, numeroProducto);
				break;
			default:
				cout<<"Opcion no valida, seleccione una opcion del 1 al 9."<<endl;
				break;
		}
	}while(opcion!=9);
	return 0;
}
