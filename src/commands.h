enum class Direction
{
    North = 8,
    South = 2,
    East = 6,
    West = 4
};

struct PlaceCommand
{
    PlaceCommand(int posX, int posY, Direction d):
        x(posX),
        y(posY),
        direction(d)
    {}

    int x = 0;
    int y = 0;
    Direction direction = Direction::North;
};