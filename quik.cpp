#include<iostream>
using namespace std;
int qsort(int arr[],int a, int b);
void quik(int arr[],int low,int high)
{
    if(high>low)
    {


    int p;
    p=qsort(arr,low,high);
    quik(arr,low,p-1);
    quik(arr,p+1,high);
    }
}


int qsort(int arr[],int a, int b)
{
    cout<<"IN QS: ";
int pivot=b;
int l=a;
int r=b;
if(b!=a)
{

while(l<r)
{

while(arr[l]<=arr[pivot])
{
    l++;
}
while(arr[r]>arr[pivot])
{
    r--;
}
if(r>l)
{
    swap(arr[l],arr[r]);
}

}


}
return(r);
}

int main()
{
int arr[10];
cout<<"Input 10 array elements:"<<endl;
for(int i=0;i<10;i++)
{
cin>>arr[i];
}
cout<<"INITIAL: "<<endl;
for(int i=0;i<10;i++)
{
cout<<arr[i]<<endl;
}
quik(arr,0,9);
cout<<"FINAL: "<<endl;
for(int i=0;i<10;i++)
{
cout<<arr[i]<<endl;
}


}
