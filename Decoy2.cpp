#include "File.hpp"
      
std::string File::getName() const {
   return filename_;
}

std::string File::getContents() const {
   return contents_;
}

void File::setContents(const std::string& new_contents) {
   contents_ = new_contents;
}

int* File::getIcon() const {
   return icon_;
}

void File::setIcon(int* new_icon) {
   if (icon_) { delete[] icon_; }
   icon_ = new_icon;
} 

std::ostream& operator<< (std::ostream& os, const File& target) {
   os << "Name: " << target.getName() << std::endl;
   os << "Size: " << target.getSize() << " bytes" << std::endl;
   os << "Contents: " << target.getContents(); 
   return os;
}

bool File::operator<(const File& rhs) const {
   return getName() < rhs.getName();
}

//                       DO NOT EDIT ABOVE THIS LINE. 
//             (unless you want your work to be tested incorrectly)
//    That also means includes. Remember, all other includes go in .hpp

// However, you may notice an operator overload you don't recognize (<<)
// Try calling the following once you've implemented a constructor & getSize():
//    File a; 
//    std::cout << a << std::endl;

// =========================== YOUR CODE HERE ===========================

size_t File::getSize() const
{
    return ICON_DIM;
}

File::File(const std::string&& filename, std::string contents, int* icon):contents_(contents)
{
    int periodCount = 0; 
    for(char c : filename)
    {
        if(!std::isalnum(c) && c!= ',')
        {
            throw InvalidFormatException();
        }else if(c== '.')
        {
            periodCount++;
        }
    }
    if(filename == "")
    {
        filename_ = "NewFile.txt";
    }else if(periodCount > 1)
    {
        throw InvalidFormatException();
    } else if(periodCount == 0)
    {
        filename_ = filename + ".txt";
    }else if(filename[filename.size()-1] == '.')
    {
        filename_ = filename + "txt";
    }
    else
    {
        filename_ = filename;
    }

}

File::File(const File& rhs) : filename_(rhs.filename_), contents_(rhs.contents_) 
{
    // Deep copy the icon array
    icon_ = new int[ICON_DIM];
    for (size_t i = 0; i < ICON_DIM; ++i) 
{
    icon_[i] = rhs.icon_[i];
}
}


File& File::operator=(const File& rhs) {
    if (this != &rhs) {
        filename_ = rhs.filename_;
        contents_ = rhs.contents_;

        // Delete the old icon array
        delete[] icon_;

        // Copy the icon array using a loop
        icon_ = new int[ICON_DIM];
        for (size_t i = 0; i < ICON_DIM; ++i) {
            icon_[i] = rhs.icon_[i];
        }
    }
    return *this;
}

File::File(File&& rhs)
{
    filename_ = std::move(rhs.filename_);
    contents_ = std::move(rhs.contents_);
    icon_ = new int[ICON_DIM];
    std::copy(rhs.icon_, rhs.icon_ + ICON_DIM, icon_);
}

File& File::operator=(File&& rhs) 
{
    if (this != &rhs) {
        filename_ = std::move(rhs.filename_);
        contents_ = std::move(rhs.contents_);

        // Move the icon array
        delete[] icon_;
        icon_ = rhs.icon_;
        rhs.icon_ = nullptr;
    }
    return *this;
}

File::~File() {
    delete[] icon_;
}