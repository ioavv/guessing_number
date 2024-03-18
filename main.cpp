#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

bool playAgain();
int getMaxValue();
int getMaxAttempts();

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int maxValue, maxAttempts;
    bool playGame = true;

    while (playGame) {
        maxValue = getMaxValue();
        maxAttempts = getMaxAttempts();
        int randomNumber = rand() % maxValue + 1;
        int guess;
        int attempts = 0;
        bool won = false;

        cout << "Welcome to the Guessing Game!" << endl;
        cout << "I'm thinking of a number between 1 and " << maxValue << ". Can you guess it?" << endl;

        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess < randomNumber) {
                cout << "Too low! Try again." << endl;
            } else if (guess > randomNumber) {
                cout << "Too high! Try again." << endl;
            } else {
                cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
                won = true;
                break;
            }
        } while (attempts < maxAttempts);

        if (!won) {
            cout << "Sorry, you've reached the maximum number of attempts. The number was " << randomNumber << "." << endl;
        }

        playGame = playAgain();
    }

    return 0;
}

bool playAgain() {
    char choice;
    cout << "Would you like to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int getMaxValue() {
    int maxValue;
    cout << "Enter the maximum value for the random number: ";
    cin >> maxValue;
    return maxValue;
}

int getMaxAttempts() {
    int maxAttempts;
    cout << "Enter the maximum number of attempts: ";
    cin >> maxAttempts;
    return maxAttempts;
}