#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODE 10

typedef struct node
{
  int value;
  struct node *next;
}node_t;

node_t *create_new_node(int number)
{
  node_t *new = malloc(sizeof(node_t));

  new->value = number;
  new->next = NULL;

  return new;
}

/*
TO INSERT HEAD OF THE LIST
*/
node_t *add_to_head(node_t *head, node_t *toAdd)
{
  toAdd->next = head;
  return toAdd;
}

/*
TO INSERT AFTER A NODE
*/

void insert_after_node(node_t *node_to_insert_after, node_t *new_node)
{
  /*
  这一段的规律可以参考tmp和head, insert tmp to the head of the list的过程是：
  tmp->next = head;
  head = tmp; 即
  被添加->next = 前一项；
  前一项 = 被添加

  同理在一段code中, new_node是被添加， node_to_insert_after是前一项，即:
  new_node->next = node_to_insert_after->next;
  node_to_insert_after->next = new_node;
  */
  new_node->next = node_to_insert_after->next;  //区别是head和前一项->next
  node_to_insert_after->next = new_node;
}
//??HOW TO PRESENT THIS GRAPHICALLY???

node_t *find_node(node_t *head, int number)
{
  node_t *tmp = head;

  while(tmp != NULL)
  {
    if(tmp->value == number)
    {
      return tmp;
    }
    tmp = tmp->next;
  }
  return NULL;
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
      printf("%d -", tmp->value);
      tmp = tmp->next;
    }
  }
  printf("\n");
  return true;
}

int main()
{
  node_t *head = NULL;
  node_t *tmp;

  for(int i = 0; i < MAX_NODE; i++)
  {
    tmp = create_new_node(i);
    head = add_to_head(head, tmp);
  }

  print_list(head);

  insert_after_node(find_node(head, 3), create_new_node(888));
  print_list(head);
}