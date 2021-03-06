// NNCombs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <conio.h>

using It = std::vector<size_t>::const_iterator;

/*std::vector<size_t> recomb(It b, It e)
{
	if (b == e)
		return;
	auto item = *b;
	size_t length = std::distance(b, e);
	auto remainder = recomb(b+1, e);
}*/

namespace std {
	template<class It>
	bool nxt_permutation(It b, It e)
	{
		if (b == e)
			return false;
		auto l = e-1;
		if (b == l)
			return false;
		auto c = l - 1;
		while (true)
		{
			if (*c < *(c + 1))
			{
				auto n = l;
				while (*n <= *c)
					--n;
				std::iter_swap(c, n);
				std::reverse(c + 1, e);
				return true;
			}
			if (c == b)
			{
				std::reverse(b, e);
				return false;
			}
			c--;
		}
		return false;
	}
}

void impl1(size_t max)
{
	std::vector<size_t> s(max, 0);
	size_t last = 0;
	std::generate(s.begin(), s.end(), [&] {	return last++; });
	s.push_back(3);
	std::copy(s.begin(), s.end(), std::ostream_iterator<size_t>(std::cout, " "));
	std::vector<size_t> s1(s.cbegin(), s.cend());
	std::cout << std::endl;
	std::cout << std::endl;

	std::sort(s.begin(), s.end());
	std::sort(s1.begin(), s1.end());
	do
	{
		std::copy(s.begin(), s.end(), std::ostream_iterator<size_t>(std::cout, " "));
		std::cout << std::endl;
		std::copy(s1.begin(), s1.end(), std::ostream_iterator<size_t>(std::cout, " "));
		std::cout << std::endl;

		_getch();
	} while (std::next_permutation(s.begin(), s.end()) && std::nxt_permutation(s1.begin(), s1.end()));
}

int main()
{
	impl1(5);
	_getch();
    return 0;
}

