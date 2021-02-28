#include<iostream>

using namespace std;

int main()
{
	string s;
	cin>>s;

	int len=s.size();
    int a[len],b[len];

    for(int i=0;i<len;i++)
    {
    	a[i]=int(s[i])-48;
    	b[i]=0;
     
    }

    int num1=0;
    
    for(int i=0;i<len;i++)
    {   int pos=a[i]-b[i];
    	if(pos<0)
    		pos=-pos;
    	num1+=(pos)*(len-i);
    	for(int j=i;j<len;j++)
    	{
            b[j]=a[i];
    	}
    }
  
   //int num=0;
   //for(int i=0;i<len;i++)
   //{
    // num+=(10-a[i])*(len-i);
     
   //}



   cout<<num1<<endl;

}