#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

int D2[5][5]={{0,0,0,0,0},
	          {0,-1,-1,-1,0},
	          {0,0,0,0,0},
	          {0,-1,-1,-1,0},
	          {0,0,-1,0,0},
	          };

void display(int x,int y,int tx,int ty)
{
	system("clear");
    for(int i=0;i<5;i++)
     {
      for(int j=0;j<5;j++)
      {
        if(i==x && j==y)
        {
         cout<<'p';
        }
        else if(i==tx && j==ty)
        {
        cout<<'*';
        }
        else if(D2[i][j]!=-1)
        {
        cout<<"-";
        }
        else
        {
         cout<<"%";
        }
      }
     cout<<endl;
     }
   getchar();
}
int BFS(int tx,int ty)
{
	queue<pair<int,int> > q;
	q.push(make_pair(2,0));
	D2[2][0]=1;
	while(!q.empty())
	{
	 pair<int,int> p;
	 p=q.front();
	 q.pop();
	 int x=p.first,y=p.second;
      display(x,y,tx,ty);
      if(x==tx && y==ty)
      {
        return 1;
      }
      if(y+1<5 && D2[x][y+1]==0)
      { D2[x][y+1]=1;
        
        q.push(make_pair(x,y+1));
      }
      if(x+1<5 && D2[x+1][y]==0)
      {D2[x+1][y]=1;
       
       q.push(make_pair(x+1,y));
      }
      if(x-1>=0 && D2[x-1][y]==0)
      {D2[x-1][y]=1;
       
       q.push(make_pair(x-1,y));
      }
      if(y-1>=0 && D2[x][y-1]==0)
      {D2[x][y-1]=1;
       
       q.push(make_pair(x,y-1));
      }
	}
return 0;
}
int DFS(int tx,int ty)
{
	stack<pair<int,int> > s;
	s.push(make_pair(2,0));
	D2[2][0]=1;
    while(!s.empty())
    {
      pair<int,int> p;
      p=s.top();
      int c=0;
      int x=p.first,y=p.second;
      display(x,y,tx,ty);
      if(x==tx && y==ty)
      {
        return 1;
      }
      if(y+1<5 && D2[x][y+1]==0)
      { D2[x][y+1]=1;
        c++;
        s.push(make_pair(x,y+1));
      }
      if(x+1<5 && D2[x+1][y]==0)
      {D2[x+1][y]=1;
       c++;
       s.push(make_pair(x+1,y));
      }
      if(x-1>=0 && D2[x-1][y]==0)
      {D2[x-1][y]=1;
       c++;
       s.push(make_pair(x-1,y));
      }
      if(y-1>=0 && D2[x][y-1]==0)
      {D2[x][y-1]=1;
       c++;
       s.push(make_pair(x,y-1));
      }
      if(c==0)
       s.pop();
    }
return 0;
}
void reset()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(D2[i][j]==1)
				D2[i][j]=0;
		}
	}
}
int main()
{ int x=0,y=4;
	cout<<"enter the coordinates for food\n";
    cin>>x;
    cout<<"x taken\n";
    cin>>y;
    cout<<"y taken\n";
    cout<<"using BFS\n";
    int f1=BFS(x,y);
    reset();
    cout<<"using DFS\n";
    int f2=DFS(x,y);
    return 0;
}