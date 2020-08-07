
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

int increment(int k) { return ++k; }
int sum(int a)
{
    int f;
    int b[]={2, 4, 6, 8, 10};
    for(int c=0;c<5;c++)
    {
        f=a*b[c];
    }
    return f;
    }

int main() {
  vector<int> v1;
  for(int i=1; i<=5; i++)
    { v1.push_back (i);  }
    cout<< "V1 : ";
    for (int i=0; i<v1.size(); ++i)
    {cout << v1[i] << ' ';}
    cout<<"initial state"<<endl;
    cout<<endl;
    vector<int> v2(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), sum);
    transform(v2.begin(), v2.end(), v1.begin(), increment);
    cout<<"V1 : ";
    for (int h=0; h<v1.size(); ++h)
    {cout << v1[h] << ' ';}
    cout<<"final state"<<endl;
    system("PAUSE");
    return 0;

}

