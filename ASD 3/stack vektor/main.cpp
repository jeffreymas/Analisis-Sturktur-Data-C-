#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stack>
using namespace std;

int KaliSebelas(int e){return e*11;}
int Kali(int b){return b*b;}

int main()
{
	stack<int> StackVector1;
	stack<int> StackVector2;
    vector<int> A1;
    vector<int>::iterator pos1;
    for(int a=0;a<5;a++)
    {
        A1.push_back(a+1);
    }
    cout<<"initial state"<<endl<<"A1 : ";
    for (int i=0; i<A1.size(); ++i)
    {cout << A1[i] << ' ';}
    cout<<endl<<endl;
    vector<int>A2(A1.size());
    vector<int>::iterator pos2;
    transform (A1.begin(), A1.end(), A2.begin(), Kali);
    cout<<"final state"<<endl<<"A2 : ";
    for (int h=0; h<A1.size(); ++h)
    {
        cout << A2[h] << ' ';
    }
    cout<<endl<<"A1 : ";
    transform (A2.begin(), A2.end(), A1.begin(), KaliSebelas);
    for (int i=0; i<A1.size(); ++i)
    {
        cout << A1[i] << ' ';
    }
    cout<<endl;
    sort(A1.begin(), A1.end());
    sort(A2.begin(), A2.end());
    pos1=max_element(A1.begin(), A1.end());
    pos2=max_element(A2.begin(), A2.end());
    cout<< "nilai maksimum A1 : " << *pos1 <<endl;
    cout<< "nilai maksimum A2 : " << *pos2 <<endl;
    reverse(A1.begin(), A1.end());
    reverse (A2.begin(), A2.end());
    cout<<"Hasil Terbalik A1 : ";
    for (pos1=A1.begin(); pos1!=A1.end(); ++pos1) {
        cout << *pos1 << ' ';
    }
    cout<<endl<<"Hasil Terbalik A2 : ";
    for (pos2=A2.begin(); pos2!=A2.end(); ++pos2) {
        cout << *pos2 << ' ';
    }
    for (int p=0;p<A1.size();p++)
    {
    	StackVector1.push(A1[p]);
    }
    for (int q=0;q<A1.size();q++)
    {
    	StackVector2.push(A2[q]);
    }
    
    system("pause");
    return 0;
}
