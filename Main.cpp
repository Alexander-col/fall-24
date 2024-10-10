#include <iostream>
#include "File.hpp"
// #include "Folder.hpp"
// #include "InvalidFormatException.hpp"
int main()
{

    std::cout << "I AM GOING TO KASHOOT MYSELF" << std::endl;
    
    int test = 26;
    int* test_ptr = &test;

    std::cout << *test_ptr << std::endl;
    File Alex("alexander.txt", "I like to code", test_ptr);
    std::cout << Alex << std::endl;

}