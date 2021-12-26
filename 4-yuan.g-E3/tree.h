#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#pragma warning(disable: 4996)

#define NONE -1
#define TRUE 1
#define FAL 0

typedef struct tree_t
{
	int key;
	struct tree_t* left;
	struct tree_t* right;

}tree_t;

//创建新树
tree_t* create_bin_tree();

//打印树
void print_tree(tree_t* tree, int level);

//删除所有树，free操作
void destroy_tree(tree_t* tree);

//创建树分支
void sub_tree(tree_t* parent, int tree_left, int tree_right);

//用*来举例
tree_t* example_min_tree(void);

//最小分支树
void min_tree(tree_t* tree);
