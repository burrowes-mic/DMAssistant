#include "TownGenerator.h"
#include "Town.h"
#include "Region.h"

#include <iostream>

#define SECTOR_FILEPATH "Sectors.dma"
#define PROFESSION_FILEPATH "Professions.dma"
#define RACE_FILEPATH "Races.dma"
#define REGION_FILEPATH "Regions.dma"

using namespace std;

int main(int argc, char* argv[])
{
   TownGenerator* generator = TownGenerator::Create(SECTOR_FILEPATH, PROFESSION_FILEPATH, RACE_FILEPATH, REGION_FILEPATH);
   if(!generator)
   {
      cout << "Unable to create TownGenerator!" << endl;
      return -1;
   }
   Town* town = generator->GenerateTown(10000, Region::GetCategory()[0]);
   town->Print();

   return 0;
}