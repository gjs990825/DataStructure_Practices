#include "Practices.h"

/************************线性表************************/

#ifndef LINEAR_LIST

// 逆转顺序表中的所有元素
Elem_t* SeqList_Reverse(Elem_t a[], int n) {
	for (int i = 0; i < n / 2; i++)
		swap(a[i], a[n - i - 1]);
	return a;
}

Elem_t* SeqList_ReverseRange(int a[], int l, int h) {
	for (int i = l, j = h; i < j; i++, j--)
		swap(a[i], a[j]);
	return a;
}


// 删除线性链表中数据为item的节点
LinkList& LinkList_PurgeItem(LinkList& l, Elem_t item) {
	if (l == NULL) return l;
	LinkNode* cur = l->next, * pre = l;
	while (cur != NULL) {
		if (cur->data == item) {
			pre->next = cur->next;
			free(cur);
			cur = pre->next;
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	if (l->data == item) {
		pre = l;
		l = l->next;
		free(pre);
	}
	return l;
}

// 逆转线性链表
LinkList& LinkList_Reverse(LinkList& l) {
	LinkNode* pre = NULL, * cur = l, * tmp;
	while (cur != NULL) {
		tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	l = pre;
	return l;
}

// 拷贝线性链表
LinkList LinkList_Copy(LinkList l) {
	if (l == NULL) return NULL;
	LinkNode* copy = (LinkNode*)malloc(sizeof(LinkNode));
	copy->data = l->data;
	copy->next = LinkList_Copy(l->next);
	return copy;
}

// **剩余表的连接
// 合并两个非空的有序线性链表
LinkList LinkList_Merge(LinkList la, LinkList lb) {
	LinkList lc, plc;
	if (la->data < lb->data) {
		lc = la;
		la = la->next;
	}
	else {
		lc = lb;
		lb = lb->next;
	}
	plc = lc;

	while (la && lb) {
		if (la->data <= lb->data) {
			plc->next = la;
			la = la->next;
		}
		else {
			plc->next = lb;
			lb = lb->next;
		}
		plc = plc->next;
	}
	plc->next = la ? la : lb;
	return lc;
}

// 递归，删除不带头节点的单链表L中所有值为x的节点
void LinkList_NoHeadNodeDelX(LinkList& l, Elem_t x) {
	if (l == NULL) return;
	if (l->data == x) {
		LinkNode* p = l;
		l = l->next;
		free(p);
		LinkList_NoHeadNodeDelX(l, x);
	}
	else {
		LinkList_NoHeadNodeDelX(l->next, x);
	}
}

// 非递归
void LinkList_NoHeadNodeDelXIterative(LinkList& l, Elem_t x) {
	if (l == NULL) return;
	LinkNode* cur = l->next, * pre = l;
	while (cur != NULL) {
		if (cur->data == x) {
			pre->next = cur->next;
			free(cur);
			cur = pre->next;
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	if (l->data == x) {
		pre = l;
		l = l->next;
		free(pre);
	}
}

// **记录偏移量
// 删除顺序表中在[s,t]上的值
bool SeqList_DelStoT(SeqList& l, Elem_t s, Elem_t t) {
	if (l.length == 0 || s > t)
		return false;
	int offset = 0;
	for (int i = 0; i < l.length; i++) {
		if (l.data[i] >= s && l.data[i] <= t)
			offset++;
		else
			l.data[i - offset] = l.data[i];
	}
	l.length -= offset;
	return true;
}

// 合并两个有序顺序表
bool SeqList_Merge(SeqList a, SeqList b, SeqList& c) {
	if (a.length + b.length > SeqList_MaxLength)
		return false;
	int ia = 0, ib = 0, ic = 0;
	while (ia < a.length && ib < b.length)
		c.data[ic++] = a.data[ia] < b.data[ib] ? a.data[ia++] : b.data[ib++];
	while (ia < a.length)
		c.data[ic++] = a.data[ia++];
	while (ib < b.length)
		c.data[ic++] = b.data[ib++];
	c.length = a.length + b.length;
	return true;
}

// 删除有序顺序表中重复元素
bool SeqList_DeleteDuplicate(SeqList& l) {
	if (l.length == 0)
		return false;
	int index = 0;
	for (int i = 1; i < l.length; i++)
		if (l.data[i] != l.data[index])
			l.data[++index] = l.data[i];
	l.length = index + 1;
	return true;
}

// 逆序输出带头节点的单链表
void _print_node(LinkNode* node) { cout << node->data << " -> "; }
void LinkList_WithHeadReverseOutput(LinkList l) {
	if (l == NULL) return;
	if (l->next != NULL)
		LinkList_WithHeadReverseOutput(l->next);
	_print_node(l);
}

// 删除带头节点的单链表L中所有值为x的节点
// 解法1
void LinkList_WithHeadNodeDelX(LinkList& l, Elem_t x) {
	LinkNode* cur = l->next, * pre = l;
	while (cur != NULL) {
		if (cur->data == x) {
			pre->next = cur->next;
			free(cur);
			cur = pre->next;
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
}

// 解法2
void LinkList_WithHeadNodeDelX_2(LinkList& l, Elem_t x) {
	LinkNode* cur = l->next, * p = l, * tmp;
	while (cur != NULL) {
		if (cur->data == x) {
			tmp = cur;
			cur = cur->next;
			free(tmp);
		}
		else {
			p->next = cur;
			p = cur;
			cur = cur->next;
		}
	}
	p->next = NULL;
}

#endif // !LINEAR_LIST

/************************二叉树************************/
#ifndef TREE

// 先序遍历
void BTree_PreOrder(BTree T) {
	if (T != NULL) {
		BTree_VisitNode(T);
		BTree_PreOrder(T->lchild);
		BTree_PreOrder(T->rchild);
	}
}

// 中序遍历
void BTree_InOrder(BTree T) {
	if (T != NULL) {
		BTree_InOrder(T->lchild);
		BTree_VisitNode(T);
		BTree_InOrder(T->rchild);
	}
}

// 后序遍历
void BTree_PostOrder(BTree T) {
	if (T != NULL) {
		BTree_PostOrder(T->lchild);
		BTree_PostOrder(T->rchild);
		BTree_VisitNode(T);
	}
}

#define MAX_STACK 50
// 先序遍历 非递归
void BTree_PreOrderIterative(BTree T) {
	BTreeNode* s[MAX_STACK], * p = T;
	int top = -1;
	while (p != NULL || top != -1) {
		while (p != NULL) {
			BTree_VisitNode(p);
			s[++top] = p;
			p = p->lchild;
		}
		p = s[top--];
		p = p->rchild;
	}
}

// 中续遍历 非递归
void BTree_InOrderIterative(BTree T) {
	BTreeNode* s[MAX_STACK], * p = T;
	int top = -1;
	while (p != NULL || top != -1) {
		while (p != NULL) {
			s[++top] = p;
			p = p->lchild;
		}
		p = s[top--];
		BTree_VisitNode(p);
		p = p->rchild;
	}
}

#define MAX_QUEUE 50
// 层次遍历 手动队列
void BTree_LevelOrder(BTree T) {
	BTreeNode* q[MAX_QUEUE], * p;
	int front = -1, rear = -1;
	if (T != NULL) {
		q[++rear] = T;
		while (front < rear) {
			p = q[++front];
			BTree_VisitNode(p);
			if (p->lchild != NULL)
				q[++rear] = p->lchild;
			if (p->rchild != NULL)
				q[++rear] = p->rchild;
		}
	}
}

// 建立二叉树 从键盘输入数据
BTree BTree_CreateFromInput(void) {
	char ch;
	scanf("%c", &ch);
	if (ch == ' ') {
		return NULL;
	}
	else {
		BTree T = (BTreeNode*)malloc(sizeof(BTreeNode));
		T->data = ch - '0';
		T->lchild = BTree_CreateFromInput();
		T->rchild = BTree_CreateFromInput();
		return T;
	}
}

// 建立二叉树 从数组中获取数据
void _CreateFromArray(BTree& T, Elem_t*& arr) {
	Elem_t e = *arr++;
	if (e == -1) {
		T = NULL;
	}
	else {
		T = (BTreeNode*)malloc(sizeof(BTreeNode));
		T->data = e;
		_CreateFromArray(T->lchild, arr);
		_CreateFromArray(T->rchild, arr);
	}
}

void BTree_CreateFromArray(BTree& T, Elem_t* arr) {
	Elem_t* p = arr;
	_CreateFromArray(T, p);
}

// 求二叉树最小深度 递归 (??
int BTree_GetMinDepth(BTree T) {
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	int ld = INT_MAX;
	int rd = INT_MAX;
	if (T->lchild)
		ld = BTree_GetMinDepth(T->lchild);
	if (T->rchild)
		rd = BTree_GetMinDepth(T->rchild);
	return min(ld, rd) + 1;
}

// 求二叉树深度 递归
int BTree_GetDepth(BTree T) {
	if (T == NULL)
		return 0;
	int ld = BTree_GetDepth(T->lchild);
	int rd = BTree_GetDepth(T->rchild);
	return ((ld > rd) ? ld : rd) + 1;
}

// 二叉树深度 手动队列
int BTree_GetDepthIterative(BTree T) {
	if (T == NULL) return 0;
	BTreeNode* q[MAX_QUEUE], * p;
	int front = -1, rear = -1, depth = 0;
	q[++rear] = T;
	while (front < rear) {
		depth++;
		for (int i = 0, size = rear - front; i < size; i++) {
			p = q[++front];
			if (p->lchild) q[++rear] = p->lchild;
			if (p->rchild) q[++rear] = p->rchild;
		}
	}
	return depth;
}

// 节点深度 手动队列
int BTree_GetNodeLayer(BTree T, Elem_t e) {
	BTreeNode* q[MAX_QUEUE], * p;
	int front = -1, rear = -1, depth = 0;
	q[++rear] = T;
	while (front < rear) {
		depth++;
		for (int i = 0, size = rear - front; i < size; i++) {
			p = q[++front];
			if (p->data == e) return depth;
			if (p->lchild) q[++rear] = p->lchild;
			if (p->rchild) q[++rear] = p->rchild;
		}
	}
	return -1;
}

// 交换左右子树 递归
void BTree_Swap(BTree T) {
	if (T != NULL) {
		BTreeNode* tmp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = tmp;
		BTree_Swap(T->lchild);
		BTree_Swap(T->rchild);
	}
}

// 交换左右子树 非递归（前序遍历）
void BTree_SwapIterative(BTree T) {
	BTreeNode* s[MAX_STACK], * p = T, * tmp;
	int top = -1;
	while (p != NULL || top != -1) {
		while (p != NULL) {
			s[++top] = p;
			p = p->lchild;
		}
		p = s[top--];
		tmp = p->lchild;
		p->lchild = p->rchild;
		p->rchild = tmp;
		p = p->lchild;
	}
}

// 删除子树 递归
void BTree_DeleteSubTree(BTree& T, Elem_t e) {
	if (T == NULL) return;
	if (T->data == e) {
		BTree_Destroy(T);
	}
	else {
		BTree_DeleteSubTree(T->lchild, e);
		BTree_DeleteSubTree(T->rchild, e);
	}
}

// 删除子树 非递归
// 需要记录父节点
void BTree_DeleteSubTreeIterative(BTree& T, Elem_t e) {
	BTreeNode* s[MAX_STACK], * p = T, * q = NULL;
	int top = -1;
	if (T == NULL)
		return;
	if (T->data == e) {
		BTree_Destroy(T);
		T = NULL;
		return;
	}
	while (p != NULL || top != -1) {
		while (p != NULL) {
			if (p->data == e) {
				if (q->lchild == p)
					q->lchild = NULL;
				else
					q->rchild = NULL;
				BTree_Destroy(p);
				return;
			}
			q = p;
			s[++top] = p;
			p = p->lchild;
		}
		q = s[top--];
		p = q->rchild;
	}
}

#endif // !TREE

/************************查找************************/
#ifndef SEARCH

// 顺序查找
int Search_SequentialSearch(Elem_t A[], int n, Elem_t key) {
	for (int i = 0; i < n; i++)
		if (A[i] == key)
			return i;
	return -1;
}

// 顺序查找 递归
int Search_SequentialSearchRecursive(Elem_t A[], int n, Elem_t key, int i) {
	if (i >= n) return -1;
	if (A[i] == key) return i;
	return Search_SequentialSearchRecursive(A, n, key, i + 1);
}

// 折半查找
int Search_BinarySearch(Elem_t A[], int n, Elem_t key) {
	int l = 0, h = n - 1, m;
	while (l <= h) {
		m = (l + h) / 2;
		if (A[m] == key) return m;
		if (A[m] > key) h = m - 1;
		else l = m + 1;
	}
	return -1;
}

// 折半查找 递归
int Search_BinarySearchRecursive(Elem_t A[], Elem_t key, int l, int h) {
	if (l > h) return -1;
	int m = (l + h) / 2;
	if (A[m] == key) return m;
	if (A[m] > key) h = m - 1;
	else l = m + 1;
	return Search_BinarySearchRecursive(A, key, l, h);
}

// 在有n个元素的递增的线性表中查找并插入一个元素
void Search_BinaryInsert(Elem_t A[], int& n, Elem_t key) {
	int l = 0, h = n - 1, m;
	while (l <= h) {
		m = (l + h) / 2;
		if (A[m] > key) h = m - 1;
		else l = m + 1;
	}
	for (int i = n; i > l; i--)
		A[i] = A[i - 1];
	A[l] = key;
	n++;
}

// 在有n个元素的递增的线性表中查找不小于key的最小元素
int Search_BinaryGEKey(Elem_t A[], int n, Elem_t key) {
	int l = 0, h = n - 1, m;
	while (l <= h) {
		m = (l + h) / 2;
		if (A[m] == key) return m;
		if (A[m] > key) h = m - 1;
		else l = m + 1;
	}
	if (l <= n - 1) return l;
	else return -1;
}

#endif // !SEARCH


/************************排序************************/
#ifndef SORT

// 插入排序
Elem_t* Sort_InsertionSort(Elem_t a[], int n) {
	int i, j;
	Elem_t t;
	for (i = 1; i < n; i++) {
		t = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > t) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}
	return a;
}

// 折半插入排序
Elem_t* Sort_BinaryInsertionSort(Elem_t a[], int n) {
	int i, j, l, h, m;
	Elem_t t;
	for (i = 1; i < n; i++) {
		t = a[i];
		l = 0; h = i - 1;
		while (l <= h) {
			m = (l + h) / 2;
			if (a[m] > t) h = m - 1;
			else l = m + 1;
		}
		for (j = i - 1; j >= l; j--)
			a[j + 1] = a[j];
		a[l] = t;
	}
	return a;
}

// 冒泡排序
Elem_t* Sort_BubbleSort(Elem_t a[], int n) {
	int i, j; bool flag;
	for (i = 0; i < n - 1; i++) {
		flag = false;
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if (flag == false)
			return a;
	}
	return a;
}

// 选择排序
Elem_t* Sort_SelectionSort(Elem_t a[], int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[min], a[i]);
	}
	return a;
}

// 快速排序
int QSort_Partition(Elem_t a[], int l, int h) {
	Elem_t pivot = a[l]; // a[l] instead of a[0]!!
	while (l < h) {
		while (l < h && a[h] >= pivot) h--;
		a[l] = a[h];
		while (l < h && a[l] <= pivot) l++;
		a[h] = a[l];
	}
	a[l] = pivot;
	return l;
}

void QSort(Elem_t a[], int l, int h) {
	if (l < h) { // !!
		int pivot = QSort_Partition(a, l, h);
		QSort(a, l, pivot - 1);
		QSort(a, pivot + 1, h);
	}
}

Elem_t* Sort_QuickSort(Elem_t a[], int n) {
	QSort(a, 0, n - 1);
	return a;
}

// 堆排序
void heapify(Elem_t a[], int i, int n) {
	int p = i, l = 2 * i + 1, r = l + 1;
	if (l < n && a[l] > a[p]) p = l;
	if (r < n && a[r] > a[p]) p = r;
	if (p != i) {
		swap(a[i], a[p]);
		heapify(a, p, n);
	}
}

Elem_t* Sort_HeapSort(Elem_t a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, i, n);
	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, 0, i);
	}
	return a;
}

// 希尔排序
Elem_t* Sort_ShellSort(Elem_t a[], int n) {
	int i, j, gap; Elem_t t;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			t = a[i];
			j = i - gap;
			while (j >= 0 && a[j] > t) {
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = t;
		}
	}
	return a;
}

