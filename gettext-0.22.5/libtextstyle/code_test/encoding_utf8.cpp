#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>  // For strerror
#include <cerrno>   // For errno
#include <cctype>   // For isprint

// Function to remove non-printable characters
std::string remove_non_printable(const std::string& str) {
    std::string result;
    for (char ch : str) {
        if (std::isprint(static_cast<unsigned char>(ch)) || std::isspace(static_cast<unsigned char>(ch))) {
            result += ch;
        }
    }
    return result;
}

void convert_ascii_to_utf8(const std::string& input_file, const std::string& output_file) {
    std::cout << "Trying to open input file: " << input_file << std::endl;

    // Open the input file
    std::ifstream infile(input_file, std::ios::binary);
    if (!infile.is_open()) {
        std::cerr << "Error opening input file: " << input_file << std::endl;
        std::cerr << "Error reason: " << std::strerror(errno) << std::endl;
        return;
    }

    // Read the input file into a string
    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
    infile.close();

    std::cout << "Input file opened successfully." << std::endl;

    // Remove non-printable characters
    content = remove_non_printable(content);

    // Open the output file
    std::ofstream outfile(output_file, std::ios::binary);
    if (!outfile.is_open()) {
        std::cerr << "Error opening output file: " << output_file << std::endl;
        std::cerr << "Error reason: " << std::strerror(errno) << std::endl;
        return;
    }

    // Write BOM for UTF-8 encoding
    unsigned char bom[] = {0xEF, 0xBB, 0xBF}; // UTF-8 BOM
    outfile.write(reinterpret_cast<char*>(bom), sizeof(bom));

    // Write the content to the output file
    outfile << content;
    outfile.close();

    std::cout << "Output file created successfully." << std::endl;
}

int main() {
    std::string input_file = "C:/msys64/components.xml";       // Absolute path in Windows style
    std::string output_file = "C:/msys64/components_utf8.xml"; // Absolute path in Windows style

    convert_ascii_to_utf8(input_file, output_file);

    return 0;
}
