function m = tor(r1, r2)
  l = [-pi:0.4:pi+0.2];
  l = repmat(l, 1, 5);
  l = reshape(l, [], 5);
  #l = reshape(l, [], 4)';
  x = ((ones(17, 5) .* cos(l)*r1) .* [1 2 3 2 1])';
  y = ((ones(17, 5) .* sin(l)*r1) .* [1 2 3 2 1])';
  z = (zeros(17, 5) + [0 1 0 -1 0])';
  #plot3(x, y, z, '-.')
  #surf(x, y, z, 'FaceAlpha', 0.2)
  surf(x, y, z, 'FaceAlpha', 0.2, 'FaceColor', 'interp')
  pbaspect([1 1 1])
  xlabel('cos(x)');
  ylabel('sin(y)');
  zlabel('ring z');
  grid on
end

