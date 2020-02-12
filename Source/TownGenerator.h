#ifndef TOWN_GENERATOR_H
#define TOWN_GENERATOR_H

#include <vector>
#include <string.h>

class Town;
class Region;

class TownGenerator
{
public:
   Town* GenerateTown(int size, Region& region); 

   static TownGenerator* Create(std::string sectorFilepath, std::string professionFilepath, std::string raceFilepath, std::string regionFilepath);
};

#endif