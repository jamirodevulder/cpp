#pragma once;
#include "User.h";
#include "PlaneDataBase.h";
class Worker
{
public:
	Worker();
	void UserThatIsWorker(User ThisWorker);
	void LoadOwnDatabase(PlaneDataBase planeDataBase);
	void ChooseMenu();
	void GetAllFlights();
	~Worker();
private:
	User* meAsWorker;
	PlaneDataBase _PlaneDatabase;
};

