#include<iostream>
using namespace std;
/* rand example: guess the number */
#include <stdio.h> /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */
int main ()
{
int iSecret, iGuess,noOfTurns(0);
/* initialize random seed: */
srand (time(NULL));
/* generate secret number between 1 and 10: */
iSecret = rand() % 10+ 1;
do {
printf ( "Guess the number (1 to 10): " );
scanf ( "%d" ,&iGuess);
if (iSecret<iGuess) {
puts ( "The secret number is lower" );
noOfTurns++;}
else {
if (iSecret>iGuess) puts ( "The secret number is higher" );
noOfTurns++;}
} while (iSecret!=iGuess);
puts ( "Congratulations!" );
puts ("Completed in ");
cout<<noOfTurns;
puts (" turns");
return 0;
}
