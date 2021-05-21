rm graph;

echo ;
echo ;

COUNT=3;
while [ "$COUNT" -gt 0 ]; do
	echo "Flag --BIG trial"
	./gen --big > graph
	time ./lem-in < graph > /dev/null
	echo ;
	echo ;
	((COUNT--));
done

COUNT=3;
while [ "$COUNT" -gt 0 ]; do
	echo "Flag --BIG-SUPERPOSITION trial"
	./gen --big-superposition > graph
	time ./lem-in < graph > /dev/null
	echo ;
	echo ;
	((COUNT--));
done
