/*  DVA   */
#include "mlisp.h"
double day__of__week/*2*/ ();
	 double zeller/*9*/ (double d, double m
	 , double y, double c);
	 double neg__to__pos/*19*/ (double d);
	 double birthday/*24*/ (double dw);
	 extern double dd/*45*/ ;
	 extern double mm/*46*/ ;
	 extern double yyyy/*47*/ ;
	 //________________ 
double day__of__week/*2*/ (){
 return
 zeller(dd
	 , ((3. >= mm)
	? (mm + 10.)
	: true
	? (mm - 2.)
	: _infinity)
	 , remainder(((3. >= mm)
	? (yyyy - 1.)
	: true
	? yyyy
	: _infinity)
	 , 100.)
	 
	 , quotient(((3. >= mm)
	? (yyyy - 1.)
	: true
	? yyyy
	: _infinity)
	 , 100.)
	 )
	 ;
	 }

double zeller/*9*/ (double d, double m
	 , double y, double c){
 return
 neg__to__pos(remainder((d + y + quotient(((26. * m) - 2.)
	 , 10.)
	  + quotient(y
	 , 4.)
	  + quotient(c
	 , 4.)
	  + (2. * (- c)))
	 , 7.)
	 );
	 }

double neg__to__pos/*19*/ (double d){
 return
 ((0. >= d)
	? (d + 7.)
	: true
	? d
	: _infinity);
	 }

double birthday/*24*/ (double dw){
 display("Your were born on ");
	 ((dw == 1.)
	? display("Monday "),
	 0.
	: (dw == 2.)
	? display("Tuesday "),
	 0.
	: (dw == 3.)
	? display("Wednesday "),
	 0.
	: (dw == 4.)
	? display("Thursday "),
	 0.
	: (dw == 5.)
	? display("Friday "),
	 0.
	: (dw == 6.)
	? display("Saturday "),
	 0.
	: (dw == 7.)
	? display("Sunday "),
	 0.
	: _infinity);
	 display(dd);
	 display(".");
	 display(mm);
	 display(".");
	 return
 yyyy;
	 }

double dd/*45*/ = 31.;
	 
double mm/*46*/ = 07.;
	 
double yyyy/*47*/ = 2001.;
	 int main(){
 display("Calculations!");
	 newline();
	 display(birthday(day__of__week()));
	 newline();
	 std::cin.get();
	 return 0;
	 }

