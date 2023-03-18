#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#define PLAYERINTERFACE __declspec(dllexport)
#include <string>
class PLAYERINTERFACE Interfacepl
{
public:
	static Interfacepl* CreateInterface();
	virtual void init(std::string uri) = 0;
	virtual wchar_t* charTowchar(char* oc) = 0;
	virtual void play() = 0;
	virtual void test() = 0;
};

#endif

