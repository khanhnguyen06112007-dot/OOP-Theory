#include "function.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <iterator>
bool isPalindrome(const std::string &str) {
    std::string res = "";
    std::copy_if(str.begin(), str.end(), std::back_inserter(res), [](char c) {
        return std::isalnum(c);
    });
    
    std::transform(res.begin(), res.end(), res.begin(), [](char c){
        return std::tolower(c);
    });

    bool it = std::equal(res.begin(), res.begin() + res.size() / 2, res.rbegin());
    return it;
}