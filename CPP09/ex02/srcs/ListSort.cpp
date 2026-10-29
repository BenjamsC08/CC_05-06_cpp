#include <cstddef>
#include <utility>
#include <vector>

#include "ListIdx.hpp"
#include "ListSort.hpp"

void	jacob(std::pair<size_t, size_t> &i)
{
	size_t tmp = i.second;
	i.second +=  i.first * 2;
	i.first = tmp;
}

void	sortVec(std::vector<int> &tab)
{
	std::vector<std::pair<int, int> > matchPairs;
	std::vector<int> winner;

	int tmp = deepDive(tab, winner, matchPairs);
	if (winner.size() > 2)
		sortVec(winner);
	else if (winner.size() == 2 && winner[0] > winner[1])
	{
		int tmp0 = winner[0];
		winner[0] = winner[1];
		winner[1] = tmp0;
	}
	tab = remontada(winner, matchPairs, tmp);
}

void	sortList(ListIdx<int> &tab)
{
	ListIdx<std::pair<int, int> > matchPairs;
	ListIdx<int> winner;

	int tmp = deepDive(tab, winner, matchPairs);
	if (winner.size() > 2)
		sortList(winner);
	else if (winner.size() == 2 && winner[0] > winner[1])
	{
		int tmp0 = winner[0];
		winner[0] = winner[1];
		winner[1] = tmp0;
	}
	tab = remontada(winner, matchPairs, tmp);
}

