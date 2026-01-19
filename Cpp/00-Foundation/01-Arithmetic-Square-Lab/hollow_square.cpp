#include <iostream>

using namespace std;


int main(){
    const int h=7; const int p=12;
    
    for(int i=0; i<h;++i){
        for(int j=0; j<p; ++j){
            if(i == 0|| i==h-1||  j==0 || j==p-1
            ){
            cout<<"*";}
            else{ 
            cout<<" ";}
        }
        cout<<" \n";
    }
    
}
