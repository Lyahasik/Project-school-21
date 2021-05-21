.name       "Begin"
.comment    "What's going on here?"

loop:
	sti r1, %100, %2
	zjmp %100
	live %100
	zjmp %:loop
