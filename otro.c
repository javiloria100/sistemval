
// LISTA PARA ALMACENAR DATOS DEL ARCHIVO
struct  lista{
int valor;
struct lista *prox;
};

//DEFINE LA UNION DE MEMORIA
union semun{
	int val;
	struct semid_ds * buf;
	short int *array;
	struct seminfo *__buf;
};


int crearSemaforo(){
key_t Llave;
int semaforo;    //identificador o id del semaforo
struct sembuf Proceso; // direcciones de las acciones que realizará el Semaforo
int i = 0 ;
Llave = ftok ("/bin/ls", 313);       /*archivo del sistema y un numero cualquiera para definir la
llave este es el mismo en todos los procesos que van a compartir el Semaforo */

					/* CREO EL SEMAFORO */
	semaforo = semget (Llave, 3, 0600 | IPC_CREAT);
	/* DEFINICION DE PARAMETROS:
	1: llave: direccion del semaforo
	2: cantidad de semaforos que queremos(arreglo). Se puede usar uno de exclusión mutua y otro de contador ...
	3: permisos en este caso lectura y escritura "0600"
	4: bandera en el caso de IPC_CREAT es una bandera que si no existe indica que debe crearse
	*/


			/* INICIALIZACION DE LOS SEMAFOROS  */

	/* ENCARGADO DE EXCLUSION MUTUA*/
	semctl (semaforo, 0, SETVAL, 1);    //lo defino en uno para que entre "verde"

	/*ENCARGADO DE IR A LA DERECHA "R"*/
	semctl (semaforo, 1, SETVAL, 9);
	/*lo definimos en 9 porque son diez el cual es el maximo de circulantes en cada sentido.  "ULTIMO PARAMETRO" */

	/*ENCARGADO DE IR A LA IZQUIERDA "L"*/
	semctl (semaforo, 0, SETVAL, 9);
	/*lo definimos en 9 porque son diez el cual es el maximo de circulantes en cada sentido. "ULTIMO PARAMETRO" */
	/*     DEFINICION DE PARAMETROS:
	1: id del semaforo a inicializar
	2: id del arreglo del semaforo
	3: funcion "SETVAL" que indica que debe cambiar el valor del semaforo
	4: valor a colocarle
	*/


}





void Sendero(){
int entrada=1;
	while(entrada !=0){
		printf("INTRODUZCA VALOR");
		scanf("%i",&entrada);
		if(entrada ==1){
			crearProceso();


		}
			/*
			if(sem !=0 ){
				sem.down();
				escribirEnArchivo(proceso);
			}
			*/
	}
}
