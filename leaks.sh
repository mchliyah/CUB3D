while [ 1 ]
do
	leaks cub3 | grep bytes
	sleep 2
	clear
done