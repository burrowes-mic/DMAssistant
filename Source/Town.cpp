#include "Town.h"

#include "Region.h"
#include "NpcMold.h"
#include "Race.h"
#include "Sector.h"
#include "Profession.h"

#include <iostream>
#include <iomanip>
#include <map>

Town::Town(Region& region, std::vector<NpcMold>& npcMolds)
   : mRegion(region)
   , mNpcMolds(npcMolds)
{}

void Town::Print() const
{
   std::map<int, int> raceCounts, sectorCounts, professionCounts;
   for(auto iter = mNpcMolds.begin(); iter != mNpcMolds.end(); ++iter)
   {
      int raceIndex = iter->GetRace().GetCategoryIndex();
      int sectorIndex = iter->GetProfession().GetSector().GetCategoryIndex();
      int professionIndex = iter->GetProfession().GetCategoryIndex();

      if(raceCounts.count(raceIndex))
         raceCounts[raceIndex] += 1;
      else
         raceCounts.emplace(raceIndex, 1);

      if(sectorCounts.count(sectorIndex))
         sectorCounts[sectorIndex] += 1;
      else
         sectorCounts.emplace(sectorIndex, 1);

      if(professionCounts.count(professionIndex))
         professionCounts[professionIndex] += 1;
      else
         professionCounts.emplace(professionIndex, 1);
   }


   Category<Race>& raceCategory = Race::GetCategory();
   Category<Sector>& sectorCategory = Sector::GetCategory();
   Category<Profession>& professionCategory = Profession::GetCategory();
   double percentFactor = 100.0 / mNpcMolds.size();

   std::cout << "Citizens: " << mNpcMolds.size() << "\n";
   std::cout << CalculateTownType((int)mNpcMolds.size()) << " (Urbanization: " << std::setprecision(4) << CalculateUrbanization((int)mNpcMolds.size()) << ")\n";
   std::cout << "Region: " << mRegion.GetName() << "\n\n";

   std::cout << "Races:\n";
   for(int i = 0; i < raceCategory.Size(); ++i)
   {
      if(raceCounts.count(i))
         std::cout << std::setw(12) << raceCategory[i].GetName() << ": " << std::setw(5) << raceCounts[i] << std::setw(7) << "(" << std::setprecision(3) << (double)raceCounts[i] * percentFactor << "%)\n";
      else
         std::cout << std::setw(12) << raceCategory[i].GetName() << ":" << std::setw(5) << "0" << std::setw(7) << "(0.00)%\n";
   }
   std::cout << "\n";

   std::cout << "Sectors:\n";
   for(int i = 0; i < sectorCategory.Size(); ++i)
   {
      if(sectorCounts.count(i))
         std::cout << std::setw(24) << sectorCategory[i].GetName() << ": " << std::setw(4) << sectorCounts[i] << std::setw(7) << "(" << std::setprecision(3) << (double)sectorCounts[i] * percentFactor << "%)\n";
      else
         std::cout << std::setw(24) << sectorCategory[i].GetName() << ": " << std::setw(4) << "0" << std::setw(7) << "(0.00)%\n";
   }
   std::cout << "\n";

   std::cout << "Professions:\n";
   for(int i = 0; i < professionCategory.Size(); ++i)
   {
      if(professionCounts.count(i))
         std::cout << std::setw(20) << professionCategory[i].GetName() << ": " << std::setw(4) << professionCounts[i] << std::setw(7) << "(" << std::setprecision(3) << (double)professionCounts[i] * percentFactor << "%)\n";
   }
   std::cout << "\n";
}

double Town::CalculateUrbanization(int population)
{
   return pow((double)population / 100000.0, 0.15);
}

std::string Town::CalculateTownType(int population)
{
   if(population <= 80)
      return "Thorp";
   else if(population < 400)
      return "Hamlet";
   else if(population < 900)
      return "Village";
   else if(population < 2000)
      return "Small Town";
   else if(population < 5000)
      return "Large Town";
   else if(population < 12000)
      return "Small City";
   else if(population < 25000)
      return "Large City";
   else
      return "Metropolis";
}