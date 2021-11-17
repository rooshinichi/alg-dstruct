#include "pch.h"
//#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "gtest/gtest.h"
#include "../pragma019/A25.h"
#include"../pragma019/A25.c"

TEST(add_name_to_node1,test1 ) //adding new data in firstname
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	if (!temp) {
		printf("Error allocating memory\n");
		exit(1);
	}
	char string[] = { "Ivan" };
	add_name_to_node1(temp, string);
	ASSERT_STRCASEEQ(string, temp->firstname);
	free(temp);
}

TEST(add_name_to_node2, test2) //adding new data in name
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	if (!temp) {
		printf("Error allocating memory\n");
		exit(1);
	}
	char string[] = { "Ivanov" };
	add_name_to_node2(temp, string);
	ASSERT_STRCASEEQ(string, temp->name);
	free(temp);
}
TEST(add_name_to_node3, test3 ) //adding new data in fathername
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	if (!temp) {
		printf("Error allocating memory\n");
		exit(1);
	}
	char string[] = { "Ivanovich" };
	add_name_to_node3(temp, string);
	ASSERT_STRCASEEQ(string, temp->fathername);
	free(temp);
}
TEST(insert_front_of_the_node, test4) //check that node_2 is inserted in front of the head
{
	node_t* head_node_1 = (node_t*)malloc(sizeof(node_t));
	node_t* node_2 = (node_t*)malloc(sizeof(node_t));
	if (!head_node_1 || !node_2) {
		printf("Error allocating memory\n");
		exit(1);
	}
	char strA[] = { "A" };
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strD[] = { "D" };
	char strE[] = { "E" };
	char strF[] = { "F" };
	head_node_1->firstname = strA;
	head_node_1->name = strB;
	head_node_1->fathername = strC;
	node_2->firstname = strD;
	node_2->name = strE;
	node_2->fathername = strF;
	head_node_1 = insert_front_of_the_node(&node_2, &head_node_1, head_node_1);
	ASSERT_STRCASEEQ(head_node_1->firstname, strD);
	ASSERT_STRCASEEQ(head_node_1->name, strE);
	ASSERT_STRCASEEQ(head_node_1->fathername, strF);
	ASSERT_STRCASEEQ(head_node_1->next->firstname, strA);
	ASSERT_STRCASEEQ(head_node_1->next->name, strB);
	ASSERT_STRCASEEQ(head_node_1->next->fathername, strC);
	free(head_node_1->next);
	free(head_node_1);
}
TEST(insert_front_of_the_node, test5 ) //check that node_2 is inserted in front of the node_1 which is not the head
{
	node_t* head = (node_t*)malloc(sizeof(node_t));
	node_t* node_1 = (node_t*)malloc(sizeof(node_t));
	node_t* node_2 = (node_t*)malloc(sizeof(node_t));
	if (!head || !node_1 || !node_2) {
		printf("Error allocating memory\n");
		exit(1);
	}
	head->next = node_1;
	char strA[] = { "A" };
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strD[] = { "D" };
	char strE[] = { "E" };
	char strF[] = { "F" };
	head->firstname = strA;
	head->name = strA;
	head->fathername = strA;
	node_1->firstname = strA;
	node_1->name = strB;
	node_1->fathername = strC;
	node_2->firstname = strD;
	node_2->name = strE;
	node_2->fathername = strF;
	head = insert_front_of_the_node(&node_2, &node_1, head);
	node_t* p;
	p = head;
	head = head->next;
	free(p);
	ASSERT_STRCASEEQ(head->firstname, strD);
	ASSERT_STRCASEEQ(head->name, strE);
	ASSERT_STRCASEEQ(head->fathername, strF);
	ASSERT_STRCASEEQ(head->next->firstname, strA);
	ASSERT_STRCASEEQ(head->next->name, strB);
	ASSERT_STRCASEEQ(head->next->fathername, strC);
	free(head->next);
	free(head);
}

TEST(insert_the_position, test6 ) //check that SUCCESS is returned if node_name is less than node_in_list_name
{
	node_t* node_1 = (node_t*)malloc(sizeof(node_t));
	node_t* node_2 = (node_t*)malloc(sizeof(node_t));
	if (!node_1 || !node_2) {
		printf("Error allocating memory\n");
		exit(1);
	}
	char strA[] = { "A" };
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strD[] = { "D" };
	char strE[] = { "E" };
	char strF[] = { "F" };
	node_1->firstname = strA;
	node_1->name = strB;
	node_1->fathername = strC;
	node_2->firstname = strD;
	node_2->name = strE;
	node_2->fathername = strF;
	ASSERT_EQ(insert_the_position(node_1->firstname, node_2->firstname, &node_1, &node_2, &node_2), SUCCESS);
	free(node_1->next);
	free(node_1);
}

