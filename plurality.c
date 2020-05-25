//Include data from these libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Max number of candidates is 9
#define MAX 9

// Candidate name and vote count struct//
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes (These show up later)
bool vote(string name);
void print_winner(void);

/////////////////////////////////////////////////////////////

//Main body of code, command line argument counter and vector
int main(int argc, string argv[])
{
    //Check for invalid usage (if less than 1 name)
    if (argc < 2)
    {
        //Print error 1
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    //Make candidate count match the number of names in the command line.
    candidate_count = argc - 1;

    //If candidate count is over 9
    if (candidate_count > MAX)
    {
        //Print error 2
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    //For loop going up to the candidate_count
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    //Prompt for number of voters
    int voter_count = get_int("Number of voters: ");

    //For loop over the number of voters
    for (int i = 0; i < voter_count; i++)
    {
        //Prompt for vote
        string name = get_string("Vote: ");

        //Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}
/////////////////////////////////////////////////////

// Update vote totals given a new vote
bool vote(string name)
{
    //Scan through the candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        //Use strcmp to compare input candidate name with the one in the struct
        int match = strcmp(candidates[i].name, name);

        //If the result is a match
        if (match == 0)
        {
            //vote + 1
            candidates[i].votes++;
            printf("%s + 1\n", candidates[i].name);
            return true;
        }
    }
    //Otherwise
    return false;
}

////////////////////////////////////////////////

// Print the winner (or winners) of the election
void print_winner(void)

{
    //Create an int called winner
    int winner = 0;

    //Scan through array of candidate counts
    for (int i = 0; i < candidate_count; i++)
    {
        //If candidates votes is > winner
        if (candidates[i].votes > winner)
        {
            //bigger candidate becomes new value for winner
            winner = candidates[i].votes;
        }
    }

    //Scan through array of candidate counts
    for (int i = 0; i < candidate_count; i++)
    {
        //If candidates votes is == winner
        if (candidates[i].votes == winner)
        {
            //Output
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
