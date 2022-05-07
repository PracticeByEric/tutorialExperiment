/*
Following tutorial on:
https://www.youtube.com/watch?v=2Ti5yvumFTU
*/

#include <stdio.h>
#include <string.h>

#define MAX_NAME 256
//Size of hash table
#define TABLE_SIZE 10

//Hash table store information about people
typedef struct
{
  char name[MAX_NAME];
  int age;
  //...add other info
}person;

person *hash_table[TABLE_SIZE];

//Hash function: in this case look up people by their name
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

//Initialize hash table
void init_hash_table()
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    hash_table[i] = NULL;
  }
}

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

int main()
{
  init_hash_table();
  print_hash_table();

  return 0;
}