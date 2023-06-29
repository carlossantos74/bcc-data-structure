#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *queue;

void first(int info)
{
  queue = malloc(sizeof(Node));
  queue->data = info;
  queue->next = NULL;
}

void next(int info)
{
  Node *last = queue;
  Node *new = malloc(sizeof(Node));
  new->data = info;
  new->next = NULL;

  while (last->next != NULL)
  {
    last = last->next;
  }

  last->next = new;
}

void show()
{
  printf("mostrando \n");

  for (Node *last = queue; last != NULL; last = last->next)
  {
    printf("%d \n", last->data);
  }
}

void enquene(int info)
{
  if (queue == NULL)
  {
    first(info);
  }
  else
  {
    next(info);
  }
}

void main()
{
  enquene(1);
  show();
  enquene(2);
  show();
  enquene(3);
  show();
}
