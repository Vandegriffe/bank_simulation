//*****************************************************************************************************
//
//		File:					Customer.h
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
//		This header defines customer struct
//
//		 Other files required:
//		1. none
//
//*****************************************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H

//*****************************************************************************************************

struct Customer
{
	int id,
		arrivalTime,
		serviceTime;

	Customer()
	{
		id = 0;
		arrivalTime = 0;
		serviceTime = 0;
	}
};

//*****************************************************************************************************

#endif