#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <sstream>
#include <set>
#include <queue>
using namespace std;
int a, b, start;
int arr[1001][1001];
int visit[1001];
queue <int> q;
void bfs()
{
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        if (visit[s] == 1)continue;
        visit[s] = 1;
        cout << s << " ";
        for (int k = 1; k <= a; k++)
        {
            if (arr[s][k] == 1 || arr[k][s] == 1)
            {
                q.push(k);
            }
        }
    }
}
void init()
{
    for (int k = 1; k <= a; k++)
    {
        visit[k] = 0;
    }
}
void dfs(int s)
{
    cout << s << " ";
    visit[s] = 1;
    for (int k = 1; k <= a; k++)
    {
        if ((arr[s][k] == 1 || arr[k][s]) && visit[k] != 1)
        {
            dfs(k);
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> start; 
    for (int k = 0; k < b; k++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    dfs(start);
    init();
    cout << "\n";
    q.push(start);
    bfs();
}