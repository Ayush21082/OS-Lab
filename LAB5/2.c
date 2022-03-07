#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

int main(){
pid_t p= fork();
if(p==0){
sleep(5);
printf("I am Child : %dIn", getpid());
printf ("Parent %d\n", getppid());
}else{
printf("I am Parent %d\n", getppid());
printf ("Child : %d\n", getpid());
}
return 0;
}
