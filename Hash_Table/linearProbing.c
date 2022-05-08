#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 10
#define TABLE_SIZE 5

typedef struct
{
	char name[MAX_NAME];
	int age;
}person;

person *hash_table[TABLE_SIZE];

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

//Initialize hash_table
void hash_table_init()
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		hash_table[i] = NULL;
	}
}

//Insert to hash table: Linear probing
bool hash_table_insert(person *p)
{
	if(p == NULL)
	{
		return false;
	}
	else
	{
		//generate index number through hash function
		int index = hash(p->name);

		//within limit of TABLE_SIZE, go through all spots in table
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			//from index to all other spots in table
			int try = (index + i) % TABLE_SIZE;
			//found empty spot
			if(hash_table[try] == NULL)
			{
				//save p to that place
				hash_table[try] = p;
				return true;
			}
		}
		//not found
		return false;
	}
}

//Print hash table
void hash_table_print()
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(hash_table[i] == NULL)
		{
			printf("%d --- \n", i);
		}
		else
		{
			printf("%d %s\n", i, hash_table[i]->name);
		}
	}
}

int main()
{
	person jack = {.name = "jack", .age = 30};
	person bob = {.name = "bob", .age = 12};
	person adrian = {.name = "adrain", .age = 20};
	person alan = {.name = "alan", .age = 45};
	person peter = {.name = "peter", .age = 88};

	hash_table_insert(&jack);
	hash_table_insert(&bob);
	hash_table_insert(&adrian);
	hash_table_insert(&alan);
	hash_table_insert(&peter);

	hash_table_print();

	return 0;
}