#include<iostream>
#include<string>
#include <time.h>
#include"Team.hpp"

// Constructors and Destructors
Team::Team()
{
	headPtr = nullptr;
	playerCount = 0;
}

Team::~Team()
{
	Clear();
}



// Team->Player Node Acccessor Functions
PlayerNode* Team::GetPlayerNode(std::string namePar) const
{
	PlayerNode* currentNode = headPtr;
	while (currentNode->GetName() != namePar)
	{
		currentNode = currentNode->GetNext();
	}
	return currentNode;
}



// General use functions
bool Team::isEmpty()
{
	if (playerCount == 0)
		return true;
	else
		return false;
}

void Team::Clear()
{
	while (headPtr != nullptr)
	{
		PlayerNode* NodeToDelete = headPtr;
		headPtr = headPtr->GetNext();

		delete NodeToDelete;
		NodeToDelete = nullptr;
	}
}

int Team::RandomNumberGen(int range)
{
	int i, number;
	time_t nTime;
	srand((unsigned)time(&nTime));

	return rand() % range;
}

int Team::GetPlayerCount()
{
	return playerCount;
}



// Generation Functions
void Team::AddPlayer(std::string namePar, int battingAveragePar)
{
	PlayerNode* newPlayerPtr = new PlayerNode();

	// if the team is empty (adding your first member)
	if (isEmpty())
	{
		newPlayerPtr->SetName(namePar);
		newPlayerPtr->SetBattingAverage(battingAveragePar);
		newPlayerPtr->SetNext(nullptr);
		headPtr = newPlayerPtr;
		playerCount += 1;
	}
	else // if the team has at least 1 member
	{
		PlayerNode* lastPlayerPtr = headPtr;

		while (lastPlayerPtr->GetNext() != nullptr)
		{
			lastPlayerPtr = lastPlayerPtr->GetNext();
		} // iterates until we get to the last player

		newPlayerPtr->SetNext(lastPlayerPtr->GetNext()); // sets the next of the new player to nullptr
		lastPlayerPtr->SetNext(newPlayerPtr); // sets the last player next to be the new player

		newPlayerPtr->SetName(namePar);
		newPlayerPtr->SetBattingAverage(battingAveragePar);
		playerCount += 1;
	}
}

void Team::DeletePlayer(std::string namePar)
{
	// if the team is empty
	if (isEmpty())
	{
		std::cout << "There are no players in this list" << std::endl << std::endl;
	}

	PlayerNode* PlayerToDeletePtr = headPtr;

	// if you are trying to delete the only member of a team and the name matches
	if (PlayerToDeletePtr->GetName() == namePar && PlayerToDeletePtr->GetNext() == nullptr)
	{
		Clear();
		return;
	}
	// if you are trying to delete the only member of a team and the name does not match
	else if (PlayerToDeletePtr->GetName() != namePar && PlayerToDeletePtr->GetNext() == nullptr)
	{
		std::cout << "There is only one (1) player in your team: " << headPtr->GetName() << std::endl;
		return;
	}

	// if you are deleting from a team with more than 1 member
	PlayerNode* PrevPlayerPtr = headPtr;
	PlayerToDeletePtr = PlayerToDeletePtr->GetNext();

	while (PlayerToDeletePtr->GetName() != namePar)
	{
		PrevPlayerPtr = PrevPlayerPtr->GetNext();
		PlayerToDeletePtr = PlayerToDeletePtr->GetNext();

		// if the player isn't in the team
		if (PlayerToDeletePtr == nullptr)
		{
			std::cout << "The player you requested to delete is not in the team: " << headPtr->GetName() << std::endl;
			return;
		}
	}

	PrevPlayerPtr->SetNext(PlayerToDeletePtr->GetNext());
	PlayerToDeletePtr->SetNext(nullptr);
	delete PlayerToDeletePtr;
	PlayerToDeletePtr = nullptr;
	playerCount--;
}

void Team::SortPlayers() // sorts players on team by batting average (highest to lowest)
{
	if (isEmpty())
	{
		return;
	}
	bool swap = false;
	bool sorted = false;
	while (!sorted)
	{
		swap = false;
		PlayerNode* playerB = headPtr;
		PlayerNode* playerC = headPtr->GetNext();

		while (!swap)
		{
			// if player B is greater than player A (in other words the pair is sorted) and we haven't reached the end of the list
			if ((playerB->GetBattingAverage() > playerC->GetBattingAverage()) && (playerC->GetNext() != nullptr))
			{
				playerB = playerB->GetNext();
				playerC = playerC->GetNext();
			}
			// if we reached the end of the list
			if (playerC->GetNext() == nullptr)
			{
				sorted = true;
				break;
			}
			// if Player B is less than Player A (in other words the pair is not sorted)
			if (playerB->GetBattingAverage() < playerC->GetBattingAverage())
			{
				// create a node and move it to just before Player A
				PlayerNode* playerA = headPtr;
				while (playerA->GetNext() != playerB)
				{
					playerA = playerA->GetNext();
				}

				// swap players B and C
				// Player A Links to Player B link (which is C)
				playerA->SetNext(playerB->GetNext());
				// Player B links to player C link (Which is the next node/nullptr)
				playerB->SetNext(playerC->GetNext());
				// Player C links to player B
				playerC->SetNext(playerB);

				swap = true;
			}
		}
	}
}