// 归并排序 递归
void merge_sort(Elem_t a[], Elem_t b[], int start, int end) {
	if (start >= end) return;
	int mid = (start + end) / 2;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	merge_sort(a, b, start1, end1);
	merge_sort(a, b, start2, end2);
	int k = start;
	while (start1 <= end1 && start2 <= end2)
		b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
	while (start1 <= end1)
		b[k++] = a[start1++];
	while (start2 <= end2)
		b[k++] = a[start2++];
	for (k = start; k <= end; k++)
		a[k] = b[k];
}

Elem_t* Sort_MergeSort(Elem_t a[], int n) {
	Elem_t* b = (Elem_t*)malloc(sizeof(Elem_t) * n);
	merge_sort(a, b, 0, n - 1);
	free(b);
	return a;
}

#endif // !SORT

/************************图************************/
#ifndef GRAPH

bool visited[MAX_VERTEX_NUM];

void Graph_VisitVertex(MGraph G, Vertex_t v) {
	cout << G.verties[v] << " - ";
}

void DFS(MGraph G, int i) {
	Graph_VisitVertex(G, i);
	visited[i] = true;
	for (int j = 0; j < G.vexNum; j++)
		if (G.edges[i][j] == 1 && !visited[j])
			DFS(G, j);
}

// 深度优先遍历
void Graph_DFS(MGraph G) {
	for (int i = 0; i < G.vexNum; i++)
		visited[i] = false;
	for (int i = 0; i < G.vexNum; i++)
		if (!visited[i])
			DFS(G, i);
}

