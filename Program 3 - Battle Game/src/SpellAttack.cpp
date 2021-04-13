#include "SpellAttack.hpp"

void SpellAttack::Execute()
{
	cout << "\n-" << damage << " Damage";
	other->Hit(damage);
}

void SpellAttack::Undo()
{
	cout << "\n+" << damage << " Heal";
	other->Heal(damage);
}
