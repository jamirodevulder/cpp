#pragma once
#include "User.h"
#include "PlaneDataBase.h"
#include "UserDataBase.h"
#include "LoginPanel.h"
class Admin
{
public:
	Admin();
	void chooseOption();
	void GetUserThatIsLoggedIn(User thisUSer);
	void AssignPlane();
	void GetAllFlights();
	~Admin();
	void GetAllUsers();
	void CreateNewUser();
private:
	User* loggedInUser;
	Plane* iNeedToUseThisPlane;
	static PlaneDataBase _PlaneDataBase;
	static UserDataBase _UserDataBase;
	
};