// 广度优先遍历
#include <queue>
void Graph_BFS(MGraph G) {
	for (int i = 0; i < G.vexNum; i++)
		visited[i] = false;
	queue<int> q;
	for (int i = 0; i < G.vexNum; i++) {
		if (!visited[i]) {
			Graph_VisitVertex(G, i);
			visited[i] = true;
			q.push(i);
			while (!q.empty()) {
				int j = q.front(); q.pop();
				for (int k = 0; k < G.edgeNum; k++) {
					if (G.edges[j][k] == 1 && !visited[k]) {
						Graph_VisitVertex(G, k);
						visited[k] = true;
						q.push(k);
					}
				}
			}
		}
	}
}

void _DFS(MGraph G, int i) {
	visited[i] = true;
	for (int j = 0; j < G.vexNum; j++)
		if (G.edges[i][j] == 1 && !visited[j])
			_DFS(G, j);
}

bool Graph_IsConnected(MGraph G) {
	for (int i = 0; i < G.vexNum; i++)
		visited[i] = false;
	_DFS(G, 0);
	for (int i = 0; i < G.vexNum; i++)
		if (visited[i] == false)
			return false;
	return true;
}

#endif // !GRAPH

/************************真题************************/
// 分割奇偶数组
void SplitEvenAndOdd(int A[], int n) {
	int i = 0, j = n - 1;
	while (i < j) {
		while (i < j && A[j] % 2 != 0) j--;
		swap(A[i], A[j]);
		while (i < j && A[i] % 2 == 0) i++;
		swap(A[i], A[j]);
	}
}

