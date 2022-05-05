/*
This code shows one solution to the hash table collision:

External chain: Each location in the hash table becomes the head of a linked list,
when collision happens, add the item to the list
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 10
#define TABLE_SIZE 10

typedef struct person
{
  char name[MAX_NAME];
  struct person *next;
}
person;

//Generate hash table
person *hash_table[TABLE_SIZE];

//Initialize hash table
void hash_table_init()
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    hash_table[i] = NULL;
  }
}

//Hash function
unsigned int hash(char *name)
{
  int length = strnlen(name, MAX_NAME);
  unsigned int hash_value = 0;

  for(int i = 0; i < length; i++)
  {
    hash_value += name[i];
    //generate more random number but fit inside of table (%TABLE_SIZE)
    hash_value = (hash_value * name[i]) % TABLE_SIZE;
  }
  return hash_value;
}

//Insert to hash table
bool hash_table_insertion(person *p)
{
  //if p does not exist
  if(p == NULL)
  {
    return false;
  }
  //p exists: 1_
  else
  {
    int index = hash(p->name);

    //WHY??? 
    p->next = hash_table[index];
    //WHY???
    hash_table[index] = p;
    return true;

  }
  }
}

//Print hash table
void hash_table_print()
{
  for(int i = 0; i <TABLE_SIZE; i++)
  {
    if(hash_table[i] == NULL)
    {
      printf("%i ---\n", i);
    }
    else
    {
      printf("%i %s\n", i, hash_table[i]->name);
    }
  }
}

int main(void)
{
  person jack = {.name = "jack"};

  hash_table_insertion(&jack);

  hash_table_print();
}