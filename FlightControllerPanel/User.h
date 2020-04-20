#pragma once
#include "string"
#include "Plane.h";
#include <list>
class User
{
public:
	
	User(std::string Username, std::string Phonenumber, bool Admin, std::string Password, std::list<Plane> Planes);


	~User();
	std::string GetUserName();
	std::string GetUserPassword();
	void AddPlane(Plane* PlaneToAdd);
	bool GetAdminRights();

private:
	std::string username;
	std::string phonenumber;
	bool admin;
	std::string password;
	std::list<Plane> planes;

};

