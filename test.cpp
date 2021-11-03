#include "pch.h"
#include "../pragma002/A25.h"
#include "../pragma002/A25.c"

TEST(add_name_to_the_list, test1)
{
	node_t* head = nullptr;
	node_t* key = nullptr;
	node_t* key_NULL = nullptr;
	node_t* get_new_name = (node_t*)malloc(sizeof(node_t));
	key = add_name_to_the_list(head, get_new_name);
	ASSERT_TRUE(key != key_NULL);               
	free(get_new_name);
}

TEST(add_name_to_the_list, test2)
{
	node_t* head = (node_t*)malloc(sizeof(node_t));
	if (head != NULL)
	{
		node_t* key = nullptr;
		node_t* key_NULL = nullptr;
		node_t* get_new_name = nullptr;
		key = add_name_to_the_list(head, get_new_name);
		ASSERT_TRUE(key == key_NULL);
		free(head);       
	}
}

TEST(add_name_to_the_list, test3)
{
	node_t* head = (node_t*)malloc(sizeof(node_t));
	node_t* head2 = (node_t*)malloc(sizeof(node_t));
	node_t* head3 = (node_t*)malloc(sizeof(node_t));


	// we get that head3->head2->NULL and head is separately
	if (head != NULL && head2 != NULL && head3 != NULL)
	{
		char temp_one_1[NAME_LENGTH_MAX] = "Navetkina", temp_two_1[NAME_LENGTH_MAX] = "Irina", temp_three_1[NAME_LENGTH_MAX] = "Sergeevna";
		strcpy(head->Fullname.firstname, temp_one_1);
		strcpy(head->Fullname.name, temp_two_1);
		strcpy(head->Fullname.fathername, temp_three_1);
		head->next = NULL;

		char temp_one_2[NAME_LENGTH_MAX] = "Ivanov", temp_two_2[NAME_LENGTH_MAX] = "Nikolay", temp_three_2[NAME_LENGTH_MAX] = "Petrovich";
		strcpy(head2->Fullname.firstname, temp_one_2);
		strcpy(head2->Fullname.name, temp_two_2);
		strcpy(head2->Fullname.fathername, temp_three_2);
		head2->next = NULL;

		char temp_one_3[NAME_LENGTH_MAX] = "Ivanov", temp_two_3[NAME_LENGTH_MAX] = "Boris", temp_three_3[NAME_LENGTH_MAX] = "Crecovich";
		strcpy(head3->Fullname.firstname, temp_one_3);
		strcpy(head3->Fullname.name, temp_two_3);
		strcpy(head3->Fullname.fathername, temp_three_3);
		head3->next = head2;

		head3 = add_name_to_the_list(head3, head);
		ASSERT_TRUE(head3->next->next == head);
		free(head);
		free(head2);
		free(head3);
	}
}



TEST(write_string_to_node_t, test4)
{
	char* string = nullptr;
	Fullname_t get_new_name = { "firstname", "name", "fathername" };
	node_t* head = (node_t*)malloc(sizeof(node_t));
	if (head != nullptr)
	{
		head->Fullname = get_new_name;
		int key = write_string_to_node_t(string, head);
		ASSERT_TRUE(key == error);
		free(head);
	}
}

TEST(write_string_to_node_t, test5)
{
	char* string = nullptr;
	Fullname_t get_new_name = { "firstname", "name", "fathername" };
	node_t* head = (node_t*)malloc(sizeof(node_t));
	if (head != nullptr)
	{
		head->Fullname = get_new_name;
		string = (char*)malloc(sizeof(3 * NAME_LENGTH_MAX + 5));
		if (string == nullptr)
		{
			string = "Helloworldhoneuy Helloworldhoneiy Helloworldhoneoy";  
			int key = write_string_to_node_t(string, head);
			free(string);
			free(head);
			ASSERT_TRUE(key == error);
		}
	}
}

TEST(write_string_to_node_t, test6)
{
	node_t* get_new_name = NULL;
	char string[3 * NAME_LENGTH_MAX + 5] = "Helloworld Helloworld Helloworld";
	int key = write_string_to_node_t(string, get_new_name);
	ASSERT_TRUE(key == error);
}

