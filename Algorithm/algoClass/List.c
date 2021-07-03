//
// Created by LanFear on 2021/4/8.
//

#include "List.h"

p_seq_list create_null_list_seq(int m) {
    p_seq_list list = (p_seq_list) malloc(sizeof(struct seq_list));
    list->maxn = m;
    list->n = 0;
    list->element = (int *) malloc(sizeof(int) * m);
    return list;
}

int is_null_list(p_seq_list list) {
    return list->n == 0;
}

int locate_seq(p_seq_list list, int x) {
    if (list->n == 0) return -1;
    for (int i = 0; i < list->n; ++i) {
        if (list->element[i] == x) return i;
    }
    return -1;
}

int insert_pre_seq(p_seq_list list, int p, int x) {
    if (list->maxn == list->n) {
        printf("insert_pre_seq::list overflow!\n");
        return 0;
    } else if (p < 0 || p >= list->maxn) {
        printf("insert_pre_seq::given place is illegal!\n");
        return 0;
    }
    if (p < list->n) {
        for (int i = list->n - 1; i >= p; --i)
            list->element[i + 1] = list->element[i];
        list->element[p] = x;
        list->n++;
        return 1;
    } else {
        list->element[list->n] = x;
        printf("insert_pre_seq::given place is invalid, auto fixed.\n");
        list->n++;
        return 1;
    }
}

int insert_post_seq(p_seq_list list, int p, int x) {
    if (list->maxn == list->n) {
        printf("insert_post_seq::list overflow!\n");
        return 0;
    } else if (p < 0 || p >= list->maxn) {
        printf("insert_post_seq::given place is illegal!\n");
        return 0;
    }
    if (p < list->n) {
        for (int i = list->n - 1; i >= p + 1; --i) {
            list->element[i + 1] = list->element[i];
        }
        list->element[p + 1] = x;
        list->n++;
        return 1;
    } else {
        list->element[list->n] = x;
        list->n++;
        printf("insert_post_seq::given place is invalid, auto fixed.\n");
        return 1;
    }
}

int deleteP_seq(p_seq_list list, int p) {
    if (list->n == 0) {
        printf("deleteP_seq::list underflow!\n");
        return 0;
    } else if (p < 0 || p >= list->n) {
        printf("deleteP_seq::given place is illegal!\n");
        return 0;
    }
    for (int i = p; i < list->n - 1; ++i) {
        list->element[i] = list->element[i + 1];
    }
    list->n--;
    return 1;
}

void show_list_seq(p_seq_list list) {
    if (list->n == 0) {
        printf("show_list_seq::nothing to show!\n");
    } else {
        for (int i = 0; i < list->n; ++i) {
            printf("%d\t", list->element[i]);
        }
        printf("\n");
    }
}

linked_list create_null_list_link() {
    linked_list list = (linked_list) malloc(sizeof(p_linked_node));
    if (list != NULL)
        list->link = NULL;
    else
        printf("out of space.\n");
    return list;
}

p_linked_node locate_link(linked_list list, int x) {
    p_linked_node node = list->link;
    while (node != NULL) {
        if (node->info == x)
            return node;

        node = node->link;
    }

    return NULL;
}

// insert a linked_node which data is info before p
int insert_pre_link(linked_list list, p_linked_node p, int info) {
    p_linked_node q1 = list;
    while (q1 != NULL && q1->link != p) q1 = q1->link;
    if (q1->link != p) {
        printf("linked_node p not existed\n");
        return 0;
    } else {
        p_linked_node q2 = (p_linked_node) malloc(sizeof(p_linked_node));
        if (q2 == NULL) {
            printf("Out of Space\ns");
            return 0;
        } else {
            q2->info = info;
            q2->link = p;
            q1->link = q2;
            return 1;
        }
    }
}

int insert_post_link(linked_list list, p_linked_node p, int info) {
    p_linked_node node = list->link;

    while (node != NULL && node->link != p)
        node = node->link;

    if (node->link == p) {
        p_linked_node x = node->link, y = x->link;
        p_linked_node insert_node = (p_linked_node) malloc(sizeof(struct linked_node));

        insert_node->info = info;
        insert_node->link = y;
        x->link = insert_node;

        return 1;
    } else {
        printf("linked_node is not existed.\n");
        return 0;
    }
}

