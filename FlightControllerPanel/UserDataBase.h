#pragma once
#include "user.h"
#include "list"
#include <iterator>
class UserDataBase
{
public:
	UserDataBase();
	~UserDataBase();
	void LoadDataBase();
	User CheckforLoginDetails(std::string username, std::string password);
	std::list<User> Getusers();
	void UpdateUsers(std::list<User> newUsers);
private:
	std::list<User> users;
	int errorCount;
};

