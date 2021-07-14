#pragma once
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_SECURE_NO_WARNINGS
#include "Contacts.h"
#include <iostream>
#include <fstream>
#include "Messages.h"
#include "File_Messages.cpp"
#include "File_contacts.cpp"
#include <string>
#include <vector>
#include <windows.h>
#include <direct.h>
#include "user.h"
using namespace std;
Contacts::Contacts()
{

}

Contacts::Contacts(user &usr)
{
	File_contacts::Read_contacts(usr.contact_list, usr.getName());
}


// bab3t el user instance by reference 3lshan mmkn hy7sl modification f el contacts file while searching by adding new contact

void Contacts::search_contacts(user &User, vector<user>usrs)
{
	string name;
	int choice = 0, flag = 0;
	do
	{
		cout << "Enter the name you are searching for: ";
		cin >> name;
		flag = 0;
		for (int i = 0; (size_t)i < (usrs.size()); i++)
		{
			if (name == usrs[i].getName())
			{
				cout << usrs[i].getName() << " " << "is found ;) ";
				flag = 1;
				cout << endl << "Do you want to add him/her to your contact list to send secret messages ;)" << endl;
				cout << "If yes, press 1" << endl;
				cout << "If no, press 2 " << endl;
				cin >> choice;
				if (choice == 1)
				{
					bool check = 0;
					for (int i = 0; i < (size_t)User.contact_list.size(); i++)

					{
						if (name == User.contact_list[i])
						{
							cout << "This name already exists in your Contact List!" << endl;
							check = 1;
							cout << "Do you want to search for someone else?";
							cout << endl << "If yes, press 1" << endl;
							cout << "If no, press 0" << endl;
							cin >> choice;
							break;
						}
					}
			
					 if (check==0) {
						User.contact_list.push_back(usrs[i].getName());
						File_contacts::Write_users(User.getName(), User.contact_list);
						cout << usrs[i].getName() << " " << "is added to your contact list successfully ;) " << endl;
						cout << "Do you want to search for someone else?";
						cout << endl << "If yes, press 1" << endl;
						cout << "If no, press 0" << endl;
						cin >> choice;
						break;
					}
				}
				else if (choice == 2)
				{
					cout << "Do you want to search again?";
					cout << endl << "If Yes, press 1" << endl;
					cout << "If No, press 0" << endl;
					cin >> choice;
					break;
				}
			}

		}
		if (flag == 0)
		{
			cout << "User is not found :(" << endl;
			cout << "Do you want to search again?";
			cout << endl << "If Yes, press 1" << endl;
			cout << "If No, press 0" << endl;
			cin >> choice;

		}

	} while (choice > 0);

}

// bb3t el user instance by value as no changes will occur in the contacts file
void Contacts::search_contactlist(user User, bool flag)
{

	string name;
	int choice = 0, bool1 = 0;
	do
	{
		cout << "Enter the name you are searching for: ";
		cin >> name;
		for (int i = 0; (size_t)i < (User.contact_list.size()); i++)
		{
			if (name == User.contact_list[i])
			{
				cout << User.contact_list[i] << " " << "is found :D ";
				bool1 = 1;
				if (flag == true)
				{
					cout << endl << "Do you want to send to him/her a secret message ;) " << endl;
					cout << "If Yes, press 1" << endl;
					cout << "If No, press 2 " << endl;
					cin >> choice;
					if (choice == 1)
					{
						Messages mesg;
						mesg.send_message(User, User.contact_list[i]);

						choice = 0;
						break;
					}
				}
				else
				{
					cout << "Do you want to search again?";
					cout << endl << "If Yes, press 1" << endl;
					cout << "If No, press 0" << endl;
					cin >> choice;
					break;
				}
			}

		}
		if (bool1 == 0)
		{
			cout << "User is not found :(" << endl;
			cout << "Do you want to search again?";
			cout << endl << "If Yes, press 1" << endl;
			cout << "If No, press 0" << endl;
			cin >> choice;

		}

	} while (choice > 0);

}
void Contacts::viewcontacts(user User, bool flag)
{



	for (int i = 0; i < User.contact_list.size(); i++)
	{
		cout << i + 1 << "." << User.contact_list[i] << endl;


	}
	if (flag == true)
	{
		cout << endl << "Do you want to send a message for any user in your contact list" << endl;
		int choice;

		cout << "For yes press 1 :)" << endl;
		cout << "For no press  0" << endl;
		cin >> choice;
		if (choice == 1)
		{
			do
			{
				cout << "Please enter the name of the user you want to send him a message: ";
				string Username;
				cin >> Username;
				bool b = false;
				for (int i = 0; (size_t)i < User.contact_list.size(); i++)
				{
					if (Username == User.contact_list[i])

					{
						Messages mesg;
						mesg.send_message(User, User.contact_list[i]);
						choice = 0;
						b = true;
						break;
					}

				}

				if (b == false)
				{
					cout << "We can't find "<< Username << " in your contact list :( " << endl;
					cout << "Do you want to try again?";
					cout << endl << "If Yes, press 1";
					cout << endl << "If No, press 0";
					cin >> choice;
				}
			} while (choice != 0);
		}
	}


}