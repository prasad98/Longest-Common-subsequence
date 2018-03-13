#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
void lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
 
    for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   // Following code is used to print LCS
   int index = L[m][n];
 
   char lcs[index+1];
   lcs[index] = '\0';
 
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
   	
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; 
          i--; j--; index--;     
      }
    else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
 
   cout << lcs;
}

int main()
{
	freopen("inp.txt","r",stdin);           //put ur input here with space seperated 
	freopen("out.txt","w+",stdout);          // u will get output here 
	int i;
	
	 char X[100] ;
  char Y[100] ;
	for(i=0;i<14;i++){                         // Place ur 19 here after typing ur input 
		scanf("%s %s",X,Y);
 		 int m = strlen(X);
 	 	 int n = strlen(Y);
 		 lcs(X, Y, m, n);cout <<"\n";
	}
  return 0;
}
