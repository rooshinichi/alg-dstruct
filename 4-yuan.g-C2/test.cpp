#include"pch.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "gtest/gtest.h"

#include "../pragma021_LabC/labC2.h"
#include "../pragma021_LabC/main.c"

TEST(create_edge, adding_data) 
{
	edge_t* head;
	int data1 = 1;
	int data2 = 2;
	head = create_edge(data1, data2);
	ASSERT_EQ(data1, head->start_edge);
	ASSERT_EQ(data2, head->end_edge);
	free(head);
}
TEST(add_edge, adding_data_to_the_created_node_when_1_node_in_list) 
{
	edge_t* head = (edge_t*)malloc(sizeof(edge_t));
	if (!head) 
	{
		printf("Error allocating memory\n");
		exit(1);
	}
	head->next = NULL;
	int data_head1 = 1;
	int data_head2 = 2;
	head->start_edge = data_head1;
	head->end_edge = data_head2;
	int add_node_data1 = 3;
	int add_node_data2 = 4;
	head = add_edge(head, add_node_data1, add_node_data2);
	ASSERT_EQ(data_head1, head->start_edge);
	ASSERT_EQ(data_head2, head->end_edge);
	ASSERT_EQ(add_node_data1,(head->next)->start_edge);
	ASSERT_EQ(add_node_data2,(head->next)->end_edge);
	free(head->next);
	free(head);
}
TEST(add_edge, adding_data_to_the_created_node_when_more_than_1_node_in_list) 
{
	edge_t* head = (edge_t*)malloc(sizeof(edge_t));
	if (!head) 
	{
		printf("Error allocating memory\n");
		exit(1);
	}
	edge_t* node1 = (edge_t*)malloc(sizeof(edge_t));
	if (!node1) 
	{
		printf("Error allocating memory\n");
		exit(1);
	}
	head->next = node1;
	int data_head1 = 1;
	int data_head2 = 2;
	head->start_edge = data_head1;
	head->end_edge = data_head2;
	int node1_data1 = 3;
	int node2_data2 = 4;
	node1->start_edge = node1_data1;
	node1->end_edge = node2_data2;
	node1->next = NULL;
	int add_node_data1 = 5;
	int add_node_data2 = 6;
	head = add_edge(head, add_node_data1, add_node_data2);
	edge_t* temp = head;
	ASSERT_EQ(data_head1, temp->start_edge);
	ASSERT_EQ(data_head2, temp->end_edge);
	temp = temp->next;
	ASSERT_EQ(node1_data1, temp->start_edge);
	ASSERT_EQ(node2_data2, temp->end_edge);
	temp = temp->next;
	ASSERT_EQ(add_node_data1, temp->start_edge);
	ASSERT_EQ(add_node_data2, temp->end_edge);
	free((head->next)->next);
	free(head->next);
	free(head);
}
