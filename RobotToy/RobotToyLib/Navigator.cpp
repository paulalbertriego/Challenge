#include "pch.h"
#include "Navigator.h"

string Navigator::toString(Direction direction) const
{
    for (const auto& directionData : directions)
    {
        if (directionData.Value == direction)
            return directionData.StringValue;
    }
    throw exception("Direction Not Found");
}

int Navigator::toInt(Direction direction) const
{
    for (const auto& directionData : directions)
    {
        if (directionData.Value == direction)
            return directionData.IntValue;
    }
    throw exception("Direction Not Found");
}

Direction Navigator::stringToDirection(const string& t_stringValue)
{
    for (const auto& directionData : directions)
    {
        if (directionData.StringValue == t_stringValue)
            return directionData.Value;
    }
    throw exception("Direction Not Found");
}

Direction Navigator::intToDirection(int t_intValue) const
{
    for (const auto& directionData : directions)
    {
        if (directionData.IntValue == t_intValue)
            return directionData.Value;
    }
    throw exception("Direction Not Found");
}

Direction Navigator::rotate(Direction t_direction, int t_moveDirection)
{
    int direction = toInt(t_direction);
    
    if (direction < 0)
        throw out_of_range("Rotation Direction out of bounds");

    switch (t_moveDirection)
    {
        case ROTATE_LEFT:
            direction--;
            if (direction < 0)
            {
                return Direction::WEST;
            }
            break;
        case ROTATE_RIGHT:
            direction++;
            if (direction > 3)
            {
                return Direction::NORTH;
            }
            break;
        default:
            throw exception("Invalid Rotation");
    }
    return intToDirection(direction);
}
