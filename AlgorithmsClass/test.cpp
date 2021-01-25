//
// Created by LanFear on 2020/12/27.
//

#include "iostream"
#include "Algorithms.h"

int main() {
    int array1[10] = {4, 2, 3, 1, 6, 1, 10, 20, 3, 15};
    int array2[10] = {4, 2, 3, 1, 6, 1, 10, 20, 3, 15};
    int array3[10] = {4, 2, 3, 1, 6, 1, 10, 20, 3, 15};
    int brray[10];
    int n = sizeof array1 / sizeof array1[0];

    // quickSort test
    std::cout << "quickSort test" << std::endl;
    Lango testQuickSort(array1, n); // why Lango* test = new Lango(arr, n); work?
    testQuickSort.show();
    testQuickSort.quickSort(0, n - 1);
    testQuickSort.show();

    // countingSort test
    std::cout << "countingSort test" << std::endl;
    Lango testCountingSort(array2, n);
    testCountingSort.show();
    testCountingSort.countingSort(brray);
    std::cout << "array in sequn: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << brray[i] << "\t";
    }
    std::cout << std::endl;

    // priority queue test
    std::cout << "priority queue test" << std::endl;
    LanHeap test(array3 + 0, array3 + 10);
    test.showHeap();
    test.buildMaxHeap();
    test.showHeap();
    std::cout << "max number in heap is: " << test.heapMaximum() << std::endl;
    std::cout << "extract max number: " << test.heapExtractMax() << std::endl;
    test.showHeap();
    test.heapIncreaseKey(5, 100); // why couldn't deliver int &i?
    test.showHeap();
    test.maxHeapInsert(200);
    test.showHeap();

    // heapSort test
    std::cout << "heapSort test" << std::endl;
    test.heapSort();
    test.showHeap();

    // LanStack test
    std::cout << "LanStack test" << std::endl;
    LanStack testStack;
    testStack.showStack();
    for (size_t i = 1; i <= 10; ++i) {
        testStack.push(i);
    }
    testStack.showStack();
    std::cout << "the pop element is: " << testStack.pop() << std::endl;
    testStack.showStack();

    // LanQueue test
    LanQueue testLanQueue(10);
    std::cout << "is queue empty?: " << testLanQueue.empty() << std::endl;
    for (size_t i = 1; i <= 9; ++i) {
        testLanQueue.enqueue(i);
    }
    std::cout << "is queue empty?: " << testLanQueue.empty() << std::endl;
    testLanQueue.showQueue();
    testLanQueue.enqueue(10);
    for (size_t i = 1; i <= 9; ++i) {
        std::cout << "deleted element is: " << testLanQueue.dequeue() << std::endl;
    }
    std::cout << "deleted element is: " << testLanQueue.dequeue() << std::endl;

    //LanLinkedList test
    std::cout << "LanLinkedList test" << std::endl;
    LanLinkedList testlist;
    testlist.listInsertAfter(1);
    testlist.listInsertAfter(2);
    testlist.listInsertAfter(3);
    testlist.showLinkedList();
    std::cout << "search data: " << std::endl;
    Node *nt = testlist.listSearch(2);
    std::cout << "data: " << nt->key << " next pointer's data: " << nt->next->key << std::endl;

    testlist.listDeleteAfter(nt);
    testlist.showLinkedList();
    testlist.listInsertFront(0);
    testlist.showLinkedList();
    return 0;
}