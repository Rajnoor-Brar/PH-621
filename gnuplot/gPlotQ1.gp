set title 'Red and Blue'
set grid
set xlabel 'The Xis'
set xlabel 'The Xis'
set ylabel 'The Blexis'
set y2label 'The Reddix'

set term qt
set output "q1overlay.png"
pl 'slopey.txt' u 1:2 title 'Blexis' w l lc 'blue' dt 1, 'slopey.txt' u 1:3 title 'Reddix'  w l lc 'red' dt 2

