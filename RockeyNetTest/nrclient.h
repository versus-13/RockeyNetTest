/**************************************************************************************************
	created:	2002/04/04
	created:	4:4:2002   16:44
	filename: 	NrClient.h
	file base:	NrClient
	file ext:	h
	
	purpose:	Header file for Nrclient.dll or NrClient.lib.

	Tip:		You can access NetROCKEY in two ways: Using Static Library or using dynamic library. 
				NrClient.lib is a static library, you can run your program without NrClient.dll when using it.

				NrClient.lib is a static library for VC6.0, you can use it through steps below:
				(1) 	Insert Nrclient.lib and Nrclient.h to your project. (via "Add files to project...")
				(2)		include "NrClient.h", then you can use functions directly.
				(3) 	Go to "Project" Menu, Select "Setting"£¬then "link", Insert "wsock32.lib netapi32.lib" to "Object\Library Modules".
				(4)		Compile and enjoy :)
******************************************************************************************************/

#pragma once

#include "windows.h"


//Functions used by static library.

extern "C" 
{
	DWORD WINAPI	NetRockey(WORD function, WORD *handle, DWORD *lp1, 
						DWORD *lp2, WORD *p1, WORD *p2, WORD *p3, 
						WORD *p4, BYTE *buffer);

	DWORD WINAPI	SetIniPathName(LPCTSTR iniName);

	DWORD WINAPI	NrGetLastError();
	DWORD WINAPI	NrGetVersion();
}




//Functions used by dynamic library.

typedef DWORD (WINAPI *NETROCKEY)(WORD function, WORD *handle, DWORD *lp1, 
									 DWORD *lp2, WORD *p1, WORD *p2, WORD *p3, 
									 WORD *p4, BYTE *buffer);

typedef DWORD (WINAPI *NRSETINIPNAME)(LPCTSTR iniName);

typedef DWORD (WINAPI *NRGETLASTERROR)();
typedef DWORD (WINAPI *NRGETVERSION)();



//NetROCKEY functions
#define  RY_FIND                        1		// Find
#define  RY_FIND_NEXT					2		// Find Next
#define  RY_OPEN                        3		// Open
#define  RY_CLOSE                       4		// Close
#define  RY_READ                        5		// Read
#define  RY_WRITE                       6		// Write
#define  RY_RANDOM                      7		// Generate Random
#define  RY_SEED                        8		// Seed
#define  RY_READ_USERID					10		// Read USER ID ZONE
#define  RY_CHECK_MOUDLE		        12		// Chcek Module Attribute
#define  RY_CALCULATE1			        14		// Calculate 1
#define  RY_CALCULATE2			        15		// Calculate 2
#define  RY_CALCULATE3			        16		// Calculate 3
#define  RY_DECREASE			        17		// Decrease 




//Rockey Error Code
#define  ERR_SUCCESS					0		//Success 
#define  ERR_NO_PARALLEL_PORT			1		//No parallel port on the computer 
#define  ERR_NO_DRIVER					2		//No driver installed 
#define  ERR_NO_ROCKEY					3		//No ROCKEY4 dongle 
#define  ERR_INVALID_PASSWORD			4		//ROCKEY4 dongle found, but base password is incorrect
#define  ERR_INVALID_PASSWORD_OR_ID		5		//Wrong password or ROCKEY4 HID
#define  ERR_SETID						6		//Set ROCKEY4 HID wrong
#define  ERR_INVALID_ADDR_OR_SIZE		7		//Read/Write address is wrong
#define  ERR_UNKNOWN_COMMAND			8		//No such command
#define  ERR_NOTBELEVEL3				9		//Inside error
#define  ERR_READ						10		//Read error
#define  ERR_WRITE						11		//Write error
#define  ERR_RANDOM						12		//Random error
#define  ERR_SEED						13		//Seed Code error
#define  ERR_CALCULATE					14		//Calculate error
#define  ERR_NO_OPEN					15		//Ry_Open must precede this operation
#define  ERR_OPEN_OVERFLOW				16		//Too many open dongles (>16)
#define  ERR_NOMORE						17		//No more dongle
#define  ERR_NEED_FIND					18		//No Find before FindNext
#define  ERR_DECREASE					19		//Decrease error
#define  ERR_AR_BADCOMMAND				20		//Arithmetic instruction error
#define  ERR_AR_UNKNOWN_OPCODE			21		//Arithmetic operator error
#define  ERR_AR_WRONGBEGIN				22		//A constant. cannot be in the first instruction
#define  ERR_AR_WRONG_END				23		//A constant. cannot be in the last instruction 
#define  ERR_AR_VALUEOVERFLOW			24		//Const number > 63


#define  ERR_NET_LOGINAGAIN				1001	//A module can only be opened once by the same process.  
#define  ERR_NET_NETERROR				1002	//Network error.
#define	 ERR_NET_LOGIN					1003	//Too many users are logged on.
#define	 ERR_NET_INVALIDHANDLE			1004	//Invalid handle, this handle might have been closed.
#define	 ERR_NET_BADHARDWARE			1005	//Defective hardware 
#define	 ERR_NET_REFUSE					1006	//Client dll modified, service refused request.
#define	 ERR_NET_BADSERVER				1007	//Nrsvr.exe modified, service is invalid.





//Error code for network

#define ERR_INIT_SOCK					2001	//Error when initializing.
#define ERR_NOSUCHPROTO					2002	//No such protocol.
#define ERR_UDPSOCKCREATE				2003	//UDP error when creating socket.
#define ERR_UDPSETBROADCAST				2004	//UDP error when setting broadcast.
#define ERR_UDPBINDFAILED				2005	//UDP error when binding.
#define ERR_SVRCALLBACKNULL				2006	//Server call back null.
#define ERR_TCPSOCKCREATE				2007	//TCP error when creating socket.
#define ERR_TCPBINDFAILED				2008	//TCP error when binding.
#define ERR_TCPLISTENFAILED				2009	//TCP error when listening.
#define ERR_NOSUCHSEARCH				2010	//No such search mode.
#define ERR_UDPSEND						2012	//UDP error when sending.
#define ERR_UDPTIMEOUT					2013	//UDP timeout error when waiting.
#define ERR_UDPRECV						2014	//UDP error when receiving.
#define	ERR_TCPCONNECT					2015	//TCP error when connecting to server.
#define ERR_TCPSENDTIMEOUT				2016	//TCP time out error when sending.
#define	ERR_TCPSEND						2017	//TCP error when sending.
#define ERR_TCPRECVTIMEOUT				2018	//TCP time out error when receiving.
#define	ERR_TCPRECV						2019	//TCP error when receiving.
#define ERR_IPXSOCKCREATE				2020	//IPX error when creating socket.
#define ERR_IPXSETBROADCAST				2021	//IPX error when setting broadcast.
#define	ERR_IPXSEND						2022	//IPX error when sending data. 
#define	ERR_IPXRECV						2023	//IPX error when receiving data.
#define ERR_IPXBIND						2024	//IPX error when binding.
#define ERR_NBSRESET					2025	//NetBIOS error when initializing.
#define ERR_NBSADDNAME					2026	//NetBIOS error when adding name.
#define ERR_NBSSEND						2027	//NetBIOS error when sending data.
#define ERR_NBSRECV						2028	//NetBIOS error when receiving data.



	
#define  ERR_UNKNOWN					0xffff	// Unknown error 





















