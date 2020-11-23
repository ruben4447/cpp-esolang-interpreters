#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>

#include "lib/utils/files.cpp"
#include "lib/utils/time_ms.cpp"
#include "lib/befunge.cpp"

// int main(int argc, char *argv[])
int main()
{
    // char *c = argv[1];
    // std::string filename(c);
    std::string filename = "./examples/befunge/soe.bf";
    std::string program = get_file_contents(filename);

    std::chrono::milliseconds start = get_time_ms();
    int code = befunge::interpret(program);
    std::chrono::milliseconds elapsed = get_time_ms() - start;

    std::cout << std::endl << "--------------------------------------------------------" << std::endl;
    std::cout << "Execution Time: " << elapsed.count() << " ms" << std::endl;
    std::cout << "Exit Code: " << code << std::endl;

    return 0;
}