#include <bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool vis[1001][1001];
vector<int> arr;
vector<pair<int, int>> v;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m ;
bool valid(int i, int j)
{
    if ((i < 0 || i >= n || j < 0 || j >= m) || a[i][j] == '#')
        return false;
    return true;
}
void dfs(int si, int sj)
{
    v.push_back({si, sj});
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false)
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int ai= i;
            int aj= j;
            if(a[i][j] == '.' && vis[i][j] == false)
            {
                dfs(ai, aj);
                arr.push_back(v.size());
                v.clear();
            }
        }
    }
    sort(arr.begin(), arr.end());
    for(int i: arr)
    {
        cout << i << " ";
    }
    return 0;
}