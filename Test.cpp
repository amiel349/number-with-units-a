#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include <fstream>
#include "NumberWithUnits.hpp"
using namespace std;
using namespace ariel;

// members of distance
    
    NumberWithUnits d_a{2, "km"}; 
    NumberWithUnits d_b{2, "m"}; 

    //mambers of weight

    NumberWithUnits w_a{2, "ton"}; 
    NumberWithUnits w_b{2, "kg"}; 

    //mambers of coin

    NumberWithUnits c_a{1, "ILS"}; 
    NumberWithUnits c_b{1, "USD"}; 

TEST_CASE("good addition and subtraction postfix and prefix"){
    
     
    CHECK((d_a+d_b)==NumberWithUnits{2.002, "km"});
    CHECK((w_a+w_b)==NumberWithUnits{2.002, "ton"});
    CHECK((c_a+c_b)==NumberWithUnits{4.33, "ILS"});
    CHECK((d_a-d_b)==NumberWithUnits{1.998, "km"});
    CHECK((w_a-w_b)==NumberWithUnits{1.998, "ton"});
    CHECK((c_a-c_b)==NumberWithUnits{-2.33, "ILS"});

    CHECK((d_a+=d_b)==NumberWithUnits{2.002, "km"});
    CHECK((w_a+=w_b)==NumberWithUnits{2.002, "ton"});
    CHECK((c_a+=c_b)==NumberWithUnits{4.33, "ILS"});
    CHECK((d_a-=d_b)==NumberWithUnits{1.998, "km"});
    CHECK((w_a-=w_b)==NumberWithUnits{1.998, "ton"});
    CHECK((c_a-=c_b)==NumberWithUnits{-2.33, "ILS"});



    d_a={2, "km"}; 
    w_a={2, "ton"}; 

    CHECK((-d_a)==NumberWithUnits{-2.00, "km"});
    CHECK((-w_a)==NumberWithUnits{-2.00, "ton"});
    CHECK((+d_a)==NumberWithUnits{2.00, "km"});
    CHECK((+w_a)==NumberWithUnits{2.00, "ton"});

    CHECK((--d_a)==NumberWithUnits{1.00, "km"});
    CHECK((--w_a)==NumberWithUnits{1.00, "ton"});

     CHECK((++d_a)==NumberWithUnits{2.00, "km"});
    CHECK((++w_a)==NumberWithUnits{2.00, "ton"});

     CHECK((d_a--)==NumberWithUnits{2.00, "km"});
     CHECK((w_a--)==NumberWithUnits{2.00, "ton"});

     CHECK((d_a++)==NumberWithUnits{1.00, "km"});
    CHECK((w_a++)==NumberWithUnits{1.00, "ton"});

     CHECK((d_a)==NumberWithUnits{2.00, "km"});
    CHECK((w_a)==NumberWithUnits{2.00, "ton"});


    

   
    
    }

    TEST_CASE("wrong addition and subtraction"){
    
     // objects are from diffrent types
    CHECK_THROWS((d_a+w_b));
    CHECK_THROWS((w_a+c_b));
    CHECK_THROWS((d_a-w_b));
    CHECK_THROWS((w_a-c_b));

    CHECK_THROWS((d_a+=w_b));
    CHECK_THROWS((w_a+=c_b));
    CHECK_THROWS((d_a-=w_b));
    CHECK_THROWS((w_a-=c_b));
    
    }

    TEST_CASE("good and wrong assignment"){
    
     d_a=d_b;
     c_a=c_b;
     w_a=w_b;
    CHECK((d_a)==NumberWithUnits{2.00, "m"});
    CHECK((w_a)==NumberWithUnits{2.00, "kg"});
    CHECK((c_a)==NumberWithUnits{1.00, "USD"});

    
    CHECK_THROWS(d_a=w_b);
    CHECK_THROWS((w_a=c_b));
    CHECK_THROWS((d_a=w_b));
    CHECK_THROWS((w_a=c_b));
    }

