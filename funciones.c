#include "funciones.h"

void limpiar_buffer(){
 int c;
    while ((c = getchar()) != '\n' && c != EOF); 

}

FILE * abrir_archivo(char * ruta,char * modo){

   FILE *fp = fopen(ruta, modo);

  if (fp == NULL) {
    printf("No se pudo abrir el archivo\n");
  }
  return fp;
}

int imprimirArchivo(FILE * archivo){

 char linea[80]={0};

while (fgets(linea, sizeof(linea), archivo) != NULL) {
      printf("%s", linea);
  }
  
  return 0;
} 

Estudiante * capturar_estudiantes(int n){
    int i;
    Estudiante * estudiantes=calloc(n,sizeof(Estudiante)), *aux;
    aux=estudiantes;
    limpiar_buffer();
    for(i=0;i<n;i++){
       printf("Ingresa los datos del estudiante %d\n",i+1);
       printf("nombre:");
       fgets(aux->nombre,sizeof(estudiantes->nombre), stdin);
       printf("matricula:");
       fgets(aux->matricula,sizeof(estudiantes->matricula), stdin);
       printf("email:");
       fgets(aux->email,sizeof(estudiantes->email), stdin);
       aux++;
    }
  return estudiantes;
}

FILE * guardar_estudiantes(Estudiante* lista,int n){
 FILE * archivo;
 int i;
 archivo=abrir_archivo("lista.txt","w");
 if(abrir_archivo!=NULL)
  for(i=0;i<n;i++){
    (lista->nombre)[strcspn(lista->nombre, "\n")] = '\0';
    (lista->matricula)[strcspn(lista->matricula, "\n")] = '\0';
    (lista->email)[strcspn(lista->email,"\n")] = '\0';
    
    fprintf(archivo, "%s,", lista->nombre); 
    fprintf(archivo, "%s,", lista->matricula);
    fprintf(archivo, "%s\n", lista->email);
    lista++;
   }
 fclose(archivo);

  return archivo;
}

int ejemplo1(){

  Estudiante * lista_estudiantes;
  int num_estudiantes;
  FILE * archivo_estudiantes;
  printf("número de estudiantes:");
  scanf("%d",&num_estudiantes);

  lista_estudiantes=capturar_estudiantes(num_estudiantes);
  
  archivo_estudiantes= guardar_estudiantes(lista_estudiantes,num_estudiantes);

  if(archivo_estudiantes==NULL) return -1;

  return 0;
}

int ejemplo2(){

    FILE * p_archivo;

    p_archivo=abrir_archivo("datos.txt","r");
  
    if(p_archivo==NULL) return -1;
   
    imprimirArchivo(p_archivo);
    fclose(p_archivo);

  return 0;

}

/*
Funciones de los ejercicios propuestos
*/
Estado * cargar_estados(){
  FILE * datos=abrir_archivo("estados_capitales.txt","r");
  Estado *estados=NULL;
  char linea[100]={0},* nombre,*capital;
  int i=0;

  if(datos!=NULL){
    //reservar memoria para los 32 estados
      estados=calloc(32,sizeof(Estado));
      if(estados!=NULL){
    //Leer linea a linea el archivo y reservar espacio para los datos del estado
        while (fgets(linea, sizeof(linea), datos) != NULL) {
          (estados+i)->nombre=calloc(50,1);
          (estados+i)->capital=calloc(50,1);

          strcpy((estados+i)->nombre,strtok(linea,"–"));
          strcpy((estados+i)->capital,strtok(NULL,"–"));
          i++;
        }
        
      }
      fclose(datos);
  }
  return estados;
}

void imprimir_estados(Estado *estados){
   int i;
  for(i=0;i<32;i++){
    printf("%d:%s --- %s\n",i,estados->nombre,estados->capital);
    estados++;
  }
}

char *busca_capital(Estado *estados,char *estado_buscado){
    int i=0;
    while(i<32 && strcmp(estados->nombre,estado_buscado)!=0  ){
        estados++;
        i++;
      }
    if(i<32) return estados->capital;
    else return NULL;
}

void ejercicio_prop1(){

  Estado *lista_estados;
  char nom_estado[20]={0},*capital;

  lista_estados=cargar_estados();
  printf("Ingresa el estado:");
  fgets(nom_estado,sizeof(nom_estado),stdin);
  nom_estado[strcspn(nom_estado, "\n")] = '\0';
  capital=busca_capital(lista_estados,nom_estado);
  if(capital!=NULL){
     printf("\n Su capital es:%s",capital);
  } else printf("No se encontró el estado\n"); 
  
  //imprimir_estados(lista_estados);

}