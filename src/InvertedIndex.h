#pragma once
#include <iostream>
#include "Folder.h"
#include <vector>
class InvertedIndex
{
private:
	std::vector<Folder> folderList;
	int frequency;
public:
	InvertedIndex();
	~InvertedIndex();
	InvertedIndex(InvertedIndex&);
	InvertedIndex &operator=(InvertedIndex &copy);
	void addToList(std::string file_name,std::string file_path,int index,int occurency);
	void addToList(Folder temp);
	void writeToFile();
	void readFromFile();
	void printFolderList();
	friend std::ostream& operator<< (std::ostream ,InvertedIndex);
	std::vector<Folder> getFolderList();
};

