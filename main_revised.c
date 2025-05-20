/*  User stories
 
Login Page – the password is minimum length is 8 digits with 1 special character 
required: 
As a new user, I want to create a secure password with at least 8 characters, including at least one 
special character, so that my account remains protected.
 
Acceptance criteria
Functional requirements
Given a user decides to create an account, when they select a password, then the system 
must verify it has a minimum of 8 characters with at least 1 special character.

Quality attributes & Non-functional requirements
Convenience: The password requirements are reasonable and balance the ability to be 
easily recalled while maintaining security.
 
 Second user story
(Front of index card)
The Hedge Fund Simulator’s Risk Tolerance Setting:
As an aspiring trader, I want to adjust risk tolerance settings so that I can explore different 
investment strategies.


Acceptance criteria
Functional requirements
Given the simulator is launched, when a user inputs their starting parameters(including
risk tolerance), then the simulator will track their investments and portfolio performance 
over a specified duration. The user can also alter each starting parameter.
Quality attributes & Non-functional requirements
Fidelity: Risk tolerance will be reflected by simulated market behaviors.
Flexibility: Users must have the option to adjust starting parameters: initial capital, 
algorithm selection, duration, asset allocation, and risk tolerance.

 Third user story
The Advanced Tutorial’s in-depth knowledge on Leveraging AI: 
As an experienced trader, I want to access tutorials on AI for hedge fund management, 
especially leveraging AI, so that I can enhance my own knowledge.

Acceptance criteria
Functional requirements
Given a user selects the advanced tutorial, when they engage the modules, then they will 
receive information on AI related hedge fund topics such as algorithmic trading and 
optimization recommendations. 

Quality attributes & Non-functional requirements
Fidelity: Both the information and examples provided will reflect real-world hedge fund 
practices.
Flexibility: Users will be able to select specific topics and strategies within the advanced 
tutorial.





2. Using OpenCV (Computer Vision Library)
If your project involves image processing, OpenCV can display images easily:

c
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("image.jpg");  // Load JPG file
    cv::imshow("Display Window", img);
    cv::waitKey(0);  // Wait for user input to close window
    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


// intro topics  **no need for = in precompiler directives
#define	BASIC_STRUCTURE "basic_structure.txt"
#define	INTRO "hedge_funds_intro.txt" 
#define	HOW_THEY_WORK "how_they_work.txt"

// advanced topics
#define	CURRENT_MARKET_CONDITIONS  "current_market_conditions.txt"
#define	DIGITAL_ASSETS_TOKENIZATION  "digital_assets_tokenization.txt"
#define	MANAGING_RISK  "managing_risk.txt"
#define	LEVERAGING_AI  "leveraging_AI.txt"
#define	STRATEGIES  "strategies.txt"

/*
 * Struct: Account
 * Purpose: represents an individual account
 * Fields:
 *     - user name: up to 33 characters
 *     - password: up to 12 characters
 *     - experience: Level 1 to 5
 *     -
 *     - risk_tolerance: a float value between 1.0 and 10.0 (inclusive).
 *     - *next: A pointer to the next account
 * Usage:
 *     This struct is used to implement a linked list of accounts
 */

 // may need to adjust buffer sizes for paswords and emails 
 // emaail Maximum Length: Up to 254 characters (RFC standard)
 //Minimum Recommended Length: 12–16 characters (longer is better!) 🔒 Strong Security: 16–24 characters
 // for maximum protection 🔒 Must Include: A mix of uppercase, lowercase, numbers, and symb
struct account{
    char name[33];
    char password[12];
    int  experience;
    char email[20];
    float risk_tolerance;
    double a_tutorial_time;
    struct account *next;
};

typedef struct {
    float stocks, bonds, annuities;
} allocation;

struct account* create_account(struct account* ll_head, struct account* user);

void customer_accounts_setup(struct account *ll_head);

struct account*  create_account_from_file(char* csv_line);

void  login();

void template(float initial_capital,float risk_tolerance, int difficulty_level, int duration, char algorithm[] );
void  help();

void  login_assistance();

/*
Since these literals are immutable, passing them to a function expecting a modifiable character 
array (char filename[100]) causes issues. 
Changing your function parameter to const char* (as shown above) resolves this.
*/
void  display_ind_tutorial(const char* filename);

