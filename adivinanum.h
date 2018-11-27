#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

 
using namespace std;
 
int adivinanum()
{
	int OP;
	int a, b, c, s;
	
	system("cls");
 
	cout<<"Ingrese limite inferior de un rango	:";
	cin>>a;
	cout<<"Ingrese limite superior de un rango	:";
	cin>>b;
	cout<< endl;
 
mateu:
srand(time(0));
	c=a+(rand()%(b-a+1));
 
 system("cls");
 
	cout<<"	Su numero es:	";
	cout<<c;
 
	cout<<endl;
	cout<<"Seleccione la opcion que corresponda"<<endl;
	cout<<"1. Menor"<<endl;
	cout<<"2. Mayor"<<endl;
	cout<<"3. Es ese"<<endl;
	cout<<endl<<"\n";
 
	cin>>OP;
 
	if (OP==1)
	{
	    b=c-1;
		goto mateu;
 
	}
 
	if(OP==2)
	{
	    a=c+1;
		goto mateu;
	}
	if(OP==3)
	{
		cout<<endl<<"\n";
		cout<<"Su numero es:	"<<c;
	}
}
