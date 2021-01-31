//
// Created by LanFear on 2020/12/27.
//

#include "Algorithms.h"
#include<bits/stdc++.h>

// Class-Lango ***************************************************************************************
//Lango::Lango(int* _arr, int _lenscale) {
//    arr = _arr;
//    lenscale = _lenscale;
//}

// constructor can also be defined like this:
Lango::Lango(int* _arr, int _lenscale): arr(_arr), lenscale(_lenscale) {
    for (size_t i = 0; i < lenscale; ++i) {
        if (arr[i] > maxn) {
            maxn = arr[i];
        }
    }
    std::cout << "maxn is " << maxn << std::endl;
};

Lango::~Lango() {
    std::cout << "Bye!" << std::endl;
}

void Lango::show() const {
    std::cout << "this array's length: " << lenscale << std::endl;
    std::cout << "the element is: ";
    for (size_t i = 0; i <lenscale; ++i) {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

// Sort_bubbleSort ************************************************************************************
void Lango::bubbleSort() {
    for (size_t i = 0; i < lenscale - 1; ++i) {
        for(size_t j = 0; j < lenscale - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// Sort_bubbleSort ended*******************************************************************************


//  Sort_quickSort ************************************************************************************
// partition belongs to the original quickSort
int partition(int* arr, const int &l, const int &r) {
    int pivot = arr[r];
    int place = l - 1;
    for (size_t i = l; i < r; ++i) {
        if (arr[i] <= pivot) {
            place = place + 1;
            std::swap(arr[i], arr[place]);
        }
    }
    std::swap(arr[place + 1], arr[r]);
    return place + 1;
}

// randomPartition belongs to the original quickSort
// it changes pivot and ensures the equality of the partition
int randomPartition(int* arr, const int &l, const int &r) {
    int place = rand() % (r - l + 1) + l;
    std::swap(arr[r], arr[place]);
    return partition(arr, l, r);
}


int hoarePartition(int* arr, const int &l, const int &r) {
    int x = arr[l];
    int i = l - 1, j = r + 1;
    while (true) {
        do j--; while (arr[j] > x);
        do i++; while (arr[i] < x);
        if (i < j) std::swap(arr[i], arr[j]);
        else return j;
    }
}

// binary quickSort
//void Lango::quickSort(const int &l, const int &r) {
//    if(l < r)
//    {
//        int pivot = arr[l];
//        int low = l, high = r;
//        while(low < high)
//        {
//            while(arr[high] >= pivot && low < high)
//                high--;
//            arr[low] = arr[high];
//
//            while(arr[low] <= pivot && low < high)
//                low++;
//            arr[high] = arr[low];
//        }
//        arr[low] = pivot;
//
//        quickSort(l, low - 1);
//        quickSort(low + 1, r);
//    }
//}

// original quickSort
void Lango::quickSort(const int &l, const int &r) {
    if (l < r) {
        int mid = hoarePartition(arr, l, r);
        quickSort(l, mid - 1);
        quickSort(mid + 1, r);
    }
}

//  Sort_quickSort ended*******************************************************************************


//  Sort_countingSort *********************************************************************************
void Lango::countingSort(int* brr) {
    int crr[maxn + 1];
    for (size_t i = 0; i <= maxn; ++i) {
        crr[i] = 0;
    }
    for (size_t i = 0; i < lenscale; ++i) {
        crr[arr[i]]++;
    }
    for (size_t i = 1; i <= maxn; ++i) {
        crr[i] += crr[i - 1];
    }
    for (size_t i = lenscale - 1; i != -1; --i) {
        brr[crr[arr[i]] - 1] = arr[i];
        crr[arr[i]]--;
    }
}

//  Sort_countingSort ended****************************************************************************
// Class-Lango ended***********************************************************************************


// Class-LanHeap **************************************************************************************
// Sort_heapSort **************************************************************************************

#define parent(i)   (i / 2)
#define leftChild(i)     (2 * i)
#define rightChild(i)    (2 * i + 1)

LanHeap::LanHeap(int* start, int* end) {
    int* q = arr;
    q++;
    for (int* p = start; p != end; p++) {
        *(q++) = *p;
    }
    length = end - start;
}

LanHeap::~LanHeap() {
    std::cout << "Bye!" << std::endl;
}

void LanHeap::showHeap() const {
    std::cout << "the heap is: ";
    for (size_t i = 1; i <= length; ++i) {
        std::cout << std::setw(8) << arr[i];
    }
    std::cout << std::endl;
    std::cout << "length: " << length << " heapSize: " << heapSize << std::endl;
}

void LanHeap::maxHeapify(const int &i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest;
    if (l <= heapSize && arr[l] > arr[i]) {
        largest = l;
    } else largest = i;
    if (r <= heapSize && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        maxHeapify(largest);
    }
}

void LanHeap::buildMaxHeap() {
    heapSize = length;
    for (size_t i = length / 2; i >= 1; --i) {
        maxHeapify(i);
    }
}

void LanHeap::heapSort() {
    buildMaxHeap();
    for (size_t i = length; i >= 2; --i) {
        std::swap(arr[1] , arr[i]);
        heapSize--;
        maxHeapify(1);
    }
}

void LanHeap::maxHeapInsert(const int &key) {
    heapSize = heapSize + 1;
    length = length + 1;
    arr[heapSize] = INT32_MIN;
    heapIncreaseKey(heapSize, key);
}

int LanHeap::heapMaximum() const {
    return arr[1];
}

int LanHeap::heapExtractMax() {
    if (heapSize < 1) {
        std::cout << "ERROR: heap underflow!" << std::endl;
    }
    int maxn = arr[1];
    arr[1] = arr[heapSize];
    heapSize = heapSize - 1;
    length = length - 1;
    maxHeapify(1);
    return maxn;
}

void LanHeap::heapIncreaseKey(int i, const int &key) {
    arr[i] = key;
    while (i > 1 && arr[parent(i)] < arr[i]) {
        std::swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

//  Sort_heapSort ended********************************************************************************
// Class-LanHeap ended*********************************************************************************


// Class-LanStack *************************************************************************************
LanStack::LanStack(): top(0) {};

LanStack::~LanStack() {
    std::cout << "Bye!" << std::endl;
}

void LanStack::showStack() const {
    std::cout << "the stack is empty: " << (bool)empty() << std::endl;
    if (empty() == 1) {
        std::cout << "no element exists" << std::endl;
    } else {
        std::cout << "the stack is: ";
        for (size_t i = 0; i < top; ++i) {
            std::cout << std::setw(8) << arr[i];
        }
        std:: cout << std::endl;
    }
}

bool LanStack::empty() const {
    if (top == 0) {
        return true;
    } else {
        return false;
    }
}

void LanStack::push(const int &x) {
    top += 1;
    arr[top - 1] = x;
}

int LanStack::pop() {
    top -= 1;
    return arr[top];
}

// Class-LanStack ended********************************************************************************


// Class-LanQueue *************************************************************************************
LanQueue::LanQueue(): head(0), tail(0) {}

LanQueue::LanQueue(const int &_length): head(0), tail(0), length(_length) {}

LanQueue::~LanQueue() {
    std::cout << "Bye!" << std::endl;
}

bool LanQueue::empty() const {
    return head == tail;
}

int LanQueue::size() const {
    if (head <= tail) {
        return tail - head;
    } else {
        return length - (head - tail);
    }
    return 0;
}

void LanQueue::showQueue() const {
    if (!empty()) {
        std::cout << "this queue contains " << size() << " elements" << std::endl;
        std::cout << "the element is: ";
        if (head < tail) {
            for (size_t i = head; i <tail; ++i) {
                std::cout << std::setw(8) << arr[i];
            }
            std::cout << std::endl;
        } else {
            for (size_t i = head; i < length; ++i) {
                std::cout << std::setw(8) << arr[i];
            }
            for (size_t i = 0; i < tail; ++i) {
                std::cout << std::setw(8) << arr[i];
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Queue is empty!" << std::endl;
    }
}

void LanQueue::enqueue(const int &x) {
    if (head == (tail + 1) % 10) {
        std::cout << "Queue overflow!" << std::endl;
    } else {
        arr[tail] = x;
        tail += 1;
        tail %= 10;
    }
}

int LanQueue::dequeue() {
    if (head == tail) {
        std::cout << "Queue underflow!" << std::endl;
        return 0;
    } else {
        tail -= 1;
        if (tail < 0) {
            tail += 10;
        }
        return arr[tail];
    }
}

// Class-LanQueue ended********************************************************************************


// Class-LanLinkedList ********************************************************************************
LanLinkedList::LanLinkedList(): size(0), head(NULL), tail(NULL) {}

void LanLinkedList::showLinkedList() const {
    Node* x = head;
    std::cout << "linkedList size is: " << size << std::endl;
    std::cout << "linkedList elements: " << std::endl;
    while (x != NULL) {
        if (x->next != NULL) {
            std::cout << "data: " << x->key<< " next pointer's data: " << x->next->key << std::endl;
        } else {
            std::cout << "data: " << x->key<< " it is the last element. " << std::endl;
        }
        x = x->next;
    }
}

Node *LanLinkedList::listSearch(const int &k) {
    Node* x = head;
    while (x != NULL && x->key != k) {
        x = x->next;
    }
    return x;
}

void LanLinkedList::listInsertFront(const int &x) {
    Node* node = (Node *)(malloc(sizeof(node)));
    if (head == NULL) {
        node->prior = NULL;
        node->next = NULL;
        node->key = x;
        head = node;
        tail = node;
    } else {
        node->prior = NULL;
        node->next = head;
        node->key = x;
        head->prior = node;
        head = node;
    }
    size += 1;
}

void LanLinkedList::listInsertAfter(const int &x) {
    Node* node = (Node *)(malloc(sizeof(node)));
    if (tail == NULL) {
        node->prior = NULL;
        node->next = NULL;
        node->key = x;
        head = node;
        tail = node;
    } else {
        node->prior = tail;
        node->next = NULL;
        node->key = x;
        tail->next = node;
        tail = node;
    }
    size += 1;
}

void LanLinkedList::listDeleteAfter(Node* x) {
    Node* cur = head;
    int count = 0;

    if (x->next == NULL) {
        std::cout << "nothing to delete" << std::endl;
    } else {
        for (size_t i = 0; i < size; ++i) {
            count += 1;
            if (cur == x) {
                break;
            } else {
                cur = cur->next;
            }
        }
        tail = x;
        x->next = NULL;
        size = count;
    }
}

// Class-LanLinkedList ended***************************************************************************