TEST_CASE("good comparission operators"){


    d_a={2, "km"}; 
    d_b={2, "m"}; 

    w_a={2, "ton"}; 
    w_b={2, "kg"}; 

    c_a={1, "ILS"}; 
    c_b={1, "USD"}; 
    
     // gt
    CHECK((d_a)>NumberWithUnits{1, "km"});
    CHECK((w_a)>NumberWithUnits{1, "ton"});
    CHECK((c_a)>NumberWithUnits{.5, "ILS"});
    //lt
    CHECK((d_a)<NumberWithUnits{50, "km"});
    CHECK((w_a)<NumberWithUnits{50, "ton"});
    CHECK((c_a)<NumberWithUnits{50, "ILS"});
    // not equal
    CHECK((d_a)!=NumberWithUnits{1.998, "km"});
    CHECK((w_a)!=NumberWithUnits{1.998, "ton"});
    CHECK((c_a)!=NumberWithUnits{-2.33, "ILS"});

    CHECK((d_a)>=NumberWithUnits{2, "km"});
    CHECK((w_a)>=NumberWithUnits{2, "ton"});
    CHECK((c_a)>=NumberWithUnits{1, "ILS"});
    //equal less than
    CHECK((d_a)<=NumberWithUnits{2, "km"});
    CHECK((w_a)<=NumberWithUnits{2, "ton"});
    CHECK((c_a)<=NumberWithUnits{1, "ILS"});

   

   
    
    }

    TEST_CASE("bad comparission operators"){

    d_a={2, "km"}; 
    d_b={2, "m"}; 

    w_a={2, "ton"}; 
    w_b={2, "kg"}; 

    c_a={1, "ILS"}; 
    c_b={1, "USD"};

    
     // gt
    CHECK_FALSE((d_a)>NumberWithUnits{3, "km"});
    CHECK_FALSE((w_a)>NumberWithUnits{3, "ton"});
    CHECK_FALSE((c_a)>NumberWithUnits{3, "ILS"});
    //lt
    CHECK_FALSE((d_a)<NumberWithUnits{1, "km"});
    CHECK_FALSE((w_a)<NumberWithUnits{1, "ton"});
    CHECK_FALSE((c_a)<NumberWithUnits{.5, "ILS"});
    // not equal
    CHECK_FALSE((d_a)!=NumberWithUnits{2, "km"});
    CHECK_FALSE((w_a)!=NumberWithUnits{2, "ton"});
    CHECK_FALSE((c_a)!=NumberWithUnits{1, "ILS"});

    CHECK_FALSE((d_a)>=NumberWithUnits{3, "km"});
    CHECK_FALSE((w_a)>=NumberWithUnits{3, "ton"});
    CHECK_FALSE((c_a)>=NumberWithUnits{3, "ILS"});
    //equal less than
    CHECK_FALSE((d_a)<=NumberWithUnits{1, "km"});
    CHECK_FALSE((w_a)<=NumberWithUnits{1, "ton"});
    CHECK_FALSE((c_a)<=NumberWithUnits{1, "ILS"});

    }

TEST_CASE("wrong comparission operators"){

      bool a;
    d_a={2, "km"}; 
    d_b={2, "m"}; 

    w_a={2, "ton"}; 
    w_b={2, "kg"}; 

    c_a={1, "ILS"}; 
    c_b={1, "USD"}; 
    
     // gt
    CHECK_THROWS(a=(d_a)>w_a);
    CHECK_THROWS(a=(w_a)>c_a);
    //lt
    CHECK_THROWS(a=(d_a)<c_a);
    CHECK_THROWS(a=(w_a)<c_b);
    // not equal
    CHECK_THROWS(a=(d_a)!=c_b);
    CHECK_THROWS(a=(w_a)!=c_b);

    CHECK_THROWS(a=(d_a)>=c_b);
    CHECK_THROWS(a=(w_a)>=c_b);
    //equal less than
    CHECK_THROWS( a =d_a<=c_b);
    CHECK_THROWS( a =w_a<=c_b);
    }

TEST_CASE("multiplication operator"){
    
     
    CHECK((d_a*2)==NumberWithUnits{4, "km"});
    CHECK((w_a*2)==NumberWithUnits{4, "ton"});
    CHECK((c_a*2)==NumberWithUnits{2, "ILS"});
    CHECK((2*d_a)==NumberWithUnits{4, "km"});
    CHECK((2*w_a)==NumberWithUnits{4, "ton"});
    CHECK((2*c_a)==NumberWithUnits{2, "ILS"});
    }

    
    
   