function m = tor(r1 = 3, r2 = 2)
  l = [-pi:0.4:pi+0.2];
  l = repmat(l, 1, 5);
  l = reshape(l, [], 5);
  x = ((ones(17, 5) .*cos(l)*r1) .* [1 2 3 2 1])';
  y = ((ones(17, 5) .*sin(l)*r1) .* [1 2 3 2 1])';
  z = (zeros(17, 5)+(cos([-pi/2:pi/2:pi+pi/2])*r1+r1))';
  
  #plot3(x, y, z, '-.')
  surf(x, y, z, 'FaceAlpha', 0.2, 'FaceColor', 'interp')
  hold on
  plot3(0, 0, r1*6)
  pbaspect([1 1 1])
  xlabel('cos(x)');
  ylabel('sin(y)');
  zlabel('ring z');
  grid on
  hold off
end
