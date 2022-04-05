#include<bits/stdc++.h>
using namespace std;

//class to scan user names , enter choices and toss a coin.

class match{
	private:
		string player1,player2,winner_name;
		int winner;
	public:
		void details();
		void gamestart();
		int coinToss();	
		void tosswinner();
friend class game;	
friend class stats;				
};
match m1;

//class to start the match , and asks for choice to play again or show the stats.

class game{
	private:	
        int player1_wins=0,player2_wins=0,game_draw=0,player,i,choice;
	public:
		void matchstart();
		void play_again();
friend class match;	
friend class stats;
friend class display_board;
};
game g1;

//class to display the board , check for the winner and clear it once the match is over.

class display_board{
	private:
		char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
		vector<vector<char>> game_state;
	public:
		void board();
		void clear_board();
		int checkwin();
friend class game;
friend class stats;
};
display_board b1;

//class to show the statistics and print the detailed information.

class stats{
	private:
	    vector<pair<string,double>> match_time;	
	public:
	    void statistics();
	    void detailed_information();
friend class display_board;
friend class game;
};
stats s1;


//function to scan the name of users.
void match::details(){
		cout<<"-----------------------WELCOME TO TIC-TAC-TOE WORLD!-----------------------"<<endl<<endl;
		cout<<"Enter the name of player 1 : ";
		cin>>player1;
		cout<<"Enter the name of player 2: ";
		cin>>player2;
		cout<<endl;
		cout<<"WELCOME "<<player1<<" & "<<player2<<"!"<<endl;
		gamestart();
}

//function to start the toss.

void match::gamestart(){
		cout<<endl<<"Let's have a toss on who will run first!"<<endl;
		string toss;
		cout<<"Type 'TOSS' to get started : ";
		cin>>toss;
		if(toss=="TOSS"){
		tosswinner(); 
		}
		else{
			cout<<"Invalid Choice!"<<endl;
		}
}

int match::coinToss() {
	int randomNumber;
	randomNumber = 1 + rand() % 2;
	return randomNumber;
}

//function to cointoss and declaring the winner of toss.

void match::tosswinner(){
	cout<<"Enter your choice , " << player1 <<" (HEAD OR TAIL) : ";
	string choice1,choice2;
	cin>>choice1;
	if(choice1=="HEAD") choice2=="TAIL";
	else choice2=="HEAD";
	string coin;
    cout<<endl<<"Tossing the coin ! "<<endl;
    int number = coinToss();
    if(number%2==0) coin="HEAD";
    else coin="TAIL";
    cout<<"And the coin results in "<<coin<<" !"<<endl;
    if(coin==choice1){
    	winner=1;
	 winner_name=player1;
    }
    else {
    	winner=2;
	winner_name=player2;
    }
    cout<<endl<<"The winner is "<<winner_name<<" and will go first . "<<endl;
    cout<<"Let's start the game ! "<<endl;
    string start;
    cout<<"Type 'START' to load the TIC-TAC-TOE board : ";
    cin>>start;
    if(start=="START"){
	    g1.matchstart();
	} 
    else cout<<"Invalid Choice!";
}

//function to display the tic-tac-toe board.