TEST(insert_the_position, test7) 
{
	node_t* node_1 = (node_t*)malloc(sizeof(node_t));
	node_t* node_2 = (node_t*)malloc(sizeof(node_t));
	if (!node_1 || !node_2) {
		printf("Error allocating memory\n");
		exit(1);
	}
	node_2->next = NULL;
	char strA[] = { "A" };
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strD[] = { "D" };
	char strE[] = { "E" };
	char strF[] = { "F" };
	node_1->firstname = strD;
	node_1->name = strB;
	node_1->fathername = strC;
	node_2->firstname = strA;
	node_2->name = strE;
	node_2->fathername = strF;
	ASSERT_EQ(insert_the_position(node_1->firstname, node_2->firstname, &node_1, &node_2, &node_2), SUCCESS_2);
	free(node_1);
	free(node_2);
}
TEST(insert_the_position,teat8 )
{
	node_t* node_1 = (node_t*)malloc(sizeof(node_t));
	node_t* node_2 = (node_t*)malloc(sizeof(node_t));
	if (!node_1 || !node_2) {
		printf("Error allocating memory\n");
		exit(1);
	}
	node_2->next = NULL;
	char strA[] = { "A" };
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strE[] = { "E" };
	char strF[] = { "F" };
	node_1->firstname = strA;
	node_1->name = strB;
	node_1->fathername = strC;
	node_2->firstname = strA;
	node_2->name = strE;
	node_2->fathername = strF;
	ASSERT_EQ(insert_the_position(node_1->firstname, node_2->firstname, &node_1, &node_2, &node_2), SUCCESS_2);
	free(node_1);
	free(node_2);
}

