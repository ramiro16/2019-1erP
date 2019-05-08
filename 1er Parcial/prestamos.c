#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "socios.h"
#include "libros.h"
#include "autores.h"
#include "prestamos.h"



void altaPrestamo(ePrestamo prestamos[], int tamp, eSocio socios[], int tams, eLibro libros[], int taml)
{
    int i;
    int auxId = 10000;

    for(i=0;i<tamp;i++)
    {
        prestamos[i].idPrestamo = auxId + i;

        listarSocios(socios, tams);
        printf("\nSeleccione un ID de socio:");
        scanf("%d",&prestamos[i].idSocio);

        listarLibros(libros,taml);
        printf("\nSeleccione un ID de libro:");
        scanf("%d",&prestamos[i].idLibro);

        printf("\nIngrese fecha de prestamo\nDia:");
        scanf("%d",&prestamos[i].fechaPrestamo.dia);

        printf("\nMes:");
        scanf("%d",&prestamos[i].fechaPrestamo.mes);

        printf("\nAnio:");
        scanf("%d",&prestamos[i].fechaPrestamo.anio);


        printf("\n\nPrestamo dado de alta con exito!\n\n");

        system("pause");

        break;

    }
}