void display_board::board(){
	cout << "     |     |     " <<endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

//function to clear the board after one match is over.

void display_board::clear_board(){
    square[1]='1';
    square[2]='2';
    square[3]='3';
    square[4]='4';
    square[5]='5';
    square[6]='6';
    square[7]='7';
    square[8]='8';
    square[9]='9';
	g1.matchstart();
}

//function to check for the winner.

int display_board::checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

//function to play the game and calculate time for each match and store it in vector pair for detailed stats.

void game::matchstart(){
	string curr_player,curr_winner;
	g1.player=m1.winner;
    char mark;
    time_t start,end;
    time(&start);
    do
    {	
	    cout<<"Here is your board!"<<endl;
        b1.board();
        g1.player=(g1.player%2)?1:2;
        if(g1.player==1){
        	curr_player=m1.player1;
		}
		else {
			curr_player=m1.player2;
		}
        cout << "Player " << curr_player << ", enter a number:  ";
        cin >> choice;
        mark=(g1.player == 1) ? 'X' : 'O';
        if (choice == 1 && b1.square[1] == '1')
            b1.square[1] = mark;
        else if (choice == 2 && b1.square[2] == '2')

            b1.square[2] = mark;
        else if (choice == 3 && b1.square[3] == '3')

            b1.square[3] = mark;
        else if (choice == 4 && b1.square[4] == '4')

            b1.square[4] = mark;
        else if (choice == 5 && b1.square[5] == '5')

            b1.square[5] = mark;
        else if (choice == 6 && b1.square[6] == '6')

            b1.square[6] = mark;
        else if (choice == 7 && b1.square[7] == '7')

            b1.square[7] = mark;
        else if (choice == 8 && b1.square[8] == '8')

            b1.square[8] = mark;
        else if (choice == 9 && b1.square[9] == '9')

            b1.square[9] = mark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i=b1.checkwin();
        player++;
    }while(i==-1);
    b1.board();
    curr_winner=curr_player;
    
    if(i==1){
    	cout<<"==>\aPlayer "<<curr_winner<<" wins!"<<endl;
        if(curr_winner==m1.player1){
    	player1_wins++;
	    }
	   else if(curr_winner==m1.player2){
		player2_wins++;
	    }
	}
	
    else{
    	cout<<"==>\aGame draw"<<endl;
    	game_draw++;
    	curr_winner="DRAW";
	}
	
	time(&end);
	b1.game_state.push_back(vector<char>(b1.square,b1.square+sizeof(b1.square)/sizeof(b1.square[0])));
	double curr_time=double(end-start);
	cout<<"Time taken for this match is "<<curr_time<<" seconds "<<endl;
	s1.match_time.push_back({curr_winner,curr_time});
    play_again();
}

//function to display choices after one match is over.

void game::play_again(){
	cout<<endl<<"Press 1 , if you want to play again. "<<endl<<"Press 2 , for game statistics. "<<endl<<"Press 3 , for exit. "<<endl;
	cout<<endl<<"Enter your choice : ";
	int choice;
	cin>>choice;
	switch(choice){
		case 1: b1.clear_board(); 
		case 2: s1.statistics();
		case 3: exit(0);
		default: cout<<"Invalid Choice!"<<endl;
	}
}


//function to show the stats after the game is over.

void stats::statistics(){
	cout<<endl<<"Game Statistics:"<<endl;
	cout<<endl<<"The total number of matches is "<<g1.player1_wins+g1.player2_wins+g1.game_draw<<endl;
	cout<<"The match won by "<<m1.player1<<" is "<<g1.player1_wins<<"."<<endl;
	cout<<"The match won by "<<m1.player2<<" is "<<g1.player2_wins<<"."<<endl;
	cout<<"The match draw"<<" is "<<g1.game_draw<<"."<<endl;
	cout<<endl<<"Press 1 for detailed information , 2 for exit : ";
	int ch; cin>>ch;
	switch(ch){
		case 1: detailed_information();
		case 2: exit(0);
		default: cout<<"Invalid Choice!"<<endl;
	}	
}


//function to display the detailed information after the matches are over.

void stats::detailed_information(){
	cout<<endl<<"Detailed Information:"<<endl;
	int count=1;
	double total_time=0;
	cout<<endl;
	cout<<"----------------------------------------------------------------------------------"<<endl;
	int m=b1.game_state.size();
	int n=b1.game_state[0].size();
	for(auto h: match_time){
		int i=0,p=0;
	for(int j=0;j<n;j++){
    	b1.square[p++]=b1.game_state[i][j];	
	}
	
	cout << setw(5) <<"  MATCH" << setw(15) << "WINNER "  << setw(22) << "TIME TAKEN " <<endl;
		cout << setw(5) << count << setw(15) << h.first <<  setw(15)<< h.second <<" seconds "<<endl;
		cout<<endl;
		cout<<"GAME BOARD STATE"<<endl;
		b1.board();
		cout<<endl;
		cout<<"----------------------------------------------------------------------------------"<<endl;
		total_time+=h.second;
		count++;
		i++;
	}
	cout<<"The total time taken for all the matches is "<<total_time<<" seconds."<<endl;
	
    	
}

int main()
{
	m1.details();
    return 0;
}