TEST(insert_the_position,teat9 )
{
	node_t* node_1 = (node_t*)malloc(sizeof(node_t));
	node_t* node_2 = (node_t*)malloc(sizeof(node_t));
	if (!node_1 || !node_2) {
		printf("Error allocating memory\n");
		exit(1);
	}
	char strA[] = { "A" };
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strD[] = { "D" };
	char strE[] = { "E" };
	char strF[] = { "F" };
	node_1->firstname = strD;
	node_1->name = strB;
	node_1->fathername = strC;
	node_2->firstname = strA;
	node_2->name = strE;
	node_2->fathername = strF;
	node_t* p;
	p = node_2;
	ASSERT_EQ(insert_the_position(node_1->firstname, node_2->firstname, &node_1, &node_2, &node_2), ERROR);
	free(node_1);
	free(p);
}
TEST(insert_the_position, teat10) 
{
	node_t* node_1 = (node_t*)malloc(sizeof(node_t));
	node_t* node_2 = (node_t*)malloc(sizeof(node_t));
	if (!node_1 || !node_2) {
		printf("Error allocating memory\n");
		exit(1);
	}
	char strA[] = { "A" };
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strE[] = { "E" };
	char strF[] = { "F" };
	node_1->firstname = strA;
	node_1->name = strB;
	node_1->fathername = strC;
	node_2->firstname = strA;
	node_2->name = strE;
	node_2->fathername = strF;
	node_t* p;
	p = node_2;
	ASSERT_EQ(insert_the_position(node_1->firstname, node_2->firstname, &node_1, &node_2, &node_2), ERROR);
	free(node_1);
	free(p);
}
TEST(insert_the_position, teat11)
{
	node_t* node_1 = (node_t*)malloc(sizeof(node_t));
	node_t* node_2 = (node_t*)malloc(sizeof(node_t));
	node_t* node_2_next = (node_t*)malloc(sizeof(node_t));
	if (!node_1 || !node_2 || !node_2_next) {
		printf("Error allocating memory\n");
		exit(1);
	}
	node_2->next = node_2_next;
	char strA[] = { "A" };
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strD[] = { "D" };
	char strE[] = { "E" };
	char strF[] = { "F" };
	char strH[] = { "H" };
	char strI[] = { "I" };
	char strJ[] = { "J" };
	node_1->firstname = strD;
	node_1->name = strB;
	node_1->fathername = strC;
	node_2->firstname = strA;
	node_2->name = strE;
	node_2->fathername = strF;
	node_2_next->firstname = strH;
	node_2_next->name = strI;
	node_2_next->fathername = strJ;
	node_t* tmp1;
	node_t* tmp2;
	node_t* tmp3;
	tmp1 = node_1;
	tmp2 = node_2;
	tmp3 = node_2_next;
	insert_the_position(node_1->firstname, node_2->firstname, &node_1, &node_2, &node_2);
	ASSERT_STRCASEEQ(node_2->firstname, strH);
	ASSERT_STRCASEEQ(node_2->name, strI);
	ASSERT_STRCASEEQ(node_2->fathername, strJ);
	free(tmp1);
	free(tmp2);
	free(tmp3);
}
TEST(insert_the_position,teat12) 
{
	node_t* node_1 = (node_t*)malloc(sizeof(node_t));
	node_t* node_2 = (node_t*)malloc(sizeof(node_t));
	node_t* node_2_next = (node_t*)malloc(sizeof(node_t));
	if (!node_1 || !node_2 || !node_2_next) {
		printf("Error allocating memory\n");
		exit(1);
	}
	node_2->next = node_2_next;
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strD[] = { "D" };
	char strE[] = { "E" };
	char strF[] = { "F" };
	char strH[] = { "H" };
	char strI[] = { "I" };
	char strJ[] = { "J" };
	node_1->firstname = strD;
	node_1->name = strB;
	node_1->fathername = strC;
	node_2->firstname = strD;
	node_2->name = strE;
	node_2->fathername = strF;
	node_2_next->firstname = strH;
	node_2_next->name = strI;
	node_2_next->fathername = strJ;
	node_t* tmp1;
	node_t* tmp2;
	node_t* tmp3;
	tmp1 = node_1;
	tmp2 = node_2;
	tmp3 = node_2_next;
	insert_the_position(node_1->firstname, node_2->firstname, &node_1, &node_2, &node_2);
	ASSERT_STRCASEEQ(node_2->firstname, strH);
	ASSERT_STRCASEEQ(node_2->name, strI);
	ASSERT_STRCASEEQ(node_2->fathername, strJ);
	free(tmp1);
	free(tmp2);
	free(tmp3);
}
TEST(sort_node, test13) 
{
	node_t* zero = (node_t*)malloc(sizeof(node_t));
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (!zero || !node) {
		printf("Error allocating memory\n");
		exit(1);
	}
	zero->next = NULL;
	char firstname[] = { "A" };
	char name[] = { "B" };
	char fathername[] = { "C" };
	zero->firstname = firstname;
	zero->name = name;
	zero->fathername = fathername;
	node->firstname = firstname;
	node->name = name;
	node->fathername = fathername;
	zero = sort_node(zero, node);
	ASSERT_STRCASEEQ(zero->firstname, firstname);
	ASSERT_STRCASEEQ(zero->name, name);
	ASSERT_STRCASEEQ(zero->fathername, fathername);
	ASSERT_STRCASEEQ(zero->next->firstname, firstname);
	ASSERT_STRCASEEQ(zero->next->name, name);
	ASSERT_STRCASEEQ(zero->next->fathername, fathername);
	free(zero);
	free(node);
}
TEST(sort_node,test14) 
{
	node_t* zero = (node_t*)malloc(sizeof(node_t));
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (!zero || !node) {
		printf("Error allocating memory\n");
		exit(1);
	}
	zero->next = NULL;
	char strA[] = { "A" };
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strD[] = { "D" };
	char strE[] = { "E" };
	char strF[] = { "F" };
	node->firstname = strA;
	node->name = strB;
	node->fathername = strC;
	zero->firstname = strD;
	zero->name = strE;
	zero->fathername = strF;
	zero = sort_node(zero, node);
	ASSERT_STRCASEEQ(zero->firstname, strA);
	ASSERT_STRCASEEQ(zero->name, strB);
	ASSERT_STRCASEEQ(zero->fathername, strC);
	ASSERT_STRCASEEQ(zero->next->firstname, strD);
	ASSERT_STRCASEEQ(zero->next->name, strE);
	ASSERT_STRCASEEQ(zero->next->fathername, strF);
	free(zero->next);
	free(zero);
}
TEST(sort_node, test15)
{
	node_t* zero = (node_t*)malloc(sizeof(node_t));
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (!zero || !node) {
		printf("Error allocating memory\n");
		exit(1);
	}
	zero->next = NULL;
	char strA[] = { "A" };
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strD[] = { "D" };
	char strE[] = { "E" };
	node->firstname = strA;
	node->name = strB;
	node->fathername = strC;
	zero->firstname = strD;
	zero->name = strB;
	zero->fathername = strE;

	zero = sort_node(zero, node);
	ASSERT_STRCASEEQ(zero->firstname, strA);
	ASSERT_STRCASEEQ(zero->name, strB);
	ASSERT_STRCASEEQ(zero->fathername, strC);
	ASSERT_STRCASEEQ(zero->next->firstname, strD);
	ASSERT_STRCASEEQ(zero->next->name, strB);
	ASSERT_STRCASEEQ(zero->next->fathername, strE);
	free(zero->next);
	free(zero);
}
TEST(sort_node, test16) 
{
	node_t* zero = (node_t*)malloc(sizeof(node_t));
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (!zero || !node) {
		printf("Error allocating memory\n");
		exit(1);
	}
	zero->next = NULL;
	char strA[] = { "A" };
	char strB[] = { "B" };
	char strC[] = { "C" };
	char strD[] = { "D" };
	node->firstname = strA;
	node->name = strB;
	node->fathername = strC;
	zero->firstname = strA;
	zero->name = strB;
	zero->fathername = strD;
	zero = sort_node(zero, node);
	ASSERT_STRCASEEQ(zero->firstname, strA);
	ASSERT_STRCASEEQ(zero->name, strB);
	ASSERT_STRCASEEQ(zero->fathername, strC);
	ASSERT_STRCASEEQ(zero->next->firstname, strA);
	ASSERT_STRCASEEQ(zero->next->name, strB);
	ASSERT_STRCASEEQ(zero->next->fathername, strD);
	free(zero->next);
	free(zero);
}