void display_beginner_tutorial();

void  display_advanced_tutorial();

void  run_simulator(struct account* user);

bool password_check(char password[]);


int main(int argc, char *argv[]) {
    struct account *new_user = (struct account *) malloc(sizeof(struct account));
    struct account *ll_head = NULL;
    char Continue = 'y';
    printf("Welcome to Hege Funds For Dummies\n");
    printf("We Make Hedge Funds Simple \n");
    printf("\n");
    // IH1
    printf("You can learn more about this complex financial instrument at your own pace. \n");
    printf("There is a begginner tutorial, an advanced tutorial, and a simulator for you to enjoy.\n");
    printf("You can experience realistic market conditions without financial risk.\n");
    printf("You will be also asked to specifiy your level of experience, and you can update this as you make progress.\n");
    printf("The time you spend learning advanced material and your simulation experiences will be tracked for your convienence.\n");
    printf("Press Enter to continue. \n");
    getchar();
    system("clear"); // clear the screen
    while (Continue != 'Q' || Continue == 'q'){
        printf("        Main Menu\n");
        printf("Enter L or l to Log in to your account\n");
        printf("Enter C or c to create an account\n");
        printf("Enter H or h for help\n");
        printf("Enter Q or q to exit the app\n");
        scanf(" %c", &Continue);

        if (Continue== 'L' || Continue== 'l' ){     // upper or lower case is acceptable
            // call log in function login();
            login();
            //Continue = 'A'; // Automatically transition to Activities Menu after login
            // continue;
            goto activities_menu;
        }  
        if (Continue== 'C' || Continue== 'c' ){     // upper or lower case is acceptable
             new_user = create_account(ll_head, new_user);
            //Continue = 'A';
            //continue;
            goto activities_menu;
        }

        if (Continue== 'Q' || Continue== 'q' ){     // upper or lower case is acceptable
            break;
        }
        
        if (Continue== 'H' || Continue== 'h' ){     // upper or lower case is acceptable
            // call Help;
            help();
            //Continue = 'G';
            continue;
        }

        printf("\n");

        /*
        IH3
        The user can select from a choice of three activities: Basic tutorials, advanced tutorials, and
         a simulator option. This screen allows users to select their preferred depth of information. Users can 
         begin with introductory knowledge in the Basic Tutorials or go straight to  Advanced Tutorials if desired. 


        
        */
        // create a while loop for the activities menu
        activities_menu:
        while (Continue != 'G' || Continue != 'g'){
        system("clear"); // clear the screen
        printf("                       Activities Menu                         \n");
        printf("**Basic Tutorial**      **Advanced Tutorial**      **Simulator**  \n");
        printf("Please Enter B for the Basic Tutorial, A for the Advanced Tutorial, or S to run the Simulator: ");
        scanf(" %c", &Continue);
        if (Continue== 'B' || Continue== 'b' ){     // Basic Tutorial
            printf("**The Basic Tutorial provides information about hedge funds such as their history, basic structure, and how they work. \n");
            printf("**Would you like to enter the basic tutorial? If yes enter Y.");
            printf("\n");
            printf("**If you would like to go back to the home screen, please enter G or g to go back. ");
            scanf(" %c", &Continue);
            if (Continue  == 'Y' || Continue  == 'y'){
                system("clear"); // clear the screen
                display_beginner_tutorial();
                system("clear"); // clear the screen
                }
            else{
                Continue = 'G';
                }
        }

        if (Continue== 'A' || Continue== 'a' ){     // Advanced Tutorial
            printf("**The Advanced Tutorial provides information on more advanced topics regarding hedge funds. \n");
            printf("**Here is a complete list: Digital Assets and Tokenization, managing risk, leveraging artificial intelligence, current market conditions, and strategies. \n");
            //IH2
            printf("You can expect each of the Advanced Tutorials to take 15–30 minutes to complete.\n");
            printf("**Would you like to enter the Advance Tutorial? If yes enter, Y or not enter N.");
            printf("\n");
            printf("**If you would like to go back to the home screen, please enter G or g to go back. ");
            scanf(" %c", &Continue);
            if (Continue  == 'Y' || Continue  == 'y'){

                clock_t start_time, end_time;
                start_time = clock(); 
                system("clear"); // clear the screen
                display_advanced_tutorial();
                system("clear"); // clear the screen
                end_time= clock();
                new_user->a_tutorial_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
                }
                else{
                Continue = 'G';
                }
        }

        if (Continue== 'S' || Continue== 's' ){     // Advanced Tutorial
            printf("**The Simulator will let you put your knowledge to use. \n");
            printf("You can customize your simulation with the following options:  \n");
            printf("initial capital, select an algorithm, duration, asset allocation, and risk tolerance \n");
            //
            printf("**Would you like to enter the Simulation? If yes enter, y or not enter n. ");
            printf("\n");
            printf("**If you would like to go back to the home screen, please enter G or g to go back. ");
            scanf(" %c", &Continue);
            if (Continue  == 'Y' || Continue  == 'y'){
                // call the simulator
                run_simulator(new_user); 
                }
                else{
                Continue = 'G';
                }
        }

      }

    }
    
    return 0;
}

