#include "pch.h"
#include "Admin.h"
#include <iostream>
#include "UserDataBase.h"
#include "LoginPanel.h"
#include <limits>
#include <chrono>
#include <thread>


PlaneDataBase Admin::_PlaneDataBase;
UserDataBase Admin::_UserDataBase;

Admin::Admin()
{
	
}

void Admin::chooseOption()
{
	bool AdminLoggedIn = true;
	while (AdminLoggedIn)
	{
		std::cout << "GoedeMiddag! " + loggedInUser->GetUserName() + " \n";
		std::cout << "type het nummer van welke actie die u wild nemen \n";
		std::cout << "1. maak een nieuwe gebruiker aan \n";
		std::cout << "2. toon alle gebruikers \n";
		std::cout << "3. zie alle vliegtuigen \n";
		std::cout << "4. voeg vliegtuig aan medewerker toe \n";
		std::cout << "5. log uit\n";

		std::string keuze;
		std::cin >> keuze;-

		if (keuze == "1")
		{
			CreateNewUser();
		}
		else if (keuze == "5")
		{
			system("CLS");
			LoginPanel login;
			login._UserDataBase = _UserDataBase;
			login._PlaneDataBase = _PlaneDataBase;
			login.Login();
			AdminLoggedIn = false;



		}
		else if (keuze == "2")
		{
			GetAllUsers();
		}
		else if (keuze == "3")
		{
			GetAllFlights();
		}
		else if (keuze == "4")
		{
			AssignPlane();
		}
	}
}



void Admin::GetUserThatIsLoggedIn(User thisUser)
{
	loggedInUser = new User(thisUser);
	
}

void Admin::AssignPlane()
{
	system("CLS");
	std::list<Plane> planes = _PlaneDataBase.GetPlanes();
	std::list<Plane>::iterator it;
	int goodID = 10000;
	int typedID = 0;
	while (goodID != typedID)
	{
		int count = 0;
		for (it = planes.begin(); it != planes.end(); it++)
		{
			

			if (it->GetTakenBy() == "none")
			{
			std::cout << "id: " + std::to_string(count) + " " + it->GetFlightInfo();
			}
			count++;
		}


		std::cout << "\nwelk vliegtuig wild u toevoegen aan een medewerker? \n";
		std::cin >> typedID;
		count = 0;
		for (it = planes.begin(); it != planes.end(); it++)
		{
			

			if (it->GetTakenBy() == "none" && count == typedID)
			{
				
				iNeedToUseThisPlane =  new Plane(*it);
				
				goodID = typedID;
				
			}
			count++;
		}
		if (goodID != typedID)
		{
			std::cout << "dit id word niet herkend......";
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			system("CLS");
		}
		else 
		{
			std::cout << "Vliegtuig succesvol geselecteerd!";
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			system("CLS");
		}
	}
	std::string goodID2 = "oefjioa";
	std::string typedID2 = "jfsakjsakfjakhfsa";

	while (goodID2 != typedID2)
	{
		std::cout << iNeedToUseThisPlane->GetFlightInfo() + "\n";
		std::list<User> users = _UserDataBase.Getusers();
		std::list<User>::iterator it;
		for (it = users.begin(); it != users.end(); it++)
		{

			std::string name = it->GetUserName();
			std::string userpassword = it->GetUserPassword();
			if (!it->GetAdminRights())
			{
				std::cout << "Gebruikersnaam: " + name + "\n";
			}
		}
		std::cout << "\nwelke medewerker wil je koppelen aan dit vliegtuig  type naam van medewerker \n";
		std::cin >> typedID2;

		std::list<Plane> planes = _PlaneDataBase.GetPlanes();
		std::list<Plane>::iterator it2;
		std::list<Plane> randomlist;
		for (it = users.begin(); it != users.end(); it++)
		{


			if (!it->GetAdminRights() && it->GetUserName() == typedID2)
			{
				goodID2 == typedID2;
				
				for (it2 = planes.begin(); it2 != planes.end(); it2++)
				{
					
					if (it2->ReturnPlane()->GetID() == iNeedToUseThisPlane->GetID())
					{
						it2->SetTakenBy(typedID2);						
					}
					randomlist.push_front(*it2->ReturnPlane());
				}
				_PlaneDataBase.UpdateDatabase(randomlist);
				it->AddPlane(iNeedToUseThisPlane);
				return;
			}
		}
		
		
	}
}

void Admin::GetAllFlights()
{
	system("CLS");
	std::list<Plane> planes = _PlaneDataBase.GetPlanes();
	std::list<Plane>::iterator it;
	int count = 0;
	for (it = planes.begin(); it != planes.end(); it++)
	{
		count++;


		std::cout << it->GetFlightInfo();

	}
	std::cout << "klaar? type j \n";
	std::string done;
	while (done != "j")
	{
		std::cin >> done;
		if (done == "j")
		{


			system("CLS");
		}
	}
}
Admin::~Admin()
{
}

void Admin::GetAllUsers()
{
	system("CLS");
	std::list<User> users = _UserDataBase.Getusers();
	std::list<User>::iterator it;
	int count = 0;
	for (it = users.begin(); it != users.end(); it++)
	{
		count++;
		
		std::string name = it->GetUserName();
		std::string userpassword = it->GetUserPassword();
		
		std::cout << "Gebruikersnaam: " + name + " wachtwoord: " + userpassword + "\n";

	}
	std::cout << "klaar? type j \n";
	std::string done;
	while (done != "j")
	{
		std::cin >> done;
		if (done == "j")
		{


			system("CLS");
		}
	}
}

void Admin::CreateNewUser()
{
	system("CLS");
	

	std::string username;
	std::string password;
	std::string phoneNumber;
	std::string adminacc;
	std::cout << "U gaat nu een nieuw account maken. \n";
	std::cout << "Gebruikersnaam:";
	std::cin >> username;
	system("CLS");
	std::cout << "wachtwoord:";
	std::cin >> password;
	system("CLS");
	std::cout << "Telefoonnummer:";
	std::cin >> phoneNumber;
	system("CLS");

	bool adminrights = false;
	bool loopQuestion = true;
	while (loopQuestion)
	{
		std::cout << "Admin account j/n? \n";
		std::cin >> adminacc;
		system("CLS");



		
		if (adminacc == "j")
		{
			adminrights = true;
			loopQuestion = false;
		}
		else if (adminacc == "n")
		{
			adminrights = false;
			loopQuestion = false;
		}

		std::cout << "geen geldige keuze \n";
	}


	system("CLS");

	std::list<Plane> Myplanes;
	std::list<User> users = _UserDataBase.Getusers();
	users.push_front(User(username, phoneNumber, adminrights, password, Myplanes));
	_UserDataBase.UpdateUsers(users);

}

