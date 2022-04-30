#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int months;
  double contribution;
  double rate_of_return;
}
retire_info;

int yearConversion(int months)
{
  int year;

  year =  months / 12;

  return year;
}

int monthConversion(int months)
{
  int month;

  month = months % 12;

  return month;
}

void accumulation(int startAge,double initial, retire_info working, retire_info retired)
{
  int initialAge;
  int totalMonths;
  int currentAge;

  double balance;

  initialAge = startAge;
  totalMonths = working.months + retired.months;

  balance = initial;
  
  for (int i = 0; i < totalMonths; i++)
  {
    currentAge = initialAge + i;

    //when not working
    if(i == 0)
    {
      balance = balance;
    }
    //when start working
    else if(i <= working.months)
    {
      balance = balance + balance * working.rate_of_return + working.contribution;
    }
    //when retired
    else
    {
      balance = balance + balance * retired.rate_of_return + retired.contribution;
    }

    printf("Age %d Month %d you have %.2f\n", yearConversion(currentAge), monthConversion(currentAge), balance);
  }

}

int main(void)
{
  int age;
  int saving;
  retire_info working;
  retire_info retired;

  age = 327;
  saving = 21345;

  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12;

  accumulation(age, saving, working,retired);
}