typedef struct
{
  int dia;
  int mes;
  int anio;
}eFecha;

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

void inicializarSocios(eSocio[],int);
void altaSocio(eSocio[],int);
void bajaSocio(eSocio[],int);
void modificarSocio(eSocio[],int);
void listarSocios(eSocio[],int);
