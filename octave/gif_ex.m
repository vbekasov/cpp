function gif_ex()
  x = 0:0.01:1;
  
  filename    = 'elec.gif';
  DelayTime = 0.5;
  f = figure;
  
  for n = 1:0.5:5
    y = x.^n;
    plot(x,y)
    title('FirstGIF', "fontsize", 16)
    drawnow
    frame = getframe(f);
    im = frame2im(frame);
    [imind,cm] = rgb2ind(im);
    if n == 1;
      imwrite(imind,cm,filename,'gif','DelayTime', DelayTime , 'Compression' , 'lzw');
    else
      imwrite(imind,cm,filename,'gif','WriteMode',
      'append','DelayTime', DelayTime , 'Compression' , 'lzw');
    end
  end
  
end
# https://electroagenda.com/en/create-gif-files-in-octave-and-matlab/
