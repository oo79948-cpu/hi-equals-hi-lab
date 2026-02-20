#include <iostream>

#include "cmake-build-debug/_deps/catch2-src/src/catch2/internal/catch_stdstreams.hpp"
#include "src/hello.hpp"

int main() {

  while (true) {
    std::string string1, string2, skipSpaces, answer;
    int maxCharacters;

    std::cout << "Input the first string to compare: ";
    std::getline(std::cin, string1);
    std::cout << "Input the second string to compare: ";
    std::getline(std::cin, string2);

    std::cout << "Do you want to skip spaces? Y/N: ";
    std::getline(std::cin, skipSpaces);
    std::cout << "What is the maximum number of characters to compare? (-1 if no limit): ";
    std::cin >> maxCharacters;

    bool skipSpacesBool = false;
    if (skipSpaces == "Y" || skipSpaces == "y" ) { skipSpacesBool = true; }

    std::cout << "Result: "<< strcmp_case_insensitive(string1, string2, skipSpacesBool, maxCharacters) << std::endl;
    std::cout << "Continue? Y/N: ";
    std::cin >> answer;

    if (answer == "N" || answer == "n") { break; }
  }
}
