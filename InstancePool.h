#ifndef _INSTANCEPOOL_H_
#define _INSTANCEPOOL_H_
#include "instance.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

class InstancePool
{
      private:
              vector<Instance> pool;
      public:
             InstancePool();
             InstancePool(const InstancePool& original);
             ~InstancePool();
             unsigned getNumberOfInstances() const;
             const Instance& operator[](unsigned index)const;
             vector<string> getFeatures() const;
             vector<unsigned> getFeatureIDs() const;
             InstancePool& operator=(const InstancePool& right);
             friend istream& operator>>(istream& in, InstancePool& ip);
             friend ostream& operator<<(ostream& out, const InstancePool& ip);
             


};
#endif
