
#include <casadi/core/function.hpp>
#include <casadi/core/mx.hpp>
#include <casadi/core/nlpsol.hpp>
#include <casadi/core/serializing_stream.hpp>
#include <casadi/core/sparsity_interface.hpp>
#include <iostream>
#include <casadi/casadi.hpp>
#include <vector>


int main(){


  auto x = casadi::MX::sym("x",1);
  auto y = casadi::MX::sym("y", 1);
  auto z = casadi::MX::vertcat(std::vector<casadi::MX>{x,y});

  auto f = 2*x+3*y;

  auto g = vertcat(std::vector<casadi::MX>{x+y,x,y});

  casadi::MXDict nlp = {{"x", z}, {"f", f}, {"g", g}};
  
  auto solver = casadi::nlpsol("solver","highs",nlp);



  // Bounds on g
  std::vector<double> gmin = {0, -1,-1};
  std::vector<double> gmax = {5, 1,1};
  // Solve the problem
  casadi::DMDict arg = {
      {"lbx", -10}, {"ubx", 10}, {"x0", 0.4}, {"lbg", gmin}, {"ubg", gmax}};
  auto res = solver(arg);
  }
