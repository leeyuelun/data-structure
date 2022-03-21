# data-structure
# WARMUP2
```C++=
#include <iostream>
#include <ostream>
#include <cassert>
#include <string>
#include <math.h>

using namespace std;

class Binary_Number { 
    private :
        unsigned int no ; // 儲存數字於無號整數
    public :
        // 建構函式：
        Binary_Number( const string& num ) ;

        Binary_Number( int sum) {no = sum;}

        int get_no() const{return no;}
        
        friend ostream& operator<< ( ostream& out ,const Binary_Number& foo ) ;
};

Binary_Number::Binary_Number(const string& num){
    no = stoi(num);
} 




ostream& operator<< (ostream& out ,const Binary_Number& foo) {
    int decimal = 0, i = 0, remainder, n;
    n = foo.no;
    out << foo.no;
    while (n != 0)
    {
        remainder = n % 10;
        n /= 10;
        decimal += remainder*pow(2,i);
        ++i;
    }
    return out <<"("<< decimal <<")";
}

Binary_Number operator+(const Binary_Number& a, const Binary_Number& b){
    int sum;
    sum = a.get_no()*b.get_no();
    int check=0;
    for(int i=0;sum>0;i++){
        if(sum%10==2){
            sum=sum-2+10;
        }
        check=check+sum%10*pow(10,i);
        sum=sum/10;
    }
    return
        Binary_Number(check);
    
}

Binary_Number operator*(const Binary_Number& a, const Binary_Number& b){
    int sum;
    sum = a.get_no()*b.get_no();
    int check=0;
    for(int i=0;sum>0;i++){
        if(sum%10==2){
            sum=sum-2+10;
        }
        check=check+sum%10*pow(10,i);
        sum=sum/10;
    }
    return
        Binary_Number(check);
}    



int main(){
    Binary_Number a("10010"),b("110");
    cout<< a << endl;
    cout<< a+b << endl;
    cout<< a*b << endl;
}
```
# WARMUP3
```C++=

#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

const int R = 5;
const int C = 4;

class Bitmap {
private:
    static const int bmap[10][R];       //數字0~9的點陣圖儲存方式
    string snum;                        //cin的字串
    int scale;                          //放大倍率
    
public:
    Bitmap(string sno = "", int s = 1) : snum(sno), scale(s) {}

    void setsnum(string sno) {
        snum = sno;
    }

    void setscale(int s) {
        scale = s;
    }
    string output;


    friend Bitmap operator* (const Bitmap& foo, int n) {
      int i , j , k , a ;
      char w;
     for( i = 0 ; i < R ; i++ ){
       for(a = 0 ; a < n ; ++a){
	 for( k = 0 ; k < foo.snum.size() ; k++){
	      for( j = C-1 ; j >= 0 ; --j ){
		w = foo.snum[k] -'0';
		if( (foo.bmap[w][i] >>j )%2 ) {
		  cout <<string(n, static_cast <char>('0'+w)) ;
		}else{
		  cout <<string(n,' ') ;
		}
	   }
	   cout <<" " ;
	 }
	 cout << endl ;
       }
     }
     return foo.output;
    }
    friend ostream& operator<< ( ostream& out, const Bitmap& foo) {
        out << foo.output;
        
        
        return out;
    }
};

int main()
{
    int s;
    string sno;
    Bitmap foo;

    while (1) {
        cout << "> ";
        cin >> sno;
        foo.setsnum(sno);

        for (s = 1; s < 4 ; ++s)
        {
            cout << foo * s << endl;
        }
        cout << endl;
    }
    return 0;
}


const int Bitmap::bmap[10][R] = {
    {15,9,9,9,15}   ,   {2,6,2,2,7}     ,   {15,1,15,8,15} ,
    {15,1,7,1,15}   ,   {9,9,15,1,1}    ,   {15,8,15,1,15} ,
    {15,8,15,9,15}  ,   {15,1,2,4,8}    ,   {15,9,15,9,15} ,
    {15,9,15,1,15}
};
