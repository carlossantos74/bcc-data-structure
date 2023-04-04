#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
  int data[MAX_SIZE];
  int top;
} Stack;

void push(Stack *stack, int value)
{
  if (stack->top == MAX_SIZE - 1)
  {
    printf("The stack is full! \n");
    return;
  }
  stack->top++;
  stack->data[stack->top] = value;
}

int pop(Stack *stack)
{
  if (stack->top == -1)
  {
    printf("The stack is empty!\n");
    return -1;
  }
  int value = stack->data[stack->top];
  stack->top--;
  return value;
}

void show(Stack *stack)
{
  printf("Stack elements: \n");
  for (int i = stack->top; i >= 0; i--)
  {
    printf("%d \n", stack->data[i]);
  }
}

void menu(Stack *stack)
{
  while (1)
  {
    int element;
    int choice;

    printf("\nPerform operations on the stack:");
    printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
    printf("\n\nEnter the choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      scanf("%d", &element);
      push(stack, element);
      menu(stack);
      break;
    case 2:
      pop(stack);
      menu(stack);
      break;
    case 3:
      show(stack);
      menu(stack);
      break;
    case 4:
      exit(0);

    default:
      printf("\nInvalid choice!!");
    }
  }
}

int main()
{
  Stack stack;
  stack.top = -1;

  menu(&stack);
}