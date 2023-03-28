#include <stdio.h>

typedef struct
{
  int start;
  int end;
  int data[5];
} Queue;

Queue initialize()
{
  Queue queue;
  queue.start = -1;
  queue.end = -1;

  printf("created \n");
  return queue;
}

void display(Queue *queue)
{
  for (int i = 0; i < 5; i++)
  {
    printf("%d. %d \n", i, queue->data[i]);
  }
}

void enqueue(Queue *queue, int key)
{
  if (queue->end == 5 - 1)
  {
    printf("queue is full\n");
    return;
  }

  if (queue->start == -1)
  {
    queue->start = 0;
  }

  queue->end = (queue->end + 1) % 5;
  queue->data[queue->end] = key;
}

void dequeue(Queue *queue)
{
  if (queue->start == -1 || queue->start > queue->end)
  {
    printf("queue is empty \n");
    return;
  }

  queue->data[queue->start] = 0;
  queue->start = queue->start + (queue->start) % 5;
}

void find(Queue *queue, int target)
{
  for (int i; i < 5; i++)
  {
    if (target == queue->data[i])
    {
      printf("\n the target was found in the %d index", i);
      return;
    }

    printf("\n the target was not found in this queue");
  }
}

int main()
{
  Queue q = initialize();

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  enqueue(&q, 40);
  enqueue(&q, 50);

  display(&q);
  dequeue(&q);

  display(&q);

  find(&q, 30);

  return 0;
}
