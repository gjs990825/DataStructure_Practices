#include "utils.h"
#include <iostream>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

void DumpArray(Elem_t* a, int length) {
	cout << "[ ";
	for (int i = 0; i < length; i++)
		cout << *a++ << ", ";
	cout << "](" << length << ")";
	cout << endl;
}

void CheckSortingResult(Elem_t* a, int length, Elem_t* (sort)(Elem_t* a, int n), const char* name) {	
	printf("[%s]\n", name);
	DumpArray(a, length);
	DumpArray(sort(a, length), length);
	bool res = VERIFY(a, length);
	printf("[%s]\n\n", (res ? "Passed!" : "FAILED!!!"));

	if (!res) {
		cout << "EXIT!" << endl;
		exit(-1);
	}
}

void CheckSortingResult(Elem_t* (sort)(Elem_t* a, int n), const char* name) {
	CheckSortingResult(In(), 10, sort, name);
}

void CheckSortingResult_F(Elem_t* a, int length, Elem_t* (sort)(Elem_t* a, int n)) {
	cout << "*************************************\n";
	DumpArray(a, length + 1);
	DumpArray(sort(a, length), length + 1);
	printf("************---%s---************\n\n", (VERIFY_F(a, length) ? "Passed!" : "FAILED!"));
}

bool VERIFY(Elem_t* a, Elem_t* b, int length) {
	for (int i = 0; i < length; i++)
		if (*a++ != *b++)
			return false;
	return true;
}

int cmp(void const* a, void const* b) {
	return (*(Elem_t*)a - *(Elem_t*)b);
}

bool VERIFY(Elem_t* a, int len) {
	for (int i = 0; i < len; i++)
		if (a[i] != i)
			return false;
	return true;
}

bool VERIFY_F(Elem_t* a, int len) {
	return VERIFY(++a, len);
}

bool VERIFY(Elem_t* a) { return VERIFY(a, 10); }
bool VERIFY_F(Elem_t* a) { return VERIFY_F(a, 10); }

Elem_t _In_F[] = { 0, 3, 7, 1, 9, 2, 4, 0, 6, 5, 8 };
Elem_t _In[] = { 3, 7, 1, 9, 2, 4, 0, 6, 5, 8 };

Elem_t* In() {
	return (Elem_t*)memcpy(new Elem_t[10], _In, sizeof(Elem_t) * 10);
}

Elem_t* In_F() {
	return (Elem_t*)memcpy(new Elem_t[11], _In_F, sizeof(Elem_t) * 11);
}

// µ¹ÐòÁ´±í
LinkList LinkList_GenerateReverse(int length) {
	LinkList l = NULL;
	for (int i = 0; i < length; i++) {
		LinkNode* n = new LinkNode;
		n->data = i;
		n->next = l;
		l = n;
	}
	return l;
}

LinkList LinkList_Generate(int length) {
	LinkList l = NULL;
	for (int i = length - 1; i >= 0; i--) {
		LinkNode* n = new LinkNode;
		n->data = i;
		n->next = l;
		l = n;
	}
	return l;
}

LinkList LinkList_Generate(int *a, int n) {
	LinkList l = NULL;
	for (int i = n - 1; i >= 0; i--) {
		LinkNode* n = new LinkNode;
		n->data = a[i];
		n->next = l;
		l = n;
	}
	return l;
}

LinkList LinkList_GenerateRand(void) {
	LinkList l = NULL;
	int a[] = { 5, 2, 4, 0, 1 ,3 };
	for (int i = sizeof(a) / sizeof(a[0]) - 1; i >= 0; i--) {
		LinkNode* n = new LinkNode;
		n->data = a[i];
		n->next = l;
		l = n;
	}
	return l;
}

LinkList LinkList_GenerateRandWithHead(void) {
	LinkList l = NULL;
	int a[] = { -1, 5, 2, 4, 0, 1 ,3 };
	for (int i = sizeof(a) / sizeof(a[0]) - 1; i >= 0; i--) {
		LinkNode* n = new LinkNode;
		n->data = a[i];
		n->next = l;
		l = n;
	}
	return l;
}

