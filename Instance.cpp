#include"Instance.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


//
Instance::Instance(unsigned features)
{
     numberOfFeatures = features;
     itsFeature = new string[numberOfFeatures];
	 itsFeatureID = new unsigned[numberOfFeatures];
	 itsScore = new float[numberOfFeatures];                        
}


//
unsigned Instance::getNumberOfFeatures() const
{
    return numberOfFeatures;     
}


//
Instance::Instance(const Instance& original)
{
    numberOfFeatures = original.numberOfFeatures;
	itsFeature = new string[numberOfFeatures];
	itsFeatureID = new unsigned[numberOfFeatures];
    itsScore = new float[numberOfFeatures];
    file = original.file;
    messageCategory = original.messageCategory;

    for (unsigned i=0; i<numberOfFeatures; i++)
    {
		itsFeature[i] = original.itsFeature[i];
        itsFeatureID[i]=original.itsFeatureID[i];
        itsScore[i]=original.itsScore[i];
    }
}


//
Instance::~Instance()
{
         delete[] itsFeature;
         cout << "deleting feature" << endl;
         delete[] itsFeatureID;
         cout << "deleting featureID" << endl;
         delete[] itsScore;       
         cout << "deleting score" << endl;
}


//
void Instance::setCategory(bool category)
{
     messageCategory = category;
}


//
bool Instance::getCategory() const
{
    return messageCategory; 
}


//
void Instance::setFileName(const string& fileName)
{
     file=fileName;
}


//
string Instance::getFileName() const
{
      return file; 
}


//
void Instance::setFeature(unsigned i, const string& feature, unsigned featureID, float score)
{
    itsFeature[i]=feature;
    itsFeatureID[i]=featureID;
    itsScore[i]=score;
}


//
string Instance::getFeature(unsigned i) const
{
    return itsFeature[i];
}


//
unsigned Instance::getFeatureID(unsigned i) const
{
     return itsFeatureID[i];    
}


//
float Instance::getScore(unsigned i) const
{
      return itsScore[i];
}


//
Instance& Instance::operator=(const Instance& right)
{
      if (this == &right)
         return *this;
         
      delete [] itsFeature;
      delete [] itsScore;
      delete [] itsFeatureID;
      
      numberOfFeatures = right.numberOfFeatures;
	  itsFeature = new string[numberOfFeatures];
	  itsFeatureID = new unsigned[numberOfFeatures];
      itsScore = new float[numberOfFeatures];
      file = right.file;
      messageCategory = right.messageCategory;

      for (unsigned i=0; i<numberOfFeatures; i++)
      {
    	  itsFeature[i] = right.itsFeature[i];
          itsFeatureID[i]= right.itsFeatureID[i];
          itsScore[i]= right.itsScore[i];
      }              
}


//
ostream& operator<<(ostream& out, const Instance& inst)
{
    string category;
    
    if (inst.messageCategory == false)
        category = "ham";
    else
        category = "spam";
        
    out << "< message file = \"" << inst.file << "\" category = \"" << category << "\" features = \"" << inst.numberOfFeatures << "\" >" << endl;
    
    for (unsigned i=0; i<inst.numberOfFeatures; i++)
        out << "< feature token = \"" << inst.itsFeature[i] << "\" id = \"" << inst.itsFeatureID[i] << "\" tfidf = \"" << inst.itsScore[i] << "\" />" << endl;   
    
    out << "</ message >" << endl << endl; 
    return out;
}


//
istream& operator>>(istream& in, Instance& inst)
{
     delete [] inst.itsFeature;
     delete [] inst.itsScore;
     delete [] inst.itsFeatureID;
     
     string word;
    
     in >> word;
     in >> word;
     inst.file = word.substr(1,(word.length()-2)).c_str();;
     in >> word;
     in >> word;
     in >> word;
     if (word == "\"spam\"")
         inst.messageCategory = true;
     else
         inst.messageCategory = false;
     in >> word;
     in >> word;
     in >> word;
     inst.numberOfFeatures=atoi(word.substr(1,(word.length()-2)).c_str());
     inst.itsFeature = new string [inst.numberOfFeatures];    
     inst.itsFeatureID = new unsigned [inst.numberOfFeatures]; 
     inst.itsScore = new float [inst.numberOfFeatures]; 
     for (unsigned i = 0; i < inst.numberOfFeatures; i++)
     {
         while (in >> word)
         {
             if (word == "token")
             {
                 in >> word;   
                 in >> word;  
                 inst.itsFeature[i] = word.substr(1,(word.length()-2)).c_str();
                 in >> word;
                 in >> word;
                 in >> word;
                 inst.itsFeatureID[i] = atoi(word.substr(1,(word.length()-2)).c_str());
                 in >> word;
                 in >> word;
                 in >> word;
                 inst.itsScore[i] = atof(word.substr(1,(word.length()-2)).c_str());
                 break;
             }
         }
     }
     return in;    
}
