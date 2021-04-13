#pragma once
#include "UndoableCommand.hpp"
#include "Stack.hpp"

using namespace std;

class CommandManager
{
private:
    Stack<UndoableCommand*> stack;

public:
    CommandManager() :stack{ Stack<UndoableCommand*>(100) } {}
    void ExecuteCommand(UndoableCommand* command);
    void UndoCommand();
    ~CommandManager();
};
