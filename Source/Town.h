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

private:
   Region& mRegion;
   std::vector<NpcMold> mNpcMolds;
};

#endif