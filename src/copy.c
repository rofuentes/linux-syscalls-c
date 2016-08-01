#include <fcntl.h>
#include <stdlib.h>
/* Size of chunks to read/write. Multiple of block size. */
#define BSIZE 16384

void main()
{
    int fin, fout;  /* Input and output handles */
    char buf[BSIZE];
    int count;

    /*
    Open syscall notes:
    Must choose one of: O_RDONLY, O_WRONLY, O_RDWR
    May also specify one of: O_APPEND, O_CREAT, O_TRUNC (if exists)
    Symbolic constants that are single bit values can be combined.

    Returns the lowest available file descriptor.
    0: stdin, 1: stdout, 2: stderr, 3: first available @ start
    Program is unaware if any of these are redirected.
    */
    if ((fin = open("foo", O_RDONLY)) < 0) {
        perror("foo");
        exit(1);
    }
    if ((fout = open("bar", O_WRONLY | O_CREAT, 0644)) < 0) {
        perror("bar");
        exit(2);
    }
    /*
    Read syscall notes:
    Returns number of bytes read, 0 at EOF.
    */
    while ((count = read(fin, buf, BSIZE)) > 0)
        /*
        Write syscall notes:
        buf is a pointer to data
        count is the size of buffer (not checked)
        */
        write(fout, buf, count);

    /* Closing frees the descriptor for reuse. */
    close(fin);
    close(fout);
}
