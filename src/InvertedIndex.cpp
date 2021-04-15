#include "InvertedIndex.h"

InvertedIndex::InvertedIndex()
{
	frequency = 0;
}

InvertedIndex::~InvertedIndex()
{
}
InvertedIndex::InvertedIndex(InvertedIndex &copy)
{
	this->folderList = copy.folderList;
	this->frequency = copy.frequency;
}
InvertedIndex & InvertedIndex::operator=(InvertedIndex & copy)
{
	this->folderList = copy.folderList;
	this->frequency = copy.frequency;
	// TODO: insert return statement here
	return *this;
}
void InvertedIndex::addToList(Folder temp)
{
	folderList.push_back(temp);
	frequency += temp.getFrequency();
}

void InvertedIndex::addToList(std::string file_name, std::string file_path, int index,int occurency)
{
	Folder temp(file_name, file_path,index);
	folderList.push_back(temp);
	frequency += occurency;
}

void InvertedIndex::writeToFile()
{
}

void InvertedIndex::readFromFile()
{
}

void InvertedIndex::printFolderList()
{
	std::cout << "Total Frequency :" << frequency<<std::endl;
	std::cout << "File Name :";
	for (int i = 0; i < folderList.size(); i++)
	{
		std::string path = folderList[i].getFullPath();
		int freq = folderList[i].getFrequency();
		int index = path.find("library");
		if (std::string::npos != index)
		{
			path = path.substr(index, path.size());
		}
		if (i != (folderList.size() - 1))
		{
			std::cout << path << "("<<freq<<"),";
		}
		else {
			std::cout << path <<"("<<freq<<")"<< std::endl;
		}

	}
}

std::vector<Folder> InvertedIndex::getFolderList()
{
	return folderList;
}

std::ostream& operator<<(std::ostream out, InvertedIndex copy)
{

	for (int i = 0; i < copy.folderList.size(); i++)
	{
		std::string path = copy.folderList[i].getFullPath();
		int freq = copy.folderList[i].getFrequency();
		int index = path.find("library");
		if (std::string::npos != index)
		{
			path = path.substr(index, path.size());
		}
		if (i != (copy.folderList.size() - 1))
		{
			out << path << "(" << freq << "),";
		}
		else {
			out << path << "(" << freq << ")" << std::endl;
		}

	}

	return out;
}
