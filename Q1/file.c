#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
int main(int argc,char const* argv[])
{
    int fd=0;
    fd=open("desdXam",O_RDWR | O_CREAT);
    write(fd,"HELLO",5);
    close(fd);
    return 0;
}