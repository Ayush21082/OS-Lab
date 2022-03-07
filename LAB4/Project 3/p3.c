#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

        int fd1, fd2;    
        char c;       
        int offset;    

        fd1 = open("first_file", O_RDONLY);      //open file to read
        if (fd1 < 0) {
                printf("%s", "Open error");
        }

        fd2 = open("second_file", O_WRONLY | O_CREAT);   
        if(fd2 < 0) {
                printf("%s", "Open error");
        }

        offset = lseek(fd1, 0, SEEK_END);    //go to the end of the file

        while (offset > 0) {  
                read(fd1, &c, 1);  
                write(fd2, &c, 1); 
                lseek(fd1, -2, SEEK_CUR);
                offset--;     
        }

        close(fd1);  //close the files
        close(fd2);

        return 0;

}
