/**
 * Demo file for the exercise on numbers with units
 *
 * @author Amiel Lejzor
 * @since 2021
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "NumberWithUnits.hpp"
using namespace ariel;


namespace ariel{
    
       
        NumberWithUnits::NumberWithUnits(double num, const string unit){this->number = num; this->type =unit;}
      
        
        /* 6 arithmetic operations */

        // unary and binaary addition
          const NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& num){
            return NumberWithUnits(0,"USD");
        }
        const NumberWithUnits NumberWithUnits::operator+()const{
            return NumberWithUnits(0,"USD");
        }
        // binary addition adn assigment
       const NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& num)const {return num;}
        // prefix addition operator
       const NumberWithUnits& NumberWithUnits::operator++()const{return *this;}
        // postfix addition
       const NumberWithUnits& NumberWithUnits::operator++(int num)const{return *this;}

        // unary substraction
       const NumberWithUnits NumberWithUnits::operator-()const{return NumberWithUnits(0,"USD");}

       const NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& num){return NumberWithUnits(0,"USD"); }
        //prefix substraction  operator
       const NumberWithUnits& NumberWithUnits::operator--()const{return *this;}
        // postfix substraction
       const NumberWithUnits& NumberWithUnits::operator--(int num)const{return *this;}
        // binary substraction adn assigment
       const NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& num)const{return num;}




        // assigment operator
       const NumberWithUnits& NumberWithUnits::operator=(const NumberWithUnits& num)const {return num;}
        


        /* 6 comparission operators*/

        // equal operator
       bool ariel::NumberWithUnits::operator==(const NumberWithUnits& num)const{ return true;} 
        // not equal operator
       bool NumberWithUnits::operator!=(const NumberWithUnits& num)const {return true;}
        // grather equal operator
       bool NumberWithUnits::operator>=(const NumberWithUnits& num)const  {return true;}
        // smaller equal operator
       bool NumberWithUnits::operator<=(const NumberWithUnits& num)const  {return true;}
        // grather than operator
       bool NumberWithUnits::operator>( const NumberWithUnits& num)const  {return true;}
        // smaller than operator
       bool NumberWithUnits::operator<( const NumberWithUnits& num)const  {return true;}

    
        /*  multiplication prefix and postfix operator */

        const NumberWithUnits& operator*(const double num, const NumberWithUnits& x) {return x;}
        const NumberWithUnits& operator*(const NumberWithUnits& x,const double num) {return x;}


        /* input and output operators */
        // output operator
       ostream& operator<<(ostream & os, const NumberWithUnits& num){string s="check"; os<<s;return os;}

        // input operator
       istream& operator>>(istream & is, NumberWithUnits& num){string s="check"; is>>s;return is;}

       void NumberWithUnits::read_units(ifstream& file){};
    
    
    // ostream& operator<<(ostream &os, const NumberWithUnits& num);
    // istream& operator>>(istream &is, NumberWithUnits& num);

    }

