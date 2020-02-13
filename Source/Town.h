#ifndef TOWN_H
#define TOWN_H

#include <vector>

class Region;
class NpcMold;

class Town
{
public:
   Town(Region& region, std::vector<NpcMold>& npcMolds);

   void Print() const;

   static double CalculateUrbanization(int population);
   static std::string CalculateTownType(int population);

private:
   Region& mRegion;
   std::vector<NpcMold> mNpcMolds;
};

#endif