#include "pch.h"
#include "User.h"


User::User(std::string Username, std::string Phonenumber, bool Admin, std::string Password, std::list<Plane> Planes)
{
	username = Username;
	phonenumber = Phonenumber;
	admin = Admin;
	password = Password;
	planes = Planes;
}

User::~User()
{
}

std::string User::GetUserName()
{
	return username;
}
std::string User::GetUserPassword()
{
	return password;
}

void User::AddPlane(Plane* PlaneToAdd)
{
	planes.push_front(*PlaneToAdd);
}

bool User::GetAdminRights()
{
	return admin;
}
