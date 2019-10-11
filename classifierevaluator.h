#ifndef _CLASSIFIEREVALUATOR_H_
#define _CLASSIFIEREVALUATOR_H_
#include<string>
#include<iostream>
#include "Classifier.h"
#include "Instance.h"
#include "InstancePool.h"
using namespace std;

class ClassifierEvaluator{
private:
	int Total;
	int TruePositives;
	int FalsePositives;
	string *axiologitis;
	
public:
	ClassifierEvaluator(Classifier& classifier,const InstancePool& trainingPool,const InstancePool& testPool);
	float getAccuracy() const;
	float getPrecision() const;
	float getRecall() const;
};

#endif
