#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquiler.h"
#include "servicios.h"

void inicializarCliente(eCliente cliente[],int tamCliente)
{
    for(int i = 0; i < tamCliente; i++)
    {
        cliente[i].isEmpty = 1;
    }
}
void harcodearClientes(eCliente cliente[],int tamHC)
{
    eCliente auxCliente[] =
    {
        {0, 43721946, "Carlos","Pedroza",{12/7/2021}},
        {1, 44345908,"Mabel","Cozzi",{1/8/2021}},
        {2, 40689332,"Ruperto","Munioz",{23/1/2021}},
        {3, 39044213,"Ernesto","Sendin",{10/2/2021}},
        {4, 48456234,"Juan","Bermeo",{5/5/2021}},
        {5, 47652918,"Jose","Mezzano",{30/10/2021}},
        {6, 46904291,"Alberto","Fernandez",{9/5/2021}}
    };

    for(int i=0; i<tamHC; i++)
    {
        cliente[i] = auxCliente[i];
    }
}
int cargarNombreCliente(char nombreCliente[],int id,eCliente cliente[],int tamCliente)
{
    int todoOk = 0;

    for(int i=0; i<tamCliente; i++)
    {
        if(cliente[i].id == id&&cliente[i].isEmpty==0)
        {
            strcpy(nombreCliente, cliente[i].nombre);
            todoOk = 1;
        }
    }
    return todoOk;
}
int altaCliente(int idX, eCliente vec[], int tam,int idCliente,eCliente cliente[],int tamCliente)
{
    int todoOk = 0;
    int indice = buscarLibre(vec, tam);
    eCliente auxCliente;

    system("cls");
    printf("***** Alta Cliente *****\n");
    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxCliente.id=idCliente;

        printf("\nIngrese Id: ");
        fflush(stdin);
        scanf("%d", &auxCliente.id);

        printf("\nIngrese Dni: ");
        fflush(stdin);
        scanf("%d", &auxCliente.dni);

        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(auxCliente.nombre);

         printf("Ingrese Apellido: ");
        fflush(stdin);
        gets(auxCliente.apellido);

        printf("\nIngrese Fecha: ");
        fflush(stdin);
        scanf("%d", &auxCliente.fecha.dia, &auxCliente.fecha.mes, &auxCliente.fecha.anio);

        auxCliente.isEmpty=0;

        cliente[idCliente]=auxCliente;

        todoOk = 1;
    }
    return todoOk;
}
int buscarCliente(int id, eCliente vec[], int tamCliente)
{
    int indice = -1;

    for(int i = 0; i < tamCliente; i++)
    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int menuModificar()
{
    int opcion;

    printf("\n***** Menu de Modificaciones *****\n\n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar Apellido\n");
    printf("3. Salir\n\n");
    printf("Ingrese la opcion elegida: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
void modificarCliente(eCliente vec[], int tam, eCliente cliente,int tamCliente)
{
    int id;
    int indice;
    char confirma;
    char salir;

    system("cls");
    printf("***** Modificar Cliente *****\n\n");
    mostrarClientes(cliente, tamCliente);
    printf("\nIngrese id: ");
    scanf("%d", &id);

    indice = buscarCliente(id, vec, tamCliente);
    if(indice == -1)
    {
        printf("El id %d no existe en sistema.\n", id);
    }
    else
    {
        system("cls");
        printf("***** Modificar Cliente *****\n\n");
        printf("El cliente con el id %d es:\n", id);
        printf("------------------------------\n");
        printf("  ID   DNI     Nombre   Apellido     Dia/Mes/Anio\n\n");

        mostrarCliente(cliente[indice],cliente,tamCliente);

        printf("\nDesea modificar? 's' o 'n': ");
        fflush(stdin);
        confirma=getche();
        system("cls");

        while(confirma == 's')
        {
            printf("  ID   DNI     Nombre   Apellido     Dia/Mes/Anio\n\n");
            printf("------------------------------\n");
            mostrarCliente(cliente[indice],cliente, tamCliente);

            switch(menuModificar())
            {
            case 1:
                printf("Ingrese nuevo Nombre: ");
                fflush(stdin);
                scanf("%c",&cliente[indice].nombre);
                system("cls");
                break;
            case 2:
                printf("Ingrese nuevo Apellido: ");
                fflush(stdin);
                scanf("%c",&cliente[indice].apellido);
                system("cls");
                break;
            case 3:
                printf("Confirma salida? s/n: ");
                fflush(stdin);
                salir=getche();
                if(salir == 's')
                {
                    confirma = 'n';
                }
                break;
            }
        }
        if(confirma!='s')
        {
            printf("\n\nSe ha cancelado la operacion.\n");
        }
    }
}
void mostrarCliente(eCliente x, eCliente cliente[],int tamCliente)
{
    char nombreCliente[20];

    cargarNombreCliente(nombreCliente,x.id,cliente,tamCliente);
    printf("  %d   %d    %c   %c    %d%d%d\n", x.id, x.dni, x.nombre, x.apellido, x.fecha.dia, x.fecha.mes, x.fecha.anio);

}
void mostrarClientes(eCliente cliente[],int tamCliente)
{
    int flag = 0;

    printf("***** Listado de Clientes *****\n\n");
    printf("  ID   DNI     Nombre   Apellido     Dia/Mes/Anio\n\n");
    for(int i = 0; i < tamCliente; i++)
    {
        if(cliente[i].isEmpty == 0)
        {
            mostrarCliente(cliente[i],cliente,tamCliente);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("No hay clientes que listar\n");
    }
}
void bajaCliente(eCliente vec[],eCliente cliente[],int tamCliente)
{
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("***** Baja Cliente *****\n\n");
    mostrarClientes(cliente,tamCliente);
    printf("\nIngrese id: ");
    scanf("%d", &id);

    indice = buscarCliente(id, vec, tamCliente);
    if(indice == -1)
    {
        printf("El id %d no existe en sistema.\n", id);
    }
    else
    {
        system("cls");
        printf("***** Modificar Cliente *****\n\n");
        printf("El cliente con el id %d es:\n", id);
        printf("------------------------------\n");
        printf("  ID   DNI     Nombre   Apellido     Dia/Mes/Anio\n\n");
        mostrarCliente(cliente[indice], cliente,tamCliente);

        printf("Confirma la baja? 's' o 'n': ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se cancelo la operacion.\n");
        }
    }
}
