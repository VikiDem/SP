/* $n08 */
#include "code-gen.h"
using namespace std;
void tCG::init(){declarations.clear();
 Authentication = "DVA";
//                  ^ 
// replace with your initials!!! 
}
int tCG::p01(){ // S -> PROG
  string header ="/*  " + Authentication +"   */\n";
  header += "#include \"mlisp.h\"\n";
  header += declarations;
  header += "//________________ \n";
  S1->obj = header + S1->obj;
	return 0;}
int tCG::p02(){ //    PROG -> CALCS
    S1->obj = "int main(){\n " + S1->obj + "std::cin.get();\n\t return 0;\n\t }\n";
	return 0;}
int tCG::p03(){ //    PROG -> DEFS
    S1->obj += "int main(){\n "
               "display(\"No calculations!\");\n\t newline();\n\t "
               "std::cin.get();\n\t return 0;\n\t }\n";
	return 0;}
int tCG::p04(){ //    PROG -> DEFS CALCS
    S1->obj += "int main(){\n "
               "display(\"Calculations!\");\n\t newline();\n\t ";
    S1->obj += S2->obj;
    S1->obj += "std::cin.get();\n\t return 0;\n\t }\n";
	return 0;}
int tCG::p05(){ //       E -> $id
	S1->obj = decor(S1->name);
	return 0;}
int tCG::p06(){ //       E -> $int
	S1->obj = S1->name + ".";
	return 0;}
int tCG::p07(){ //       E -> $dec
    S1->obj = S1->name;
	return 0;}
int tCG::p08(){ //       E -> AREX
	return 0;}
int tCG::p09(){ //       E -> COND
	return 0;}
int tCG::p10(){ //       E -> EASYLET
	return 0;}
int tCG::p11(){ //       E -> CPROC
	return 0;}
int tCG::p12(){ // EASYLET -> HEASYL E )
//
	if (S1->count != 0)
        S1->obj += S2->obj + ";\n\t";
    S1->obj += S2->obj;
    ++(S1->count);
	return 0;}
int tCG::p13(){ //  HEASYL -> ( let ( )
//
	return 0;}
int tCG::p14(){ //  HEASYL -> HEASYL INTER
//
	S1->obj += S2->obj + ",\n\t ";
	return 0;}
int tCG::p15(){ //    AREX -> HAREX E )
	if (S1->count == 0 && S1->name == "/")
    	S1->obj = "(1. " + S1->obj + " " + S2->obj + ")";
	else
   	 S1->obj = "(" + S1->obj + " " + S2->obj + ")";
	return 0;}
int tCG::p16(){ //   HAREX -> ( AROP
	S1->obj = S2->obj;
	S1->name = S2->name;
	return 0;}
int tCG::p17(){ //   HAREX -> HAREX E
	if (S1->count == 0)
		S1->obj = S2->obj + " " + S1->name;
	else
    	S1->obj = S1->obj + " " + S2->obj + " " + S1->name;
	++(S1->count);
	return 0;}
int tCG::p18(){ //    AROP -> +
	S1->obj = S1->name;
	return 0;}
int tCG::p19(){ //    AROP -> -
	S1->obj = S1->name;
	return 0;}
int tCG::p20(){ //    AROP -> *
	S1->obj = S1->name;
	return 0;}
int tCG::p21(){ //    AROP -> /
	S1->obj = S1->name;
	return 0;}
int tCG::p22(){ //   CPROC -> HCPROC )
	if (S1->count <= 1)
        S1->obj = S1->obj + ")";
    else
        S1->obj = S1->obj + ")\n\t ";
	return 0;}
int tCG::p23(){ //  HCPROC -> ( $id
	S1->obj = decor(S2->name) + "(";
	return 0;}
int tCG::p24(){ //  HCPROC -> HCPROC E
    if (S1->count)
        S1->obj += "\n\t , ";
    S1->obj += S2->obj;
    ++(S1->count);
	return 0;}
int tCG::p25(){ //    COND -> ( cond BRANCHES )
	S1->obj = "(" + S3->obj + "_infinity)";
	return 0;}
int tCG::p26(){ //BRANCHES -> CLAUS
	return 0;}
int tCG::p27(){ //BRANCHES -> CLAUS BRANCHES
//
//	S1->obj += "\n\t: " + S2->obj;
	S1->obj = S1->obj + S2->obj;
	return 0;}
int tCG::p28(){ //   CLAUS -> ( BOOL E )
	S1->obj = "" + S2->obj + "\n\t? " + S3->obj + "\n\t: ";
	return 0;}
