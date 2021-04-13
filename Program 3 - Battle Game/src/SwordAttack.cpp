#include "SwordAttack.hpp"

void SwordAttack::Execute()
{
	cout << "\n-" << damage << " Damage";
	other->Hit(damage);
}

void SwordAttack::Undo()
{
	cout << "\n+" << damage << " Heal";
	other->Heal(damage);
}
