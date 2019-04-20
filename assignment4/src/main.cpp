#include <iostream>
#include <string>
#include "io.h"
#include "library.h"

int main(int argc, char **argv) {
    Library library;
    while (true) {
        printInstructions();
        std::string instruction;
        std::cout << "Input instruction: ";
        std::getline(std::cin, instruction, '\n');
        std::cout << "\n";
        handleInstructions(instruction, library);
        // TODO: Handle the input instructions.
    }
}
