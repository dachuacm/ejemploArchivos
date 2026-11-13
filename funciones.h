#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Estudiante{
  char nombre[100];
  char matricula[20];
  char email[15];
} Estudiante;

FILE * abrir_archivo(char * ruta,char * modo);
int imprimirArchivo(FILE* archivo);
Estudiante * capturar_estudiantes(int n);
FILE * guardar_estudiantes(Estudiante* lista,int n);
void limpiar_buffer();
int ejemplo2();
int ejemplo1();

/*Estructura ejercicio propuesto 1*/

typedef struct Estado{
  char *nombre;
  char *capital; 
} Estado;

void ejercicio_prop1();