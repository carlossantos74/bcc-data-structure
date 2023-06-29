#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um nó da lista
struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
};

// Função para criar um novo nó
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// Função para inserir um nó no início da lista
void insertAtBeginning(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  if (*head == NULL)
  {
    *head = newNode;
  }
  else
  {
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  }
  printf("Inserido %d no início da lista.\n", data);
}

// Função para exibir a lista
void displayList(struct Node *head)
{
  struct Node *current = head;
  if (head == NULL)
  {
    printf("A lista está vazia.\n");
  }
  else
  {
    printf("Conteúdo da lista: ");
    while (current != NULL)
    {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

int main()
{
  struct Node *head = NULL; // Ponteiro para a cabeça da lista

  // Inserindo alguns elementos na lista
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 30);

  // Exibindo a lista
  displayList(head);

  return 0;
}
