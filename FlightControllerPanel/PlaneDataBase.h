#pragma once
#include <list>
#include "Plane.h"
class PlaneDataBase
{
public:
	PlaneDataBase();
	~PlaneDataBase();
	std::list<Plane> GetPlanes();
	void UpdateDatabase(std::list<Plane> newPlanes);
	void LoadDataBase();
	

private:
	std::list<Plane> allPlanes;
};

