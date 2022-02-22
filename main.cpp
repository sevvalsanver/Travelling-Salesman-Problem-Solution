
// Travelling Salesman Problem

#include <bits/stdc++.h>
#include <ctime> 
#define V 100 // nxn matris icin n degeri
using namespace std;

int k;
static int t0=0;
static int t1=0;
int dizi[1000];
char charDizi[1000];
static int minP;

// int array i char array a ceviren method
char convertArray(int i)
{
    return (i%26) + 'A';
}
// simetrik matrisi bastýran method
void printMatrix(int n,int graph[][V])
{
    int initialArray[n - 1][n - 1], finalArray[n][n];
  
    for (int i = 0; i < n - 1; ++i)
        initialArray[0][i] = rand() % 50;
  
    
    for (int i = 1; i < n - 1; ++i)
        for (int j = 0; j < n - 1; ++j)
            initialArray[i][j]
                = initialArray[i - 1][(j + 1) % (n - 1)];
  
   
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1; ++j) 
            finalArray[i][j] = initialArray[i][j];
  
    
    for (int i = 0; i < n; ++i)
        finalArray[i][n - 1] = finalArray[n - 1][i] = 0;
  
    for (int i = 0; i < n; ++i) {
        int s0 = finalArray[i][i];
     	int s1 = finalArray[i][n - 1];
  
        swap(finalArray[i][i], finalArray[i][n - 1]);
  
        finalArray[n - 1][i] = s0;
    }
  
    // Final array i ekrana bastirir
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j){
		cout << finalArray[i][j] << " ";
        graph[i][j]=finalArray[i][j];
       
        
        }
        cout<<""<<endl;
    }
}
int tsp(int graph[][V], int x,int n,int E)
{
    int pathArray[1000];
   
	int t=0;

    vector<int> vertex;
    
    for (int i = 0; i < n; i++)
    {
    	 if (i != x)
    	 {
    	 	vertex.push_back(i);
		 }
            
	}
       
 
    int minPath = INT_MAX;
    
    do {
 	if(t==E)
	 {
 		minP=minPath;
		return minPath;
	}
	
	t++;
	
        
        int currentPathweight = 0;
 
        k = x;
        char l; 
	
            cout<<""<<convertArray(k);// ekrana baslangic dugumu 'A' yi yazdirir
        	charDizi[t0]=convertArray(k);
        	t0++;
        	
        for (int i = 0; i < vertex.size(); i++) 
		{
            
        	pathArray[i]=graph[k][vertex[i]];// yollarý ayri ayri ekrana basar
            currentPathweight += graph[k][vertex[i]];
            k = vertex[i];
             
            // path teki dugumleri harf seklinde yazdirir
            cout<<" -> "<<convertArray(k);
            charDizi[t0]=convertArray(k);
            t0++;
           
        } 
            // path in sonuna 'A' yazdirir
            cout<<" -> "<<convertArray(0)<<"  "; 
           	charDizi[t0]=convertArray(0);
        	t0++; 
        	cout<<"	  ";
            
            for(int i=0;i<n-1;i++)
			{
			    // yollarin maliyetlerini sirayla ekrana basar
            	cout<<pathArray[i]<<"+";
			}
		
        currentPathweight += graph[k][x];
        cout<<graph[k][x];// yollari ayri ayri yazdiri
        cout<<" = "<<currentPathweight<<"\n"; //yollarin maliyetleri toplamini bastirir
        
 	     dizi[t1]=currentPathweight;
 	     t1++;
        
        minPath = min(minPath, currentPathweight);
        minP=minPath;
        
        
 		
    } while (next_permutation(vertex.begin(), vertex.end()));
    
    return minPath;
}


  void findMinPath(int n,int E,char charDizi[V] ,int dizi[V], int minP){
  		cout<<"Gezilebilecek olasi en kisa yollar:"<<"\n\n";
  		for(int i=0;i<=E;i++){
			
    			if(minP==dizi[i]){
    		
    		
    			for(int j=i*(n+1);j<(i*(n+1))+n;j++){
    				
    			 cout<<""<<charDizi[j]<<" -> ";
    			
			}
			cout<<""<<charDizi[0]<<"\n";
    		
		}
    	
	}
 			
  }

int main()
{

    srand(time(NULL)); 
    int graph[100][100];      
    int nodeNumber;
    int x = 0;
    int e;
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"Travelling Salesman Problemi icin 3 ve 100 arasinda bir N degeri giriniz:"<<endl; //n dugum alma
    cout<<"=> ";
    cin>>nodeNumber;
    if(nodeNumber>=3 && nodeNumber<=100)
    {
    graph[nodeNumber][nodeNumber];
        cout<<"-------------------------------------------------------------------------\n\n";

    cout<<"Degerleri rastgele olusturulan komsuluk matrisi:\n";
    printMatrix(nodeNumber,graph);
    e=rand() %((nodeNumber*(nodeNumber-1)/2)+1-nodeNumber)+nodeNumber;
    cout<<"-------------------------------------------------------------------------\n\n";

    cout << "Rastgele atanan E degeri: "<<e<< endl; //E: baglanti sayisi icin random deger atama
    cout<<"-------------------------------------------------------------------------\n\n";
    cout <<"Travelling Salesman Problemi icin Hesaplanan Optimal Path => "<<tsp(graph, x,nodeNumber,e) << endl;
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"\n\n";
    findMinPath(nodeNumber,e,charDizi,dizi,minP);
    cout<<"\n";
	}
    
    else if(nodeNumber<3)
    {
    	cout<<"3 ten kucuk bir deger girdiniz! Yeniden deneyiniz."<<endl;
	}
	else if(nodeNumber>100)
    {
    	cout<<"100 den buyuk bir deger girdiniz! Yeniden deneyiniz."<<endl;
	}

    
   
    return 0;
}

