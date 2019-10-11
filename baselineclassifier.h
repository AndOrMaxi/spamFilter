#ifndef _BASELINECLASSIFIER_H_
#define _BASELINECLASSIFIER_H_
#include "Instance.h"
#include "InstancePool.h"
#include<string>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include "classifier.h"
using namespace std;

class BaselineClassifier : public Classifier{
private:
	int private_spam,private_legit;
public:
	void train(const InstancePool& trainingPool);
	bool classify(const Instance& inst);
};

#endif
