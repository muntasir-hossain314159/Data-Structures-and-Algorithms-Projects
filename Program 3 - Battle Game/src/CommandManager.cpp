#include "CommandManager.hpp"
#include "BattleMoveFactory.hpp"
#include <iostream>

void CommandManager::ExecuteCommand(UndoableCommand* command)
{
    command->Execute(); 
    stack.Push(command);
}

void CommandManager::UndoCommand()
{
    if (stack.IsEmpty()) 
    {
        cout << "\nNothing to undo";
        return;
    }
    UndoableCommand* command = stack.Top();
    command->Undo(); 
    delete stack.Top();
    stack.Pop();
}

CommandManager:: ~CommandManager()
{
    while (!stack.IsEmpty()) {
        delete stack.Top();
        stack.Pop();
    }
}
