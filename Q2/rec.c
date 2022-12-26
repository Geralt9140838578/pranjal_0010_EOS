
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

#define BUFF_SIZE 64
char buff[BUFF_SIZE];
struct mq_pranjal_attr;
int op = fopen("deadXam", O_RDWR);
int main()
{
    mqd_t pranjal_mq_desd;
    int pranjal_rcv_bytes,a_close;
    pranjal_attr.mq_flags=0;
    pranjal_attr.mq_maxmsg=10;
    pranjal_attr.mq_msgsize=64;
    pranjal_attr.mq_curmsgs=0
    pranjal_mq_desd=mq_open("/deasXam",O_CREAT|O_RDONLY,S_IRUSR|S_IWUSR,&pranjal_attr);
    if(pranjal_mq_desd==-1)
    {
        perror("error in opening msg\n");
        exit(EXIT_FAILURE);
    }
    pranjal_rcv_bytes=mq_receive(pranjal_mq_desd,buff,64,0);
    if(pranjal_rcv_bytes==-1)
    {
        perror("error in recieving msg\n");
        exit(EXIT_FAILURE);
    }
    printf("received msg:: %s\n",buff);
    if(buff!= NULL)
    {
        for (int i =0 ; buff[i]!='\0';i++);
        {
        int count ++;
        printf("%d\n",count);
        }

        else{
            printf("empty\n");
        }
    }

    a_close=mq_close(pranjal_mq_desd);
    if(a_close==-1)
    {
        perror("error in closing msg\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}