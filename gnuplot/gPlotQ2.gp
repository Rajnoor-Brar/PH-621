set title 'Restricted Range'
set grid mxtics mytics my2tics
set xlabel 'The Xis'
set xlabel 'The Xis'
set ylabel 'The Blexis y1(x)'
set y2label 'The Reddix y2(x)'
set xrange [200:800]
set yrange [*:*] writeback
set y2range [*:*] writeback
set term qt
set output "q2_zoom.png"
pl 'slopey.txt' u 1:2 title 'Blexis' w l lc 'blue' dt 1, 'slopey.txt' u 1:3 title 'Reddix' w l lc 'red' dt 2
