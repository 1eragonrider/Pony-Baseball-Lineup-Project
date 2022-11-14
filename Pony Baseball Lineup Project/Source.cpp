#include<iostream>
#include<string>
#include"Team.hpp"


int main()
{
	// Declarations
	Team* team = new Team();

	int menuChoice;
	std::string playerNameToDelete;
	std::string playerNameToAdd;
	int playerBattingAverage;

	bool exitProgram = false;
	bool exitFunction = false;
	std::string userProgressCommand;

	while (!exitProgram)
	{
		system("cls"); // clear command prompt

		// reset some variables
		exitFunction = false;
		userProgressCommand;

		// User input
		std::cout << "-----------   MAIN MENU   -----------" << std::endl;
		std::cout << "Please select one of the options" << std::endl;
		std::cout << "1. Add players to your team" << std::endl;
		std::cout << "2. Delete players from your team" << std::endl;
		std::cout << "3. How many players are in my team?" << std::endl;
		std::cout << "4. Generate game lineup and field positions" << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cout << "Choice: ";
		std::cin >> menuChoice;
		std::cout << std::endl << std::endl;

		// Output
		switch (menuChoice)
		{
		case 1:
			system("cls");
			while (!exitFunction)
			{
				system("cls");
				std::cout << "--- Adding a player ---" << std::endl;
				std::cout << "Player Name: ";
				std::cin >> playerNameToAdd;
				std::cout << "Player Batting Average: ";
				std::cin >> playerBattingAverage;
				std::cout << std::endl;

				team->AddPlayer(playerNameToAdd, playerBattingAverage);
				std::cout << "Player Successfully added to your team!" << std::endl;

				// check if user wants to continue
				std::cout << "Exit or Continue?";
				std::cin >> userProgressCommand;

				if (userProgressCommand == "exit" || userProgressCommand == "Exit" || userProgressCommand == "EXIT" || userProgressCommand == "Yes" || userProgressCommand == "yes")
				{
					exitFunction = true;
					break;
				}

			}
			break;
		case 2:
			system("cls");
			while (!exitFunction)
			{
				system("cls");
				std::cout << "--- Deleting a player ---" << std::endl;
				std::cout << "Player Name: ";
				std::cin >> playerNameToDelete;
				std::cout << std::endl;

				team->DeletePlayer(playerNameToDelete);

				// check if user wants to continue
				std::cout << "Exit or Continue?";
				std::cin >> userProgressCommand;

				if (userProgressCommand == "exit" || userProgressCommand == "Exit" || userProgressCommand == "EXIT")
				{
					exitFunction = true;
					break;
				}
			}
			break;
		case 3:
			system("cls");
			while (!exitFunction)
			{
				std::cout << "There are currently " << team->GetPlayerCount() << " players on your team." << std::endl << std::endl;

				// check if user wants to continue
				std::cout << "Exit or Continue?";
				std::cin >> userProgressCommand;

				if (userProgressCommand == "exit" || userProgressCommand == "Exit" || userProgressCommand == "EXIT")
				{
					exitFunction = true;
					break;
				}
			}
			break;
		case 4:
			system("cls");
			while (!exitFunction)
			{
				team->SortPlayers();
				team->AssignPlayerPositions();
				team->PrintPlayerLineup();

				// check if user wants to continue
				std::cout << "Exit or Continue?";
				std::cin >> userProgressCommand;

				if (userProgressCommand == "exit" || userProgressCommand == "Exit" || userProgressCommand == "EXIT")
				{
					exitFunction = true;
					break;
				}
			}
		case 5:
			system("cls");
			exitProgram = true;
			std::cout << "Exiting the program. Thank you!" << std::endl << std::endl << std::endl;
			break;
		default:
			break;
		}

		// while loop cleanup

		exitFunction = false;
		userProgressCommand;
	}
}