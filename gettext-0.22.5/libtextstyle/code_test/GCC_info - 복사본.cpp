#include <iostream>
#include <cstdlib>
#include <array>
#include <memory>
#include <string>
#include <fstream>

bool checkGccFeature(const std::string& stdFlag, bool isCpp = false) {
    // 임시 소스 파일 작성
    std::ofstream sourceFile("temp.c");
    sourceFile << "#include <stdio.h>\n"
               << "int main() { return 0; }\n";
    sourceFile.close();

    // C 표준 확인은 gcc 사용, C++ 표준 확인은 g++ 사용
    std::string compilerCommand = isCpp ? "g++" : "gcc";
    std::string command = compilerCommand + " -o check_gcc_feature -std=" + stdFlag + " temp.c";
    int result = std::system(command.c_str());

    // 임시 파일 삭제
    std::remove("temp.c");
    std::remove("check_gcc_feature");

    return (result == 0);  // 0이면 성공
}

int main() {
    std::cout << "Checking C language standard support..." << std::endl;

    // C Standard Checks
    std::cout << "Checking for C99 support..." << std::endl;
    if (checkGccFeature("c99")) {
        std::cout << "C99 Supported: Yes" << std::endl;
    } else {
        std::cout << "C99 Supported: No" << std::endl;
    }

    std::cout << "Checking for C11 support..." << std::endl;
    if (checkGccFeature("c11")) {
        std::cout << "C11 Supported: Yes" << std::endl;
    } else {
        std::cout << "C11 Supported: No" << std::endl;
    }

    std::cout << "Checking for C17 support..." << std::endl;
    if (checkGccFeature("c17")) {
        std::cout << "C17 Supported: Yes" << std::endl;
    } else {
        std::cout << "C17 Supported: No" << std::endl;
    }

    std::cout << "Checking C++ language standard support..." << std::endl;

    // C++ Standard Checks
    std::cout << "Checking for C++98 support..." << std::endl;
    if (checkGccFeature("c++98", true)) {
        std::cout << "C++98 Supported: Yes" << std::endl;
    } else {
        std::cout << "C++98 Supported: No" << std::endl;
    }

    std::cout << "Checking for C++11 support..." << std::endl;
    if (checkGccFeature("c++11", true)) {
        std::cout << "C++11 Supported: Yes" << std::endl;
    } else {
        std::cout << "C++11 Supported: No" << std::endl;
    }

    std::cout << "Checking for C++14 support..." << std::endl;
    if (checkGccFeature("c++14", true)) {
        std::cout << "C++14 Supported: Yes" << std::endl;
    } else {
        std::cout << "C++14 Supported: No" << std::endl;
    }

    std::cout << "Checking for C++17 support..." << std::endl;
    if (checkGccFeature("c++17", true)) {
        std::cout << "C++17 Supported: Yes" << std::endl;
    } else {
        std::cout << "C++17 Supported: No" << std::endl;
    }

    std::cout << "Checking for C++20 support..." << std::endl;
    if (checkGccFeature("c++20", true)) {
        std::cout << "C++20 Supported: Yes" << std::endl;
    } else {
        std::cout << "C++20 Supported: No" << std::endl;
    }

    return 0;
}
