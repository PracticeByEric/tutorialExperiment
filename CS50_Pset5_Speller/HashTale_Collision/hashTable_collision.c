/*
This code show collision happens in a hash table
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

//print out hash table
void print_hash_table()
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    if(hash_table[i] == NULL)
    {
      printf("%i --- \n", i);
    }
    else
    {
      printf("%i %s \n", i, hash_table[i]->name);
    }
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
  animal lizard = {.name = "lizard", .life = 29};
  animal snake = {.name = "snake", .life = 65};
  animal fox = {.name = "fox", .life = 15};
  animal duck = {.name = "duck", .life = 29};

  //add to hash table
  add_hash_table(&koala);
  add_hash_table(&bear);
  add_hash_table(&rabbit);
  add_hash_table(&panda);
  add_hash_table(&chick);
  add_hash_table(&human);
  add_hash_table(&lizard);
  add_hash_table(&snake);
  add_hash_table(&fox);
  add_hash_table(&duck);
  
  print_hash_table();
}