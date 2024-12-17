#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct GraphMatrix {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct GraphList {
    int vertices;
    struct Node* adjList[MAX_VERTICES];
};

struct Node {
    int vertex;
    struct Node* next;
};

void initGraphMatrix(struct GraphMatrix* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdgeMatrix(struct GraphMatrix* graph, int start, int end) {
    graph->adjMatrix[start][end] = 1;
    graph->adjMatrix[end][start] = 1;
}

void displayGraphMatrix(struct GraphMatrix* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void initGraphList(struct GraphList* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
}

void addEdgeList(struct GraphList* graph, int start, int end) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = end;
    newNode->next = graph->adjList[start];
    graph->adjList[start] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = start;
    newNode->next = graph->adjList[end];
    graph->adjList[end] = newNode;
}

void displayGraphList(struct GraphList* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFSMatrix(struct GraphMatrix* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSMatrix(graph, i, visited);
        }
    }
}

void BFSMatrix(struct GraphMatrix* graph, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void DFSList(struct GraphList* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    struct Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFSList(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

void BFSList(struct GraphList* graph, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = graph->adjList[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int choice, start, end;
    struct GraphMatrix graphMatrix;
    struct GraphList graphList;

    printf("Nhap so luong dinh cua do thi: ");
    int vertices;
    scanf("%d", &vertices);

    initGraphMatrix(&graphMatrix, vertices);
    initGraphList(&graphList, vertices);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Them canh vao do thi (Matrix)\n");
        printf("2. Them canh vao do thi (List)\n");
        printf("3. Duyet DFS (Matrix)\n");
        printf("4. Duyet BFS (Matrix)\n");
        printf("5. Duyet DFS (List)\n");
        printf("6. Duyet BFS (List)\n");
        printf("7. Hien thi do thi (Matrix)\n");
        printf("8. Hien thi do thi (List)\n");
        printf("9. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap dinh dau va dinh cuoi (Matrix): ");
                scanf("%d %d", &start, &end);
                addEdgeMatrix(&graphMatrix, start, end);
                break;
            case 2:
                printf("Nhap dinh dau va dinh cuoi (List): ");
                scanf("%d %d", &start, &end);
                addEdgeList(&graphList, start, end);
                break;
            case 3:
                printf("Duyet DFS (Matrix): ");
                int visitedMatrix[MAX_VERTICES] = {0};
                DFSMatrix(&graphMatrix, 0, visitedMatrix);
                printf("\n");
                break;
            case 4:
                printf("Duyet BFS (Matrix): ");
                BFSMatrix(&graphMatrix, 0);
                printf("\n");
                break;
            case 5:
                printf("Duyet DFS (List): ");
                int visitedList[MAX_VERTICES] = {0};
                DFSList(&graphList, 0, visitedList);
                printf("\n");
                break;
            case 6:
                printf("Duyet BFS (List): ");
                BFSList(&graphList, 0);
                printf("\n");
                break;
            case 7:
                printf("Hien thi do thi (Matrix):\n");
                displayGraphMatrix(&graphMatrix);
                break;
            case 8:
                printf("Hien thi do thi (List):\n");
                displayGraphList(&graphList);
                break;
            case 9:
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

