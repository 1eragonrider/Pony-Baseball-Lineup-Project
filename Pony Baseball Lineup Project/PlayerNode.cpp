#include<iostream>
#include<string>
#include"PlayerNode.hpp"

PlayerNode::PlayerNode()
{
	name = "Not defined";
	battingAverage = 0;
	next = nullptr;
	for (int i = 0; i < 5; i++)
	{
		positionsPlayed[i] = "";
	}
}

// Functions dealing with Node Name Parameter
void PlayerNode::SetName(std::string inputPar)
{
	name = inputPar;
}

std::string PlayerNode::GetName()
{
	return name;
}

// Functions dealing with Node Batting Average Parameter
void PlayerNode::SetBattingAverage(int inputPar)
{
	battingAverage = inputPar;
}


int PlayerNode::GetBattingAverage()
{
	return battingAverage;
}

// Functions dealing with Node position Parameter
void PlayerNode::SetPosition(int inningNumberPar, std::string inputPar)
{
	positionsPlayed[inningNumberPar] = inputPar;
}

std::string PlayerNode::GetPosition(int inningNumberPar)
{
	return positionsPlayed[inningNumberPar];
}

// Functions dealing with Node pointer Parameter
void PlayerNode::SetNext(PlayerNode* nextPlayerPtr)
{
	next = nextPlayerPtr;
}

PlayerNode* PlayerNode::GetNext()
{
	return next;
}


