set title 'y2 v y3'
set xlabel 'y2'
set ylabel 'y3'
set size square
set term png
set output "q5_phase.png"
pl 'slopey.txt' u 2:3 w l title 'y3(y2)'
