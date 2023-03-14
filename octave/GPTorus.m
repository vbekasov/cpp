% Define the parameters of the animation
dt = 0.1; % Time step
tf = 5; % Final time
g = 9.8; % Acceleration due to gravity

% Define the initial position and velocity of the sphere
r0 = [0,0,10]; % Initial position of the sphere
v0 = [0,0,-20]; % Initial velocity of the sphere

% Define the radius of the sphere and the dimensions of the surface
r = 1; % Radius of the sphere
L = 20; % Length of the surface
W = 20; % Width of the surface

% Define the time array
t = 0:dt:tf;

% Initialize the position and velocity arrays
r = zeros(length(t),3);
v = zeros(length(t),3);

% Set the initial conditions
r(1,:) = r0;
v(1,:) = v0;

% Calculate the position and velocity at each time step
for i = 2:length(t)
    % Calculate the new position and velocity using the Verlet algorithm
    r(i,:) = r(i-1,:) + v(i-1,:)*dt + 0.5*[0,0,-g]*dt^2;
    v(i,:) = v(i-1,:) + 0.5*([0,0,-g] + [0,0,-g])*dt;

    % Check if the sphere has hit the surface
    if r(i,3) < r
        % If the sphere has hit the surface, set its z position and velocity to zero
        r(i,3) = r;
        v(i,3) = 0;
    end
end

% Create the animation
for i = 1:length(t)
    % Draw the sphere
    [x,y,z] = sphere;
    surf(x*r(i,1),y*r(i,2),z*r(i,3), 'EdgeColor', 'none');
    hold on;

    % Draw the surface
    surface([-L/2 L/2; -L/2 L/2], [-W/2 -W/2; W/2 W/2], [0 0; 0 0], 'FaceColor', 'g', 'EdgeColor', 'none');

    % Set the axes and view
    axis([-L/2 L/2 -W/2 W/2 0 r0(3)]);
    view(45,30);

    % Pause for a short time to create the animation effect
    pause(0.01);

    % Clear the plot for the next frame
    clf;
end


  