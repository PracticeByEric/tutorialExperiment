#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//size of name
#define MAX_NAME 256
//size of hash table
#define TABLE_SIZE 10

//struct of person data
typedef struct
{
  char name[MAX_NAME];
  int age;
}
person;

//STEP 2_Make hash table;
person *hash_table[TABLE_SIZE];

//STEP 1_generate hash function, return number
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

//STEP 3_Initialize the table, set all pointers to null
void init_hash_table()
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    hash_table[i] = NULL;
  }
}

//STEP 4_Print out the table
void print_hash_table()
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    //nothing in table: print sequential number
    if(hash_table[i] == NULL)
    {
      printf(" %i --- \n", i);
    }
    //hash table filled: print sequential number and its name 
    else
    {
      printf(" %i %s \n", i, hash_table[i]->name);
    }
  }
}

int main(void)
{
  
  print_hash_table();

  /*
  printf("Jack => %u\n", hash("Jack"));
  printf("Eric => %u\n", hash("Eric"));
  printf("Jackie => %u\n", hash("Jackie"));
  printf("Mandy => %u\n", hash("Mandy"));
  printf("Bob => %u\n", hash("Bob"));
  */

  return 0;
}