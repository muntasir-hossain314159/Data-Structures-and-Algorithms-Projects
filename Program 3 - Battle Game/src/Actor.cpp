#include "Actor.hpp"

ostream& operator<<(ostream& out, const Actor& actor)
{
    out << actor.type;
    return out;
}
