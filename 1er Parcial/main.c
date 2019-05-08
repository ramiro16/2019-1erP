#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "socios.h"
#include "libros.h"
#include "autores.h"
#include "prestamos.h"

#define TAMA 10
#define TAML 15
#define TAMS 5
#define TAMP 5

char menu();
int menuInformes();

void socioConPrestamo(eSocio[],int,ePrestamo[],int);
void librosConSocio(eLibro[],int,ePrestamo[],int);

void listarSocioInsercion(eSocio[],int);
void listarLibrosBurbujeo(eLibro[],int);


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
    int opcionInforme;

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
                system("cls");
                altaPrestamo(prestamos,TAMP,socios,TAMS,libros,TAML);
                printf("\n");
            break;

            case 'H':
                system("cls");
                opcionInforme = menuInformes();

                switch(opcionInforme){

                case 1:
                break;
                case 2:
                break;
                case 3:
                    system("cls");
                    socioConPrestamo(socios,TAMS,prestamos,TAMP);
                    printf("\n");
                    system("pause");
                break;
                case 4:
                    system("cls");
                    librosConSocio(libros,TAML,prestamos,TAMP);
                    printf("\n");
                    system("pause");
                break;
                case 5:
                break;
                case 6:
                break;
                case 7:
                break;
                case 8:
                break;
                case 9:
                break;
                case 10:
                    system("cls");
                    listarLibrosBurbujeo(libros,TAML);
                    printf("\n");
                    system("pause");

                break;
                default:
                    printf("Opcion invalida");
                    break;
                }

                printf("\n");

                break;

            case 'I':
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
    printf("G- Prestamo\n");
    printf("H- Informar y listar\n\n");

    printf("I- Salir\n\n");

    printf("Ingrese una opcion:");
    fflush(stdin);
    retorno = toupper(getch());


    return retorno;

}

int menuInformes()
{
    int retorno;

    //printf("1- Total general y promedio diario\n");
    //printf("2- Cantidad de dias cuya solicitud de prestamos no superan el promedio\n");
    printf("3- Listar socio que pidieron un prestamo\n");
    printf("4- Listar libros que fueron solicitados por un socio\n");
    //printf("5- Listar libros menos solicitados\n");
    //printf("6- Listar el/los socios que solicitaron mas prestamos\n");
    //printf("7- Listar todos los libros solicitados en una fehca determinada\n");
    //printf("8- Listar todos los socios que solicitaron prestamo en la misma fecha\n");
    //printf("9- Listar todos los libros por titulo (Burbujeo eficiente)\n");
    printf("10- Listar socios por apellido(insercion)\n");

    printf("\nIngrese una opcion:");
    scanf("%d",&retorno);

    return retorno;

}


void socioConPrestamo(eSocio socios[],int tams, ePrestamo prestamos[],int tamp)
{
    int i,j;
    int auxCont = 0;

    for(i=0;i<tams;i++)
    {
        if(socios[i].estado == 1)
        {
            for(j=0;j<tamp;j++)
            {
                if(socios[i].idSocio == prestamos[j].idSocio)
                {
                    auxCont++;
                }
            }

            if(auxCont == 1)
            {
                printf("%d\t%s\t%s\n\n",socios[i].idSocio,socios[i].nombre,socios[i].apellido);
            }

        }
    }
}

void librosConSocio(eLibro libros[],int taml,ePrestamo prestamos[],int tamp)
{
    int i,j;
    int contador = 0;

    for(i=0;i<taml;i++)
    {
        for(j=0;j<tamp;j++)
        {
            contador = 0;

            if(prestamos[j].idLibro == libros[i].idLibro)
            {
                contador++;
            }
        }

        if(contador == 1)
        {
            printf("%d\t%s\t%d\n",libros[i].idLibro,libros[i].titulo,libros[i].codigoAutor);

            system("pause");
        }
    }


}



void listarLibrosBurbujeo(eLibro libros[],int taml)
{
    int j;
    eLibro auxLibro;
    int flagNoEstaOrdenado = 1;

    while (flagNoEstaOrdenado == 1)
    {
     flagNoEstaOrdenado = 0;

         for (j = 1; j < taml; j++)
         {
            if (libros[j].titulo > libros[j - 1].titulo)
             {
             auxLibro = libros[j];
             libros[j] = libros[j - 1];
             libros[j - 1] = auxLibro;
             flagNoEstaOrdenado = 1;
             }
        }

        for(j=1;j<taml;j++)
        {
            printf("%d\t%s\t%d\n",libros[j].idLibro,libros[j].titulo,libros[j].codigoAutor);
        }
    }
}

