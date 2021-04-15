#include "FolderList.h"
FolderList *FolderList::instance = NULL;
FolderList::FolderList()
{
}

FolderList::~FolderList()
{
}

void FolderList::addToList(std::string path)
{
	int index = path.find_last_of("/");
	std::string name = "";
	if (std::string::npos != index)
	{
		name = path.substr(index + 1);
	}
	Folder temp(name,path,folderList.size());
	folderList.push_back(temp);
}
int FolderList::getFileListSize()
{
	return folderList.size();
}
Folder FolderList::getFolderwithPath(std::string full_path)
{
	for (int i = 0; i < folderList.size(); i++)
	{
		if (folderList[i].getFullPath() == full_path)
			return folderList[i];
	}
	return Folder();
}
std::string FolderList::getFullPathWithIndex(int index)
{
	std::vector<Folder>::iterator ptr;
	for (ptr = folderList.begin(); ptr != folderList.end(); ptr++)
	{
		if (ptr->getIndex() == index)
			return ptr->getFullPath();
	}
	return "";
}
void FolderList::writeToFile(std::string currentPath)
{
	std::ofstream myfile(currentPath + "file.txt");
	std::vector<Folder>::iterator ptr;
	myfile << "File Name\t\t\tPath\t\t\t\t\t\t\tIndex\n";
	for (ptr = folderList.begin(); ptr != folderList.end(); ptr++)
	{
		myfile << ptr->getFileName() <<"\t\t"<< ptr->getFullPath() << "\t\t" << ptr->getIndex()<<"\n";

	}
	myfile.close();

	
}
void FolderList::readFromFile()
{
}
FolderList* FolderList::getInstance()
{
	if (!instance)
		instance = new FolderList();
	return instance;
}
std::vector<int> FolderList::getFolderIndexList()
{
	std::vector<int> indexList;
	std::vector<Folder>::iterator ptr;
	for (ptr = folderList.begin(); ptr != folderList.end(); ptr++)
	{
		indexList.push_back(ptr->getIndex());
	}
	return indexList;
}
std::vector<std::string> FolderList::getFolderPathList()
{
	std::vector<std::string> pathList;
	std::vector<Folder>::iterator ptr;
	for (ptr = folderList.begin(); ptr != folderList.end(); ptr++)
	{
		pathList.push_back(ptr->getFullPath());
	}
	return pathList;
}


/*void FolderList::printList()
{
	std::vector<Folder>::iterator ptr;
	for (ptr = folderList.begin(); ptr != folderList.end(); ptr++)
	{
		(*ptr).printFolder();
	}
}*/

int FolderList::getFolderIndexwithName(std::string other)
{
	std::vector<Folder>::iterator ptr;
	for (ptr = folderList.begin(); ptr != folderList.end(); ptr++)
	{
		if (ptr->getFileName() == other)
			return ptr->getIndex();
	}
	return -1;
}

std::string FolderList::getFolderNamewithIndex(int index)
{
	std::vector<Folder>::iterator ptr;
	for (ptr = folderList.begin(); ptr != folderList.end(); ptr++)
	{
		if (ptr->getIndex() == index)
			return ptr->getFileName();
	}
	return "";
}

std::ostream & operator<<(std::ostream &out, FolderList &copy)
{
	std::vector<Folder>::iterator ptr;
	for (ptr = copy.folderList.begin(); ptr != copy.folderList.end(); ptr++)
	{
		out << ptr->getFullPath() << " " << ptr->getFrequency()<<std::endl;	
	}
	return out;
}
