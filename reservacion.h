#ifndef RESERVACION_H
#define RESERVACION_H

#include "hospedaje.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Clase Reservacion
 * 
 * Representa una reservación en un hospedaje. Contiene la información
 * de las fechas de inicio y fin, el hospedaje reservado, el monto pagado,
 * la fecha de pago y el método de pago.
 */
class Reservacion {
public:
    string fechaInicio; // Fecha de inicio de la reservación
    string fechaFin;    // Fecha de fin de la reservación
    Hospedaje hospedaje; // Hospedaje reservado
    double monto;       // Monto pagado por la reservación
    string fechaPago;   // Fecha en que se realizó el pago
    string metodoPago;  // Método de pago utilizado

    /**
     * Constructor de la clase Reservacion.
     * 
     * Inicializa un nuevo objeto Reservacion con los valores proporcionados.
     *
     * fechaInicio Fecha de inicio de la reservación.
     * fechaFin Fecha de fin de la reservación.
     * hospedaje Hospedaje reservado.
     * monto Monto pagado por la reservación.
     * fechaPago Fecha en que se realizó el pago.
     * metodoPago Método de pago utilizado.
     */
    Reservacion(string fechaInicio, string fechaFin, Hospedaje hospedaje, double monto, string fechaPago, string metodoPago)
        : fechaInicio(fechaInicio), fechaFin(fechaFin), hospedaje(hospedaje), monto(monto), fechaPago(fechaPago), metodoPago(metodoPago) {}

    /**
     * Muestra la información de la reservación.
     */
    void mostrarInfo() const { 
        cout << "Reservación desde " << fechaInicio << " hasta " << fechaFin << " en:\n";
        hospedaje.mostrarInfo();
        cout << "Pago de $" << monto << " realizado el " << fechaPago << " usando " << metodoPago << endl;
    }

    /**
     * Cancela la reservación.
     */
    void cancelar() {
        cout << "Reservación desde " << fechaInicio << " hasta " << fechaFin << " cancelada." << endl;
    }
};

#endif // RESERVACION_H
