#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"
#include "alquiler.h"
void inicializarServicios(eServicios servicio[],int tamOperador)
{
    for(int i = 0; i < tamOperador; i++)
    {
        servicio[i].isEmpty = 1;
    }
}
void hardcodearServicios(eServicios servicio[], int cant)
{
    eServicio auxServicio[] =
    {
        {20000, "AMOLADORA"},
        {20001, "MEZCLADORA"},
        {20002, "TALADRO"}
    };

    for(int i=0; i<cant; i++)
    {
        servicio[i] = auxServicio[i];
    }
}
int buscarLibreServicio(eOperador trabajo[], int tamOperador)
{

    int indice = -1;
    for(int i = 0; i < tamOperador; i++)
    {
        if(trabajo[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void listarServicios(eServicios servicio[],int tam)
{
    system("cls");
    printf("***** Listado de Servicios *****\n");
    printf("  id     Descripcion\n\n");
    for(int i=0; i<tam; i++)
    {
        printf(" %d   %13s  \n",servicio[i].id, servicio[i].equipo);
    }
    printf("\n");
}
int altaAlquiler(eCliente cliente[],int tamCliente, eOperador operador[], int tamOperador)
{
    int todoOk=0;
    int indiceTrabajo;
    eServicios auxTrabajo;
    eCliente auxiliarTrabajo;

    system("cls");
    printf("***** Alta Alquiler *****\n\n");
    indiceTrabajo=buscarLibreServicio(trabajo,tamOperador);

    if(indiceTrabajo==-1)
    {
        printf("Sistema completo no se puede dar de alta mas alquileres\n");
    }
    else
    {
        mostrarClientes(cliente,tamCliente);
        printf("Ingrese Id de la persona: ");
        scanf("%d",&auxiliarTrabajo.id);
        if(indiceTrabajo==-1)
        {
            printf("Alquiler ingresado no dada de alta!\n");
        }
        else
        {
            printf("El cliente con el id %d es:\n",auxTrabajo.id);
            printf("------------------------------\n");
            printf("  ID   DNI     Nombre   Apellido     Dia/Mes/Anio\n\n");

            mostrarCliente(cliente[indice],cliente,tamCliente);
            system("pause");

            listarServicios(servicio,tam);
            printf("Ingrese Id del servicio: ");
            scanf("%d",&auxTrabajo.id);
            if(buscarLibreServicio(auxTrabajo.id,trabajo,tamOperador)==-1)
            {
                printf("Servicio ingresado inexistente!\n");
            }
            else
            {
                printf("Ingrese fecha dd/mm/aaaa: ");
                fflush(stdin);
                scanf("%d/%d/%d",&auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);

                auxTrabajo.id=idTrabajo;
                auxTrabajo.isEmpty=0;

                trabajo[indiceTrabajo]=auxTrabajo;

                todoOk=1;

                printf("\nAlta Trabajo exitosa!!!\n");
            }
        }
    }
    return todoOk;
}