void DumpLinkList(LinkList l) {
	int count = 0;
	cout << "|";
	while (l != NULL) {
		cout << l->data << " -> ";
		l = l->next;
		count++;
	}
	cout << "|(" << count << ")" << endl;
}

LinkList LinkListCL_CreateWithHead(int n) {
	LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
	head->data = -1;
	head->next = head;
	for (int i = n; i > 0; i--) {
		LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
		newNode->data = i;
		newNode->next = head->next;
		head->next = newNode;
	}
	return head;
}

LinkList LinkListCL_CreateWithoutHead(int n) {
	LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
	head->data = -1;
	head->next = head;
	for (int i = n; i > 0; i--) {
		LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
		newNode->data = i;
		newNode->next = head->next;
		head->next = newNode;
	}
	LinkNode* tmp = head->next;
	head->data = tmp->data;
	head->next = tmp->next;
	free(tmp);
	return head;
}

void DumpLinkListCLWithHead(LinkList l) {
	LinkNode *cur = l->next;
	int count = 0;
	cout << "|";
	while (cur != l) {
		cout << cur->data << " -> ";
		cur = cur->next;
		count++;
	}
	cout << "|(" << count << ")" << endl;
}

void DumpLinkListCLWithoutHead(LinkList l) {
	if (l == NULL) {
		cout << "||(0)" << endl;
		return;
	}
	cout << "|" << l->data << " -> ";
	int count = 1;
	LinkNode *cur = l->next;
	while (cur != l) {
		cout << cur->data << " -> ";
		cur = cur->next;
		count++;
	}
	cout << "|(" << count << ")" << endl;
}

SeqList SeqList_Generate(int length)
{
	SeqList l;
	for (int i = 0; i < length; i++)
		l.data[i] = i;
	l.length = length;
	return l;
}

SeqList SeqList_GenerateRand(int length)
{
	SeqList l;
	srand(0);
	for (int i = 0; i < length; i++)
		l.data[i] = rand() % length;
	l.length = length;
	return l;
}

BTree BTreeInit(Elem_t data) {
	BTree T = new BTreeNode;
	T->data = data;
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}

BTree BTreeInit() {
	BTree T = new BTreeNode;
	T->data = -1;
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}

void BTree_Create(BTree& T) {
	char ch;
	ch = getchar();
	if (ch == ' ') {
		T = NULL;
	}
	else {
		T = BTreeInit(ch - '0');
		BTree_Create(T->lchild);
		BTree_Create(T->rchild);
	}
}

void BTree_Create(BTree& T, const char*& s) {
	char ch = *s++;
	if (ch == ' ') {
		T = NULL;
	}
	else {
		if (ch >= 'A')
			T = BTreeInit(ch - 'A' + 10);
		else
			T = BTreeInit(ch - '0');
		BTree_Create(T->lchild, s);
		BTree_Create(T->rchild, s);
	}
}

void BTree_VisitNode(BTreeNode* T) {
	cout << T->data << ", ";
}

void BTree_PreOrderTraverse(BTree T) {
	if (T) {
		BTree_VisitNode(T);
		BTree_PreOrderTraverse(T->lchild);
		BTree_PreOrderTraverse(T->rchild);
	}
}

void BTree_InOrderTraverse(BTree T) {
	if (T) {
		BTree_InOrderTraverse(T->lchild);
		BTree_VisitNode(T);
		BTree_InOrderTraverse(T->rchild);
	}
}

void BTree_PostOrderTraverse(BTree T) {
	if (T) {
		BTree_PostOrderTraverse(T->lchild);
		BTree_PostOrderTraverse(T->rchild);
		BTree_VisitNode(T);
	}
}

void BTree_InOrderTraverseIterative(BTree T) {
	stack<BTree> s;
	BTree p = T;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top(); s.pop();
			BTree_VisitNode(p);
			p = p->rchild;
		}
	}
}

