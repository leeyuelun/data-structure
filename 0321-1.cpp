#include <iostream>
#include <sstream>

using namespace std;
int main(){
  string line , foo ;
  int n ,sum;
  istringstream istr, istr2;
  
  cout << ">" ;
  while( getline(cin,line)){
    istr.str(line);
    sum = 0;
    while (1) {

      if ( istr >> n ){
	sum += n ;
      }else {
	if( istr.eof() ) break;
	istr.clear();
	istr.ignore();
      }
    }
    istr.clear();
    cout << sum << endl;
    cout <<"> ";
  }
  return 0 ;
}
