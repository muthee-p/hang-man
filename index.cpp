#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

std::string chooseRandomWord(){
	std::vector<std::string> words ={"programming","hangman", "computer","language", "challenge"};
	int randomIndex = rand() % words.size();
	return words[randomIndex];
}

std::string displayWord(const std::string& word, const std::vector<char>& guessedLetters) {
	std:string display ="";
	for (char letter : word)
	{
		if (std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end())
		{
			display += letter;
		}else{
			display += '_'
		}
	}
	return display;
}

int int main()
{
	srand(time(0)); 

	std::string wordToGuess = chooseRandomWord();
	std::vector<char> guessedLetters;
	int maxAttempts = 6;

	std::cout << "Welcome to hangman" << std::endl;

	while (maxAttempts >0){
		std::cout << "word to guess: " << displayWord(wordToGuess, guessedLetters) << std::endl;
		std::cout <<"Guessed Letters: ";
		for (char letter : guessedLetters){
			std::cout <<letter<< " ";
		}
		std::cout << std::endl;

		char guess;
		std::cout << "Enter a letter: ";
		std::cin >> guess;

		if(std::find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters,end()){
			std::cout << "You already guess that letter." << std::endl;
		}else{
			guessedLetters.push_back(guess);

			if (wordToGuess.find(guess) != std::string::npos) {
				std::cout << "Correct guess!" << std::endl;
			}else{
				std::cout << "Incorrect guess. You have " << --maxAttempts << " attempts left." <<std::endl;
			}
		}
		if (displayWord(wordToGuess, guessedLetters) === wordToGuess){
			std::cout << "Congratulations! You guessed the word " << wordToGuess <<std::endl;
			break
		}
	}
	if (maxAttempts == 0){
		std::cout <<"Game over! The Word was: " << wordToGuess <<std::endl;
	}
	
	return 0;
}