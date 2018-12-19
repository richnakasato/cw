/*
 * #Counting Duplicates
 *
 * #6 KYU
 *
 * -------------------------------------------------------------------------------
 *
 * # Description
 *
 * ### Count the number of Duplicates
 *
 * Write a function that will return the count of distinct case-insensitive
 * alphabetic characters and numeric digits that occur more than once in the input
 * string. The input string can be assumed to contain only alphabets (both
 * uppercase and lowercase) and numeric digits.
 *
 * ### Example
 *
 * "abcde" -> 0             # no characters repeats more than once "aabbcde" -> 2
 * # 'a' and 'b' "aabBcde" -> 2           # 'a' occurs twice and 'b' twice
 * (`b` and `B`) "indivisibility" -> 1    # 'i' occurs six times "Indivisibilities"
 * -> 2  # 'i' occurs seven times and 's' occurs twice "aA11" -> 2              #
 * 'a' and '1' "ABBA" -> 2              # 'A' and 'B' each occur twice
 *
 * -------------------------------------------------------------------------------
 *
 * # Provided code
 *
 *     function duplicateCount(text){
 *       //...
 *     }
 *
 * # Provided tests
 *
 *     Test.assertEquals(duplicateCount(""), 0);
 *     Test.assertEquals(duplicateCount("abcde"), 0);
 *     Test.assertEquals(duplicateCount("aabbcde"), 2);
 *     Test.assertEquals(duplicateCount("aabBcde"), 2,"should ignore case");
 *     Test.assertEquals(duplicateCount("Indivisibility"), 1)
 *     Test.assertEquals(duplicateCount("Indivisibilities"), 2, "characters may not be adjacent")
 *
 *
 * -------------------------------------------------------------------------------
 *
 * To print these instructions again, run: codewars print To verify your solution,
 * run: codewars verify solution.js
 */

#include<cassert>
#include<iostream>
#include<locale>
#include<string>
#include<tuple>
#include<unordered_set>
#include<vector>

int counting_duplicates(const std::string& str) {
    std::unordered_set<char> seen;
    std::unordered_set<char> dupe;
    for (const auto& c : str) {
        char temp = std::tolower(c, std::locale());
        if (seen.find(temp) == seen.end()) {
            seen.insert(temp);
        }
        else {
            dupe.insert(temp);
        }
    }
    return dupe.size();
}

int main() {
    std::tuple<std::string, int> temp {"", 0};
    std::vector<std::tuple<std::string, int>> tests
        {std::tuple<std::string,int>{"",0},
        std::tuple<std::string,int>{"abcde",0},
        std::tuple<std::string,int>{"abcde",0},
        std::tuple<std::string,int>{"aabbcde",2},
        std::tuple<std::string,int>{"aabBcde",2},
        std::tuple<std::string,int>{"Indivisibility",1},
        std::tuple<std::string,int>{"Indivisibilities",2}};
    for (const auto& test : tests) {
        assert(counting_duplicates(std::get<0>(test))==std::get<1>(test));
    }
    return 0;
}
