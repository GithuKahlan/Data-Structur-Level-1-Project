#include <iostream>
#include"clsDblLinkedList.h"
#include"clsMyQueue.h"
#include"clsMyStack.h"
#include"clsDynamicArray.h"
#include"clsMyQueueArr.h"
#include"clsMyStackArr.h"
#include"clsMyString.h"
#include"clsMyString.h"
#include"clsQueueLine.h"
using namespace std;

int main()
{

	clsQueueLine PayBillsQueue("A0", 10);
	clsQueueLine SubscriptionQueue("B0", 5);


	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();

	cout << "\nPay Bills Queue Info:\n";
	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintTicketsLineRTL();
	PayBillsQueue.PrintTicketsLineLTR();


	PayBillsQueue.PrintAllTickets();



	PayBillsQueue.ServeNextClient();
	PayBillsQueue.ServeNextClient();
	cout << "\nPays Bills Queue After Serving two Client\n";
	PayBillsQueue.PrintInfo();




	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();


	cout << "\nSubscription Queue Info:\n";
	SubscriptionQueue.PrintInfo();



	SubscriptionQueue.PrintTicketsLineRTL();
	SubscriptionQueue.PrintTicketsLineLTR();


	SubscriptionQueue.PrintAllTickets();



	SubscriptionQueue.ServeNextClient();
	SubscriptionQueue.ServeNextClient();
	cout << "\nSubscription After Serving two Client\n";
	SubscriptionQueue.PrintInfo();




	system("pause>0");

}
