/*
Practice on reading from a text file.

Tutorial: https://www.youtube.com/watch?v=mrKSsb3h2tQ
*/
#include <stdio.h>

#define MAX_NAME 20

int main()
{
  //Open the file
  FILE *file = fopen("texts.txt", "r");

  char name[MAX_NAME];

  int age;

  if(file == NULL)
  {
    //file not exist
    printf("There is no such file to open.\n");
  }
  else
  //file exists
  {
    /*
    Read the file with fscanf
    fscanf (file pointer, "percent specifiers", ADDRESS OF THE VARIABLE);
    
    就像scanf("%s", name); scanf(type of data, ADDRESS OF DATA go into), fscanf的逻辑是相同的
    fscanf(pointer of he file, type of data, address of data go into)，因此:
    */

    fscanf(file, "%s %d", name, &age);  //因为name是string, address of string就是adress of first char; age是int, address of int 是&int
    
    printf("%s %d", name, age);
    
    fclose(file);
  }

  //Close the file
  return 0;
}