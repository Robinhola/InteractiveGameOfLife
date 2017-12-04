#ifndef M_GAMEOFLIFE_ENGINE_H
#define M_GAMEOFLIFE_ENGINE_H

#include <vector>

namespace GameOfLife {

class Grid {
  public:
    using Line  = std::vector<int>;
    using World = std::vector<Line>;

  private:
    World d_world;
    World d_neighbours;

    void updateGrid();
    void updateNeighbours();
    void updateWorld();

  public:
    Grid(int width, int height);

    const World& getWorld();

    void init();
    void run();
    void stop();
};

} // closing project namespace

#endif

