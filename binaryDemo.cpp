/*
 *二叉树的练习，包括遍历，得到高度，还有其他等等
 *时间:20170717
 */

#include<iostream>
#include<queue>
using namespace std;

typedef struct node
{
	struct node *lchild;
	struct node *rchild;
	int data;
}BiTreeNode;

/*
 * 可以输入 1 2 4  0 0 5 0 0 3 6 0 0 0
 * 建立如下的树结构:
 *			1
 *		  /   \
 *		2		3
 *	  /  \    /   
 *	4	  5  6
 */
//建立二叉树
void createBiTree(BiTreeNode* &T)
{
	int data;
	cin>>data;
	if(0==data)
		T=NULL;
	else{
		T = new BiTreeNode;
		T->data = data;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}

//深度优先，前、中、后序遍历
void preorder(BiTreeNode* T)
{
	if(T)
	{
		cout<<T->data<<" ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

//二叉树中的节点个数,左右子树的个数加上根节点
int getNodeNum(const BiTreeNode* T)
{
	if(T == NULL)
		return 0;
	return getNodeNum(T->lchild)+getNodeNum(T->rchild)+1;
}

//二叉树的深度,用递归，左右子树的深度加1
int getDepth(BiTreeNode* T)
{
	if(T == NULL)
		return 0;
	int depthLeft = getDepth(T->lchild);
	int depthRight = getDepth(T->rchild);
	cout<<"depthLeft="<<depthLeft<<"depthRight="<<depthRight<<endl;
	return depthLeft > depthRight?(depthLeft+1):(depthRight+1);
}

//广度优先遍历，利用队列
void levelTraverse(BiTreeNode* T)
{
	if(T == NULL)
		return;
	queue<BiTreeNode*> q;
	q.push(T);
	while(!q.empty())
	{
		BiTreeNode *pNode = q.front();
		q.pop();
		cout<<"data ="<<pNode->data;
		if(pNode->lchild!=NULL)
			q.push(pNode->lchild);

		if(pNode->rchild!=NULL)
			q.push(pNode->rchild);
	}
	return;
}

//求二叉树第K层的节点个数
//如果为空或者小于1，返回0
//如果不为空并且等于1，返回1
//如果大于1，返回左右子树k-1层的节点个数
int getNodeNumKthLevel(BiTreeNode* T,int k)
{
	if(T == NULL || k < 1)	
		return 0;
	if(k==1)
		return 1;
	int numLeft = getNodeNumKthLevel(T->lchild,k-1);
	int numRight = getNodeNumKthLevel(T->rchild,k-1);
	return numLeft + numRight;
	
}
//求k层节点个数的另外一种合理方法
size_t findLevel(BiTreeNode* T,size_t k,size_t level)
{
	static size_t num=0;
	if(T == NULL)
		return 0;
	if(level == k)
	{	num++;
		return num;
	}
	findLevel(T->lchild,k,level+1);	
	findLevel(T->rchild,k,level+1);	
	return num;
}

//判断二叉树是否为完全二叉树
//完全二叉树就是指，深度为h，除第H层外，其余各层的节点数都达到最大个数，而且第H层的叶子节点都集中在左边
//思想:利用层次遍历，当遇到左子树为空的情况，则柚子树必须为空，且后面遍历的必须都是左右子树都为空，否则不是
bool isCompleteBinaryTree(BiTreeNode*T)
{
	if(T == NULL)
		return false;
	queue<BiTreeNode*> q;
	q.push(T);
	bool mustHaveNochild = false;//判断是否出现空子树
	bool result = true;
	while(!q.empty())
	{
		BiTreeNode* pNode = q.front();
		q.pop();

		if(mustHaveNochild)	//出现空子树
		{
			if(pNode->lchild != NULL || pNode->rchild !=NULL)//这个节点子树不为空
			{
				result = false;
				break;
			}
		}
		else	//分为四种情况进行讨论
		{
			if(pNode->lchild != NULL && pNode->rchild != NULL)//左右都不为空
			{
				q.push(pNode->lchild);
				q.push(pNode->rchild);
			}
			else if(pNode->lchild != NULL && pNode->rchild == NULL)//右为空
			{
				mustHaveNochild = true;	//出现了柚子树为空的，那么后面必须是叶子节点
				q.push(pNode->lchild);
			}
			else if(pNode->lchild == NULL && pNode->rchild != NULL)//左为空，右不为空
			{
				result = false;
				break;
			}
			else{	//都为空
				mustHaveNochild = true;
			}
		}
	}
	return result;
}
int main()
{
	BiTreeNode* rootNode ;
	createBiTree(rootNode);
	//preorder(rootNode);
	//cout<<getDepth(rootNode)<<" "<<getNodeNum(rootNode);
	//levelTraverse(rootNode);
//	cout<<getNodeNumKthLevel(rootNode,2);
	//cout<<findLevel(rootNode,3,1);
	cout<<isCompleteBinaryTree(rootNode);
	return 0;
}
