#include <iostream>
#include <vector>
/*
 * sample noonabbad  noon | abba | d
the number of cuts needed is 2
 */

// time complexity o(n) space complexity o(1)
bool isPalindrome(std::string word) {
  int leftIdx = 0;
  int rightIdx = word.length() - 1;
  while (leftIdx < rightIdx) {
    if (word[leftIdx] != word[rightIdx]) {
      return false;
    }
    leftIdx ++;
    rightIdx --;
  }
  return true;
}

// time
int palindromePartitioningMinCuts(std::string string) {
  std::vector<std::vector<bool>> palindromes(string.length(), std::vector<bool>(string.length()));
  for (int i = 0; i < string.length(); ++i) {
    for (int j = i; j < string.length(); ++j) {
      palindromes[i][j] = isPalindrome(string.substr(i, j + 1 - i));
    }
  }

  std::vector<int> cuts(string.length(), INT_MAX);
  for (int i = 0; i < string.length(); ++i) {
    if (palindromes[0][i]) {
      cuts[i] = 0;
    } else {
      cuts[i] = cuts[i - 1] + 1;
      for (int j = 1; j < i; ++j) {
        if (palindromes[j][i] && cuts[j - 1] + 1 < cuts[i]) {
          cuts[i] = cuts[j - 1] + 1;
        }
      }
    }
  }
  for (auto cut: cuts) {
    std::cout<<cut << std::endl;
  }
  return cuts[string.length() - 1];
}

int main() {
  std::cout << "Palindrome min cuts" << std::endl;
  std::cout << palindromePartitioningMinCuts("noonabbad");
  return 0;
}