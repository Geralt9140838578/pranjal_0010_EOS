#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#define BUFF_SIZE 64
char buff[BUFF_SIZE];
struct mq_attr pranjal_attr;



int main()
{
    mqd_t pranjal_mq_desd;
    int pranjal_send_bytes,a_close;
    mq_pranjal_attr.mq_flags=0;
    mq_pranjal_attr.mq_maxmsg=10;
    mq_pranjal_attr.mq_msgsize=64;
    mq_pranjal_attr.mq_curmsgs=0;
    int send=1;

    pranjal_mq_desd = mq_open("/desdXam",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR,&mq_pranjal_attr);
    if(pranjal_mq_desd == -1)
    {
        perror("error in opening msg\n");
        exit(EXIT_FAILURE);
    }
    pranjal_send_bytes=mq_send(pranjal_mq_desd,"INDIA IS THE BEST\n",20,0);

    pranjal_mq_desd = mq_open("/desdXam",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR,&mq_pranjal_attr);
    if(pranjal_mq_desd == -1)
    {
        perror("error in opening msg\n");
    exit(EXIT_FAILURE);
    }
    pranjal_send_bytes=mq_send(pranjal_mq_desd,"i am student of cdac\n",20,0);
    if(pranjal_send_bytes == -1)
    {
        perror("error sending msg\n");
        exit(EXIT_FAILURE);
    }
    a_close=mq_close(pranjal_mq_desd);
     if(a_close == -1)
    {
        perror("error in closing msg\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}