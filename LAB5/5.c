#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
pid_t PID=fork();
if (PID>0) {
printf("I am Parent %d I am going to wait for my child\n", getppid());
int child_status=wait(NULL);
printf("I am Parent %d My childs return status is %d \n", getppid(), child_status);
}
else if (PID==0){
printf("I am Child %d\n", getpid());
printf("My parent is %d\n", getppid ()) ;
exit(0);
}
else{
printf ("ERROR" );
}
return 0;
}
