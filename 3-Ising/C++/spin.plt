set terminal gif animate delay 10
set output "output/gif/spin.gif"
stats "output/dat/spin.dat" name "A"
#set xrange [A_min_x:A_max_x]
#set yrange [A_min_y:A_max_y]
set autoscale fix
set palette defined (-1 'red',1'blue')
unset label
unset key 
unset tics
unset colorbox
set size square
set title "Spin dynamics"
do for [i=0:int(A_blocks-1)]{plot "output/dat/spin.dat" index i matrix with image notitle}