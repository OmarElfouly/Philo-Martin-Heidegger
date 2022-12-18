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

    type("{As soon as the scientest has walked out of site, a man aproaches from the distance. Similar, to the scientist this man also points towards the same direction}");

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
    type("This is why he cannot and will never see that the fundemntal defining feature of science is the mathmatical.");
    cout << "\n";
    type("Brace yourself friend for now I will do to you what was once done to me by Heidegger, that is to guide you to a definition of the mathmatical through language.");
    cout << "\n";
    type("In greek the mathmatical is ta mathemata. This directly translates to what can be learned, and by extension what can be taught.");
    type("By comparing other Greek words with their meaning we reach that ta mathemata must be things insofar that they … are learnable");
    type("Learning is grasping and appropriating but not all taking is learning.");
    type("For example taking a rock is not learning. Instead, learning is taking something you already have e.g. taking a word and placing it in your vocabulary");
    type("The mathemata, the mathematical, is that “about” things which we really already know.");
    cout << "\n";
    type("{This definition is essential to our journey as it describes an important limit of the mathmatical}");
    cout << "\n\n";
    type("Take as much time as you need to absorb this information.");
    cin.get();
    type("Next, I will ask you a question can man think?");
    type("Since man is the rational being, it is clear we possess reason. This reason evolves in thinking. So man must possess the posibility to think.");
    type("But Heidegger would have us question if this possibility can ever become reality. He argues that, the issue with the world is our issue is that man has taken an interest in everything, but I believe, that the interest of today is something short-lived and therefore to call something interesting is to seal its fate as anything interesting is soon replaced by another thing meaning the first item of interest is treated with indifference.");
    cout << "\n";
    type("To understand how to think we must first learn to think. And to learn to think we must know what there is to think about, which we will name the thought-provoking.");
    cout << "\n\n";
    type("{A sudden and powerful wind pulls at the player. This wind is so powerful the player feels as if his whole being is being pulled by it. No. Pulled TOWARD it.}");
    type("{The player finds himself facing the same direction as both the scientist and the follower}");
    type("[Something is there. I feel it withdrawing yet why do I feel this odd attraction towards it?]");
    cout << "\n";
    type("If my designer was more artisticly gifted you'd a knowing smile on my face. That draw you felt. That force that pulls at your very core yet at the same time, always, withdraws. Is what Heidegger named the most-thought-provoking.");
    type("Since the beginning, the most-thought-provoking has withdrawn from man leaving us lost and needy as while we can never truly see it, we feel its abscence, and its draw.");
    type("Since what must be thought has withdrawn, man cannot think properly, no matter how close to thought we have come in our current time.");
    cout << "\n";
    type("{Somehow, as a result of the draw of what is most-thought-provoking the player finds himseld alone and in a foregin land. In front of him lies a chasm that seprates the domain of science and thinking}");
    cout << R"(
