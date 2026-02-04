#plot data file
set title "data file plot"
set key
set xlabel "x"
set ylabel "potential V(x)"
#pl 'slopey.txt' u 1:2 w l
#pl 'slopey.txt' u 1:2 w l title 'slope1', 'slopey.txt' u 1:3 w l title 'slope2' 
#pl 'slopey.txt' u 1:2 w l lc "red" title 'slope1',\
#   'slopey.txt' u 1:3 w l lc "blue" title 'slope2' 

pl 'slopey.txt' every 150 u 1:2 w lp pt 4 lw 2 lc "red"  title 'slope1' 
