#ifndef LEARNER_H_INCLUDED
#define LEARNER_H_INCLUDED

#include <iostream>
#include <fstream>
#include "voice.h"

using namespace std;

/*  A learner will respond to phrases if it knows how to, and learn how, if it doesn't. */
class Learner {
public:
    void respond(string phrase);    // Used to get, or teach a response
    void say(string phrase);    // Used to textually and audibly communicate a phrase

    Voice voice;    // The learner's voice that will audibly communicate a response
};
#endif // LEARNER_H_INCLUDED
