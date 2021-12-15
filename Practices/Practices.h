#pragma once

#include <iostream>
#include "utils.h"

/************************���Ա�************************/
// ��ת˳����е�����Ԫ��
Elem_t* SeqList_Reverse(Elem_t a[], int n);
// ��ת˳����з�Χ��Ԫ��
Elem_t* SeqList_ReverseRange(int a[], int l, int h);
// ѭ������
Elem_t* SeqList_Ror(Elem_t* a, int n, int i);
// ѭ������
Elem_t* SeqList_Rol(Elem_t* a, int n, int i);
// ��ת��������
LinkList& LinkList_Reverse(LinkList& l);
// ������������
LinkList LinkList_Copy(LinkList l);
// **ʣ��������
// �ϲ������ǿյ�������������
LinkList LinkList_Merge(LinkList la, LinkList lb);
// �ݹ飬ɾ������ͷ�ڵ�ĵ�����L������ֵΪx�Ľڵ�
void LinkList_NoHeadNodeDelX(LinkList& l, Elem_t x);
// �ǵݹ�
void LinkList_NoHeadNodeDelXIterative(LinkList& l, Elem_t x);
// **��¼ƫ����
// ɾ��˳�������[s,t]�ϵ�ֵ
bool SeqList_DelStoT(SeqList& l, Elem_t s, Elem_t t);
// �ϲ���������˳���
bool SeqList_Merge(SeqList a, SeqList b, SeqList& c);
// ɾ������˳������ظ�Ԫ��
bool SeqList_DeleteDuplicate(SeqList& l);
// ���������ͷ�ڵ�ĵ�����
void LinkList_WithHeadReverseOutput(LinkList l);
// ɾ����ͷ�ڵ�ĵ�����L������ֵΪx�Ľڵ�
void LinkList_WithHeadNodeDelX(LinkList& l, Elem_t x);
void LinkList_WithHeadNodeDelX_2(LinkList& l, Elem_t x);

/************************������************************/
// ����
void BTree_PreOrder(BTree T);
void BTree_InOrder(BTree T);
void BTree_PostOrder(BTree T);
void BTree_PreOrder(BTree T);
void BTree_InOrder(BTree T);
void BTree_PostOrder(BTree T);
void BTree_InOrderIterative(BTree T);
void BTree_PreOrderIterative(BTree T);
void BTree_LevelOrder(BTree T);
// ���������� �Ӽ�����������
BTree BTree_CreateFromInput(void);
// ���������� �������л�ȡ����
void BTree_CreateFromArray(BTree& T, Elem_t* arr);
// ���������� �ݹ�
int BTree_GetDepth(BTree T);
// ��������� �ֶ�����
int BTree_GetDepthIterative(BTree T);
// �ڵ���� �ֶ�����
int BTree_GetNodeLayer(BTree T, Elem_t e);
// ������������ �ݹ�
void BTree_Swap(BTree T);
// ������������ �ǵݹ飨ǰ�������
void BTree_SwapIterative(BTree T);
// ɾ������ �ݹ�
void BTree_DeleteSubTree(BTree& T, Elem_t e);
// ɾ������ �ǵݹ�
// ��Ҫ��¼���ڵ�
void BTree_DeleteSubTreeIterative(BTree& T, Elem_t e);

/************************����************************/
// ˳�����
int Search_SequentialSearch(Elem_t A[], int n, Elem_t key);
// �۰����
int Search_BinarySearch(Elem_t A[], int n, Elem_t key);
// �۰���� �ݹ�
int Search_BinarySearchRecursive(Elem_t A[], Elem_t key, int l, int h);
// ����n��Ԫ�صĵ��������Ա��в��Ҳ�����һ��Ԫ��
void Search_BinaryInsert(Elem_t A[], int& n, Elem_t key);
// ����n��Ԫ�صĵ��������Ա��в��Ҳ�С��key����СԪ��
int Search_BinaryGEKey(Elem_t A[], int n, Elem_t key);

/************************����************************/
// ��������
Elem_t* Sort_InsertionSort(Elem_t a[], int n);
// �۰��������
Elem_t* Sort_BinaryInsertionSort(Elem_t a[], int n);
// ð������
Elem_t* Sort_BubbleSort(Elem_t a[], int n);
// ѡ������
Elem_t* Sort_SelectionSort(Elem_t a[], int n);
// ��������
Elem_t* Sort_QuickSort(Elem_t a[], int n);
// ������
Elem_t* Sort_HeapSort(Elem_t a[], int n);
// ϣ������
Elem_t* Sort_ShellSort(Elem_t a[], int n);
// �鲢���� �ݹ�
Elem_t* Sort_MergeSort(Elem_t a[], int n);


/************************ͼ************************/
// ������ȱ���
void Graph_DFS(MGraph G);
// ������ȱ���
void Graph_BFS(MGraph G);
// �ж�ͼ�Ƿ���ͨ
bool Graph_IsConnected(MGraph G);


//#define LINEAR_LIST
//#define	TREE
//#define SEARCH
//#define GRAPH
#define SORT

// auto xxSort = [](Elem_t* a, int n)->Elem_t* { ... };
