#include "InvertedIndexList.h"
InvertedIndexList *InvertedIndexList::instance = NULL;
InvertedIndexList::InvertedIndexList()
{
}
InvertedIndexList::~InvertedIndexList()
{
}

InvertedIndexList::InvertedIndexList(InvertedIndexList &copy)
{
	this->instance = copy.getInstance();
	

}

InvertedIndexList& InvertedIndexList::operator=(InvertedIndexList &other)
{
	if (this != &other)
	{
		this->instance = other.getInstance();
	}
	return *this;
}


void InvertedIndexList::addToList(Folder temp,std::map<std::string,int> myMap)
{
	
	for (std::map<std::string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
		
		std::string key = it->first;
		int occurency = it->second;
		temp.setFrequency(occurency);
		wordList[key].addToList(temp);

	}
}

void InvertedIndexList::printList()
{
	std::cout << "Print";
	auto ptr = wordList.begin();
	while (ptr != wordList.end())
	{
		std::cout << "Word :"<<ptr->first<<" ";
		ptr->second.printFolderList();
		std::cout << "\n";
		ptr++;
	}

}

InvertedIndexList * InvertedIndexList::getInstance()
{
	if (instance == NULL)
		instance = new InvertedIndexList();
	return instance;
}

void InvertedIndexList::find(std::string key)
{
	
	if (wordList.find(key) != wordList.end())
	{
		std::cout << "Word :" << key << std::endl;
		wordList[key].printFolderList();
	}
	else {
		std::cout << "There is no word in library" << std::endl;
	}
}

void InvertedIndexList::writeToFile(std::string currentPath)
{
	std::ofstream output(currentPath + "/InvertedTable.txt");
	std::string key;
	auto ptr = wordList.begin();
	while (ptr != wordList.end())
	{
		key = ptr->first;
		output << key<< " ";
		auto var = ptr->second.getFolderList();
		for (int i = 0; i < var.size(); i++)
		{
			std::string path = var[i].getFullPath();
			int index = path.find("library");
			if (std::string::npos != index)
			{
				path = path.substr(index, path.size());
			}
			if (i != var.size() - 1)
			{
				output << path << " (" << var[i].getFrequency() << ") " << ", ";
			}
			else {
				output << path << " (" << var[i].getFrequency() << ")" << "\n";
			}
		}
		ptr++;;
	}
	std::cout << "Inverted table is created.\n" << currentPath +  "/InvertedTable.txt" << std::endl;
	
}

void InvertedIndexList::readFromFile(std::string path)
{
	std::ifstream file(path + "InvertedTable.txt");
	std::string line;
	std::string key;
	Folder temp;
	while (getline(file,line)) {
		std::vector<std::string>strList = splitWord(line);
		//splitTo(line, map);
		key = strList[0];
		temp.setFullPath(strList[1]);
		temp.setFrequency(std::atoi(strList[2].c_str()));
		wordList[key].addToList(temp);
		for (int i = 3; i < strList.size(); i++)
		{
			if (i % 2 == 1) // fullpath
			{
				temp.setFullPath(strList[i]);
				temp.setFrequency(std::atoi(strList[i+1].c_str()));
				wordList[key].addToList(temp);
				i++;
			}
		}


	}

}
std::vector<std::string> InvertedIndexList::splitWord(const std::string& str)
{
	std::vector<std::string>tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(" ", prev);
		if (pos == std::string::npos) pos = str.length();
		std::string token = str.substr(prev, pos - prev);
		if (!token.empty())
		{
			int index = token.find("(");
			if (std::string::npos != index)
			{
				int indx = token.find(")");
				token = token.substr(index+1, indx-1);
			}
			index = token.find(",");
			if(index == std::string::npos)
				tokens.push_back(token);
		}
		prev = pos + 1;
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

std::ostream& operator<<(std::ostream &out, InvertedIndexList& copy)
{
	auto ptr = copy.getInstance()->wordList.begin();
	while (ptr != copy.wordList.end())
	{
		out <<"Word :"<< ptr->first<<std::endl;
		 ptr->second.printFolderList();

	}
	return out;
}

