File::File(const std::string& filename, std::string contents, int* icon):contents_(contents)
{
    int periodCount = 0;
    for(char c : filename)
    {
        if(!std::isalnum(c) && c!= '.')
        {
            throw InvalidFormatException();
        }else if(c == ',')
        {
            periodCount++;
        }
    }

    if(filename == "")
    {
        filename_ == "NewFile.txt";
    }else if (periodCount > 1)
    {
        throw InvalidFormatException();
    }else if (periodCount == 0)
    {
        filename_ = filename + ".txt";
    }
    else if (filename[filename.size()-1] == '.')
    {
        filename_ = filename + "txt";
    }else 
    {
        filename_ = filename;
    }

    icon_ = new int[ICON_DIM];
    }