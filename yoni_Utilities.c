#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable : 4996)

#include "Utilities.h";


char FILE_NAME[1000];

void InitLog(char filename[1000])
{
	
	strcpy(FILE_NAME, filename);

}

void Log(char massage[100])
{
	time_t t;
	time(&t);
	struct tm* timeinfo;

	timeinfo = localtime(&t);
	char str[1000];
	sprintf(str, "%d.%d.%d-%d:%d:%d -- %s", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, massage);

	FILE* f = fopen(FILE_NAME, "a");
	fputs("\n\n", f);
	fputs(str, f);
	fputs("\n\n", f);


	fclose(f);
}

void ErrorLog(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Error - %s", message);
	Log(newMessage);
}

void EventLog(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Event - %s", message);
	Log(newMessage);
}

void WarningLog(char message[100])
{
	char newMessage[100];
	sprintf(newMessage, "Warning - %s", message);
	Log(newMessage);
}

