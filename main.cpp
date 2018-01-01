#include <algorithm>
#include <cctype>
#include <locale>
#include <iostream>

std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
}

int main()
{
    std::string strings[] = {"", " ", "test", " test", "test ", " test ", " test y", "\t test\n", "\v\f\r\ntest\f\vg"};
    const size_t n = sizeof(strings) / sizeof(std::string);
    for (unsigned int i = 0; i < n; ++i) {
        std::string str = strings[i];
        trim(str);
        std::cout << "\"" << str << "\"" << "\n";
    }
}
