#include "mpel/builtins.hpp"
#include "mpel/core.hpp"
#include "mpel/visualization.hpp"

using namespace mpel;
namespace graph_builder = mpel::builtins::graph_builder;
namespace graph_search  = mpel::builtins::graph_search;
namespace interpolator  = mpel::builtins::interpolator;

int main()
{
    auto workspace   = Workspace::load_from_file("workspace/001.bmp");
    auto problem_def = ProblemDefinition(Point(0, 0), Point(50, 50));
    auto prm_planner = Planner(new graph_builder::None(),
                               new graph_search::None(),
                               new interpolator::None());
    /*
    auto prm_planner = Planner(new graph_builder::ProbabilisticRoadmap(),
                               new graph_search::AStar(),
                               new interpolator::PotentialField());
    */
    prm_planner.set_workspace(workspace);
    auto path = prm_planner.solve(problem_def);

    auto interp = interpolator::PotentialField(workspace);
    Path xpath;
    append(path, Point(0, 0));
    interp.interpolate(xpath);

    // Canvas(workspace).add_layer(problem_def).add_layer(path).show();
}