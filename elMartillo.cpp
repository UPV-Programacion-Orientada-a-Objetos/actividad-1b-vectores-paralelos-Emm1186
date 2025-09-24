#include <iostream>
#include <string>

/*Arreglos paralelos: ocupo 4 arreglos paralelos. 
codigo = int     |codigo unico del produvto
nombre = string  |nombre del producto
stock = int      |cantidad de stock
precio = float   |precio unitario  */  

 //Aquí creé los 4 arreglos del tamañño maximo que son 100 o sea 99 índices
const int toromax = 100;
int codigo[toromax];
std :: string nombre[toromax];
int stock[toromax];
float precio[toromax];
int numProductos = 5; //because iniciamos con 5 productos

//opcion 1. Saber si existe o no
//void porque no devuelve ningun valor
void consultarProducto() {
    int cod;
    std :: cout << "\nIngrese el codigo del producto a consultar: ";
    std :: cin >> cod;

    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (codigo[i] == cod) {
            std :: cout << "\nInformacion del Producto:\n";
            std :: cout << "Codigo: " << codigo[i] << std :: endl;
            std :: cout << "Nombre: " << nombre[i] << std :: endl;
            std :: cout << "Cantidad en stock: " << stock[i] << std :: endl;
            std :: cout << "Precio: $" << precio[i] << std :: endl;
            encontrado = true;
            break;
        }
    }

    //mensaje de error, el ! convierte el valor booleano al contrario seh
    if (!encontrado) {
        std :: cout << "\nERROR: El producto con codigo " << cod << " no existe.\n";
    }
}

// Opción 2: Actualizar inventario
void actualizarInventario() {
    int cod;
    std::cout << "\nIngrese el codigo del producto a actualizar: ";
    std::cin >> cod;

    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (codigo[i] == cod) {
            std::cout << "Producto encontrado: " << nombre[i] << std::endl;
            std::cout << "Cantidad actual del stock: " << stock[i] << std::endl;

            int newCantidad;
            std::cout << "Ingrese una nueva cantidad del stock: ";
            std::cin >> newCantidad;

            stock[i] = newCantidad;  // aquí se actualiza
            std::cout << "Inventario actualizado correctamente.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        std::cout << "El producto con codigo " << cod << " no existe en el inventario.\n";
    }
}



int main() {
   
    //Los 5 productos que pide que inicialicemos
    codigo[0] = 101;
    nombre[0] = "Taladro electrico";
    stock[0] = 20;
    precio[0] = 700;

    codigo[1] = 102;
    nombre[1] = "Cinta metrica(5 m)";
    stock[1] = 35;
    precio[1] = 70;

    codigo[2] = 103;
    nombre[2] = "Serrucho";
    stock[2] = 40;
    precio[2] = 140;

    codigo[3] = 104;
    nombre[3] = "Mascarilla de proteccion";
    stock[3] = 50;
    precio[3] = 30;

    codigo[4] = 105;
    nombre[4] = "Multicontacto";
    stock[4] = 70;
    precio[4] = 80;

    int opcion; //para la wea del menu
    //Un do-while para que se repita hasta salir 
    do {
        std :: cout << "\n---Bienvenido a Ferreteria el Martillo---\n";
        std :: cout << "1. Consultar un producto\n";
        std :: cout << "2. Actualizar inventario\n";
        std :: cout << "3. Generar reporte completo\n";
        std :: cout << "4. Encontrar el producto mas caro\n";
        std :: cout << "5. Salir\n";
        std :: cout << "Elige una opcion: ";
        std :: cin >> opcion;
        //Cada opcion una funcion para ajam, cada caso

        switch (opcion) {
            case 1:
                consultarProducto();
              break;
            case 2:
                actualizarInventario();
                break;
            case 3:
                std :: cout << "reporte";
                break;
            case 4:
                std :: cout << "El weo mas caro";
                break;
            case 5:
                std :: cout << "Salier";
                break;
            default:
                std :: cout << "\nOpción invalida. Intente de nuevo.\n";
        }

        if (opcion != 5){

        
            std :: cout << "\n--- Menu principal ---\n";
        }

    }while (opcion != 5);











   
    return 0;
}