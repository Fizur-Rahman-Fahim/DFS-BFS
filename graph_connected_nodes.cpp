#include<bits/stdc++.h>
using namespace std;
vector<int> arr[1005];

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
        vector<int> v;
        int a;
        cin>>a;
        for(int child : arr[a])
        {
            v.push_back(child);
        }
        if(v.empty())
        {
            cout<<-1<<endl;
            continue;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i:v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}