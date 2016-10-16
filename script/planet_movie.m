clear;
close all;

% parameters.
orbits = 4; % Number of planets.
max_points = 10; % Maximum number of plot points.
range = [1, 1]; % Used for determine the number of points.
x_col = 2; % Which column contains the x data.
y_col = 3; % Which column contains the y data.
z_col = 4; % Which column contains the z data.

% read input.
input = load('../build/Debug/movie');
[rows, cols] = size(input);

% define data points.
points = rows / orbits;

% load orbital data.
orbit_x_data = zeros(orbits, points);
orbit_y_data = zeros(orbits, points);
orbit_z_data = zeros(orbits, points);

% translate data.
for i=1:points
  for j=1:orbits
    orbit_x_data(j, i) = input((i-1)*orbits + j, x_col);
    orbit_y_data(j, i) = input((i-1)*orbits + j, y_col);
    orbit_z_data(j, i) = input((i-1)*orbits + j, z_col);
  end
end

filename = 'testnew.gif';
% start recording movie.
for i=1:points
  range(2) = i;
  if ((range(2) - range(1)) > max_points)
    range(1) = range(1) + 1;
  end
  r = range(1):1:range(2);
  f = figure('visible', 'off');
  hold on;
  plot3(orbit_x_data(1,r), orbit_y_data(1,r), orbit_z_data(1,r), 'r');
  plot3(orbit_x_data(2,r), orbit_y_data(2,r), orbit_z_data(2,r), 'g');
  plot3(orbit_x_data(3,r), orbit_y_data(3,r), orbit_z_data(3,r), 'b');
  plot3(orbit_x_data(4,r), orbit_y_data(4,r), orbit_z_data(4,r), 'k');
  axis([-3 3 -3 3]);
  
  F(i) = getframe(gca);
  im = frame2im(F(i));
  [imind,cm] = rgb2ind(im,256);
  
  if i == 1;
    imwrite(imind,cm,filename,'gif', 'Loopcount',inf);
  else
    imwrite(imind,cm,filename,'gif','WriteMode','append');
  end
  
  close(f);
end