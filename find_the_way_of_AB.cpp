#include <bits/stdc++.h>
using namespace std;
char a[1001][1001];
vector<char> arr[1001];
bool vis[1001][1001];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j)
{
    if ((i < 0 || i >= n || j < 0 || j >= m) && a[i][j]!='.')
        return false;
    return true;
}
void dfs(int si, int sj)
{
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
    
    int ai,aj,bi,bj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            if (a[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
            arr[i].push_back(a[i][j]);
        }
    }

    memset(vis, false, sizeof(vis));
    dfs(ai, aj);

    if( vis[bi][bj] == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}