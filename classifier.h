#ifndef _CLASSIFIER_H_
#define _CLASSIFIER_H_
#include "Instance.h"
#include "InstancePool.h"
#include<string>
#include<iostream>
#include<sstream>
#include<cstdlib>

using namespace std;

class Classifier{

public:
	virtual ~Classifier();
	virtual void train(const InstancePool& trainingPool)=0;
	virtual bool classify(const Instance& inst) =0;
	
};

#endif
