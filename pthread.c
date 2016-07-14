#include<stdio.h>
#include<pthread.h>

//some contrcl of thread

//void *pthread_run(void* arg)
//{
//	while(1){
//		printf("this is thread...\n");
//		sleep(1);
//	}
//}
//int main()
//{
//	pthread_t id;
//	pthread_create(&id,NULL,pthread_run,NULL);
//	int count = 0;
//	while(count++ < 5){
//		sleep(1);
//	}
//
//	pthread_cancel(id);
//
//	void *ret = NULL;
//	pthread_join(id,&ret);
//	printf("%d\n",(int)ret);    //why is (int)ret??why not *(int *)ret
//	return 0;
//}

//pthread_mutex

int g_val = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *pthread_run(void *arg)
{
	int i = 0;
	int val = 0;
	while(i < 5000){
		pthread_mutex_lock(&lock);
		val = g_val;
		printf("g_val:%d\n",g_val);
		g_val = val+1;
		pthread_mutex_unlock(&lock);
		i++;
	}
}
int main()
{
	pthread_t id1,id2;
	pthread_create(&id1,NULL,pthread_run,NULL);
	pthread_create(&id2,NULL,pthread_run,NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_mutex_destroy(&lock);
	printf("%d\n",g_val);
	return 0;
}
