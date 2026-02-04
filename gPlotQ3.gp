set title "Difference Plot"
set xlabel "x"
set ylabel "y2-y1"

set term png
set output "q3_difference.png"

pl "slopey.txt" u 1:($2-$3) w lp title "y2-y1 (x)"
