#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

    //update for linear probing
    for(int i = 0; i < TABLE_SIZE; i++)
    {
      //update index
      int try = ( index + i ) % TABLE_SIZE;

      //from index to all other following "slots" in hash table
      //if found
      if(hash_table[try] == NULL)
      {
        // add value
        hash_table[try] = p;
        return true;
      }
    }
    //not found, return false
    return false;
  }
}

//find a person in the table
person *hash_table_find(char *name)
{
  int index = hash(name);

  for(int i = 0; i < TABLE_SIZE; i++)
  {
    if(hash_table[index] != NULL &&
      strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
    {
      return hash_table[index];
    }
  }
  return NULL;
}

//delete person in hash table
/*To remove means set the pointer back to NULL*/
person *hash_table_delete(char *name)
{
  int index = hash(name);

  for(int i = 0; i < TABLE_SIZE; i++)
  {
    //found the location
    if(hash_table[index] != NULL &&
      strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
    {
      //save the data inside of a temporary pointer
      person *tmp = hash_table[index];
      //remove
      hash_table[index] = NULL;
      return tmp;
    }
  }
  return NULL;
}

//print out hash table
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
  
  person jack = {.name = "jack", .age = 30};
  hash_table_insert(&jack);

  print_hash_table();

  person *toFind = hash_table_find("jack");

  if(toFind == NULL)
  {
    printf("Not found.");
  }
  else
  {
    printf("Found the person named %s.\n", toFind->name);
  }

//remove jack from the hash table
  hash_table_delete("jack");

//print out new table
  print_hash_table();

  return 0;
}
