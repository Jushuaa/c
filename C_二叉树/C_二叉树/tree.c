#include"tree.h"
#include"Queue.h"
#include"Stack.h"
BTNode* BuyBTNode(BTDataType x)
{
	BTNode * node = (BTNode *)malloc(sizeof(BTNode));
	node->_left = NULL;
	node->_right = NULL;
	node->_data = x;
	return node;
}
// a是一个前序遍历的数组
BTNode* BinaryTreeCreate(BTDataType* a, int n, int pi)
{
	if (a[pi] != '#')
	{
		BTNode* root = BuyBTNode(a[pi]);
		++(pi);
		root->_left = BinaryTreeCreate(a, n, pi);
		++(pi);
		root->_right = BinaryTreeCreate(a, n, pi);
		return root;
	}
	else
	{
		return 0;
	}

}

void BinaryTreeDestory(BTNode** pptree)
{
	BTNode* root = *pptree;
	if (root == NULL)
		return;
	
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
	*pptree = NULL;
}
int size = 0;
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return NULL;
	if (root->_left == NULL&&root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k = 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1)+BinaryTreeLevelKSize(root ->_right, k - 1);
}
// 遍历  递归&非递归
void BinaryTreePrevOrder(BTNode* root)//前序
{
	if (root == NULL)
	{
		return;
	}
	printf("%c", root->_data);
	BinaryTreePrevOrder(root->_left);	
	BinaryTreePrevOrder(root->_right);

}

void BinaryTreeInOrder(BTNode* root)//中序
{
	if (root == NULL)
		return ;

	BinaryTreePrevOrder(root->_left);
	printf("%c", root->_data);
	BinaryTreePrevOrder(root->_right);
}
void BinaryTreePostOrder(BTNode* root)//后序
{
	if (root == NULL)
		return NULL;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c", root->_data);
}
void BinaryTreeLevelOrder(BTNode* root)//层序
{
		Queue q;
		QueueInit(&q);
		if (root)
		{
			QueuePush(&q, root);
			while (QueueEmpty(&q != 0))
			{
				BTNode* front = QueueFront(&q);
				printf("%c", front->_data);
				if (front->_left)
				{
					QueuePush(&q, front->_left);
				}
				if (front->_left)
				{
					QueuePush(&q, front->_left);
				}
			}
			QueuePop(&q);
		}
}
int BinaryTreeHeight(BTNode * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftHeight = BinaryTreeHeight(root->_left);
	int rightHeight = BinaryTreeHeight(root->_right);
	return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root == NULL || root->_data == x)
	{
		return root;
	}
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
	{
		return ret;
	}
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
		{
			return ret;
		}
}
int BinaryTreeComplete(BTNode*root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (QueueEmpty(&q) != NULL)
	{
		BTNode* front = QueueFront(&q);
		if (front)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{
			break;
		}
	}

	while (QueueEmpty(&q) != NULL)
	{
		BTNode* front = QueueFront(&q);
		if (front)
		{
			QueueDestory(&q);
			return -1;
		}
		else
		{
			QueuePop(&q);
		}
		return 0;
	}
}
int BinaryTreeComplete1(BTNode* root)
{
	Queue q;
	if (root == root)
		printf("空树\n");
		return 1;
	
	QueuePush(&q, root);
	//这里给一个flag是标记是否出现过满结点
	int flag=0;
	int count = 0;
	while (QueueEmpty(&q) != NULL)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q); //如果队首元素的左子树为空将标记置为false如果层序遍历后面的节点还有子树说明不是
		if (front != NULL && (front->_left&&front->_right))
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		if (front == NULL)
		{
			flag = NULL;
			count++;
		}
		else
		{
			if (count == 1)
			{
				flag = 0;
				return 0;
			}
			else
			{
				flag = 0;
			}
		}
	}
	if (flag = 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}		
void BinaryTreePrevOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode * top;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s)!=NULL)
	{
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
	}
	top = StackTop(&s);
	StackPop(&s);
	cur = top->_right;
}

void BinaryTreeInOrderNonR(BTNode* root)
{

	BTNode* cur = root;
	BTNode * top;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s)!=NULL)
	{
		while (cur)
		{
			
			StackPush(&s, cur);
			cur = cur->_left;
		}
	}
    top = StackTop(&s);
	StackPop(&s);
	printf("%c ", cur->_data);
	
	cur = top->_right;
}
void BinaryTreePostOrderNonR(BTNode* root)
{

	BTNode* cur = root;
	BTNode* top; BTNode* prev;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;   //访问左树
			top = StackTop(&s);
			prev = top;
			if (top->_right == NULL || top->_right == prev)
			{
				printf("%c ", top->_data);  //根节点
				prev = top;
				StackPop(&s);
			}
			else
			{
				cur = top->_right;     //访问右树
			}
		}
	}
}