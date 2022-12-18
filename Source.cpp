#include <iostream>
#include <string>
#include <windows.h> 
#include <cwchar>
#include <vector>
#include <stdlib.h>


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
    string nothing;
	// https://www.text-image.com/convert/ was used to convert img to ascii
	// will put an image then their text
	// clear screen after every character
    //cout << "Before we begin please select the largest option that fits on your screen:\n";
    //cout << " ";
	type("Greetings player, welcome to my game! The goal of this game is to help you understand some of the things Martin Heidegerr wanted to teach you.");
	type("The game is a story based one where the player will encounter different characters each with the goal of teaching the player something new.");
    cout << "\n";
	type("Whenever you see text between [] it means that the main character is thinking something.\n[Cool]");
    type("Whenever the game master wishes to speak to you it will be between the {}.\n{Like this}");
    type("The player should expect to be prompted for input every now and again.");
    type("Sometimes a cursor will appear and the game will wait for the user to press the Enter button on their keyboard. Like this:\n");
    cin.get();
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

	type("Hey! I heard someone say Martin Heidegger! As the one and only Mr. Scienctist, full name Modern Scientist (not the most creative name but it serves its purpose)");
	type("I cannot sit idly as someone mentions the name of the man who dared to seperate thinking and science, and who failed to acknowledge the uniqueness of modern science!");
	type("[huh? what does he mean by seprating thinking and science?]");
    cout<<"\n{The player notices that the scientist seems to be facing a direction away from the player}\n\n";
    type("I mean its obvious to any layman how distinct modern science is from medival science. Right?"); cout << "\n";
    type("I mean modern science is based on facts while its predecssor relied on things such as concepts and propositions.");
    type("[Is he right? I remember there existing examples of propositions in medival science from class so I dont think so.]"); cout << "\n";
    type("Furthermore modern science is unique in its experiments and scientific method!");
    type("[That can't be right, the scientific method has exisisted since the 1600s! (Plus one point to scientific thinking)]"); cout << "\n";
    type("Lastly modern science is best known for its unqiue incredible calculations and investigations.");
    type("[Makes sense ... but calculations have exsisted long before modern science]"); cout << "\n";
    type("Your obviously convinced right? Anyhow welcome to the land of science hope you enjoy your time."); cout << "\n";
    type("{With a proud smile on his face the scientist walks away}\n{Odly enough you notice he still insists on facing a certain direction}"); cout << "\n";

    cout << "\n\n";
    type("{The main takeaway from this encounter was that modern science cannot be defined by its reliance on facts, its use of experiments, nor its calculations and investegations. So what defines modern science and by extension makes it distinct from other sciences??}");
    cout << "\n";
    cin.get();
    //system("cls");

    type("{As soon as the scientest has walked out of site, a man aproaches from the distance}");

    cout << R"(
