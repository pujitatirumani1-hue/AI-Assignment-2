#include <stdio.h>
#include <time.h>

#define MAX 100

typedef struct {
    int jug1;
    int jug2;
} State;

typedef struct {
    State s;
    int cost;
} Node;

// bfs queue
State queue[MAX];
int front = 0, rear = 0;

// dfs stack
State stack[MAX];
int top = -1;

// ucs list
Node ucs_list[MAX];
int ucs_size = 0;

int visited[5][5] = {0};

int goal(State s) {
    return (s.jug1 == 2 || s.jug2 == 2);
}


void BFS() {
    printf("\nBFS Solution:\n");

    State start = {0,0};
    queue[rear++] = start;
    visited[0][0] = 1;

    while(front < rear) {
        State curr = queue[front++];

        printf("(%d,%d)\n", curr.jug1, curr.jug2);

        if(goal(curr)) {
            printf("Goal reached!\n");
            return;
        }

        State next[6] = {
            {4, curr.jug2},
            {curr.jug1, 3},
            {0, curr.jug2},
            {curr.jug1, 0},
            {curr.jug1 - (3-curr.jug2 < curr.jug1 ? 3-curr.jug2 : curr.jug1),
             curr.jug2 + (3-curr.jug2 < curr.jug1 ? 3-curr.jug2 : curr.jug1)},
            {curr.jug1 + (4-curr.jug1 < curr.jug2 ? 4-curr.jug1 : curr.jug2),
             curr.jug2 - (4-curr.jug1 < curr.jug2 ? 4-curr.jug1 : curr.jug2)}
        };

        for(int i=0;i<6;i++){
            if(next[i].jug1>=0 && next[i].jug2>=0 &&
               next[i].jug1<=4 && next[i].jug2<=3 &&
               !visited[next[i].jug1][next[i].jug2]) {

                queue[rear++] = next[i];
                visited[next[i].jug1][next[i].jug2] = 1;
            }
        }
    }
}

/* ---------------- DFS ---------------- */

void DFS() {
    printf("\nDFS Solution:\n");

    State start = {0,0};
    stack[++top] = start;

    int visited_dfs[5][5] = {0};

    while(top >= 0) {
        State curr = stack[top--];

        if(visited_dfs[curr.jug1][curr.jug2])
            continue;

        visited_dfs[curr.jug1][curr.jug2] = 1;

        printf("(%d,%d)\n", curr.jug1, curr.jug2);

        if(goal(curr)) {
            printf("Goal reached!\n");
            return;
        }

        State next[6] = {
            {4, curr.jug2},
            {curr.jug1, 3},
            {0, curr.jug2},
            {curr.jug1, 0},
            {curr.jug1 - (3-curr.jug2 < curr.jug1 ? 3-curr.jug2 : curr.jug1),
             curr.jug2 + (3-curr.jug2 < curr.jug1 ? 3-curr.jug2 : curr.jug1)},
            {curr.jug1 + (4-curr.jug1 < curr.jug2 ? 4-curr.jug1 : curr.jug2),
             curr.jug2 - (4-curr.jug1 < curr.jug2 ? 4-curr.jug1 : curr.jug2)}
        };

        for(int i=0;i<6;i++){
            if(next[i].jug1>=0 && next[i].jug2>=0 &&
               next[i].jug1<=4 && next[i].jug2<=3 &&
               !visited_dfs[next[i].jug1][next[i].jug2]) {

                stack[++top] = next[i];
            }
        }
    }
}

/* ---------------- UCS ---------------- */

void UCS() {
    printf("\nUCS Solution:\n");
    int visited_ucs[5][5] = {0};
    State start = {0,0};
    ucs_list[ucs_size++] = (Node){start,0};
    while(ucs_size > 0) {
        int min_index = 0;
        for(int i=1;i<ucs_size;i++) {
            if(ucs_list[i].cost < ucs_list[min_index].cost)
                min_index = i;
        }
        Node currNode = ucs_list[min_index];
        State curr = currNode.s;
        ucs_list[min_index] = ucs_list[--ucs_size];
        if(visited_ucs[curr.jug1][curr.jug2])
            continue;
        visited_ucs[curr.jug1][curr.jug2] = 1;
        printf("(%d,%d)\n", curr.jug1, curr.jug2);
        if(goal(curr)) {
            printf("Goal reached!\n");
            return;
        }
        State next[6] = {
            {4, curr.jug2},
            {curr.jug1, 3},
            {0, curr.jug2},
            {curr.jug1, 0},
            {curr.jug1 - (3-curr.jug2 < curr.jug1 ? 3-curr.jug2 : curr.jug1),
             curr.jug2 + (3-curr.jug2 < curr.jug1 ? 3-curr.jug2 : curr.jug1)},
            {curr.jug1 + (4-curr.jug1 < curr.jug2 ? 4-curr.jug1 : curr.jug2),
             curr.jug2 - (4-curr.jug1 < curr.jug2 ? 4-curr.jug1 : curr.jug2)}
        };

        for(int i=0;i<6;i++){
            if(next[i].jug1>=0 && next[i].jug2>=0 &&
               next[i].jug1<=4 && next[i].jug2<=3 &&
               !visited_ucs[next[i].jug1][next[i].jug2]) {

                ucs_list[ucs_size++] = (Node){next[i], currNode.cost + 1};
            }
        }
    }
}

int main() {

    clock_t start, end;
    double cpu_time;

    start = clock();
    BFS();
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by BFS: %f seconds\n", cpu_time);

    start = clock();
    DFS();
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by DFS: %f seconds\n", cpu_time);

    start = clock();
    UCS();
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by UCS: %f seconds\n", cpu_time);

    return 0;
}
