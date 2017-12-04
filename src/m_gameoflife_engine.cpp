#include "m_gameoflife_engine.h"

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

namespace GameOfLife {

namespace {

bool inRange(int val, int max, int min = 0)
{
    return val >= min && val < max;
}

void updateLine(Grid::Line& line, int center, bool updateCenter)
{
    if (center - 1 >= 0) ++line[center - 1];
    if (center + 1 < line.size()) ++line[center + 1];
    if (updateCenter) ++line[center];
}

void updateNeighbourhood(Grid::World& neighbours, int x, int y)
{
    if (y - 1 >= 0) updateLine(neighbours[y -1], x, true);
    if (y + 1 < neighbours.size()) updateLine(neighbours[y + 1], x, true);
    updateLine(neighbours[y], x, false);
}

}


Grid::Grid(int width, int height)
: d_world(height, Line(width, 0))
, d_neighbours(d_world)
{
    init();
}

void Grid::init()
{
    std::srand(std::time(0));
    for (auto& line : d_world) {
        for (auto& value : line) {
            value = std::rand() % 2 == 0 ? 1 : 0;
        }
    }
}

const Grid::World& Grid::getWorld()
{
    return d_world;
}

void Grid::updateWorld()
{
	updateNeighbours();
	updateGrid();
}

void Grid::updateNeighbours()
{
    for (auto& line : d_neighbours) { for (auto& v : line) { v = 0; } }
    for (int y = 0; y < d_world.size(); ++y) {
        const auto& line = d_world[y];
        for (int x = 0; x < line.size(); ++x) {
            if (line[x] == 0) continue;
            updateNeighbourhood(d_neighbours, x, y);
        }
    }
}

void Grid::updateGrid()
{
    for (int y = 0; y < d_neighbours.size(); ++y) {
        const auto& nLine = d_neighbours[y];
        auto& wLine = d_world[y];
        for (int x = 0; x < nLine.size(); ++x) {
            if ((nLine[x] < 2 || nLine[x] > 3)
                && wLine[x] == 1) {
                wLine[x] = -3;
            } else if (nLine[x] == 3) {
                wLine[x] = wLine[x] == 0 ? 4 : 1;
            }
        }
    }
}

} // closing project namespace

