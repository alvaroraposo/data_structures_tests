#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <cmath> 
#include <string_view>

using namespace std;

// Function to find Levenshtein Distance between string X and Y
// m and n are the number of characters in X and Y respectively
// int dist(string X, int m, string Y, int n)
// {
// 	// base case: empty strings (case 1)
// 	if (m == 0)
// 		return n;

// 	if (n == 0)
// 		return m;

// 	int cost;

// 	// if last characters of the strings match (case 2)
// 	if (X[m - 1] == Y[n - 1])
// 		cost = 0;
// 	else
// 		cost = 1;

//   int one = dist(X, m - 1, Y, n) + 1;
//   int two = dist(X, m, Y, n - 1) + 1;
//   int three = dist(X, m - 1, Y, n - 1) + cost;
  
// 	return min (min(one,  // deletion	(case 3a))
// 			two),		 // insertion (case 3b))
// 			three);  // substitution (case 2 & 3c)
// }

unsigned int edit_distance(const std::string& s1, const std::string& s2)
{
	const std::size_t len1 = s1.size(), len2 = s2.size();
	std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

	d[0][0] = 0;
	for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
	for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

	for(unsigned int i = 1; i <= len1; ++i)
		for(unsigned int j = 1; j <= len2; ++j)
                      // note that std::min({arg1, arg2, arg3}) works only in C++11,
                      // for C++98 use std::min(std::min(arg1, arg2), arg3)
                      d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
	return d[len1][len2];
}

int main()
{
	string X = "kitten", Y = "sitting";
  std::cin >> X >> Y;

	cout << edit_distance(X, Y) << std::endl;

	return 0;
}

