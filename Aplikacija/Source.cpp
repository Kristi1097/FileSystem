#include "Commands.h"
#include "Exception.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <filesystem>
int main()
{
	Commands command1;
	try {
		if (command1.checklogin())
		{
			User korisnik;
			korisnik.login();
			bool logout = false;
			do {
				Commands command;
				if (command.checkwhere()) {
					korisnik.where();
				}
				else if (command.checkLogOut())
				{
					korisnik.~User();
					logout = true;
				}
				else if (command.checkgo())
				{
					korisnik.go(command.getCommand());
				}
				else if (command.checkList())
				{
					std::string path; char pathc[100];
					path = korisnik.getCurrentDir();
					strcpy(pathc, path.c_str());
					korisnik.listPath(pathc, 0);
				}
				else if (command.checkListPath())
				{
					std::string path; char pathc[100];
					std::size_t pos1 = command.getCommand().find(" ");
					path = command.getCommand().substr(pos1 + 1);
					strcpy(pathc, path.c_str());
					korisnik.listPath(pathc, 0);
				}
				else if (command.checkCreateDirPath())
				{

					korisnik.createDirPath(command.getCommand());
				}
				else if (command.checkCreateFilePath())
				{
					korisnik.createFilePath(command.getCommand());
				}
				else if (command.checkCreateDirName())
				{
					korisnik.createDirName(command.getCommand());
				}
				else if (command.checkCreateFileName())
				{
					korisnik.createFileName(command.getCommand());
				}
				else if (command.checkPrintFile())
				{
					korisnik.printFile(command.getCommand());
				}
				else if (command.checkFindTextInFile())
				{
					int position = korisnik.findTextInFile(command.getCommand());
					std::cout << position<< std::endl;
				}
				else if (command.checkFindDat())
				{
					std::string directory; std::string fileName2;
					std::size_t pos1 = command.getCommand().find(" ");
					std::size_t pos2 = command.getCommand().find(" ", pos1 + 1);
					fileName2 = command.getCommand().substr(pos1 + 1, pos2 - pos1 - 1);
					directory = command.getCommand().substr(pos2 + 1);
					std::filesystem::path dir(directory);
					std::filesystem::path fileName22(fileName2);
					korisnik.findDat(dir, fileName22);
				}
				else if (command.help())
				{
					std::cout << "\nCommands:\nlogin-prijava korisnika na sistem\nlogout-odjava korisnika sa sistema\nwhere-prikazuje putanju tekuceg direktorijuma\ngo putanja-mijenja tekuci direktorijum navedenim\ncreate [-d] putanja-kreira direktorijum na navedenoj putanji\ncreate putanja-kreira datoteku u navedenoj putanji sa zadatim imenom\ncreate [-d] naziv-kreira direktorijum sa navedenim imenom u tekucem direktorijumu\ncreate naziv-kreira datoeteku sa navedenim imenom u tekucem direktorijumu\nlist [putanja]-ispisuje sve direktorijume i poddorektorijume navedene putanje\nprint datoteka-ispisuje sadrzaj navedene datoteke\nfind 'text' datoteka-trazi u datoteci navedeni text i vraca broj linije na kojoj pocinje\nfindDat datoteka putanja-trazi navedenu datoteku u navedenoj putanji\n";
					std::cout << "Korisnicko ime: sadrzi min-4 max-14 karaktera(prvi karkater mora biti slovo)ukljucujuci mala,velika slova,brojevi i _\nPassword:sadrzi min-4 max-14 karaktera(prvi karkater mora biti slovo)ukljucujuci mala,velika slova,brojevi\nNaziv datoteke: sadrzi mala,velika slova,brojeve i _(mora pocinjati slovom,a zavrsavati sa ekstenzijom .txt)\n";
				}
				else std::cout << "Pogresno ste unijeli komandu!\n";
			} while (logout == false);
			std::cout << "Kraj programa!\n";
		}
		else std::cout << "\nPogresno ste unijeli komandu login !\n " << std::endl;;
	}
	catch(Exception message)
	{
		message.printMsg();
	}
	catch (...) {
		std::cout << "Desila se greska!\n";
	}
	system("pause");
}