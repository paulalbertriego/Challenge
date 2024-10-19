#include <stdexcept>
#include "Navigator.h"
#include <iostream>

Navigator::Navigator(Direction t_direction, int t_moveDirection)
    : m_direction(t_direction), m_moveDirection(t_moveDirection) {}

int Navigator::getDirectionIntValue()
{
    for (const auto& pair : directions)
    {
        if (pair.second == m_direction)
            return pair.first;
    }
    return -1;
}

void Navigator::rotate()
{
    int direction = getDirectionIntValue();
    
    if (direction < 0)
        throw out_of_range("Rotation Direction out of bounds");

    switch (m_moveDirection)
    {
        case ROTATE_LEFT:
            direction--;
            if (direction < 0)
            {
                m_direction = Direction::WEST;
                return;
            }
            break;
        case ROTATE_RIGHT:
            direction++;
            if (direction > 3)
            {
                m_direction = Direction::NORTH;
                return;
            }
            break;
        default:
            break;
    }

    m_direction = directions[direction];
}

Direction Navigator::getDirection() const
{
    return m_direction;
}