// 将链表中最小元素移动到头部
void LinkList_MoveMinToFront(LinkList& L) {
	LinkNode* cur = L->next, * pre = L, * minpre = L;
	while (cur != NULL) {
		if (cur->data < minpre->next->data)
			minpre = pre;
		pre = cur;
		cur = cur->next;
	}
	LinkNode* tmp = minpre->next;
	minpre->next = tmp->next;
	tmp->next = L->next;
	L->next = tmp;
}

// 2020 408
// 最小距离
int get_D(int a, int b, int c) { return abs(a - b) + abs(b - c) + abs(c - a); }

int Min_D(int S1[], int n1, int S2[], int n2, int S3[], int n3) {
	int min = get_D(S1[0], S2[0], S3[0]), D;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			for (int k = 0; k < n3; k++) {
				D = get_D(S1[i], S2[j], S3[k]);
				min = (D < min) ? D : min;
			}
	return min;
}

// 408
// 找出没有出现的最小正整数
int FindMinPositiveIntegerNotIn(int a[], int n) {
	bool* b = new bool[n];
	for (int i = 0; i < n; i++)
		b[i] = false;
	for (int i = 0; i < n; i++)
		if (a[i] <= n && a[i] >= 1)
			b[a[i] - 1] = true;
	for (int i = 0; i < n; i++)
		if (!b[i])
			return i + 1;
	delete[] b;
	return n + 1;
}

