#include <stdio.h>		/* Cabecera llamada al sistema printf */
#include <sys/types.h>		/* Cabeceras llamada al sistema open */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>		/* Cabecera llamadas al sistema read, write y close */

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
	int descriptor;
	char buffer[BUFFER_SIZE];
	int numbytes;

	/*Si los argumentos son menores que dos (argv[0] -> programa, argv[1] -> fichero a mostrar) imprimimos error y retornamos -1 */
	if(argc < 2){
		printf("Argumentos insuficientes\n");
		return -1;
	}else{	
		/*Abre el fichero y guarda su descriptor*/
		descriptor = open(argv[1], O_RDWR);
		if (descriptor==-1){ /*Si descriptor vale -1, no ha podido abrir el fichero*/
			printf("No Existe el fichero\n");
		}else{ /*Si el descriptor es distinto de -1 (ha abierto el fichero), sigue*/
		       /*el programa: va leyendo el fichero y escribiéndolo por pantalla*/
		       /*hasta que la variable numbytes devuelva 0 (no se ha leído nada).*/
			numbytes=read(descriptor, buffer, BUFFER_SIZE);
			/*Si el fichero no está vacío*/
			if (numbytes != 0){
				do{
				write(STDOUT_FILENO, buffer, numbytes);
				numbytes=read(descriptor, buffer, BUFFER_SIZE);
				}while (numbytes !=0);
			}
		}
		close(descriptor);
	}
	return 0;
}

