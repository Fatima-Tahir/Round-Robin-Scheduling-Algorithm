#pragma once

#include<string>
#include<iostream>
using namespace std;
class Process
{
	friend class ProcessQueue;
	friend class ProcessSingleList;
private:
	string name;
	int arrival_time;
	int service_time;
	int running_time;
	int finish_time;
	int turnAround_time;
	int waiting_time;
	Process* next;

public:
	Process(string name,int a_time,int s_time,Process * tail);
	void showDetails();
	Process* getNext();
	int getArrival_time();
	int getService_time();
	int getFinish_time();
	int getTurnAround_time();
	int getWaiting_time();
	int getRunning_time();


	void setRunning_time(int);
	void setFinish_time(int);
	void setTurnAround_time(int);
	void setWaiting_time(int);

};

