#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	/* integer or any integer like */
	int integer;
		cin>>integer;
		cout<<integer<<endl;

	/* character string */
	char charstring[100];
		cin>>charstring;	// stops input after a "space"
		cout<<charstring<<endl;

		cin.getline(charstring, 100);	// stops after 100 character or eof whichever comes first
		cout<<charstring<<endl;

	string strstring;
		cin>>strstring;		// stops input after a "space"
		cout<<strstring<<endl;

		getline(cin, strstring);	// stops after eof or '\n', whichever comes first
		cout<<strstring<<endl;

	/* safest way to get an integer (but very slow) - taken from cpluspls.com */
	int number = 0;
	string input;
	while(true) {
		getline(cin, input);

		stringstream myStream(input);
		if(myStream>>number)
			break;
	}

	/* Safest way to get a single character */
	char singlechar = {0};
	while(true) {
		getline(cin, input);

		if(input.length() == 1){
			singlechar = input[0];
			break;
		}
	}
}
