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

// std::ostream& operator<< (std::ostream& os, const File& target) {
//    os << "Name: " << target.getName() << std::endl;
//    os << "Size: " << target.getSize() << " bytes" << std::endl;
//    os << "Contents: " << target.getContents(); 
//    return os;
// }

// bool File::operator<(const File& rhs) const {
//    return getName() < rhs.getName();
// }

//                       DO NOT EDIT ABOVE THIS LINE. 
//             (unless you want your work to be tested incorrectly)
//    That also means includes. Remember, all other includes go in .hpp

// However, you may notice an operator overload you don't recognize (<<)
// Try calling the following once you've implemented a constructor & getSize():
//    File a; 
//    std::cout << a << std::endl;

// =========================== YOUR CODE HERE ===========================
File::File(const std::string& filename, const std::string& contents , int* icon) 
{
   std::regex pattern(R"([a-zA-Z0-9]+(\.[a-zA-Z0-9]+)?)");
   if (!std::regex_match(filename, pattern)) 
   {
      filename_ = "NewFile.txt";
   } 
   else 
   {
      filename_ = filename;
      if (filename.find('.') == std::string::npos || filename.find('.') + 1 == filename.length()) 
      {
         filename_ += ".txt";
      }
   }

   if(contents.empty())
   {
      contents_ = "";
   }
   else
   {
      contents_ = contents;
   }
}
