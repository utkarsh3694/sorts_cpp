#include<iostream>
#include<math.h>
using namespace std;
#define SZ 10
class heap
{
public:
int ah[11];
int hsize;
void print()
{
    cout<<endl;
    for(int i=1;i<=this->hsize;i++)
    {
        cout<<" "<<ah[i];
    }
}
};


int LEFT(int n)
{
    return(2*n);
}
int RIGHT(int n)
{
    return(2*n+1);
}
int PARENT(int n)
{
    return(n/2);
}

heap ret(heap h)
{
    h.print();
    h.ah[0]=10;
    return h;
}

heap max_heapify(heap h, int n)
{
    int larg=0;
    int left=LEFT(n);
    int right=RIGHT(n);
    int pt=PARENT(n);

    if(left<=h.hsize && h.ah[left]>h.ah[n])
    {
        larg=left;
    }
    else
    {
        larg=n;
    }
    if(right<=h.hsize && h.ah[right]>h.ah[larg])
    {
        larg=right;
    }
    if(larg==left || larg==right)
    {
    int temp=h.ah[n];
    h.ah[n]=h.ah[larg];
    h.ah[larg]=temp;
    h=max_heapify(h,larg);
    }

    return h;
}

int main()
{
heap hp1;

int A[SZ]={1,2,3,4,5,6,7,8,9,10};
hp1.hsize=SZ;
for(int i=6;i<=10;i++)
{
    hp1.ah[i]=A[i-1];


}
for(int i=5;i>0;i--)
{
    hp1.ah[i]=A[i-1];

    hp1=max_heapify(hp1,i);

}
/*
cout<<"BEFORE: ";
hp1.print();
heap hm;
//hm=ret(hp1);
hm=max_heapify(hp1,3);
cout<<"\nAFTER: ";
*/
cout<<"HEAP: "<<endl;
hp1.print();
while(hp1.hsize!=1)
{
    swap(hp1.ah[1],hp1.ah[hp1.hsize]);
    hp1.hsize--;
    hp1=max_heapify(hp1,1);
}
cout<<endl<<"AFTER HEAPSORT: "<<endl;
for(int i=1;i<=10;i++)
    {
        cout<<" "<<hp1.ah[i];
    }

}
