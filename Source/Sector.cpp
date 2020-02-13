#include "Sector.h"

#include "Race.h"

#include <sstream>

#define FIELD_COUNT 4
#define CENTERING_COEF 0.6

DEFINE_CLOSED_CATEGORY(Sector)

Sector::Sector(std::string name, double weight, double ruralScale, double urbanScale)
   : INITIALIZE_CLOSED_CATEGORY(Sector)
   , mName(name)
   , mWeight(weight)
   , mRuralScale(ruralScale)
   , mUrbanScale(urbanScale)
{}

double Sector::GetWeight(double urbanization) const
{
   return mWeight * _CalculateUrbanizationFactor(urbanization);
}

Sector* Sector::ParseCsvLine(std::string line)
{
   std::string name;
   double weight;
   double ruralScale;
   double urbanScale;

   std::string val;
   std::istringstream iline(line);
   int linesRead = 0;
   while(getline(iline, val, ','))
   {
      switch(linesRead)
      {
      case 0:
         name = val;
         break;

      case 1:
         weight = stof(val);
         break;

      case 2:
         ruralScale = stof(val);
         break;

      case 3:
         urbanScale = stof(val);
         break;

      default:
         break;
         //return nullptr;
      }

      ++linesRead;
   }
   
   if(linesRead < FIELD_COUNT)
      return nullptr;

   return new Sector(name, weight, ruralScale, urbanScale);
}

double Sector::_CalculateUrbanizationFactor(double urbanization) const
{
   return 1 + CENTERING_COEF * (urbanization * (mUrbanScale - mRuralScale) + mRuralScale);
}