TEST(write_string_to_node_t, test7)
{

	node_t* get_new_name = (node_t*)malloc(sizeof(node_t));;
	char string[3 * NAME_LENGTH_MAX + 5] = "Helloworld Helloworld Helloworld";
	int key = write_string_to_node_t(string, get_new_name);
	ASSERT_TRUE(key == success);
	free(get_new_name);
}



TEST(add_name_to_the_list, test8)
{
	node_t* head = nullptr;
	node_t* get_new_name = (node_t*)malloc(sizeof(node_t));
	if (get_new_name != nullptr)
	{
		node_t* key = add_name_to_the_list(head, get_new_name);
		ASSERT_TRUE(key == get_new_name);
		free(get_new_name);
	}
}

TEST(add_name_to_the_list, test9)
{
	node_t* get_new_name = nullptr;
	node_t* cheakNull = nullptr;
	node_t* head = (node_t*)malloc(sizeof(node_t));
	if (head != nullptr)
	{
		node_t* key = add_name_to_the_list(head, get_new_name);
		ASSERT_TRUE(key == cheakNull);
		free(head);
	}
}

TEST(add_name_to_the_list, test10)
{
	node_t* head = (node_t*)malloc(sizeof(node_t));
	node_t* head2 = (node_t*)malloc(sizeof(node_t));
	node_t* head3 = (node_t*)malloc(sizeof(node_t));
	node_t* head4 = (node_t*)malloc(sizeof(node_t));


	// we get that head3->head2->NULL and head is separately
	if (head != NULL && head2 != NULL && head3 != NULL && head4 != NULL)
	{
		char temp_one_1[NAME_LENGTH_MAX] = "Navetkina", temp_two_1[NAME_LENGTH_MAX] = "Irina", temp_three_1[NAME_LENGTH_MAX] = "Sergeevna";
		strcpy(head->Fullname.firstname, temp_one_1);
		strcpy(head->Fullname.name, temp_two_1);
		strcpy(head->Fullname.fathername, temp_three_1);
		head->next = NULL;

		char temp_one_2[NAME_LENGTH_MAX] = "Ivanov", temp_two_2[NAME_LENGTH_MAX] = "Nikolay", temp_three_2[NAME_LENGTH_MAX] = "Petrovich";
		strcpy(head2->Fullname.firstname, temp_one_2);
		strcpy(head2->Fullname.name, temp_two_2);
		strcpy(head2->Fullname.fathername, temp_three_2);
		head2->next = NULL;

		char temp_one_3[NAME_LENGTH_MAX] = "Ivanov", temp_two_3[NAME_LENGTH_MAX] = "Boris", temp_three_3[NAME_LENGTH_MAX] = "Crecovich";
		strcpy(head3->Fullname.firstname, temp_one_3);
		strcpy(head3->Fullname.name, temp_two_3);
		strcpy(head3->Fullname.fathername, temp_three_3);
		head3->next = head2;

		char temp_one_4[NAME_LENGTH_MAX] = "Ivanova", temp_two_4[NAME_LENGTH_MAX] = "Karina", temp_three_4[NAME_LENGTH_MAX] = "Pokrashena";
		strcpy(head4->Fullname.firstname, temp_one_4);
		strcpy(head4->Fullname.name, temp_two_4);
		strcpy(head4->Fullname.fathername, temp_three_4);
		head4->next = head2;
		node_t* key = add_name_to_the_list(head3, head4);
		ASSERT_TRUE(key->next->next == head4);
		free(head);
		free(head2);
		free(head3);
		free(head4);
	}
}


TEST(compare_the_name , test11)
{
	char temp_one_1[NAME_LENGTH_MAX] = "Lol", temp_two_1[NAME_LENGTH_MAX] = "Kek", temp_three_1[NAME_LENGTH_MAX] = "Cheburek";
	node_t* head = nullptr;
	node_t* key = compare_the_name (head, temp_one_1, temp_two_1, temp_three_1);
	ASSERT_TRUE(key == nullptr);
}

