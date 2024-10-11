#include "Folder.hpp"

/**
* @brief Construct a new Folder object
* @param name A string with alphanumeric characters.
   If the folder name is empty / none is provided, default value of "NewFolder" is used. 
* @throw If the name is invalid (eg. contains non-alphanumeric characters) an InvalidFormatException is thrown
*/
Folder::Folder(const std::string& name) : name_{"NewFolder"} {
   if (name.empty()) { return; }

   for (const char& c : name) {
      if (!std::isalnum(c)) {
         // We have found a non-alphanumeric character
         throw InvalidFormatException("Invalid folder name: " + name);
      }
   }
   
   name_ = name;
}

/**
   * @brief Get the value stored in name_
   * @return std::string 
   */
std::string Folder::getName() const {
   return name_;
}

/**
* @brief Sets the name_ member to the given parameter
* 
* @param new_foldername A string containing only alphanumeric characters
*    - If the string is invalid the folder is not renamed
* @return True if the folder was renamed sucessfully. False otherwise.
*/
bool Folder::rename(const std::string& name) {
   for (const char& c : name) {
      if (!std::isalnum(c)) { return false; }
   }
   
   name_ = name;
   return true;
}

/**
* @brief Sorts and prints the names of subfolder and file vectors lexicographically (ie. alphabetically)
* The contents of subfolders are not printed.
* Reference the following format (using 3 spaces to indent the contained filenames)
* <CURRENT_FOLDER_NAME> 
*    <SUBFOLDER1_NAME> 
*    <SUBFOLDER2_NAME> 
*    ...
*    <SUBFOLDER_N_NAME> 
*    <FILENAME_1>
*    <FILENAME_2>
*     ...
*    <FILENAME_N>
* 
* @note: This CAN be done more efficiently by maintaining sorted order in the vectors already, instead of sorting each time we print. 
*    However, we'll hold off on that for now, since we just want to get used to iterating with iterators.
*/
void Folder::display() {
   std::sort(files_.begin(), files_.end());

   std::cout << getName() << std::endl;
   for (auto it = files_.begin(); it != files_.end(); ++it) { std::cout << "   " << it->getName() << std::endl; }
}

//                       DO NOT EDIT ABOVE THIS LINE. 
//             (unless you want your work to be tested incorrectly)
//    That also means includes. Remember, all other includes go in .hpp
// =========================== YOUR CODE HERE ===========================



size_t Folder::getSize()const
{
   size_t total = 0;
   for(const File& file : files_)
   {
      total += file.getSize();
   }
   return total;
}


bool Folder::addFile(File& newFile) 
{
    // Check if a file with the same name already exists
    if (std::any_of(files_.begin(), files_.end(), [&newFile](const File& file) {
        return file.getName() == newFile.getName();
    })) {
        return false; // File already exists
    }

    // If the name is empty, don't add the file
    if (newFile.getName().empty()) {
        return false;
    }

    // Add the file using move semantics
    files_.push_back(std::move(newFile));
    return true;
}


bool Folder::removeFile(const std::string& name) {
    auto it = std::find_if(files_.begin(), files_.end(), [&name](const File& file) {
        return file.getName() == name;
    });

    if (it != files_.end()) {
        files_.erase(it);
        return true;
    }

    return false;
}

bool Folder::moveFileTo(const std::string& name, Folder& destination) {
    // Find the file to be moved in the current folder
    auto it = std::find_if(files_.begin(), files_.end(), [&name](const File& file) {
        return file.getName() == name;
    });

    // Check if the file exists in the current folder
    if (it == files_.end()) {
        return false; // File not found
    }

    // Check if the destination folder is the same as the current folder
    if (this == &destination) {
        return true; // Moving within the same folder is always successful
    }

    // Check if the destination folder already contains a file with the same name
    if (std::any_of(destination.files_.begin(), destination.files_.end(), [&name](const File& file) {
        return file.getName() == name;
    })) {
        return false; // File already exists in the destination folder
    }

    // Move the file to the destination folder
    destination.files_.push_back(std::move(*it));
    files_.erase(it);
    return true;
}

bool Folder::copyFileTo(const std::string& name, Folder& destination) 
{
    // Find the file to be copied in the current folder
    auto it = std::find_if(files_.begin(), files_.end(), [&name](const File& file) {
        return file.getName() == name;
    });

    // Check if the file exists in the current folder
    if (it == files_.end()) {
        return false; // File not found
    }

    // Check if the destination folder is the same as the current folder
    if (this == &destination) {
        return false; // Copying within the same folder is not allowed
    }

    // Check if the destination folder already contains a file with the same name
    if (std::any_of(destination.files_.begin(), destination.files_.end(), [&name](const File& file) {
        return file.getName() == name;
    })) {
        return false; // File already exists in the destination folder
    }

    // Create a copy of the file and add it to the destination folder
    destination.files_.push_back(File(*it));
    return true;
}