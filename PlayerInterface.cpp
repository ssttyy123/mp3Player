#include "PlayerInterface.h"
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#pragma comment (lib, "winmm.lib")

class Player :public Interfacepl
{
public:
	void init(std::string uri);
	wchar_t* charTowchar(char* oc);
	void play();
	void test();
private:
	std::string order;
};
void Player::init(std::string uri) {
	this->order = "open " + uri + " alias song";
}
wchar_t* Player::charTowchar(char* oc)
{
	int num = MultiByteToWideChar(CP_ACP, 0, oc, -1, NULL, 0);
	wchar_t* wp = new wchar_t[num];
	MultiByteToWideChar(CP_ACP, 0, oc, -1, wp, num);
	return wp;
}
void Player::play() {
	char* tu = new char[this->order.size()+1];
	strcpy_s(tu, this->order.size()+1, this->order.c_str());
	mciSendString(charTowchar(tu), NULL, 0, NULL);
	mciSendString(TEXT("play song wait"), NULL, 0, NULL);
}
void Player::test() { std::cout << "test" << std::endl; }

Interfacepl* Interfacepl::CreateInterface()
{
	return new Player();
}
