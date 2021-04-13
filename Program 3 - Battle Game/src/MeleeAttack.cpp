#include "MeleeAttack.hpp"

void MeleeAttack::Execute()
{
	cout << "\n-" << damage << " Damage";
	other->Hit(damage);
}

void MeleeAttack::Undo()
{
	cout << "\n+" << damage << " Heal";
	other->Heal(damage);
}
