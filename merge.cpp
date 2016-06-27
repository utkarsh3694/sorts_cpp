#include<iostream>
#define SZ 10
using namespace std;

void mergee(int A[],int p,int q,int r)
{
    int k=0;
int L[10],R[10];
for(int i=p;i<=q;i++)
{
    L[k++]=A[i];

}
int l=0;
for(int i=q+1;i<=r;i++)
{
    R[l++]=A[i];
}
L[k]=1000;
R[l]=1000;
int t=0,n=p,lf=0,mi=0,ma=0,las=r-p+1;
int ll=0,rr=0;
while(t<las)
{
if(L[ll]==1000 || R[rr]==1000)
    {
    if(L[ll]==1000)
    {
        while(t<las)
        {
            A[n++]=R[rr++];
            t++;
        }
    }
    else if(R[rr]==1000)
    {
        while(t<las)
        {
            A[n++]=L[ll++];
            t++;
        }
    }
}
else
{
    if(L[t]<=R[t])
    {
        A[n++]=L[ll++];
        t++;
    }
    else if(L[t]>R[t])
    {
        A[n++]=R[rr++];
        t++;
    }

}

}

}

void merge_sort(int A[],int p,int r)
{   if(p<r)
    {
    int q=(p+r)/2;
    merge_sort(A,p,q);
    merge_sort(A,q+1,r);
    mergee(A,p,q,r);
    }
}


int main()
{
//cout<<"Enter ARRAY of integers..."<<endl;
int A[SZ]={74,62,56,41,33,27,14,13,12,1};
cout<<"BEFORE:"<<endl;
for(int i=0;i<SZ;i++)
{
    cout<<A[i]<<" ";
}

merge_sort(A,0,SZ-1);

cout<<"\nAFTER:"<<endl;
for(int i=0;i<SZ;i++)
{
    cout<<A[i]<<" ";
}

}
