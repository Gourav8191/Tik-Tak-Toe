#include<iostream>
using namespace std;
	//Different variable used in program
	char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	int choice;
	char turn='X';
	int row,column;
	bool draw=false;
// function used to display the board
void display()
	{
		system("cls");
		cout<<"\n\t\tTIK TAK TOE"<<endl;
		cout<<"\n\nSymbols of players\nPlayer 1[X]\nPlayer 2[O]\n\t"<<endl;
		cout<<"\t\t     |     |     \n";
		cout<<"\t\t  "<<a[0][0]<<"  |  "<<a[0][1]<<"  |  "<<a[0][2]<<"   \n";
		cout<<"\t\t_____|_____|_____\n";
		cout<<"\t\t     |     |     \n";
		cout<<"\t\t  "<<a[1][0]<<"  |   "<<a[1][1]<<" |   "<<a[1][2]<<"  \n";
		cout<<"\t\t_____|_____|_____\n";
		cout<<"\t\t     |     |     \n";
		cout<<"\t\t  "<<a[2][0]<<"  |  "<<a[2][1]<<"  |   "<<a[2][2]<<"  \n";
		cout<<"\t\t     |     |     \n";


	}
// function tells about players turn and input 
void playerx()
{
	if(turn=='X')
		cout<<"\n\tPlayer 1[X] turn:";
	if(turn=='O')
		cout<<"\n\tPlayer 2[O] turn:";
	cin>>choice;
	switch(choice)
	{
		case 1:
				row =0; column=0;
				break;
		case 2:
				row =0; column=1;
				break;
		case 3:
				row =0; column=2;
				break;
		case 4:
				row =1; column=0;
				break;
		case 5:
				row =1; column=1;
				break;
		case 6:
				row =1; column=2;
				break;
		case 7:
				row =2; column=0;
				break;
		case 8:
				row =2; column=1;
				break;
		case 9:
				row =2; column=2;
				break;		
		default:cout<<"invalid choice";
				break;
	}
	if(turn=='X' && a[row][column]!='X' &&a[row][column]!='O')
	{
		a[row][column]='X';
		turn='O';
	}
	else if(turn=='O' && a[row][column]!='X' &&a[row][column]!='O')
	{
		a[row][column]='O';
		turn='X';
	}
	 else
	{
	 	cout<<"Box Already Filled\n Please Try Again\n\n";
	 	playerx();
	}
}
bool gameover()
{	
	//winning case
	for(int i=0;i<3;i++)
	if(a[i][0]==a[i][1] && a[i][0]==a[i][2] || a[i][0]==a[0][i] && a[1][i]==a[2][i])
	return false;
	if(a[0][0]==a[1][1] && a[0][0]==a[2][2] && a[0][2]==a[1][1] && a[0][2]==a[2][0])
	return false;
	
	//checking whether the game is still going-on
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
		if(a[i][j]!='X'&&a[i][j]!='O')
	return true;
	
	//in ase of draw
	draw=true;
	return false;
}
main()
{
	while(gameover())
	{
		display();
		playerx();
		//redisplaying the board so that updated value in board will be displayed
		display();
		gameover();
	}
	if(turn=='X' && draw==false)
	cout<<"\nPlayer2 [O] WINS!!!\n";
	else if(turn=='O' && draw==false)
	cout<<"\nPlayer1 [X] WINS!!!\n";
	else
	cout<<"\t\tGAME DRAW!!\n";
}