/* Function:  () 
 * Purpose:  
 * Parameters:
 *     - param1(data type):  
 *     - param1(data type): T 
 * Return Value:
 *     - 
 * 
 * 
*/

/* Function: customer_accounts_setup() 
 * Purpose: creates customer accounts from the specified file customer_accounts.csv
 * Parameters:
 *     - ll_head(account struct): the head of the linked list storing the customer accounts
 * Return Value: no return value with the csv files being loaded into the linked list for use in the app. 
*/
void customer_accounts_setup(struct account *ll_head){
    struct account *curr_account = NULL;

    char *currLine = NULL;
    size_t len = 0;
    // Open the customer data file for reading only
    char* filename = "customer_accounts.csv";
    FILE* customersFile = fopen(filename, "r");
    if (customersFile == NULL) {
      perror("Error opening file");
      return;
    }
    // read past the header on line 1
    //getline(&currLine, &len, customersFile);

    // read the file line by line
    while(getline(&currLine, &len, customersFile) != -1)
    {  
      curr_account = create_account_from_file(currLine);

    // add to linked list
    if (ll_head == NULL) {
        ll_head = curr_account; 
      } 

    // free the memory allocated by getline for currLine
    free(currLine);
    // Close the file
    fclose(customersFile);
    }
}


/* Function:  () 
 * Purpose:  
 * Parameters:
 *     - param1(data type):  
 *     - param1(data type): T 
 * Return Value:
 *     - 
 * 
 * 
*/
/*
 char name[33];
   char name[33];
    char password[12];
    int experience[12];
    char email[20];
    float risk_tolerance;
    struct account *next;
*/

struct account*  create_account_from_file(char* csv_line){
    char *token, *savePtr;
    // allocate memory for each new account
    struct account* customer_account = malloc(sizeof(struct account));
    // extract the name
    token = strtok_r(csv_line, ",", &savePtr);
    strcpy(customer_account->name, token);  //str_cpy since its not a pointer

    // extract the passoword
    token = strtok_r(NULL, ",", &savePtr);
    strcpy(customer_account->name, token); 

     // extract the experience
     token = strtok_r(NULL, ",", &savePtr);
     customer_account->experience = atoi(token);

    // extract the email
    token = strtok_r(NULL, ",", &savePtr);
    strcpy(customer_account->name, token);

    // extract the risk tolerance
    token = strtok_r(NULL, ",", &savePtr);
    strcpy(customer_account->name, token);
    customer_account->next = NULL;
    return customer_account;
}


/* Function:  () 
 * Purpose:  
 * Parameters:
 *     - param1(data type):  
 *     - param1(data type): T 
 * Return Value:
 *     - 
 * 
 * 
*/

/* Function: create_account() 
 * Purpose: creates a new user account from the user provided data
 * Parameters:
 *     - user(account struct): empty user account
 * Return Value: the user struct with the appropriate values entered by the user 
 * and written to customer_accounts.csv
*/
struct account* create_account(struct account* ll_head, struct account* user){
    system("clear"); // clear the screen
    printf("        **Create Your Account**\n");
    // IH2
    printf("**Please be advised that your information will maintained on a secure private server**\n");
    printf("Please enter your full name (up to 33 characters): ");
    while (getchar() != '\n');
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = '\0';

