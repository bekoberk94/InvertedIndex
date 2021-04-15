#pragma once
#include "InvertedIndex.h"
#include <map>
#include <fstream>
class InvertedIndexList
{
private:
	std::map<std::string, InvertedIndex> wordList;
	InvertedIndexList();
	~InvertedIndexList();
	static InvertedIndexList *instance;
public:
	InvertedIndexList(InvertedIndexList&);
	InvertedIndexList &operator=(InvertedIndexList &other);
	void addToList(Folder,std::map<std::string,int>);
	void printList();
	static InvertedIndexList* getInstance();
	void find(std::string key);
	void writeToFile(std::string);
	friend std::ostream& operator<<(std::ostream &out, InvertedIndexList& copy);
	void readFromFile(std::string);
	std::vector<std::string> splitWord(const std::string & str);


};

