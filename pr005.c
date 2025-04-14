#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	pid_t prid, parprid;
	int a = 0, c;
	prid = getpid();
	printf("До выполнения fork():\n");
	printf("Ид. текущего процесса: %d\n", prid);
	printf("Ид. Родительского процесса: %d\n", parprid);
	printf("Начальное значение переменной: %d\n", a);
	c = fork();
	if(c<0) {
		printf("Ошибка при вызове fork()");
		exit(-1);
	
	}
	else if (c==0){
		printf("Выполнение дочернего процесса\n");
		a = a+1;
		prid = getpid();
		parprid = getppid();
		printf("После выполнения fork():\n");
		printf("Ид. текущего процесса: %d\n", prid);
		printf("Мд. родительского поцесса: %d\n", parprid);
		printf("Значение переменной: %d", a);
	}
	else {
		printf("%d", c);
		a = a+1000;
		prid = getpid();
		parprid = getppid();
		printf("Посл выполнения fork() для родительского процессф: \n");
		printf("Ид. текущего процесса: %d\nИд. родительского процесса: %d\n", prid, parprid);
		printf("Значение переменной a: %d\n", a);
	}
	return 0;
}
