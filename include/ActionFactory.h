/*
* Created by tom on 16/11/18.
**/

#ifndef ASS1_ACTIONFACTORY_H
#define ASS1_ACTIONFACTORY_H

#include <include/Action.h>

class LimitedFactory
{
    public :
    /// Generates an action from the line typed in.
    ///
    /// \param actionLine The line inserted by the user
    /// \return The action the user requested
    BaseAction* generateAction(std::string actionLine);
};
#endif //ASS1_ACTIONFACTORY_H
