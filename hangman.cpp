#include <iostream>
using namespace std;
bool stringContains(string, char);
void updateWord(char, string, string&);
int maxStrikes = 7, win=0, lose = 0 , score =0;
void showScore();
void updateDisplay(string, string, int);

int main() {
	string actualWord = "computer";	//TODO: Change to dictionary work
	string completedWord = "", lettersUsed = "";

	for (char letter : actualWord)
		completedWord += "_";
	int strikes = maxStrikes;

	cout << "Hangman!\n"; 

	while(stringContains(completedWord, '_') && strikes > 0) {
	cout << completedWord << endl;

	char guess;
	cout << "your guess: ";
	cin >> guess;
	guess = tolower(guess);


	if (guess >= 97 && guess <= 122) {
		if (stringContains(lettersUsed, guess) || stringContains(completedWord, guess)) {
			cout << "you already tried the leter " << guess << endl;
		}

		else if (stringContains(actualWord, guess)) {
			cout << "Correct"<< endl;
			updateWord(guess, actualWord, completedWord);

		}
		else {
			cout << "you suck" <<endl;
			lettersUsed += guess;
			strikes--;
		}


	}
	else
		cout << "please type letters only" << endl;


	}
}
void showScore() {
	cout << "\nWins: : " << win << endl;
	cout << "Lose: " << lose << endl;
	cout << "Score: " << score < <endl;
}
void updateDisplay( string lettersUsed, string completedWord, int strikes) {
	cout << "yes" << endl;
}

bool stringContains(string text, char letter) {
	for (char character : text)
		if (character == letter)
			return true;
	return false;

}
void updateWord( char guess, string actualWord, string& completedWord) {
	for (int i = 0; i < actualWord.size(); i++)
			if (actualWord.at(i) == guess)
				completedWord = completedWord.substr(0,i) + guess + completedWord.substr(i+1, completedWord.length());

}
