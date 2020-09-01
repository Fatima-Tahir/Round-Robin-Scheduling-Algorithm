#pragma once

#include "Process.h"
#include<string>
#include<queue>
#include<iostream>
using namespace std;
class ProcessQueue
{
private:
	Process * head;
public:
	ProcessQueue();
	~ProcessQueue();
	bool isEmpty();
	Process* getHead(); 
	void insert(const Process& pro);
	void insertAfter(Process * prev,const Process &newProcess);
	void showList();
	void remove(const Process * obj);
};


