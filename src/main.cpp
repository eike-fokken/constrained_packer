
#include <casadi/casadi.hpp>
#include <iostream>
#include <vector>

int main() {

  auto x = casadi::MX::sym("x", 1);
  auto y = casadi::MX::sym("y", 1);
  auto z = casadi::MX::vertcat({x, y});

  auto f = -(2 * x + 3 * y);

  auto g = casadi::MX::vertcat({x + y, x, y});

  casadi::MXDict lp = {{"x", z}, {"f", f}, {"g", g}};

  casadi::Dict options;

  std::vector<bool> discrete = {true, true};
  // std::vector<bool> discrete = {};
  options["discrete"] = discrete;

  auto solver = casadi::qpsol("solver", "highs", lp, options);

  // Bounds on g
  std::vector<double> gmin = {0, -4.5, -4.5};
  std::vector<double> gmax = {5, 4.5, 4.5};
  // Solve the problem
  casadi::DMDict solver_arguments
      = {{"lbx", -10}, {"ubx", 10}, {"x0", 0.4}, {"lbg", gmin}, {"ubg", gmax}};
  auto res = solver(solver_arguments);

  std::cout << "x: " << res["x"] << std::endl;
  std::cout << "f: " << res["f"] << std::endl;
  std::cout << "g: " << res["g"] << std::endl;
}
