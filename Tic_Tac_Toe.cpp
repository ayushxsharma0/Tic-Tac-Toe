#include <iostream>
#include <stdlib.h>

using namespace std ;

// to mark quadrants char array is used

char square[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}} ;
char turn='X' ;
int row, column ;
int choice ;
bool draw = false ;


//to display the table 

void display_table(){
    cout<<"Player 1 - [X] \t Player 2 - [O] "<<endl ;
    cout<<"\t     |     |     \t"<<endl ;
    cout<<"\t  "<<square[0][0]<<"  |  "<<square[0][1]<<"  |  "<<square[0][2]<<"  \t"<<endl ;
    cout<<"\t_____|_____|_____\t"<<endl ;
    cout<<"\t     |     |     \t"<<endl ;
    cout<<"\t  "<<square[1][0]<<"  |  "<<square[1][1]<<"  |  "<<square[1][2]<<"  \t"<<endl ;
    cout<<"\t_____|_____|_____\t"<<endl ;
    cout<<"\t     |     |     \t"<<endl ;
    cout<<"\t  "<<square[2][0]<<"  |  "<<square[2][1]<<"  |  "<<square[2][2]<<"  \t"<<endl ;
    cout<<"\t     |     |     \t"<<endl ;
}

void player_turn(){
    if (turn == 'X')
    {
        cout<<"Player 1, Enter the Number - "<<endl ;
    }
    else if(turn == 'O'){
        cout<<"Player 2, Enter the Number - "<<endl ;
    }
    
    cin>>choice ;

    switch (choice)
    {
   case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && square[row][column] != 'X' && square[row][column] != 'O'){
        square[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && square[row][column] != 'X' && square[row][column] != 'O'){
        
        square[row][column] = 'O';
        turn = 'X';
    }else {
    
        cout<<"Box already filled!n Please choose another!!\n\n";
        player_turn();
    }
}

bool gameover(){
    
    for(int i=0; i<3; i++)
    if(square[i][0] == square[i][1] && square[i][0] == square[i][2] || square[0][i] == square[1][i] && square[0][i] == square[2][i])
    return false;

    

    if(square[0][0] == square[1][1] && square[0][0] == square[2][2] || square[0][2] == square[1][1] && square[0][2] == square[2][0])
    return false ;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(square[i][j] != 'X' && square[i][j] != 'O')
    return true;

    draw = true;
    return false;
}

// Driver code 
int main(){

    while(gameover()){
    display_table() ;
    player_turn() ;
    gameover() ;
    }

    if(turn == 'X' && draw == false){
        cout<<"\nCongratulations! Player with 'O' has won the game"<<endl ;
    }
    else if(turn == 'O' && draw == false){
        cout<<"\nCongratulations! Player with 'X' has won the game"<<endl;
    }
    else
    cout<<"\n\nGAME DRAW!!!\n\n";

    system("PAUSE");

    return 0 ;    
}