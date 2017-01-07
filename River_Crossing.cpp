/*Contract : the code should return true or false regarding whether the person can cross the river */
/*Purpose : the code take a string of asterisk with gaps and return whether such a pattern of stones can help a person cross the river*/
/* Approach Used: Dynamic Programming */
/* time complexity of the approach is O(n^2)*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

int canCrossRiver(int array[], int stones)
{
	int i=0,j=0;

    /*Vague case*/
    if (stones==0)
    	return 0;

	int jumps=sqrt(2*stones); // number of jumps the person will take for crossing the river
	
	int **reachability=(int **)malloc(stones * sizeof(int *));
	for(i=0;i<stones;i++)
	{
		reachability[i]=(int *)malloc(jumps * sizeof(int));
		for(j=0;j<jumps;j++)
		{  
               reachability[i][j]=0;
		}
	}

	for(j=0;j<=jumps;j++)
	{
		reachability[0][j]=0;
	}
	for(i=1;i<stones;i++)
	{
		reachability[i][0]=0;
	}
	
	reachability[0][1] = array[0];
	/* dynamic programming structure */
	for(i=1;i<stones;i++)
	{
     for(j=1;j<=jumps;j++)
     {
     	if((array[i]==1) && (i>=j))
     	{
     		if(reachability[i-j][j]==1)
     		{
     			reachability[i][j]=1;
     		}
     		else if ((j+1 < jumps) && (reachability[i-j][j+1]==1))
     		{
     			reachability[i][j]=1;
     		}
     		else if ((reachability[i-j][j-1]==1) && j>0)
     		{
     			reachability[i][j]=1;
     		}
     	}
     	if((i+j+1 >= stones) && (reachability[i][j]==1))
     	{
     		return 1;
     	}
     }
	}
	return 0;
}


int main()
{
	/* for simplicity I have converted '*' to 1 and ' ' to 0*/
	string str="***  *      *   *";
	int len=str.size();
    int *arr = (int *)malloc(len * sizeof(int));
    int i=0;
    for(i=0;i<len;i
    {
      if (str[i] == '*')
      	   arr[i] = 1;
      else
      	   arr[i] = 0;
    }    	
	//int arr[]={1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1};
	int NoOfStones=sizeof(arr)/sizeof(arr[0]);

	if(canCrossRiver(arr,NoOfStones) == 1)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
return 0;
}