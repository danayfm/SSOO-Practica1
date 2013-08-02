all:
	gcc -Wall -o mycat mycat.c 
	gcc -Wall -o myls myls.c
	gcc -Wall -o mysize mysize.c 

clean:
	rm -f mycat myls mysize
