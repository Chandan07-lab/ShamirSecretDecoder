#include "../include/sss.hpp"
#include <iostream>

int main() {
    try {
        std::string filename = "../testcases/input.json";
        std::string secret = sss::process_jsonfile(filename);
        std::cout << "Reconstructed Secret: " << secret << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
