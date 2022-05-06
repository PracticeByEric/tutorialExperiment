//for print out
#include <stdio.h>
//asking for memory
#include <stdlib.h>
//bool
#include <stdbool.h>

#define MAX_NAME 10
#define TABLE_SIZE 100

//Store information
typedef struct node
{
  //key
  char name[MAX_NAME];
  //information
  int age;
  //pointer to the next
  struct node *next;
}
person;

//Hash function
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

//Hash table
person *hash_table[TABLE_SIZE];

//Initialize hash table, nothing to return
void hash_table_init()
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    hash_table[i] = NULL;
  }
}

//Add to hash table
bool hash_table_insertion(person *p)
{
  //nothing to add
  if(p == NULL)
  {
    return false;
  }
  //yes to add
  else
  {
    //index to add
    int index = hash(p->name);

    //Add to linked list???
    p->next = hash_table[index]; //update p->next
    hash_table[index] = p; //update head(in this case hash_table[index])
    return true;
  }
}

//Main function
int main(void)
{

}