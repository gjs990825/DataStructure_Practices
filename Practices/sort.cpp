#include "Practices.h"

/************************≈≈–Ú************************/
#ifdef SORT

// ≤Â»Î≈≈–Ú
Elem_t* Sort_InsertionSort(Elem_t a[], int n) {
	int i, j, t;
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

// ’€∞Î≤Â»Î≈≈–Ú
Elem_t* Sort_BinaryInsertionSort(Elem_t a[], int n) {
	int i, j, t, l, h, m;
	for (i = 1; i < n; i++) {
		t = a[i];
		l = 0, h = i - 1;
		while (l <= h) {
			m = (l + h) / 2;
			if (a[m] < t) l = m + 1;
			else h = m - 1;
		}
		for (j = i - 1; j >= l; j--)
			a[j + 1] = a[j];
		a[l] = t;
	}
	return a;
}

// √∞≈›≈≈–Ú
Elem_t* Sort_BubbleSort(Elem_t a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	return a;
}

// —°‘Ò≈≈–Ú
Elem_t* Sort_SelectionSort(Elem_t a[], int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[i], a[min]);
	}
	return a;
}

int qpartition(int a[], int l, int h) {
	int pivot = a[l];
	while (l < h) {
		while (l < h && a[h] >= pivot) h--;
		a[l] = a[h];
		while (l < h && a[l] <= pivot) l++;
		a[h] = a[l];
	}
	a[l] = pivot;
	return l;
}

void qsort(int a[], int l, int h) {
	if (l >= h) return;
	int pivot = qpartition(a, l, h);
	qsort(a, l, pivot - 1);
	qsort(a, pivot + 1, h);
}

// øÏÀŸ≈≈–Ú
Elem_t* Sort_QuickSort(Elem_t a[], int n) {
	qsort(a, 0, n - 1);
	return a;
}

void heapify(int a[], int i, int n) {
	int l = i * 2 + 1, r = i * 2 + 2, p = i;
	if (l < n && a[l] > a[p]) p = l;
	if (r < n && a[r] > a[p]) p = r;
	if (p != i) {
		swap(a[i], a[p]);
		heapify(a, p, n);
	}
}

// ∂—≈≈–Ú
Elem_t* Sort_HeapSort(Elem_t a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, i, n);
	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, 0, i);
	}
	return a;
}

// œ£∂˚≈≈–Ú
Elem_t* Sort_ShellSort(Elem_t a[], int n) {
	int i, j, t, gap;
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

void merge_sort(int a[], int b[], int start, int end) {
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

// πÈ≤¢≈≈–Ú µ›πÈ
Elem_t* Sort_MergeSort(Elem_t a[], int n) {
	int* b = new int[n];
	merge_sort(a, b, 0, n - 1);
	delete[] b;
	return a;
}

#endif // SORT

/*
ƒ£∞Â£∫

// ≤Â»Î≈≈–Ú
Elem_t* Sort_InsertionSort(Elem_t a[], int n) {
	return a;
}

// ’€∞Î≤Â»Î≈≈–Ú
Elem_t* Sort_BinaryInsertionSort(Elem_t a[], int n) {
	return a;
}

// √∞≈›≈≈–Ú
Elem_t* Sort_BubbleSort(Elem_t a[], int n) {
	return a;
}

// —°‘Ò≈≈–Ú
Elem_t* Sort_SelectionSort(Elem_t a[], int n) {
	return a;
}

// øÏÀŸ≈≈–Ú
Elem_t* Sort_QuickSort(Elem_t a[], int n) {
	return a;
}

// ∂—≈≈–Ú
Elem_t* Sort_HeapSort(Elem_t a[], int n) {
	return a;
}

// œ£∂˚≈≈–Ú
Elem_t* Sort_ShellSort(Elem_t a[], int n) {
	return a;
}

// πÈ≤¢≈≈–Ú µ›πÈ
Elem_t* Sort_MergeSort(Elem_t a[], int n) {
	return a;
}
*/