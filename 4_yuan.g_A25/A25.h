#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME_LENGHT 50
#define SUCCESS 1 
#define SUCCESS_2 2
#define ERROR 0

typedef struct node 
{
    char* firstname;
    char* name;
    char* fathername;
    struct node* next;
}node_t;

node_t* create_new_node_t();
void print_node(node_t* node);
void print_list(node_t* zero);
void add_name_to_node(node_t* node, char* name_part, const char* key_word);
int insert_the_position(char* node_name, char* nodeInListName, node_t** node, node_t** node_in_list, node_t** head);
node_t* insert_front_of_the_node(node_t** node, node_t** node_in_list, node_t* head);
node_t* sortNode(node_t* zero, node_t* node);
void compare_the_name(node_t* zero);
