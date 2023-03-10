class Exception
{
private:
	char msg[100];
public:
	Exception(const char*);
	~Exception();
	void printMsg();
};
