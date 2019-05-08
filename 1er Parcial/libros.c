#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "socios.h"
#include "libros.h"
#include "autores.h"
#include "prestamos.h"


void listarLibros(eLibro libros[],int tam)
{
    int i;

    printf("ID LIBRO\tTITULO\t\tCOD.AUTOR\n\n");

    for(i=0;i<tam;i++)
    {
        printf("%d\t\t%s\t\t%d\n",libros[i].idLibro,libros[i].titulo,libros[i].codigoAutor);
    }
}
