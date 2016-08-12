#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
struct record {
    int id;
    char name[80];
};

int print()
{
}

void main()
{
    int fd, size = sizeof(struct record);
    struct record info;

    fd = open("data", O_RDWR | O_CREAT | O_TRUNC, 0644);

    /* First Record */
    info.id = 10;
    strcpy(info.name, "Ann");
    write(fd, &info, size);
    printf("The first record is:\n");
    printf("ID: %d\nName: %s\n", info.id, info.name);

    /* Second Record */
    info.id = 20;
    strcpy(info.name, "Bob");
    write(fd, &info, size);
    printf("The second record is:\n");
    printf("ID: %d\nName: %s\n", info.id, info.name);

    lseek(fd, size, SEEK_SET);
    read(fd, &info, size);

    /* Change second record id */
    info.id = 99;
    lseek(fd, -size, SEEK_CUR);
    write(fd, &info, size);
    printf("The modified second record is:\n");
    printf("ID: %d\nName: %s\n", info.id, info.name);

    close(fd);
}
