#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Estudiante{
  char nombre[100];
  char matricula[20];
  char email[15];
} Estudiante;

FILE * imprimirArchivo(FILE* archivo);
FILE * abrir_archivo(char * ruta,char * modo);
Estudiante * capturar_estudiantes(int n);
FILE * guardar_estudiantes(Estudiante* lista,int n);

int ejemplo2();
int ejemplo1();