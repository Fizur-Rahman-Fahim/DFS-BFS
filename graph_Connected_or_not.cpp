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
    }
    int Q;
    cin>>Q;
    while(Q--)
    {
        int a,b;
        cin>>a>>b;
        bool found = false;
        if(a==b)
        {
            cout<<"YES"<<endl;
            continue;
        }
        for(int child : arr[a])
        {
            if(child==b)
            {
                cout<<"YES"<<endl;
                found = true;
            }
        }
        if(!found)
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}