#include<iostream>
#include<list>
#include<stdlib.h>

using namespace std;
int main()
{
	list<int>coll;
	for(int c=1; c<=20; c++)
	{
		coll.push_back(c);
	}
	while(!coll.empty())
	{
		cout<<coll.back()<<endl;
		coll.pop_back();
	}
	cout<<endl;
	system("PAUSE");
	return 0;
	}
