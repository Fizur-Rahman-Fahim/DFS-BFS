/*
Question: You will be given an undirected graph as input.
Then you will be given a query Q.
For each query, you will be given source S and destination D.
You need to print the shortest distance between S and D. 
If there is no path from S to D, print -1.
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> arr[1001];
bool vis[1001];
int level[1001];

void bfs(int src,int destination)
{
    queue<int> q;
    q.push(src);
    vis[src]=true;
    bool found = false;
    level[src]=0;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        
        if(par == destination)
        {
            cout << level[par] <<endl;
            found = true;
            return;
        }

        for(int child :arr[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]= true;
                level[child]=level[par]+1;
                if(child == destination)
                {
                    cout<<level[child]<<endl;
                    return;
                }
            }
        }
    }
    if(!found)
    {
        cout << -1 <<endl;
        return;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int Q;
    cin>>Q;
    while(Q--)
    {
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));
        int s1,s2;
        cin>>s1>>s2;
        bfs(s1,s2);
    }
    return 0;
}