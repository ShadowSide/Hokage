// AllSubsets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iterator>
#include <set>
#include <iostream>
#include <conio.h>

bool nextSubset(size_t amount, std::set<size_t>& subset)
{
	auto carryPos = -1;
	auto beforeCarry = std::find_if(subset.cbegin(), subset.cend(), [&](size_t place) 
	{
		bool needCarry = place != carryPos+1;
		if(!needCarry)
			carryPos = place;
		return needCarry;
	});
	subset.erase(subset.cbegin(), beforeCarry);
	subset.insert(carryPos + 1);
	bool ended = carryPos + 1 == amount;
	if(ended)
		subset.clear();
	return !ended;
}

int main()
{
	int i = 0;
	std::generate_n(std::ostream_iterator<size_t>(std::cout, " "), 10, [&] { return i++; });
	std::cout << std::endl;
	std::set<size_t> currentSubset;
	do
	{
		if (currentSubset.size() != 5)
			continue;
		std::copy(currentSubset.cbegin(), currentSubset.cend(), std::ostream_iterator<size_t>(std::cout, " "));
		std::cout << std::endl;
	} while (nextSubset(10, currentSubset));
	_getch();
    return 0;
}

