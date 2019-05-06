#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


#define TAMA 10
#define TAML 15
#define TAMS 5
#define TAMP 5

typedef struct
{
  int dia;
  int mes;
  int anio;
}eFecha;

typedef struct
{
    int idAutor;
    char apellido[31];
    char nombre[31];

}eAutor;

typedef struct
{
    int idLibro;
    char titulo[51];
    int codigoAutor;

}eLibro;

typedef struct
{
    int idSocio;
    char apellido[51];
    char nombre[51];
    char sexo;
    char telefono[16];
    char email[31];
    eFecha fechaAsoc;

    int estado;

}eSocio;

typedef struct
{
    int idPrestamo;
    int idLibro;
    int idSocio;
    eFecha fechaPrestamo;

}ePrestamo;

char menu();

void inicializarSocios(eSocio[],int);
void altaSocio(eSocio[],int);
void bajaSocio(eSocio[],int);
void modificarSocio(eSocio[],int);

void listarSocios(eSocio[],int);
void listarLibros(eLibro[],int);
void listarAutores(eAutor[],int);

void altaPrestamo(ePrestamo[],int,eSocio[],int,eLibro[],int);

//---------------------------------------------------------------------------------------------------------//

int main()
{
    eAutor autores[TAMA] = {{100,"Sanchez","Rodrigo"},{101,"Perez","Carla"},{102,"Rivera","Diego"},{103,"Jackson","Stephan"},{104,"Killer","Mariela"},{105,"Dolores","Graciela"},{106,"Doyle","Arthur"},{107,"Adams","Jhon"},{108,"Peterson","Adam"},{109,"Diaz","Carla"}};
    eLibro libros[TAML] = {{1000,"Libro 1",100},{1001,"Libro 2",101},{1002,"Libro 3",102},{1003,"Libro 4",103},{1004,"Libro 5",104},{1005,"Libro 6",105},{1006,"Libro 7",106},{1007,"Libro 8",107},{1008,"Libro 9",108},{1009,"Libro 10",109},{1010,"Libro 11",104},{1011,"Libro 12",102},{1012,"Libro 13",104},{1013,"Libro 14",109},{1014,"Libro 15",101}};
    eSocio socios[TAMS];
    ePrestamo prestamos[TAMP];

    inicializarSocios(socios, TAMS);

    char rta = 's';
    char opcion;

    do
    {
        system("cls");

        opcion = menu();

        switch(opcion)
        {
            case 'A':
                system("cls");
                altaSocio(socios,TAMS);
                system("pause");
            break;

            case 'B':
                system("cls");
                modificarSocio(socios,TAMS);
                system("pause");
            break;

            case 'C':
                system("cls");
                bajaSocio(socios,TAMS);
                system("pause");
            break;

            case 'D':
                system("cls");
                listarSocios(socios,TAMS);
                printf("\n");
                system("pause");

            break;

            case 'E':
                system("cls");
                listarLibros(libros,TAML);
                printf("\n");
                system("pause");
            break;

            case 'F':
                system("cls");
                listarAutores(autores,TAMA);
                printf("\n");
                system("pause");
            break;

            case 'G':
                altaPrestamo(prestamos,TAMP,socios,TAMS,libros,TAML);
            break;

            case 'H':
                rta = 'n';
            break;

            default:
                system("cls");
                printf("ERROR. Reingrese una opcion valida\n\n");
                system("pause");
                break;

        }

    }while(rta == 's');


    return 0;
}


//------------------------------------------------------------------------------------------------------//

char menu()
{
    char retorno;

    printf("A- Alta socio\n");
    printf("B- Modificar socio\n");
    printf("C- Baja socio\n");
    printf("D- Listar socios (apellido y nombre)\n");
    printf("E- Listar libros\n");
    printf("F- Listar autores\n");
    printf("G- Prestamo\n\n");

    printf("H- Salir\n\n");

    printf("Ingrese una opcion:");
    fflush(stdin);
    retorno = toupper(getch());


    return retorno;

}

/*int buscarLibre(eSocio vec[], int tam){

    int indice = -1;
    int i;

     for(i=0; i < tam; i++)
    {
        if(vec[i].estado == 0){
            indice = i;
            break;
        }
    }

    return indice;
}*/

void inicializarSocios(eSocio socios[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        socios[i].estado = 0;
    }
}

void altaSocio(eSocio socios[],int tam)
{
    int i;
    int flag = 0;
    int auxInt = 10;
    char auxChar;

    for(i=0;i<tam;i++)
    {
        if(socios[i].estado == 0)
        {
            flag = 1;
            printf("Se ha encontrado lugar para cargar un nuevo socio\n\n");

            socios[i].idSocio = auxInt + i;

            printf("Ingrese apellido del socio:");
            fflush(stdin);
            gets(socios[i].apellido);

            printf("Ingrese nombre del socio:");
            fflush(stdin);
            gets(socios[i].nombre);

            printf("\nIngrese sexo del socio. F para mujer, M para hombre: ");
            fflush(stdin);
            auxChar = toupper(getch());

            while(auxChar != 'F' && auxChar != 'M')
            {
                printf("\nOpcion invalida. Reingrese una opcion valida");
                fflush(stdin);
                auxChar = toupper(getch());
            }

            socios[i].sexo = auxChar;

            printf("\n\nIngrese numero telefonico:");
            fflush(stdin);
            gets(socios[i].telefono);

            printf("\nIngrese email:");
            fflush(stdin);
            gets(socios[i].email);

            printf("\nIngrese fecha de asociacion:\n");
            printf("Dia:");
            scanf("%d",&socios[i].fechaAsoc.dia);
            printf("Mes:");
            scanf("%d",&socios[i].fechaAsoc.mes);
            printf("Anio:");
            scanf("%d",&socios[i].fechaAsoc.anio);

            socios[i].estado = 1;

            printf("\n\nSocio cargado correctamente!\n\n");
            break;

        }
    }

    if(flag == 0)
    {
        printf("No hay lugar para cargar mas usuarios");
    }

}