.::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::::::::::::::::::::::::::::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:^^^^^^^:::::::::::::::::::::::::::::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::::::::::::::::::::::::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^::::::::::::::::::::.^!!!!!!!~::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::::::::::::::^^^!YYYYYYY?!!!~^
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^::::::::::!??JJYPGGGGP?!^:^:::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^::::::::::!PPPPBGPPPJ!.:::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::::::::::^^^^^5GGG#5^^^^::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^::^~^:::::^~7?J??P#BB&G!::::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::::7J?7!!!!?J55PP5G&&&@#J7^:::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^::^~~7PP55YYY5PGGGGGB@@GPP~^^^:::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::^:!?JJPGGGPPPGGY7JPGG#BJ^:::::::::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^::::::::::::::^^:::YPPGBBBBBBB#J:::^^^^^:::::::::::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::^:::^~~~~~^~^^~!7??7!JGGG######BPJ^:^^:::::^::::::::::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~!!!!?YYYJJ?JJJYY555Y5GBB#&&&#G?!::^^^^^^^^^^^^::::::::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^::::7YYYYPPPPPP5PPPPPGGPPG##&@@@@J:::^^^^^^^^^^^^^^^^::::::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:^!!~JPPPPGGGGGGGGGBBBBBBB&@@&&GYP~^:^^^^^^^^^^^^^^^^^^:::::::::::::::
:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^JYY5GGGGBB#BBBB5YJ??JYPGPPB!^^::^^^^^^^^^^^^^^^^^^^^^^::::::::::::::
:^^^^^^^^^^^^^^^^^^^::^:::::^:^~YPPGBBBB##G##5J^:::::::^::^::^^^^^^^^^^:^^^^^^^^^^^^^^^:::::::::::::
:^^^^^^^^^^^^::::^^^~~~~~~~~^^7J5BGB###&&7:!7::^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::::::::::
:^^^^^^^^^::^^~!!!7?JJJJJJJJ??YPG#B#&&@@&!^::^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::::::::
:^^^^^^^^^^^~?JJYYY55PPPPPPPP5PGB&#&@@@B!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::::::
:^^^::::^7?JJYPPPPPPGGGGGGGGGGGBB&@@@@&7:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::::::
:^^^^~~!7?5PPPPGGGGGBBBBBBBBBBB##@@@@@J:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:::::
:^~?JJJYY5PGGGGBBB######&#&&&##&&&#&@@5^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^::::
:^!Y5PPPPGGGBBBB##&&&&&@&@@B7~!?7~^~7Y?^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:
^?J5PGGGGBBB####&&@@&GPJ!?Y~:^^^^^^^^:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:
!YPGGGBBBB###&&&@@@&P:^^^^:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:
7GGBBB###&&&&&@@G7!~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:
7G###&&&&&@@@@@@P^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:
Y&&@@@@@@@@#5Y?!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:
?BGGBBBBGBP~::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


)" << "\n";
    type("{Looking around, the player spots faulty bridges in the distance each failing to cross this chasm}");
    type("{A person can be scene sitting on the edge of the chasm. The mysterious, yet well groomed, person turns to the player}");
    cout << "\n";
    cout << R"(


                                                                                                    
                                            .......                                                 
                                    ..:!7YYJYYY55555J777~:.                                         
                                  :?YJY55J??JJJJJY55PPP5PPPY7^.                                     
                               .^?55?7!~^::^^^~^^~!7?J?J55PPGPY7~:.                                 
                             .~7J??~:......::::.::^~~!!!?JJ55P5PPP55?~.                             
                            :7J?7!~~::::::::^^^^~!77??J?J?JY5Y55PPGB#BG7.                           
                           ~???~^:............::^~!!??JJY55YJ55PGGBBB###?                           
                          :YY?~:..   ...........:^~!777JYP5YY5PPGBBBBBB#G.                          
                          !5?~:.     ...........:~!!!7?J5PPY5PGGBBBGGBBB#7                          
                         :JJ7~.. .  ..   ......:^~!!!7?Y5GGPPGGBBGGGGBBB#B:                         
                        ^JY?7^.. .  ..     ....:^~~!77J5PPGBGPGGP5PPGGBB##~                         
                       .7?J?!:.     ..       ..^~!777JYY55PGPPPPPP5GBBBBBBJ                         
                       :7?J?7!~~^:......:~!7????JJ?JJY5YY55PPYPG555BBBBBB#P.                        
                      .^!YY7777?YY?^^~^?5P5YJ777?YYY55Y55555PPYPPGBBBBBB##P.                        
                      :~~YJ7~~!?YY?^^^!J5J!~!!7??JJY5YYY55555P5PPBBBBBBBB#B~                        
                     ^~!75YY7!PGPJ!~.~JJY7~???GBGGP5P5YJ5555555YPBBBBBBBB##5.                       
                    .~!7PP~~7!7!!^^^^JYJ?!~!!7YY55GPY?YY5PP55GP5PGGBBBBBB##B7                       
                     :!?GY::^^^:.:~:7YYJ?7~^~!!?JJ?7~!J5PP5PP55PY555GBBBBBB#B~                      
                      ~JPY~......^^^?YYYJ!:::~~~~~~!7J5PP555PYJYPG5J5BBBBBBB#G:                     
                     ^?YPY7^::.::^:~JY555!:.:~~!7?JY555P555PGY7JGG5JYPB#BBBBB#7                     
                    :7JJ55?!~^^~?^^!YYYY5?^:^~!?JY555P5P55PGPJ?5BP5JYYGB#BBBBB5.                    
                   .??JYY5?7~~!!JYY555YYPY7~~7?JYYYY55555PPP55GBBGG5YY5GBBBBBB#Y.                   
                   !J7JYY5Y?!~^.:7Y?JP555J?!7?JYYYY55555P5PGYGBBBGGBGGP5GBB##BB#J                   
                  ^5Y!?JJYPJ7!~~!??~75Y??JY?7?JYYYYY5555555GPGBBBBGBBGBGGGBBB#BB#J.                 
                   ^JJ!7?YP577!7J???JJYYJ55Y?7JJYYY5Y555Y5PG55GB##GBBGBGBBBBBBBBB#P~                
                    .7J?JPGGY?!!??J??JY5Y5J?7!?JYY55YY55YY5PGGBBGBBB#BBGB#BBBBBBB##Y                
                     ..~7J55PY?77?JJJJJJJJJ?77?JYY5YYYYJY5GBGGP5YJ5PPGPGBBBBB#BBBB#Y                
                           .:!Y?~:::::^!7???JJY5YYJYJJJY5PP55YJ??JYJ?5PPGBBBBBBBBBB5.               
                              !5J?77???J?JYYYYJJ???JJY5P5YJ?7!!7JYJJJPPGPGBBBBBB#B#B!               
                               ~?Y5Y5YYJYYJJJJ??JY55PP5J?7~^:^!?JYJ?PPP5G#######G5PJ:               
                                 .:Y5555Y55P55555555Y?!!^:.::~?JYYYJPYPB####BB##Y:                  
                               :^~!J7?JJYYYYYYJJJJ7~^~^.....^?JJYY5PYP###BB#BBBB#B?.                
                            ..:!JYJ?~^~!77??J??7!^:^:......:7??JJYY5G###BBBBBBBBB##Y:               
                           :..:!7?J?^:^^~~~!!7~:.:.. ...:^^?JJ????YB####BBBBBBBBBB##BY:             
                          .:..^~!???~:.:^^^^^....   ....:^!J?77?~7B####B#BBBGGBBBBB###GJ:           
                           ..:^^~7?J!^::^^:.. .::~?YJ?!~^^??!^!~!G###BBBBBBGGBBBBBBBBB##GJ^         
                           ..::~!?J?!^^^^^^:!?5GBB#####B5Y?!^!7JB###BBBBBGBGGBBGGBBBBBBB##B?^       
                         .:~.:::^7???!~^7??G#####BB#######P77!Y#####BBBGGGGPGGGGGGBBGBBBBB##B7      
                       .:^~~:.::^7JJ7~~J5P#####B####BBBBBB#J!5######BBBGGPGBBGBGPGGGBBBBBB####Y^    
                     .^~~~!?~::^7?77!!YPG###B###BB#GGBBBBB#PP&&####BBBBBGGGGGPPPGGGGGGBBBBBBB###5~. 
                    .~!^~7JJ!~^^~!7!?5GB######BBBBBBBBBGGB###########BBGPGGGPGPPGGGGGGBBBBBBBB####P?
                   ^7~^~!77!!^^^!!~?5G####BBBBGGBBGBBGPGBBGBBBB####BGGGPPGPGGPPGGPBGGBGBBBBBBBBB####
                  ^J?!!~~~~^:.:!~^7YP##BBBBBBGBGGBGGGGPBGGBBB####BBGGGPGGPPGPPGGPGGGGGGBBBBBBBBB##&#
                 :7!~~~~!~:.:^~!^~JYBBBBBBBBGGPGGGGGGPGGGBBBB###BBGGBPPGGPPGGGGPGGGGGBBBBBBBBBB#####
                .^^:^~~!~^^^~!!~^??GBBBGGGGGBPGBGGGGGBPPBBB##&#BBGGGGPGBPGGGBBGGGGGGBBBBBBBBB#######
              ^!~~^^^^^~~!77?77!?JJB#BGGGPPBGGGGGGBGBGPBBB###&BBGPGGPGG5PPPPGGGGGGGGBBBBBB##########
             :?7!~~~^~!!~~~!7~~!JJ5B#GGGPPGPPGGGGBBBGPB#BB##&BBBGGGPPG55PPPGGGBGGBBBBBBB##B#########
            ^?J!~~~~!7~^~!~~!~~?JYG#BGGPPGPGGBGGGBBBGB#B#####BBGGGPPGPPPPGGGGGGGGBBB#BB#############
           .7J?!~~!!~^~77~!7!~7JYPG#BGGPGGPPBGBPBBBBB#BB##&#BBGGGPPGPPGPGGGPGGGGBBB#################
           :??7!~^^~~!7!~77!!7?JYPB#BBGGGGPGGBBGBBB#B#B###&#BGGBGGGGPGGGGBBBBBB##B#################&
           !77!^^^^~7?!^~7?!~7?7JPBBGGGPGP5GGBBBGGBBB#BB####BGBBGBBGBBBBBBB##B###B##################

)" << "\n";
    type_text("We are a sign that is not read.\nWe feel no pain, we almost have\nLost our tongue in foreign lands.");
    cout << "\n";
    type("[A hymn? How intresting. Perhaps he is right for every person here always points in the same direction as if a sign despratly guiding us somewhere.]");
    cout << "\n";
    type("{The player realizes he has somehow gotten closer to the foothills of thinking but how he moved he is unsure. Although he suspects the words of that poet somehow helped push him towards what is most thought provoking}");

    cout << "\n";
    type("{This is an oppertunity for the player to stop and rest for a moment}");
    cin.get();








}