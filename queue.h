#ifndef QUEUE_H
#define QUEUE_H

struct QUEUE {
    int number;
    QUEUE *next;
};

int pop     (QUEUE **root);
void push   (QUEUE **root, int number);
void clear  (QUEUE **root);
void print  (QUEUE *root);
void parser (char *str, QUEUE **root);

#endif
