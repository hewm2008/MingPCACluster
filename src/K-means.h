#ifndef Kmeans_H_
#define Kmeans_H_


#include<algorithm>
#include<list> 
#include <bits/stdc++.h> 
#include<fstream>
#include <cmath>

using namespace std;

//#define PI 3.14159265

/*
//#define int long long int
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define fori(it,A) for(it=A.begin();it!=A.end();it++)
//#define out1(a) cout<<#a<<" "<<a<<endl
//#define out2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
//#define out3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
//#define out4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
//#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ft first
#define sd second
#define pb push_back
#define mp make_pair
//#define endl "\n"
#define maxn 100001
*/

#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;


//vector<float> err;

struct Point
{
	float x;
	float y;
	float z;
	int Cluster_no;
};

float distance(Point a, Point b)
{
	return sqrtf( powf((a.x - b.x),2) + powf((a.y - b.y),2) + powf((a.z - b.z),2) );
}

/*
   void get_data(vector<Point> &data)
   {

   ifstream file;
   file.open("data.csv");

   if(!file.is_open()) cout<<"Could not open file"<<endl;
   else cout<<"File open!"<<endl;

   string word,line,temp;
   getline(file,line);
   cout<<line<<endl;

   while(getline(file,line))
   {	
   stringstream s(line);
   int cnt=0;
   Point a = {0,0,0,-1};
   while(getline(s,word,','))
   {
   if(cnt == 0) a.x = atof(word.c_str());
   if(cnt == 1) a.y = atof(word.c_str());
   if(cnt == 2) a.z = atof(word.c_str());

   cnt++;
   }
   data.push_back(a);
   }
   }
   */

/*
   float NewSSE(vector<Point> &data,vector<Point> &cluster)
   {
   float sse=0;
   int  NN=data.size();
   float Count=0;
   for (int ii=0; ii<NN,ii++)
   {
   if(data[ii].Cluster_no!=-1)
   {
   for (int jj=0; jj<NN,jj++)
   {
   if (data[ii].Cluster_no!=data[jj].Cluster_no)
   {

   }
   if (ii==jj)
   {
   continue;
   }
   sse+=distance(data[ii],data[jj]);
   Count++;
   }
   }
   }
   if  (Count!=0)
   {
   sse=sse/Count;
   }
   return sse;
   }
   */

///*//
float SSE(vector<Point> &data,vector<Point> &cluster)
{
	float sse=0;
	int Count=0;
	rep(i,0,data.size())
	{
		if(data[i].Cluster_no!=-1)
		{
			sse += powf(distance(data[i],cluster[data[i].Cluster_no]),2);
			Count++;
		}
	}
	if  (Count!=0)
	{
		sse=sse/Count;
	}
	//this code was earlier used as i was iterating this process over various K and storing the error to find elbow point
	// err.push_back(sse);

	return sse;
}


/*
   The Davies–Bouldin index (DBI) (introduced by David L. Davies and 
   Donald W. Bouldin in 1979) is a metric for evaluating clustering algorithms. 
   This is an internal evaluation scheme, where the validation of how well the 
   clustering has been done is made using quantities and features inherent to the dataset.
   This is the function of K cluster calculation DBI developed by hewm2008
   Davies-Bouldin Index(戴维森堡丁指数)
   *///
double Davies_Bouldin_index(vector<Point> &data,vector<Point> &cluster,int KK)
{
	double DBi=0;
	int  NN=data.size();
	vector <double> SumDis (KK,0);
	vector <int> Count (KK,0);

	for (int ii=0; ii<NN ; ii++)
	{
		int NumCluster=data[ii].Cluster_no;
		if(NumCluster!=-1)
		{
			for (int jj=ii+1; jj<NN; jj++)
			{
				if (NumCluster==data[jj].Cluster_no)
				{
					SumDis[NumCluster]+=distance(data[ii],data[jj]);
					Count[NumCluster]++;
				}
			}
		}
	}

	for (int ii=0 ; ii<KK; ii++)
	{
		if  (Count[ii]!=0)
		{
			SumDis[ii]=SumDis[ii]/Count[ii];
		}
	}


	for (int ii=0 ; ii<KK; ii++)
	{
		double MaxEE=0;
		double index=0;
		for (int jj=ii+1; jj<KK ;jj++)
		{
			index =((SumDis[ii] + SumDis[jj]))/(distance(cluster[ii],cluster[jj]));
			if (MaxEE<index) {MaxEE=index;}
		}
		DBi+=MaxEE;
	}

	DBi=DBi/KK;

	return DBi;
}



