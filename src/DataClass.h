
////////////////////////swimming in the sea & flying in the sky //////////////////


/*
 * DataClass.h
 *
 *  Created on: 2021-11-21
 *      Author: hewm@genomics.cn
 */

#ifndef DataClass_H_
#define DataClass_H_


using namespace std;


class In3str1v {
	public:
		string InStr1;
		string InStr2;
		string InStr3;
		string InSTOgem;
		string SubPop;
		string PlotPara;
		string SampleGroup;
		string BinDir;
		string InKinship;
		string InPlink;
		string STOName;
		int  ClusterBin ;
		int  CellBin ;
		bool NoShow ;
		bool RandomCenter ;
		bool TF2 ;
		int  Method ;
		double BestKRatio ;
		int ClusterNum;
		int PCANum ;
		In3str1v()
		{
			InStr1="";
			InStr2="";
			InStr3="";
			SubPop="";
			STOName="S";
			PlotPara="";
			InPlink="";
			InSTOgem="";
			ClusterBin=10;
			CellBin=100;
			NoShow=true;
			TF2=true;
			RandomCenter=true;
			Method=1;
			SampleGroup="";
			InKinship="";
			BinDir="";
			BestKRatio=0.15;
			ClusterNum=12;
			PCANum=10;
		}
};


class Para_18 {
	public:
		string input ;
		string FChrName ;
		double Het ;
		double Miss ;
		double MAF ;
		double HWE;
		int Cut3base ;
		Para_18()
		{
			input="";
			FChrName="chrX,chrY,X,Y";
			Het=1.001 ;
			Miss=0.25 ;
			Cut3base=0;
			MAF=0.001;
			HWE=0;
		}
};




#endif /* DataClass_H_ */

//////////////// swimming in the sky and flying in the sea ////////////////
