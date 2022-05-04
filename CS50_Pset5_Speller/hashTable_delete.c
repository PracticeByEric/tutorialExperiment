/*
Put a group of animal into the hash table
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 10
#define TABLE_SIZE 10

//animal info
typedef struct
{
  char name[MAX_NAME];
  int life;
}
animal;

//Hash table animal
animal *hash_table[TABLE_SIZE];

//Initialize hash table
void init_hash_table()
{
  for (int i = 0; i < TABLE_SIZE; i++)
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

//Add to hash table
bool add_hash_table(animal *a)
{
  if(a == NULL)
  {
    return false;
  }
  else
  {
    int index = hash(a->name);

      if(hash_table[index] != NULL)
    {
      return false;
    }
    else
    {
      hash_table[index] = a;
      return true;
    }
  }
}

/*
//Print out hash table
void print_hash_table()
{
  for(int i = 0; i < TABLE_SIZE; i++)
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
*/


//Look up returns animal type
animal *lookup_hash_table(char *name)
{
  //name index after hash function
  int index = hash(name);

//find name on hash table
  //if there
  if(hash_table[index] != NULL &&
    strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
  {
    return hash_table[index];
  }
  //if not
  else
  {
    return NULL;
  }
}

//remove
person *hash_table_delete(char *name)
{
  //name index after hash function
  int index = hash(name);

  //find name on hash table
  //if there
  if(hash_table[index] != NULL &&
    strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
  {
    //move item out of hash table
    animal *tmp = hash_table[index];
    hash_table[index] = NULL;
    return tmp;
  }
  else
  {
    return NULL;
  }
}

int main (void)
{


  //add animal info
  animal koala = {.name = "koala", .life = 18};
  animal bear = {.name = "bear", .life = 20};
  animal rabbit = {.name = "rabbit", .life = 9};
  animal panda = {.name = "panda", .life = 30};
  animal chick = {.name = "chick", .life = 6};
  animal human = {.name = "human", .life = 70};

  //add to hash table
  add_hash_table(&koala);
  add_hash_table(&bear);
  add_hash_table(&rabbit);
  add_hash_table(&panda);
  add_hash_table(&chick);
  add_hash_table(&human);


  //search for "koala"
  animal *tmp = lookup_hash_table("koala");

  if (tmp == NULL)
  {
    printf("Not found!\n");
  }
  else
  {
    printf("Found!\n");
  }
  
}