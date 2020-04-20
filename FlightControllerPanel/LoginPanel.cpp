#include "pch.h"
#include "LoginPanel.h"
#include <iostream>
#include <chrono>
#include <thread>

UserDataBase LoginPanel::_UserDataBase;
PlaneDataBase LoginPanel::_PlaneDataBase;
LoginPanel::LoginPanel()
{
	loggedIn = false;
}


LoginPanel::~LoginPanel()
{
}

void LoginPanel::Login()
{
	while (!loggedIn)
	{
		std::string username;
		std::string password;
		std::cout << "Gebruikersnaam:";
		std::cin >> username;
		system("CLS");
		std::cout << "wachtwoord:";
		std::cin >> password;
		system("CLS");
		User user = _UserDataBase.CheckforLoginDetails(username, password);
		
		if (user.GetUserName() != "0")
		{
			loggedIn = true;

			if (user.GetAdminRights() == true)
			{
				Admin _Admin;
				_Admin.GetUserThatIsLoggedIn(user);
				_Admin.chooseOption();
			}
			else
			{
				Worker _Worker;
				_Worker.LoadOwnDatabase(_PlaneDataBase);
				_Worker.UserThatIsWorker(user);
				_Worker.ChooseMenu();


			}
		}
		else
		{
			std::cout << "verkeerde inlog gegevens probeer het opnieuw....";
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			system("CLS");
			
		}



	}


}