    printf("\n");
    printf("Please select a password that is easy for you to remember but difficult to guess: \n");
    printf("**The password must be at least 8 characters and include at least one special character** ");
    fgets(user->password, sizeof(user->password), stdin);
    user->password[strcspn(user->password, "\n")] = '\0';
    while (password_check (user->password)== false){
        printf("Please choose  a password that is at least 8 characters and includes at least one special character ");
        fgets(user->password, sizeof(user->password), stdin);
        user->password[strcspn(user->password, "\n")] = '\0';
    }

    printf("Please enter your experience level on a scale of 1-4 with 4 being the highest: ");
    scanf("%d", &user->experience);
    while(user->experience<1 || user->experience>4){
        printf("**Please re-enter your experience level on a scale of 1-4 with 4 being the highest: ** \n");
    }

    printf("Please enter your risk tolerance on a scale of 1.0-10.0 with 10 being the highest: \n");
    scanf("%f", &user->risk_tolerance);

    while ((user->risk_tolerance > 10.0 || user->risk_tolerance < 1.0)){
        printf("**Please re-enter your risk tolerance on a scale of 1.0-10.0: ***");
        scanf("%f", &user->risk_tolerance);
    }

    printf("\n");
    while (getchar() != '\n'); // clear the buffer
    printf("Please enter your email address: ");
    fgets(user->email, sizeof(user->email), stdin);
    user->email[strcspn(user->email, "\n")] = '\0';
    
    printf("Please note this will be used to provide your credentials in the event you are unable to access your account.");
    printf("\n");
    getchar();
    // add to the customer database  **segmentation fault
    FILE *file = fopen("customer_accounts.csv", "a");  // Open file in append mode
    if (!file) {
        perror("Error opening file");
        return NULL;  // Handle error appropriately
    }
    fprintf(file, "%s,%s,%d,%s,%f\n", 
        user->name, 
        user->password, 
        user->experience, 
        user->email, 
        user->risk_tolerance);
    fclose(file);  // close the file
    // point the head to the newly created user if the head is NULLL, otherwise add to LL
    if (ll_head == NULL){
        ll_head = user;
        return user;
    }
    ll_head->next=user;
    return user;
}      

/*
    char name[33];
    char password[12];
    int experience;
    char email[20];
    float risk_tolerance;
    struct account *next;
*/

