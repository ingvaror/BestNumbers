#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>
#include <numeric>
#include <math.h>
#include <cassert>
#include <algorithm>

template<uint64_t RADIX, uint64_t COUNT_BEAUTIFUL_NUMBERS>
class BeautifulNumbers
{
public:
	uint64_t Count()
	{
		std::vector<std::array<int, COUNT_BEAUTIFUL_NUMBERS>> availableFigures = GetAvailableFigures();

		for (const auto& figure : availableFigures)
		{
			AddCombination(figure);
		}
		uint64_t count = 0;
		for (const auto& figure : availableFigures)
		{
			count += CountCombinations(figure);
		}
		return count;
	}

private:
	std::vector< std::array<int, COUNT_BEAUTIFUL_NUMBERS>> GetAvailableFigures()
	{
		std::array<int, COUNT_BEAUTIFUL_NUMBERS> figure;
		std::fill(figure.begin(), figure.end(), 0);
		std::vector< std::array<int, COUNT_BEAUTIFUL_NUMBERS>> availableFigures;
		uint64_t total = std::pow(RADIX, COUNT_BEAUTIFUL_NUMBERS);
		availableFigures.resize(total);

		uint64_t index = 0;
		while (figure.back() != RADIX)
		{
			availableFigures[index++] = figure;
			figure[0]++;
			if (figure.front() == RADIX)
			{
				figure.front() = 0;
				size_t order = 1;
				while (true)
				{
					if (order == figure.size())
					{
						figure.back() = RADIX;
						break;
					}
					if (figure[order] + 1 < RADIX)
					{
						figure[order]++;
						break;
					}
					else if (figure[order] + 1 == RADIX)
					{
						figure[order] = 0;
						order++;
					}
					else
						order++;
				}
			}
		}
		return availableFigures;
	}

	void AddCombination(const std::array<int, COUNT_BEAUTIFUL_NUMBERS>& figure)
	{
		m_combinations[std::accumulate(figure.begin(), figure.end(), 0)]++;
	}
	uint64_t CountCombinations(const std::array<int, COUNT_BEAUTIFUL_NUMBERS>& figure)
	{
		return m_combinations[std::accumulate(figure.begin(), figure.end(), 0)] * RADIX;
	}
private:
	std::unordered_map<int, uint64_t> m_combinations;
};

int main() 
{
	{
		BeautifulNumbers<2, 2> bestNumbers;
		assert(bestNumbers.Count() == 12);
	}
	{
		BeautifulNumbers<13, 6> bestNumbers;
		std::cout << bestNumbers.Count() << std::endl;
	}

	return 0;
}