// 移除相同绝对值的元素
void Remove_DuplicatedAbsoluteValue(LinkList L, int N) {
	bool* flags = new bool[N + 1];
	for (int i = 0; i < N + 1; i++) flags[i] = false;
	LinkNode* cur = L->next, * pre = L;
	while (cur != NULL) {
		if (flags[abs(cur->data)]) {
			pre->next = cur->next;
			free(cur);
			cur = pre->next;
		}
		else {
			flags[abs(cur->data)] = true;
			pre = cur;
			cur = cur->next;
		}
	}
	delete[] flags;
}

int main() {
	cout << "/************************线性表************************/" << endl;
	DumpArray(In(), 10);
	DumpArray(SeqList_Reverse(In(), 10), 10);

	LinkList l = LinkList_Generate(10);
	DumpLinkList(l);
	DumpLinkList(LinkList_PurgeItem(l, 0));
	DumpLinkList(LinkList_PurgeItem(l, 2));
	DumpLinkList(LinkList_Reverse(l));

	LinkList l2 = LinkList_Generate(4);
	LinkList l2_copy = LinkList_Copy(l2);
	DumpLinkList(l2_copy);
	cout << (l2 == l2_copy) << endl;

	LinkList l3 = LinkList_Generate(3);
	LinkList l4 = LinkList_Generate(3);
	LinkList l5 = LinkList_Merge(l3, l4);
	DumpLinkList(l5);

	LinkList_NoHeadNodeDelX(l5, 0);
	LinkList_NoHeadNodeDelXIterative(l5, 1);
	DumpLinkList(l5);

	SeqList sl = SeqList_Generate(10);
	DumpSeqList(sl);
	SeqList_DelStoT(sl, 4, 6);
	DumpSeqList(sl);

	SeqList s2 = SeqList_Generate(5);
	SeqList s3 = SeqList_Generate(5);
	SeqList s4 = SeqList_Generate(0);
	SeqList_Merge(s2, s3, s4);
	DumpSeqList(s4);

	SeqList_DeleteDuplicate(s4);
	DumpSeqList(s4);

	LinkList l8 = LinkList_Generate(3);
	LinkList l9 = LinkList_Generate(3);
	LinkList l10 = LinkList_Merge(l8, l9);
	l10->data = -1;
	DumpLinkList(l10);
	NL(LinkList_WithHeadReverseOutput(l10));
	LinkList_WithHeadNodeDelX(l10, 0);
	LinkList_WithHeadNodeDelX_2(l10, 1);
	DumpLinkList(l10);

	cout << "/************************二叉树************************/" << endl;
	//const char* ts = "124  5  36  7  ";
	const char* ts = "124  5  3 7  ";

	BTree t1 = BTreeInit();
	BTree_Create(t1, ts);
	BTree_Dump(t1);

	NL(BTree_PreOrder(t1));
	NL(BTree_PreOrderTraverse(t1));
	NL(BTree_InOrder(t1));
	NL(BTree_InOrderTraverse(t1));
	NL(BTree_PostOrder(t1));
	NL(BTree_PostOrderTraverse(t1));
	NL();
	NL(BTree_PreOrderIterative(t1));
	NL(BTree_PreOrderTraverseIterative(t1));
	NL();
	NL(BTree_InOrderIterative(t1));
	NL(BTree_InOrderTraverseIterative(t1));
	NL();
	NL(BTree_LevelOrder(t1));
	NL(BTree_LevelOrderTraverse(t1));

	//BTree_Dump(BTree_CreateFromInput());
	int a[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 7, -1, 8, -1, -1 };
	BTree t2;
	BTree_CreateFromArray(t2, a);
	BTree_Dump(t2);

	cout << BTree_GetDepth(t2) << endl;
	cout << BTree_GetDepthIterative(t2) << endl;
	//cout << BTree_GetMinDepth(t2) << endl;
	cout << BTree_GetNodeLayer(t2, 3) << endl;

	BTree_Swap(t2);
	BTree_Dump(t2);
	BTree_SwapIterative(t2);
	BTree_Dump(t2);

	BTree_DeleteSubTree(t2, 7);
	BTree_Dump(t2);
	BTree_DeleteSubTreeIterative(t2, 2);
	BTree_Dump(t2);

	cout << "/************************查找************************/" << endl;
	cout << Search_SequentialSearch(SeqList_Generate(10).data, 10, 4) << endl;
	cout << Search_SequentialSearchRecursive(SeqList_Generate(10).data, 10, 4, 0) << endl;
	cout << Search_BinarySearch(SeqList_Generate(10).data, 10, 8) << endl;
	cout << Search_BinarySearchRecursive(SeqList_Generate(10).data, 9, 0, 10 - 1) << endl;

	SeqList sl1 = SeqList_Generate(10);
	DumpSeqList(sl1);
	Search_BinaryInsert(sl1.data, sl1.length, 6);
	DumpSeqList(sl1);
	cout << Search_BinaryGEKey(SeqList_Generate(10).data, 10, -1) << endl;

	cout << "/************************排序************************/" << endl;

	CheckSort(Sort_InsertionSort);
	CheckSort(Sort_BinaryInsertionSort);
	CheckSort(Sort_BubbleSort);
	CheckSort(Sort_SelectionSort);
	CheckSort(Sort_QuickSort);
	CheckSort(Sort_HeapSort);
	CheckSort(Sort_ShellSort);
	CheckSort(Sort_MergeSort);

	cout << "/************************图************************/" << endl;
	NL(Graph_DFS(Graph_GenerateConnected()));
	NL(Graph_BFS(Graph_GenerateConnected()));
	NL(Graph_DFS(Graph_GenerateDisconnected()));
	NL(Graph_BFS(Graph_GenerateDisconnected()));

	cout << Graph_IsConnected(Graph_GenerateConnected()) << ", "
		<< Graph_IsConnected(Graph_GenerateDisconnected()) << endl;

	cout << "/************************真题练习************************/" << endl;
	int S1[] = { -1, 0, 9 },
		S2[] = { -25, -10, 10, 11 },
		S3[] = { 2, 9, 17, 30, 41 };
	cout << Min_D(S1, 3, S2, 4, S3, 5) << endl;


	int A[] = { 5,5,6,7,8,8,9,1,2,2,3,4,5 };
	int A_len = sizeof(A) / sizeof(A[0]);
	DumpArray(A, A_len);
	SplitEvenAndOdd(A, A_len);
	DumpArray(A, A_len);

	LinkList Ltest = LinkList_GenerateReverse(10);
	DumpLinkList(Ltest);
	LinkList_MoveMinToFront(Ltest);
	DumpLinkList(Ltest);

	int integer_1[] = { -5, 3, 2, 3 };
	int integer_2[] = { 1, 2, 3 };
	cout << FindMinPositiveIntegerNotIn(integer_1, 4) << endl;
	cout << FindMinPositiveIntegerNotIn(integer_2, 3) << endl;

	int testArray[] = { 0, 21, -15, -15, -7, 15 };
	LinkList t408_15l = LinkList_Generate(testArray, sizeof(testArray) / sizeof(testArray[0]));
	DumpLinkList(t408_15l);
	Remove_DuplicatedAbsoluteValue(t408_15l, 30);
	DumpLinkList(t408_15l);

	auto RollToTheRight = [](int a[], int n, int k) {
		SeqList_ReverseRange(a, 0, n - k - 1);
		SeqList_ReverseRange(a, n - k, n - 1);
		SeqList_ReverseRange(a, 0, n - 1);
	};
	auto RollToTheLeft = [](int a[], int n, int k) {
		SeqList_ReverseRange(a, 0, k - 1);
		SeqList_ReverseRange(a, k, n - 1);
		SeqList_ReverseRange(a, 0, n - 1);
	};
	int testArray2[] = { 1, 2, 3, 4, 5 };
	RollToTheRight(testArray2, 5, 3);
	DumpArray(testArray2, 5);
	RollToTheLeft(testArray2, 5, 3);
	DumpArray(testArray2, 5);

	auto testLinkList = [](LinkList &L) -> LinkList& {
		LinkNode* pre = NULL, * cur = L, * tmp;
		while (cur != NULL) {
			tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		L = pre;
		return L;
	};

	LinkList testL = LinkList_Generate(11);
	DumpLinkList(testLinkList(testL));

}