// delete the linked_node x
void delete_node_link(linked_list list, p_linked_node node) {
    if (list == node) {
        list = list->link;
        node->link = NULL;
        free(node);
    } else {
        p_linked_node p = list;
        while (p->link != NULL && p->link != node) p = p->link;
        p->link = node->link;
        node->link = NULL;
        free(p);
    }
}

// delete all the linked_node which data is x
void delete_all_x_link(linked_list list, int x) {
    p_linked_node node = list;
    if (list->info == x) {
        node = list->link;
        list->link = NULL;
        list = node;
    }
    while (node->link != NULL) {
        while (node->link != NULL && node->link->info != x) node = node->link;
        node->link = node->link->link;
    }
}

cycled_linked_list create_null_list_cycled_link() {
    cycled_linked_list cycled_list = (cycled_linked_list) malloc(sizeof(p_cycled_linked_node));
    if (cycled_list != NULL) {
        cycled_list->link = cycled_list;
        return cycled_list;
    }

    printf("out of space.\n");
    return NULL;
}

void delete_p_double_link(struct double_linked_list list, p_double_linked_node p) {
    p->left->right = p->right;
    p->right->left = p->left;
    free(p);
}

int insert_post_double_link(struct double_linked_list list, p_double_linked_node p, int info) {
    p_double_linked_node node = (p_double_linked_node) malloc(sizeof(struct double_linked_node));
    if (node != NULL) {
        node->info = info;
        node->left = p;
        node->right = p->right;
        p->right->left = node;
        p->right = node;
        return 1;
    }

    printf("create node failed.\n");
    return 0;
}

int insert_pre_double_link(struct double_linked_list list, p_double_linked_node p, int info) {
    p_double_linked_node node = (p_double_linked_node) malloc(sizeof(struct double_linked_node));
    if (node != NULL) {
        node->info = info;
        node->right = p;
        node->left = p->left;
        p->left->right = node;
        p->left = node;
        return 1;
    }

    printf("create node failed.\n");
    return 0;
}

double_cycled_linked_list convert_to_double_cycled_linked_list(cycled_linked_list list) {
    double_cycled_linked_list double_list = (double_cycled_linked_list) malloc(sizeof(struct double_cycled_linked_node));

    /* empty function */

    return double_list;
}

int reverse_link(linked_list list) {
    if (list == NULL || list->link == NULL) {
        printf("no need to reverse\n");
        return 0;
    } else {
        p_linked_node back = list, front = list->link;
        list->link = NULL;
        while (front->link != NULL) {
            p_linked_node next = front->link;
            front->link = back;
            back = front;
            front = next;
        }
        front->link = back;
        list = front;
        free(front);
        free(back);
        return 1;
    }
}

void delete_duplicated_data_link(linked_list list) {
    p_linked_node x, y, pre;
    x = list;
    pre = NULL;

    while (x != NULL) {
        pre = x;
        y = pre->link;
        while (y != NULL) {
            if (y->info == x->info) {
                pre->link = y->link;
                free(y);
            }

            pre = pre->link;
            y = pre->link;
        }

        x = x->link;
    }

    /* bad trick */
    /*int book[10000];
    for (int i = 0; i < 10000; i++) {
        book[i] = 0;
    }
    p_linked_node node = list;
    while (node->link != NULL) {
        book[node->info]++;
        if (book[node->info] == 2) {
            book[node->info]--;
            p_linked_node p = node;
            node = node->link;
            delete_node_link(list, p);
            free(p);
        } else {
            node = node->link;
        }
    }*/
}

int delete_all_data_seq(p_seq_list list, int info) {
    if (list == NULL || list->n <= 0) {
        printf("nothing to delete.\n");
        return 0;
    }

    int i = 0;
    while (i < list->n) {
        if (list->element[i] == info) {
            for (int j = i; j < list->n - 1; ++j)
                list->element[j] = list->element[j + 1];
            list->n -= 1;
        } else
            i++;
    }

    return 1;
}