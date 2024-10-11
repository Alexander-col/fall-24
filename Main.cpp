#include <iostream>
#include "File.hpp"
#include "Folder.hpp"

int main() 
{
    // Create an icon array
    int icon[256];
    for (size_t i = 0; i < 256; ++i) 
    {
        icon[i] = i; // Initialize with values for demonstration
    }

    // Create a File object
    File myFile("example.txt", "This is the file contents.", icon);
    std::cout << myFile << std::endl;

    Folder John("John");
    John.addFile(myFile);
    John.display();
    // // Print the File object
    // std::cout << myFile << std::endl;

    // // Access and modify members
    // std::cout << myFile.getName() << std::endl;
    // std::cout << myFile.getContents() << std::endl;
    // myFile.setContents("New contents");
    // std::cout << myFile.getContents() << std::endl;

    // // Create a copy of the File object
    // File copiedFile = myFile;

    // // Modify the original and check if the copy is affected
    // myFile.setContents("Modified contents");
    // std::cout << myFile.getContents() << std::endl;
    // std::cout << copiedFile.getContents() << std::endl;

    return 0;
}
