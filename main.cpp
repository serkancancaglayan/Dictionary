/*
 *Serkan Can Caglayan
 * 7.04.2019
 */
#include "sozluk.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	
	Kayit A("ege","men");
	Kayit C("serkan","can");
	
	vector<string> v;
	v.push_back("selam1");
	v.push_back("selam2");
	Kayit E("selam",v);
	
	
	Sozluk R(E);
	Sozluk B(A);
	Sozluk D(C);
	
	//+ ve = operatoru testi
	Sozluk X=B+D;
	
	cout<<"##################"<<endl;
	Sozluk P(X);
	cout << P;
	cout<<"##################"<<endl<<endl;
	
	cout<<"##################"<<endl;
	X-="ege";
	cout<<X;
	cout<<"##################"<<endl<<endl;
	
	cout<<"##################"<<endl;
	cout<<R;
	cout<<"##################"<<endl<<endl;
	
	cout<<"##################"<<endl;
	R+=B;
	cout<<R;
	cout<<"##################"<<endl<<endl;
	
	cout<<"##################"<<endl;
	R-=A;
	cout<<R;
	cout<<"##################"<<endl<<endl;
	
	cout<<"##################"<<endl;
	cout<<R["ege"];
	cout<<"##################"<<endl<<endl;
	
	cout<<"##################"<<endl;
	if(R>B) cout<<"> operatoru calisiyor"<<endl;
	if(!(R<B)) cout<<"< operatoru calisiyor"<<endl;
	if(!(R==B)) cout<<"== operatoru calisiyor"<<endl;
	if(R!=B) cout<<"!= operatoru calisiyor"<<endl;
	if(R>=B) cout<<">= operatoru calisiyor"<<endl;
	if(!(R<=B)) cout<<"<= operatoru calisiyor"<<endl;
	cout<<"##################"<<endl<<endl;
	
	
	return 0;
}
