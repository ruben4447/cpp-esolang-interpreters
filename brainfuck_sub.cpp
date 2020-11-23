#include <iostream>
#include <string>
#include <chrono>

#include "lib/utils/files.cpp"
#include "lib/utils/time_ms.cpp"
#include "lib/brainfuck.cpp"

#include "lib/brainfuck-substitution.cpp"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "Args: [format] [src_file] [?dest_file]";
        exit(1);
    }

    brainfuck_sub_tables::init();

    char *tmp = argv[1];
    std::string sub_type(tmp);

    char *c = argv[2];
    std::string filename(c);
    std::string program = get_file_contents(filename);

    std::string output;
    int code = brainfuck::to_brainfuck(program, &output, sub_type);

    std::string dest_file = ""; // Default: output
    if (argc > 3) {
        char *c = argv[3];
        std::string tmp(c);
        dest_file = c;
    }

    if (code == 0) {
        std::cout << "----- [ PROGRAM ] ------" << std::endl;

        if (dest_file == "") {
            std::cout << output << std::endl;
        } else {
            put_file_contents(dest_file, output);
            std::cout << "Saved to file " << dest_file << std::endl;
            std::cout << "Length: " << output.length() << std::endl;
        }
    } else {
        std::cout << "----- [ ERROR ] -----" << std::endl;
        std::cout << "Exit Code: " << code << std::endl;
        std::cout << output << std::endl;
    }

    return 0;
}