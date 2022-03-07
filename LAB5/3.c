#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>

int main(){
pid_t PID = fork();
if(PID>0) {
sleep(10);
printf("I am Parent %d\n", getppid());
}
else if(PID==0){
printf("I am Child %d\n" , getpid());
exit(0);
}else{
printf("ERROR");
}
return 0;
}
