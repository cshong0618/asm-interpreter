	TTL test
	AREA program, PROGRAM, READONLY
	ENTRY
Main
	LDR R0, =a
	MOV R1, #0
	STR R1, [R0], #4
	STR R1, [R0], #4
	STR R1, [R0], #4
Here	BAL Here

	AREA data, DATA, READWRITE
a	DCD 3, 2, 1, -1
