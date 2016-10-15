//
//  physics.hpp
//  planet_simulator
//
//  Created by Anton Segerkvist on 14/10/16.
//  Copyright © 2016 anton segerkvist. All rights reserved.
//

#ifndef physics_hpp
#define physics_hpp

#include <vector>
#include "planet_math_3d.hpp"
#include "planet_context_3d.hpp"
#include "planet_vector_3d.hpp"
#include "planet_typedef_3d.hpp"

namespace Planet
{

template <typename _type> class Physics3D;
template <typename _type> class Context3D;

template <typename _type>
class Physics3D
{
public:
  
  /**
   * Update the planetary context using the Euler method.
   * @param context The context to update.
   * @param time The time to update by.
   */
  static void UpdateEuler(Context3D<_type>& context, _type time);
  
  /**
   * Update the planetary context using Heun's method.
   * @param context The context to update.
   * @param time The time to update by.
   */
  static void UpdateHeun(Context3D<_type>& context, _type time);
  
  /**
   * Update the planetary context using the Runge-Kutta mathod.
   * @param context The context to update.
   * @param time The time to update by.
   */
  static void UpdateRungeKutta(Context3D<_type>& context, _type time);
  
private:
  
  /**
   * Convinient function for calculating all gravity terms.
   * @param buffer The position to save all acceleration values at.
   * @param masses The masses of the individual planets.
   * @param planets The position data of all the planets.
   */
  static void GravityFunction(Vector3DVector<_type>& buffer,
                              const std::vector<_type>& masses,
                              const Vector3DVector<_type>& planets);

};

template <typename _type>
/* static */ void Physics3D<_type>::UpdateEuler(Context3D<_type>& context, _type time)
{
  // Create buffer.
  Vector3DVector<_type> buffer;
  
  // Calculate the gravity functions.
  GravityFunction(buffer, context.m_mass, context.m_position);
  
  // Update the planets.
  for(size_t i=0; i<context.m_mass.size(); ++i)
  {
    context.m_position[i] = context.m_position[i] + context.m_velocity[i] * time;
    context.m_velocity[i] = context.m_velocity[i] + buffer[i] * time;
  }
}
  
template <typename _type>
/* static */ void Physics3D<_type>::UpdateHeun(Context3D<_type>& context, _type time)
{
  // Create buffers.
  Vector3DVector<_type> buffer1;
  Vector3DVector<_type> buffer2;
  Vector3DVector<_type> buffer3;
  
  // Fill the buffers.
  buffer1.resize(context.m_position.size());
  GravityFunction(buffer2, context.m_mass, context.m_position);
  
  for(size_t i=0; i<context.m_position.size(); ++i)
  {
    buffer1[i] = context.m_position[i] + buffer2[i] * time;
  }
  
  GravityFunction(buffer3, context.m_mass, buffer1);
  
  // Update the planets.
  for(size_t i=0; i<context.m_mass.size(); ++i)
  {
    context.m_position[i] = context.m_position[i] + context.m_velocity[i] * time;
    context.m_velocity[i] = context.m_velocity[i] + (time / 2.0) * (buffer2[i] + buffer3[i]);
  }
}
  
template <typename _type>
/* static */ void Physics3D<_type>::UpdateRungeKutta(Context3D<_type>& context, _type time)
{
  // Create buffers.
  Vector3DVector<_type> buffer1;
  Vector3DVector<_type> buffer2;
  Vector3DVector<_type> buffer3;
  Vector3DVector<_type> buffer4;
  Vector3DVector<_type> buffer5;
  
  // Fill the buffers.
  buffer1.resize(context.m_position.size());
  GravityFunction(buffer2, context.m_mass, context.m_position);
  
  for(size_t i=0; i<context.m_position.size(); ++i)
  {
    buffer1[i] = context.m_position[i] + buffer2[i] * (time * 2);
  }
  
  GravityFunction(buffer3, context.m_mass, buffer1);
  
  for(size_t i=0; i<context.m_position.size(); ++i)
  {
    buffer1[i] = context.m_position[i] + buffer3[i] * (time * 2);
  }
  
  GravityFunction(buffer4, context.m_mass, buffer1);
  
  for(size_t i=0; i<context.m_position.size(); ++i)
  {
    buffer1[i] = context.m_position[i] + buffer4[i] * time;
  }
  
  GravityFunction(buffer5, context.m_mass, buffer1);
  
  // Update the planets.
  for(size_t i=0; i<context.m_mass.size(); ++i)
  {
    context.m_position[i] = context.m_position[i] + context.m_velocity[i] * time;
    context.m_velocity[i] = context.m_velocity[i] +
                            (time / 6.0) * (buffer2[i] + buffer3[i] * 2 + buffer4[i] * 2 + buffer5[i]);
  }
}

template <typename _type>
/* static */ void Physics3D<_type>::GravityFunction(Vector3DVector<_type>& buffer,
                                                    const std::vector<_type>& masses,
                                                    const Vector3DVector<_type>& planets)
{
  // Define stack data.
  Vector3D<_type> k;
  
  // Resize the buffer.
  buffer.resize(planets.size());
  
  // Calculate the gravitational functions.
  for(size_t i=0; i<planets.size(); ++i)
  {
    // Reset stack.
    k = Vector3D<_type>(0, 0, 0);
    
    // Loop over all the planets and fill the buffer.
    for(size_t j=0; j<planets.size(); ++j)
    {
      // Don't include it self.
      if(i == j) continue;
      
      // Calculate components.
      Vector3D<_type> diff = planets[j] - planets[i];
      _type mass           = masses[j];
      _type norm_3         = pow(TwoNorm(diff), 3);
      
      // Update buffer.
      k += mass * diff / norm_3;
    }
    
    buffer[i] = k;
  }
}
  
};

#endif /* physics_hpp */
