set terminal gif animate delay 10
set output "output/gif/points.gif"
stats "output/dat/points.dat" name "A"
set xrange [A_min_x:A_max_x]
set yrange [A_min_y:A_max_y]
unset label
set title "Molecular Dynamic"
do for [i=0:int(A_blocks-1)]{plot "output/dat/points.dat" index i pt 7 ps 0.5 lc "red" notitle}