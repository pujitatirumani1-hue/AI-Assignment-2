#include <stdio.h>
#define MAX 5
int visited[MAX] = {0};

void DFS(int graph[MAX][MAX], int node)
{
    visited[node] = 1;
    printf("%d ", node);
    for(int i = 0; i < MAX; i++)
    {
        if(graph[node][i] == 1 && !visited[i])
        {
            DFS(graph, i);
        }
    }
}

int main()
{
    int graph[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };
    printf("DFS traversal: ");
    DFS(graph, 0);

    return 0;
}
