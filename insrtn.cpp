#include<iostream>
#define SZ 10
using namespace std;
int main()
{
//cout<<"Enter ARRAY of integers..."<<endl;
int A[SZ]={74,62,56,41,33,27,14,13,12,1};
cout<<"BEFORE:"<<endl;
for(int i=0;i<SZ;i++)
{
    cout<<A[i]<<" ";
}

for(int j=1;j<SZ;j++)
{
    int key=A[j];
    int i=j-1;
    while(i>-1 && A[i]>key)
    {
        A[i+1]=A[i];
        i=i-1;
    }
    A[i+1]=key;
}
cout<<"\nAFTER:"<<endl;
for(int i=0;i<SZ;i++)
{
    cout<<A[i]<<" ";
}

}
