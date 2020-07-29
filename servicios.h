#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
#include "alquiler.h"
typedef struct
{
    int id;
    char equipo;
    eFecha fecha;
    int isEmpty;
}eServicios;

#endif // SERVICIOS_H_INCLUDED
void inicializarServicios(eServicios servicio[],int tamOperador);
void hardcodearServicios(eServicios servicio[], int cant);
int buscarLibreServicio(eOperador trabajo[], int tamOperador);
void listarServicios(eServicios servicio[],int tam);
int altaAlquiler(eCliente cliente[],int tamCliente, eOperador operador[], int tamOperador);

