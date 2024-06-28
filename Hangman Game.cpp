// Hangman Game.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int MAX_ATTEMPS = 6;

class Hangman {

public:

	Hangman() {
		srand(time(NULL));
		secret_word_ = GetRandomWord();
		current_word_ = string(secret_word_.length(), '_');
	}

	void Play() {
		while (MAX_ATTEMPS > 0) {
            DisplayGameInfo();
            char guess_letter;
            cout << "Guess the letter: "s;
            cin >> guess_letter;
            if (LetterAlreadyGuessed(guess_letter)) {
                cout << "You guessed this letter."s << endl;
            } else {
                bool correct_guess = UpdateCurrentWord(guess_letter);
                if (current_word_ == secret_word_) {
                    DisplayGameInfo();
                    cout << "Congratulations! Secret word was: "s << secret_word_ << endl;
                    return;
                }
                if (correct_guess) {
                    cout << "We have this letter!"s << endl;
                    system("cls");
                } else {
                    system("cls");
                    cout << "Word doesn't content this letter."s << endl;
                    --MAX_ATTEMPS;
                    DisplayGame();
                }
            }
		}
        cout << "You ran out of attemps..."s << endl;
        cout << "Secret word was: "s << secret_word_ << endl;
	}

private:

	string secret_word_;
	string current_word_;
	vector<char> guessed_letters_;
	vector<string> words = { "apple"s,"banana"s,"orange"s,"math"s,"car"s,"cat"s,"dog"s,"horse"s};

	string GetRandomWord() {
		int index_of_word = rand() % words.size();
		return words[index_of_word];
	}

	bool LetterAlreadyGuessed(char letter) {
		return find(guessed_letters_.begin(), guessed_letters_.end(), letter) != guessed_letters_.end();
	}

	bool UpdateCurrentWord(char letter) {
		bool correct_letter = false;
        for (int i = 0; i < secret_word_.size(); ++i) {
			if (secret_word_[i] == letter) {
				correct_letter = true;
                current_word_[i] = letter;
			}
		}
		guessed_letters_.push_back(letter);
		return correct_letter;
	}

	void DisplayGameInfo() {
		cout << "Word: "s << current_word_ << endl;
		cout << "You have "s << MAX_ATTEMPS << " attemps left."s << endl;
		cout << "Guessed letters: "s;
		for (char& ch : guessed_letters_) {
			cout << ch << " "s;
		}
		cout << endl;
	}

	void DisplayGame() {
        if (MAX_ATTEMPS == 5) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (MAX_ATTEMPS == 4) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |     |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (MAX_ATTEMPS == 3) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (MAX_ATTEMPS == 2) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|\\" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (MAX_ATTEMPS == 1) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|\\" << endl;
            cout << "  |    /" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (MAX_ATTEMPS == 0) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|\\" << endl;
            cout << "  |    / \\" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
	}

};

int main()
{
    Hangman game;
    game.Play();
   
}

