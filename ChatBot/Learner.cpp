#include "Learner.h"
#include <iostream>
#include <fstream>

using namespace std;
/*
    The following function will look for the passed phrase in the memory file.
    If there is a match, the accompanying response, stored below the initial phrase,
    will be outputed.
    If the response cannot be found, the learner will repeat the phrase, and prompt
    the user to enter an ideal response. This response will be stored in the memory
    file along with the initial phrase.
*/
void Learner::respond(string phrase){
    fstream memory;     //create a file stream object and in the next step, assign the memory file.
    memory.open("memory/memory.txt", ios::in);    // Open the memory file for input (ios::in is for reading)

    // Search through the file until the end is reached
    while( !memory.eof() ){    // While not at end of file
        string identifier;
        getline(memory,identifier);    // Get next phrase in the variable names 'identifier'

        if(identifier == phrase){    // Is it the phrase we are looking for [ check if current phrase matched the user phrase ]
            string response;
            getline(memory,response);   // If so, get the response
            voice.say(response);   // Textually and audibly output the response!
            return;    // Leave the function
        }
    }

    memory.close();    // Looks like we couldn't find the phrase in memory. Close the file!
    memory.open("memory/memory.txt", ios::out | ios::app);    // Now open for output i.e. program to file , and append at end of file
    memory << phrase << endl;    // Record initial phrase in memory

    voice.say(phrase);   // Repeat the phrase the user entered
    string userResponse;
    cout << "YOU: ";
    getline(cin, userResponse);    // Get the ideal response
    memory << userResponse << endl;    // Write the ideal response to memory
    memory.close();    // Close the file!
}

/*
    This function simply communicates a phrase textually and audibly
*/
void Learner::say(string phrase){
    this->voice.say(phrase);
}
