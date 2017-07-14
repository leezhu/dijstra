/*
 *树的前中后序遍历访问
 */

#include<iostream>
using namespace std;

typedef struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
}

void pre_order(TreeNode* Node)
{
	if(Node!=NULL)
	{
		printf("%d",Node->data);
		pre_order(Node->left);
		pre_order(Node->right);
	}
}

int main()
{

}
