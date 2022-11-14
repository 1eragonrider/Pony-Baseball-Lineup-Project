#ifndef _Team
#define _Team

#include"Team.hpp"
#include"PlayerNode.hpp"

class Team
{
private:
	PlayerNode* headPtr;
	int playerCount;
	PlayerNode* GetPlayerNode(std::string namePar) const;
public:
	Team();
	virtual ~Team();

	bool isEmpty();
	void Clear();
	int RandomNumberGen(int range);
	int GetPlayerCount();

	void AddPlayer(std::string namePar, int battingAveragePar);
	void DeletePlayer(std::string namePar);
	void SortPlayers();
	void AssignPlayerPositions();
	void PrintPlayerLineup();
};

#endif // !_Team

