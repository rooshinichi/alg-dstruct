#define _CRT_SECURE_NO_WARNINGS
#include"A25.h"
//----------------------------------------------//

void main() 
{
    char string[MAX_NAME_LENGHT]; // max lenght(firstname, name, fathername) < string
    node_t* zero = (node_t*)malloc(sizeof(node_t));
    if (!zero) 
    {
        perror("/nerror NO_001 ");
        exit(1);
    }
    zero->next = NULL;
    node_t* new_node;
    int key;
    FILE* input;
    if (NULL == (input = fopen("TEXT.txt", "rb")))
    {
        perror("/nerror NO_002 ");
    }else
    {
        key = fscanf(input, "%s", string);
        add_name_to_node1(zero, string);
        fscanf(input, "%s", string);
        add_name_to_node2(zero, string);
        fscanf(input, "%s", string);
        add_name_to_node3(zero, string);
        key = fscanf(input, "%s", string);
        while (key != EOF)
        {
            new_node = create_new_node_t();
            add_name_to_node1(new_node, string);
            fscanf(input, "%s", string);
            add_name_to_node2(new_node, string);
            fscanf(input, "%s", string);
            add_name_to_node3(new_node, string);
            zero = sort_node(zero, new_node);
            key = fscanf(input, "%s", string);
        }
        print_list(zero);
        compare_the_name(zero);
        delete_list(zero);
    }
    return;
}
