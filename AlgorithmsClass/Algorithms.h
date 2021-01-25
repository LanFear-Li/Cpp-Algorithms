//
// Created by LanFear on 2020/12/27.
//

#ifndef ALGORITHMSCLASS_ALGORITHMS_H
#define ALGORITHMSCLASS_ALGORITHMS_H

#include "iostream"

class Lango{
private:
    int* arr = NULL;
    int lenscale;
    int maxn = INT32_MIN;
public:
    Lango(int* _arr, int _lenscale);
    ~Lango();
    void show() const;
    void bubbleSort();
    void quickSort(const int &l, const int &r);
    void countingSort(int* brr);
};

class LanHeap{
private:
    int* arr = (int*)(malloc(200)); // malloc problem::Do size has limits?
    int length;
    int heapSize;
    void maxHeapify(const int &i);
public:
    LanHeap(int* start, int* end);
    ~LanHeap();
    void showHeap() const;
    void buildMaxHeap();
    void heapSort();
    void maxHeapInsert(const int &key);
    int heapMaximum() const;
    int heapExtractMax();
    void heapIncreaseKey(int i, const int &key);
};

class LanStack{
private:
    int* arr = (int*)(malloc(200));
    int top;
public:
    LanStack();
    ~LanStack();
    void showStack() const;
    bool empty() const;
    void push(const int &x);
    int pop();
};

class LanQueue{
private:
private:
    int* arr = (int*)malloc(200);
    int length = 12;
    int head;
    int tail;
public:
    LanQueue();
    LanQueue(const int &len);
    ~LanQueue();
    void showQueue() const;
    bool empty() const;
    int size() const;
    void enqueue(const int &x);
    int dequeue();
};

class Node{
public:
    int key;
    Node* next;
    Node* prior;
};

class LanLinkedList{
public:
    Node* head;
    Node* tail;
    int size;
    LanLinkedList();
    Node* listSearch(const int &k);
    void showLinkedList() const;
    void listInsertFront(const int &x);
    void listInsertAfter(const int &x);
    void listDeleteAfter(Node* x);
};

#endif //ALGORITHMSCLASS_ALGORITHMS_H
