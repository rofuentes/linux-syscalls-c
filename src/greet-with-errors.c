#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int fd;
    /*
       Symbolic constants:
       O_WRONLY write only
       O_CREAT if file does not exist, create it
       System calls do not throw exceptions. Rather, the return value
       of the call is set to -1 on failure.
    */
    if ((fd = open("foo", O_WRONLY | O_CREAT, 0644)) < 0) {
        /*
           Errors set the global integer variable errno, set to a value
           which corresponds to the error. Symbolic constants relate
           values to names. Errno is only set if an error occurs.
        */
        printf("error number %d\n", errno);
        /* Print given text and message corresponding to errno */
        perror("foo");
        exit(1);
    }
    write(fd, "hello world", 11);
    close(fd);
}
