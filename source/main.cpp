//
//  main.cpp
//  planet_simulator
//
//  Created by Anton Segerkvist on 15/10/16.
//  Copyright © 2016 anton segerkvist. All rights reserved.
//

#include "../header/planet_context_3d.hpp"
#include "../header/planet_math_3d.hpp"
#include "../header/planet_physics_3d.hpp"
#include "../header/planet_planet_3d.hpp"
#include "../header/planet_typedef_3d.hpp"
#include "../header/planet_vector_3d.hpp"

int main(int argc, const char** argv)
{
  /*
  // Define parameters.
  double mass = 1.0;
  Planet::Vector3D<double> v1(0, 0, 0);
  Planet::Vector3D<double> v2(1, 0, 0);
  Planet::Vector3D<double> v3(0, 1, 0);
  Planet::Vector3D<double> v4(0, 0, 1);
  
  // Define contexts.
  Planet::Context3D<double> c1(0.001);
  Planet::Context3D<double> c2(0.001);
  Planet::Context3D<double> c3(0.001);
  
  // Context 1.
  c1.addPlanet(Planet::Planet3D<double>(mass, v1, v1));
  c1.addPlanet(Planet::Planet3D<double>(mass, v2, v1));
  c1.addPlanet(Planet::Planet3D<double>(mass, v3, v1));
  c1.addPlanet(Planet::Planet3D<double>(mass, v4, v1));
  Planet::Physics3D<double>::UpdateEuler(c1, 0.01);
  Planet::Physics3D<double>::UpdateEuler(c1, 0.01);
  Planet::Physics3D<double>::UpdateEuler(c1, 0.01);
  
  // Context 2.
  c2.addPlanet(Planet::Planet3D<double>(mass, v1, v1));
  c2.addPlanet(Planet::Planet3D<double>(mass, v2, v1));
  c2.addPlanet(Planet::Planet3D<double>(mass, v3, v1));
  c2.addPlanet(Planet::Planet3D<double>(mass, v4, v1));
  Planet::Physics3D<double>::UpdateHeun(c2, 0.01);
  Planet::Physics3D<double>::UpdateHeun(c2, 0.01);
  Planet::Physics3D<double>::UpdateHeun(c2, 0.01);
  
  // Context 3.
  c3.addPlanet(Planet::Planet3D<double>(mass, v1, v1));
  c3.addPlanet(Planet::Planet3D<double>(mass, v2, v1));
  c3.addPlanet(Planet::Planet3D<double>(mass, v3, v1));
  c3.addPlanet(Planet::Planet3D<double>(mass, v4, v1));
  Planet::Physics3D<double>::UpdateRungeKutta(c3, 0.01);
  Planet::Physics3D<double>::UpdateRungeKutta(c3, 0.01);
  Planet::Physics3D<double>::UpdateRungeKutta(c3, 0.01);
  
  // Print it all.
  c1.print();
  std::cout << "---" << std::endl;
  c2.print();
  std::cout << "---" << std::endl;
  c3.print();
  */
  
  double mass = 1.0;
  Planet::Vector3D<double> v1(+1, +0, +0);
  Planet::Vector3D<double> v2(-1, +0, +0);
  Planet::Vector3D<double> v3(+0, +1, +0);
  Planet::Vector3D<double> v4(+0, -1, +0);
  Planet::Context3D<double> c(0.8);
  
  c.addPlanet(Planet::Planet3D<double>(mass, v1, v3));
  c.addPlanet(Planet::Planet3D<double>(mass, v2, v4));
  c.addPlanet(Planet::Planet3D<double>(mass, v3, v2));
  c.addPlanet(Planet::Planet3D<double>(mass, v4, v1));
  
  c.print();
  for(int i=0; i<60*100; ++i)
  {
    Planet::Physics3D<double>::UpdateRungeKutta(c, 1.0 / 60.0);
    if(i % 20 > 0)
    {
      continue;
    }
    c.print();
  }
}
