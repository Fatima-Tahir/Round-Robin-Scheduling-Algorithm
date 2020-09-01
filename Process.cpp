#include "Process.h"

Process::Process(string name,int a_time,int s_time,Process * tail)
{
	this->arrival_time=a_time;
	this->name=name;
	this->service_time=s_time;

	finish_time=0;
	turnAround_time=0;
	waiting_time=0;
	running_time=service_time;

	this->next=tail;
}

void Process::showDetails()
{
	cout<<"\nName "<<name<<"   Arrival Time = "<<arrival_time<<"   service Time ="<<service_time <<"   Finish Time = "<<finish_time<<"   Turn Around Time = "<<turnAround_time
		<<"   Waiting Time = "<<waiting_time<<endl;
}

Process* Process:: getNext()
{
	return next;
}

int Process ::getArrival_time()
{
	return arrival_time;
}
int Process:: getService_time()
{
	return service_time;
}
void Process:: setFinish_time(int ft)
{
	this->finish_time=ft;
}
void Process:: setTurnAround_time(int ft)
{
	this->turnAround_time=ft;
}
void Process:: setWaiting_time(int ft)
{
	this->waiting_time=ft;
}

int Process:: getFinish_time()
{
	return finish_time;
}
int Process:: getTurnAround_time()
{
	return turnAround_time;
}
int Process:: getWaiting_time()
{
	return waiting_time;
}

int Process:: getRunning_time()
{
	return running_time;
}

void Process:: setRunning_time(int rt)
{
	running_time=rt;
}