//*/


/*
   void put_data(vector<Point> &data,int K)
   {
   ofstream file;
   file.open("clustered_data.csv");

   rep(i,0,data.size())
   {
   file<<data[i].x<<", "<<data[i].y<<", "<<data[i].z<<", "<<data[i].Cluster_no<<"\n";
   }
   }
   */

/*
   void standardize(vector<Point> &data)
   {
   float mean_x,sd_x,mean_y,sd_y,mean_z,sd_z;

   mean_x = 0;mean_y = 0;mean_z = 0;
   sd_x=0;sd_y=0;sd_z=0;

//Calculatung Mean
rep(i,0,data.size())
{
mean_x += data[i].x;mean_y += data[i].y;mean_z += data[i].z;
}
mean_x /= data.size();
mean_y /= data.size();
mean_z /= data.size();

//Calculating S.D
rep(i,0,data.size())
{
sd_x += powf((data[i].x - mean_x),2);sd_y += powf((data[i].y - mean_y),2);sd_z += powf((data[i].z - mean_z),2);
}
sd_x /= data.size();
sd_y /= data.size();
sd_z /= data.size();
sd_x=sqrtf(sd_x);sd_y=sqrtf(sd_y);sd_z=sqrtf(sd_z);

//Standardize
rep(i,0,data.size())
{
data[i].x = (data[i].x - mean_x)/sd_x;
data[i].y = (data[i].y - mean_y)/sd_y;
data[i].z = (data[i].z - mean_z)/sd_z;
}

}
///*///*//

//*///
void initialize_clustera(int K, vector<Point> &cluster, vector<Point> &data)
{
	unordered_map<int,int> index_visited;
	int cnt=0;
	while(cnt != K)
	{
		int z = rand()%(data.size());
		if(index_visited[z]!=1)
		{
			index_visited[z]=1;
			cluster[cnt] = data[z];
			cnt++;
		}
	}
}
///*///

// new initialize function  delelop by hewm2008  
void initialize_clustera_V2(int K, vector<Point> &cluster, vector<Point> &data, double  & XXmax , double  & XXmin ,double  & YYmax,double  & YYmin )
{

	double XXMid=(XXmax+XXmin)*0.5;
	double YYMid=(YYmax+YYmin)*0.5;
	//	double ZZMid=0;
	double Radius=abs(XXmax-XXMid)*0.70; // 0.7 is the rand num 
	double angle=360.0/K;
	double DetaYY=(YYmax-YYmin)*1.0/(XXmax-XXmin);
	//	double DetaZZ=(ZZmax-ZZmin)*1.0/(XXmax-XXmin);
	double TmpPI=0.017453295;  // PI/180 
	int NN=data.size();

	double DetaAngle=angle/20 ;
	float min_Sumdist = FLT_MAX ;
	float max_Sundist =0;

	vector<Point> Precluster (K,{0,0,0,-1});

	for (int Time=0; Time<20 ; Time++)
	{

		unordered_map<int,int> index_visited;
		double DDtaAngle=DetaAngle*Time;
		double TmpComAngle=0;
		for (int cnt=0; cnt<K ; cnt++)
		{
			double AA=(angle*cnt+DDtaAngle)*TmpPI;
			double XX=XXMid+Radius*sin(AA);
			double YY=YYMid+Radius*cos(AA)*DetaYY;
			float min_dist = FLT_MAX;
			int ThisNj=K;
			for (int z=0 ; z< NN ; z++)
			{
				if(index_visited[z]!=1)
				{
					double Dis=sqrtf(powf((data[z].x-XX),2)+ powf((data[z].y - YY),2));
					if (min_dist>Dis)
					{
						ThisNj=z;
						min_dist=Dis;
					}
				}
			}
			Precluster[cnt] = data[ThisNj];
			index_visited[ThisNj]=1;
			TmpComAngle+=min_dist;
		}

		/*//
		  double  Par=0;
		  for (int UU=0; UU<K; UU++)
		  {
		  for (int TT=UU+1; TT<K; TT++)
		  {
		  Par+=distance(Precluster[UU],Precluster[TT]);
		  }
		  }
		  if ( max_Sundist < Par )
		  {
		  max_Sundist=Par;
		  for (int UU=0; UU<K; UU++)
		  {
		  cluster[UU] =Precluster[UU];
		  }
		  }
		//*///

		if (min_Sumdist>TmpComAngle)
		{
			min_Sumdist=TmpComAngle;
			for (int UU=0; UU<K; UU++)
			{
				cluster[UU] =Precluster[UU];
			}
		}

		//		cerr<<K<<"\t"<<Time<<"\t"<<max_Sundist<<"\t"<<min_Sumdist<<"\n";
	}
}




