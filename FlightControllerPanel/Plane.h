#pragma once
#include "string"
#include <atomic> 

class Plane
{
	
public:
	Plane(std::string PlaneName, std::string Time, int Seats, int Passengers, std::string Destination, std::string TakenBy);
	std::string GetFlightInfo();
	~Plane();
	void RemovePlane();
	std::string GetTakenBy();
	void SetTakenBy(std::string TakenBy);
	Plane* ReturnPlane();
	int GetID();
	
private:
	std::string planeName;
	std::string time;
	int seats;
	int passengers;
	std::string destination;
	std::string takenBy;
	int planeID;
	
	

};

