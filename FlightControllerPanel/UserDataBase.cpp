#include "pch.h"
#include "UserDataBase.h"
#include <iostream>



UserDataBase::UserDataBase()
{
	LoadDataBase();
}
UserDataBase::~UserDataBase()
{
}

void UserDataBase::LoadDataBase()
{
	std::list<Plane> Myplanes;
	users.push_front(User("jamiro", "0645810281", true, "jampot112", Myplanes));
	users.push_front(User("kees", "0645810281", false, "jampot112", Myplanes));
	
}

User UserDataBase::CheckforLoginDetails(std::string username, std::string password)
{
	std::list<User>::iterator it;
	int count = 0;
	for (it = users.begin(); it != users.end(); it++)
	{
		count++;
		// Access the object through iterator
		std::string name = it->GetUserName();
		std::string userpassword = it->GetUserPassword();
		if (name == username && userpassword == password)
		{
			return *it;
		}
		
		
		

	}
	std::list<Plane> myplane;

	return User("0", "0", false, "0", myplane);
}

std::list<User> UserDataBase::Getusers()
{
	return users;
}

void UserDataBase::UpdateUsers(std::list<User> newUsers)
{
	users = newUsers;
}
