#include "tree.h"

tree_t* create_bin_tree()
{
	tree_t* tree = (tree_t*)malloc(sizeof(tree_t));
	if (tree == NULL)
	{
		printf("Allocation memory error\n");
		return NULL;
	}
	tree->right = NULL;
	tree->left = NULL;
	tree->key = NONE;
	
	return tree;
}

void destroy_tree(tree_t* tree)
{
	if (tree != NULL)
	{
		destroy_tree(tree->left);
		destroy_tree(tree->right);
		free(tree);
	}
}

void print_tree(tree_t* tree, int level)
{
	if (tree != NULL)
	{
		print_tree(tree->left, level + 1);
		for (int i = 0; i < level; i++)
		{
			printf("    ");
		}
		if (tree->key == NONE)
		{
			printf("*\n");
		}
		else
		{
			printf("%d\n", tree->key);
		}
		print_tree(tree->right, level + 1);

	}
}

void sub_tree(tree_t* parent, int tree_left, int tree_right)
{
	if (parent == NULL)
	{
		printf("NULL pointer");
		return;
	}
	if (tree_left == TRUE)
	{
		parent->left = create_bin_tree();
	}
	if (tree_right == TRUE)
	{
		parent->right = create_bin_tree();
	}
}

tree_t* example_min_tree(void)
{
	tree_t* root = create_bin_tree();
	tree_t* temp;

	temp = root;
	sub_tree(temp, TRUE, TRUE);

	temp = root->left;
	sub_tree(temp, TRUE, TRUE);
	temp = root->right;
	sub_tree(temp, FAL, FAL);

	temp = root->left->left;
	sub_tree(temp, TRUE, FAL);
	temp = root->left->right;
	sub_tree(temp, FAL, TRUE);

	temp = root->left->left->left;
	sub_tree(temp, TRUE, TRUE);
	temp = root->right;
	sub_tree(temp, TRUE, TRUE);
	return root;
}

void min_tree(tree_t* tree)
{
	if ((NULL != tree->left) && (NULL != tree->right))
	{
		min_tree(tree->left);
		min_tree(tree->right);
		if (tree->left->key > NONE)
		{
			tree->key = tree->left->key + 1;
		}
		if (tree->right->key > NONE)
		{
			tree->key = min(tree->key, tree->right->key + 1);
		}
	}
	else
	{
		if (NULL != tree->left)
		{
			min_tree(tree->left);
			if (tree->left->key > NONE)
			{
				tree->key = tree->left->key + 1;
				return;
			}
			return;
		}
		if (tree->right != NULL)
		{
			min_tree(tree->right);
			if (tree->right->key > NONE)
			{
				tree->key = tree->right->key + 1;
				return;
			}

		}
		else
		{
			tree->key = 0;
		}
	}
}
