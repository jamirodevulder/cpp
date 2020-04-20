#include "pch.h"
#include "PlaneDataBase.h"


PlaneDataBase::PlaneDataBase()
{
	LoadDataBase();
}


PlaneDataBase::~PlaneDataBase()
{
}

std::list<Plane> PlaneDataBase::GetPlanes()
{
	return allPlanes;
}

void PlaneDataBase::UpdateDatabase(std::list<Plane> newPlanes)
{
	allPlanes = newPlanes;
}

void PlaneDataBase::LoadDataBase()
{
	allPlanes.push_front(Plane("klm", "10:00", 100, 52, "London", "none"));
	allPlanes.push_front(Plane("Tui", "12:00", 100, 42, "Manchester", "none"));
}