TEST(compare_the_name , test12)
{
	node_t* head = (node_t*)malloc(sizeof(node_t));
	node_t* head2 = (node_t*)malloc(sizeof(node_t));
	node_t* head3 = (node_t*)malloc(sizeof(node_t));

	if (head != NULL && head2 != NULL && head3 != NULL)
	{
		char temp_one_1[NAME_LENGTH_MAX] = "Ivanov", temp_two_1[NAME_LENGTH_MAX] = "Boris", temp_three_1[NAME_LENGTH_MAX] = "Crecovich";
		strcpy(head->Fullname.firstname, temp_one_1);
		strcpy(head->Fullname.name, temp_two_1);
		strcpy(head->Fullname.fathername, temp_three_1);
		head->next = NULL;

		char temp_one_2[NAME_LENGTH_MAX] = "Ivanov", temp_two_2[NAME_LENGTH_MAX] = "Nikolay", temp_three_2[NAME_LENGTH_MAX] = "Petrovich";
		strcpy(head2->Fullname.firstname, temp_one_2);
		strcpy(head2->Fullname.name, temp_two_2);
		strcpy(head2->Fullname.fathername, temp_three_2);
		head2->next = head;

		char temp_one_3[NAME_LENGTH_MAX] = "Navetkina", temp_two_3[NAME_LENGTH_MAX] = "Irina", temp_three_3[NAME_LENGTH_MAX] = "Sergeevna";
		strcpy(head3->Fullname.firstname, temp_one_3);
		strcpy(head3->Fullname.name, temp_two_3);
		strcpy(head3->Fullname.fathername, temp_three_3);
		head3->next = head2;

		char temp_one_4[NAME_LENGTH_MAX] = "", temp_two_4[NAME_LENGTH_MAX] = "", temp_three_4[NAME_LENGTH_MAX] = "";

		node_t* key = compare_the_name (head3, temp_one_4, temp_two_4, temp_three_4);
		EXPECT_TRUE(key == head3);
		EXPECT_TRUE(key->next == head2);
		EXPECT_TRUE(key->next->next == head);
		free(head);
		free(head2);
		free(head3);
	}
}

TEST(compare_the_name , test13)
{
	node_t* head = (node_t*)malloc(sizeof(node_t));
	node_t* head2 = (node_t*)malloc(sizeof(node_t));
	node_t* head3 = (node_t*)malloc(sizeof(node_t));

	if (head != NULL && head2 != NULL && head3 != NULL)
	{
		char temp_one_1[NAME_LENGTH_MAX] = "Navetkina", temp_two_1[NAME_LENGTH_MAX] = "Irina", temp_three_1[NAME_LENGTH_MAX] = "Sergeevna";
		strcpy(head->Fullname.firstname, temp_one_1);
		strcpy(head->Fullname.name, temp_two_1);
		strcpy(head->Fullname.fathername, temp_three_1);
		head->next = NULL;

		char temp_one_2[NAME_LENGTH_MAX] = "Ivanov", temp_two_2[NAME_LENGTH_MAX] = "Nikolay", temp_three_2[NAME_LENGTH_MAX] = "Petrovich";
		strcpy(head2->Fullname.firstname, temp_one_2);
		strcpy(head2->Fullname.name, temp_two_2);
		strcpy(head2->Fullname.fathername, temp_three_2);
		head2->next = head;

		char temp_one_3[NAME_LENGTH_MAX] = "Ivanov", temp_two_3[NAME_LENGTH_MAX] = "Boris", temp_three_3[NAME_LENGTH_MAX] = "Crecovich";
		strcpy(head3->Fullname.firstname, temp_one_3);
		strcpy(head3->Fullname.name, temp_two_3);
		strcpy(head3->Fullname.fathername, temp_three_3);
		head3->next = head2;

		char temp_one_4[NAME_LENGTH_MAX] = "Iva", temp_two_4[NAME_LENGTH_MAX] = "", temp_three_4[NAME_LENGTH_MAX] = "";
		node_t* key = compare_the_name (head3, temp_one_4, temp_two_4, temp_three_4);

		ASSERT_FALSE(strcmp(key->Fullname.firstname, head3->Fullname.firstname));
		ASSERT_FALSE(strcmp(key->next->Fullname.firstname, head2->Fullname.firstname));
		free(head);
		free(head2);
		free(head3);
	}
}