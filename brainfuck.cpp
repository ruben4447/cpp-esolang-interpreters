#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>

#include "src/utils/files.cpp"
#include "src/utils/time_ms.cpp"
#include "src/brainfuck.cpp"

#include "src/brainfuck-substitution.cpp"

int main(int argc, char *argv[])
{
    char *c = argv[1];
    std::string filename(c);
    std::string program = get_file_contents(filename);

    std::chrono::milliseconds start = get_time_ms();
    int code = brainfuck::interpret(program);
    std::chrono::milliseconds elapsed = get_time_ms() - start;

    std::cout << std::endl << "--------------------------------------------------------" << std::endl;
    std::cout << "Execution Time: " << elapsed.count() << " ms" << std::endl;
    std::cout << "Exit Code: " << code << std::endl;

    return 0;
}