#include <iostream>
#include <string>
using namespace std;
/* Author: usman O. Olanrewaju (Blu3 Sky) 
 * Title: House-Renovation-System
 */ 
class  usmanRenovation {

public:
	usmanRenovation() {
		string l, w, h;

		cout<<"what is the dimension of this rooms: \n";

		cout<<"The length is:";
		getline (cin,l);
		cout<<"The width is:";
		getline (cin, w);
		cout<<"The height is:";
		getline (cin,h);
	    
	}
	usmanRenovation(int l, int w,int h){
	    cout<<l<<w<<h;
	}
};

int main()
{
	int num;
	int total=0;


	cout<<"(A) painting=$20 per square meter\n(B) Flooring=$30 per square meter \n(C) Full renovation=$50 per square meter "<<endl;
	cout << "How many rooms do you want to renovate: ";
	cin >> num;


	for(int i=1; i<=num; i++) {
		int sum=0;
		cin.ignore ();
		usmanRenovation obj;
		int f=0,f1;
		int p=0, p1;
		int full=0,full1;
		cout<<"for the  "<<i<<"st room what did you want: "<<endl;
		cout << "How many floors: ";
		cin >> f1;
		cout << "How many painting: ";
		cin >> p1;

		cout << "Do you need full renovation for this room and how many: ";
		cin >> full1;

		for (int i=0; i<f1 ; i++) {
			f=f+30;

		}
		for (int i=0 ; i<p1 ; i++) {
			p=p+20;
		}
		for (int i =0 ; i<full1; i++) {
			full=full+50;
		}

		sum= f+p+full;
		cout << "Total cost of renovation for the "<<i<<"st room is:"<<sum<<endl;
		cout<<"\n";
		total=total +sum;
	}

	cout<<"The total sum of the house renovation is: "<<total;

};
