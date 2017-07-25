/*
 *
 *描述:二叉搜索树，又名二叉排序树，二叉查找树，右节点>中>左，中序遍历会得到从小到大的结果
 *时间:20170725
 */

#include<iostream>
using namespace std;

typedef struct node
{
	int key;
	struct node *lchild,*rchild;
}Node, *BST;

bool BSTInsert(Node *&p,int element)
{
	//存在的问题就是，因为根节点取得是第一个，如果第一个值最小，就容易造成左右子树高度相差太大，增加搜索时间
	if(NULL == p)//空树
	{
		p = new Node;
		p->key = element;
		p->lchild = p->rchild = NULL;
		return true;
	}
	//分三种情况进行讨论:判断大小
	if(element == p->key)
		return false;	//不能存在相同元素
	else if(element < p->key)
		return BSTInsert(p->lchild,element);	//插入到柚子树当中
	else
		return BSTInsert(p->rchild,element);	//插入到左子树当中
	
}

//建立BST
void createBST(Node *&T,int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		BSTInsert(T,a[i]);
	}
}

//中序遍历二叉树

void traverseBST(Node *&root)
{
	if(root!=NULL)
	{
		traverseBST(root->lchild);
		cout<<root->key<<" ";
		traverseBST(root->rchild);
	}
}

int main()
{
	Node *root=NULL;
	int a[10]={4,2,0,3,5,7,9,6,8,1};
	createBST(root,a,10);
	cout<<"root->key="<<root->key;
	traverseBST(root);
	return 0;
}
