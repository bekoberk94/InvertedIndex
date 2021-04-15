#pragma once
#include <string>
#include <iostream>
class Folder
{
private:
	std::string filename;
	std::string full_path;
	int index;
	int frequency;
public:
	Folder();
	Folder(const std::string & name, const std::string path, int index,int freq);
	Folder(const std::string & name, const std::string path, int index);
	~Folder();
	Folder(std::string);
	std::string getFileName();
	void setFileName(const std::string);
	std::string getFullPath();
	void setFullPath(const std::string);
	int getIndex();
	void printFolder();
	void setFrequency(int);
	int getFrequency();
};

