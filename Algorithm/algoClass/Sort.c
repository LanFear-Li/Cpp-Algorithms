//
// Created by LanFear on 2021/6/26.
//

#include "Sort.h"

sort_object *generate_random_object(int object_size) {
    sort_object *object = (sort_object *) malloc(sizeof(sort_object));
    object->record = (record_node *) malloc(sizeof(record_node) * object_size);
    object->n = object_size;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < object->n; ++i) {
        record_node temp;
        temp.key = rand() % 50 + 1;
        temp.info = rand() % 100 + 50;
        object->record[i] = temp;
    }

    return object;
}

void show_object(sort_object *object) {
    for (int i = 0; i < object->n; ++i) {
        printf("key: %d\t", object->record[i].key);
    }
    printf("\n");
}

void direct_insert_sort(sort_object *p_vector) {
    record_node temp;
    int j;

    for (int i = 1; i < p_vector->n; ++i) {
        temp = p_vector->record[i];
        j = i - 1;

        while (j >= 0 && temp.key < p_vector->record[j].key) {
            p_vector->record[j + 1] = p_vector->record[j];
            j--;
        }

        if (j != i - 1)
            p_vector->record[j + 1] = temp;
    }
}

void binary_insert_sort(sort_object *p_vector) {
    record_node temp;

    for (int i = 1; i < p_vector->n; ++i) {
        temp = p_vector->record[i];
        int left = 0, right = i - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (temp.key < p_vector->record[mid].key) right = mid;
            else left = mid + 1;
        }

        for (int j = i - 1; j >= left; --j)
            p_vector->record[j + 1] = p_vector->record[j];

        if (left != i)
            p_vector->record[left] = temp;
    }
}

void shell_insert_sort(sort_object *p_vector, int d) {
    record_node temp;
    int j;

    for (int increment = d; increment > 0; increment /= 2) {
        for (int i = increment; i < p_vector->n; i++) {
            temp = p_vector->record[i];
            j = i - increment;

            while (j >= 0 && temp.key < p_vector->record[j].key) {
                p_vector->record[j + increment] = p_vector->record[j];
                j -= increment;
            }

            p_vector->record[j + increment] = temp;
        }
    }
}

void direct_select_sort(sort_object *p_vector) {
    for (int i = 0; i < p_vector->n - 1; ++i) {
        int idx = i;
        for (int j = i + 1; j < p_vector->n; ++j) {
            if (p_vector->record[idx].key > p_vector->record[j].key)
                idx = j;
        }

        if (idx != i)
            swap(p_vector->record, i, idx);
    }
}

void shift(sort_object *p_vector, int size, int p) {
    record_node temp;
    int i, child;
    temp = p_vector->record[p];
    i = p, child = 2 * i + 1;

    while (child < size) {
        if (child < size - 1 && p_vector->record[child].key < p_vector->record[child + 1].key)
            child++;
        if (temp.key < p_vector->record[child].key) {
            p_vector->record[i] = p_vector->record[child];
            i = child, child = 2 * i + 1;
        } else
            break;
    }

    p_vector->record[i] = temp;
}

static inline void swap(record_node *record, int i, int j) {
    record_node temp = record[i];
    record[i] = record[j];
    record[j] = temp;
}

void heap_select_sort(sort_object *p_vector) {
    int n = p_vector->n;

    for (int i = n / 2 - 1; i >= 0; --i)
        shift(p_vector, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(p_vector->record, 0, i);
        shift(p_vector, i, 0);
    }
}

void bubble_swap_sort(sort_object *p_vector) {
    for (int i = 0; i < p_vector->n - 1; ++i) {
        for (int j = 0; j < p_vector->n - i - 1; ++j) {
            if (p_vector->record[j].key > p_vector->record[j + 1].key)
                swap(p_vector->record, j, j + 1);
        }
    }
}

void quick_swap_sort(sort_object *p_vector, int l, int r) {
    if (l >= r) return;

    int i = l, j = r;
    record_node temp = p_vector->record[i];

    while (i != j) {
        while (p_vector->record[j].key >= temp.key && j > i) j--;
        if (i < j) p_vector->record[i++] = p_vector->record[j];

        while (p_vector->record[i].key <= temp.key && j > i) i++;
        if (i < j) p_vector->record[j--] = p_vector->record[i];
    }

    p_vector->record[i] = temp;
    quick_swap_sort(p_vector, l, i - 1);
    quick_swap_sort(p_vector, i + 1, r);
}

void merge_sort(sort_object *p_vector) {

}