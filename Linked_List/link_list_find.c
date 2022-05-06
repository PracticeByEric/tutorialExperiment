#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIST 25

typedef struct node
{
  int value;
  struct node *next;
}node_t;

node_t *create_new_node(int value)
{
  node_t *new = malloc(sizeof(node_t));

  new->value = value;
  new->next = NULL;

  return new;
}

node_t *add_to_list(node_t *head, node_t *next_node)
{
  next_node->next = head;
  return next_node;
}

/*
TO FIND VALUE IN THE LINKED LIST
*/
node_t *find_link_list(node_t *head, int number_to_find)
{
  node_t *tmp = head;

  while (tmp != NULL)
  {
    if(tmp->value == number_to_find)
    {
      return tmp;
      tmp = tmp->next;
    }
  }
  return NULL;
}


bool print_linked_list(node_t *head)
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
      printf("%d ", tmp->value);
      tmp = tmp->next;
    }
  return true; 
  }
}

int main()
{
  node_t *head = NULL;
  node_t *tmp;

  for(int i = 0; i < MAX_LIST; i++)
  {
    tmp = create_new_node(i);
    head = add_to_list(head, tmp);
  }

  tmp = find_link_list(head, 9);
  printf("%d \n", tmp->value);

  print_linked_list(head);
}