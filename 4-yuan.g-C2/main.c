#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "labC2.h"




int num_edges = 0;
int num_vertex = 0;
vertex* vertices;

edge_t* create_edge(int start_edge, int end_edge) {
    edge_t* temp = (edge_t*)malloc(sizeof(edge_t));
    if (!temp)
    {
        perror("No_001 \n");
        exit(1);
    }

    temp->next = NULL;
    temp->start_edge = start_edge;
    temp->end_edge = end_edge;
    return temp;
}

edge_t* add_edge(edge_t* head, int start_edge, int end_edge) {
    if (!head) {
        perror("No_002 \n");
        exit(1);
    }
    edge_t* cur_node = head;
    edge_t* temp = (edge_t*)malloc(sizeof(edge_t));
    if (!temp) {
        perror("No_003 \n");
        exit(1);
    }
    temp->next = NULL;
    temp->start_edge = start_edge;
    temp->end_edge = end_edge;
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
    }
    cur_node->next = temp;
    return head;
}

void delete_list(edge_t* head) {
    while (head != NULL) {
        edge_t* p;
        p = head;
        head = head->next;
        free(p);
    }
}

void func(edge_t* head, int weight) {
    edge_t* cur_edge = head;
    fprintf(stdout, "%d ", weight);
    int min_vert_weight = num_vertex;
    vertices[weight].visited = SUCCESS;
    int j = 0;
    while (1) {
        if (j == 1) {
            break;
        }
        cur_edge = head;
        min_vert_weight = num_vertex;
        for (int i = 0; i < num_edges; i++) {
            if (cur_edge->start_edge == weight) {
                if (vertices[cur_edge->end_edge].visited == ERROR) {
                    if (min_vert_weight > cur_edge->end_edge) {
                        min_vert_weight = cur_edge->end_edge;
                    }
                }
            }
            if (cur_edge->end_edge == weight) {
                if (vertices[cur_edge->start_edge].visited == ERROR) {
                    if (min_vert_weight > cur_edge->start_edge) {
                        min_vert_weight = cur_edge->start_edge;
                    }
                }
            }
            cur_edge = cur_edge->next;
        }
        j++;
        if (min_vert_weight != num_vertex) {
            func(head, min_vert_weight);
            j = 0;
        }
    }
}

int main(void) {
    edge_t* head = NULL;
    int start_edge;
    int end_edge;
    scanf("%d", &num_vertex);
    vertices = (vertex*)malloc(num_vertex * sizeof(vertex));

    if (!vertices) {
        perror("No_005 \n");
        exit(1);
    }

    for (int i = 0; i < num_vertex; i++) {
        vertices[i].weight = i;
        vertices[i].visited = ERROR;
    }

    if (fscanf(stdin, "%d %d", &start_edge, &end_edge) != EOF) {
        head = create_edge(start_edge, end_edge);
        num_edges++;
    }

    while (fscanf(stdin, "%d %d", &start_edge, &end_edge) != EOF) {
        head = add_edge(head, start_edge, end_edge);
        num_edges++;
    }

    func(head, 0);
    delete_list(head);
    free(vertices);

    return 0;
}
