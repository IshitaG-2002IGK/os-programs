#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#define num 10
#define se 10
#define sf 0
int main()
{
int rc,pid,semid;
int shmid,status,i;
char elem;
union semun
{
int val;
}mysemun;
struct sembuf waitempty={se,-1,SEM_UNDO};
struct sembuf signalempty={se,1,IPC_NOWAIT};
struct sembuf waitfull={sf,-1,SEM_UNDO};
struct sembuf signalfull={sf,1,IPC_NOWAIT};
struct shmid_ds myshmid_ds;
void *shmptr;
semid=semget(IPC_PRIVATE,2,0666 | IPC_CREAT);
mysemun.val=num;
semctl(semid,se,SETVAL,mysemun);
mysemun.val=0;
semctl(semid,sf,SETVAL,mysemun);
shmid=shmget(IPC_PRIVATE,num,0666 | IPC_CREAT);
pid=fork();
if(pid==0)
{
shmptr=shmat(shmid,0,SHM_R);
for(i=0;i<10;i++)
{
semop(semid,&waitfull,1);
elem=*((char *)shmptr+(i%num));
printf("consumed element %c\n",elem);
semop(semid,&signalempty,1);
sleep(1);
}
exit(0);
}
else
{
shmptr=shmat(shmid,0,SHM_W);
for(i=0;i<10;i++)
{
semop(semid,&waitempty,1);
elem='i'+i;
printf("produced element %c\n",elem);
*((char *)shmptr+(i%num))=elem;
semop(semid,&signalfull,1);
sleep(2);
}
}
wait(&status);
shmctl(shmid,IPC_RMID,&myshmid_ds);
semctl(semid,se,IPC_RMID,mysemun);
exit(0);
}