/* Function: password_check()
 * Purpose: validate the user entered password
 * Parameters:
 *     - passwprd(string):  
 * Return Value: returns true if the password is at least 8 characters and contains at least 1 special character
 *
*/
bool password_check(char password[]){
    int i;
    if (strlen(password) >= 8){
        for (i = 0; i < strlen(password); i++)
        {
            if (password[i] >=33 && password[i] <=47){
                return true;
            }

            if (password[i] >=58  && password[i]<= 64 ){
                return true;
            }

            if (password[i] >=91  && password[i]<= 96 ){
                return true;
            }
            if (password[i] >=123  && password[i]<= 126 ){
                return true;
            }
        }
        }
        
        return false;
}

      /*
    
0–31 & 127	Control Characters	\n, \t, \r
32–47	Punctuation	Space (), !, ", #, $, %, &, ', (, )
58–64	Punctuation/Symbols	:, ;, <, =, >, ?, @
91–96	Brackets & Misc	[, \, ], ^, _, `
123–126	Braces & Operators	{, `
    
*/
/* Function: display_tutorial()
 * Purpose: function to display tutorial text files line
 * Parameters:
 *     - na( ):  
 * Return Value: displays the requested tutorial line by line
 *
*/ // parameter should be the file name
void display_ind_tutorial(const char* filename){
    FILE *file;
    char buffer[256];

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    // print line by line
    printf("\nFile content:\n");
    while (fgets(buffer, 256, file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}


/*
#define	BASIC_STRUCTURE "basic_structure.txt"
#define	INTRO "hedge_funds_intro.txt" 
#define	HOW_THEY_WORK "how_they_work.txt"

*/

/* Function: display_beginner_tutorial() 
 * Purpose: Displays the begginer tutorial pages and provides the user the option to either repeat or go back 
 * to the main menu
 * Parameters: None
 *  
 * Return Value: No return value with the appropriate tutorial being displayed line by line
   - 
*/

void display_beginner_tutorial(){
    char choice; 
    printf("The Basic Tutorial Begins Here");
    origins:
    printf("            Origins of Hedge Funds");
    display_ind_tutorial(INTRO);
    printf("\n");
    printf("Do you want to see that again or go to the next tutorial? Enter Y to display that tutorial again, or any other key to move to the next page.\n");
    printf("You can also enter G to go back to the Activities Menu. ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y'){
        goto origins;
    }

    if (choice == 'G' || choice == 'g'){
        return;
    }

    hedge_fund_workings:
    printf("            How Hedge Funds Work");
    display_ind_tutorial(HOW_THEY_WORK);
    printf("\n");
    printf("Do you want to see that again or go to the next tutorial? Enter Y to display that tutorial again, or any other key to move to the next page.\n");
    printf("You can also enter G to go back to the Activities Menu. ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y'){
        goto hedge_fund_workings;
    }

    if (choice == 'G' || choice == 'g'){
        return;
    }

    basic_structure:
    printf("\n");
    printf("            Basic Structure");
    display_ind_tutorial(BASIC_STRUCTURE);
    printf("\n");
    printf("Do you want to see that again or go to the next tutorial?Enter Y to display that tutorial again, or any other key to move to the next page.\n");
    printf("You can also enter G to go back to the Activities Menu. ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y'){
        goto basic_structure;
    }

    if (choice == 'G' || choice == 'g'){
        return;
    }

}

/*
// advanced topics
#define	CURRENT_MARKET_CONDITIONS  "current_market_conditions.txt"
#define	DIGITAL_ASSETS_TOKENIZATION  "digital_assets_tokenization.txt"
#define	MANAGING_RISK  "managing_risk.txt"
#define	LEVERAGING_AI  "leveraging_AI.txt"
#define	STRATEGIES  "strategies.txt"

*/

/* Function: display_advanced_tutorial() 
 * Purpose: Displays the advanced tutorial pages and provides the user the option to either repeat or go back 
 * to the main menu
 * Parameters: None
 *  
 * Return Value: No return value with the advanced tutorial being displayed line by line
*/
void display_advanced_tutorial(){
    char choice; 
    printf("The Advanced Tutorial Begins Here");
    market_conditions:
    printf("            Current Market Conditions");
    display_ind_tutorial(CURRENT_MARKET_CONDITIONS);
    printf("\n");
    printf("Do you want to see that again or go to the next tutorial? Enter Y to display that tutorial again, or any other key to move to the next page.\n");
    printf("You can also enter G to go back to the Activities Menu. ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y'){
        goto market_conditions;
    }

     if (choice == 'G' || choice == 'g'){
        return;
    }

    da_tokenization:
    printf("            Digital Assets and Tokenization");
    display_ind_tutorial(DIGITAL_ASSETS_TOKENIZATION);
    printf("\n");
    printf("Do you want to see that again or go to the next tutorial? Enter Y to display that tutorial again, or any other key to move to the next page.\n");
    printf("You can also enter G to go back to the Activities Menu. ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y'){
        goto da_tokenization;
    }

    if (choice == 'G' || choice == 'g'){
        return;
    }

    /*
#IH2
Risk management is critical to successful hedge fund trading. Topics include industry risk management best
 practices: trading limits, stress testing, liquidity analysis, back testing, and leverage. The tutorial also 
 discusses nine ‘red flags’ common in the industry. Banner: Feel free to try these risky strategies in the Simulator without financial jeopardy.
These are useful problem-solving skills for any profession, and the user can enjoy enrichment with no financial risk. 


    */
    managing_risk:
    printf("            Managing Risk");
    display_ind_tutorial(MANAGING_RISK);
    printf("\n");
    printf("Do you want to see that again or go to the next tutorial? Enter Y to display that tutorial again, or any other key to move to the next page.\n");
    printf("You can also enter G to go back to the Activities Menu. ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y'){
        goto managing_risk;
    }

    if (choice = 'G' || choice == 'g'){
        return;
    }
        
    ai:
    printf("            Leveraging Artificial Intelligence");
    display_ind_tutorial(LEVERAGING_AI);
    printf("\n");
    printf("Do you want to see that again or go to the next tutorial? Enter Y to display that tutorial again, or any other key to move to the next page.\n");
    printf("You can also enter G to go back to the Activities Menu. ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y'){
        goto ai;
    }

    if (choice == 'G' || choice == 'g'){
        return;
    }

    strategy:
    printf("            Strategies");
    display_ind_tutorial(STRATEGIES);
    printf("\n");
    printf("Do you want to see that again or go to the next tutorial? Enter Y to display that tutorial again, or any other key to move to the next page.\n");
    printf("You can also enter G to go back to the Activities Menu. ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y'){
        goto strategy;
    }

    if (choice == 'G' || choice == 'g'){
        return;
    }
    
}


/* IH4
The login page includes ubiquitous fields like "Username," "Password," and 
a "Forgot Password?" link. Users are likely to expect and be comfortable using them. The 
layout is intended to be intuitive by mirroring common patterns found in apps and websites. Lastly,
 error recovery is supported through the "Forgot Password?" option.

*/
/* Function: help()
 * Purpose: simulates logging in for the user 
 * Parameters: None
 *     
 * Return Value: none with the user being granted access to their account
*/
void login(){
    char user_name[33];
    char password[12];
    system("clear"); // clear the screen
    //IH4
    printf("        **Login to Your Account**\n");

    printf("Enter F if you forgot your username, or enter to access your account with your username and password: \n");
    fgets(user_name, sizeof(user_name), stdin);
    user_name[strcspn(user_name, "\n")] = '\0';
    
    // call login assistance if the user enters f or F
    if (user_name[0] == 'F' || user_name[0] == 'f'){
        login_assistance();
    }

    printf("Please enter your username: ");
    fgets(user_name, sizeof(user_name), stdin);
    user_name[strcspn(user_name, "\n")] = '\0';
    
    printf("\n");
    printf("Please enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';
    printf("Welcome back %s \n \n", user_name);

}


/* Function: help()
 * Purpose: displays a useful help information to the user
 * Parameters: None
 *     
 * Return Value: none with helpful information displayed to the user
*/
void  help(){
    char choice;
    system("clear"); // clear the screen
    printf("\n"); 
    printf("          **Help Menu** \n");
    printf("Please let us know how we can assist you. \n");
    printf("Please enter L if you need assistance with resetting your password \n");
    printf("Please enter H again if you want to learn more about how the app works: \n");
    scanf(" %c", &choice);
    if (choice == 'L' ||choice == 'l'){
        login_assistance();
        return;
    }
     if (choice == 'H' ||choice == 'h'){ 
        printf("Commands are not case sensitive and can be entered as upper or lower case. \n");
        printf("We also have an option for resetting your password by selecing L for login assstance. \n");
        printf("When creating an account, you will need to enter each value as directed, and you will not be able to proceed until a correct entry is placed. \n");
        printf("The tutorials are broken down into begginer and advanced sections. \n");
        printf("Remember there is no fiancial risk while using the simulator, you will be provided with guidance, as needed.\n");
        printf("You also have the option to use a custom template. \n");
        getchar();
    }
}



/*
#IH6 a well-defined and explicit task process that provides clarity and structure.
The login_assisance page();
*/
/* Function: login_assistance()
 * Purpose: sends an email to the user with their credentials
 * Parameters: None
 *     
 * Return Value: sends an email to the user with their credentials
*/
void  login_assistance(){
    char menu[2];
    system("clear"); // clear the screen
    printf("\n"); 
    printf("        **Login Assostance** \n");
    printf("Please use the form below if you're unable to remember your username and/or password. \n");
    printf("You also have the option to email or call our team directly for assistance if needed.\n");
    printf("For assistance via email, please email wheelken@oregonstate.edu; for assistance over the phone, please call (318) 538-3744.\n");
    while (getchar() != '\n'); // clear the buffer
    char email[33];
    printf("Please enter your email in the format email@provider.com: \n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    while (getchar() != '\n'); // clear the buffer
    printf("Please verify your email. We have: %s. Please enter Y or to confirm or N to re-enter.", email);
    fgets(menu, sizeof(menu), stdin);
    while (menu[0] != 'Y' && menu[0] != 'y') {
        while (getchar() != '\n'); // clear the buffer
        printf("Please re-enter your email in the format email@provider.com: \n");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0';
        printf("Please verify your email. We have: %s. Please enter Y or to confirm or N to re-enter. ", email);
        fgets(menu, sizeof(menu), stdin);
        }
    printf("You will recieve an email with your credentials within the next 5 minutes- please check your inbox. \n");
    getchar();

}                                   // implement as a microservice 

/*
  allocation asset_allocation;
    float initial_capital, risk_tolerance; 
    int difficulty_level,duration;
    char algorithm[10];
    char menu[2]; 

    IH#8
    The custom template provides a range of acceptable values, and a warning if they input a value that 
    is mathematically acceptable, but unrealistic. The “Standard” templates follow normal hedge fund strategies.  

*/
void template(float initial_capital,float risk_tolerance, int difficulty_level, int duration, char algorithm[] ){
    int aggression; 
    printf("\n");
    printf("Please describe the level of aggresivness you would like to use in your simulation on a scale of 1-5 (with 5 being the highest)? ");
    scanf("%d", &aggression);

    switch (aggression) {
        case 1:
            printf("\n");
            printf("Very conservative with less risk; here are the best options:  ");
            printf("Initial Capital should be over $10 million to ensure stability:  \n");
            printf("Risk tolerance of 1 \n");
            printf("Duration: at least 5 years (60 months) \n");
            printf("Algorithm: Regression Analysis\n");
            break;

        case 2:
            printf("\n");
            printf("For a small amount of risk; here are the best options:  ");
            printf("Initial Capital should be over $1 to $5 million:  \n");
            printf("Risk tolerance of 2 \n");
            printf("Duration: 3-5 years (36-60 months) \n");
            printf("Algorithm: Regression Analysis \n");
            break;
        case 3:
            printf("\n");
            printf("For a medium amount of risk; here are the best options:  ");
            printf("Initial Capital should be $1 to $5 million: \n");
            printf("Risk tolerance of 3\n");
            printf("Duration: 3-7 years (36-84 months)\n");
            printf("Algorithm: Convertible Arbitrage\n");
        case 4:
            printf("\n");
            printf("Moderately Aggressive: here are the best options:  ");
            printf("Initial Capital should be at least $1 million\n");
            printf("Risk tolerance of 4\n");
            printf("Duration: 1-5 years (12-60 months)\n");
            printf("Algorithm: Merger Arbitrage (Risk Arbitrage)\n");
            break;
        case 5:
            printf("\n");
            printf("Very Aggressive: here are the best options for this path: ");
            printf("Initial Capital should be at least $1 million\n");
            printf("Risk tolerance of 5\n");
            printf("Duration: less than one year (12 months)\n");
            printf("Algorithm: High-frequency AI strategies \n");
            break;
        default:
        // use normal risk parameters
    }
}

/* 
typedef struct {
    float stocks, bonds, annuities;
} allocation;

*/

/* Function: run_simulator()
* Purpose: runs a simulator once the user enters the required information: initial_capital, 
*  duration, assett_allocation, risk_tolerance, and selects an algorithm.  
* Parameters: None
*     
* Return Value: none with the results of the simulation being displayed to the user. 
*/
void  run_simulator(struct account* user){
    allocation asset_allocation;
    float initial_capital, risk_tolerance; 
    int difficulty_level,duration;
    char algorithm[10];
    char menu[2]; 

    sim:
    // printf("\n");
    printf("        **Welcome to the Simulator** \n");
    // let the user decide if they want to use templates
    printf("n");
    printf("Would you like to customize your simulation or use a template? Enter Y to use a template or N to customize: ");
    fgets(menu, sizeof(menu), stdin);
    if (menu[0] == 'Y'|| menu[0] == 'y'){
        template(initial_capital, risk_tolerance, difficulty_level, duration,algorithm);
    }

    printf("Please specify the difficulty level for this simulation on a scale of 1-4 with 5 being the highest. \n");
    printf("To mirror this value to the experience level based off your profile enter 0: ");
    scanf("%d", &difficulty_level);
    if (difficulty_level== 0){
        difficulty_level = user->experience;
    }
    while (difficulty_level<1 || difficulty_level>4){
        printf("\n");
        printf("Please re-enter the difficulty or hit enter to use the default: ");
        scanf("%d", &difficulty_level);
        while (getchar() != '\n');  // Clear buffer after scanf
    }
    printf("\n");
    printf("Please specify your initial capital as a dollar amount WITHOUT commas: $");
    scanf("%f", &initial_capital);
    while (getchar() != '\n');  // Clear buffer after scanf
    // check for realism
    while (initial_capital<=1000000){
        printf("Please re-enter a valid initial (must be greater than $1 million dollars): $");
        scanf("%f", &initial_capital);
        while (getchar() != '\n');  // Clear buffer after scanf
    }
    if (initial_capital>=50000000){
        printf("Please note that this amount, while acceptable for the simulation, does not reflect realisitic practices.\n");
        printf("Do you wish to re-enter a different intial capital? ");
        fgets(menu, sizeof(menu), stdin);
        if (menu[0] == 'Y'|| menu[0] == 'y'){
            printf("Please re-enter a valid initial (must be greater than $1 million dollars): $");
            scanf("%f", &initial_capital);
        }
    }

    printf("\n");
    printf("Please specify a duration in months: ");
    scanf("%d", &duration);

    // check for realism
    while (duration<=0){
        printf("Please re-enter a valid duration (must be greater than 0) in months: ");
        scanf("%d", &duration);
    }
    if (duration<=3 || duration>=120){
        printf("Please note that this duration, while acceptable for the simulation, does not reflect realisitic practices.\n");
        printf("Most hedge fund investments last between 6 months and 10 years.\n");
        printf("Do you wish to re-enter a different duration? ");
        fgets(menu, sizeof(menu), stdin);
        if (menu[0] == 'Y'|| menu[0] == 'y'){
            printf("Please re-enter a valid duration (must be greater than 0) in months: ");
            scanf("%d", &duration);
        }
  
    printf("\n");
    printf("Please specify an asset allocation in percentages for stocks, bonds, and annuities with commas seperating each value: ");
    while (getchar() != '\n');
    scanf("%f %f %f", &asset_allocation.stocks, &asset_allocation.bonds, &asset_allocation.annuities);
    printf("\n");
    while (getchar() != '\n'); // clear the buffer
    }
    /*
    Conservative Portfolio (Low Risk)
Stocks: 30–50%

Bonds: 40–60%

Annuities: 10–20%

Designed for capital preservation with lower volatility.

Balanced Portfolio (Moderate Risk)
Stocks: 50–70%

Bonds: 20–40%

Annuities: 10–15%

A mix of growth and stability for medium-term investors.

Aggressive Portfolio (High Risk)
Stocks: 70–90%

Bonds: 10–20%

Annuities: 0–10%

Optimized for maximum growth potential but higher volatility.

Ultra-Aggressive Portfolio (High Volatility)
Stocks: 90–100%

Bonds: 0–10%

Annuities: 0%
    */
    // regression analysis, Merger Arbitrage (Risk Arbitrage), Convertible Arbitrage, Fixed-Income Arbitrage
    printf("Please select an agorithm: \n");
    fgets(algorithm, sizeof(algorithm), stdin);

    // display the output
    system("clear"); // clear the screen
    printf("**Your results are as follows** \n");

    printf("Total Return: 15\n");
    printf("Annualized Return: 6\n");
    printf("Volatility: 8.5\n");
    printf("Sharpe Ratio: .75\n");
    printf("Max Drawdown: 15\n");

    printf("\n");
    printf("Enter R to run the simulation again or B to go back to the Activities Menu: ");
    fgets(menu, sizeof(menu), stdin);
    if (menu[0] =='B'|| menu[0]== 'b'){
        return;
    }

    if (menu[0] == 'R' || menu[0] =='r')
    {
        goto sim;
    }
    
}

  /*
    Performance Summary
    - Total Return: Final portfolio value vs. initial capital.
    -  Annualized Return: Adjusted for the length of the     simulation.
    - Volatility: standard deviation of returns   
    - Sharpe Ratio: return per unit of risk.
    - Max Drawdown: difference between highest and lowest value.    

    Algorithm Behavior Analysis
    - Strategy Overview: Brief explanation of the selected algorithm’s logic.
    - Notable Decisions: Key trades during the simulation.
    - Behavior vs. Risk Tolerance (risk analysis) 

    */