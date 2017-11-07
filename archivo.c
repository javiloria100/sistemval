/*Objetivo: Cambia el \n por \0 en los string, ya que son leidos con fgets
Prametros recibidos: string al cual se le modifica su terminacion '\n'*/
void cambio(char x[]) {
	int i = 0;

	while (i < strlen(x)) {
		if (x[i] == '\n')
			x[i] = '\0';

		i++;
	}

}



int leer_Entrada(FILE *f, string *string, lista_Entrada **p, ) {

	char cadena[N];
	int numero_int, i = 0, encontrado = 0, error = 0;
	long numero_long;

	lista_Entrada *aux, *t;
	//Se crea una nueva "cajita" con sus punteros a otras "cajitas" inicializados en NULL
	aux = new lista_Entrada;
	aux->prox_Entrada = NULL;

	do {
		while (fgetc(f) != 'R' && fgetc(f)!='L');  //Se posiciona en el "R" o "L" de la linea

		fgets(cadena, N, f);  //Lee la linea hasta el "\n"
		cambio(cadena);  //Cambia el "\n" por "\0" del string

		i++;


		if (!(*p))
			*p = aux;
		else {
			t = *p;
			while ((t) && (t->prox_Entrada))
				t = t->prox_Entrada;

			t->prox_Entrada = aux;
		}

		textcolor(10);
		printf("    BUENO. \n");

	textcolor(7);

}
}  // ------ FIN LEER_ENTRADA -------




void entrada(){
	char opcion[N];
lista_Entrada *entrada = p;

FILE *f;

printf(" Nombre del Archivo (NO USAR '.TXT'): ");
leer_cadena(opcion);
strcat_s(opcion, ".txt");
fopen_s(&f, opcion, "w");



}
