#include "Region.h"

#include "Race.h"

#include <sstream>

#define CENTERING_COEF 0.3

DEFINE_CLOSED_CATEGORY(Region)

Region::Region(std::string name, std::vector<double>& raceScales)
   : INITIALIZE_CLOSED_CATEGORY(Region)
   , mName(name)
   , mRaceScales(raceScales)
{}

Region* Region::ParseCsvLine(std::string line)
{
   std::string name;
   std::vector<double> raceScales;

   std::string val;
   std::istringstream iline(line);
   int linesRead = 0;
   while(getline(iline, val, ','))
   {
      if(linesRead == 0)
         name = val;
      else if(linesRead <= Race::GetCategory().Size())
         raceScales.push_back(_FactorizeRaceScale(stod(val)));

      ++linesRead;
   }

   if(linesRead < Race::GetCategory().Size() + 1)
      return nullptr;

   return new Region(name, raceScales);
}

double Region::_FactorizeRaceScale(double scale)
{
   return scale;
}