void bajaSocio(eSocio socios[],int tam)
{
    int i;
    int auxId;
    int flag = 0;

    listarSocios(socios,tam);

    printf("\nIngrese ID de socio que desea dar de baja:");
    scanf("%d",&auxId);

    for(i=0;i<tam;i++)
    {
        if(auxId == socios[i].idSocio && socios[i].estado == 1)
        {
            flag = 1;
            socios[i].estado = 0;
            printf("\n\nBaja realizada con exito!");
            break;
        }
    }

    if(flag == 0)
    {
        printf("\n\nNo se ha encontrado un socio correspondiente al ID ingresado\n");
    }

}

void modificarSocio(eSocio socio[],int tam)
{
    int auxId;
    int i;
    int opcion;

    listarSocios(socio,tam);

    printf("Ingrese ID de socio que desea modificar");
    scanf("%d",&auxId);

    for(i=0;i<tam;i++)
    {
        if(auxId == socio[i].idSocio && socio[i].estado == 1)
        {
            printf("Se ha encontrado el siguiente usuario\n\n");
            printf("%s\t%s\t%s\t%s\t%c\n",socio[i].apellido,socio[i].nombre,socio[i].email,socio[i].telefono,socio[i].sexo);

            printf("Que desea modificar?\n\n1-Apellido\n2-Nombre\n3-Sexo\n4-Telefono\n5-eMail\n\n");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("Modificacion de apellido. Ingrese nuevo apellido:");
                fflush(stdin);
                gets(socio[i].apellido);
                printf("Modificacion realizada con exito!");
                break;
            case 2:
                printf("Modificacion de nombre. Ingrese nuevo nombre:");
                fflush(stdin);
                gets(socio[i].nombre);
                printf("Modificacion realizada con exito!");
                break;
            case 3:
                printf("Modificacion de sexo. Realizada");
                if(socio[i].sexo == 'F')
                {
                    socio[i].sexo = 'M';
                }
                if(socio[i].sexo == 'M')
                {
                    socio[i].sexo = 'F';
                }
                printf("Modificacion realizada con exito!");
                break;
            case 4:
                printf("Modificacion de telefono. Ingrese nuevo telefono:");
                fflush(stdin);
                gets(socio[i].telefono);
                printf("Modificacion realizada con exito!");
                break;
            case 5:
                printf("Modificacion de email. Ingrese nuevo email:");
                fflush(stdin);
                gets(socio[i].email);
                printf("Modificacion realizada con exito!");
                break;
            default:
                printf("\n\nERROR. Opcion invalida\n\n");
                break;

            }

        }
    }

}



void listarSocios(eSocio socios[], int tam)
{
    int i;
    int flag = 0;


    for(i=0;i<tam;i++)
    {
        if(socios[i].estado == 1)
        {
            flag = 1;
            printf("%d\t%s\t%s\t%s\t%s\t%d/%d/%d\n",socios[i].idSocio,socios[i].apellido,socios[i].nombre,socios[i].telefono,socios[i].email,socios[i].fechaAsoc.dia,socios[i].fechaAsoc.mes,socios[i].fechaAsoc.anio);
        }
    }

    if(flag == 0)
    {
        system("cls");
        printf("No hay socios que mostrar\n\n");
        system("pause");
    }
}

void listarLibros(eLibro libros[],int tam)
{
    int i;

    printf("ID LIBRO\tTITULO\t\tCOD.AUTOR\n\n");

    for(i=0;i<tam;i++)
    {
        printf("%d\t\t%s\t\t%d\n",libros[i].idLibro,libros[i].titulo,libros[i].codigoAutor);
    }
}

void listarAutores(eAutor autores[],int tam)
{
    int i;

    printf("ID AUTOR\tAPELLIDO\tNOMBRE\n\n");

    for(i=0;i<tam;i++)
    {
        printf("%d\t\t%s\t\t%s\t\n",autores[i].idAutor,autores[i].apellido,autores[i].nombre);
    }
}

void altaPrestamo(ePrestamo prestamos[], int tamp, eSocio socios[], int tams, eLibro libros[], int taml)
{
    int i;
    int auxId = 10000;

    for(i=0;i<tamp;i++)
    {
        prestamos[i].idPrestamo = auxId + i;

        listarSocios(socios, tams);
        printf("Seleccione un ID de socio:");
        scanf("%d",&prestamos[i].idSocio);

        listarLibros(libros,taml);
        printf("Seleccione un ID de libro:");
        scanf("%d",&prestamos[i].idLibro);

        printf("Ingrese fecha de prestamo\nDia:");
        scanf("%d",&prestamos[i].fechaPrestamo.dia);

        printf("\nMes:");
        scanf("%d",&prestamos[i].fechaPrestamo.mes);

        printf("\nAnio:");
        scanf("%d",&prestamos[i].fechaPrestamo.anio);


        printf("\n\nPrestamo dado de alta con exito!\n\n");

    }
}
