#ifndef HOSPEDAJE_H
#define HOSPEDAJE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Clase Hospedaje
 * 
 * Representa un hospedaje con una dirección, descripción y precio por noche.
 * Proporciona un método para mostrar la información del hospedaje.
 */
class Hospedaje {
public:
    string direccion;    // Dirección del hospedaje
    string descripcion;  // Descripción del hospedaje
    double precioNoche;  // Precio por noche del hospedaje

    /**
     * Constructor de la clase Hospedaje.
     * 
     * Inicializa un nuevo objeto de hospedaje con la dirección, descripción y precio por noche proporcionados.
     *
     * direccion Dirección del hospedaje.
     * descripcion Descripción del hospedaje.
     * precioNoche Precio por noche del hospedaje.
     */
    Hospedaje(string direccion, string descripcion, double precioNoche)
        : direccion(direccion), descripcion(descripcion), precioNoche(precioNoche) {}

    /**
     * Muestra la información del hospedaje.
     * 
     * Imprime la dirección, descripción y precio por noche del hospedaje.
     */
    void mostrarInfo() const {
        cout << "Direccion: " << direccion << ", Descripcion: " << descripcion 
             << ", Precio por noche: $" << precioNoche << endl;
    }
};

#endif // HOSPEDAJE_H
