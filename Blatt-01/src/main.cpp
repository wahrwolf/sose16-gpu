#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void wait();
void showMenu();
string getPathFromUser(string);
void vignereStream(string, string, string, bool);
char normalize(char);

int main()
{
	bool leaveLoop = false;

	while(!leaveLoop)
	{	
		showMenu();

		char input = 'B';
		bool decrypt = true;

		string in, out;
		cin >> input;

		if(input == 'q')
		{
			leaveLoop=true;
		}else{
			//Quelldatei einlesen
	
			switch(input)
			{
				case 'v':
					// Zieldatei wählen
					 out = getPathFromUser("Pfad zur Zieldatei eingeben...");
					decrypt = false;

				case 'e':
					// Quelldatei wählen
					in = getPathFromUser("Pfad zur Quelldatei eingeben...");
					
					// Lese Key ein
					string key = getPathFromUser("Geheimschlüssel eingeben...");

					vignereStream(in, out, key, decrypt);
			}

		}
	}	

	wait();

	return 0;
}


// Menüs und Info Funktionen
void wait()
{
	cout << endl<< "--> Press Enter to Continue <--" << endl <<endl;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();;
}

void showMenu()
{
	cout << "Willkommen zu einem wirklich sicheren Crypto-Service" <<endl <<endl;
	cout << endl;
	cout << "der einzige deutsche Service mit dem NSA Siegel" <<endl << endl;
	cout << "Geben Sie Ihre Auswahl an:!" << endl ;
	cout << "(v)erschlüsselung starten" << endl ;
	cout << "(e)ntschlüsselung starten" << endl;
	cout << "(q)uerschiessen und was anderes tun" << endl;
	cout << "#";
}

string getPathFromUser(string message) 
{
	string pfad = "default.txt";

	cout << "Eingabe: "<< endl;
	cout << message << endl;
	cout << "-> ";

	cin >> pfad;

	return pfad;
}

//Crypto Funktionen
char vignere(char in, char key, bool decrypt)
{
	in = normalize(in);
	key = normalize(key);

	if(in >=0)
	{
		return (char) 'A' +(in + (!decrypt  ? 1 : (-1)) * key + 26) % 26; 
	}else{
		return in;
	}
	
}

void vignereStream(string in, string out, string key, bool decrypt)
{
	char cBuf;
	int count = 0;
	
	
	ifstream fin;
	ofstream fout;

	if(!decrypt)
	{
		fout.open(out.c_str());
	}

	cout << endl;	

	for(fin.open(in.c_str()); !fin.eof(); cBuf = fin.get())
	{ 

		if(normalize(cBuf)>=0)
		{
			cBuf = vignere(cBuf, key.at(count % key.length()), decrypt);
			count ++;
			if(decrypt)
			{
				cout << cBuf;
			} else {
				fout << cBuf;
			}
		}
	}
	
	cout << endl;

	if(!decrypt)
	{
		fout.close();
	}
	fin.close();
}

// Utils
char normalize(char c)
{
	if( 'A' <= c && c <= 'Z' )
	{
		return c - 'A';

	}else if ('a' <= c && c <= 'z'){
		return c - 'a';
	}

	return (char) -1;
}


