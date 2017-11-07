//ejercicio 4
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>                      //Libreria de semaforos
//#include <sys/types.h >
#include <unistd.h>
/* DETALLES O DATOS IMPORTANTES
si el semaforo es igual a 0 entonces esta en rojo, en otras palabras no hay paso
BASH = TERminal
*/

#include <string.h>
#define N 100

/* DEFINIENDO LISTA PARA LA ENTRADA */
struct lista_Entrada {
 char caracter;
 struct lista_Entrada *prox;
 }*lista;

void* hola (void* argumento ){
	printf("HOLAAAAAAAA qlq parcee \n");
}


int crearProceso(){

pid_t pid ;
/* pid: identificador  de procesos es un número entero usado por el kernel.
Para asignar el PID, el kernel utiliza internamente una variable global que se va incrementando
con cada nuevo proceso creado con una llamada fork(). Cuando la variable alcanza un cierto valor límite se empieza
otra vez desde 0, buscando números que no estén asignados ya a otro proceso en ejecución. */

/* CREACION DE PROCESOS */
pid = fork () ; //crea una replica del proceso que lo creo

//VER QUE PROCESOS SE EJECUTAN USAMOS "ps -fe"

/* SI ENTRO ACA ES QUE NO SE CREO CORRECTAMENTE	*/
	if ( pid == -1) {
		printf ( "Fallo en fork \n " ) ;
		return -1;
	} else{
		if ( pid== 0 ) {
			printf ( " SOy Proceso hijo : PID %d , ID DEL PAPA %d\n " , getpid (),  getppid() ) ;
		} else { //primero entra el papa
			printf ( "Soy Proceso padre : PID %d \n \n" , getpid () ) ;
			fork();
		}
		printf("SE EJECUTA 3 veces jaja\n" ); // a estas alturas tendre 3 procesos aca
		return 0;
//}
}
}
/*
getpid(): devuelve el id de el proceso actua
getppid(): devuelve el id de su padre. si uso esta desde el padre de todo me devuelve el terminal que es el que o ejec
*/

/*ENCARGADA DE LEER LA ENTRADA Y GUARDARLA EN ARCHIVO*/
int entrada(){

	FILE *archivo;


	 	char caracteres[100];

	 	archivo = fopen("fichero.txt","r");

	 	if (archivo == NULL)
	 		exit(1);
	 	else{
	 	    printf("\n	El contenido del archivo de entrada es \n\n");

/*
					while (feof(archivo) == 0){
				 		fgets(caracteres,100,archivo);
							while(!lista){
								lista=lista_>prox;
							}
						 lista= new (lista_Entrada);
						 lista_>prox =NULL;
						lista_>caracter =caracteres;
						printf("%s",caracteres);

	*/
						while (feof(archivo) == 0){
						fgets(caracteres,100,archivo);
				 		printf("%s",caracteres);
	 	    		}
	          //  system("PAUSE");
	        }
	        fclose(archivo);

	return 0;
}



int salida(char caracter){
	FILE *fp;
	 	fp = fopen ( "salida.txt", "a+t" ); //parametro para escritura al final y para file tipo texto

	 	printf("\nIntroduce un texto al fichero: ");
	 	{
	 		printf("%c", fputc(caracter, fp));
      fputc('\n', fp); //para que solo escriba un caracter por linea
	 	}

	 	fclose ( fp );

	 	return 0;


}




//PRINCIPAL
int main( int argc, char *argv[ ], char *envp[ ] ){
printf("HOLAAA \n\n\n");

entrada();
salida('L');
crearProceso();
//ACA tengo 3 procesos osea hago 3 veces todo de aca para abajo asi que mosca
salida('R');
printf("HOLAAAAAAAAA\n");


//hola("epales");

//Sendero();
return  0;
}
