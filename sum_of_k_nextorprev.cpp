#include<iostream>


using namespace std;



int main()
{
	int n=5;
	int a[n];
	for(int i=0;i<n;i++)
	{
	a[i]=i;
	}
	int k;
	cin>>k;
	if(k>=0)
	{int slid=0;
    for(int i=1;i<=k;i++)
       {slid+=a[i%n];}
        cout<<slid<<" ";

    for(int i=1;i<n;i++)
    {
    	slid=slid-a[i];
        slid=slid+a[(i+k)%n];
        cout<<slid<<" ";
    }
    }
    else
    {  int nk=-k;
    	int slid=0;
    	for(int i=1;i<=nk;i++)
    	{
    		slid+=a[(n-(i%n))];
    	}
        cout<<slid<<" ";

        for(int i=1;i<n;i++)
        {
        	slid+=a[i-1];
        	slid-=a[(n+i-k%n)%n];
            cout<<slid<<" ";
        }

    }
}