#include <stdio.h>
#define MAX 5
#define INF 9999
int minDistance(int dist[], int visited[])
{
    int min = INF, index = -1;
    for(int i = 0; i < MAX; i++)
    {
        if(!visited[i] && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void UCS(int graph[MAX][MAX], int start)
{
    int dist[MAX];
    int visited[MAX] = {0};
  
    for(int i = 0; i < MAX; i++)
        dist[i] = INF;
    dist[start] = 0;
  
    for(int i = 0; i < MAX-1; i++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for(int v = 0; v < MAX; v++)
        {
            if(graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Minimum cost from node %d:\n", start);
    for(int i = 0; i < MAX; i++)
        printf("to %d = %d\n", i, dist[i]);
}

int main()
{
    int graph[MAX][MAX] = {
        {0,2,4,0,0},
        {2,0,1,7,0},
        {4,1,0,3,5},
        {0,7,3,0,2},
        {0,0,5,2,0}
    };
    UCS(graph, 0);
    return 0;
}
