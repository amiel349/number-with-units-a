#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
//#include "NumberWithUnits.cpp"
using namespace std;
//using namespace ariel;
namespace ariel{
    class NumberWithUnits{

       
        private:
        string type ;
        double number ;

        public:
       
         //constructor and distuctor
        NumberWithUnits(double number , string type) ;
        ~NumberWithUnits(){};
        
        /* 6 arithmetic operations */

        // unary and binary addition 
        const NumberWithUnits operator+(const NumberWithUnits& num);
        const NumberWithUnits operator+()const;
        
         // binary addition adn assigment
        const NumberWithUnits& operator+=(const NumberWithUnits& num)const;

         // prefix and postfix addittion operator
        const NumberWithUnits& operator++()const; 
        const NumberWithUnits& operator++(int num)const;
        
        // unary and binary substraction 
        const NumberWithUnits operator-()const;
        const NumberWithUnits operator-(const NumberWithUnits& num);

        // binary substraction adn assigment
        const NumberWithUnits& operator-=(const NumberWithUnits& num) const;

         //prefix substraction  operator
        const NumberWithUnits& operator--()const;

        // postfix substraction
        const NumberWithUnits& operator--(int num)const;


        // assigment operator
        const NumberWithUnits& operator=(const NumberWithUnits& num)const ;
        /* 6 comparission operators*/

        // equal operator
        bool operator==(const NumberWithUnits& num)const;
        // not equal operator
        bool operator!=(const NumberWithUnits& num)const;
        // grather equal operator
        bool operator>=(const NumberWithUnits& num)const;
        // smaller equal operator
        bool operator<=(const NumberWithUnits& num)const;
        // grather than operator
        bool operator>( const NumberWithUnits& num)const;
        // smaller than operator
        bool operator<( const NumberWithUnits& num)const;
      

        /*  multiplication operator */
       friend const NumberWithUnits& operator*(const NumberWithUnits& num,const double x) ;
       friend const NumberWithUnits& operator*(const double x,const NumberWithUnits& num) ;

       static void read_units(ifstream& file);

        /* input and output operators */
        // output operator
       friend ostream& operator<<(ostream&, const NumberWithUnits& num);

        // input operator
       friend istream& operator>>(istream& is,NumberWithUnits& num);
    };
    
     

    }