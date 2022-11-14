#ifndef _PLAYER_NODE
#define _PLAYER_NODE

#include<iostream>

class PlayerNode
{
private:
	std::string name;
	int battingAverage;
	std::string positionsPlayed[5];
	PlayerNode* next;

public:
	PlayerNode();

	void SetName(std::string inputPar);
	std::string GetName();

	void SetBattingAverage(int inputPar);
	int GetBattingAverage();

	void SetPosition(int inningNumberPar, std::string inputPar);
	std::string GetPosition(int inningNumberPar);

	void SetNext(PlayerNode* nextPlayerPtr);
	PlayerNode* GetNext();
};

#endif // !_PLAYER_NODE

