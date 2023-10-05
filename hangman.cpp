/* Lucas Hartfiel 
 *
 * This program is a simple hangman game.
 * There are 50 randomly selected words in the file and one is randomly selected when the code
 * gets run. The user is allowed 5 incorrect guesses before the game is over. If the user
 * guesses the word before their 5th incorrect guess, the user wins.
 *
 * TODO: Import an English dictionary library and expand on the number of available words
 * TODO: Fix case sensitivity (currently only lowercase accepted
 */


#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>

using namespace std;

string words[50] = {"plastic","dismissal","neglect","cassette","electron","experiment","thinker","vertical"
,"symptom","decline","recommend","password","admiration","excitement","constraint","organization",
"compartment","crusade","accompany","cathedral","laundry","whisper","depression","miserable","absorption",
"secretion","distance","sequence","entertain","temperature","aviation","anxiety","profession","dimension",
"organize","talkative","promotion","accident","consider","functional","storage","orchestra","secretary",
"finished","concrete","innocent","discourage","assertive","consultation","implication"};


int main(){
    srand(time(0));
    int randomInt = rand() % 50;    
    string hWord = words[randomInt];
    int lives = 5;
    bool notGuessed = true;
    string currentGuess = "";
    char guess;
    for(int i = 0; i < hWord.size(); i++){
        currentGuess += "_";
    }

    while(notGuessed){
        if(currentGuess == hWord){
            cout << hWord << "\n";
            cout << "You win!\n";
            return 0;
        }
        if(lives == 0){
            cout << "You lose :(\n";
            cout << "The word was " << hWord << "\n";
            return 0;
        }
        cout << "You have " << lives << " guesses.\n";
        cout << currentGuess << "\n\n";
        bool inWord = false;
        cin >> guess;
        int found = hWord.find(guess);
        if(found < hWord.size()){
            for(int i = 0; i < hWord.size(); i++){
                if(hWord[i] == guess){
                    currentGuess[i] = guess;
                }
                inWord = true;
            }
        }
        else{
            lives--;
        }
        cout << "\n";
    } 
    return 0;
}
