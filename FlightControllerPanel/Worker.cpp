#include "pch.h"
#include "Worker.h"
#include <iostream>
#include "LoginPanel.h"


Worker::Worker()
{


}

void Worker::UserThatIsWorker(User ThisWorker)
{
	meAsWorker = new User(ThisWorker);
}
void Worker::LoadOwnDatabase(PlaneDataBase planeDataBase)
{
	_PlaneDatabase = planeDataBase;
}


void Worker::ChooseMenu()
{
	bool WorkerLoggedIn = true;
	while (WorkerLoggedIn)
	{
		std::cout << "GoedeMiddag! " + meAsWorker->GetUserName() + " \n";
		std::cout << "type het nummer van welke actie die u wild nemen \n";
		std::cout << "1. zie alle vliegtuigen \n";
		std::cout << "2. log uit\n";

		std::string keuze;
		std::cin >> keuze;

		if (keuze == "1")
		{
			GetAllFlights();
		}
		else if (keuze == "2")
		{
			system("CLS");
			LoginPanel login;
			login._PlaneDataBase = _PlaneDatabase;
			login.Login();
			WorkerLoggedIn = false;
		}
		
	}
}

void Worker::GetAllFlights()
{
	system("CLS");
	std::list<Plane> planes = _PlaneDatabase.GetPlanes();
	std::list<Plane>::iterator it;
	int count = 0;
	for (it = planes.begin(); it != planes.end(); it++)
	{
		count++;
		if (it->GetTakenBy() == meAsWorker->GetUserName())
		{
			std::cout << it->GetFlightInfo();
		}
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

Worker::~Worker()
{
}
