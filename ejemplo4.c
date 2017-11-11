//ejercicio 4
#include <stdio.h>
#include <stdlib.h>
//#include <sys/sem.h>                      //Libreria de semaforos
#include <semaphore.h>
//#include <sys/types.h >
#include <unistd.h>
#include "listaEnlazada.h"

/* DETALLES O DATOS IMPORTANTES
si el semaforo es igual a 0 entonces esta en rojo, en otras palabras no hay paso
BASH = TERminal
*/

#include <string.h>
#define N 100   //TAMAÑO DE BUFER

    pid_t proceso1,proceso2 ;
     char nueva[5],proceso;




 /* Declaración de LISTA*/
 struct element {
   char caracter;
   int tiempo;
   struct element *sig;
 }*lista;
 int salida(char caracter){
 	FILE *fp;
 	 	fp = fopen ( "salida.txt", "w" ); //parametro para escritura al final y para file tipo texto

 	 	{
 	 		//printf("%c", fputc(caracter, fp));
       fputc('\n', fp); //para que solo escriba un caracter por linea
 	 	}

 	 	fclose ( fp );

 	 	return 0;


 }

//DEFINE LA UNION DE MEMORIA
union semun{
	int val;
  	struct semid_ds * buf;
	short int *array;
	struct seminfo *__buf;
};


int entrada(pid_t proceso1, pid_t proceso2){

	FILE *archivo;


	 	char caracteres[100];

	 	archivo = fopen("fichero.txt","r");

	 	if (archivo == NULL)
	 		exit(1);
	 	else{
        /* DENTRO DEL ARCHIVO*/
						while (feof(archivo) == 0){
						fgets(caracteres,100,archivo);

            if(proceso1==0){
              salida('r');
                }
              else {
                if(proceso2==0){
                salida('2');
              }
            }


	 	    		}
	          //  system("PAUSE");
	        }
	        fclose(archivo);

	return 0;
}


//PRINCIPAL
int main( int argc, char *argv[ ], char *envp[ ] ){

  /* Declaracion*/
  sem_t mutex,sR,sL;
    pid_t procesoL,procesoR ;
    nodo *A = NULL;
      nodo *aux=NULL;

int entero;
float timpos,decimal;
  /*Inicialización de Semáforos*/
  sem_init(&mutex,1,1);
  sem_init(&sR,1,10);
   sem_init(&sL,1,10);              /* PROBLEMA ACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA*/

//creacionSemaforos();

salida('L');
int numero;


/* pid: identificador  de procesos es un número entero usado por el kernel.
Para asignar el PID, el kernel utiliza internamente una variable global que se va incrementando
con cada nuevo proceso creado con una llamada fork(). Cuando la variable alcanza un cierto valor límite se empieza
otra vez desde 0, buscando números que no estén asignados ya a otro proceso en ejecución. */

/* CREACION DE PROCESOS */

//procesoL = fork () ; //crea una replica del proceso que lo creo

//VER QUE PROCESOS SE EJECUTAN USAMOS "ps -fe"

/* SI ENTRO ACA ES QUE NO SE CREO CORRECTAMENTE	*/
/*
  if ( procesoL == -1) {
		printf ( "Fallo en fork \n " ) ;
		return -1;
	}
  else{
		if ( procesoL== 0 ) {
			//printf ( " SOy Proceso hijo : PID %d , ID DEL PAPA %d\n " , getpid (),  getppid() ) ;
		} else { //primero entra el papa
			//printf ( "Soy Proceso padre : PID %d \n \n" , getpid () ) ;
			 procesoR =fork();
		}
		//printf("SE EJECUTA 3 veces jaja\n" ); // a estas alturas tendre 3 procesos aca
    if(procesoL==0){
      //printf(" PROCESOOOOOOO 1: %d   : PID %d , ID DEL PAPA %d \n",proceso1, getpid (),  getppid());
      salida('1');

    }

    if(procesoR==0){
        printf(" PROCESOOOOOOO 2: %d    : PID %d , ID DEL PAPA %d\n",proceso2, getpid (),  getppid());
        salida('2');
    }
//}
}
*/

//entrada(proceso1,proceso2);
FILE *archivo;


  char caracteres[100];

  archivo = fopen("fichero.txt","r");

  if (archivo == NULL)
    exit(1);
  else{
      /* DENTRO DEL ARCHIVO*/
        //if((procesoR!=0)&&(procesoL!=0)){
          while(!feof(archivo)) { // Mientras no sea el final del archhivo
              // contLineas++; //contar lineas
    		fgets(caracteres, 100, archivo);  //Lee la linea hasta el "\n"
        cambio(caracteres);  //Cambia el "\n" por "\0" del string
        if(strlen(caracteres)>4){
        //  printf("%s",caracteres);
        for( int a = 0; a < 2; a++ )
        nueva[ a ] = caracteres[ a ];
//  printf("caracteres %s\n", caracteres);
entero= atoi(nueva);
printf("entero:   %d\n", entero);
// Inserto el elemento que se convirtió a entero en la lista enlazada

proceso=caracteres[6];
//printf("char: %c\n",proceso );
insertarPorColaConRep(&A, entero,proceso);
}


       }

    		//cambio(cadena);  //Cambia el "\n" por "\0" del string

      //      lista->caracter=caracteres;
          //  switch (lista->caracter) {
            /*  case 'R':
                      if(procesoR==0){
                        salida('2');
                        exit(procesoR);

              }
              break;
              case 'L': if(procesoL==0){
                salida('r');
                sem_wait(&mutex);
                sem_wait(&derecha);
                exit(procesoL);
                  }
                  break;
            }



  */
            //}

          } //else

           mostrarLista(A); // system("PAUSE");
          //if((procesoR!=0)&&(procesoL!=0)){
            fclose(archivo);
            //ACA tengo 3 procesos osea hago 3 veces todo de aca para abajo asi que mosca

            int valorinicial,auxvalorinicial;
            char charinicial,auxcharinicial;
            //MANEJO DEL SEMAFORO
              if(A){
                valorinicial=A->valor;
                charinicial=A->proceso;
                    procesoL=fork();
                    if ( procesoL== 0 ) {
                      //printf ( " SOy Proceso hijo : PID %d , ID DEL PAPA %d\n " , getpid (),  getppid() ) ;
                    } else { //primero entra el papa
                      //printf ( "Soy Proceso padre : PID %d \n \n" , getpid () ) ;
                       procesoR =fork();
                     }
                aux=A->prox;
                  while(aux){
                    auxvalorinicial=aux->valor;
                    auxcharinicial=aux->proceso;
                      if(auxvalorinicial!= valorinicial){

                           printf("voy aca %c \n",charinicial);
                           if(charinicial=='L'){
                             printf("LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLl\n" );
                             if(procesoL==0){
                               printf("entreeeEEEEEEEEEEEEEEEEEEEEEEEEEE\n" );
                               salida('L');
                             }

                           }
                           else {
                             if(procesoR==0){
                               salida('R');

                           }

                         }
                        }

                      aux=aux->prox;
                      valorinicial=auxvalorinicial;
                      charinicial=auxcharinicial;
                      }


                }



              }
