#include <iostream>

void checkCStandard() {
    #if __STDC_VERSION__ >= 201710L
        std::cout << "C17 or later is supported." << std::endl;
    #elif __STDC_VERSION__ >= 201112L
        std::cout << "C11 is supported." << std::endl;
    #elif __STDC_VERSION__ >= 199901L
        std::cout << "C99 is supported." << std::endl;
    #else
        std::cout << "Older than C99." << std::endl;
    #endif
}

void checkCppStandard() {
    #if __cplusplus >= 202002L
        std::cout << "C++20 or later is supported." << std::endl;
    #elif __cplusplus >= 201703L
        std::cout << "C++17 is supported." << std::endl;
    #elif __cplusplus >= 201402L
        std::cout << "C++14 is supported." << std::endl;
    #elif __cplusplus >= 201103L
        std::cout << "C++11 is supported." << std::endl;
    #elif __cplusplus >= 199711L
        std::cout << "C++98 is supported." << std::endl;
    #else
        std::cout << "Older than C++98." << std::endl;
    #endif
}

int main() {
    std::cout << "Checking C standard support..." << std::endl;
    checkCStandard();

    std::cout << "Checking C++ standard support..." << std::endl;
    checkCppStandard();

    return 0;
}