void Team::AssignPlayerPositions()
{
	/*
	* if I roll a random number between 1 and 100 and its even we assign a random infield position, odd we assign a random outfield position (DONE)
	*	How?
	* we roll a number between 1 and 6 and assign the member of the cooresponding array to the players position played array (DONE)
	* we compare the players position played array to inning assigned positions array if it was already assigned we re roll (DONE)
	* we store the position played in the inning assigned array (DONE)
	*
	* repeat in a while loop until the number of assignments made to the inning assigned array is 12 (counter) (number of players to be assigned) continue loop  (DONE)
	* 
	* 
	* (DONE)(DONE)(DONE)(DONE)
	* The next iteration we check if the second member of the player position played array is empty (DONE) -- edit we changed this to a for loop over head structure
	* if it is empty we flip a boolean rotateFieldPosition from false to true which bypasses the rand number generator and does the following instead
	* checks the first position to see if its a member infieldPositions, if it is we set the number to 2. Otherwise we set it to 1.
	* 
	* code proceeds as normal.
	*/


	// Declarations
	std::string infieldPositions[6] = { "P   ", "C   ", "1B  ", "2B  ", "3B  ", "SS  " };
	std::string outfieldPositions[6] = { "LF  ", "LCF ", "RCF ", "RF  ","OUT1","OUT2" };
	std::string positionToAdd;
	int randomNumber1;
	int randomNumber2;
	

	for (int inning = 1; inning <= 5; inning++)
	{
		// resets the position of the node to the first node
		PlayerNode* playerToAssignPosition = headPtr;

		// resets the array which stores the assigned positions in the inning
		std::string inningAssignedPositions[12];

		// resets the loop counter for the inning
		int loopCounter = 0;

		while (loopCounter < playerCount)
		{

			// check if its the second inning so we can skip the number generation
			if (inning == 2)
			{
				// check if the previous position is infield
				for (int i = 0; i < 6; i++)
				{
					if (playerToAssignPosition->GetPosition(0) == infieldPositions[i])
						randomNumber1 = 1; // we set it to odd so the next position will be outfield
				}
				randomNumber1 = 2; // we set it to even so the next position will be infield

				goto SKIPRANDNUMBER; // skips the random generation of the randomNumber1
			}


			// Generate a random number between 1 and 100 
			// check even/odd, infield/outfield
			// random number 1 to 6 for assignment

			randomNumber1 = RandomNumberGen(100);

			SKIPRANDNUMBER:
			if (randomNumber1 % 2 == 0) // even
			{
				randomNumber2 = RandomNumberGen(6);
				positionToAdd = infieldPositions[randomNumber2];
			}
			else // odd
			{
				randomNumber2 = RandomNumberGen(6);
				positionToAdd = outfieldPositions[randomNumber2];
			}
			

			// check whether its already assigned to inning played restart while loop if it is.

			for (int i = 0; i < playerCount; i++)
			{
				if (positionToAdd == inningAssignedPositions[i])
				{
					continue; // restarts while loop if and only if the positionToAdd has allready been assigned in this inning
				}
			}

			// Check whether the position to assign has already been played by the player

			for (int i = 0; i < 5; i++)
			{
				if (positionToAdd == playerToAssignPosition->GetPosition(i))
				{
					continue; // restarts while loop if and only if the positionToAdd has allready been assigned to the player
				}
			}


			// Modifies the current players positionsPlayed array
			playerToAssignPosition->SetPosition(inning, positionToAdd);

			// Add the position to the positionPlayed
			inningAssignedPositions[loopCounter] = positionToAdd;

			// go to the next node
			playerToAssignPosition = playerToAssignPosition->GetNext();

			// increment the loop counter
			loopCounter++;
		}
	}
}

void Team::PrintPlayerLineup()
{
	// inititialize to the head node
	PlayerNode* playerToPrint = headPtr;

	int nameLength = playerToPrint->GetName().length();
	int numSpacesToPrint = 10 - nameLength;
	std::string spaces;
	for (int i = 0; i < numSpacesToPrint; i++)
	{
		spaces.append(" ");
	}

	for (int player = 1; player <= playerCount; player++)
	{
		std::cout << "Game lineup and field positions:" << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << "Name      " << "Inning 1  " << "Inning 2  " << "Inning 3  " << "Inning 4  " << "Inning 5  " << std::endl;

		std::cout << playerToPrint->GetName() << spaces
			<< playerToPrint->GetPosition(0) << "      "
			<< playerToPrint->GetPosition(0) << "      "
			<< playerToPrint->GetPosition(0) << "      "
			<< playerToPrint->GetPosition(0) << "      "
			<< playerToPrint->GetPosition(0) << "      "
			<< std::endl;

		// go to the next player/line
		playerToPrint = playerToPrint->GetNext();
	}
}

