#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>
#include <numeric>

const size_t DIMMENSION = 13;

//class Manager
//{
//public:
//	std::vector<int> GetMinimumView(uint32_t sum)
//	{
//		std::vector<int> output;
//		int ceils = sum / DIMMENSION;
//		if (ceils > 0)
//		{
//			output.resize(ceils);
//			std::fill_n(output.begin(), output.size(), DIMMENSION);
//		}
//		if (sum % DIMMENSION)
//			output.push_back(sum % DIMMENSION);
//		return output;
//	}
//
//	uint32_t GetUniqueCombinations(uint32_t sum)
//	{
//		std::vector<int> figure = GetMinimumView(sum);
//		if (auto it = m_combinations.find(figure); it != m_combinations.end())
//			return it->second;
//		else
//		{
//			uint32_t count = 0;
//			if (!figure.empty())
//			{
//				if (figure.size() == 1)
//				{
//					count++;
//					figure.front()--;
//					figure.push_back(1);
//				}
//				size_t pos = 0;
//				while (figure.front() > *std::next(figure.begin(), 1))
//				{
//					figure.front()--;
//					(*std::next(figure.begin(), 1))++;
//					uint32_t tCount = RecursiveCountCombinations(figure);
//					m_combinations[figure] = tCount;
//					count += tCount;
//				}
//			}
//			return count;
//		}
//	}
//
//private:
//
//	uint32_t RecursiveCountCombinations(std::vector<int> figure)
//	{
//		if (auto it = m_combinations.find(figure); it != m_combinations.end())
//		{
//			return it->second;
//		}
//		else
//		{
//
//		}
//	}
//
//private:
//	std::unordered_map<std::vector<int>, uint32_t> m_combinations;
//};


auto GetAvailableFigures()
{
	std::array<int, 6> figure = { 0, 0, 0, 0, 0, 0 };
	std::vector< std::array<int, 6>> availableFigures;
	uint64_t total = std::pow(DIMMENSION, 6);
	availableFigures.resize(total);

	uint64_t index = 0;
	while (figure.back() != DIMMENSION)
	{
		availableFigures[index++] = figure;
		figure[0]++;
		if (figure.front() == DIMMENSION)
		{
			figure.front() = 0;
			size_t order = 1;
			while (true)
			{
				if (order == figure.size())
				{
					figure.back() = DIMMENSION;
					break;
				}
				if (figure[order] + 1 < DIMMENSION)
				{
					figure[order]++;
					break;
				}
				else if (figure[order] + 1 == DIMMENSION)
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

// input 8

uint32_t CountCombinations(const std::array<int, 6>& key)
{
	uint32_t output = 0;
	std::vector<int> combination;

	uint32_t sum = std::accumulate(key.begin(), key.end(), 0);
	combination.push_back(sum);
	output++;
	while (true)
	{
		combination.push_back(1ul);
		if (sum - combination.size() > 0)
		{
			combination.front() = sum - combination.size();
			std::fill_n(combination.begin() + 1, combination.size() - 1, 1ul);
			size_t pos = 0;
		}
		else
			break;
	}
	return output;
}

int main() 
{
	std::unordered_map<uint32_t, std::vector<uint32_t>> unified;

	std::vector<std::array<int, 6>> availableFigures = GetAvailableFigures();

	uint64_t count = 0;
	return 0;
}