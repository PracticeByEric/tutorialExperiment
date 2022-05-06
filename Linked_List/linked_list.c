/*
  How to create a linked list
  Tutorial on https://www.youtube.com/watch?v=VOpjAHCee7c
*/

#include <stdio.h>
#include <stdlib.h>


#define NODES_NUMBER 10

typedef struct node
{
  int value;
  struct node *next;
}
node_t;


//takes in the key to trigger
void printlist(node_t *head)
{
  //create empty inidicating each location
  node_t *tmp = head;

  while (tmp != NULL)
  {
    printf("%d - ", tmp->value);
    tmp = tmp->next;
  }
  printf("\n");
}

//new node creation
node_t *create_new_node(int value) //returning pointer
{
  node_t *result = malloc(sizeof(node_t));
  result->value = value;
  result->next = NULL;
  return result;
}

int main()
{
  node_t *head = NULL;
  node_t *tmp;

  for(int i = 0; i < NODES_NUMBER; i++)
  {
      tmp = create_new_node(i);
      tmp->next = head; //update tmp->next
      head = tmp;  //update head, keep adding to the front
  }

  printlist(head);

  return 0;
}