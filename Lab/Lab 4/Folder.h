#pragma once
#include "FileSystemElement.h"

class Folder : public FileSystemElement {
private:
	FileSystemElement** clan;
public:
	Folder();
	Folder(const char* ime, FileSystemElement* roditelj = nullptr);
	virtual ~Folder();

	char* KvalifikovanoIme();
	void PrintList();

	FileSystemElement* ReturnClan(int i) { return clan[i]; };
	void DodajElement(FileSystemElement& podelement);
	void BrisiElement(int i);
};