#pragma once
#include "FileSystemElement.h"

class File : public FileSystemElement {
public:
	File();
	File(const char* ime, const char* ekstenzija, FileSystemElement* roditelj = nullptr);
	virtual ~File() {};

	char* KvalifikovanoIme();
	void PrintList();
};