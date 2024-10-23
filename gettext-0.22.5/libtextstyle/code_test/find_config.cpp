#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

bool hasConfigInclude(const fs::path& filePath) {
    std::ifstream file(filePath);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("config.h") != std::string::npos) {
            return true;
        }
    }
    return false;
}

void insertConfigInclude(const fs::path& filePath) {
    std::ifstream file(filePath);
    std::string content;
    std::string line;

    // 파일의 모든 내용을 읽어들입니다.
    while (std::getline(file, line)) {
        content += line + "\n";
    }

    // 파일을 다시 열어 내용을 수정합니다.
    std::ofstream outFile(filePath);
    outFile << "#include \"config.h\"\n" << content;  // 첫 줄에 추가
}

int main() {
    fs::path directory = "./lib";  // 검색할 디렉토리
    std::string includeGuard = "stdio.h";

    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.path().extension() == ".h") {
            std::ifstream file(entry.path());
            std::string line;

            // 파일의 각 줄을 검사하여 stdio.h가 포함되어 있는지 확인
            while (std::getline(file, line)) {
                if (line.find(includeGuard) != std::string::npos) {
                    // "config.h"가 포함되지 않은 경우 삽입
                    if (!hasConfigInclude(entry.path())) {
                        insertConfigInclude(entry.path());
                        std::cout << "Inserted #include \"config.h\" in " << entry.path() << std::endl;
                    }
                    break; // 다음 파일로 이동
                }
            }
        }
    }

    return 0;
}
