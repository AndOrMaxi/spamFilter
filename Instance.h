#ifndef _INSTANCE_H_
#define _INSTANCE_H_
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Instance
{
      private:
              unsigned numberOfFeatures;
	          bool messageCategory;
	          string file;
	          string* itsFeature;
	          float* itsScore;
              unsigned* itsFeatureID;
              
      public:
             Instance(unsigned features = 0);
             unsigned getNumberOfFeatures() const;
             Instance(const Instance& original);
             ~Instance();
             void setCategory(bool category);
             bool getCategory() const;
             void setFileName(const string& fileName);
             string getFileName() const;
             void setFeature(unsigned i, const string& feature, unsigned featureID, float score);
             string getFeature(unsigned i) const;
             unsigned getFeatureID(unsigned i) const;
             float getScore(unsigned i) const;
             Instance& operator=(const Instance& right);
             friend ostream& operator<<(ostream& out, const Instance& inst);
             friend istream& operator>>(istream& in, Instance& inst);
             
};
#endif
