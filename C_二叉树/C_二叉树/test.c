#include"tree.h"
#include"Queue.h"
#include"Stack.h"
void TestBinaryTree()
{
	BTNode* root;
	char array[] = { 'A', 'B', 'D', '#', '#', '#', 'C', 'E', '#', '#', 'F', '#', '#' };
	size_t i = 0;
	BTNode* tree = BinaryTreeCreate(array, (sizeof(array) / sizeof(BTDataType(*))), i);
	//BinaryTreePrevOrder(&root);
	printf("\n");
    //BinaryTreeInOrder(&root);
	printf("\n");
	//BinaryTreePostOrder(&root);
	printf("\n");
	//BinaryTreeLevelOrder(&root);
	printf("\n");
	//int ret = BinaryTreeFind(&ret, 'A');
	//printf("%c\n", ret);
	//BinaryTreeHeight(&root);
	printf("\n");
	//BinaryTreeComplete(&root);
	printf("\n");
	//BinaryTreeComplete1(&root);
	printf("\n");
	//int size = BinaryTreeSize(&root);
	printf("\n");
	//BinaryTreePrevOrderNonR(&root);
	printf("\n");
	//BinaryTreeInOrderNonR(&root);
	printf("\n");
	//BinaryTreePostOrderNonR(&root);
	printf("\n");
	
}
int main()
{
	TestBinaryTree();
	system("pause");
	return 0;
}