int tCG::p29(){ //     STR -> $str
    S1->obj = S1->name;
	return 0;}
int tCG::p30(){ //     STR -> SIF
	return 0;}
int tCG::p31(){ //     SIF -> ( if BOOL STR STR )
	S1->obj = "(" + S3->obj + "\n\t? " + S4->obj + "\n\t: " + S5->obj + ")";
	return 0;}
int tCG::p32(){ //    BOOL -> $bool
    S1->obj += (S1->name == "#t" ? "true" : "false");
	return 0;}
int tCG::p33(){ //    BOOL -> $idq
    S1->obj = decor(S1->name);
	return 0;}
int tCG::p34(){ //    BOOL -> REL
	return 0;}
int tCG::p35(){ //    BOOL -> OR
	return 0;}
int tCG::p36(){ //    BOOL -> ( not BOOL )
    S1->obj = "(!" + S3->obj + ")";
	return 0;}
int tCG::p37(){ //    BOOL -> CPRED
	return 0;}
int tCG::p38(){ //   CPRED -> HCPRED )
    S1->obj += ")";
	return 0;}
int tCG::p39(){ //  HCPRED -> ( $idq
    S1->obj = decor(S2->name) + "(";
	return 0;}
int tCG::p40(){ //  HCPRED -> HCPRED ARG
    if (S1->count)
        S1->obj += S1->count % 2 ? ", " : "\n\t , ";
    S1->obj += S2->obj;
    ++(S1->count);
	return 0;}
int tCG::p41(){ //     ARG -> E
	return 0;}
int tCG::p42(){ //     ARG -> BOOL
	return 0;}
int tCG::p43(){ //     REL -> ( = E E )
    S1->obj = "(" + S3->obj + " == " + S4->obj + ")";
	return 0;}
int tCG::p44(){ //     REL -> ( >= E E )
    S1->obj = "(" + S3->obj + " >= " + S4->obj + ")";
	return 0;}
int tCG::p45(){ //      OR -> HOR BOOL )
	if (S1->count == 0) S1->obj += " " + S2->obj + " )";
    else S1->obj += " || " + S2->obj + " )";
	return 0;}
int tCG::p46(){ //     HOR -> ( or
	S1->obj = "(";
	return 0;}
int tCG::p47(){ //     HOR -> HOR BOOL
	if (S1->count == 0) S1->obj += " " + S2->obj;
    else S1->obj += " || " + S2->obj;
    ++S1->count;
	return 0;}
int tCG::p48(){ //     SET -> HSET E )
    S1->obj += S2->obj;
	return 0;}
int tCG::p49(){ //    HSET -> ( set! $id
    S1->obj = decor(S3->name) + " = ";
	return 0;}
int tCG::p50(){ // DISPSET -> ( display E )
    S1->obj = "display(" + S3->obj + ")";
	return 0;}
int tCG::p51(){ // DISPSET -> ( display BOOL )
    S1->obj = "display(" + S3->obj + ")";
	return 0;}
int tCG::p52(){ // DISPSET -> ( display STR )
    S1->obj = "display(" + S3->obj + ")";
	return 0;}
int tCG::p53(){ // DISPSET -> ( newline )
    S1->obj = "newline()";
	return 0;}
int tCG::p54(){ // DISPSET -> SET
	return 0;}
int tCG::p55(){ //   INTER -> DISPSET
	return 0;}
int tCG::p56(){ //   INTER -> E
	return 0;}
int tCG::p57(){ //   CALCS -> CALC
	return 0;}
int tCG::p58(){ //   CALCS -> CALCS CALC
    S1->obj += S2->obj;
	return 0;}
int tCG::p59(){ //    CALC -> E
    S1->obj = "display(" + S1->obj + ");\n\t newline();\n\t ";
	return 0;}
int tCG::p60(){ //    CALC -> BOOL
    S1->obj = "display(" + S1->obj + ");\n\t newline();\n\t ";
	return 0;}
int tCG::p61(){ //    CALC -> STR
    S1->obj = "display(" + S1->obj + ");\n\t newline();\n\t ";
	return 0;}
int tCG::p62(){ //    CALC -> DISPSET
    S1->obj = S1->obj + ";\n\t ";
	return 0;}
int tCG::p63(){ //    DEFS -> DEF
	return 0;}
int tCG::p64(){ //    DEFS -> DEFS DEF
    S1->obj = S1->obj + "\n" + S2->obj;
	return 0;}
int tCG::p65(){ //     DEF -> PRED
	return 0;}
int tCG::p66(){ //     DEF -> VAR
	return 0;}
int tCG::p67(){ //     DEF -> PROC
	return 0;}
