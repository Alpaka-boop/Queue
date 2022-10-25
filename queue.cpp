#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "queue.h"

int main()
{
    int oper = 0;
    QUEUE *root = NULL;

    scanf("%d\n", &oper);

    for (int i = 0; i < oper; ++i)
    {
        char str[100] = "";

        fgets(str, 50, stdin);
        parser(str, &root);
    }

    clear(&root);

    return 0;
}

void push (QUEUE **root, int number)
{
    if (*root != NULL) {
        QUEUE *curr = *root;

        while (curr->next != NULL)
            curr = curr->next;

        QUEUE *new_el = (QUEUE *) malloc(sizeof(QUEUE *));

        curr->next = new_el;
        new_el->next = NULL;
        new_el->number = number;
    }
    else
    {
        *root = (QUEUE *) malloc(sizeof (QUEUE *));
        (*root)->number = number;
        (*root)->next = NULL;
    }
}

void parser (char *str, QUEUE **root)
{
    int i = 0;
    bool flag = true;

    assert(root);

    while (flag)
    {
        switch (str[i])
        {
            case '\n':
                flag = false;
                break;
            case '-':
                printf("%i\n", pop(root));
                break;
            case '+':
            {
                int number = 0;

                while (!isdigit(str[++i])) {;}

                do {
                    number = number * 10 + (str[i] - '0');
                    i++;
                } while ('0' <= str[i] && str[i] <= '9');

                push(root, number);
            }
            case ' ':
                break;
            case '\r':
                break;
            default:
                flag = false;
        }

        i++;
    }
}

int pop (QUEUE **root)
{
    assert(*root);

    int number = (*root)->number;

    QUEUE *curr = (*root)->next;

    free(*root);
    *root = curr;

    return number;
}

void clear (QUEUE **root)
{
    while (*root != NULL)
        pop(root);
}

void print(QUEUE *root)
{
    while (root->next != NULL) {
        printf("%i ", root->number);
        root = root->next;
    }

    printf("%i", root->number);
}
