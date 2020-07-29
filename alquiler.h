#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct
{
    char nombre[20];
    char apellido;
    int isEmpty;
}eOperador;
typedef struct
{
    int id;
    int dni;
    char nombre[20];
    char apellido;
    eFecha fecha;
    int isEmpty;
    eOperador operador;

}eCliente;


#endif // ALQUILER_H_INCLUDED
void inicializarCliente(eCliente cliente[],int tamCliente);
void harcodearClientes(eCliente cliente[],int tamHC);
int cargarNombreCliente(char nombreCliente[],int id,eCliente cliente[],int tamCliente);

int altaCliente(int idX, eCliente vec[], int tam,int idCliente,eCliente cliente[],int tamCliente);
int buscarCliente(int id, eCliente vec[], int tamCliente);
void mostrarCliente(eCliente x, eCliente cliente[],int tamCliente);
void mostrarClientes(eCliente cliente[],int tamCliente);
int menuModificar();
void modificarCliente(eCliente vec[], int tam, eCliente cliente,int tamCliente);
void bajaCliente(eCliente vec[],eCliente cliente[],int tamCliente);

