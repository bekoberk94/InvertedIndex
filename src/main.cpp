#include <cstddef>
#include <iostream>
#include <sstream>
#include "FolderList.h"
#include <experimental/filesystem>
#include <fstream>
#include <map>
#include "InvertedIndexList.h"
#include <algorithm>

namespace fs = std::experimental::filesystem;

void findFiles(std::string path)
{
	// this function finds files in the folder recursively 
	for (const auto & entry : fs::directory_iterator(path))
	{
		int index = entry.path().generic_string().find(".txt");
		if (index != std::string::npos)
		{
			FolderList::getInstance()->addToList(entry.path().generic_string());
		}
		path = entry.path().generic_string();
		findFiles(path);
	}
}
std::map<std::string,int> split(const std::string& str,std::map<std::string,int>tokens)
{
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(" ", prev);
		if (pos == std::string::npos) pos = str.length();
		std::string token = str.substr(prev, pos - prev);
		if (!token.empty())
		{
			std::map<std::string,int>::iterator ptr = tokens.lower_bound(token);
			if (ptr != tokens.end() && !(tokens.key_comp()(token, ptr->first)))
			{
				tokens[token]++;
			}
			else {
				tokens.insert(std::make_pair(token, 1));
			}
		}
		prev = pos + 1;
	} while (pos < str.length() && prev < str.length());
	return tokens;
}
void readFiles(std::string path)
{
	
	std::map<std::string,int> tokens;
	std::ifstream file(path);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::string line;
	while (std::getline(file,line)){
		tokens = split(line,tokens);
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	InvertedIndexList::getInstance()->addToList(FolderList::getInstance()->getFolderwithPath(path),tokens);
	file.close();
	

}
void createInvertedTable()
{
	std::vector<int> indexList = FolderList::getInstance()->getFolderIndexList();
	std::vector<int>::iterator ptr = indexList.begin();
	for (; ptr != indexList.end(); ptr++)
	{
		std::string file_path = FolderList::getInstance()->getFullPathWithIndex(*ptr);
		readFiles(file_path);
	}
	InvertedIndexList::getInstance()->writeToFile(fs::current_path().generic_string());
}
int main(int argc, char *argv[])
{
	int i = 0;
	if (argc < 2)
	{
		std::cout << "No parameters is entered."<<std::endl;
		std::cout << "Proper parameter for creating inverted table is :""cli index path_to_library" << std::endl;
		std::cout << "Proper parameter for searcing in inverted table is :""cli search word" << std::endl;
		std::getchar();
		return 0;
	}
	std::string key = argv[2];
	std::transform(key.begin(), key.end(), key.begin(), ::tolower);

	int index = key.find("index");
	if (std::string::npos != index)
	{
		std::string path = argv[3];
		std::transform(path.begin(), path.end(), path.begin(), ::tolower);
		findFiles(path);
		createInvertedTable();
	}
	else {
		index = key.find("search");
		if (std::string::npos != index)
		{
			std::string word = argv[3];
			InvertedIndexList::getInstance()->readFromFile(fs::current_path().generic_string());
			InvertedIndexList::getInstance()->find(word);
		}
		else {
			std::cout << "Wrong input.." << std::endl;
			std::cout << "Proper parameter for creating inverted table is :""cli –index “path_to_library”" << std::endl;
			std::cout << "Proper parameter for searcing in inverted table is :""cli –search “word”" << std::endl;
			std::getchar();
		}
	}
	
}