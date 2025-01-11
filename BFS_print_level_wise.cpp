/*
Question: 
You will be given an undirected graph which will be connected as input. 
Then you will be given a level L. 
You need to print the node values at level L in descending order. 
The source will be 0 always.
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> arr[50];

void
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
    int level;
    cin>>level;
    bfs(level);
    return 0;
}