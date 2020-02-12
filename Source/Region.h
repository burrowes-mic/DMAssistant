#ifndef REGION_H
#define REGION_H

#include "Category.h"

#include <vector>

class Region
{
   DECLARE_CLOSED_CATEGORY(Region)

public:
   Region(std::string name, std::vector<double>& raceScales);

   std::string GetName() const { return mName; }
   double GetRaceScale(int raceIndex) const { return mRaceScales[raceIndex]; }

   static Region* ParseCsvLine(std::string line);

private:
   static double _FactorizeRaceScale(double scale);

   std::string mName;
   std::vector<double> mRaceScales;
};

#endif