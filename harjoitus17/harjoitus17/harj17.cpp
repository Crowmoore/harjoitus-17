/*
Ryhm‰: IIO14S2
Kuvaus: Harjoitus 17 (Palautus vko 46)
Muokkaa edellist‰ ohjelmaa siten, ett‰ edell‰ m‰‰ritelty‰ tietuetyyppi‰
k‰ytet‰‰n my‰s kahden muun "koululaisen" tietojen tallentamiseen.
N‰iden kahden muun koululaisen tiedot alustetaan ao. muuttujien
m‰‰rittelyn yhteydess‰. Ainoastaan yhden koululaisen tiedot kysyt‰‰n
k‰ytt‰j‰lt‰ edellisen teht‰v‰n tapaan.

Tulosta kolmen koululaisen tiedot koulumatkan mukaisessa
suuruusj‰rjestyksess‰ (pienimm‰st‰ suurimpaan) n‰yt‰lle
Tekij‰: Joel Kortelainen
P‰iv‰ys: 5.11.2014
Versio 1.0
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct userInfo
{
	string firstnames;
	string lastname;
	float distance;
	string address;
	int shoesize;
	string zipcode;
};

void clearConsole();
string getUserInputString();
int getUserInputInteger();
float getUserInputFloat();
void printUser(userInfo);
userInfo getUser();
userInfo student1Info();
userInfo student2Info();
int compareUserDistance(const void*, const void*);


int main()
{
	userInfo user;
	userInfo student1;
	userInfo student2;
	user = getUser();
	student1 = student1Info();
	student2 = student2Info();
	userInfo users[] = { user, student1, student2 };
	qsort(users, 3, sizeof(userInfo), compareUserDistance);
	printUser(users[0]);
	printUser(users[1]);
	printUser(users[2]);
	return(0);
}
userInfo getUser()
{
	struct userInfo user;
	cout << "First name(s): ";
	user.firstnames = getUserInputString();
	clearConsole();
	cout << "Last name: ";
	user.lastname = getUserInputString();
	clearConsole();
	cout << "Address: ";
	user.address = getUserInputString();
	clearConsole();
	cout << "Zipcode: ";
	user.zipcode = getUserInputString();
	clearConsole();
	cout << "Distance from home to school: ";
	user.distance = getUserInputFloat();
	clearConsole();
	cout << "Shoesize: ";
	user.shoesize = getUserInputInteger();
	clearConsole();
	return user;
}

userInfo student1Info()
{
	struct userInfo student1;
	student1.firstnames = "Pablo";
	student1.lastname = "el Diablo";
	student1.address = "Penance Street";
	student1.zipcode = "38915";
	student1.distance = 5.8;
	student1.shoesize = 45;
	return student1;
}

userInfo student2Info()
{
	struct userInfo student2;
	student2.firstnames = "Alexander";
	student2.lastname = "Stubb";
	student2.address = "Parliament Street";
	student2.zipcode = "00090";
	student2.distance = 145.4;
	student2.shoesize = 43;
	return student2;
}

void printUser(userInfo user)
{
	cout << "Name: " << user.firstnames << " " << user.lastname << endl;
	cout << "Address: " << user.address << endl;
	cout << "Zipcode: " << user.zipcode << endl;
	cout << "Distance to school: " << user.distance << endl;
	cout << "Shoesize: " << user.shoesize << endl << endl;
}


void clearConsole()
{
	system("cls");
}
string getUserInputString()
{
	string userString;
	getline(cin, userString);
	return userString;
}
int getUserInputInteger()
{
	int userInt;
	cin >> userInt;
	return userInt;
}
float getUserInputFloat()
{
	float userFloat;
	cin >> userFloat;
	return userFloat;
}

int compareUserDistance(const void * a, const void * b)
{
	if (((const userInfo*)a)->distance <  ((const userInfo*)b)->distance) return -1;
	if (((const userInfo*)a)->distance ==  ((const userInfo*)b)->distance) return 0;
	if (((const userInfo*)a)->distance >  ((const userInfo*)b)->distance) return 1;
}