#include "A25.h"

//-----------------------------------------------------------------------------//

int main()
{
	FILE* input = fopen("TEXT.txt", "r");   //读取文件，返回文件的指针
	if (NULL == input)
	{
		perror("/nerror NO_001 ");
		return error;
	}

	char* string = malloc(sizeof(char) * 3 * NAME_LENGTH_MAX); //创建指针来存放从文件里读取的数据
	if (NULL == string)
	{
		perror("/nerror NO_002 ");
		return error;
	}

	node_t* head = NULL;   //创建空链表预备存储名字数据
	while (!feof(input))   //读取文件是否到结尾
	{
		fgets(string, 3 * NAME_LENGTH_MAX, input);   //把数据先放到指针里

		node_t* get_new_name = (node_t*)malloc(sizeof(node_t));  //存储一个名字然后再连接到链表上

		if (NULL == get_new_name)
		{
			perror("/nerror NO_003 ");
			return error;
		}

		int key = write_string_to_node_t(string, get_new_name);

		if (!key)
		{
			perror("/nerror NO_004 ");
			return error;
		}  //把名字从string读取一个名字到预备链表上

		head = add_name_to_the_list(head, get_new_name);  //把读取的那一个名字放到链表里
	}

	node_t* temp = head;

	while (NULL != temp)  //打印出来所有的名字
	{
		printf("%s    %s    %s\n---------------------------\n", &(temp->Fullname.firstname), temp->Fullname.name, temp->Fullname.fathername);
		temp = temp->next;
	}

	printf("Put here your FIO in form: \"firstname name fathername\" \n---------------------------\n(if you want miss some name, you can just push void space)\n");
	fgets(string, 3 * NAME_LENGTH_MAX, stdin);  //获得搜索关键词

	node_t* zero = (node_t*)malloc(sizeof(node_t));     

	if (NULL == zero)
	{
		perror("/nerror NO_006 ");
		return -1;
	}

	write_string_to_node_t(string, zero);

	head = compare_the_name (head, zero->Fullname.firstname, zero->Fullname.name, zero->Fullname.fathername);

	while (NULL != head)
	{
		printf("%s    %s    %s\n---------------------------\n", &(head->Fullname.firstname), head->Fullname.name, head->Fullname.fathername);
		head = head->next;
	}

	delete_linked_list(head);
	free(zero);
	free(string);
	fclose(input);

	return 0;

}