int tCG::p68(){ //    PRED -> HPRED BOOL )
    //S1->obj += S2->obj + ";\n\t }\n";
	S1->obj += S2->obj + ";\n\t }\n";
	(S1->count)++;
	return 0;}
int tCG::p69(){ //   HPRED -> PDPAR )
    S1->obj += ")";
    declarations += S1->obj + ";\n\t ";
    S1->obj += "{\n return ";
    S1->count = 0;
	return 0;}
int tCG::p70(){ //   PDPAR -> ( define ( $idq
    S1->obj = "bool " + decor(S4->name) + "/*" + S4->line + "*/ (";
    S1->count = 0;
	return 0;}
int tCG::p71(){ //   PDPAR -> PDPAR $idq
    if (S1->count)
        S1->obj += S1->count % 2 ? ", " : "\n\t , ";
    S1->obj += "double " + decor(S2->name);
    ++(S1->count);
	return 0;}
int tCG::p72(){ //   PDPAR -> PDPAR $id
    if (S1->count)
        S1->obj += S1->count % 2 ? ", " : "\n\t , ";
    S1->obj += "double " + decor(S2->name);
    ++(S1->count);
	return 0;}
int tCG::p73(){ //     VAR -> VARDCL E )
    declarations += "extern double " + S1->obj + "/*" + S1->line + "*/ ;\n\t ";
    S1->obj = "double " + S1->obj + "/*" + S1->line + "*/ = " + S2->obj + ";\n\t ";
	return 0;}
int tCG::p74(){ //  VARDCL -> ( define $id
    S1->obj = decor(S3->name);
	return 0;}
int tCG::p75(){ //    PROC -> HPROC BLOCK )
    S1->obj += S2->obj + "}\n";
	return 0;}
int tCG::p76(){ //    PROC -> HPROC E )
    S1->obj += "return\n " + S2->obj + ";\n\t }\n";
	return 0;}
int tCG::p77(){ //   HPROC -> PCPAR )
    S1->obj += ")";
    declarations += S1->obj + ";\n\t ";
    S1->obj += "{\n ";
	return 0;}
int tCG::p78(){ //   HPROC -> HPROC INTER
    S1->obj += S2->obj + ";\n\t ";
	return 0;}
int tCG::p79(){ //   PCPAR -> ( define ( $id
    S1->obj = "double " + decor(S4->name) + "/*" + S4->line + "*/ (";
    S1->count = 0;
    S1->name = S4->name;
	return 0;}
int tCG::p80(){ //   PCPAR -> PCPAR $id
    if (S1->count)
        S1->obj += S1->count % 2 ? ", " : "\n\t , ";
    S1->obj += "double " + decor(S2->name);
    ++(S1->count);
	return 0;}
int tCG::p81(){ //   BLOCK -> HBLOCK E )
    S1->obj = S1->obj + "return\n " + S2->obj + ";\n\t }\n";
	return 0;}
int tCG::p82(){ //  HBLOCK -> BLVAR )
    S1->obj = S1->obj + ";\n\t ";
	return 0;}
int tCG::p83(){ //  HBLOCK -> HBLOCK INTER
    S1->obj += S2->obj + ";\n\t ";
	return 0;}
int tCG::p84(){ //   BLVAR -> ( let ( LOCDEF
    S1->obj = "{\n double " + S4->obj;
	return 0;}
int tCG::p85(){ //   BLVAR -> BLVAR LOCDEF
    S1->obj += ",\n\t " + S2->obj;
	return 0;}
int tCG::p86(){ //  LOCDEF -> ( $id E )
    S1->obj += decor(S2->name) + "(" + S3->obj + ")";
	return 0;}
//_____________________
int tCG::p87(){return 0;} int tCG::p88(){return 0;} 
int tCG::p89(){return 0;} int tCG::p90(){return 0;} 
int tCG::p91(){return 0;} int tCG::p92(){return 0;} 
int tCG::p93(){return 0;} int tCG::p94(){return 0;} 
int tCG::p95(){return 0;} int tCG::p96(){return 0;} 
int tCG::p97(){return 0;} int tCG::p98(){return 0;} 
int tCG::p99(){return 0;} int tCG::p100(){return 0;} 
int tCG::p101(){return 0;} int tCG::p102(){return 0;} 
int tCG::p103(){return 0;} int tCG::p104(){return 0;} 
int tCG::p105(){return 0;} int tCG::p106(){return 0;} 
int tCG::p107(){return 0;} int tCG::p108(){return 0;} 
int tCG::p109(){return 0;} int tCG::p110(){return 0;} 


