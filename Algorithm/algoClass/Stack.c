//
// Created by LanFear on 2021/4/8.
//

#include "Stack.h"

p_seq_stack create_empty_stack_seq(int m) {
    p_seq_stack stack = (p_seq_stack) malloc(sizeof(struct seq_stack));
    if (stack != NULL) {
        stack->s = (data_type *) malloc(sizeof(data_type) * m);
        if (stack->s) {
            stack->n = -1;
            stack->maxn = m;
            return stack;
        } else {
            free(stack);
        }
    }
    printf("create empty stack failed, space overflow.\n");
    return NULL;
}

int is_empty_stack_seq(p_seq_stack stack) {
    return stack->n == -1;
}

void push_seq(p_seq_stack stack, data_type x) {
    if (stack->n == stack->maxn - 1) {
        printf("stack overflow.\n");
    } else {
        stack->n += 1;
        stack->s[stack->n] = x;
    }
}

void pop_seq(p_seq_stack stack) {
    if (stack->n == -1) {
        printf("stack underflow.\n");
    } else {
        stack->n -= 1;
    }
}

data_type top_seq(p_seq_stack stack) {
    if (stack->n == -1) {
        printf("stack underflow.\n");
        return 0;
    } else {
        return stack->s[stack->n];
    }
}

p_shared_seq_stack create_empty_stack_shared_seq(int size) {
    p_shared_seq_stack stack = (p_shared_seq_stack) malloc(sizeof(struct shared_seq_stack));
    if (stack != NULL) {
        stack->s = (data_type *) malloc(sizeof(data_type) * size);
        if (stack->s) {
            stack->top[0] = -1, stack->top[1] = size;
            stack->maxn = size;
            return stack;
        } else {
            free(stack);
        }
    }
    printf("create empty shared stack failed, space overflow.\n");
    return NULL;
}

int is_empty_stack_shared_seq(p_shared_seq_stack stack, int idx) {
    if (idx == 0)
        return stack->top[0] == -1;
    else
        return stack->top[1] == stack->maxn;
}

void push_shared_seq(p_shared_seq_stack stack, int x, int idx) {
    if (stack->top[0] == stack->top[1] - 1) {
        printf("stack overflow.\n");
    } else {
        if (idx == 0) {
            stack->top[0] += 1;
            stack->s[stack->top[0]] = x;
        } else {
            stack->top[1] -= 1;
            stack->s[stack->top[1]] = x;
        }
    }
}

void pop_shared_seq(p_shared_seq_stack stack, int idx) {
    if (idx == 0) {
        if (stack->top[0] == -1) {
            printf("nothing to pop.\n");
        } else
            stack->top[0] -= 1;
    } else {
        if (stack->top[1] == stack->maxn) {
            printf("nothing to pop.\n");
        } else
            stack->top[1] += 1;
    }
}

int top_shared_seq(p_shared_seq_stack stack, int idx) {
    if (idx == 0) {
        if (stack->top[0] == -1) {
            printf("nothing to pop.\n");
            return -1;
        } else
            return stack->s[stack->top[0]];
    } else {
        if (stack->top[1] == stack->maxn) {
            printf("nothing to pop.\n");
            return stack->maxn;
        } else
            return stack->s[stack->top[1]];
    }
}

void digit_conversion(int num, int d) {
    p_seq_stack stack = create_empty_stack_seq(100);
    while (num) {
        push_seq(stack, num % d);
        num /= d;
    }

    while (!is_empty_stack_seq(stack)) {
        printf("%d\t", top_seq(stack));
        pop_seq(stack);
    }
}

int bracket_match(p_seq_string str) {
    p_seq_stack stack = create_empty_stack_seq(str->maxn);
    for (int i = 0; i < str->n; ++i) {
        switch (str->c[i]) {
            case '(':
            case '{':
            case '[':
                push_seq(stack, str->c[i]);
                break;

            case ')':
            case '}':
            case ']':
                if (is_empty_stack_seq(stack)) {
                    printf(") obsessed.\n");
                    return 0;
                } else if (top_seq(stack) == str->c[i])
                    pop_seq(stack);
                else {
                    printf("wrong type.\n");
                    return 0;
                }
        }
    }

    if (is_empty_stack_seq(stack))
        return 1;
    else {
        printf("( obsessed.\n");
        return 0;
    }
}