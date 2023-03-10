#include "User.h"
class Commands	//klasa komande
{
private :
	std::string command;//komanda
	bool checkFile(const std::string&);//provjerava da li je naziv fajla ispravno unesen
	bool checkPath(const std::string&);//provjervaa da li je putanja ispravno unesena
public:
	Commands();//unos komande
	~Commands();
	std::string getCommand()const;//getter za komandu, vraca u komandu i van klase
	 bool checklogin();//provjerava da li je funkcija login() ispravno unesena
	 bool checkLogOut();//odjavljuje korisnika sa sistema
	 bool checkwhere();//provjerava da li je funkcija where() ispravno unesena
	 bool checkgo();//provjerava da li je funkcija go() ispravno unesena
	 bool checkList();//provjerava da li je funkcija list() ispravno unesena
	 bool checkListPath();//provjerava da li je funkcija listPath() ispravno unesena
	 bool checkCreateDirPath();//provjerava da li je funkcija createDirPath() ispravno unesena
	 bool checkCreateFilePath();//provjerava da li je funkcija createFilePath() ispravno unesena
	 bool checkCreateDirName();//provjerava da li je funkcija createDirName() ispravno unesena
	 bool checkCreateFileName();//provjerava da li je funkcija createFileName() ispravno unesena
	 bool checkPrintFile();//provjerava da li je funkcija print() ispravno unesena
	 bool checkFindTextInFile();//provjerava da li je funkcija findTextInFile() ispravno unesena
	 bool checkFindDat();//provjerava da li je funkcija findDat() ispravno unesena
	 bool help();//ispisuje moguce funkcije i njihovu upotrebu

};