5P55555555YYYYYYYYJJJJJJJJJ?JJ??????????77777777777777777!!!!!!!!!!!!!!!~~~~~~~~~~~~~~~~~~~~~~!!!!!!
5P55555555YYYYYYYJJJJJJJJJ?????????????7777777777!!!!!!!!!!!!7!!!!~!!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!
5P555555YYYYYYYYYJJJJJJJJJ????????????77777!!~~^~!~~^~~^^^~~!!!!!!777777!!!~~~~~~~~~~~~~~~~~~~~~~~~~
5P55555YYYYYYJJJJJJJJJJJJ???????7???777!!~^:::^~^^^:::::::::^~~~!7777?JJJYYJ?!!~~~~~~~~~~~~~~~~~~~~~
55555555YYYYJJJJJJJJJJ?????????????77!^^...::::.....:.:::::::^^^^~!!~!7??JJJYJJJ?777~^^^^~^~~~^~~~~~
555555YYYYYJJJJJJJJJ????????????7777!:................::::::::^^^^^!~~!77???JYJJJJJYYJ?!~^^~^^^~~~~~
5555YYYYYYJJJJJJJJJJ????????7??77!~^:.....  .........::.::::::::^^^^^~~~!!777??JYYJJJ55Y5Y!^^~^^^~^~
5555YYYYJJJJJJJJJJ?????????7???7!~:..... . ..........::::::::::^^^^^^^^~~~!!!!7?JJJJ?!?5PGPY!^^^^^~~
Y555YYYYJJJJJJJJJJ????????????77!::.       ..........:.:::::::::::^^^^~~~~~!!77???J?7!7?YPPP5~^^^^^^
Y55YYYYJJJJJJJJJ?JJ???????????7!^^....      .........::::::::::::^^^^^^^^~~~!!77????77!7?JYYP5~^^^^~
Y5YYYYYJJJJJJJJJJJ????????????7^^:...       ..........:::::::::::^^^^^^^~~~~!!!7?7???7777?J55PY^^^~~
Y5YYYYYJJJJJJJJJJJ????????????7~:...     . ..........::::::::::::^^^^^^^~~~!!!77777?JJ???JY55PG7^^^~
Y55YYYYYJJJJJJJJJ??????????7??!:...     ..............::::::::^^^^^^^^^~^~!!!!777???YY???JY55PP~^^^~
Y55YYYYJJJJJJJJJJJJ???????????^.... .. ...............:::::^::^^^^^^^^^~~~!!!7?77???Y5Y?JYY5PPP!^~^~
Y55YYYYJJJJJJJJJJJJ??J????????7::..  ...............:::::^^::::^^^^^^~~~~~~!77??7??JYYYJJY5PPPY~~~~~
Y555YYYYJJJJJJ?JJJJ?J??????????~:.      ..........:::::^^^:::::^^^^^^~~~~~!7?????JJJYYYYY5PPP5?~~~~~
Y55YYYYYJJJJJJJJJJJ?J???????7~!!.    ...:^^^^^:::::::::^^^::::::^^^^^~!!!!777??JJJJY55YJ5PPP5YY!^~~~
5555YYYYYYJJJJJJJJJJ???????J~: :.   .::^^~!7?J?7!~^^^^^^^^^^^~~^~~^^~~!!!777?J?JJJJY5P555PPP5Y?!~^~~
Y555YYYYYJYJJJJJJJJJJ???????:~^..  .^7^:~!!!!!7JYJ?7!77~~!!~~~~~~~~~!!77!777??JYYYYJYPGGPPPP5?~~~~~~
Y55YYYYYYJJJJJJJJJJJJ???????:^~.  .:^^!J5BGBPJ5J7?JYJJ!^~7?7?JJJY55PPP5J??77??J55YJJJJPBGPPG?~~^^~~~
Y55YYYYYYJJJJJJJJJJJJJ??????~::   ...:..:!JY?~?J??7!~^:^~!?YPGBBBBBGGPG5YYYJYJY55YJ??J5BGGGY^^^^~~~~
55555YYYYJJJJJJJJJJJJ????????^.      ..::^^^^^^^!7!^::::^~7YPGGGGBBPPYYYY55555555JJJ?J5GGGP7^^^~~~~~
Y55YYYYYYJJJJJJJJJJJJ???????J~       .::::::^^~~^:::::.:^~JPPP5P5Y5B#BPPGGGGGGP55YJJJYPGBJ~~~^^^~~~~
Y555YYYYJYJJJJJJJJJJJ????????! ........:::^^^^:::::..::^~755YY!^~~~!77!7?5GGGGPP5YJYJ5PGY!7?Y7^~~~~~
Y555YYYYYYJJJJJJJJJ?JJ?J????J^ ..::::::::::::...... ..:^!J5YJJ7!!~!~~!!!!7?5PP5YYJYYJPY?7?JYY~^~~~~!
555YYYYYYYYJJJJJJJJJJJ??????7.....:::.......:::..  ...:^7YYJJ?77!!!!!!7?JJJJYJ???JYJJYJ???JY!^~~~~~!
555YYYYYYJYJJJJJJJJJ?J??????............::::^~^..  ..:^~7JYYYJ7!!~~~!7777777777?JJYJYJY?7JJ!^~~~~~!!
5555Y5YYJJJJJJJJJJJJ?JJ?????^.........::^^!??^ ......:~!?YPP5GJ!!!~~~~~~~!777??JJYYYJ7J77?~^~~~~!!!!
5555YYYYYYYJJJJJJJJJJJJ???J?:.:....::^^~!J5?~......::^~?5PPY?5G7!!~!!!!7?JJJJJJJJ55Y???7!~~~~~~~!!!!
5P555YYYYYJJJJJJJJJJJJJ???J?..:::::^^~!?J?~^:^?Y7::^~!?YPP5JY5BG?7!!!7??JYYYJJJJY5YJ???7~~~~~~!!!!77
5P555YYYYYYJJJJJJJJJJJJJ??J!.:::^:^^!7??!:^7~^~JBY!J5PGBBB#BG55GGJ777??JJYJJJJJJ5YYJ?77~~~~~~!!!!777
555555YYYJYJJJJJJJJJJJJJJJJ^.:::^^~~~~~^^~77!?77YYP#####B#BGP555GPJJJJYYYJYYYJJ55YJ?J7~~~~~!!!!!7777
5P5555YYYYJJYJJJJJJJJJJJ?77^.:::^^^^:::^JPP?5YJPGGP5GGBBB##BGBGP5G5YYY5555YYYY55YYYJ?~~~!!!!!!!7777?
5P5555YYYYYJJJJJJJ?JJJ77!!7^.:::::::^~!???JJYPGGBBBGBBBGB##BGGGG5PPP555555YYY555J~!!~!!!!!!!!!7777??
Y55YYYJ???JYJJ?????JJ7!77777:::^:::^^~^^::::^~~!?JY5GB##&###B#&B5Y5P555PP5YY555Y~~~!!!!!!!!77777????
JJJJ?JJJJJY55YJ?????777???7?7:^:::^^^^^^^^^~!J5PGPPP55PGGGGGGBBB5YJY55PPP5555PY!!!!!!!!!!77777????JJ
5P5PPP555PPPP5J????777?????JJ?^~~~~~^^^^^^^~!7?JY5GBBBBGG5555PPP5YJJY555P5PPPY!!!!!!!!7777777????JJJ
PGGPGGPGGPGP5YJ?JJ?????JJJYJYYJ?5PPY~:^^^^:::::^^^~!7JJJJYYYYYY55YY55555PPPP?!!!7!!7!7777777???J?JJJ
PGGGGGGGGGPP555J??????JJJJJJYYY55PBB5~:^^^~~~~!!!~~~~~~~!7????JYYJY55555PPGY?7!!!!77777777????JJJJJY
PGGGGGGGGPPPPP55???JJJYYYYYYYYY5GGGPPP??777??777!!!7777?????JY5555PPPPPPB##BBGPYJ?7!7777??????JJJJYY
PGGGBGGGGPPPPP55??JJJY5YY5555YY5PGB#BPBBBBGBGPPP555PPP555Y5PGGBBGGGGGGG#&########BGPYJ??7????JJJJYYY
PGGGGGGGGGPPPPP55?JJJJ55555555555PGB&P75B####&&&&&&&##BBBBBBB######B5B#################BP5YJJ??JJJYY
PGGBGBBGGGGPPPP5PYYYY5PPPPPPP5PP5PPGB#?:~JPB#############BBBBBBGP5J!7######################BBGP55YYJ
GBBBBBBGGGGPPP5PPY555PPPPPPPPPPPPPPGGBB~.:^!J5GB##&######BBGPY?7!!~~5############################BGP
GBBBBBGGGGPPPP5G55555PPPPPPPPPP55PPPPGBP:::::^~7YG#&#BGPJ?77!!!!!!!7################################
GBBBBBBBGGGPP5PGPPP5PGGGGGGGPPPPPPPGP5PBJ:..:!YGB######B5?!!!!!!!!!Y&###############################
G#BBBBBBBGGGP5GGPPPPPGGGPGGPPPPPPPG5P5PGB!^?5PPBBB#######BY!!!!!!!7G&######B########################
G###BBBBBBBGPPGGPPPPGGGGPGPPPPPPPGP5Y5GGGG#BJ?YYPPGBB#BBB##5!!!!7!J###BB#B####B################&####
G&###B#BBBGGPPGPPPPGBBGGGGGPPPPPPGP55PPPGG##5??JY5PGGBBB####J~!!!7P###B##B##########B##############&
G&##BBBBBBGPPGPPPPPGGGGGGGGPPPGGGPP5PPPPPPG#BY???YY5GGB##GG&G!!!!7#####B######B#####################
G&####BBBBBPGGGBBBBBGGGGPPPPPPPGP5PPPPPGPPPB#G?7?JY5PGB#P77G&J!!!5&##BBBB##B#############&&#&&#&&&##
G&&BB#BBBBBGGGGGBBBBBBBBGGPPPGGPP5PPPPGPPPPPB#Y77?J5PB#Y!777PB7!7B##BBBBBB#BB##B#########&&&##&#&#&#
G&&###B#BBBBBBBGGGGGGGGBGBBGGBPPPPPPPPGPPPPPP#GJ????YB5!7!777Y5!Y#GBBGGGBBBBB#BBBBBB#####&&##&&#&#&#
G&#&###B##BBBBBGBBGGGGGGGGPPGGPGGPPPPPPPPPPPPG#Y!~!75J~777!!!~775PPBGPPGBGBBBBBBBBB########&&&&&&&&#
G&######B#BBBBBBBBGGGGGGGGGGGGPPGGPGPPPPPPPPPPBG7~!PB#J~!!!!!~~^!?5BG5PGGGGBBGBBBB#######&&&########
G&&&####BBBBBGBBBBGGGGPGGGGGGGPPGGGPPPPP5PPPPPGBY~?PGGB?!!!!!!~!J?JBG5PGGGGGGGBBBB#######&&####BB###
)" << "\n";

    type("Hello there friend. I am a follower of Heidegger (which is why the lazy game designer gave me his face)");
    type("{rude}");
    type("You probably noticed the scientiest's inability to provide a definition of modern science that makes it distinct from medival science.");
    type("This is a result of him being a postivist who beleives all we need in life is facts, and that we should avoid all concepts.");
    type("This immeadiatly creats an issue as whenever Mr. Scientist inevitably encounters a concept in his investegations he will ignore it, no matter how essential it is to reaching a valid conclusion.");



}