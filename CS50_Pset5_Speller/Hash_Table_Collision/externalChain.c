/*
This code shows one solution to the hash table collision:

External chain: Each location in the hash table becomes the head of a linked list,
when collision happens, add the item to the list

https://www.youtube.com/watch?v=2Ti5yvumFTU
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 10
#define TABLE_SIZE 10

//Struct_1: One entry to the hash table
typedef struct person
{
  //key
  char name[MAX_NAME];
  //value: ...
  //pointe to another entry: single linked list
  struct person *next;
}
person;

//Struct_2:
//Hash table: array of pointers to an entry
person *hash_table[TABLE_SIZE];

//Initialize hash table: easy for lookup and delete
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
    //make sure value between 0 <= value <= TABLE_SIZE
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
      //which slot is p going to
      int index = hash(p->name);

      //Add the person to the front of the list
      //p becomes the head of the list (p->next becomes the index)
      p->next = hash_table[index];
      hash_table[index] = p;
      return true;
    }
}

person *hash_table_lookup(char *name)
{
 int index = hash(name);

 for(int i = 0; i < TABLE_SIZE; i++))
 {
   //loop from the beginning
   person *tmp = hash_table[index];

    //Go through the entire loop from beginning, tmp not at the end && tmp != name looking for
   while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
   {
     //move to next
     tmp = tmp->next;
   }
   //found it, return tmp
   return tmp;
 }
}

//Delete name
person *hash_table_delete(char *name)
{
  int index = hash(name);

  person *tmp =  hash_table[index];
  person *prev = NULL;

  //Go through the entire loop. Not the end, haven't found the name
  while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
  {
    prev = tmp;
    tmp = tmp->next;
  }
  
  //tmp reaches the end of the linked list: Didn't find a match
  if(tmp == NULL)
  {
    //not there
    return NULL;
  }
  //just started the loop, at the beginning: match node was the front of the list
  if (prev == NULL)
  {
    //deleting the end
    hash_table[index] = tmp->next;
  }
  else
  {
    prev->next = tmp->next;
  }
  return tmp; 
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