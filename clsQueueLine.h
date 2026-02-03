#pragma once
#include<iostream>
#include"clsDate.h"
#include"queue"
#include"stack"
using namespace std;


class clsQueueLine
{

	//  _

private:

	string _Prefix="";
	short _AverageServiceTime=0;
	short  _TotalTickets = 0;

	class clsTicket
	{
	private:

		string _Prefix;
		short  _Number = 0;
		short  _WaitingClients = 0;
		string _TicketTime;
		short _AverageServiceTime = 0;
		short _ExpectedServiceTime = 0;


	public:

		clsTicket(string Prefix, short Number, short WaitingClients, short AverageServiceTime)
		{
			_Number = Number;
			_Prefix = Prefix;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_WaitingClients = WaitingClients;
			_AverageServiceTime = AverageServiceTime;
		}


		string Prefix()
		{
			return _Prefix;

		}

		short Number()
		{
			return _Number;
		}

		string FullNumber()
		{
			return _Prefix + to_string(_Number);
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		short WaitingClients()
		{
			return _WaitingClients;
		}

		short ExpectedServeTime()
		{
			return _AverageServiceTime * _WaitingClients;

		}

		void Print()
		{

			cout << "\n\t\t\t--------------------\n";
			cout << "\n\t\t\t\t    " << FullNumber();
			cout << "\n\n\t\t\t    " << _TicketTime;
			cout << "\n\t\t\t      Waiting Clients = " << _WaitingClients;
			cout << "\n\t\t\t       Serve Time In";
			cout << "\n\t\t\t          ";
			cout << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t--------------------\n";
		}





	};


public:


	queue <clsTicket>QueueLine;



	clsQueueLine(string prefix, short averageservicetime)
	{
		_Prefix = prefix;
		_AverageServiceTime = averageservicetime;
		_TotalTickets = 0;


	}
	
	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServiceTime);


		QueueLine.push(Ticket);
		
	}

	int WaitingClients()
	{
		return QueueLine.size();
	}

	string WhoIsNext()
	{

		if (QueueLine.empty())
		{
			return "No Clients Left. ";
		}

		else
			return QueueLine.front().FullNumber();

	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;

	  

			QueueLine.pop();
		return true;

	}


	short ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}




	void PrintInfo()
	{

		cout << "\n\t\t\t-------------------\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t-------------------\n";
		cout << "\n\t\t\t    Prefix           =" << _Prefix;
		cout << "\n\t\t\t    Total Tickets    =" << _TotalTickets;
		cout << "\n\t\t\t    Served Clients   =" << ServedClients();
		cout << "\n\t\t\t    Waiting Clients  =" << WaitingClients();
		cout << "\n\t\t\t-------------------\n";
		cout << "\n"; 

	}


	

	void PrintTicketsLineRTL()
	{

	
		if (QueueLine.empty())
			cout << "\n\t\tTicket: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		queue<clsTicket>TempQueueLine = QueueLine;


		while (!TempQueueLine.empty())
		{
			clsTicket Ticket = TempQueueLine.front();

			cout << " " << Ticket.FullNumber() << "<--";
			TempQueueLine.pop();

		}
		cout << "\n";

	}

	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty())
			cout << "\n\t\tTicket: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

			queue<clsTicket>TempQueueLine = QueueLine;
			stack<clsTicket>TempStackLine;

			while (!TempQueueLine.empty())
			{
				TempStackLine.push(TempQueueLine.front());
				TempQueueLine.pop();

			}

			while (!TempStackLine.empty())
			{
				clsTicket Ticket = TempStackLine.top();

				cout << " " << Ticket.FullNumber() << "-->";
				TempStackLine.pop();
			}
			cout << "\n";
	}

	void PrintAllTickets()
	{
		cout << "\n\n\t\t\t   ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t    ---No Tickets---";

		queue <clsTicket> TempQueueLine = QueueLine;


		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();

				TempQueueLine.pop();

		}
	}


};