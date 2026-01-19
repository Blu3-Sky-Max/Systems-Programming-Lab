using namespace std;
#include <iostream>
#include <array>
#include <vector>

/* Author: Usman O. Olanrewaju (Blu3 Sky) 
 * Title: Vector-Memory-Management  */
 
   
int main()
{  
  size_t size=6;
      vector<long>usman(size);
   long * const ptr=usman.data();
   
   for(auto &i:usman){
       cout<<"Enter the your number: ";
       cin>>i;
   }
   usman.push_back(*ptr=800);
   for(auto i:usman){
       cout<<i<<" ";
   }
   cout<<endl;
   usman.pop_back();
   cout<<" After pop back: \n";
    for(auto i:usman){
       cout<<i<<" ";
   }
   cout<<endl;
   usman.clear();
   cout<<" After you clear: \n";
    for(auto i:usman){
       cout<<i<<" ";
   }
   cout<<"\n";
   usman.resize(size);
   cout<<" resize: \n";
    for(auto& i:usman){
       cout<<i * size<<" ";
   }
}
