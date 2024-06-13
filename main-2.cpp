#include "persona.h"

int main() {
    // Crear dueños
    Dueno dueno1("Pablo Jaimes", "123-456-7890", "Pjt_17@gmail.com");
    Dueno dueno2("Ana Aguilar", "987-654-3210", "Ana27_AT@gmail.com");

    // Crear hospedajes
    Hospedaje hospedaje1("Calle Hidalgo #13, QRO", "Hermoso apartamento en el centro con 4 habitaciones y 3 baños", 600.0);
    Hospedaje hospedaje2("Privada Palmas #2", "Cómoda casa con jardín,piscina, con 5 habitaciones", 900.0);

    // Registrar hospedaje1 con dueno1 y hospedaje2 con dueno2
    dueno1.registrar(hospedaje1);
    dueno2.registrar(hospedaje2);

    // Mostrar información detallada de los dueños y sus hospedajes
    cout << "\nInformación del dueño 1:\n";
    dueno1.mostrarInfo();
    cout << "\nInformación del dueño 2:\n";
    dueno2.mostrarInfo();

    // Solicitar los datos del cliente
    string nombreCliente;
    string emailCliente;
    cout << "\n-Ingrese su nombre:\n";
    cin.ignore();  // Ignorar cualquier nueva línea pendiente
    getline(cin, nombreCliente); // Leer el nombre del cliente
    cout << "-Ingrese su email: ";
    getline(cin, emailCliente); // Leer el email del cliente

    // Crear un cliente con los datos ingresados
    Cliente cliente1(nombreCliente, emailCliente);

    // Permitir al usuario seleccionar un hospedaje
    int opcion;
    cout << "\n-Seleccione un hospedaje (1 o 2): \n";
    cin >> opcion;

    Hospedaje hospedajeElegido = (opcion == 1) ? hospedaje1 : hospedaje2;

    // Solicitar la duración de la estadía
    int duracionEstadia;
    cout << "-Ingrese la duración de la estadía en días: ";
    cin >> duracionEstadia;

    // Permitir al usuario seleccionar el método de pago
    string metodoPago;
    cout << "-Seleccione el método de pago (efectivo o tarjeta): ";
    cin >> metodoPago;

    // Calcular el monto total de la reservación
    double montoTotal = duracionEstadia * hospedajeElegido.precioNoche;

    // Crear una reservación con el hospedaje seleccionado, la duración ingresada y el método de pago
    Reservacion reservacion1("2024-06-01", "2024-06-09", hospedajeElegido, montoTotal, "2024-06-12", metodoPago);
    cliente1 += reservacion1;

    // Mostrar información de la reservación
    cout << "\n-Resumen de la reservación:\n";
    reservacion1.mostrarInfo();
    cout << "\n-Duración de la estadía: " << duracionEstadia << " días\n";
    cout << "-Método de pago: " << metodoPago << endl; // Mostrar el método de pago seleccionado
    cout << "-Monto total a pagar: $" << montoTotal << endl;

    // Mostrar información del dueño del hospedaje elegido
    cout << "\nInformación del dueño del hospedaje:\n";
    if (opcion == 1) {
        dueno1.mostrarInfo();
    } else {
        dueno2.mostrarInfo();
    }

    return 0;
}
