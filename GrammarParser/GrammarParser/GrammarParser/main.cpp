﻿/*************************************************************************************************
 *   く__,.ヘヽ.　　　　/　,ー､ 〉	
 *　　　　　＼ ', !-a a - i 　/　/´				
 *   　　　 　 ／｀ｰ'　　　 L/／｀ヽ､
 *   　　 　 /　 ／,　 /|　 ,　 ,　　　 ',
 *   　　　ｲ 　/ /--/　ｉ　L_ ﾊ ヽ!　 i
 *   　　　 ﾚ ﾍ 7ｲ／｀ﾄ　 ﾚ'ｧ-ﾄ､!ハ|　 |										
 *   　　　　 !,/7 '0'　　 ´0iソ| 　 |　　　
 *   　　　　 |.从"　　_　　 ,,,, / |./ 　 |
 *   　　　　 ﾚ'| i＞.､,,__　_,.イ / 　.i 　|
 *   　　　　　 ﾚ'| | / k_７_/ﾚ'ヽ,　ﾊ.　|
 *   　　　　　　 | |/i 〈|/　 i　,.ﾍ |　　|
 *   　　　　　　.|/ /　ｉ： 　 ﾍ!　　　　　＼|
 *   　　　 　 　 ヽ>､ﾊ 　 _,.ﾍ､ 　 /､!
 *   　　　　　　 !'〈//｀Ｔ´', ＼ ｀'7'ｰr'
 *   　　　　　　 ﾚ'ヽL__|___i,___,ンﾚ|ノ
 *   　　　　　 　　　ﾄ-,/　|___./
 *   　　　　　 　　　'ｰ'　　!_,.:
  ***********************************************************************************************/
#include <iostream>
#include "FirstAndFollow.h"
#include "PredictiveParsing.h"
#include <unordered_map>
#include<functional>
#include "Util.h"
#include "FirstRecursiveDescentImpl.h"
void test(int a){}
auto newFun = bind(test,1);
int main()
{
	FirstAndFollow ff;
	PredictiveParsing pp;


	try {
		ff.init();
		ff.splitProductions();
		//找出终结符
		ff.findVtAndVn();
		//消除左递归
		//Util::eliminateTheLeftRecursion(ff.noneTerminal, ff.splitedProductions);
		ff.getFirst();
		ff.getFollow();
		pp.getPredictiveAnalysisTable(ff);
		FirstRecursiveDescentImpl firstRecursiveDescentImpl(ff);
		
	}
	catch (const char* e) {
		cout << "There was an error: " << endl << "\t" << e << endl;
	}
	
}

