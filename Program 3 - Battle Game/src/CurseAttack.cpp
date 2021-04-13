#include "CurseAttack.hpp"

void CurseAttack::Execute()
{
	cout << "\n-" << damage << " Damage";
	other->Hit(damage);
}

void CurseAttack::Undo()
{
	cout << "\n+" << damage << " Heal";
	other->Heal(damage);
}

