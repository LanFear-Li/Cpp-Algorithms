//
// Created by LanFear on 2021/4/23.
//

#include "ThrTree.h"

p_seq_stack create_empty_stack(int size) {
    p_seq_stack stack = (p_seq_stack) malloc(sizeof(struct seq_stack));
    if (stack != NULL) {
        stack->s = (thread_linked_tree *) malloc(sizeof(thread_linked_tree) * size);
        if (stack->s) {
            stack->n = -1;
            stack->maxn = size;
            return stack;
        } else {
            free(stack);
        }
    }
    printf("create empty stack failed, space overflow.\n");
    return NULL;
}

int is_empty_stack(p_seq_stack stack) {
    return stack->n == -1;
}

void push(p_seq_stack stack, thread_linked_tree x) {
    if (stack->n == stack->maxn - 1) {
        printf("stack overflow.\n");
    } else {
        stack->n += 1;
        stack->s[stack->n] = x;
    }
}

void pop(p_seq_stack stack) {
    if (stack->n == -1) {
        printf("stack underflow.\n");
    } else {
        stack->n -= 1;
    }
}

thread_linked_tree top(p_seq_stack stack) {
    if (stack->n == -1) {
        printf("stack underflow.\n");
        return 0;
    } else {
        return stack->s[stack->n];
    }
}

p_thread_linked_tree create_null_tree_thread() {
    p_thread_linked_tree tree = (p_thread_linked_tree) malloc(sizeof(struct thread_linked_node));
    *tree = NULL;
    return tree;
}

p_thread_linked_node create_null_node_thread() {
    p_thread_linked_node node = (p_thread_linked_node) malloc(sizeof(struct thread_linked_node));
    node->info = 0;
    node->lLink = NULL;
    node->rLink = NULL;
    node->lTag = 0;
    node->rTag = 0;
    return node;
}

void insert_thread(p_thread_linked_tree tree, int val) {
    p_thread_linked_node node = create_null_node_thread();
    p_thread_linked_node x = *tree, y = NULL;
    node->info = val;
    while (x != NULL) {
        y = x;
        if (val < x->info) {
            x = x->lLink;
        } else {
            x = x->rLink;
        }
    }
    if (y == NULL) {
        *tree = node;
    } else if (val < y->info) {
        y->lLink = node;
    } else {
        y->rLink = node;
    }
}

void inorder_tree_walk_thread(thread_linked_tree tree) {
    thread_linked_tree p = tree;

    if (p == NULL)
        return;

    while (p->lTag == 0 && p->lLink != NULL)
        p = p->lLink;
    while (p != NULL) {
        printf("%d", p->info);

        if (!p->rTag) {
            p = p->rLink;
            while (!p->lTag)
                p = p->lLink;
        } else
            p = p->rLink;
    }
}

void inorder_make_thread(thread_linked_tree tree) {
    p_seq_stack stack = create_empty_stack(100);
    thread_linked_tree p, pr;
    if (tree == NULL)
        return;
    p = tree, pr = NULL;
    do {
        while (p != NULL) {
            push(stack, p);
            p = p->lLink;
        }
        p = top(stack);
        pop(stack);

        if (p->lLink == NULL) {
            p->lLink = pr;
            p->lTag = 1;
        }

        if (pr != NULL && pr->rLink == NULL) {
            pr->rLink = p;
            pr->rTag = 1;
        }

        pr = p;
        p = p->rLink;
    } while (!is_empty_stack(stack) || p != NULL);

    pr->rLink = p;
    pr->rTag = 1;
}

p_thread_linked_node find_post_in_pre_order(p_thread_linked_node node) {
    if (node->lTag == 0) return node->lLink;
    if (node->rTag == 0) return node->rLink;
    while (node->rLink != NULL) {
        node = node->rLink;
        if (node->rTag == 0) return node->rLink;
    }
    return NULL;
}