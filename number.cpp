#include <iostream>
#include <cstdlib>        // for rand() and srand()   Generate and initialize random number
#include <ctime>          // for time()          manupulate date and time

using namespace std;

int main() 
{
    srand(static_cast<unsigned int>(time(0)));                  // seed for random number generation
    int secretNumber = rand() % 100 + 1;                        // generate secret number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game !!\n";
    cout << "Guess a number between 1 and 100\n";

    do {
        cout << "Enter Your Guess : ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) 
        {
            cout << "Too low! Try again.\n";
        } 
        else if (guess > secretNumber)
        {
            cout << "Too high! Try again.\n";
        } 
        else 
        {
            cout << "Congratulations !!! You guessed the correct number in " << attempts << " attempts.\n";
        }
      } 
      while (guess != secretNumber);

    return 0;
}
