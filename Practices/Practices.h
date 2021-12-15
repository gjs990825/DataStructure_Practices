#pragma once

#include <iostream>
#include "utils.h"

/************************线性表************************/
// 逆转顺序表中的所有元素
Elem_t* SeqList_Reverse(Elem_t a[], int n);
// 逆转顺序表中范围内元素
Elem_t* SeqList_ReverseRange(int a[], int l, int h);
// 循环右移
Elem_t* SeqList_Ror(Elem_t* a, int n, int i);
// 循环左移
Elem_t* SeqList_Rol(Elem_t* a, int n, int i);
// 逆转线性链表
LinkList& LinkList_Reverse(LinkList& l);
// 拷贝线性链表
LinkList LinkList_Copy(LinkList l);
// **剩余表的连接
// 合并两个非空的有序线性链表
LinkList LinkList_Merge(LinkList la, LinkList lb);
// 递归，删除不带头节点的单链表L中所有值为x的节点
void LinkList_NoHeadNodeDelX(LinkList& l, Elem_t x);
// 非递归
void LinkList_NoHeadNodeDelXIterative(LinkList& l, Elem_t x);
// **记录偏移量
// 删除顺序表中在[s,t]上的值
bool SeqList_DelStoT(SeqList& l, Elem_t s, Elem_t t);
// 合并两个有序顺序表
bool SeqList_Merge(SeqList a, SeqList b, SeqList& c);
// 删除有序顺序表中重复元素
bool SeqList_DeleteDuplicate(SeqList& l);
// 逆序输出带头节点的单链表
void LinkList_WithHeadReverseOutput(LinkList l);
// 删除带头节点的单链表L中所有值为x的节点
void LinkList_WithHeadNodeDelX(LinkList& l, Elem_t x);
void LinkList_WithHeadNodeDelX_2(LinkList& l, Elem_t x);

/************************二叉树************************/
// 遍历
void BTree_PreOrder(BTree T);
void BTree_InOrder(BTree T);
void BTree_PostOrder(BTree T);
void BTree_PreOrder(BTree T);
void BTree_InOrder(BTree T);
void BTree_PostOrder(BTree T);
void BTree_InOrderIterative(BTree T);
void BTree_PreOrderIterative(BTree T);
void BTree_LevelOrder(BTree T);
// 建立二叉树 从键盘输入数据
BTree BTree_CreateFromInput(void);
// 建立二叉树 从数组中获取数据
void BTree_CreateFromArray(BTree& T, Elem_t* arr);
// 求二叉树深度 递归
int BTree_GetDepth(BTree T);
// 二叉树深度 手动队列
int BTree_GetDepthIterative(BTree T);
// 节点深度 手动队列
int BTree_GetNodeLayer(BTree T, Elem_t e);
// 交换左右子树 递归
void BTree_Swap(BTree T);
// 交换左右子树 非递归（前序遍历）
void BTree_SwapIterative(BTree T);
// 删除子树 递归
void BTree_DeleteSubTree(BTree& T, Elem_t e);
// 删除子树 非递归
// 需要记录父节点
void BTree_DeleteSubTreeIterative(BTree& T, Elem_t e);

/************************查找************************/
// 顺序查找
int Search_SequentialSearch(Elem_t A[], int n, Elem_t key);
// 折半查找
int Search_BinarySearch(Elem_t A[], int n, Elem_t key);
// 折半查找 递归
int Search_BinarySearchRecursive(Elem_t A[], Elem_t key, int l, int h);
// 在有n个元素的递增的线性表中查找并插入一个元素
void Search_BinaryInsert(Elem_t A[], int& n, Elem_t key);
// 在有n个元素的递增的线性表中查找不小于key的最小元素
int Search_BinaryGEKey(Elem_t A[], int n, Elem_t key);

/************************排序************************/
// 插入排序
Elem_t* Sort_InsertionSort(Elem_t a[], int n);
// 折半插入排序
Elem_t* Sort_BinaryInsertionSort(Elem_t a[], int n);
// 冒泡排序
Elem_t* Sort_BubbleSort(Elem_t a[], int n);
// 选择排序
Elem_t* Sort_SelectionSort(Elem_t a[], int n);
// 快速排序
Elem_t* Sort_QuickSort(Elem_t a[], int n);
// 堆排序
Elem_t* Sort_HeapSort(Elem_t a[], int n);
// 希尔排序
Elem_t* Sort_ShellSort(Elem_t a[], int n);
// 归并排序 递归
Elem_t* Sort_MergeSort(Elem_t a[], int n);


/************************图************************/
// 深度优先遍历
void Graph_DFS(MGraph G);
// 广度优先遍历
void Graph_BFS(MGraph G);
// 判断图是否连通
bool Graph_IsConnected(MGraph G);


//#define LINEAR_LIST
//#define	TREE
//#define SEARCH
//#define GRAPH
#define SORT

// auto xxSort = [](Elem_t* a, int n)->Elem_t* { ... };
