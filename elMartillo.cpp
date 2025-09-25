#include <iostream>
#include <string>

/*Arreglos paralelos: ocupo 4 arreglos paralelos. 
codigo = int     |codigo unico del produvto
nombre = string  |nombre del producto
stock = int      |cantidad de stock
precio = float   |precio unitario  */  

 //Aquí creé los 4 arreglos del tamañño maximo que son 100 o sea 99 índices
const int tamano = 100;
int codigo[tamano];
std :: string nombre[tamano];
int stock[tamano];
float precio[tamano];
int numProductos = 5; //because iniciamos con 5 productos

//opcion 1. Saber si existe o no
//void porque no devuelve ningun valor
void consultarProducto() {
    int code;
    std :: cout << "\nIngrese el codigo del producto a consultar: ";
    std :: cin >> code;

    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (codigo[i] == code) {
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
        std :: cout << "\nERROR: El producto con codigo " << code << " no existe.\n";
    }
}

// Opción 2: Actualizar inventario
void actualizarInventario() {
    int code;
    std::cout << "\nIngrese el codigo del producto a actualizar: ";
    std::cin >> code;

    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (codigo[i] == code) {
            std::cout << "Producto encontrado: " << nombre[i] << std::endl;
            std::cout << "Cantidad actual del stock: " << stock[i] << std::endl;

            int newCantidad;
            std::cout << "Ingrese una nueva cantidad del stock: ";
            std::cin >> newCantidad;

            stock[i] = newCantidad;  // aqui se actualiza
            std::cout << "Inventario actualizado correctamente.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        std::cout << "El producto con codigo " << code << " no existe en el inventario.\n";
    }
}

//opcion 3. mostrar una lista de productos existentes asi bien potente (sale chueca)
void generarReporte() {
    std::cout << "\n--- Reporte de Inventario ---\n";
    std::cout << "Codigo    | Nombre                 | Stock | Precio\n";
    std::cout << "---------------------------------------------------\n";

    for (int i = 0; i < numProductos; i++) {
        std::cout << codigo[i] << "       | " << nombre[i] << "       | " << stock[i] << "    | " << "$" << precio[i] << "\n";
    }

    std::cout << "---------------------------------------------------\n";
    std::cout << "--- Fin del Reporte ---\n";
}

void productoMasCaro() {
       int indiceMayor = 0; // empezamos suponiendo que el más caro es el primero

    // Recorremos todos los productos
    for (int i = 1; i < numProductos; i++) {
        if (precio[i] > precio[indiceMayor]) {
            indiceMayor = i; // guardamos la posición del más caro
        }
    }

    std::cout << "\nEl producto mas caro es: " << nombre[indiceMayor] << " con un precio de $" << precio[indiceMayor] << "\n";
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
                generarReporte();      
                break;
            case 4:
                productoMasCaro();
                break;
            case 5:
                std :: cout << "Apagando funcionamiento total de la maquina...";
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