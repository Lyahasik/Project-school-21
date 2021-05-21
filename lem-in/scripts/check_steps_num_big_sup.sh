rm graph;

echo ""
echo "INPUT NUMBER OF TRIALS"
read TRIALS
echo ""

FLAGS[0]="--flow-one"
FLAGS[1]="--flow-ten"
FLAGS[2]="--flow-thousand"
FLAGS[3]="--big"
FLAGS[4]="--big-superposition"

I=4;
while [ "$I" -lt 5 ]; do
	OK=0;
	SUM=0;
	COUNT=$TRIALS;
	while [ "$COUNT" -gt 0 ]; do
		./gen ${FLAGS[$I]} > graph
		AWAITED_RESULT=$(cat graph | grep -m 1 "Here is the" | awk '{print $8}');
		REAL_RESULT=$(cat graph | ./lem-in | wc -l | awk '{print $1}');
		let "DELTA = REAL_RESULT - AWAITED_RESULT";
		if [[ "$DELTA" -lt  3 ]]; then
			((OK++));
			let "SUM = SUM + DELTA";
		fi
		((COUNT--));
	done
	echo "RAN ${FLAGS[$I]} $TRIALS times"
	echo "OK $OK times"
	echo "SUM = $SUM"
	echo ""
	((I++));
done

