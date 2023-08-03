#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("enter the number of requests\n");
    scanf("%d",&n);
    printf("enter the requests sequence\n");
    for(i=0;i<n;i++)
    scanf("%d",&RQ[i]);
    printf("enter initial head position\n");
    scanf("%d",&initial);
    printf("enter total disk size\n");
    scanf("%d",&size);
    printf("enter the head movement direction for high 1 and low 0\n");
    scanf("%d",&move);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }
        }
    }
    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
    if(move==1)
    {
        printf("sequence of request access:\n");
        for(i=index;i<n;i++)
        {
            printf("%d",RQ[i]);
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];

        }
        TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial=0;
        for(i=0;i<index;i++)
        {
            printf("%d",RQ[i]);
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
    }
    else{
        printf("sequence of request access:\n");
        for(i=index-1;i>=0;i--)
        {
            printf("%d",RQ[i]);
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial=size-1;
        for(i=n-1;i>=index;i--)
        {
            printf("%d",RQ[i]);
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
    }
    printf("\nTotal head movement is %d",TotalHeadMoment);
    return 0;
}
/* 
enter initial head position
50
enter total disk size
200
enter the head movement direction for high 1 and low 0
1
sequence of request access:
82140170190162443
Total head movement is 391[1] + Done  */