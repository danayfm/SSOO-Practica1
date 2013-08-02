#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    DIR *direccion;
	struct dirent *leido;
	int descriptor;
    char dirActual[PATH_MAX];
	getcwd(dirActual, PATH_MAX); /*Obtiene la ruta del directorio actual*/
	direccion=opendir(dirActual); /*Abre el directorio*/
	if(direccion==NULL){ /*Si direccion==NULL, no ha podido abrirse el directorio*/
		printf("No se ha podido abrir el directorio");
		return -1;
	}else{
		leido = readdir (direccion); /*Va leyendo los ficheros del directorio*/
		while(leido!=NULL){ /*Mientras que se lea algún fichero, sigue el bucle*/
			long tam=0;
            		if(leido->d_type==DT_REG){ /*Comprueba que el archivo leído sea un fichero, y si lo es, lo abre, se desplaza a la */
									   /*última posición (que coincide con su tamaño e imprime el nombre y tamaño del fichero*/
                	descriptor=open(leido->d_name,O_RDWR);   
			tam=lseek(descriptor, 0L, SEEK_END);
			         printf("%s\t%ld\n", leido->d_name, tam);  
				close(descriptor); /*Al terminar cierra el fichero*/
			} 
			leido = readdir (direccion);
		}
	}
	closedir(direccion); /*Al terminar cierra el directorio*/
	return 0;
}
