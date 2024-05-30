#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Hospedaje {
public:
    string direccion;
    string descripcion;
    double precioNoche;

    Hospedaje(string direccion, string descripcion, double precioNoche)
        : direccion(direccion), descripcion(descripcion), precioNoche(precioNoche) {}

    void mostrarInfo() const {
        cout << "Direccion: " << direccion << ", Descripcion: " << descripcion 
             << ", Precio por noche: $" << precioNoche << endl;
    }

    void agregarComentario(const string& comentario) {
        cout << "Comentario agregado al hospedaje en " << direccion << ": " << comentario << endl;
    }
};

// Clase base Persona
class Persona {
public:
    string nombre;
    string email;

    Persona(string nombre, string email)
        : nombre(nombre), email(email) {}

    // Método virtual para mostrar información
    virtual void mostrarInfo() const {
        cout << "Nombre: " << nombre << ", Email: " << email << endl;
    }
};

class Dueno : public Persona {
public:
    string telefono;
    vector<Hospedaje> hospedajes;

    Dueno(string nombre, string telefono, string email)
        : Persona(nombre, email), telefono(telefono) {}

    void registrar(Hospedaje hospedaje) {
        hospedajes.push_back(hospedaje);
        cout << "Hospedaje en " << hospedaje.direccion << " registrado bajo el dueño " << nombre << endl;
    }

    void actualizarInfo(string nuevoTelefono, string nuevoEmail) {
        telefono = nuevoTelefono;
        email = nuevoEmail;
        cout << "Información de " << nombre << " actualizada." << endl;
    }

    // Sobrescribir el método mostrarInfo
    void mostrarInfo() const override {
        cout << "Dueño: " << nombre << ", Teléfono: " << telefono << ", Email: " << email << endl;

        for (const auto& hospedaje : hospedajes) {
            hospedaje.mostrarInfo();
        }
    }
};

class Reservacion {
public:
    string fechaInicio;
    string fechaFin;
    Hospedaje hospedaje;

    Reservacion(string fechaInicio, string fechaFin, Hospedaje hospedaje)
        : fechaInicio(fechaInicio), fechaFin(fechaFin), hospedaje(hospedaje) {}

    void mostrarInfo() const { 
        cout << "Reservación desde " << fechaInicio << " hasta " << fechaFin << " en:\n";
        hospedaje.mostrarInfo();
    }

    void cancelar() {
        cout << "Reservación desde " << fechaInicio << " hasta " << fechaFin << " cancelada." << endl;
    }
};

class Cliente : public Persona {
public:
    vector<Reservacion> reservaciones;

    Cliente(string nombre, string email)
        : Persona(nombre, email) {}

    // Sobrecarga del operador para agregar reservaciones
    void operator+=(const Reservacion& reservacion) {
        reservaciones.push_back(reservacion);
        cout << "Reservación registrada para el cliente " << nombre << endl;
    }

    // Sobrescribir el método mostrarInfo
    void mostrarInfo() const override {
        cout << "Cliente: " << nombre << ", Email: " << email << endl;

        for (const auto& reservacion : reservaciones) {
            reservacion.mostrarInfo();
        }
    }
};

class Pago {
public:
    double monto;
    string fechaPago;
    string metodoPago;

    Pago(double monto, string fechaPago, string metodoPago)
        : monto(monto), fechaPago(fechaPago), metodoPago(metodoPago) {}

    void realizarPago() {
        // cout << "Pago de $" << monto << " realizado el " << fechaPago << " usando " << metodoPago << endl;
    }

    void mostrarInfo() const {
        cout << "Pago de $" << monto << " realizado el " << fechaPago << " usando " << metodoPago << endl;
    }
};

int main() {
    // Crear un dueño
    Dueno dueno1("John Doe", "123-456-7890", "johndoe@example.com");

    // Crear hospedajes
    Hospedaje hospedaje1("123 Main St", "Hermoso apartamento en el centro", 100.0);
    Hospedaje hospedaje2("456 Elm St", "Cómoda casa con jardín", 150.0);

    // Registrar hospedajes con el dueño
    dueno1.registrar(hospedaje1);
    dueno1.registrar(hospedaje2);

    // Mostrar información del dueño y sus hospedajes
    dueno1.mostrarInfo();

    // Crear un cliente
    Cliente cliente1("Jane Smith", "janesmith@example.com");

    // Crear una reservación
    Reservacion reservacion1("2023-06-01", "2023-06-05", hospedaje1);
    cliente1 += reservacion1;

    // Mostrar información del cliente y sus reservaciones
    cliente1.mostrarInfo();

    // Crear un pago
    Pago pago1(500.0, "2023-05-01", "Tarjeta de Crédito");

    // Realizar y mostrar información del pago
    pago1.realizarPago();
    pago1.mostrarInfo();

    return 0;
}
