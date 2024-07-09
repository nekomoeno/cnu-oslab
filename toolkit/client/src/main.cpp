#include <stdio.h>
#include "iostream"

int icount = 1;

int main(int argc, char* argv[])
{
    int i, b;

    if (argc == 2) {
        icount = std::stoi(argv[1]);
    }

    i = icount;
    while (i > -1) {
        b = 5 / i;
        printf(" 5 / %d = %d \n", i, b);
        i--;
    }

    std::cout << "Finished" << std::endl;
    return 0;
}
 