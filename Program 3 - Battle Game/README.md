# Battle Game

Goals:
  Use polymorphism to create different game characters that will Battle
  Preserve history by implementing the Stack ADT and the command pattern

Overview:
  You will create a small game which will allow you to battle a character against the computer's character. 
  Each character will have several moves, and you and the computer will take turns attacking each other. 
  A battle will end when either your character or your opponent's life gets down to 0.

# Classes:

 Game 
 ----------
 This class will have a loop which allows you to either start a battle or exit. If you choose to start a battle, there will be a menu to select your character and your opponent's character. Those will be passed into the Battle object's constructor to seed a battle, and the battle will start (more details below). 

 Actor
 ----------
 Actor will be the base class for any characters. 
    
 Actor will have a Hit method which takes 'damage' as the parameter. This will be an integer value that will be subtracted from the health

 To support undoable moves, there will also be a Heal method which will heal damage that was done by a move (add the 'damage' back to health)

  
  ActorFactory
  ----------
  
  Besides Actors we need to have BattleMoves which will be the undoable commands that perform some damage to an opponent. An actor will have a list of MoveType's which it can perform (could be a vector)

  BattleMove
  ----------
  

  For an implementation of a concrete battle move, generate a random number (ranges listed below) and call hit on other (other->Hit(damage)) to apply the damage. Save the actual damage done so that an Undo can do other->Heal(damage) to reverse the damage.

  Similarly to how the Actors are built using a factory we will also use a factory to build moves. Anyone looking to create a battle move just needs to know the enum for that move and pass it to the factory:


  The battle moves will be built during a battle by the Battle class using the above factory when the player chooses their move or when the computer randomly picks one.

  CommandManager
  ----------
  To manage moves in a battle, a CommandManager will be built.
  This class will have a Stack to store moves. 


  Battle
  ------

  A battle should take care of the logic of handling menu options for a user's input as well as building the BattleMoves using the BattleMoveFactory and executing them via an CommandManager. When the player selects Undo, the last TWO commands should be undone (so player 1 move and player 2 move). The battle should go on until either the player or the computer go down to a health of 0


  It helps to be able to convert enums to strings for the sake of printing them to the console. Also to make the game fun, we need to be able to generate random integers easily (for damage values and for the NPC turn logic). 


  During a battle, the player controls player1. For player 2, pick a random number between 0 and the size of the moves vector for that player and use that as the move (not a very clever AI, but good enough for this game)
