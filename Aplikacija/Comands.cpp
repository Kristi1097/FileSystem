#include "Commands.h"
#include "Exception.h"
#include <limits>
#include <string>
#include <regex>
bool Commands::checkFile(const std::string& file) 
{
	static const std::regex re{ "^[a-zA-Z]([a-zA-Z0-9_]+)\\.txt$" };
	return std::regex_match(file, re);
}
bool Commands::checkPath(const std::string& path)
{
	static const std::regex re{ "[a-zA-Z]?:((\\\\){1,2}[a-zA-Z 0-9]*)*(\.[a-zA-Z]*)?" };
	return std::regex_match(path, re);
}
Commands::Commands()
{
	std::cout << "Unesite komandu:";
	getline(std::cin,command);
}
Commands::~Commands(){}
std::string Commands::getCommand()const
{
	return command;
}
bool Commands::checklogin()
{
	std::string login = "login";
	if (login.compare(command) == 0)
		return true;
	return false;
}
bool Commands::checkLogOut()
{
	std::string logout = "logout";
	if ((logout.compare(command) == 0) && (command.size() == 6))
		return true;
	return false;
}
bool Commands::checkwhere()
{
	std::string where = "where";
	if (((where.compare(0,5,command.c_str())) == 0)&&(command.size()==5))
		return true;
	return false;
}
bool Commands::checkgo()
{
	std::string go = "go ", path;
	if (go.compare(0, 3, command.c_str(), 0, 3) == 0)
	{
		path.assign(command.begin() + 3, command.end());
		if (checkPath(path) == 1)
			return true;
	}
	return false;
}
bool Commands::checkList()
{
	std::string list = "list";
	if((list.compare(0,4, command.c_str(), 0, 4) == 0) && (command.size() == 4))
		return true;
	return false;
}
bool Commands::checkListPath()
{
	std::string list = "list ", path;
	if (list.compare(0, 5, command.c_str(), 0, 5) == 0)
	{
		path.assign(command.begin() + 5, command.end());
		if (checkPath(path) == 1)
		return true;
	}
	return false;
}
bool Commands::checkCreateDirPath()
{
	std::string create = "create ", d = "[-d] ", path;
	if ((create.compare(0, 7, command.c_str(), 0, 7) == 0) && (d.compare(0, 5, command.c_str(), 7, 5) == 0))
	{
		path.assign(command.begin() + 12, command.end());
		if (checkPath(path) == 1)
		return true;
	}
	return false;
}
bool Commands::checkCreateFilePath()
{
	std::string create = "create ", path;
	if ((create.compare(0, 7, command.c_str(), 0, 7) == 0))
	{
		path.assign(command.begin() + 7, command.end());
		if (checkPath(path) == 1)
		return true;
	}
	return false;
}
bool Commands::checkCreateDirName()
{
	std::string create = "create ", d = "[-d] ";
	if ((create.compare(0, 7, command.c_str(), 0, 7) == 0) && (d.compare(0, 5, command.c_str(), 7, 5) == 0))
		return true;
	return false;
}
bool Commands::checkCreateFileName()
{
	std::string create = "create ";
	std::string fileName;
		if (create.compare(0, 7, command.c_str(), 0, 7) == 0)
		{
			fileName.assign(command.begin() + 7, command.end());
			if(checkFile(fileName) == 1)
			return true;
		}
		return false;
}
bool Commands::checkPrintFile()
{
	std::string print = "print "; std::string fileName;
	if (print.compare(0, 6, command.c_str(), 0, 6) == 0)
	{
		fileName.assign(command.begin() + 6, command.end());
		if (checkFile(fileName)==1)
		return true;
	}
	return false;
}
bool Commands::checkFindTextInFile()
{
	std::string find = "find ";
	if (command.compare(0, 5, command.c_str(), 0, 5) == 0)
	{
		std::size_t pos1 = command.find('"');
		std::size_t pos2 = command.find('"', pos1 + 1) + 2;
		std::string fileName; fileName.assign(command.begin() + pos2, command.end());
		if((pos1 == 5 && pos2) && (checkFile(fileName) == 1))
		return true;
	}
	return false;
}
bool Commands::checkFindDat()
{
	std::string finddat = "finddat "; std::string fileName, path;
	if (finddat.compare(0, 8, command.c_str(), 0, 8) == 0)
	{
		std::size_t pos1 = command.find(" ");
		std::size_t pos2 = command.find(" ", pos1 + 1);
		fileName = command.substr(pos1 + 1, pos2 - pos1 - 1);
		if((checkFile(fileName) == 1))
		return true;
	}
	return false;
}
bool Commands::help()
{
	std::cout << command;
	std::string help = "help";
	if (help.compare(command) == 0)
		return true;
	return false;
}

