#include "Folder.h"
Folder::Folder()
{
	filename = "";
	full_path = "";
	index = 0;
	frequency = 0;
}
Folder::Folder(const std::string &name,const std::string path,int index,int freq)
	:filename(name),full_path(path),index(index),frequency(freq)
{

}
Folder::Folder(const std::string &name, const std::string path, int index)
	: filename(name), full_path(path), index(index)
{

}

Folder::~Folder()
{

}
void Folder::printFolder()
{
	std::cout << "File name :" << filename << "\n Path :" << full_path << "\n Index :" << index << std::endl;
}
void Folder::setFrequency(int freq)
{
	frequency = freq;
}
int Folder::getFrequency()
{
	return frequency;
}
Folder::Folder(std::string name)
{
	full_path = name;
}

std::string Folder::getFileName()
{
	return filename;
}

void Folder::setFileName(const std::string file_name)
{
	filename = file_name;
}

std::string Folder::getFullPath()
{
	return full_path;
}

void Folder::setFullPath(const std::string full_path)
{
	this->full_path = full_path;
}

int Folder::getIndex()
{
	return index;
}
