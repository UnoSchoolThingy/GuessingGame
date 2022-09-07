/*
* Uno Pasadhika
* Guessing Game - Try to guess a number that the computer randomly generates
* 9/7/2022 
*/

// No global variables 
// No strings 
// Include iostream not stdio 

#include <iostream>
#include <cstring>

using namespace std;

// Check if char array is a number 
inline bool isNumber(char* in) {
    for (int i = 0; i < 5; i++) {
        if (in[i] == 0) break; // null terminated 
        if (!isdigit(in[i])) return false;
    }
    return true;
}

int main()
{
    char s[5]; // store user input
    int guess, num; // numbers 
    srand(time(NULL)); // set random seed 
    while (true) {
        num = rand() % 101; // Between 0 and 100 
        bool cont = false;
        int guesses = 0;
        while (!cont) {
            cout << "Enter a number between 0 and 100, inclusive: "; // prompt user for input 
            cin >> s;
            try { // Probably don't need try catch but putting here anyway 
                if (!isNumber(s)) { // Check if the input is actually a number 
                    cout << "That's not a number between 0 and 100!\n";
                    continue;
                }
                guess = atoi(s); // convert to int 
                if (guess >= 0 && guess <= 100) {
                    guesses++;
                    if (guess == num) {
                        cout << "You guessed the number in " << guesses << " tries!\n";
                        cont = true;
                    }
                    else {
                        cout << ((guess < num) ? "Too low!" : "Too high!") << "\n";
                    }
                }
                else {
                    cout << "That's not a number between 0 and 100!\n";
                }
            }
            catch (...) {
                cout << "That's not a number between 0 and 100!\n";
            }
        }
        // Does the user want to play again 
        cout << "Would you like to play again? (y/n)\n";
        char in;
        cin >> in;
        if (tolower(in) != 'y') break; // if the user doesn't type 'y' we just assume they typed n 
    }
    cout << "Thanks for playing!\n";
}
