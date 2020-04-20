#pragma once
#include "UserDataBase.h"
#include "PlaneDataBase.h"
#include "Admin.h"
#include "Worker.h"
class LoginPanel
{
public:
	LoginPanel();
	~LoginPanel();
	static UserDataBase _UserDataBase;
	static PlaneDataBase _PlaneDataBase;
	void Login();
private:
	bool loggedIn;
	
};

