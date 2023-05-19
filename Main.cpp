#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
	std::string playerChoice, computerChoice;
	int result;
	char playAgain;

	srand(time(0));

	do {
		std::cout << "Welcome to Rock, Paper Scissors!\n";
		std::cout << "Enter your choice: ";
		std::cin >> playerChoice;

		// Convert player's choice to lowercase for comparison
		for (char& c : playerChoice) {
			c = std::tolower(c);
		}

		int randomNum = rand() % 3;

		if (randomNum == 0) {
			computerChoice = "rock";
		}
		else if (randomNum == 1) {
			computerChoice = "paper";
		}
		else {
			computerChoice = "scissors";
		}

		std::cout << "Player's choice: " << playerChoice << std::endl;
		std::cout << "Computer's choice: " << computerChoice << std::endl;

		if (playerChoice == computerChoice) {
			result = 0; //It's a tie
		}
		else if ((playerChoice == "rock" && computerChoice == "scissors") ||
			(playerChoice == "paper" && computerChoice == "rock") ||
			(playerChoice == "scissors" && computerChoice == "paper")) {
			result = 1; // Player wins
		}
		else {
			result = -1; // Computer wins
		}

		if (result == 0) {
			std::cout << "It's a tie!\n";
		}
		else if (result == 1) {
			std::cout << "You win!\n";
		}
		else {
			std::cout << "Computer wins!\n";
		}

		std::cout << "Do you want to play again? (y/n): ";
		std::cin >> playAgain;

		// Clear input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (playAgain == 'y' || playAgain == 'Y');

	return 0;
}
