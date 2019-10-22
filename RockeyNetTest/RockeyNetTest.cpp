// RockeyNetTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "nrclient.h"

#include <iostream>

// TODO fill constants (passwords and feature to login)
const int PASS1 = 0x0;
const int PASS2 = 0x0;
const int FEATURE_ID = 0xB;


int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "start..." << std::endl;

	for (int i = 0; i < 2; i++) {
		WORD handle = 0;
		DWORD lp1 = 0;
		DWORD lp2 = 0;
		WORD p1 = PASS1;
		WORD p2 = PASS2;
		WORD p3 = 0;
		WORD p4 = 0;
		BYTE buffer[1024];

		std::cout << "find rockey..." << std::endl;
		DWORD status = ERR_NO_ROCKEY;
		while (status == ERR_NO_ROCKEY) {
			status = NetRockey(RY_FIND, &handle, &lp1, &lp2, &p1, &p2, &p3, &p4, buffer);
		}

		if (status != ERR_SUCCESS) {
			std::cout << "rockey not found" << std::endl;
			return 1;
		}

		std::cout << "rockey found: " << lp1 << std::endl;

		lp2 = FEATURE_ID + 0x10000;

		status = NetRockey(RY_OPEN, &handle, &lp1, &lp2, &p1, &p2, &p3, &p4, buffer);
		if (status != ERR_SUCCESS) {
			std::cout << "can't login" << std::endl;
			return 1;
		}
		std::cout << "login success" << std::endl;
		status = NetRockey(RY_CLOSE, &handle, &lp1, &lp2, &p1, &p2, &p3, &p4, buffer); // here throws exeption, then i == 1
		if (status != ERR_SUCCESS) {
			std::cout << "can't logut" << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "finished" << std::endl;
	return 0;
}

