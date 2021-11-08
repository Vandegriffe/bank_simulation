//*****************************************************************************************************
//
//		File:					sim1q3s.cpp
//
//		Student:				Jack Vandegriffe
//
//		Assignment:				Program #8
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					April 7, 2021
//
//
//		This header defines node
//
//		 Other files required:
//		1. Customer.h
//      2. Server.h
//      3. Queue.h
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
using namespace std;

//*****************************************************************************************************

#include "Customer.h"
#include "Server.h"
#include "Queue.h"

//*****************************************************************************************************

int fillCustomerArray(Customer cust[]);
bool isAllDone(const Queue<Customer> & custQ, int totalCust, int currCust, Server serv[]);
void processCustomers(Customer cust[], Queue<Customer> & custQ,
	                  int totalCust, int & currCust, int time, ofstream & trace);
void processServers(Server serv[], Queue<Customer> & custQ, int time, ofstream & trace);


//*****************************************************************************************************

int main()
{
	int time = 0,
		totalCust,
		currCust = 0;
	Customer cust[100];
	Server serv[3];
	Queue<Customer> custQ;
	ofstream trace;

	trace.open("trace.txt");

	totalCust = fillCustomerArray(cust);

	while (!(isAllDone(custQ, totalCust, currCust, serv)))
	{
		trace << "\nt = " << time << endl;

		processCustomers(cust, custQ, totalCust, currCust, time, trace);
		processServers(serv, custQ, time, trace);

		time++;
	}

	cout << "All " << totalCust << " customers were processed in " << time << " minutes." << endl;

	trace.close();

	return 0;
}

//*****************************************************************************************************

int fillCustomerArray(Customer cust[])
{
	ifstream f ("customerList.txt");
	int totalCust = 0;

	if (f.is_open())
	{
		while((totalCust < 100) && (f >> cust[totalCust].id) && 
			 (f >> (cust[totalCust].arrivalTime)) && (f >> cust[totalCust].serviceTime))
		{
			totalCust++;
		}
	}

	f.close();

	return totalCust;
}

//*****************************************************************************************************

bool isAllDone(const Queue<Customer> & custQ, int totalCust, int currCust, Server serv [])
{
	bool done = false;

	if ((totalCust == currCust) && (custQ.isEmpty()) && (!serv[0].busy) && 
	   (!serv[1].busy) && (!serv[2].busy))
	{
		done = true;
	}

	return done;
}

//*****************************************************************************************************

void processCustomers(Customer cust [], Queue<Customer> & custQ, 
	                  int totalCust, int & currCust, int time, ofstream & trace)
{
	while ((currCust < totalCust) && (cust[currCust].arrivalTime == time))
	{
		custQ.enqueue(cust[currCust]);

		trace << "cust-id #" << cust[currCust].id << " added to custQ" << endl;

		currCust++;
	}

}

//*****************************************************************************************************

void processServers(Server serv [], Queue<Customer> & custQ, int time, ofstream & trace)
{
	Customer tempCust;

	for (int i = 0; i < 3; ++i)
	{

		if ((!serv[i].busy) || (serv[i].endTime == time))
		{

			if (custQ.dequeue(tempCust))
			{
				serv[i].busy = true;
				serv[i].custId = tempCust.id; 
				serv[i].endTime = tempCust.serviceTime + time;   
				trace << "S" << i << " start serving cust-id #" << tempCust.id 
					  << " service length = " << tempCust.serviceTime 
					  << ", service ends at t = " << serv[i].endTime << endl;
			}
			else
			{
				serv[i].busy = false;
				trace << "S" << i << " is not busy" << endl;
			}

		}
		else
		{
			trace << "S" << i << " serving cust-id #" 
				  << serv[i].custId << " until t = " << serv[i].endTime << endl;
		}

	}
}

//*****************************************************************************************************

/*

All 49 customers were processed in 76 minutes.

*/