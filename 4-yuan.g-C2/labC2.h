#pragma once
#define SUCCESS 1
#define ERROR 0

typedef struct edge {
    int start_edge;
    int end_edge;
    struct edge* next;
}edge_t;

typedef struct {
    int weight;
    int visited;
}vertex;

edge_t* create_edge(int start_edge, int end_edge);
edge_t* add_edge(edge_t* head, int start_edge, int end_edge);
void delete_list(edge_t* head);
void func(edge_t* head, int num);
