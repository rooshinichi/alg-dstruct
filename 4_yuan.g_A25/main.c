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
        add_name_to_node(zero, string, "Fir");
        fscanf(input, "%s", string);
        add_name_to_node(zero, string, "N");
        fscanf(input, "%s", string);
        add_name_to_node(zero, string, "Fa");
        key = fscanf(input, "%s", string);
        while (key != EOF)
        {
            new_node = create_new_node_t();
            add_name_to_node(new_node, string, "Fir");
            fscanf(input, "%s", string);
            add_name_to_node(new_node, string, "N");
            fscanf(input, "%s", string);
            add_name_to_node(new_node, string, "Fa");
            zero = sortNode(zero, new_node);
            key = fscanf(input, "%s", string);
        }
        print_list(zero);
        compare_the_name(zero);
        delete_list(zero);
    }
    return;
}
