#include <stdio.h>
#include <pthread.h>

#define N 10

void* child(void *arg){
	printf("thread #%d\n",*(int *)arg);
}

int main(int argc, char const *argv[])
{
	int i;
	int tmp[N];
	pthread_t tid[N];
	int result;
	for (i = 0; i < N; i++)
	{
		tmp[i]=i;
	}
	for (i = 0; i < N; i++)
	{
		result=pthread_create(&tid[i],NULL,child,tmp+i);
		if (result)
		{
			printf("Error:return code form pthread_create() is %d\n",result);
		}else{
			printf("create thread %ld\n",i);
		}
	}
	for (i = 0; i < N; i++)
	{
		pthread_join(tid[i],NULL);
	}
	printf("main thread exit\n");
	return 0;
}