// To implement employee database using structures
#include <stdio.h>
#include <windows.h>
struct date
{
	int year;
	int month;
	int day;
};

struct employee
{
	int empid;
	struct date dob;
	struct date doj;
	struct date sysdate;
};

struct employee input(struct employee e)
{
	printf("Enter employee id: ");
	scanf("%d",&e.empid);
	printf("Enter DOB (DD MM YYYY): ");
	scanf("%d %d %d",&e.dob.day,&e.dob.month,&e.dob.year);
	printf("Enter Date of joining (DD MM YYYY): ");
	scanf("%d %d %d",&e.doj.day,&e.doj.month,&e.doj.year);
	return e;
}
struct employee joining(struct employee e)
{
	int x,day=0,month=0,year=0;
	if(e.doj.month==1||e.doj.month==3||e.doj.month==5||e.doj.month==7||e.doj.month==8||e.doj.month==10||e.doj.month==12)
		x=31;
	else if (e.doj.month==4||e.doj.month==6||e.doj.month==9||e.doj.month==11)
		x=30;
	else if(e.doj.month==2)
		{
			if(e.doj.year%4==0)
				x=29;
			else
				x=28;
		}
	
	year=e.sysdate.year-e.doj.year;	
	if(e.doj.day>e.sysdate.day)
	{
		day=x-e.doj.day+e.sysdate.day;
		month=e.sysdate.month-e.doj.month-1;
		if(month<0)
		{
			month=12+month;
			year=year-1;
		}
	}
	else if (e.sysdate.day>=e.doj.day)
	{
		day=e.sysdate.day-e.doj.day;
		if(e.doj.month>e.sysdate.month)
		{
			month=e.sysdate.month-e.doj.month;
			if(month<0)
			{
				month=12+month;
				year=year-1;
			}
		}
		else if(e.sysdate.month>=e.doj.month)
			month=e.sysdate.month-e.doj.month;
	}
	e.doj.day=day;
	e.doj.month=month;
	e.doj.year=year;
	return e;
}
struct employee age(struct employee e)
{
	int x,day=0,month=0,year=0;
	if(e.dob.month==1||e.dob.month==3||e.dob.month==5||e.dob.month==7||e.dob.month==8||e.dob.month==10||e.dob.month==12)
		x=31;
	else if (e.dob.month==4||e.dob.month==6||e.dob.month==9||e.dob.month==11)
		x=30;
	else if(e.dob.month==2)
		{
			if(e.dob.year%4==0)
				x=29;
			else
				x=28;
		}
	
	year=e.sysdate.year-e.dob.year;	
	if(e.dob.day>e.sysdate.day)
	{
		day=x-e.dob.day+e.sysdate.day;
		month=e.sysdate.month-e.dob.month-1;
		if(month<0)
		{
			month=12+month;
			year=year-1;
		}
	}
	else if (e.sysdate.day>=e.dob.day)
	{
		day=e.sysdate.day-e.dob.day;
		if(e.dob.month>e.sysdate.month)
		{
			month=e.sysdate.month-e.dob.month;
			if(month<0)
			{
				month=12+month;
				year=year-1;
			}
		}
		else if(e.sysdate.month>=e.dob.month)
			month=e.sysdate.month-e.dob.month;
	}
	e.dob.day=day;
	e.dob.month=month;
	e.dob.year=year;
	return e;
}
struct employee output(struct employee e)
{
	printf("\nEmployee Info:");
	printf("\nID:%d",e.empid);
	printf("\nAge:\n");
	printf("%d days, %d months, %d years",e.dob.day,e.dob.month,e.dob.year);
	printf("\nTotal time of working since joining:\n");
	printf("%d days, %d months, %d years",e.doj.day,e.doj.month,e.doj.year);
	return e;
}
int main()
{
	struct employee e;
	int x;
	SYSTEMTIME t;
	GetLocalTime(&t);
	e.sysdate.year=t.wYear;
	e.sysdate.month=t.wMonth;
	e.sysdate.day=t.wDay;
	e=input(e);
	e=joining(e);
	e=age(e);
	output(e);
}