void BTree_PreOrderTraverseIterative(BTree T) {
	stack<BTree> s;
	BTree p = T;
	while (p || !s.empty()) {
		if (p) {
			BTree_VisitNode(p);
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top(); s.pop();
			p = p->rchild;
		}
	}
}

void BTree_LevelOrderTraverse(BTree T) {
	queue<BTree> q;
	BTree p;
	q.push(T);
	while (!q.empty()) {
		p = q.front(); q.pop();
		BTree_VisitNode(p);
		if (p->lchild)
			q.push(p->lchild);
		if (p->rchild)
			q.push(p->rchild);
	}
}

void BTree_Destroy(BTree& T) {
	if (T != NULL) {
		if (T->lchild != NULL) {
			BTree_Destroy(T->lchild);
		}
		if (T->rchild != NULL) {
			BTree_Destroy(T->rchild);
		}
		free(T);
		T = NULL;
	}
}

//#define COMPACT

int _Btree_Dump(BTreeNode* tree, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int width = 5;

	if (!tree) return 0;

	sprintf(b, "(%03d)", tree->data);

	int lchild = _Btree_Dump(tree->lchild, 1, offset, depth + 1, s);
	int rchild = _Btree_Dump(tree->rchild, 0, offset + lchild + width, depth + 1, s);

#ifdef COMPACT
	for (int i = 0; i < width; i++)
		s[depth][offset + lchild + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + rchild; i++)
			s[depth - 1][offset + lchild + width / 2 + i] = '-';

		s[depth - 1][offset + lchild + width / 2] = '.';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < lchild + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';

		s[depth - 1][offset + lchild + width / 2] = '.';
	}
#else
	for (int i = 0; i < width; i++)
		s[2 * depth][offset + lchild + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + rchild; i++)
			s[2 * depth - 1][offset + lchild + width / 2 + i] = '-';

		s[2 * depth - 1][offset + lchild + width / 2] = '+';
		s[2 * depth - 1][offset + lchild + width + rchild + width / 2] = '+';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < lchild + width; i++)
			s[2 * depth - 1][offset - width / 2 + i] = '-';

		s[2 * depth - 1][offset + lchild + width / 2] = '+';
		s[2 * depth - 1][offset - width / 2 - 1] = '+';
	}
#endif

	return lchild + width + rchild;
}

void BTree_Dump(BTreeNode* tree)
{
	char s[20][255];
	for (int i = 0; i < 20; i++)
		sprintf(s[i], "%80s", " ");

	_Btree_Dump(tree, 0, 0, 0, s);

	int count = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 255; j++)
			if (!isblank(s[i][j])) {
				if (s[i][j] != '\0')
					count++;
				break;
			}

	for (int i = 0; i < count + 1; i++)
		printf("%s\n", s[i]);
}

#define _NUM 5
MGraph Graph_GenerateConnected() {
	MGraph G;
	int a[_NUM][_NUM] = {
		{0, 0, 0, 1, 1},
		{0, 0, 1, 0, 1},
		{0, 1, 0, 1, 0},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 0, 0},
	};
	for (int i = 0; i < _NUM; i++) {
		G.verties[i] = i + 1;
		for (int j = 0; j < _NUM; j++)
			G.edges[i][j] = a[i][j];
	}
	G.edgeNum = _NUM;
	G.vexNum = _NUM;
	return G;
}

MGraph Graph_GenerateDisconnected() {
	MGraph G;
	int a[_NUM][_NUM] = {
		{0, 0, 0, 1, 1},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{1, 0, 1, 0, 0},
		{1, 0, 0, 0, 0},
	};
	for (int i = 0; i < _NUM; i++) {
		G.verties[i] = i + 1;
		for (int j = 0; j < _NUM; j++)
			G.edges[i][j] = a[i][j];
	}
	G.edgeNum = _NUM;
	G.vexNum = _NUM;
	return G;
}

