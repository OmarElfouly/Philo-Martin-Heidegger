#include <iostream>
#include <string>
#include <windows.h> 
#include <cwchar>
#include <vector>

using namespace std;
#define INF INT_MAX

// function to output as if it was being typed
void type_text(const string& text)
{
    // loop through each character in the text
    for (std::size_t i = 0; i < text.size(); ++i)
    {
        // output one character
        // flush to make sure the output is not delayed
        cout << text[i] << std::flush;

        // sleep 60 milliseconds
        Sleep(50);
    }
    //cout << "\n";
}

vector<vector<int>> get_cost_matrix(vector<string> words, int lineWidth) {
    int n = words.size();
    int i, j;
    vector<vector<int>> leftOver(n + 1, vector<int>(n + 1));
    vector<vector<int>> lineCost(n + 1, vector<int>(n + 1));

    for (i = 1; i <= n; i++)
    {
        leftOver[i][i] = lineWidth - words[i - 1].length();
        for (j = i + 1; j <= n; j++)
            leftOver[i][j] = leftOver[i][j - 1] - words[j - 1].length() - 1;

    }
    for (i = 1; i <= n; i++) {

        for (j = i; j <= n; j++) {

            if (leftOver[i][j] < 0) {

                lineCost[i][j] = INF;

            }
            else {

                lineCost[i][j] = leftOver[i][j] * leftOver[i][j];
            }
        }
    }

    return lineCost;
}

vector<int> get_solution_array(vector<vector<int>> lineCostMat) {
    vector<int> total_cost(lineCostMat.size());
    vector<int> solution(lineCostMat.size());
    int n = (int)lineCostMat.size() - 1;
    int i, j;

    total_cost[0] = 0;
    for (j = 1; j <= n; j++) {
        total_cost[j] = INF;
        for (i = 1; i <= j; i++) {
            if (total_cost[i - 1] != INF && lineCostMat[i][j] != INF && (total_cost[i - 1] + lineCostMat[i][j] < total_cost[j])) {
                total_cost[j] = total_cost[i - 1] + lineCostMat[i][j];
                solution[j] = i;
            }
        }
    }


    return solution;
}

int display(vector<string> words, vector<int> solution, int size) {
    int k;
    if (solution[size] == 1) {
        k = 1;
    }
    else {
        k = display(words, solution, solution[size] - 1) + 1;
    }
    //cout << "Line number " << k << ": ";
    for (int i = solution[size]; i <= size; i++) {
        type_text(words[i - 1]); cout << " ";
    }
    cout << "\n";
    return k;
}
void wrap_text(string input, int lineWidth) {
    vector<string> words;
    words.push_back("");
    int count = 0;
    for (auto x : input) {
        if (x == ' ') {
            words.push_back("");
            count++;
        }
        else {
            words[count] = words[count] + x;
        }
    }
    display(words, get_solution_array(get_cost_matrix(words, lineWidth)), words.size());
}
void type(string input) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    wrap_text(input, columns);
}

int main()
{
	// https://www.text-image.com/convert/ was used to convert img to ascii
	// will put an image then their text
	// clear screen after every character
    //cout << "Before we begin please select the largest option that fits on your screen:\n";
    //cout << " ";
	type("Greetings player, welcome to my game! The goal of this game is to help you understand some of the things Martin Heidegerr wanted to teach you.");
	type("The game is a story based one where the player will encounter different characters each with the goal of teaching the player something new.");
	type("Whenever you see text between [] it means that the main character is thinking something.\n[Cool]");
	type("The player should expect to be prompted for input every now and again.\nGood luck!");
	type("Are you ready to learn?\n1. Yes\n2. N-");
	Sleep(100);
	cout << "\n\n";

	// print scientist ms3
	cout << R"(

                                                  
                      .^!7!^.                     
                .!~~?YPGGGGG5J!^^.                
                :GBBBBGGGGGGGGGGG7                
                ^BBBBBBBBBGGGGPPBG^               
                JB7!?JYYYYJJ?7!!P#7               
               .P?~77!~~~~~~!?7~!B?               
             .!7P7!JY7!!!~!!7YY!!5Y~.             
             :??5?7!7!~7J?J~~77!JYJ?^             
              ^!!!7777!77!77!7!77!!~              
                 ~!!~!7^^^^~7!!!~.                
                 .^~!!7!!!~!!!~^.                 
                   .:^~!!!!~^:.                   
                     .~!~~!~.                     
                .   .~7!!!!7~.   .                
             ..::.....77Y5?7. ...::...            
           .::::::....7YGG5?: ..::::::.           
          .::::::.....?5GG5?: ...::::::.          
          .::::::... :?5GGPJ^ ...:::::::          
         .::::::::.. ^JPGGPJ~ ...:::::::.         
         :::::::::.. ^JPGGGJ~ ..:::::::::         
        .::::::::::. ~YGGGGY! ..:::::::::.        
        .::::::::::. !YGGGGY7..::::::::::.        


		)" << "\n";

	type("Hey! I heard someone say Martin Heidegger! As a modern scientist (not the most creative name but it serves its purpose)");
	type("I cannot sit idly as someone mentions the name of the man who dared to seperate thinking and science, and who failed to acknowledge the uniqueness of modern science!");
	type("");
	type("Look behind you!");
	//present player with choice to turn and 
}