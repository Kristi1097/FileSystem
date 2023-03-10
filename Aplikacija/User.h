#include <string>//biblioteka za rad sa stringovima
#include <string.h>//biblioteka za rad sa stringovima
#include <iostream>//standaradna biblioteka za ulaz/izlaz
#include <fstream>//biblioteka koja omogucava rad sa datotekama
class User//klasa korisnik
{
private:
	std::string name;//korisnicko ime
	std::string password;//korisnicka lozinka
	std::string currentDirectory;//tekuci direktorijum
	bool checkUserName(const std::string&);//provjerava da li je korisnicko ime ispravno uneseno
	bool checkUserPassword(const std::string&);//provjerava da li je password ispravno unesenen
	bool check();//provjerava da li je korisnik postoji u bazi podataka ,ako postoji prijavi ga ako ne psotoji kreira novog korisnika
public:
	User();//unos podataka za novog korisnika
	~User();
	void login();//prijavljuje korisnika i dodjeljuje mu direktorijum
	std::string getCurrentDir()const;
	void where();//ispisuje trenutni direktorijum
	void go(std::string);//mjenja trenutni direktorijum na zadani u komandi
	void list(char*, const int);//ispisuje stablo tekuceg direktorijuma sa svim fajlovima i poddirektorijumima
	void listPath(char*, const int);//ispisuje stablo navedene putanje sa svim fajlovima i poddirektorijumima
	void createDirPath(std::string);//kreira direktorijum na zadanoj putanji
	void createFilePath(std::string);//kreira datoteku na zadatoj putanji sa tim imenom
	void createDirName(std::string);//kreira na home direktorijumu direktorijum sa zadanim nazivom
	void createFileName(std::string);//kreira datoteku na home direktorijumu sa zadanim imenom
	void printFile(std::string);//ispisuje sadrzaj navedene datoteke
	int findTextInFile(std::string);//trazi unijeti text u datoteci i vraca prvo pojavljivanje texta
	void findDat(const std::filesystem::path&,const std::filesystem::path&);//pretrazuje da li postoji zadata datoteka na zadanoj putanji
};

