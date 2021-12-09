/*  DVA   */
#include "mlisp.h"
extern double VARIANT/*1*/ ;
	 extern double LAST__DIGIT__OF__GROUP__NUMBER/*2*/ ;
	 extern double KINDS__OF__COINS/*3*/ ;
	 double first__denomination/*5*/ (double kinds__of__coin);
	 double count__change/*15*/ (double amount);
	 bool pier_Q/*40*/ (double x_Q, double y_Q);
	 double cc/*45*/ (double amount, double kinds__of__coins);
	 double denomination__list/*54*/ (double kinds__of__coins);
	 double GR__AMOUNT/*64*/ ();
	 //________________ 
double VARIANT/*1*/ = 8.;
	 
double LAST__DIGIT__OF__GROUP__NUMBER/*2*/ = 6.;
	 
double KINDS__OF__COINS/*3*/ = 6.;
	 
double first__denomination/*5*/ (double kinds__of__coin){
 return
 ((kinds__of__coin == 1.)
	? 1.
	: (kinds__of__coin == 2.)
	? 2.
	: (kinds__of__coin == 3.)
	? 3.
	: (kinds__of__coin == 4.)
	? 5.
	: (kinds__of__coin == 5.)
	? 10.
	: (kinds__of__coin == 6.)
	? 15.
	: true
	? 0.
	: _infinity);
	 }

double count__change/*15*/ (double amount){
 display("______\n amount: ");
	 display(amount);
	 newline();
	 display("KINDS-OF-COINS: ");
	 display(KINDS__OF__COINS);
	 newline();
	 {
 double largest__coin(first__denomination(KINDS__OF__COINS));
	 display("largest-coin: ");
	 display(largest__coin);
	 newline();
	 return
 ((amount >= 0.)
	? ((KINDS__OF__COINS >= 0.)
	? ((largest__coin >= 0.)
	? display("List of coin denominations: "),
	 denomination__list(KINDS__OF__COINS),
	 display("count-change= "),
	 cc(amount
	 , KINDS__OF__COINS)
	 
	: true
	? display("Improper parameter value!\ncount-change= "),
	 -1.
	: _infinity)
	: true
	? display("Improper parameter value!\ncount-change= "),
	 -1.
	: _infinity)
	: true
	? display("Improper parameter value!\ncount-change= "),
	 -1.
	: _infinity);
	 }
}

bool pier_Q/*40*/ (double x_Q, double y_Q){
 return (!( x_Q || y_Q ));
	 }

double cc/*45*/ (double amount, double kinds__of__coins){
 return
 ((amount == 0.)
	? 1.
	: pier_Q((0. >= amount), (kinds__of__coins == 0.))
	? (cc(amount
	 , (kinds__of__coins - 1.))
	  + cc((amount - first__denomination(kinds__of__coins))
	 , kinds__of__coins)
	 )
	: true
	? 0.
	: _infinity);
	 }

double denomination__list/*54*/ (double kinds__of__coins){
 return
 ((kinds__of__coins == 0.)
	? newline(),
	 0.
	: true
	? display(first__denomination(kinds__of__coins)),
	 display(" "),
	 denomination__list((kinds__of__coins - 1.))
	: _infinity);
	 }

double GR__AMOUNT/*64*/ (){
 return
 remainder(((100. * LAST__DIGIT__OF__GROUP__NUMBER) + VARIANT)
	 , 231.)
	 ;
	 }
int main(){
 display("Calculations!");
	 newline();
	 display("Variant ");
	 display(VARIANT);
	 newline();
	 newline();
	 display(count__change(100.));
	 newline();
	 display(count__change(GR__AMOUNT()));
	 newline();
	 KINDS__OF__COINS = 13.;
	 display(count__change(100.));
	 newline();
	 display("(c) Demina V.A. 2021\n");
	 std::cin.get();
	 return 0;
	 }

