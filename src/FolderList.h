#pragma once
#include "Folder.h"
#include <vector>
#include <fstream>
class FolderList
{
private:
	std::vector<Folder> folderList;
	FolderList(const FolderList &other) {};
	FolderList &operator=(const FolderList& copy) {};
	static FolderList *instance;
	FolderList();
	~FolderList();
public:
	int getFolderIndexwithName(std::string);
	std::string getFolderNamewithIndex(int index);
	void addToList(std::string name);
	int getFileListSize();
	Folder getFolderwithPath(std::string);
	std::string getFullPathWithIndex(int);
	void writeToFile(const std::string);
	void readFromFile();
	static FolderList* getInstance();
	std::vector<int> getFolderIndexList();
	std::vector<std::string> getFolderPathList();
	friend std::ostream& operator<<(std::ostream &, FolderList &);

};

