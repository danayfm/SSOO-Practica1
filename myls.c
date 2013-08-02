#include <stdio.h>		/*Cabecera llamada al sistema printf*/
#include <unistd.h>		/*Cabecera llamada al sistema getcwd*/
#include <sys/types.h>		/*Cabeceras llamadas al sistema opendir, readdir y closedir*/
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[]){
	DIR *direccion;
	struct dirent *leido;

	/*Si no se le pasa un directorio, realiza el ls del directorio actual*/
	if (argc<2){
		char dirActual[PATH_MAX];
		getcwd(dirActual, PATH_MAX); /*Obtiene el dir. actual*/
		direccion=opendir(dirActual); /*Abre el directorio*/
		}
	else {
		direccion = opendir(argv[1]); /*Abre el directorio, el 2º parámetro pasado*/
		}
		if(direccion==NULL){ /*Si la dirección devuelta por el opendir es NULL, no se ha podido abrir*/
		printf("No se ha podido abrir el directorio \n");
		return -1;
		}else{ /*Va leyendo los ficheros e imprimiendo su nombre por pantalla, hasta que leido==NULL, se llegue al final del directorio (no se lea nada)*/
			leido = readdir (direccion);
			while(leido!=NULL){
			printf("%s\n", leido->d_name);
			leido = readdir (direccion);
			}
		}
		closedir(direccion);
	return 0;
}

