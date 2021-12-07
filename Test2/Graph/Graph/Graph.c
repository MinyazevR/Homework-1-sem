#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../List/List/List.h"

typedef struct Node
{
    int index;
    int lenght;
} Node;

typedef struct Graph
{
    Node** nodes;
    int nodesCount;
    int** matrix;
} Graph;

Graph* createGraph(int numberOfNode)
{
    Graph* newGraph = calloc(1, sizeof(Graph));
    newGraph->nodes = calloc(numberOfNode, sizeof(Node*));
    for (int i = 0; i < numberOfNode; i++)
    {
        newGraph->nodes[i] = calloc(1, sizeof(int*));
        newGraph->nodes[i]->index = i;
        newGraph->nodes[i]->lenght = 0;
    }
    newGraph->matrix = calloc(numberOfNode, sizeof(int*));
    for (int i = 0; i < numberOfNode; i++)
    {
        newGraph->matrix[i] = calloc(numberOfNode, sizeof(int));
    }
    return newGraph;
}

void edgeLength(Graph* graph, int firstVertex, int secondVertex, int lenght)
{
    graph->matrix[firstVertex][secondVertex] = lenght;
    graph->matrix[secondVertex][firstVertex] = lenght;
}

void printMatrix(Graph* graph)
{
    for (int i = 0; i < 6; i++)
    {
        printf("\n ");
        for (int j = 0; j < 6; j++)
        {
            printf("%d ", graph->matrix[i][j]);
        }
    }
}

int getLength(Graph* graph, int firstVertex, int secondVertex)
{
    return graph->matrix[firstVertex][secondVertex];
}


typedef struct Table
{
    int numberOfSegments;
    struct List** array;
} Table;

Table* lenght(List* list, Error* error, Graph* graph)
{
    while (!isEmpty(list))
    {
         Position* position = first(list, error);
         while (position != NULL)
         {
             for (int i = 0; i < returnSize(list); i++)
             {
                 int l = get(list, position, error);
                 int a = getLength(graph, i, l);
                 add(list, value, error);
                 if (a != 0)
                 {
                     add(newList, i ,error);
                     removeElement(list);
                 }  
                 if (a == 0)
                 {
                     return;
                 }
                 lenght(list, error, graph);
                 next(position);
             }
         }
    }
}

void printTable(Table* table)
{
    for (int i = 0; i < table->numberOfSegments; i++)
    {
        printf("\n");
        print(table->array[i]);
    }
}


int main(void)
{
    Graph* graph = NULL;
    Error error = NOT_ERROR;
    edgeLength(graph, 0, 1, 2);
    edgeLength(graph, 0, 1, 2);
    edgeLength(graph, 0, 1, 2);
    edgeLength(graph, 0, 1, 2);
    edgeLength(graph, 0, 1, 2);
    edgeLength(graph, 0, 1, 2);
    edgeLength(graph, 0, 1, 2);
    edgeLength(graph, 0, 1, 2);
    List* list = createList();
    for (int i = 0; i < 6; i++)
    {
        add(list, i , &error);
    }

}