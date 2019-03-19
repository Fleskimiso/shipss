#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <windows.h>
using namespace std;
   int mine[10][10][2]; //param last index in table  0-mine 1-enemy
   int presentation[10][10][2];
int main()
{
	srand(time(0));
   
   	 for(int i=0; i<2; i++) // initilization
   {
   	int losowanie =0;
   	while(losowanie < 10)
	{
		int x= rand()%10;
   	 int  y= rand()&10;
   	  if(mine[x][y][i] == 1)
	  {
	  	continue;
	  }
	  else 
	  {
	  	mine[x][y][i] = 1;
	  	losowanie++;
	  }
	}
   }
   
   
   
   int tura=0;
   bool isgamerunnning = true;
   string message;
   int tile[2];
   while(isgamerunnning)
   {
		cout << "Message from last turn: " + message << endl; 
		cout << " Plansza Dawida: 	 Plansza przeciwnia:" << endl;
		for(int i=0; i<10; i++)
		{
			if( i==0)
			{
				cout << "  ";
				for(int tables =0 ;tables<2; tables++)
				{
					for(int lic = 0; lic< 10; lic++)
					{
						cout << " " << lic;
					}
					cout  << "    ";
				}
				cout << endl;
			}
			cout << i << ".";
			for(int second=0 ; second < 10; second++)
			{
				cout << " " << presentation[second][i][0];
			}
			cout <<" " << i << ". ";
			for(int second=0 ; second < 10; second++)
			{
				cout << " " << presentation[second][i][1];
			}
			cout << endl;
		}
		
		if(tura == 0)
		{
			cout << "Dawid turn. Type position to shot: " << endl;
			cin >> tile[0] >> tile[1];
			tura = 1;
			
			mine[tile[0]][tile[1]][0] = 8;
			presentation[tile[0]][tile[1]][tura] +=1; 
			if(mine[tile[0]][tile[1]][0]  == 1)
			{
				message = "congrats you have shooted a ship";
				mine[tile[0]][tile[1]][0]  = -1;
			}
			else
			{
				message = "David has missed";
			}
		}
		else if(tura ==1)
		{
			cout << "Enemy turn. Type position to shot: " << endl;
			cin >> tile[0] >> tile[1];
			tura = 0;
			presentation[tile[0]][tile[1]][tura] +=1; 
			if(mine[tile[0]][tile[1]][1]  == 1)
			{
				message = "congrats you have shooted a ship";
				mine[tile[0]][tile[1]][1]  =-1;
			}
			else
			{
				message = "Enemy has missed";
			}
		}
		system("cls");
   }
}
