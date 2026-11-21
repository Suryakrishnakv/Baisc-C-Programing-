#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 4 
#define MAX_STATES 1000000 
int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int goal[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };
typedef struct 
{
    int state[16];        
    int g;                
    int h;                
    int f;                
    int zero_pos;         
    struct Node *parent;  
} 
Node;
typedef struct 
{
    Node *nodes[MAX_STATES];
    int size;
} MinHeap;
void initMinHeap(MinHeap *heap) 
{
    heap->size = 0;
}
void swap(Node **a, Node **b) 
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(MinHeap *heap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->nodes[left]->f < heap->nodes[smallest]->f)
        smallest = left;
    if (right < heap->size && heap->nodes[right]->f < heap->nodes[smallest]->f)
        smallest = right;
    if (smallest != idx) 
	{
        swap(&heap->nodes[smallest], &heap->nodes[idx]);
        heapify(heap, smallest);
    }
}
void insertMinHeap(MinHeap *heap, Node *node)
{
    if (heap->size < MAX_STATES) 
	{
        heap->nodes[heap->size] = node;
        int idx = heap->size++;
        while (idx > 0 && heap->nodes[(idx - 1) / 2]->f > heap->nodes[idx]->f) 
		{
            swap(&heap->nodes[(idx - 1) / 2], &heap->nodes[idx]);
            idx = (idx - 1) / 2;
        }
    }
}
Node* extractMin(MinHeap *heap) 
{
    if (heap->size == 0)
        return NULL;
    Node *minNode = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];
    heapify(heap, 0);
    return minNode;
}
int isEqual(int *state1, int *state2) 
{
    for(int i = 0; i < 16; i++) 
	{
        if (state1[i] != state2[i]) 
		{
            return 0;
        }
    }
    return 1;
}
int manhattanDistance(int *state) 
{
    int distance = 0;
    for (int i = 0; i < 16; i++) 
	{
        if (state[i] != 0) 
		{
            int goalPos = state[i] - 1;
            distance += abs(i / N - goalPos / N) + abs(i % N - goalPos % N);
        }
    }
    return distance;
}
void printPuzzle(int *state) 
{
    for (int i = 0; i < N; i++)
	{
        for (int j = 0; j < N; j++) 
		{
            printf("%2d ", state[i * N + j]);
        }
        printf("\n");
    }
    printf("\n");
}
int* performMove(int *state, int zero_pos, int move) 
{
    int *newState = (int*)malloc(16 * sizeof(int));
    memcpy(newState, state, 16 * sizeof(int));
    int newPos = zero_pos + directions[move][0] * N + directions[move][1];
    newState[zero_pos] = newState[newPos];
    newState[newPos] = 0;
    return newState;
}
void aStarSearch(int *start) 
{
    MinHeap openList;
    initMinHeap(&openList);
    Node *startNode = (Node*)malloc(sizeof(Node));
    memcpy(startNode->state, start, 16 * sizeof(int));
    startNode->g = 0;
    startNode->h = manhattanDistance(start);
    startNode->f = startNode->g + startNode->h;
    startNode->zero_pos = 0;
    startNode->parent = NULL;
    insertMinHeap(&openList, startNode);
    int visited[MAX_STATES] = { 0 };
    visited[0] = 1;
    while (openList.size > 0) 
	{
        Node *currentNode = extractMin(&openList);
        
        if (isEqual(currentNode->state, goal)) 
		{
            printf("Solution found!\n");
            Node *temp = currentNode;
            while (temp != NULL) 
			{
                printPuzzle(temp->state);
                temp = temp->parent;
            }
            return;
        }
        int zero_pos = currentNode->zero_pos;
        for (int move = 0; move < 4; move++) 
		{
            int newZeroPos = zero_pos + directions[move][0] * N + directions[move][1];
            if (newZeroPos >= 0 && newZeroPos < 16) 
			{
                int *newState = performMove(currentNode->state, zero_pos, move);
                Node *newNode = (Node*)malloc(sizeof(Node));
                memcpy(newNode->state, newState, 16 * sizeof(int));
                newNode->g = currentNode->g + 1;
                newNode->h = manhattanDistance(newState);
                newNode->f = newNode->g + newNode->h;
                newNode->zero_pos = newZeroPos;
                newNode->parent = currentNode;
                if (!visited[newZeroPos]) 
				{
                    insertMinHeap(&openList, newNode);
                    visited[newZeroPos] = 1;
                }
                free(newState);
            }
        }
        free(currentNode);
    }
    printf("No solution found.\n");
}
int main() 
{
    int start[16] = { 5, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };
    printf("Initial state:\n");
    printPuzzle(start);
    aStarSearch(start);
    return 0;
}
