#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
//size of hash_table
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
  //delcare beginning of the hash table
  printf("Start\n");
  //loop through hash table
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    //nothing in hash table
    if(hash_table == NULL)
    {
      printf("%i ---\n",i);
    }
    //elements in hash table
    else
    {
      printf(" %i %s\n", i, hash_table[i]->name);
    }
  }
    printf("End\n");
}

//STEP5_Insertion to hash table
/*
this hash table insert address of person's name using bool
*/
bool hash_table_insertion(person *p)
{
  //no person
  if (p == NULL)
  {
    return false;
  }
  //is person
  else{
    int index = hash(p->name);
    //hash_table[index] filled: collision
    if(hash_table[index] != NULL)
    {
      return false;
    }
    //hash_table[index] avaiable
    hash_table[index] = p;
    return true;
  }
}

int main()
{
  init_hash_table();
  print_table();

  person jacob = {.name = "Jacob", .age = 256};
  person kate = {.name = "kate", .age = 27};
  person mpho = {.name = "mpho", .age = 14};

  hash_table_insertion(&jacob);
  hash_table_insertion(&kate);
  hash_table_insertion(&mpho);

  print_table();

  /*
  printf("Jacob => %u\n", hash("Jacob"));
  printf("Natalie => %u\n", hash("Natalie"));
  printf("Sara => %u\n", hash("Sara"));
  printf("Mpho => %u\n", hash("Mpho"));
  printf("Tebogo => %u\n", hash("Tebogo"));
  printf("Ron => %u\n", hash("Ron"));
  printf("Jane => %u\n", hash("Jane"));
  printf("Maren => %u\n", hash("Maren"));
  printf("Bill => %u\n", hash("Bill"));
  */

  return 0;
}