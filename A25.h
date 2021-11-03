#pragma once

#ifdef __cplusplus
extern "C" {
#endif // !__cplusplus


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define NAME_LENGTH_MAX 15
#define no_match 0
#define match 1
#define error -1
#define empty_element 2
#define success 1
#define add_to_end 2
#pragma warning(disable: 4996)

	typedef struct {                                           
		char firstname[NAME_LENGTH_MAX], name[NAME_LENGTH_MAX], fathername[NAME_LENGTH_MAX];
	} Fullname_t;

	typedef struct Node                                    
	{
		Fullname_t Fullname;
		struct Node* next;
	} node_t;

	node_t* get_a_new_name_to_end_link_list(node_t* head, node_t* get_new_name);

	int write_string_to_node_t(char* string, node_t* get_new_name);

	node_t* add_name_to_the_list(node_t* head, node_t* get_new_name);

	int delete_linked_list(node_t* head);

	node_t* compare_the_name (node_t* head, char* findLastname, char* findName, char* findMiddlename);

#ifdef __cplusplus
}
#endif 