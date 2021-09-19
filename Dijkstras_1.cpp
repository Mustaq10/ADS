#include <iostream>
using namespace std;
#define infinity 999
void dij(int n, int v, int cost[10][10], int dist[])
{
    int u,count,flag[10];
    for (int i = 1; i <= n; i++)
        flag[i] = 0, dist[i] = cost[v][i];
    count = 2;
    while (count <= n)
    {
        int min = 999;
        for (int w = 1; w <= n; w++)
            if (dist[w] < min && !flag[w])
                min = dist[w], u = w;
        flag[u] = 1;
        count++;
        for (int w = 1; w <= n; w++)
            if ((dist[u] + cost[u][w] < dist[w]) && !flag[w])
                dist[w] = dist[u] + cost[u][w];
    }
}
int main()
{
    int n, v,cost[10][10], dist[10];
    cout <<"\n Enter the number of nodes:"<<endl;
    cin >> n;
    cout <<"\n Enter the cost matrix:"<<endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)  
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = infinity;
        }
    cout <<" Enter the source vertex:"<<endl;
    cin >> v;
    dij(n, v, cost, dist);
    cout <<"Shortest path:\n";
    for (i = 1; i <= n; i++)
        if (i != v)
            cout << " " << v << "=>" << i << " cost= " << dist[i] << endl;
    return 0;
}