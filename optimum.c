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
void optimal(int pages[],int n,int capacity)
{
    int frames[capacity];
    int pagefaults=0;
    int index,farthest,futureindex;
    for(int i=0;i<capacity;i++)
    frames[i]=-1;
    for(int i=0;i<n;i++)
    {
        int page=pages[i];
        index=findindex(frames,capacity,page);
        if(index==-1)
        {
            int emptyindex=findindex(frames,capacity,-1);
            if(emptyindex!=-1)
            {
                frames[emptyindex]=page;

            }
            else
            {
                farthest=i+1;
                futureindex=-1;
                for(int j=0;j<capacity;j++)
                {
                    int currentpage=frames[j];
                    int k;
                    for(k=i+1;k<n;k++)
                    {
                        if(currentpage==pages[k])
                        {
                            if(k>farthest)
                            {
                                farthest=k;
                                futureindex=j;
                            }
                            break;
                        }
                    }
                    if(k==n)
                    {
                        futureindex=j;
                        break;
                    }
                }
                frames[futureindex]=page;
            }
            pagefaults++;
        }
        printframes(frames,capacity);
    }
    printf("optimal page faults: %d\n",pagefaults);

}
int main()
{
    int pages[]={1,2,3,4,1,5,6,7,8,7,8,9,7,8,9,5,4,5,4,2};
    int capacity=3;
    int n=sizeof(pages)/sizeof(pages[0]);
    printf("page reference sequence:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",pages[i]);

    }
    printf("\n\n");
    printf("\n");
    printf("optimal algorithm:\n");
    optimal(pages,n,capacity);
    printf("\n");
    return 0;
}
/*
1 - -
12 -
123
124
124
524
564
574
578
578
578
978
978
978
978
578
548
548
548
248
optimal page faults: 12*/
