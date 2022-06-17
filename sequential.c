#include<stdio.h>
#include<conio.h>
int a[20],num=0;
int fid[10],length[10],start[10];
void filedescriptor();
void display();
void filedescriptor()
{
     int i;
     printf("\n file id \t starting address \t length \n");
     for(i=0;i<num;i++)
    printf("%d\t\t\t %d\t\t%d\n",fid[i],start[i],length[i]);
    }
void display()
   {
           int i;
          for(i=0;i<20;i++)
printf("%2d",i);
            printf("\n");
            for(i=0;i<20;i++)
	printf("%2d", a[i]);
     }
void  main()
   {
	int i,n,k,temp,st,l,id,flag=0,cho;
	for(i=0;i<20;i++)
	 a[i]=0;
	 clrscr();
	 printf("\n Memory before allocation:\n");
	display();
	 while(1)  {
	printf("\n Enter the file id:");
	scanf("%d",&id);
	printf("\n Enter the number of blocks the file occupies:");
	scanf("%d", &l);
	fid[num]=id;
	length[num]=l;
	printf("\n Enter the starting address:");
	scanf("%d", &st);
	flag=0;
	 if((st+l)>20)
	{
	printf("\n Sorry the given memory goes out of space:");
	goto l;    }
	for(i=st;i<(st+l);i++) {
	 if(a[i]!=0) {
	flag=1;
	break;
	}}
	if(flag==0)  	{
	 start[num]=st;
	for(i=st;i<(st+l);i++)
	a[i]=id; }
	else
	{
	printf("\n Sorry the given blocks are already occupied: Enter new starting address");
	goto l; 	 }
	 flag=0;
	 num++;
	filedescriptor();
	 printf("\n Memory after allocation \n");
	 display();
	 printf("\n Want to continue? \n1.yes \n2.no");
	 scanf("%d",&cho);
	 if(cho==2)
	exit(0);
	}}	