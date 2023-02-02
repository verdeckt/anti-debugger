//////////////////////////////////////////
// Obfuscation
//////////////////////////////////////////

#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<char, char> code = {
    {'a', 'p'},
    {'b', 'o'},
    {'c', 'i'},
    {'d', 'u'},
    {'e', 'y'},
    {'f', 't'},
    {'g', 'r'},
    {'h', 'e'},
    {'i', 'w'},
    {'j', 'q'},
    {'k', 'j'},
    {'l', 'k'},
    {'m', 'b'},
    {'n', 'v'},
    {'o', 'g'},
    {'p', 'f'},
    {'q', 'd'},
    {'r', 's'},
    {'s', 'l'},
    {'t', 'a'},
    {'u', 'g'},
    {'v', 'f'},
    {'w', 'e'},
    {'x', 'r'},
    {'y', 't'},
    {'z', 'y'}
};

std::string Obfuscate(const std::string &input)
{
    std::string output;
    for (char c : input)
    {
        if (code.count(c) > 0)
        {
            output += code[c];
        }
        else
        {
            output += c;
        }
    }
    return output;
}

int main()
{
    std::string input = "hello world";
    std::string output = Obfuscate(input);

    std::cout << "Original input: " << input << std::endl;
    std::cout << "Obfuscated output: " << output << std::endl;

    return 0;
}
