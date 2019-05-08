#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "socios.h"
#include "libros.h"
#include "autores.h"
#include "prestamos.h"



void listarAutores(eAutor autores[],int tam)
{
    int i;

    printf("ID AUTOR\tAPELLIDO\tNOMBRE\n\n");

    for(i=0;i<tam;i++)
    {
        printf("%d\t\t%s\t\t%s\t\n",autores[i].idAutor,autores[i].apellido,autores[i].nombre);
    }
}
