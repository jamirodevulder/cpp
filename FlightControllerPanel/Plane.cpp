#include "pch.h"
#include "Plane.h"
#include "PlaneDataBase.h"



Plane::Plane(std::string PlaneName, std::string Time,int Seats, int Passengers, std::string Destination, std::string TakenBy)
{
	
	planeName = PlaneName;
	time = Time;
	seats = Seats;
	passengers = Passengers;
	destination = Destination;
	takenBy = TakenBy;
	planeID = reinterpret_cast<uint32_t>(this);;

	
}


std::string Plane::GetFlightInfo()
{
	return "ID: " + std::to_string(planeID) + " vliegtuig: " + planeName + " aantal stoellen: " + std::to_string(seats) + " en aantal gereserveerde stoellen: " + std::to_string(passengers) + " en aantal niet gereseveerde stoellen: " + std::to_string(seats - passengers) + " Naar: " + destination + " vlucht administrator: " + takenBy +  " \n";
}


Plane::~Plane()
{
}
void Plane::RemovePlane()
{
	delete this;
}

std::string Plane::GetTakenBy()
{
	return takenBy;
}

void Plane::SetTakenBy(std::string TakenBy)
{
	takenBy = TakenBy;
}

Plane* Plane::ReturnPlane()
{
	return this;
}

int Plane::GetID()
{
	return planeID;
}
