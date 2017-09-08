#include "FileAdoptionList.hpp"

FileAdoptionList::FileAdoptionList() :AdoptionList{}, filename{ "" }
{
}

void FileAdoptionList::setFileName(const std::string& filename)
{
    this->filename = filename;
}
