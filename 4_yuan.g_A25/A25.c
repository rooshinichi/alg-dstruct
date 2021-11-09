//#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "A25.h"


node_t* get_a_new_name_to_end_link_list(node_t* head, node_t* get_new_name)      
{
	if (NULL == head)
	{
		node_t* temp_t = (node_t*)malloc(sizeof(node_t));
		if (NULL == temp_t)
		{
			perror("/nerror NO_005");
			return NULL;
		}
		temp_t->next = NULL;
		temp_t->Fullname = get_new_name->Fullname;
		head = temp_t;
		return head;
	}

	if (NULL == get_new_name)
		return NULL;

	node_t* temp = head;
	while (NULL != temp->next)
		temp = temp->next;

	node_t* temp_t = get_new_name;
	temp_t->Fullname = get_new_name->Fullname;
	temp->next = temp_t;
	temp_t->next = NULL;
	return head;
}

int write_string_to_node_t(char* string, node_t* get_new_name)          
{
	if (NULL == string)
	{
		perror("/nerror NO_007 ");
		return error;
	}
	if (NULL == get_new_name)
	{
		perror("/nerror NO_008 ");
		return error;
	}

	int i = 0, j = 0, k = 0;
	char firstname[NAME_LENGTH_MAX], name[NAME_LENGTH_MAX], fathername[NAME_LENGTH_MAX];
	char temp;

	while ((temp = string[i]) != ' ')                          
	{
		if (i > NAME_LENGTH_MAX)
		{
			perror("/nerror NO_009 ");
			return error;
		}
		firstname[i++] = temp;
	}
	firstname[i++] = '\0';
                                                   

	while ((temp = string[i]) != ' ')
	{
		if (k > NAME_LENGTH_MAX)
		{
			perror("/nerror NO_010 ");
			return error;
		}
		name[k++] = temp;
		i++;
	}
	name[k] = '\0';
	i++;

	while ((temp = string[i]) != '\n' && (temp = string[i]) != '\0')
	{
		if (j > NAME_LENGTH_MAX)
		{
			perror("/nerror NO_011 ");
			return error;
		}
		fathername[j++] = temp;
		i++;
	}
	if (j > 0 && fathername[j - 1] == '\n')
		fathername[j - 1] = '\0';
	else
		fathername[j] = '\0';

	strcpy(get_new_name->Fullname.firstname, firstname);            
	strcpy(get_new_name->Fullname.name, name);
	strcpy(get_new_name->Fullname.fathername, fathername);

	return success;
}

node_t* add_name_to_the_list(node_t* head, node_t* get_new_name)           
{
	if (NULL == get_new_name)
	{
		perror("/nerror NO_012 ");
		return NULL;
	}

	node_t* temp = head;
	if (NULL == temp)                                 
	{
		get_new_name->next = NULL;
		head = get_new_name;
		return head;
	}

	node_t* first = NULL;
	while (NULL != temp)
	{
		int firstname = strcmp(get_new_name->Fullname.firstname, temp->Fullname.firstname);
		int name = strcmp(get_new_name->Fullname.name, temp->Fullname.name);
		int fathername = strcmp(get_new_name->Fullname.fathername, temp->Fullname.fathername);

	if ((firstname < 0)|| (firstname == 0 && name < 0) || (firstname == 0 && name == 0 && fathername < 0))
		{
			if (NULL == first)                              
			{
				get_new_name->next = temp;
				head = get_new_name;
				return head;
			}
			first->next = get_new_name;
			get_new_name->next = temp;
			return head;
		}
		//else if (firstname == 0 && name < 0)
		//{
		//	if (NULL == first)                           
		//	{
		//		get_new_name->next = temp;
		//		head = get_new_name;
		//		return head;
		//	}
		//	first->next = get_new_name;
		//	get_new_name->next = temp;
		//	return head;
		//}
		//else if (firstname == 0 && name == 0 && fathername < 0)
		//{
		//	if (NULL == first)                                
		//	{
		//		get_new_name->next = temp;
		//		head = get_new_name;
		//		return head;
		//	}
		//	first->next = get_new_name;
		//	get_new_name->next = temp;
		//	return head;
		//}
		first = temp;                                         
		temp = temp->next;
	}
	first->next = get_new_name;                             
	get_new_name->next = NULL;
	return head;
}

int delete_linked_list(node_t* head)
{
	if (NULL != head)
	{
		while (NULL != head->next)
		{
			node_t* temp = head;
			head = head->next;
			free(temp);
		}
		return success;
	}
	else
	{
		return error;
	}
}


node_t* compare_the_name (node_t* head, char* find_fristname, char* find_name, char* find_fathername) 
{
	if (NULL == head)
	{
		perror("/nerror NO_013 ");
		return NULL;
	}
	
	node_t* temp = head;
	node_t* needed = NULL;

	char temp_one_1, temp_two_1, temp_three_1;
	
	if ((temp_one_1 = find_fristname[0]) == '\0' && (temp_two_1 = find_fristname[0]) == '\0' && (temp_three_1 = find_fristname[0]) == '\0')
	{
		return head;
	}
	while (0 != temp)
	{
		int match_fristname = 0;
		int i = 0;
		for (i, match_fristname; *(find_fristname + i) != '\0'; i++)
		{		if (find_fristname[i] == *(temp->Fullname.firstname + i))
			{
				match_fristname++;
			}
	    }

		if (match_fristname == i)
		{
			match_fristname = 1;
	    }
		else
		{
			match_fristname = 0;
	     }

		int match_name = 0;
		for (i = 0, match_name; *(find_name + i) != '\0'; i++)
		{
			if (find_name[i] == *(temp->Fullname.name + i))
			{
				match_name++;
			}
		}

		if (match_name == i)
		{
			match_name = 1;
		}
		else
		{
			match_name = 0;
		}
		int match_fathername = 0;
		for (i = 0, match_fathername; *(find_fathername + i) != '\0'; i++)
		{
			if (find_fathername[i] == *(temp->Fullname.fathername + i))
			{
					match_fathername++;
		    }
		}

		if (match_fathername == i)
		{
			match_fathername = 1;
		}  
		else
		{
			match_name = 0;
		}

		if (match_name * match_fristname * match_fathername)
		{
			needed = get_a_new_name_to_end_link_list(needed, temp);
		}

			temp = temp->next;
	}
	head = needed;
	return head;
}
