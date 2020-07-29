#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquiler.h"
#include "servicios.h"

#define CANTHARDCODECLIENTES 5
#define TAM 10
#define TAMCLIENTES 10
#define TAMOPERADOR 10
#define CANTHARDCODE 10
int menu();
int main()
{
    char confirma;
    char seguir='s';
    int proximoId=1000;
    int proximoIdCliente=100+CANTHARDCODECLIENTES;

    eCliente cliente[TAMCLIENTES];
    int idCliente=CANTHARDCODECLIENTES;
    eOperador operador[TAMOPERADOR];


    inicializarCliente(cliente,TAM);
    hardcodearClientes(cliente, CANTHARDCODE);
    proximoId += CANTHARDCODE;

    do
    {
        switch(menu())
        {
        case 'a':
            if(altaCliente(proximoIdCliente, cliente, TAMCLIENTES, idCliente, cliente, TAMCLIENTES))
            {
                proximoIdCliente++;
                idCliente++;
            }
            system("pause");
            break;
        case 'b':
            modificarCliente(cliente, TAM, cliente, TAMCLIENTES);
            system("pause");
            break;
        case 'c':
            bajaCliente(lista, cliente, TAMCLIENTES);
            break;
        case 'd':
            system("cls");
            altaAlquiler(cliente, TAMCLIENTES, operador,TAMOPERADOR);
            system("pause");
            break;
        case 'e':
            system("cls");
            printf("Fin Alquiler");
            system("pause");
            break;
        case 'f':
            system("cls");
            printf("Infomes");
            system("pause");
            break;
        case 'g':
            printf("Confirma salida? s/n: ");
            fflush(stdin);
            confirma=getche();
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
int menu()
{
    char opcion;

    system("cls");
    printf("*****Menu Clientes*****\n");
    printf("A. Alta Cliente\n");
    printf("B. Modificar Cliente\n");
    printf("C. Baja Cliente\n");
    printf("D. Nuevo Alquiler\n");
    printf("E. Fin Alquiler\n");
    printf("F. Informes\n");
    printf("G. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}
