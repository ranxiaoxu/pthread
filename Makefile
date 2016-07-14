pthread:pthread.c
	gcc -o pthread pthread.c -lpthread
.PHONY:clean
clean:
	rm -f pthread

