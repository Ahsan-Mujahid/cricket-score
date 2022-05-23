#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void swap_player(string &,string &);
bool is_odd(int);
float run_rate(float total_score,float overs);
float req_runrate(float overs_left,float req_score);
int main()
{

	float overs;
	int players;
		cout <<"\t\t\t\t---------------------------------------" << endl;
    cout << "\t\t\t\t|============== CRIC-IN ==============|" << endl;
    cout << "\t\t\t\t|                                     |" << endl;
    cout << "\t\t\t\t|     Welcome to the live Cricket     |" << endl;
    cout << "\t\t\t\t---------------------------------------" << endl;
    cout << endl << endl;
    cout << "\t\t\t----------------------------------------------------" << endl;
    cout << "\t\t\t|================== Instructions ==================|" << endl;
    cout << "\t\t\t----------------------------------------------------" << endl;
    cout << "\t\t\t|                                                  |" << endl;
    cout << "\t\t\t| 1. Create 2 teams (Team-A and Team-B players)    |" << endl;
    cout << "\t\t\t| 2. Lead the toss and decide the choice of play.  |" << endl;
    cout << "\t\t\t| 3. Each innings will be of 6 balls.              |" << endl;
    cout << "\t\t\t----------------------------------------------------" << endl<<endl;
	cout<<"\tEnter number of players: ";
	cin>>players;
	string team1[players];
	string team2[players];
	string out[players]={""};
	int p_score[players]={0};
	int b_wickets[players]={0};
	int p_bowls[players]={0};
	int b_balls[players]={0};
	int b_score[players]={0};
	int target=0;
	cout<<"\n\tEnter number of overs: ";
	cin>>overs;
	cout << "\n\n\t------------------------------------------------" << endl;
	cout << "\t|========== Create Team-A and Team-B ==========|" << endl;
	cout << "\t------------------------------------------------" << endl;
	cout<<"\n\tEnter name of first team:  ";
	string team_one;
	cin>>team_one;
	cout<<"\n\tEnter name of Second team: ";
	string team_two;
	cin>>team_two;
	cout<<"\nEnter players of team "<<team_one<<endl;
	string name;

	for(int i=0;i<players;i++)
	{
		cin>>name;
		team1[i]=name;
	}
	cout<<"\nEnter players of team: "<<team_two<<endl;
	for(int i=0;i<players;i++)
	{
		cin>>name;
		team2[i]=name;
	}
	cout<<endl;
    cout << "\t-----------------------------------" << endl;
	cout << "\t|========== Let's Toss  ==========|" << endl;
	cout << "\t-----------------------------------" << endl;

	cout<<"\tWhich team won the toss? [1 or 2]: ";
	int choice1;
	int choice2;
	cin>>choice1;

	if(choice1==1)
	{
		cout<<"\tTeam  "<<team_one<<" won the toss "<<endl;
		cout<<"\tbat or bowl [1 or 2] :";
		int choice2;
		cin>>choice2;
		if(choice2==1)
		{
	cout<<endl<<"\t"<<team_one<<"Decided to bat first"<<endl;
	cout<<team_one<<"     "<< team_two<<endl;
	for (int i=0;i<players;i++)
	{
		cout<<i<<"-"<<team1[i];
		cout<<"            "<<i<<"-"<<team2[i]<<endl;
	}
	string striker;
	string non_striker;
	string bowler1;
	bool is_bowler=false;
	bool is_striker=false;
	bool is_non_striker=false;
	
	
	do{
	
	cout<<"\nFrom these list select openers select striker and non-striker for team "<<team_one<<" And bowlers for team "<<team_two<<endl;
	
	cout<<"ATTENTION ! If you type wrong name, the program will prompt you to type the correct one."<<endl;
	cout<<"\n\n\tSelect striker from batting team: ";
	cin>>striker;
	cout<<"\n\tSelect non_striker from batting team: ";
	cin>>non_striker;
	cout<<"\n\tSelect bowler form bowling team: ";
	cin>>bowler1;
	
	
	
	for (int k=0;k<players;k++)
	{
		if(bowler1==team2[k])
		{
			is_bowler=true;
		}	
	
		if(striker==team1[k])
		{
			is_striker=true;
		}
	
		if(non_striker==team1[k])
		{
			is_non_striker=true;
		}
	
	}	
}while(!(is_bowler&&is_striker&&is_non_striker));
	int total_score=0;
	int score=0;
	int wickets=0;
	int choice3;
	int index;
	int index_b;
	int bowls=0;
	for( int i=0;i<overs;i++)
	{
	for (int j=1;j<7;j++)
	{
		
	    cout<<"\nEnter 0-6 for score and 7 for NO Ball, 8 for Wicket, 9 for Wide"<<endl;
		cin>>choice3;

		switch(choice3)
		{
            
		
		
			case 0:
				{
            	cout<<endl<<"Dot Ball"<<endl;
            	cout<<endl<<"Total score: "<<total_score<<endl;
				for(int k=0;k<players;k++)
				{
					
					if(striker==team1[k])
					{
						
						p_bowls[k]++;
						index=k;
					}
					if(bowler1==team2[k])
					{
						index_b=k;
					}
					
				}
					b_balls[index_b]++;
					cout<<"\nscore of "<<striker<<" :"<<p_score[index]<<endl; 
					cout<<"balls played by "<<striker<<" :"<<p_bowls[index]<<endl; 
            		cout<<"overs="<<i<<"-"<<j<<endl;
            		cout<<"bowler wickets: "<<b_wickets[index_b]<<endl<<" bowler run "<<b_score[index_b]<<endl;
            		cout<<"balls by bowler "<<b_balls[index_b]<<endl;
            		break;}
            	
			case 1:{
			    total_score++;
				cout<<endl<<"\t\t||--total score: "<<total_score<<"--||"<<endl;
				for(int k=0;k<players;k++)
				{
					
					if(striker==team1[k])
					{
						p_score[k]++;
						p_bowls[k]++;
						index=k;
					}
					if(bowler1==team2[k])
					{
						b_score[k]++;
						index_b=k;
					}
				}
				b_balls[index_b]++;
					cout<<endl<<"striker:"<<striker<<"  score "<<p_score[index]<<endl;
					cout<<"balls played by "<<striker<<" :"<<p_bowls[index]<<endl; 
				swap_player(striker,non_striker);
					cout<<"bowler wickets="<<b_wickets[index_b]<<endl<<" bowler run "<<b_score[index_b]<<endl;
					cout<<"balls by bowler "<<b_balls[index_b]<<endl;
					cout<<"overs="<<i<<"-"<<j<<endl;
				break;}
			case 2:{
			
				total_score=total_score+2;
			  	cout<<endl<<"\t\t||--total score: "<<total_score<<"--||"<<endl;
				for(int k=0;k<players;k++)
				{
					if(striker==team1[k])
					{
						p_score[k]=p_score[k]+2;
						
						p_bowls[k]++;
						index=k;
					}
					if(bowler1==team2[k])
					{
						b_score[k]=b_score[k]+2;
						index_b=k;
					}
					
				}
				b_balls[index_b]++;
			cout<<endl<<"striker:"<<striker<<"  Score "<<p_score[index]<<endl;
			cout<<"balls played by "<<striker<<" :"<<p_bowls[index]<<endl;
			cout<<"bowler wickets:"<<b_wickets[index_b]<<endl<<" bowler run "<<b_score[index_b]<<endl; 
			cout<<"balls by bowler "<<b_balls[index_b]<<endl;
			cout<<"overs="<<i<<"-"<<j<<endl;
					
				break;}
			case 3:{
				
				total_score=total_score+3;	
				
				cout<<endl<<"\t\t||--total score: "<<total_score<<"--||"<<endl;
				for(int k=0;k<players;k++)
				{
					if(striker==team1[k])
					{
						p_score[k]=p_score[k]+3;
						
						index=k;
						p_bowls[k]++;
					}
					if(bowler1==team2[k])
					{
						b_score[k]=b_score[k]+3;
						index_b=k;
					}	
				}
				b_balls[index_b]++;
			    cout<<endl<<"striker:"<<striker<<"  Score "<<p_score[index]<<endl;
			    cout<<"balls played by "<<striker<<" :"<<p_bowls[index]<<endl; 
				cout<<endl<<"overs: "<<i<<"-"<<j<<endl;
					cout<<"bowler wickets:"<<b_wickets[index_b]<<endl<<" bowler run "<<b_score[index_b]<<endl;
					cout<<"balls by bowler "<<b_balls[index_b]<<endl;
				swap_player(striker,non_striker);
				break;
			}
			case 4:
				{
				total_score=total_score+4;	
				cout<<endl<<"\t\t||--total score: "<<total_score<<"--||"<<endl;
				for(int k=0;k<players;k++)
				{
					if(striker==team1[k])
					{
						p_score[k]=p_score[k]+4;
						
						index=k;
						p_bowls[k]++;
					}
					if(bowler1==team2[k])
					{
						b_score[k]=b_score[k]+4;
						index_b=k;
					}
				}
				b_balls[index_b]++;
			    cout<<endl<<"striker:"<<striker<<"  Score "<<p_score[index]<<endl;
			    cout<<"balls played by "<<striker<<" :"<<p_bowls[index]<<endl; 
			    	cout<<"bowler wickets:"<<b_wickets[index_b]<<endl<<" bowler run "<<b_score[index_b]<<endl;
			    	cout<<"balls by bowler "<<b_balls[index_b]<<endl;
				cout<<"overs="<<i<<"-"<<j;
			break;}
			case 5:
					{
					total_score=total_score+5;	
				cout<<endl<<"\t\t||--total score: "<<total_score<<"--||"<<endl;
				for(int k=0;k<players;k++)
				{
					if(striker==team1[k])
					{
						p_score[k]=p_score[k]+5;
						
						index=k;
						p_bowls[k]++;
					}
					if(bowler1==team2[k])
					{
						b_score[k]=b_score[k]+5;
						index_b=k;
					}
				}
				b_balls[index_b]++;
			    cout<<endl<<"striker:"<<striker<<"  Score "<<p_score[index]<<endl;
			    cout<<"balls played by "<<striker<<" :"<<p_bowls[index]<<endl; 
			    	cout<<"bowler wickets="<<b_wickets[index_b]<<endl<<" bowler run "<<b_score[index_b]<<endl;
			    	cout<<"balls by bowler "<<b_balls[index_b]<<endl;
				swap_player(striker,non_striker);
					cout<<endl<<"overs:"<<i<<"-"<<j;
			break;}
			case 6:
				{
						total_score=total_score+6;	
				cout<<endl<<"\t\t||--total score: "<<total_score<<"--||"<<endl;
				for(int k=0;k<players;k++)
				{
					if(striker==team1[k])
					{
						p_score[k]=p_score[k]+6;
						score=0;
						index=k;
						p_bowls[k]++;
					}
					if(bowler1==team2[k])
					{
						b_score[k]=b_score[k]+6;
						index_b=k;
					}
				}
					b_balls[index_b]++;
					cout<<endl<<"striker= "<<striker<<"score "<<p_score[index]<<endl;
					cout<<"balls played by "<<striker<<" :"<<p_bowls[index]<<endl; 
						cout<<"bowler wickets="<<b_wickets[index_b]<<endl<<" bowler run "<<b_score[index_b]<<endl;
						cout<<"balls by bowler "<<b_balls[index_b]<<endl;
					cout<<endl<<"overs="<<i<<"-"<<j;
					break;}
			case 7:
				{
				cout<<"no ball\n";
				++total_score;
				cout<<endl<<"Enter 0-6 for score on no ball"<<endl;
				
				int temp_score;
				cin>>temp_score;
				
				total_score=total_score+temp_score;
					for(int k=0;k<players;k++)
				{
					if(striker==team1[k])
					{
						p_score[k]=p_score[k]+temp_score;
					
						index=k;
						p_bowls[k]++;
					}
					if(bowler1==team2[k])
					{
						b_score[k]+temp_score+1;
						index_b=k;
					
					}
				}
				cout<<endl<<"\t\t||--total score: "<<total_score<<"--||"<<endl;
				cout<<endl<<"striker= "<<striker<<" score "<<p_score[index]<<endl;
				cout<<"bowler wickets="<<b_wickets[index_b]<<endl<<" bowler run "<<b_score[index_b]<<endl;
				j--;
				if (is_odd(temp_score))
				{
					swap_player(striker,non_striker);
				}
					cout<<endl<<"overs="<<i<<"-"<<j;
				break;}
			case 8:
				{
				cout<<"Wicket"<<endl;
			
						for (int k=0;k<players;k++)
					{
					if(striker==team1[k])
					{
						p_score[k]=p_score[k]+score;
						
						p_bowls[k]++;
						index=k;
					}
					if(bowler1==team2[k])
					{
						b_wickets[k]++;
						b_balls[k]++;
						index_b=k;
					}
					}
					float strike_rate;
					strike_rate=((p_score[index])/(p_bowls[index]))*100;
					cout<<"Score of   "<<striker<<" :"<<p_score[index]<<endl;
					cout<<"balls played by"<<striker<<" :"<<p_bowls[index]<<endl;
					cout<<"strike rate:"<<strike_rate<<endl;
					cout<<"bowler wickets "<<b_wickets[index_b]<<endl<<" bowler run "<<b_score[index_b]<<endl;
					cout<<"balls by bowler "<<b_balls[index_b]<<endl;
					int index_o;
					string new_batsman;
					bool is_out=false;
					for (int k=0;k<players;k++)
						{
							if(striker==out[k])
							{
								is_out=true;
							}
					    }
							do
							{
								for (int k=0;k<players;k++)
								{
									cout<<k<<" :"<<team1[k]<<endl;
									if(striker==team1[k])
									{
										out[k]=striker;
										index_o=k;
									}
									cout<<"Enter next batsman from the list"<<endl;
									cout<<"ATTENTION ! if you enter the current non_striker or already OUT players then the program will prompt you to take input again";
									cin>>new_batsman;
								}
							}while(new_batsman==non_striker&&new_batsman==out[index_o]&&is_out);
					swap_player(striker,new_batsman);
				break;
			}
			case 9:{
			    int choice4;
			    int temp_score;
				cout<<"Wide ball";
				total_score=++total_score;
				for(int k=0;k<players;k++)
				{
					if(bowler1==team2[k])
					{
						index_b=k;
					}
				}
				b_score[index_b]++;
				cout<<endl<<"Enter 1 if it was bye"<<endl;
				cin>>choice4;
				if (choice4==1)
				{
					cout<<"enter 0-4 for bye score";
					cin>>temp_score;
					total_score=total_score+temp_score;
				}
			    for (int k=0;k<players;k++)
					{
					if(striker==team1[k])
					{
						index=k;
					}
					if(bowler1==team2[k])
					{
						index_b=k;
					}
					}
					cout<<endl<<"\t\t**||total score: "<<total_score<<"||**"<<endl;
					cout<<"Score of   "<<striker<<" :"<<p_score[index]<<endl;
					cout<<"balls played by"<<striker<<" :"<<p_bowls[index]<<endl;
					cout<<"bowler wickets "<<b_wickets[index_b]<<endl<<" bowler run "<<b_score[index_b]<<endl;
					cout<<"balls by bowler "<<b_balls[index_b]<<endl;
				    cout<<endl<<" total score "<<total_score<<endl;
				    j--;
					cout<<endl<<"overs="<<i<<"-"<<j;
				break;	}
            	default:{
            	cout<<"default";
            	break;}	
	}
}       
        cout<<"run rate="<<run_rate(total_score,overs);
        swap_player(striker,non_striker);
        cout<<endl<<endl<<"Next Over"<<endl<<endl;
		for (int k=0;k<players;k++)
	{
		if(bowler1!=team2[k])
		{cout<<k<<"-"<<team2[k]<<endl;}
	}
	b_balls[index_b]=b_balls[index_b]+6;
	cout<<endl<<"select new bowler from given list "<<endl;
	cin>>bowler1;
	cout<<bowler1<<" is now the bowler"<<endl;
}
	/*int p_score[players]={0};
	int b_wickets[players]={0};
	int p_bowls[players]={0};
	int b_balls[players]={0};
	int b_score[players]={0};*/
	cout<<"     scorecard"<<endl;
	fflush(stdout);
	cout<<"total score="<<total_score<<endl<<"overs="<<overs<<endl<<team_one<<"\t\truns scored \t\tballs played\t\tstrike rate"<<"\t\t"<<team_two<<"\t\tRuns conceded\t\tBalls bowled\t\tWickets taken"<<endl;
	float strike_rate;
	for (int k=0;k<players;k++)
	{
		cout<<k<<" :"<<team1[k]<<"\t\t";
		cout<<k<<" :"<<p_score[k]<<"\t\t\t";
		cout<<k<<" :"<<p_bowls[k]<<"\t\t\t";
		strike_rate=((p_score[k])/(p_bowls[k]))*100;
		cout<<k<<" :"<<strike_rate<<"\t\t";
		cout<<k<<" :"<<team2[k]<<"\t\t";
		cout<<k<<" :"<<b_score[k]<<"\t\t\t";
		cout<<k<<" :"<<b_balls[k]<<"\t\t\t";
		cout<<k<<" :"<<b_wickets[k]<<endl;
	}
	/*fflush(stdout);
	cout<<team_two<<"\t\tRuns conceded \t\tBalls bowled\t\tWickets taken"<<endl;
	for (int k=0;k<players;k++)
	{
		cout<<k<<" :"<<team2[k]<<"\t\t";
		cout<<k<<" :"<<b_score[k]<<"\t\t\t";
		cout<<k<<" :"<<b_balls[k]<<"\t\t\t";
		cout<<k<<" :"<<b_wickets[k]<<endl;
	}*/
}
else if(choice2==2){
cout<<team_one<<"Decided to bowl first";
}
else
{
cout<<"Team"<<team_two<<"won the toss";
cout<<"bat or bowl [1 or 2]";
int choice2;
cin>>choice2;
if(choice2==1)
{
cout<<team_one<<"Decided to bat first";
}
else if(choice2==2)
{
cout<<team_one<<"Decided to bowl first";
}
}
}
}
void swap_player(string &striker,string &non_striker)
{
	string temp=non_striker;
	non_striker=striker;
	striker=temp;
}
bool is_odd(int num)
{
	if (num%2==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
float run_rate(float total_score,float overs)
{ 
     float runrate=total_score/overs;
    return runrate;
}
 float req_runrate(float overs_left,float req_score)
 {
 	float reqrunrate=req_score/overs_left;
 	return reqrunrate;
 }  
