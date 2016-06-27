#include<iostream>
using namespace std;
class ret_mn
{
public:
    int low,high,sum;
};

ret_mn find_cross(int arr[],int low,int high,int mid)
{
    int ls=-1000,rs=-1000;
    int sum=0;
    int l,h;
    for(int i=mid;i>=low;i--)
    {
        sum=sum+arr[i];
        if(sum>ls)
        {
            ls=sum;
            l=i;
        }
    }
    for(int i=mid+1;i<=high;i++)
    {
        sum=sum+arr[i];
        if(sum>rs)
        {
            rs=sum;
            h=i;
        }
    }
    ret_mn uvc;
    uvc.low=l;
    uvc.high=h;
    uvc.sum=ls+rs;
    return uvc;

}

ret_mn find_max_sub(int arr[],int low,int high)
{
    ret_mn uvrt,uvl,uvr,uvc;
    if(high==low)
    {
        uvrt.low=low;
        uvrt.high=high;
        uvrt.sum=arr[low];
        return uvrt;
    }
    int mid=(high+low)/2;
    uvl=find_max_sub(arr,low,mid);
    uvr=find_max_sub(arr,mid+1,high);
    uvc=find_cross(arr,low,high,mid);
    if(uvl.sum>=uvr.sum && uvl.sum>=uvc.sum)
    {
        return uvl;
    }
    else if(uvr.sum>=uvl.sum && uvr.sum>=uvc.sum)
    {
        return uvr;
    }
    else
    {
        return uvc;
    }

}
int main()
{
int arr[10]={-1,-2,-5,-6,-8,9,5,3,12,2};
ret_mn uv;
uv=find_max_sub(arr,0,9);
cout<<"UV.SUM: "<<uv.sum<<endl<<"UV.LOW: "<<uv.low<<endl<<"UV.HIGH: "<<uv.high<<endl;
}
