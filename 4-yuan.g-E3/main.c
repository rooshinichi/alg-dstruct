#include "tree.h"

int main(void)
{
	tree_t* tree = example_min_tree();
	print_tree(tree, 0);
	printf("\n\n");
	min_tree(tree);
	print_tree(tree, 0);

	destroy_tree(tree);

	return 0;
}
