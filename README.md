# Poo-segundo-semestre-

Descripción
--
Este programa simula un sistema de gestión de hospedajes en el que dueños pueden registrar sus alojamientos,
y clientes pueden hacer reservaciones y pagos para hospedarse

El cual contendra 6 clases:
-Cliente
-Reservacion 
-Hospedaje 
-Dueno (Dueño)
-Persona 

El usuario hace una reservacion para un alojamiento,permite que el cliente seleccione uno de los hospedajes disponibles y este especifica la duracion de su estancia, selecciona su metodo de pago y al final obtiene un resumen con el costo total a pagar,los datos de el lugar en el que se hospedará y datos sobre el dueño del lugar como lo es nombre y correo 

Casos que harian que el proyecto dejara de funcionar: 
--
--El programa depende de que el usuario ingrese datos válidos en ciertos puntos (nombre, email, selección de hospedaje, duración de estadía, método de pago). Si el usuario ingresa datos incorrectos o inesperados (como letras en lugar de números para la duración de la estadía), podría generar resultados inesperados o errores de ejecución.
--El programa utiliza vectores, por lo mismo, se ocuparía una versión de C++ que contenga dicha biblioteca. En caso de no tenerla podría ocasionar que el programa no compile.
--El manejo de cadenas mediante getline(cin, ...) y la operación cin >> opcion para la selección de hospedaje podrían no capturar correctamente los caracteres de nueva línea o espacios en blanco, lo que puede llevar a errores si no se manejan adecuadamente.


Consideraciones
--
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

compilar con: "g++ hospedaje.h persona.h reservacion.h main-2.cpp"

correr en linux: "/a.out"

correr en windows: "a.exe"
