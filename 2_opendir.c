#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
int main(int c,char* arg[])
{
    DIR *d;
    struct dirent *r;
    d=opendir(arg[1]);
    printf("\n\t Name of the Files \n");
    while((r=readdir(d)) != NULL)
                printf("\t %s \n",r->d_name);
}