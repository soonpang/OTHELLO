/**********|**********|**********|
Program: OTHELLO.cpp 
Course: Bachelor Of Computer Science (Hons)
Year: 2015/16 Trimester 1
Name: LIEW SOON PANG
ID: 1142700808
Email: liewsoopang@gmail.com
Phone: 0111-0776470
**********|**********|**********/
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	//Int variables
	int a, b, j, k, l, o, q, r, s, u, z, Acounter, counter = 1, counter1 = 1, myfile, Oscore, Player, Wrong, Wrong1, Wrong2, Xscore,connect;
	int XG,OG,TXG,TOG,XSP1, OSP1;
	string choice = "B", CP, Order;
	char p, y;
	int turn = 1;
	char Board[9][9] = {};
	bool XNP = true, ONP = true, XTNP = false, OTNP = false;
	 	 
	//Back to the start
	while (choice == "B")
	{
		cout << "#######################################################################" << endl;
		cout << "#                            WELCOME                                  #" << endl;
		cout << "#                              TO                                     #" << endl;
		cout << "#                            OTHELLO                                  #" << endl;
		cout << "#######################################################################" << endl;
		cout << " "<<endl;	
		cout << "Please choose an option :)" << endl << endl;		
		//Menu
		cout << "1.New game" << endl;
		cout << "2.Load a game" << endl;
		cout << "3.Help" << endl;
		cout << "4.Quit" << endl << endl;
		cout << "Type your option of 1~4 ==> ";
		getline(cin, choice);			
		//New game
		if (choice == "1")
		{	         
			XG = 0;
			OG = 0;                            
			TXG = 0;
			TOG = 0;	
			XSP1 = 0;
			OSP1 = 0;
				a = 1;
				while (a < 9)
				{
					b = 1;
					while (b < 9)
					{
						Board[a][b] =' ';
						b += 1;
					}
					a += 1;
				}
			Board[4][4] = 'O';
			Board[4][5] = 'X';
			Board[5][4] = 'X';
			Board[5][5] = 'O';		
			turn = 1;
			choice = "11";
		}		
		if (choice == "2")                                       //load a past game
		{			
			ifstream myfile;
			myfile.open("a.txt");
			if (myfile.good())
			{
				a = 1;
				while (a < 9)
				{
					b = 1;
					while (b < 9)
					{
						myfile.get(Board[a][b]);
						b+=1;
					}
					a+=1;
				}				
				myfile >> turn ;
				myfile >> XSP1;
				myfile >> OSP1 ;
				myfile >> XNP ;
				myfile >> XTNP ;
				myfile >> ONP ;
				myfile >> OTNP ;
				myfile >> XG ;
				myfile >> TXG ;
				myfile >> OG ;
				myfile >> TOG ;
				choice = "11";	
			}		
			else
			{
				cout << "Error reading file. Program Exit." << endl;               //if file not found
				return - 1;
			}
		}										
		if (choice == "11")                   //actual game program
		{		
			Xscore = 0;
			Oscore = 0;			
			while (turn > 0)				//loop the game
			{
				Xscore = 0;					//Int calculate and variable score								
				Oscore = 0;
				r = 1;
				while (r < 9)            //Number of row
				{
					s = 1;
					while (s < 9)			//Number of column
					{
						if (Board[r][s] == 'O')             //Calculate number of O
						{	
							Oscore = Oscore + 1;
						}
						else if (Board[r][s] == 'X')         //Calculate number of X                           
						{
							Xscore = Xscore + 1;
						}
						s = s + 1;
					}
					r = r + 1;					
				}																			
				Player = turn % 2;                              //whose turn                 
				if (Player == 0)
				{
					CP = "O";
				}
				if (Player == 1)
				{
					CP = "X";
				}				
				Wrong = 0;
				while (Wrong == 0)
				{
					j = 1;
					k = 8;					
					while (j < 9)              // Number of row
					{
						l = 1;
						cout <<"  |";
						while (l < 9)           // Number of '---+'
						{
							if (l < 8)
							{
								cout << "---+";
								
							}
							else if ( l == 8)          //For the last column '---|'       
							{
								cout <<"---|";
							}
							
							l = l + 1;
						}
						cout << endl;						
						l = 1;						
						cout << k << " |";       //For the side of board numbering
						while (l < 9)          //Set the number of '   |'
						{
							cout << " " << Board[j][l]<< " |";
							l = l + 1;
						}							
						cout << endl;	
						j = j + 1;
						k = k - 1;						
					}
					l = 1;
					cout << "  |";
					while (l < 9)                 //For the last line of the board
					{
						if (l < 8)
						{
							cout <<"---+";
						}
						else if (l == 8)
						{
							cout <<"---|";
						}
						l = l + 1;
					}
					Wrong = 1;
				}
				cout << endl;
				cout << "   a   b   c   d   e   f   g   h"<< endl;
				cout << "Score : O = " << Oscore <<"    X = "<< Xscore << endl;
				cout << "Current Player : " << CP << endl;
				int countempty = 64;                                             //Victory part
				for(int i = 1; i < 9; i++)
				{
					for(int j = 1; j < 9; j++)
					{
						if(Board[i][j] !=' ' )
						{
							countempty--;
						}
					}
				}
				if(countempty == 0) 
				{
					if ( Xscore > Oscore )
					{
						cout << "Congratulations!!! ";
						cout << "X is the winner of the game!!" << endl;
						system("pause");
						Wrong = 1;
						turn = 0;
						choice = "B";
						
					}
					else if ( Oscore > Xscore )
					{
						cout << "Congratulations!!! ";
						cout << "O is the winner of the game!!" << endl;
						system("pause");
						Wrong = 1;
						turn = 0;
						choice = "B";
					}
					else
					{
						cout << "It's a tie!!!" << endl;
						system("pause");
						Wrong = 1;
						turn = 0;
						choice = "B";
					}
				}
				cout << "         Options"                     <<endl;
				cout << "menu            super1 " << endl;
				cout << "save            super2 " << endl;    
			    cout << "next player     super3 " << endl; 				
				cout << "==> ";								
				getline (cin, Order);                              //to get users input
				connect = 1;								
				if ( Order == "next player")                       //change player
				{
					turn = turn + 1;
					Wrong = 1;
					connect = 0;
				}
			    if (Order == "save")                          //safe file
				{
					ofstream myfile;
					myfile.open ("a.txt");
					a = 1;
					while (a < 9)
					{
						b = 1;
						while (b< 9)
						{
							myfile << Board[a][b];
							b = b + 1;
						}
						a = a + 1;
					}
					myfile <<"\n"<< turn ;
					myfile <<"\n"<< XSP1;
					myfile <<"\n"<< OSP1 ;
					myfile <<"\n"<< XNP ;
					myfile <<"\n"<< XTNP ;
					myfile <<"\n"<< ONP ;
					myfile <<"\n"<< OTNP ;
					myfile <<"\n"<< XG ;
					myfile <<"\n"<< TXG ;
					myfile <<"\n"<< OG ;
					myfile <<"\n"<< TOG ;																									
					myfile.close();
					cout << "Game Saved"<<endl;
					system("pause");
					choice = "11";
					connect = 0;
				}								
				if (Order == "menu")                                  //to go back menu
				{
					choice = "B";
					turn = 0;
					Wrong = 1;		
					connect = 0;
				}				
				if (Order =="super1")                   //superpower 1 for X to change opponents marker and score to yours
				{
					if(CP == "X")
					{
						if(XSP1 ==0)
						{
							XSP1 = 1;
							r = 1;	
							while (r < 9)           
							{
								s = 1;
								while (s < 9)			
								{
									if (Board[r][s] == 'O')             
									{	
										Xscore = Xscore + 1;
										Board[r][s] = 'X';
									}
									else if (Board[r][s] == 'X')                                  
									{
										Oscore = Oscore + 1;
										Board[r][s] = 'O';
									}
									s = s + 1;
								}
								r = r + 1;					
							}
							turn = turn + 1;
						}
						else
						{
							cout <<"Power has been used" <<endl;                                   //used super1
							system("pause");
						}
					}
					if(CP == "O")                                  //superpower 1 for O to change opponents marker and score to yours
					{		
						if(OSP1==0)
						{
							OSP1 = 1;
							r = 1;
							while (r < 9)           
							{
								s= 1;
								while (s < 9)			
								{
									if (Board[r][s] == 'O')             
									{	
										Xscore = Xscore + 1;
										Board[r][s] = 'X';
									}
									else if (Board[r][s] == 'X')                                  
									{
										Oscore = Oscore + 1;
										Board[r][s] = 'O';
									}
									s= s + 1;
								}
								r = r + 1;					
							}
							turn = turn + 1;							
						}
						else
						{
							cout <<"Power has been used" <<endl;
							system("pause");
						}
					}
					connect = 0;				
				}
				if (Order == "super2")                                                       //super 2  gives you 2 turns
				{	
					if( CP == "X")
					{		
						if( XNP || XTNP )
						{
							XNP = false;
							XTNP = true;
							cout << "Please type in where you want the coordinate to be." << endl;                                  
							cout << "==> ";
							getline( cin, Order );
							connect = 1;
						}
						else
						{
							cout << "Superpower2 has been used" << endl;                                  //used super2
							system("pause");
							connect = 0;
						}
					}
					else
					{
						if( ONP || OTNP )
						{
							ONP = false;
							OTNP = true;
							cout << "Please type in where you want the coordinate to be." << endl;
							cout << "==> ";
							getline( cin, Order );
							connect = 1;
						}
						else
						{
							cout << "Superpower2 has been used" << endl;
							system("pause");
							connect = 0;
						}
					}
				}
				if(Order == "super3")                                                                        //super3 can on anywhere one time even on enemy
				{
					if ( CP == "X" )
					{
						if ( XG == 0 || TXG != 1 )
						{
							cout << "Please type which O you want to change." << endl;
							cout << "==> ";
							getline( cin, Order );
							if(Board[a][b] == 'O')
							{
								Board[a][b] == ' ';
							}
							XG = 1;
							TXG = 1;
							connect = 1;														
						}
						else
						{
							cout << "You have used up super3." << endl;                                             //used super2
							system("pause");
							connect = 0;
						}
					}
					else
					{
						if ( OG == 0 || TOG != 1 )
						{
							cout << "Please type which X you want to change." << endl;
							cout << "==> ";
							getline( cin, Order );
							
							if(Board[a][b] == 'X')
							{
								Board[a][b] == ' ';
							}
							OG= 1;
							TOG = 1;
							connect = 1;
							
						}
						else
						{
							cout << "You have used up super3." << endl;
							system("pause");
							connect = 0;
						}
					}						
				}
				if(connect == 1)
				{
					Wrong1 = 0;
					Wrong2 = 0;					                                         
					istringstream ss(Order);	
					//Separate the coordinate of user input
					p = 0;
					q = 0;
					ss >> p >> q; 
					y = 'a';										//Alphabet loop and number of loop to change alphabet
					Acounter = 1;
					b = 0;
					while (b == 0)
					{
						if (Acounter<8)
						{
							while (y < 'i')
							{
								if (y == p)
								{
									y = 'i';
									b = Acounter;                      //Change the alphabet order to numerical
									Wrong1 = 1;
								}
								else
								{
									y = y + 1;
									Acounter = Acounter + 1;
								}
							}
						}
						else
							b =1;
					}										                 
					a = 9 - q;                                           // The number is changed to match array number
					
					if (a > 0 && a < 9)                                      //Whether input is valid
					{
						Wrong2 = 1;
					}
					if (Wrong1 == 1 && Wrong2 == 1)  						//Test given input  true
					{
						if ( ( XG != 1 || TXG != 1 ) && ( OG != 1 || TOG != 1 ) )
						{
							if (Board[a][b] == 'X' || Board[a][b] == 'O')      //Testing for used coordinate
							{
								cout<<"The coordinate is used."<<endl;
								system ("pause");
								cout << endl;
							}	
							
						}																		
							turn = turn + 1;
							if (CP == "X")                               
							{
								Board[a][b] = 'X';
							}
							else
							{
								Board[a][b] = 'O';
							}
						
						Wrong = 1;
						if  (  XTNP || OTNP ) 
						{
							turn -= 1;
							XTNP = false;
							OTNP = false;																
						}
					}
					else
					{
						cout << "Please enter a proper input " << endl;
						system("pause");
						cout<<endl;
					}
					
					z = 1;
					if (CP == "X")                                                                                   
					{
						u = a-1;                                 //To check upwards
						if (u > 0)                                    
						{
							if (Board[u][b] =='O')                             
							{
								u = u-1;
								while (u > 0)
								{
									if(Board[u][b] == 'O')
									{
										u = u-1;
										z = z+1;
									}
									if (Board[u][b] ==' ')
									{
										break;
									}
									if (Board[u][b] == 'X')
									{
										while(z > 0)
										{
											u = u+1;
											z = z-1;
											Board[u][b]= 'X';
										}
										u = 0;	
									}								
								}								
							}
						}
						z = 1;
						u = a+1;                                  //To check downwards
						if (u < 9)                                  
						{
							if (Board[u][b] =='O')
							{
								u = u+1;
								while (u < 9)
								{
									if(Board[u][b] == 'O')
									{
										u = u+1;
										z = z+1;
									}
									if (Board[u][b] ==' ')
									{
										break;
									}
									if (Board[u][b] == 'X')
									{
										while(z > 0)
										{
											u = u-1;
											z = z-1;
											Board[u][b]= 'X';
										}
										u = 9;		
									}						
								}							
							}
						}
						z=1;
						u = b-1;                                  //To check left
						if (u > 0)
						{
							if (Board[a][u] =='O')
							{
								u = u-1;
								while (u > 0)
								{
									if(Board[a][u] == 'O')
									{
										u = u-1;
										z = z+1;
									}
									if (Board[a][u] ==' ')
									{
										break;
									}
									if (Board[a][u] == 'X')
									{
										while(z > 0)
										{
											u = u+1;
											z = z-1;
											Board[a][u]= 'X';
										}
										u = 0;	
									}									
								}	
							}
						}
						z=1;
						u = b+1;                          //To check right
						if (u < 9)
						{
							if (Board[a][u] =='O')
							{
								u = u+1;
								while (u < 9)
								{
									if(Board[a][u] == 'O')
									{
										u = u+1;
										z = z+1;
									}
									if (Board[a][u] ==' ')
									{
										break;
									}
									if (Board[a][u] == 'X')
									{
										while(z > 0)
										{
											u = u-1;
											z = z-1;
											Board[a][u]= 'X';
										}
										u = 9;	
									}																
								}	
							}
						}
						z=1;
						u = a-1;                                     //To check upwards and left
						o = b-1;                                        
						if (u > 0 && o > 0)                           
						{
							if (Board[u][o] =='O')
							{
								u = u-1;
								o = o-1;  
								while (u > 0 && o > 0)
								{
									if(Board[u][o] == 'O')
									{
										u = u-1;
										o = o-1; 
										z = z+1;
									}
									if (Board[u][o] ==' ')
									{
										break;
									}
									if (Board[u][o] == 'X')
									{
										while(z > 0)
										{
											u = u+1;
											o = o+1; 
											z = z-1;
											Board[u][o]= 'X';	
										}
										u = 0;	
										o = 0;
									}						
								}
							}
						}	
						z=1;
						u = a-1;                                           //To check upwards and right
						o = b+1;                                        
						if (u > 0 && o < 9)                     
						{
							if (Board[u][o] =='O')
							{
								u = u-1;
								o = o+1;  
								while (u > 0 && o < 9)
								{
									if(Board[u][o] == 'O')
									{
										u = u-1;
										o = o+1; 
										z = z+1;
									}
									if (Board[u][o] ==' ')
									{
										break;
									}
									if (Board[u][o] == 'X')
									{
										while(z > 0)
										{
											u = u+1;
											o = o-1; 
											z = z-1;
											Board[u][o]= 'X';
										}
										u = 0;	
										o = 9;
									}								
								}
							}
						}
						z=1;
						u = a+1;                                  //To check downwards and left
						o = b-1;                                        
						if (u < 9 && o > 0)                    
						{
							if (Board[u][o] =='O')
							{
								u = u+1;
								o = o-1;  
								while (u < 9 && o > 0)
								{
									if(Board[u][o] == 'O')
									{
										u = u+1;
										o = o-1; 
										z = z+1;
									}
									if (Board[u][o] ==' ')
									{
										break;
									}
									if (Board[u][o] == 'X')
									{
										while(z > 0)
										{
											u = u-1;
											o = o+1; 
											z = z-1;
											Board[u][o]= 'X';
										}
										u = 9;	
										o = 0;
									}									
								}
							}
						}
						z=1;
						u = a+1;                                     //To check downwards and right
						o = b+1;                                        
						if (u < 9 && o < 9)                               
						{
							if (Board[u][o] =='O')
							{
								u = u+1;
								o = o+1;  
								while (u < 9 && o < 9)
								{
									if(Board[u][o] == 'O')
									{
										u = u+1;
										o = o+1; 
										z = z+1;
									}
									if (Board[u][o] ==' ')
									{
										break;
									}
									if (Board[u][o] == 'X')
									{
										while(z > 0)
										{
											u = u-1;
											o = o-1; 
											z = z-1;
											Board[u][o]= 'X';
										}
										u = 9;	
										o = 9;
									}									
								}
							}
						}												
					}
					z = 1;
					if (CP == "O")                                           //For O flipping      
					{
						u = a-1;                                             //To check upwards
						if (u > 0)
						{
							if (Board[u][s] =='X')
							{
								u = u-1;
								while (u > 0)
								{
									if(Board[u][b] == 'X')
									{
										u = u-1;
										z = z+1;
									}
									if (Board[u][b] ==' ')
									{
										break;
									}
									if (Board[u][b] == 'O')
									{
										while(z > 0)
										{
											u = u+1;
											z = z-1;
											Board[u][b]= 'O';
										}
										u = 0;	
									}										
								}								
							}
						}
						z = 1;
						u = a+1;                                                       //To check downwards
						if (u < 9)
						{
							if (Board[u][b] =='X')
							{
								u = u+1;
								while (u < 9)
								{
									if(Board[u][b] == 'X')
									{
										u = u+1;
										z = z+1;
									}
									if (Board[u][b] ==' ')
									{
										break;
									}
									if (Board[u][b] == 'O')
									{
										while(z > 0)
										{
											u = u-1;
											z = z-1;
											Board[u][s]= 'O';
										}
										u = 9;	
									}													
								}							
							}
						}
						z=1;
						u = b-1;                                               //To check left
						if (u > 0)
						{
							if (Board[a][u] =='X')
							{
								u = u-1;
								while (u > 0)
								{
									if(Board[a][u] == 'X')
									{
										u = u-1;
										z = z+1;
									}
									if (Board[a][u] ==' ')
									{
										break;
									}
									if (Board[a][u] == 'O')
									{
										while(z > 0)
										{
											u = u+1;
											z = z-1;
											Board[a][u]= 'O';
										}
										u = 0;	
									}															
								}	
							}
						}
						z=1;
						u = b+1;                                                     //To check right
						if (u < 9)
						{
							if (Board[a][u] =='X')
							{
								u = u+1;
								while (u < 9)
								{
									if(Board[a][u] == 'X')
									{
										u = u+1;
										z = z+1;
									}
									if (Board[a][u] ==' ')
									{
										break;
									}
									if (Board[a][u] == 'O')
									{
										while(z > 0)
										{
											u = u-1;
											z = z-1;
											Board[a][u]= 'O';
										}
										u = 9;		
									}							
								}	
							}
						}
						z=1;
						u = a-1;                                          //To check upwards and left
						o = b-1;                                        
						if (u > 0 && o > 0)
						{
							if (Board[u][o] =='X')
							{
								u = u-1;
								o = o-1;  
								while (u > 0 && o > 0)
								{
									if(Board[u][o] == 'X')
									{
										u = u-1;
										o = o-1; 
										z = z+1;
									}
									else if (Board[u][o] ==' ')
									{
										break;
									}
									else if (Board[u][o] == 'O')
									{
										while(z > 0)
										{
											u = u+1;
											o = o+1; 
											z = z-1;
											Board[u][o]= 'O';											
										}
										u = 0;	
										o = 0;
									}									
								}
							}
						}	
						z=1;
						u = a-1;                                         //To check upwards and right
						o = b+1;                                        
						if (u > 0 && o < 9)                                     
						{
							if (Board[u][o] =='X')
							{
								u = u-1;
								o = o+1;  
								while (u > 0 && o < 9)
								{
									if(Board[u][o] == 'X')
									{
										u = u-1;
										o = o+1; 
										z = z+1;
									}
									else if (Board[u][o] ==' ')
									{
										break;
									}
									else if (Board[u][o] == 'O')
									{
										while(z > 0)
										{
											u = u+1;
											o = o-1; 
											z = z-1;
											Board[u][o]= 'O';
										}
										u = 0;	
										o = 9;
									}								
								}
							}
						}
						z=1;
						u = a+1;                                  //To check downwards and left
						o = b-1;                                        
						if (u < 9 && o > 0)                  
						{
							if (Board[u][o] =='X')
							{
								u = u+1;
								o = o-1;  
								while (u < 9 && o > 0)
								{
									if(Board[u][o] == 'X')
									{
										u = u+1;
										o = o-1; 
										z = z+1;
									}
									if (Board[u][o] ==' ')
									{
										break;
									}
									if (Board[u][o] == 'O')
									{
										while(z > 0)
										{
											u = u-1;
											o = o+1; 
											z = z-1;
											Board[u][o]= 'O';
										}
										u = 9;	
										o = 0;
									}								
								}
							}
						}
						z=1;
						u = a+1;                                      //To check downwards and right
						o = b+1;                                        
						if (u < 9 && o < 9)
						{
							if (Board[u][o] =='X')
							{
								u = u+1;
								o = o+1;  
								while (u < 9 && o < 9)
								{
									if(Board[u][o] == 'X')
									{
										u = u+1;
										o = o+1; 
										z = z+1;
										
									}
									if (Board[u][o] ==' ')
									{
										break;
									}
									if (Board[u][o] == 'O')
									{
										while(z > 0)
										{
											u = u-1;
											o = o-1; 
											z = z-1;
											Board[u][o]= 'O';
										}
										u = 9;	
										o = 9;
									}	
								}
							}
						}
					}
				}
			}
		}
		
		if (choice == "3")                       //Game rules
		{
			cout << "GAME RULES" << endl;
			cout <<                                        "Basics" << endl;
			cout << "1.To play this game you must have two people on an 8 by 8 square board." << endl;
			cout << "2.The main idea is to put the pieces on the board in order to trap the" << endl;
			cout<<	"  enemy's pieces in middle of yours and change them into your own side." << endl;
			cout << "3.Each piece has X  and O on the other, with a side given to each player." << endl;
			cout << "4.The game starts with two pieces of X and O on the board." << endl;
			cout << "5.Players must take turns to try and capture their opponents pieces." << endl;
			cout << "6.If the player cannot place a piece, it will trap and flip any of the" << endl;
			cout <<	"  enemy's pieces, it counts the turn as a pass." << endl;
			cout << "7.When there's no more moves left, the player who has the most pieces" << endl;
			cout <<	"  with his or her colour wins." << endl;
			cout << "            Extra!" <<endl;
			cout << " Type menu in-order for you to go back menu when your inside a game." <<endl;
			cout << " You can save the game by typing save" <<endl;
			cout << " You can give your turn to the opponent by typing next player." <<endl;
			cout << "          Powers!!!(can be used only once)" <<endl;
			cout << " Type super1 to flip your markers and scores with the enemy." <<endl;
			cout << " Type super2 to give yourself 2 turns." <<endl;
			cout << " Type super3 to place your marker anywhere for one time." <<endl;
			system("pause");
			choice = "B";			
		}
		cout<<endl << endl;
		
		if (choice == "4")         //Quit          
		{
			return 0;				
		}
		else
		{
			cout << "Please type 1 ~ 4 only" << endl;
			choice = "B";
		}	
	}
}

