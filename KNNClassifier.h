#ifndef _KNNCLASSIFIER_H_
#define _KNNCLASSIFIER_H_
#include "Instance.h"
#include "InstancePool.h"
#include<string>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include "Instance.h"
#include "classifier.h"

using namespace std;

class KNNClassifier : public Classifier{
private:
	string *sort;
	int k;
	InstancePool store_trainPool;
public:
	KNNClassifier(unsigned short kln=5);
	static unsigned short distance(const Instance& inst1, const Instance& inst2);
	void train(const InstancePool& trainingPool);
	bool classify(const Instance& inst);
	~KNNClassifier();

};

#endif  
