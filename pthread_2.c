#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
//#include <sys/time.h>
#include <string.h>

#define MAX 10

pthread_t thread[3];
pthread_mutex_t mut;

int num = 0, i;

void *thread1(){
/*
	printf("thread 1: I'm thread 1\n");
	for(i = 0; i < MAX; i++){
		printf("thread 1: number = %d\n", num);
		pthread_mutex_lock(&mut);
		num++;
		pthread_mutex_unlock(&mut);
		sleep(2);
	}
	printf("Thread 1 finish?\n");
*/
	system("/home/hao/Ccode/Motor/init");
	pthread_exit(NULL);
}

void *thread2(){
/*
	printf("thread 2: I'm thread 2\n");
	for(i = 0; i < MAX; i++){
		printf("thread 2: number = %d\n", num);
		pthread_mutex_lock(&mut);
		num++;
		pthread_mutex_unlock(&mut);
		sleep(3);
	}
	printf("Thread 2 finish?\n");
*/
	system("/home/hao/Ccode/MPU6050/mstest");
	pthread_exit(NULL);
}
void *thread3(){
	system("/home/hao/Ccode/Motor/run");
	pthread_exit(NULL);
}

void thread_create(){
	int temp;
	memset(&thread, 0, sizeof(thread));
	if((temp == pthread_create(&thread[0], NULL, thread1, NULL)) != 0){
		printf("Thread 1 create false\n");
	}else{
		printf("Thread 1 create sucess\n");
	}
	if((temp == pthread_create(&thread[1], NULL, thread2, NULL)) != 0){
		printf("Thread 2 create false\n");
	}else{
		printf("Thread 2 create sucess\n");
	}
	if((temp == pthread_create(&thread[2], NULL, thread3, NULL)) != 0){
		printf("Thread 3 create false\n");
	}else{
		printf("Thread 3 create sucess\n");
	}
}

void thread_wait(){
	if(thread[0] != 0){
		pthread_join(thread[0], NULL);
		printf("Thread 1 was finished\n");
	}
	if(thread[1] != 0){
		pthread_join(thread[1], NULL);
		printf("Thread 2 was finished\n");
	}
	if(thread[2] != 0){
		pthread_join(thread[2], NULL);
		printf("Thread 3 was finished\n");
	}
}


int main(){
	pthread_mutex_init(&mut, NULL);
	printf("Creating thread...\n");
//	sleep(2);
	thread_create();
	printf("Wait thread finish...\n");
//	sleep(2);
	thread_wait();
	return 0;
}
