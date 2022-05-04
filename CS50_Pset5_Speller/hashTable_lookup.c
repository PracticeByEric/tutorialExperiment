#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct{
  char name[MAX_NAME];
  int age;
  //add other personal information
} person;

//STEP2_Generate hash table
person *hash_table[TABLE_SIZE];
/*
Why pointers for the hash table?

(1) Do not need space for the full table unless fill out the table.
(2) Easy to tell when the spot on the table is empty.
*/

//STEP1_Create hash function
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

//STEP3_Initialize hash table
void init_hash_table()
{
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    hash_table[i] = NULL;
  }
  //table is empty
}

//STEP4_Print out hash table
void print_table()
{
  printf("Start\n");
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    if(hash_table == NULL)
    {
      printf("%i ---\n",i);
    }
    else
    {
      printf(" %i %s\n", i, hash_table[i]->name);
    }
  }
    printf("End\n");
}

//STEP5_Insertion to hash table
bool hash_table_insertion(person *p)
{
  if (p == NULL)
  {
    return false;
  }
  else{
    int index = hash(p->name);
    //check availability of the hash_table[index]
    if(hash_table[index] != NULL)
    {
      return false;
    }
    //insert p into hash_table[index]
    hash_table[index] = p;
    return true;
  }
}

//STEP6_Look up_Find a person by name
person *hash_table_lookup(char *name)
{
  int index = hash(name);
  if (hash_table[index] != NULL && 
  strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
  {
    return hash_table[index];
  }
  else
  {
    return NULL;
  }
}

int main(void)
{
  init_hash_table();
  print_table();

  person jacob = {.name = "jacob", .age = 256};
  person kate = {.name = "kate", .age = 27};
  person mpho = {.name = "mpho", .age = 14};

  hash_table_insertion(&jacob);
  hash_table_insertion(&kate);
  hash_table_insertion(&mpho);
  print_table();

  person *tmp = hash_table_lookup("jacob");
  if(tmp == NULL)
  {
    printf("Not found!");
  }
  else
  {
    printf("Found!");
  }

  return 0;
}