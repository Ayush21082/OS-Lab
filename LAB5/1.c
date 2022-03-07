#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

int main() {
int PID=fork() ;
if (PID>0){
printf ("parent %d\n", getppid());
}
else if (PID==0) {
printf("CHILD %d" , getpid());
}
else {
printf ("ERROR") ;
}
return 0;
}

