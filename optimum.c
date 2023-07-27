#include<stdio.h>
#include<stdbool.h>

int findindex(int frames[],int n,int page)
{
    for(int i=0;i<n;i++)
    {
        if(frames[i]==page)
        return i;
    }
    return -1;
}
void printframes(int frames[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(frames[i]==-1)
        printf(" -");
        else
        printf("%d",frames[i]);
    }
    printf("\n");
}