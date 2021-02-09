#include <stdio.h>
#include <math.h>
#include <cs50.h>

//Note to self: Array solution would be favorable, but going with the flow of CS50 here.

//prototypes
int doubleDigitValue (int);
bool luhnCheck (bool, int, long);
string typeOfCard (long);

int main (void)
{
  //Prompt user for input
  long number = get_long("Number: ");
  bool isValid;

  //Find digit length of number
  //Modified from https://www.quora.com/How-can-I-find-the-length-of-a-long-number-in-C
  int num_length = floor(1 + log10(number));

  //Determine if length of number is even or odd and call luhnCheck
  if (num_length % 2 == 0) isValid = luhnCheck (true, num_length, number);
  else isValid = luhnCheck (false, num_length, number);

  printf("This is a %s cc number.\n", isValid ? "valid" : "INVALID");

  if (isValid)
    printf("%s\n", typeOfCard(number));
  else
    printf("INVALID\n");

  return 0;
}

int doubleDigitValue (int digit)
{
  int doubledDigit = digit * 2;
  int sum;
  if (doubledDigit < 10) sum = doubledDigit;
  else sum = 1 + (doubledDigit % 10);
  return sum;
}

bool luhnCheck (bool isEvenLength, int length, long number)
{
  int luhnSum = 0;

  printf("The bool is %s, the length is %d, and the number is %ld\n", isEvenLength ? "true" : "false", length, number);

  for (int i = 0; i < length; i++)
  {
		//if number is even length, digits in even position will be doubled, and the reverse for odd length numbers
		if (isEvenLength)
			if (i % 2 == 0)
				luhnSum += doubleDigitValue(number % 10);
			else
				luhnSum += number % 10;
		else if (i % 2 == 0)
			luhnSum += number % 10;
		else
			luhnSum += doubleDigitValue(number % 10);

    // removes last digit of current number
    number = number / 10;
  }

  printf("The luhnSum is: %d\n", luhnSum);

  // checks if the luhn sum is valid by dividing by ten
  if (luhnSum % 10 == 0)
    return true;
  else
    return false;
}

string typeOfCard (long number)
{
  //sets number equal to the first two digits of the full cc number
  while (number >= 100)
  {
    number = number / 10;
  }

  printf("The first digits are: %ld\n", number);
  //determine brand of credit card
  if (number == 34 || number == 37)
    return "AMEX";
  else if (number >= 51 && number <= 55)
    return "MASTERCARD";
  else if (number >= 40 && number <= 49)
    return "VISA";
}
