#include <stdio.h>
#include <stdlib.h>

//Convert age in year
int yearConversion(int ageInMonth)
{
  int years;

  years = ageInMonth / 12;

  return years;
}

//Convert age in months
int monthConversion(int ageInMonth)
{
  int months;

  months = ageInMonth % 12;

  return months;
}

int main(void)
{
  int age;
  int year;
  int month;

  printf("Age in months: ");
  scanf("%d", &age);

  year = yearConversion(age);
  month = monthConversion(age);

  printf("Your month is %d, so you are Age %d month %d.\n", age, year, month);
}

