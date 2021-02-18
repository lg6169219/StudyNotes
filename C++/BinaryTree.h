#pragma once

#include<iostream>
#include<cstring>
#include <queue>
#include <stack>

using namespace std;

// define data structure;
typedef char DataType;
typedef struct TreeNode
{
	DataType data;
	struct TreeNode* leftChild;
	struct TreeNode* rightChild;
}TreeNode;

//创建二叉树
TreeNode* CreateBinaryTree(TreeNode* root); 
// 先序 递归
void PreOrderPrint_Recursion(const TreeNode* Tree);
void PreOrderPrint(TreeNode* Tree); // 非递归 利用栈先进先出的特点
// 中序
void MidOrderPrint_Recursion(const TreeNode* Tree);
void MidOrderPrint(TreeNode* Tree);
// 后序
void PostOrderPrint_Recursion(const TreeNode* Tree);
void PostOrderPrint(TreeNode* Tree); // 后序比较复杂只做了解
// 层序
void FloorPrint(TreeNode* Tree);
// 层序遍历_队列实现
void FloorPrint_Queue(TreeNode* Tree);
