#include "function.h"
#include <string>
#include <algorithm>
#include <cctype>

void removeSpaceFrontAndBack(std::string &str){
    auto start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) {
        str.clear(); 
        return;
    }
    size_t end = str.find_last_not_of(" \t\n\r");
    str = str.substr(start, end - start + 1);
}
void removeSpaceAndPunct(std::string &str){
    auto new_end = std::unique(str.begin(), str.end(), [](char a, char b) {
        return (std::isspace(a) && std::isspace(b)) || 
               (std::ispunct(a) && std::ispunct(b) && a == b);
    });
    str.erase(new_end, str.end());
}
void CaptilizeFirstLetter(std::string &str){
    bool capitalizeNext = true;
    
    std::transform(str.begin(), str.end(), str.begin(), [&capitalizeNext](char c) -> char {
        if (std::isalpha(c)) {
            if (capitalizeNext) {
                capitalizeNext = false;
                return (std::toupper(c));
            } else {
                return (std::tolower(c));
            }
        } else if (std::isspace(c)) {
            capitalizeNext = true;
        }
        return c;
    });

}

void normalizeString(std::string &str){
    removeSpaceFrontAndBack(str);
    removeSpaceAndPunct(str);
    CaptilizeFirstLetter(str);
}