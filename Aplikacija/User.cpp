#include "User.h"
#include "Exception.h"
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <direct.h>
#include <algorithm>
#include <filesystem>
#include <regex>
#include <sys/types.h>
#include <dirent.h>
bool User::checkUserName(const std::string& userName)
{
	static const std::regex re{ "^[a-zA-Z]([a-zA-Z0-9_]){4,14}" };
	return std::regex_match(userName, re);
}
bool User::checkUserPassword(const std::string& userPassword)
{
	static const std::regex re{ "^[a-zA-Z]([a-zA-Z0-9]){4,14}" };
	return std::regex_match(userPassword, re);
}
bool User::check()
{
	std::ifstream in("Users.txt", std::ios::_Nocreate);
		std::string worduser, wordpass;
		if (in.is_open())
		{
			while (in >> worduser)
			{
				if (worduser.compare(name) == 0)
				{
					in >> wordpass;
					if (wordpass.compare(password) == 0)
						return true;
				}
			}
			in.close();
		}
		std::ofstream out("Users.txt", std::ios::app);
		if (out.is_open())
		{
			out << name << " ";
			out << password << "\n";
			out.close();
		}
	return false;
}
void User::login()
{
		check();
		currentDirectory = "C:\\Korisnik";
		_mkdir(currentDirectory.c_str());
}
User::User()
{
	do {
		std::cout << "Korisnicko ime: ";
		std::cin >> name; std::cout << std::endl;
	} while ((checkUserName(name) == 0)&&(std::cout << "Korisnicko ime nije ispravno!\n"));
	do {
		std::cout << "Password: ";
		std::cin >> password; std::cout << std::endl;
		std::cin.ignore();
	} while ((checkUserPassword(password) == 0) && (std::cout << "Korisnicka lozinka nije ispravna!\n"));
}
User::~User() 
{}
std::string User::getCurrentDir()const
{
	return currentDirectory;
}
void User::where()
{
	std::cout << currentDirectory << std::endl;
}
void User::go(std::string command)
{
	std::string array, path;
	array.resize(2);
	path.resize(command.size()); int i = 0; int t = 0; bool petlja = false;
	while (i < command.size())
	{
		if (command[i] != ' ' &&petlja == false)
		{
			array[i] = command[i];
		}
		else {
			petlja = true;
			path[t] = command[i+1]; t++;
		}
		i++;
	}
	currentDirectory = path;
	_mkdir(currentDirectory.c_str());
}
void User::list(char* path, const int root) {
	struct dirent* entry;
	char temp[100];
	DIR* dir = opendir(path);
	if (!dir) {
		return;
	}
	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
		{
			for (int i = 0; i < root; i++)
			{
				if (i % 2 == 0 || i == 0)
					std::cout << "|";
				else
					std::cout << " ";
			}
			std::cout << "|-" << "-" << entry->d_name << std::endl;
			strcpy(temp, path);
			strcat(temp, "/");
			strcat(temp, entry->d_name);
			list(temp, root + 2);
		}
	}
	closedir(dir);
}
void User::listPath(char* path, const int root) {
	struct dirent* entry;
	char temp[100];
	DIR* dir = opendir(path);
	if (!dir) {
		return;
	}
	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
		{
			for (int i = 0; i < root; i++)
			{
				if (i % 2 == 0 || i == 0)
					std::cout << "|";
				else
					std::cout << " ";
			}
			std::cout << "|-" << "-" << entry->d_name <<std::endl;
			strcpy(temp, path);
			strcat(temp, "/");
			strcat(temp, entry->d_name);
			listPath(temp, root + 2);
		}
	}
	closedir(dir);
}
void User::createDirPath(std::string command)
{
	std::string temp;
	temp.assign(command.begin() + 12, command.end() - 0);
	_mkdir(temp.c_str());
}
void User::createFilePath(std::string command)
{
	std::string name;
	name.assign(command.begin() + 7, command.end() - 0);
	std::ofstream out(name,std::ios::out);
}
void User::createDirName(std::string command)
{
	std::string name, temp;
	name.assign(command.begin() + 12, command.end() - 0); 
	temp.assign(currentDirectory);
	temp.append("\\");
	temp.append(name);
	_mkdir(temp.c_str());
}
void User::createFileName(std::string command)
{
	std::string temp, name;
	temp.assign(currentDirectory);
	temp.append("\\");
	name.assign(command.begin() + 7, command.end() - 0);
	temp.append(name);
	std::ofstream out(temp, std::ios::out);
}
int User::findTextInFile(std::string command)
{
	std::string fileName, search;
	std::size_t pos1 = command.find('"');
	std::size_t pos2 = command.find('"', pos1 + 1);
	search = command.substr(pos1+1, pos2-pos1-1);
	fileName=command.substr(pos2+2);
	std::ifstream fileInput;
	std::string line;
	fileInput.open(fileName);
	if (fileInput.is_open()) {
		for (unsigned int curLine = 0; getline(fileInput, line); curLine++)
		{
			if (line.find(search) != std::string::npos) {
				std::cout << "found: " << search << " line: ";
				return curLine;
			}
		}
		fileInput.close();
	}
	else throw Exception("Unijeli ste nepostojecu datoteku!\n");
	return 0;
}
void User::printFile(std::string command)
{
	std::string nameFile;
	nameFile.assign(command.begin() + 6, command.end() - 0);
	std::ifstream in(nameFile);
	std::string text;
	if (in.is_open())
	{
		while (getline(in, text))
		{
			std::cout << text<<"\n";
		}
		in.close();
	}
	else throw Exception("Unijeli ste nepostojecu datoteku!\n");
}
void User::findDat(const std::filesystem::path& directory, const std::filesystem::path& fileName)
{
auto d = std::filesystem::directory_iterator(directory);
auto found = std::find_if(d, end(d), [&fileName](const auto& dir_entry)
	{
		return dir_entry.path().filename() == fileName;
	});
if (found != end(d))
	{
	std::cout << "Found\n";
	}
}
