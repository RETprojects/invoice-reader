// This program reads invoices from a file and outputs new information (such as total costs) to a new file.
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
// These are the function prototypes for the functions needed to write the information to the file.
double calccost(int quantity, double unitCost);
double accTotal(double itemCost, double totalCost);
void printLine(string itemno, string name, int quantity, double unitCost, double totalCost);
void printInvoiceHeader(string date);
void printReportHeader();
void printTotal(double invoiceTotal);
// The output file:
ofstream fout;

int main()
{
	// The file objects have been created and opened.
	ifstream fin("C:\\Users\\galah\\Desktop\\C++\\input\\input.txt");
	fout.open("report.txt");

	int items, quantity, i;
	string date, name, itemno;
	double totalCost, unitCost;
	double invoiceCost = 0.0;

	cout << setprecision(2) << fixed;

	printReportHeader();

	// This while loop does most of the work of printing the contents of the input file to the output file.
	while (fin >> items >> date)
	{
		totalCost = 0;
		printInvoiceHeader(date);

		// This for loop prints the contents of each invoice.
		for (i = 0; i < items; i++)
		{
			fin >> itemno >> name >> quantity >> unitCost;
			totalCost = calccost(quantity, unitCost);
			invoiceCost = accTotal(invoiceCost, totalCost);
			printLine(itemno, name, quantity, unitCost, totalCost);
		}

		// The total cost of the items from the invoices is printed.
		printTotal(invoiceCost);
	}
	// Finally, the files are closed.
	fin.close();
	fout.close();
}

// This function calculates the total cost of a group of items by multiplying the quantity by the cost per item.
double calccost(int quantity, double unitCost)
{
	return quantity * unitCost;
}

// This function adds the cost of one group of items to the total cost.
double accTotal(double itemCost, double totalCost)
{
	return itemCost + totalCost;
}

// This function prints a line from an invoice.
void printLine(string itemno, string name, int quantity, double unitCost, double totalCost)
{
	fout << "\t" << itemno << "\t" << name << "\t" << setw(5) << quantity << "\t" << setw(5) << unitCost << "\t" << setw(5) << totalCost << endl;
}

// This function prints the invoice date.
void printInvoiceHeader(string date)
{
	fout << "Invoice date: " << date << endl;
}

// This function prints the report header.
void printReportHeader()
{
	fout << "Erie Industrial Supply Corporation" << endl;
}

// This function prints the toal cost.
void printTotal(double invoiceTotal)
{
	fout << "Total   ................" << invoiceTotal << endl;
}