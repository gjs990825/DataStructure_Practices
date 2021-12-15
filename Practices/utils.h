#pragma once

#include <limits>
#include <iostream>

using namespace std;

typedef int Elem_t;

// Utilities
Elem_t* In();
Elem_t* In_F();

bool VERIFY(Elem_t* a, Elem_t* b, int length);

bool VERIFY(Elem_t* a, int len);
bool VERIFY_F(Elem_t* a, int len);

bool VERIFY(Elem_t* a);
bool VERIFY_F(Elem_t* a);

void DumpArray(Elem_t* a, int length);
void CheckSortingResult(Elem_t* a, int length, Elem_t* (sort)(Elem_t* a, int n), const char* name);
void CheckSortingResult(Elem_t* (sort)(Elem_t* a, int n), const char* name);
void CheckSortingResult_F(Elem_t* a, int length, Elem_t* (sort)(Elem_t* a, int n));

#define CheckSort(SORT) CheckSortingResult(SORT, #SORT)

Elem_t* In();
Elem_t* In_F();

typedef struct LinkNode {
	Elem_t data;
	struct LinkNode* next;
} LinkNode, * LinkList;

LinkList LinkList_Generate(int length);
LinkList LinkList_GenerateWithHead(int length);
LinkList LinkList_Generate(int* a, int n);
LinkList LinkList_GenerateReverse(int length);
LinkList LinkList_GenerateRand(void);
LinkList LinkList_GenerateRandWithHead(void);
void DumpLinkList(LinkList l);
LinkList LinkListCL_CreateWithHead(int n);
void DumpLinkListCLWithHead(LinkList l);
LinkList LinkListCL_CreateWithoutHead(int n);
void DumpLinkListCLWithoutHead(LinkList l);

typedef struct DLinkNode {
	Elem_t data;
	struct DLinkNode* prior, * next;
} DLinkNode, * DLinkList;

#define SeqList_MaxLength 50
typedef struct SeqList {
	Elem_t data[SeqList_MaxLength];
	int length;
} SeqList;

SeqList SeqList_Generate(int length);
SeqList SeqList_Generate(int* a, int n);
SeqList SeqList_GenerateRand(int length);

#define DumpSeqList(l) DumpArray(l.data, l.length)

typedef struct BTreeNode {
	Elem_t data;
	struct BTreeNode* lchild, * rchild;
} BTreeNode, * BTree;

BTree BTreeInit(Elem_t data);
BTree BTreeInit();
void BTree_Create(BTree& T);
void BTree_Create(BTree& T, const char*& s);
void BTree_CreateExpression(BTree& T, const char*& s);
void BTree_VisitNode(BTreeNode* T);
void BTree_PreOrderTraverse(BTree T);
void BTree_InOrderTraverse(BTree T);
void BTree_PostOrderTraverse(BTree T);
void BTree_InOrderTraverseIterative(BTree T);
void BTree_PreOrderTraverseIterative(BTree T);
void BTree_LevelOrderTraverse(BTree T);
void BTree_Destroy(BTree& T);

typedef struct ThreadNode {
	Elem_t data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
} ThreadNode, * ThreadTree;

// ADD A GODDAMN NEW LINE
#define NL(XXX) do { XXX; std::cout << std::endl; } while(0)

void DumpExpression(BTree T, int depth);
void DumpExpression(BTree T);

void BTree_Dump(BTreeNode* tree);

// 邻接表方式存储的图

#define MAX_VERTEX_NUM 20
typedef int Vertex_t;
typedef int Edge_t;
typedef struct {
	int vexNum, edgeNum;
	Vertex_t verties[MAX_VERTEX_NUM];
	Edge_t edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
} MGraph;

MGraph Graph_GenerateConnected();
MGraph Graph_GenerateDisconnected();

#define COMMENT(M) do { std::cout << "\n\n" << M << std::endl; } while (0)
#define EXE_OUT(X) do { std::cout << X << std::endl; } while (0)
#define DIVIDER(X)                           \
    do                                       \
    {                                        \
        std::cout                            \
            << "\n-------------------------" \
            << X                             \
            << "-------------------------\n" \
            << std::endl;                    \
    } while (0)