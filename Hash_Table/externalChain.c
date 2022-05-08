#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 10
#define TABLE_SIZE 5

typedef struct person
{
  char name[MAX_NAME];
  int age;
  struct person *next;
}person;

//generate hash table
person *hash_table[TABLE_SIZE];


//hash function
unsigned int hash(char *name)
{
  int length = strnlen(name, MAX_NAME);
  unsigned int hash_value = 0;

  for(int i = 0; i < length; i++)
  {
    hash_value += name[i];
    hash_value = (hash_value * name[i]) % TABLE_SIZE;
  }
  return hash_value;
}

//initialize hash table
void hash_table_init()
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    hash_table[i] = NULL;
  }
}

//insert to hash table
bool hash_table_insert(person *p)
{
  if(p == NULL)
  {
    return false;
  }
  else
  {
    int index = hash(p->name);

    /*
    same as adding number to linked list
    hash_table[index] is the head of the list
    */
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
  }
}

person *hash_table_lookup(char *name)
{
  int index = hash(name);

  /*
  search in linked list, head is hash_table[index]
  */

 person *tmp = hash_table[index];
 while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
 {
   tmp = tmp->next;
 }
 return tmp;
}

void hash_table_print()
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    if(hash_table[i] == NULL)
    {
      printf("%d --- ", i);
    }
    else
    {
      printf("%d ",i);
      person *tmp = hash_table[i];
      while (tmp != NULL)
      {
        printf("%s ", tmp->name);
        tmp = tmp->next;
      }
      printf("\n");
    }
  }
}

int main()
{
  person amy = {.name = "amy", .age = 22};
  person alice = {.name = "alice", .age = 32};
  person alicia = {.name = "alicia", .age = 42};
  person alex = {.name = "alex", .age = 52};
  person alexa = {.name = "alexa", .age = 62};
  person alexandra = {.name = "alexandra", .age = 72};

  hash_table_insert(&amy);
  hash_table_insert(&alice);
  hash_table_insert(&alicia);
  hash_table_insert(&alex);
  hash_table_insert(&alexa);
  hash_table_insert(&alexandra);

  hash_table_print();

  person *tmp = hash_table_lookup("alex");

  if(tmp == NULL)
  {
    printf("Not found\n");
  }
  else
  {
    printf("Found %s.\n", tmp->name);
  }

  return 0;
}