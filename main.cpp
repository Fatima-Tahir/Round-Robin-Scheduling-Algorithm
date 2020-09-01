#include "Process.h"
#include "ProcessQueue.h"
#include "ProcessSingleList.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	//++++++++++++++++READ FROM FILE AND INSERT INTO LIST

	ProcessSingleList  l1;
	float avg_waitingTime=0,avg_turnAroundTime=0;
	ProcessQueue circularList;
	string name;
	int arr_t=0, ser_t=0,no_of_proccess=0,time_slice=0;
	ifstream inf("input.txt");
	if(!inf)
	{
		cout<<"File Opening failed\n";
	}
	else
	{
		inf>>no_of_proccess>>time_slice;
		while(inf>>name>>arr_t>>ser_t)
		{
			Process obj(name,arr_t,ser_t,NULL);
			l1.insertAtLast(obj);
		}
	}
	l1.sort();

	//+++++++ADD PROCESSES IN CIRCULAR LIST

	Process * cur=l1.gethead();
	Process * temp1=cur;
	while(cur->getArrival_time()==cur->getNext()->getArrival_time())
	{
		Process * temp=cur;
		circularList.insert(*cur);
		cur=cur->getNext();
		l1.delete1(temp);
	}
	circularList.insert(*cur);
	temp1=cur;
	l1.deleteAtStart();
	
	//cout<<"++++++++++++++++++++START EXECUTING+++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	int time=0,finish=0;
	bool flag=false;

	Process * current=circularList.getHead();
	while(!circularList.isEmpty())
	{
		if(time>=time_slice)
		{
			time=0;
			if(flag==false)
			{
				current=current->getNext();
			}
			flag=false;
		}

		if(current->getRunning_time() <= 0)
		{
			current->setFinish_time(finish);
			int a =current->getFinish_time();
			current->setTurnAround_time(a-current->getArrival_time());
			int b=current->getTurnAround_time();
			current->setWaiting_time(b-current->getService_time());

			current->showDetails();

			avg_waitingTime=avg_waitingTime+current->getWaiting_time();
			avg_turnAroundTime=avg_turnAroundTime+ current->getTurnAround_time();

			Process * temp=current;
			circularList.remove(temp);
		}
		else if(current->getRunning_time() <= time_slice && current->getRunning_time() > 0)
		{
			
			time=time+time_slice;
			finish+=current->getRunning_time();
			current->setRunning_time(0);
			current->setFinish_time(finish);
			int a =current->getFinish_time();
			current->setTurnAround_time(a-current->getArrival_time());
			int b=current->getTurnAround_time();
			current->setWaiting_time(b-current->getService_time());

			current->showDetails();

			avg_waitingTime=avg_waitingTime+current->getWaiting_time();
			avg_turnAroundTime=avg_turnAroundTime+ current->getTurnAround_time();

			Process * temp=current;
			if(flag==false)
			{
				current=current->getNext();
				flag=true;
			}
			circularList.remove(temp);

		}
		else if(current->getRunning_time() >= time_slice)
		{
			int a=current->getRunning_time()-time_slice;
			current->setRunning_time(a);
			time=time+time_slice;
			finish+=time_slice;
		}

		if(!l1.isEmpty())
		{
			if(finish>=l1.gethead()->getArrival_time())
			{
				Process * cur=l1.gethead();
				Process * temp1=cur;
				if(cur->getNext() != NULL)
				{
					while(cur->getArrival_time()==cur->getNext()->getArrival_time())
					{
						Process * temp=cur;
						circularList.insertAfter(current,*cur);
						cur=cur->getNext();
						l1.delete1(temp);
					}
				}
				circularList.insertAfter(current,*cur);
				temp1=cur;
				l1.delete1(temp1);
			}
		}
	}

	cout<<"\nAverage waiting Time = "<<(avg_waitingTime/no_of_proccess);
	cout<<"\nAverage TurnAround Time = "<<(avg_turnAroundTime/no_of_proccess);
	cout<<endl;
	return 0;
}
