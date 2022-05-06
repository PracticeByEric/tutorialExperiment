/*
To insert elements to the linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODE 10

typedef struct node
{
  int value;
  struct node *next;
}node_t;

node_t *create_new_node(int number)  //return address of the new node
{
  //Ask for memory on heap to create new node
  node_t *result = malloc(sizeof(node_t));

  result->value = number;
  result->next = NULL;

  return result;
}

bool print_list(node_t *head)
{
  if(head == NULL)
  {
    return false;
  }
  else
  {
    node_t *tmp = head;

    while(tmp != NULL)
    {
      printf("%d - ", tmp->value);
      tmp = tmp->next;
    }
  }
  printf("\n");
}


/*
To insert node at the beginning of the linked list, 
takes in two values: head, node_to_insert
*/

node_t *insert_at_head(node_t *head, node_t *node_to_insert)
{
  //link node to insert with the head of the current node: simialr to tmp->next = head; head = tmp;
  node_to_insert->next = head;
  //return node_to_insert which will become the new head pointer
  return node_to_insert;
}

int main()
{
  node_t *head = NULL;
  node_t *tmp;

  for(int i = 0; i < MAX_NODE; i++)
  {
    tmp = create_new_node(i);
    //the function does not change the head
    head = insert_at_head(head, tmp);
  }

  print_list(head);
}
