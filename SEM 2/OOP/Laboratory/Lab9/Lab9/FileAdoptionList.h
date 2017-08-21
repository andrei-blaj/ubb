
#pragma once
#include "AdoptionList.h"

class FileAdoptionList : public AdoptionList
{
protected:
	std::string filename;
public:
	FileAdoptionList();
	virtual ~FileAdoptionList() {}

	void setFileName(const std::string& filename);
	virtual void writeToFile()=0;
	virtual void displayAdoptionList() const = 0;
};
