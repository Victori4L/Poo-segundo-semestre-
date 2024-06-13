#ifndef PERSONA_H
#define PERSONA_H

#include "reservacion.h"
#include <vector>
#include <string>

using namespace std;

/**
 * Clase abstracta Persona
 * 
 * Representa una persona con un nombre y un email. 
 * Proporciona métodos virtuales para mostrar y actualizar información.
 */
class Persona {
public:
    string nombre;  // Nombre de la persona
    string email;   // Email de la persona

    /**
     * Constructor de la clase Persona.
     * 
     * Inicializa un nuevo objeto Persona con el nombre y el email proporcionados.
     *
     * nombre Nombre de la persona.
     * email Email de la persona.
     */
    Persona(string nombre, string email)
        : nombre(nombre), email(email) {}

    /**
     * Método virtual para mostrar información de la persona.
     */
    virtual void mostrarInfo() const = 0;

    /**
     * Método virtual para actualizar la información de la persona.
     * 
     * nuevoNombre Nuevo nombre de la persona.
     * nuevoEmail Nuevo email de la persona.
     */
    virtual void actualizarInfo(string nuevoNombre, string nuevoEmail) = 0;
};

/**
 * Clase Dueno
 * 
 * Representa un dueño que hereda de Persona y añade un teléfono y una lista de hospedajes.
 */
class Dueno : public Persona {
public:
    string telefono;             // Teléfono del dueño
    vector<Hospedaje> hospedajes; // Lista de hospedajes del dueño

    /**
     * Constructor de la clase Dueno.
     * 
     * Inicializa un nuevo objeto Dueno con el nombre, teléfono y email proporcionados.
     *
     * ombre Nombre del dueño.
     * telefono Teléfono del dueño.
     * email Email del dueño.
     */
    Dueno(string nombre, string telefono, string email)
        : Persona(nombre, email), telefono(telefono) {}

    /**
     * Registra un nuevo hospedaje bajo el dueño.
     * 
     * hospedaje El hospedaje a registrar.
     */
    void registrar(Hospedaje hospedaje) {
        hospedajes.push_back(hospedaje);
        cout << "Hospedaje en " << hospedaje.direccion << " registrado bajo el dueño " << nombre << endl;
    }

    /**
     * Muestra la información del dueño y sus hospedajes.
     */
    void mostrarInfo() const override {
        cout << "Dueño: " << nombre << ", Teléfono: " << telefono << ", Email: " << email << endl;
        for (const auto& hospedaje : hospedajes) {
            hospedaje.mostrarInfo();
        }
    }

    /**
     * Actualiza la información del dueño.
     * 
     * nuevoNombre Nuevo nombre del dueño.
     * nuevoEmail Nuevo email del dueño.
     */
    void actualizarInfo(string nuevoNombre, string nuevoEmail) override {
        nombre = nuevoNombre;
        email = nuevoEmail;
        cout << "Información del dueño actualizada." << endl;
    }
};

/**
 * Clase Cliente
 * 
 * Representa un cliente que hereda de Persona y añade una lista de reservaciones.
 */
class Cliente : public Persona {
public:
    vector<Reservacion> reservaciones; // Lista de reservaciones del cliente

    /**
     * Constructor de la clase Cliente.
     * 
     * Inicializa un nuevo objeto Cliente con el nombre y el email proporcionados.
     *
     * nombre Nombre del cliente.
     * email Email del cliente.
     */
    Cliente(string nombre, string email)
        : Persona(nombre, email) {}

    /**
     * Sobrecarga del operador += para agregar una nueva reservación.
     * 
     * reservacion La reservación a agregar.
     */
    void operator+=(const Reservacion& reservacion) {
        reservaciones.push_back(reservacion);
        cout << "Reservación registrada para el cliente " << nombre << endl;
    }

    /**
     * Muestra la información del cliente y sus reservaciones.
     */
    void mostrarInfo() const override {
        cout << "Cliente: " << nombre << ", Email: " << email << endl;
        for (const auto& reservacion : reservaciones) {
            reservacion.mostrarInfo();
        }
    }

    /**
     * Actualiza la información del cliente.
     * 
     * nuevoNombre Nuevo nombre del cliente.
     * nuevoEmail Nuevo email del cliente.
     */
    void actualizarInfo(string nuevoNombre, string nuevoEmail) override {
        nombre = nuevoNombre;
        email = nuevoEmail;
        cout << "Información del cliente actualizada." << endl;
    }
};

#endif // PERSONA_H
