#include "BinaryTree.h"

//创建二叉树
TreeNode* CreateBinaryTree(TreeNode* root)
{
	DataType ch;
	ch = getchar();

	if (ch == '#')
	{
		return nullptr;
	}
	else
	{
		root = (TreeNode*)malloc(sizeof(TreeNode));
		if (root == NULL)
		{
			exit(0);
		}
		root->data = ch;
		root->leftChild = CreateBinaryTree(root->leftChild);
		root->rightChild = CreateBinaryTree(root->rightChild);
	}
	return root;
}

// 先序 递归
void PreOrderPrint_Recursion(const TreeNode* Tree)
{
	if (!Tree)
	{
		return;
	}
	cout << Tree->data << "->";
	PreOrderPrint_Recursion(Tree->leftChild);
	PreOrderPrint_Recursion(Tree->rightChild);
}
// 先序 非递归
void PreOrderPrint(TreeNode* Tree)
{
	if (!Tree)
	{
		return;
	}

	stack<TreeNode*> st;
	TreeNode* p = Tree;

	while (p != nullptr || !st.empty())
	{
		while (p != nullptr)
		{
			cout << p->data << "->";
			st.push(p);
			p = p->leftChild;
		}

		if (!st.empty())
		{
			p = st.top();
			st.pop();
			p = p->rightChild;
		}
	} 

}
// 中序 递归
void MidOrderPrint_Recursion(const TreeNode* Tree)
{
	if (!Tree)
	{
		return;
	}
	PreOrderPrint_Recursion(Tree->leftChild);
	cout << Tree->data << "->";
	PreOrderPrint_Recursion(Tree->rightChild);
}

// 中序 非递归
void MidOrderPrint(TreeNode* Tree)
{
	if (!Tree)
	{
		return;
	}

	stack<TreeNode*> st;
	TreeNode* p = Tree;

	while (p != nullptr || !st.empty())
	{
		while (p != nullptr)
		{
			st.push(p);
			p = p->leftChild;
		}

		if (!st.empty())
		{
			p = st.top();
			cout << p->data << "->";
			st.pop();
			p = p->rightChild;
		}
	} 

}

// 后序 递归
void PostOrderPrint_Recursion(const TreeNode* Tree)
{
	if (!Tree)
	{
		return;
	}
	PreOrderPrint_Recursion(Tree->leftChild);
	PreOrderPrint_Recursion(Tree->rightChild);
	cout << Tree->data << "->";
}

void PostOrderPrint(TreeNode* Tree)
{
	if (!Tree)
	{
		return;
	}

	stack<TreeNode*> st;
	TreeNode* cur;//当前结点 
	TreeNode* pre = nullptr;//前一次访问的结点

	st.push(Tree);
	while(!st.empty())
	{
		cur = st.top();
		if ((cur->leftChild == nullptr && cur->rightChild == nullptr) ||
			(pre != NULL && (pre == cur->leftChild || pre == cur->rightChild)))
		{
			cout<<cur->data<<" ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
			st.pop();
			pre = cur;
		}
		else
		{
			if(nullptr != cur->rightChild)
				st.push(cur->rightChild);
			if(nullptr != cur->leftChild)    
				st.push(cur->leftChild);
		}
	}
}


// 层序_数组实现 非递归(用数组实现了FIFO)
void FloorPrint(TreeNode* Tree)
{
	if (Tree == nullptr)
	{
		return;
	}

	TreeNode* pList[100]; //创建TreeNode*指针类型的指针数组
	int in = 0;
	int out = 0; 
	TreeNode* tmp = nullptr;

	cout << "FloorPrint_List :";
	// 先保存根节点
	pList[in++] = Tree;

	while(in > out)
	{
		tmp = pList[out];
		if (tmp)
		{
			cout << tmp->data << "->";
			pList[in++] = tmp->leftChild;
			pList[in++] = tmp->rightChild;
		}
		out++;
	}

	cout << "NULL" << endl;
}

// 层序遍历_队列实现 非递归
void FloorPrint_Queue(TreeNode* Tree)
{
	if (Tree == nullptr)
	{
		return;
	}
	cout << "FloorPrint_Queue :";
	// 创建队列
	queue<TreeNode*> q;
	// root节点入队
	q.push(Tree);

	while(!q.empty())
	{
		for (size_t i = 0; i < q.size(); ++i)
		{
			TreeNode* tmp = q.front();
			cout << tmp->data << "->";

			// 孩子入队
			if (nullptr != tmp->leftChild)
			{
				q.push(tmp->leftChild);
			}
			if (nullptr != tmp->rightChild)
			{
				q.push(tmp->rightChild);
			}

			// 读取过的出队
			q.pop();
		}
	}

	cout << "NULL" << endl;
}

void main()
{
	TreeNode* pTree = nullptr;
	pTree = CreateBinaryTree(pTree);

	cout << "PreOrderPrint :";
	PreOrderPrint_Recursion(pTree);
	cout << "NULL" << endl;

	cout << "MidOrderPrint :";
	MidOrderPrint_Recursion(pTree);
	cout << "NULL" << endl;

	cout << "PostOrderPrint :";
	PostOrderPrint_Recursion(pTree);
	cout << "NULL" << endl;

	FloorPrint_Queue(pTree);

	FloorPrint(pTree);

	system("pause");
}
