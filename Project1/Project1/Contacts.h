#pragma once
#define CONTACTS_H
#include <vector>
#include <string>
#include "user.h"
using namespace std;
class Contacts
{

public:
	Contacts();
	Contacts(user &usr);
	void search_contacts(user &User, vector<user>usrs);
	void search_contactlist(user User, bool flag);
	void viewcontacts(user User, bool flag);

};
