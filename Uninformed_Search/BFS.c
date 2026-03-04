#include <stdio.h>
#define MAX 5
int queue[MAX], front = 0, rear = 0;
int visited[MAX] = {0};

void BFS(int graph[MAX][MAX], int start)
{
    queue[rear++] = start;
    visited[start] = 1;
    while(front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);
        for(int i = 0; i < MAX; i++)
        {
            if(graph[node][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
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

    printf("BFS traversal: ");
    BFS(graph, 0);

    return 0;
}
