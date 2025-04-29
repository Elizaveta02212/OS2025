//Изменение пользовательского контекста процесса
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
	int result;
	pid_t pid, ppid;
	pid = getpid();
	ppid = getpid();
	printf("идентификатор текущего процесса: %d, Ид. родительского процесса: %d\n", pid, ppid);
	printf("Выполняем fork()\n");
	result = fork();
	if (result > 0) {
		pid = getpid();
		ppid = getpid();
		printf("Работает процесс родитель\n");
		printf("Псоле запуска fork():\n");
		printf("идентификатор текущего процесса: %d, Ид. родительского процесса: %d\n", pid, ppid);
		printf("Родитель завершил работу\n");

	}
	else if(result == 0){
		printf("заменяем пользв контекст проц ребенка\n");
		(void) execle("./pr002.out", "./pr002.out", 0, envp);
		printf("Ошибка при выполнении сист вызова exec\n");
		exit(-1);
	
	}
	else {
		printf("Ошибка при выполнении вызова fork\n");
		exit(-1);
	}
	return 0;
	
}
