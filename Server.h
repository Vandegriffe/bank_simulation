//*****************************************************************************************************
//
//		File:					Server.h
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
//		This header defines server struct
//
//		 Other files required:
//		1. none
//
//*****************************************************************************************************

#ifndef SERVER_H
#define SERVER_H

//*****************************************************************************************************

struct Server
{
	int custId;
	int endTime;
	bool busy;

	Server()
	{
		custId = 0;
		endTime = 0;
		busy = false;
	}

};

//*****************************************************************************************************

#endif