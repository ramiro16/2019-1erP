#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "socios.h"
#include "libros.h"
#include "autores.h"
#include "prestamos.h"

#endif

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