void assign_clusters(vector<Point> &cluster, vector<Point> &data)
{
	rep(i,0,data.size())
	{
		float min_dist = FLT_MAX;

		rep(j,0,cluster.size())
		{
			float dist = distance(data[i], cluster[j]);
			if(dist < min_dist)
			{
				min_dist=dist;
				data[i].Cluster_no = j;
			}
		}
	}
}

void recalculate_clusters(vector<Point> &cluster, vector<Point> &data,int K)
{
	Point temp={0,0,0,-1};
	temp.x=0;
	temp.y=0;
	temp.z=0;
	vector<Point> cluster_sum(K,temp);
	vector<int> cluster_num(K,0);

	rep(i,0,data.size())
	{
		if(data[i].Cluster_no != -1)
		{
			cluster_sum[data[i].Cluster_no].x += data[i].x;
			cluster_sum[data[i].Cluster_no].y += data[i].y;
			cluster_sum[data[i].Cluster_no].z += data[i].z;
			cluster_num[data[i].Cluster_no]++;
		}
	}
	rep(i,0,K)
	{
		if(cluster_num[i]!=0)
		{
			cluster[i].x = cluster_sum[i].x / cluster_num[i];
			cluster[i].y = cluster_sum[i].y / cluster_num[i];
			cluster[i].z = cluster_sum[i].z / cluster_num[i];
		}
	}
}


bool is_different(vector<Point> &cluster,vector<Point> &previous_cluster,float error_limit)
{
	bool not_valid=false;
	rep(i,0,cluster.size())
	{
		if(cluster[i].x - previous_cluster[i].x > error_limit)
		{
			not_valid=true;
		}
		if(cluster[i].y - previous_cluster[i].y > error_limit)
		{
			not_valid=true;
		}
		if(cluster[i].z - previous_cluster[i].z > error_limit)
		{
			not_valid=true;
		}
	}
	return not_valid;
}

/*
   signed main()
   {
//K defines the number of clusters.
//4 was chosen as it was found ideal by elbow method
int K = 4;

//This is to store all the points in dataset
vector<Point> data;
get_data(data);

//As the data is in different scales its necessary to standardize it
standardize(data);

cout<<"Lets take a look at standardized data : "<<endl;
rep(i,0,5)
{
cout<<data[i].x<<" "<<data[i].y<<" "<<data[i].z<<endl;
}
cout<<endl;

//Initially each point dosent belong to any cluster
rep(i,0,data.size())
{
data[i].Cluster_no=-1;
}

//stores the Cluster Centroids
vector<Point> cluster(K,{0,0,0,-1});
//We will first randomly select clusters from data
initialize_clustera(K,cluster,data);

cout<<"Initial values: "<<endl;
rep(i,0,K)
{
cout<<cluster[i].x<<","<<cluster[i].y<<","<<cluster[i].z<<endl;
}
cout<<endl;

//Stores the cluster centroids as they are later updated
vector<Point> previous_cluster(K,{0,0,0,-1});

//Do try other error limits
float error_limit = 0.000001;

while(is_different(cluster,previous_cluster,error_limit))
{
assign_clusters(cluster,data);

rep(i,0,K)
/previous_cluster
{
previous_cluster[i] = cluster[i];
}

recalculate_clusters(cluster,data,K);
}

assign_clusters(cluster,data);

//Final centroid positions
cout<<"FINAL: "<<endl;
rep(i,0,K)
{
cout<<cluster[i].x<<" "<<cluster[i].y<<" "<<cluster[i].z<<endl;
}
cout<<endl;

put_data(data,K);
cout<<"SSE : "<<SSE(data,cluster)<<endl;



}
*/
#endif 




