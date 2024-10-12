#include "File.hpp"
#include <regex>
      
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
File::File(const std::string& filename, const std::string& contents, int* icon) 
{
 
   std::regex pattern(R"([a-zA-Z0-9]+(\.[a-zA-Z0-9]+)?)");
   if (!std::regex_match(filename, pattern)) 
   {
      throw InvalidFormatException();
   }

   filename_ = filename;
   if (filename.find('.') == std::string::npos || filename.find('.') + 1 == filename.length()) 
   {
      filename_ += ".txt";
   }


   if(contents.empty())
   {
      contents_ = "";
   }
   else
   {
      contents_ = contents;
   }
   int icon_size = sizeof(icon) / sizeof(icon[0]);
   if(icon_size != ICON_DIM)
   {
      icon_ = nullptr;
   }
   }

// // Below is N's code
// File::File(const std::string& filename, std::string& contents, int* icon):contents_(contents)
// {
//    int periodCount = 0;
//    for(char c : filename)
//    {
//       if(!std::isalnum(c) && c!='.')
//       {
//          throw InvalidFormatException();
//       }else if(c == '.')
//       {
//          periodCount++;
//       }
//    }
//    if(filename == "")
//    {
//       filename_ = "NewFile.txt";
//    }else if (periodCount > 1)
//    {
//       throw InvalidFormatException();
//    }else if (periodCount == 0)
//    {
//       filename_ = filename + ".txt";
//    }
//    else if(filename[filename.size()-1] == '.')
//    {
//       filename_ = filename_+ "txt";
//    }else
//    {
//       filename_ = filename;
//    }
//    icon_ = icon;
// }






size_t File::getSize() const 
{
   return contents_.size();
}


File::File(const File& rhs)
{
   filename_ = rhs.filename_;
   contents_ = rhs.contents_;

   if (rhs.icon_ != nullptr) 
   {
      icon_ = new int[ICON_DIM];
      std::copy(rhs.icon_, rhs.icon_ + ICON_DIM, icon_);
   } 
   else 
   {
      icon_ = nullptr;
   }
}

File& File::operator=(const File& rhs) 
{
   if (this != &rhs) 
   {
      filename_ = rhs.filename_;
      contents_ = rhs.contents_;

        if (rhs.icon_ != nullptr) 
        {
            icon_ = new int[ICON_DIM];
            std::copy(rhs.icon_, rhs.icon_ + ICON_DIM, icon_);
        } else 
        {
            icon_ = nullptr;
        }
    }
    return *this;
}

File::File(File&& rhs) 
{
    filename_ = std::move(rhs.filename_);
    contents_ = std::move(rhs.contents_);

    icon_ = std::move(rhs.icon_);

    rhs.icon_ = nullptr;
}

File& File::operator=(File&& rhs)
{
   if (this != &rhs) 
   {
      filename_ = std::move(rhs.filename_);
      contents_ = std::move(rhs.contents_);

      icon_ = std::move(rhs.icon_);

      rhs.icon_ = nullptr;
   }
    return *this;
}

File::~File() 
{
   if (icon_ != nullptr) 
   {
      delete[] icon_;
   }
}

// void File::testingInvalid()
// {
//    InvalidFormatException();
// }
