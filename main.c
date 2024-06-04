#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char peliculaArchivo[50] = {"Peliculas"};

typedef struct{
    int idPelicula;
    char nombre[50];
    int anio;
    char genero[10];
    char actores[3][50];
    int calificacion;
    int estado;
}strPelicula;

void cargarArchivoDePelicula();
strPelicula cargarPelicula();
void mostrarArchivoDePelicula();
void mostrarPelicula(strPelicula pelicula);

int main()
{
    cargarArchivoDePelicula();
    mostrarArchivoDePelicula();
    return 0;
}

void cargarArchivoDePelicula(){
    FILE * buff = fopen(peliculaArchivo, "ab");
    strPelicula pelicula;

    if (buff){
        pelicula = cargarPelicula();
        fwrite(&pelicula, sizeof(pelicula),1,buff);
    }
    fclose(buff);
}

strPelicula cargarPelicula(){
    int i = 0;
    char control = 's';
    strPelicula pelicula;
    srand(time(NULL));
    pelicula.idPelicula = rand() % 1001;

    printf("\nIngrese el nombre de la pelicula\n");
    gets(pelicula.nombre);
    fflush(stdin);

    printf("\nIngrese el genero de la pelicula\n");
    gets(pelicula.genero);
    fflush(stdin);

    printf("Ingrese valores para la matriz\n");
    for(int i = 0; i < 3; i++) {
        gets(pelicula.actores[i]);
    }

    printf("\nIngrese el anio de estreno de la pelicula, si no salio un aproximado");
    scanf("%d", &pelicula.anio);
    fflush(stdin);

    printf("\nIngrese la calificacion de la pelicula, si no salio ponga 0\n");
    scanf("%d", &pelicula.calificacion);
    fflush(stdin);

    printf("\nIngrese el estado de la pelicula, 1 si ya esta lista o 0 si esta en produccion\n");
    scanf("%d", &pelicula.estado);
    fflush(stdin);

    return pelicula;
}

void mostrarArchivoDePelicula(){
    FILE * buff = fopen(peliculaArchivo, "rb");
    strPelicula pelicula;

    if (buff){
        while(fread(&pelicula, sizeof(pelicula),1,buff)){
            mostrarPelicula(pelicula);
        }
    }

    fclose(buff);
}

void mostrarPelicula(strPelicula pelicula){
    printf("\n----------------------------------Peliculas----------------------------------\n");
    printf("Nombre: %s\n", pelicula.nombre);
    printf("Año: %d\n", pelicula.anio);
    printf("Género: %s\n", pelicula.genero);
    printf("Actores:\n");
    for (int i = 0; i < 3; i++) {
        printf("  Actor %d: %s\n", i + 1, pelicula.actores[i]);
    }
    printf("Calificación: %d\n", pelicula.calificacion);
    printf("Estado: %d\n", pelicula.estado);
    printf("\n----------------------------------Peliculas----------------------------------\n");

}


