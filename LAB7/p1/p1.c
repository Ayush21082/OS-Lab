#include<stdio.h>
#include<pthread.h>

	int sum[4];
	int i[]={1,2,3,4,5,6,7,8,9,10,11,12};

	void *function (void *arg){

		int index= (int)arg;
		int start = index * 3;
		int cnt=0;

	while (cnt<3){
		sum[index] += *(i+cnt+start);
		cnt++;
	}
	printf("index=%d, its sum =%d \n",index,sum[index]);
}

int main(){

	pthread_t t1,t2,t3,t4;

	pthread_create (&t1, NULL, function, (void *)0);
	pthread_create (&t2, NULL, function, (void *)1);
	pthread_create (&t3, NULL, function, (void *)2);
	pthread_create (&t4, NULL, function, (void *)3);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);

	printf("%d\n", sum[0] + sum[1] + sum[2] + sum[3]);
}
