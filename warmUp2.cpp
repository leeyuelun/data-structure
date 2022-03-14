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