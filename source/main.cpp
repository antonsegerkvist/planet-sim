//
//  main.cpp
//  Planet Simulator
//
//  Created by Anton Segerkvist on 14/10/16.
//  Copyright © 2016 anton segerkvist. All rights reserved.
//

#include <iostream>
#include "planet.hpp"
#include "planet_context.hpp"

int main(int argc, const char * argv[]) {
  
  PlanetContext<double> context(0.001);
  
  context.addPlanet(Planet<double>(1, 0, 0, 0));
  context.addPlanet(Planet<double>(1, 1, 0, 0));
  context.addPlanet(Planet<double>(1, 0, 1, 0));
  context.addPlanet(Planet<double>(1, 0, 0, 1));
  
  context.updateEuler(0.01);
  context.print();
}
