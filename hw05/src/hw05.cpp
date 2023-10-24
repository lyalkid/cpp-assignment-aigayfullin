//#include <hw05.h>
#include <vector>
#include <string> 
using VecOfStr = std::vector<std::string>;


VecOfStr hw05(const VecOfStr& strings) {
    auto process_string = [](const std::string& str) -> std::string {
        std::string result;
        for (const auto& ch : str) {
            if (std::isalnum(ch)) {
                result += std::tolower(ch);
            }
        }
        return result;
    };

    VecOfStr result;
    for (const auto& str : strings) {
        std::string processed_str = process_string(str);
        bool is_palindrome = true;
        auto left = processed_str.begin();
        auto right = processed_str.rbegin();
        while (left != processed_str.end() && right != processed_str.rend()) {
            if (*left != *right) {
                is_palindrome = false;
                break;
            }
            ++left;
            ++right;
        }
        if (is_palindrome) {
            result.push_back(str);
        }
    }
    return result;
}