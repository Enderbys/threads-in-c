#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int x=0;
void * thread1(void *vptr)
{
	int x=0;
    while(1)
    {
		printf("%.3d\n",x);
		x++;
		fflush(stdout); 
		usleep(500000);
	}
}

void * thread2(void *vptr)
{
	char ch;
        while(1){
			scanf("%c",&ch);
			printf("\n\n%c\n\n",ch);	
        }
}

int main()
{
        int status;
        pthread_t tid1,tid2;

        pthread_create(&tid1,NULL,thread1,NULL);
        pthread_create(&tid2,NULL,thread2,NULL);
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        return 0;
}
