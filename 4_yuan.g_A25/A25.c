#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"A25.h"
node_t* create_new_node_t() //创造一个新链表
{  
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    if (!temp) 
    {
        perror("/nerror NO_003 ");
        exit(1);
    }
    temp->next = NULL;
    return temp;
}
void print_node(node_t* node) //打印链表的一节
{  
    if (node != NULL) 
    {
        printf("%s ", node->name);
        printf("%s ", node->firstname);
        printf("%s\n", node->fathername);
    }
}
void print_list(node_t* zero)  //打印整个链表
{ 
    while (zero != NULL) 
    {
        print_node(zero);
        zero = zero->next;
    }
}
void add_name_to_node1(node_t* node, char* name_part)  // Fir--firstname, N--name, Fa--farhername  往链表一节里面放入名字
{
    if (node == NULL)
    {
        perror("/nerror NO_004 ");
        exit(1);
    }
    node->firstname = (char*)malloc(strlen(name_part) + 1);
    strcpy(node->firstname , name_part);
}
void add_name_to_node2(node_t* node, char* name_part)
{
    if (node == NULL)
    {
        perror("/nerror NO_004 ");
        exit(1);
    }
    node->name = (char*)malloc(strlen(name_part) + 1);
    strcpy(node->name, name_part);
}
void add_name_to_node3(node_t* node, char* name_part)
{
    if (node == NULL)
    {
        perror("/nerror NO_004 ");
        exit(1);
    }
    node->fathername = (char*)malloc(strlen(name_part) + 1);
    strcpy(node->fathername, name_part);
}
node_t* insert_front_of_the_node(node_t** node, node_t** node_in_list, node_t* head)   //
{ 
    if (!node || !node_in_list || !head) 
    {
        perror("/nerror NO_009 ");
        exit(1);
    }
    node_t* temp;
    temp = head;
    if (*node_in_list == head) 
    {
        (*node)->next = head;
        head = *(node);
        return head;
    }
    else 
    {
        while (temp->next != *(node_in_list)) 
        {
            temp = temp->next;
        }
        (*node)->next = temp->next;
        temp->next = *node;
    }
    return head;
}
int insert_the_position(char* node_name, char* nodeInListName, node_t** node, node_t** node_in_list, node_t** head) {
    if (!node || !node_in_list || !head) 
    {
        perror("/nerror NO_010 ");
        exit(1);
    }
    if (strcmp(node_name, nodeInListName) < 0) 
    {
        *head = insert_front_of_the_node(node, node_in_list, *head);
        return SUCCESS;//position was found
    }
    else 
    {
        if ((*node_in_list)->next == NULL)
        {
            (*node_in_list)->next = (*node);
            return SUCCESS_2;//position was found
        }else 
        {
            (*node_in_list) = (*node_in_list)->next;
            return ERROR;//position was not found
        }
    }
}
node_t* sort_node(node_t* zero, node_t* node) 
{
    if (!zero || !node) 
    {
        perror("/nerror NO_011 ");
        exit(1);
    }
    int temp1,temp2,temp3,key;  //temp1--firstname  //temp2--name  //temp3--fathername 
    node_t* head;
    head = zero;
    while (1) {
        temp1 = strcmp(node->firstname, zero->firstname);
        temp2 = strcmp(node->name, zero->name);
        temp3 = strcmp(node->fathername, zero->fathername);
        if ((temp1 == 0) && (temp2 == 0) && (temp3 == 0)) 
        {
            node->next = zero->next;
            zero->next = node;
            break;
        }

        if ((temp1 == 0) && (temp2 == 0)) 
        {
            key = insert_the_position(node->fathername, zero->fathername, &node, &zero, &head);
            if (key == SUCCESS || key == SUCCESS_2) 
            {
                break;
            }
            else 
            {
                continue;
            }
        }
        if (temp2 == 0) 
        {
            key = insert_the_position(node->firstname, zero->firstname, &node, &zero, &head);
            if (key == SUCCESS || key == SUCCESS_2) 
            {
                break;
            }
            else 
            {
                continue;
            }
        }
        key = insert_the_position(node->name, zero->name, &node, &zero, &head);
        if (key == SUCCESS || key == SUCCESS_2) 
        {
            break;
        }
        else 
        {
            continue;
        }
    }
    return head;
}




void compare_the_name(node_t* zero) {
    if (!zero) {
        perror("/nerror NO_012 ");
        exit(1);
    }
    char name[MAX_NAME_LENGHT],firstname[MAX_NAME_LENGHT],fathername[MAX_NAME_LENGHT];
    gets_s(name, MAX_NAME_LENGHT);
    gets_s(firstname, MAX_NAME_LENGHT);
    gets_s(fathername, MAX_NAME_LENGHT);
    int temp1, temp2, temp3;  //temp1--firstname  //temp2--name  //temp3--fathername 
    while (zero != NULL) {
        temp1 = strncmp(firstname, zero->firstname, strlen(firstname));
        temp2 = strncmp(name, zero->name, strlen(name));
        temp3 = strncmp(fathername, zero->fathername, strlen(fathername));
        if ((temp2 == 0) && (temp1 == 0) && (temp3 == 0)) {
            print_node(zero);
        }
        zero = zero->next;
    }

}


void delete_list(node_t* head) {
    while (head != NULL) {
        free(head->firstname);
        free(head->name);
        free(head->fathername);
        node_t* p;
        p = head;
        head = head->next;
        free(p);
    }
}

