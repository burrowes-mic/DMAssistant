#ifndef SECTOR_H
#define SECTOR_H

#include "Category.h"
#include "Profession.h"

#include <string>
#include <vector>

class Profession;
class Race;

class Sector
{
   DECLARE_CLOSED_CATEGORY(Sector)

public:
   Sector(std::string name, double weight, double ruralScale, double urbanScale);

   std::string  GetName() const { return mName; }
   double GetWeight(double urbanization) const;
   const std::vector<Profession*>&  GetProfessions() const { return mProfessions; }

   void AddNewProfession(std::string name, double weight, double urbanizationScale) { mProfessions.push_back(new Profession(name, *this, weight, urbanizationScale)); }

   static Sector* ParseCsvLine(std::string line);

private:
   double _CalculateUrbanizationFactor(double urbanization) const;

   std::string mName;
   double mWeight;
   double mRuralScale;
   double mUrbanScale;

   std::vector<Profession*> mProfessions;
};

#endif