#include"InstancePool.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

//
InstancePool::InstancePool()
{
                            
}


//
InstancePool::InstancePool(const InstancePool& original)
{
    for (unsigned i=0; i < original.pool.size(); i++)
        pool.push_back(original.pool[i]);
}


//
InstancePool::~InstancePool()
{
       cout << "deleting" << endl;                       
}


//
unsigned InstancePool::getNumberOfInstances() const
{
     return pool.size();         
}


//
const Instance& InstancePool::operator[](unsigned index)const
{
    return pool[index];  
}


//
vector<string> InstancePool::getFeatures() const
{
    bool exists;
    string feat;
    vector<string> features;
    
    
    for (unsigned i=0; i < pool.size(); i++) 
    {
        for (unsigned j=0; j < pool[i].getNumberOfFeatures(); j++)
        {
            feat = pool[i].getFeature(j);   
            exists = (find(features.begin(), features.end(), feat) != features.end());  
            if (!exists)
                features.push_back(feat);
        }
    }
    
    return features;
}


//
vector<unsigned> InstancePool::getFeatureIDs() const
{
    vector<unsigned> featureIDs;
    vector<string> features;
    bool exists;
    string feat;  
    
    for (unsigned i=0; i < pool.size(); i++) 
    {
        for (unsigned j=0; j < pool[i].getNumberOfFeatures(); j++)
        {
            feat = pool[i].getFeature(j);   
            exists = (find(features.begin(), features.end(), feat) != features.end());  
            if (!exists)
                features.push_back(feat);
                featureIDs.push_back(pool[i].getFeatureID(j));
        }
    }
    
    return featureIDs;       
}


//
InstancePool& InstancePool::operator=(const InstancePool& right)
{
    if (this == &right) 
       return *this;
       
    pool.clear();
    
    for (unsigned i = 0;  i< right.pool.size(); i++)
    {
        pool.push_back(right.pool[i]);
    } 
    
    return *this;                            
}


//
istream& operator>>(istream& in, InstancePool& ip)
{
     ip.pool.clear();
     string word;
     while (in >> word)
     {
         if (word == "file")
         {
             Instance inst;
             in >> inst;
             ip.pool.push_back(inst);
         }
                 
     }
     return in; 
}


//
ostream& operator<<(ostream& out, const InstancePool& ip)
{
     out << "< messagecollection messages = \"" << ip.pool.size() << "\" >" << endl << endl;  
     for (unsigned i=0; i<ip.pool.size(); i++)
         out << ip[i];
     out << "</ messagecollection >" << endl << endl; 
}
