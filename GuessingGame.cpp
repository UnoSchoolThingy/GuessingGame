/*
* Uno Pasadhika
* C++ Programming DC
* Guessing Game - Try to guess a number that the computer randomly generates
*/

// No global variables
// No strings
// Include iostream not stdio

#include <iostream>
#include <cstring>

using namespace std;

inline bool isNumber(char* in) {
    char arr[5];
    memcpy(arr, in, 5);
    for (char c : arr) {
        if (c == 0) break;
        if (!isdigit(c)) return false;
    }
    return true;
}

int main()
{
    char s[5];
    int guess, num;
    srand(time(NULL));
    while (true) {
        num = rand() % 101;
        bool cont = false;
        int guesses = 0;
        while (!cont) {
            cout << "Enter a number between 0 and 100, inclusive: ";
            cin >> s;
            try {
                if (!isNumber(s)) {
                    cout << "That's not a number!\n";
                    continue;
                }
                guess = atoi(s);
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
        cout << "Would you like to play again? (y/n)\n";
        char in;
        cin >> in;
        if (tolower(in) != 'y') break;
    }
    cout << "Thanks for playing!\n";
}
