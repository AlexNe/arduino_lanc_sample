# Arduino LANC sample
Arduino camera remote control (LANC interface)

Normal command | Type:(BIN 00101000 | DEC 40 | HEX 28)

	DEC	BIN	HEX CODE_NAME
	0	00000000	0	variable speed zoom Tele: slowest speed
	2	00000010	2	variable speed zoom Tele: faster than 00
	4	00000100	4	variable speed zoom Tele: faster than 02
	6	00000110	6	variable speed zoom Tele: faster than 04
	8	00001000	8	variable speed zoom Tele: faster than 06
	10	00001010	0A	variable speed zoom Tele: faster than 08
	12	00001100	0C	variable speed zoom Tele: faster than 0A
	14	00001110	0E	variable speed zoom Tele: fastest speed
	16	00010000	10	variable speed zoom Wide: slowest speed
	18	00010010	12	variable speed zoom Wide: faster than 10
	20	00010100	14	variable speed zoom Wide: faster than 12
	22	00010110	16	variable speed zoom Wide: faster than 14
	24	00011000	18	variable speed zoom Wide: faster than 16
	26	00011010	1A	variable speed zoom Wide: faster than 18
	28	00011100	1C	variable speed zoom Wide: faster than 1A
	30	00011110	1E	variable speed zoom Wide: fastest speed
	33	00100001	21	grid (AVCHD)
	37	00100101	25	fader
	39	00100111	27	rec start (DV, some cameras)
	41	00101001	29	rec stop (DV, some cameras)
	48	00110000	30	variable speed zoom Tele (avoiding digital zoom, some cameras): slowest speed
	50	00110010	32	variable speed zoom Tele (avoiding digital zoom, some cameras): faster than 30
	52	00110100	34	variable speed zoom Tele (avoiding digital zoom, some cameras): faster than 32
	53	00110101	35	Zoom Tele slow (working all cameras since approx. 1996)
	54	00110110	36	variable speed zoom Tele (avoiding digital zoom, some cameras): faster than 34
	55	00110111	37	Zoom Wide slow (working all cameras since approx. 1996)
	56	00111000	38	variable speed zoom Tele (avoiding digital zoom, some cameras): faster than 36
	57	00111001	39	Zoom Tele fast (working all cameras since approx. 1996)
	58	00111010	3A	variable speed zoom Tele (avoiding digital zoom, some cameras): faster than 38
	59	00111011	3B	Zoom Wide fast (working all cameras since approx. 1996)
	60	00111100	3C	variable speed zoom Tele (avoiding digital zoom, some cameras): faster than 3A
	62	00111110	3E	variable speed zoom Tele (avoiding digital zoom, some cameras): fastest speed
	65	01000001	41	Auto-Focus on/off (not if there is a real switch at the camera)
	69	01000101	45	Focus manual far
	71	01000111	47	Focus manual near
	73	01001001	49	White balance toggle (only cameras until approx. 1996)
	75	01001011	4B	Backlight (not DV)
	81	01010001	51	Backlight (DV)
	83	01010011	53	Exposure auto/man. toggle (models of the early 90's)

Iris more close

	DEC	BIN	HEX	CODE_NAME
	85	01010101	55	Iris more open
	97	01100001	61	Shutter (models of the early 90's)
	119	01110111	77	White balance reset (not if white balance is selected via menu)
	133	10000101	85	Memory impose (models of the early 90's)
	135	10000111	87	Color / Mode (models of the early 90's)
	137	10001001	89	Superimpose (models of the early 90's)
	175	10101111	AF	Iris auto
	DEC	BIN	HEX	

Normal command to VTR or video camera | Type:(BIN 00011000 | HEX 18 | DEC 24)

	DEC	BIN	HEX	CODE_NAME
	0	00000000	00	program 1
	2	00000010	02	program 2
	4	00000100	04	program 3
	5	00000101	05	mode (only HDV/AVCHD)
	6	00000110	06	program 4
	8	00001000	08	program 5
	10	00001010	0A	program 6
	12	00001100	0C	program 7
	14	00001110	0E	program 8
	16	00010000	10	program 9
	18	00010010	12	program 0 (10: SL-HF950 MKII)
	20	00010100	14	program 11 (SL-HF950 MKII)
	22	00010110	16	enter, program 12 (SL-HF950 MKII)
	24	00011000	18	program 13
	26	00011010	1A	program 14
	28	00011100	1C	program 15
	30	00011110	1E	program 16
	32	00100000	20	program +
	34	00100010	22	program -
	36	00100100	24	
	38	00100110	26	
	40	00101000	28	x2
	42	00101010	2A	power (or viewfinder) off
	43	00101011	2B	photo write
	44	00101100	2C	eject
	46	00101110	2E	main/sub
	48	00110000	30	stop
	50	00110010	32	pause
	51	00110011	33	start/stop
	52	00110100	34	play
	53	00110101	35	tele (only CCD-V90)
	54	00110110	36	rew
	55	00110111	37	wide (only CCD-V90)
	56	00111000	38	fwd
	57	00111001	39	photo capture
	58	00111010	3A	rec
	60	00111100	3C	rec-pause (some devices)
	62	00111110	3E	
	64	01000000	40	still
	66	01000010	42	
	68	01000100	44	x1/10
	70	01000110	46	x1/5 (sometimes: vis. scan)
	72	01001000	48	
	74	01001010	4A	x14
	76	01001100	4C	x9
	78	01001110	4E	tracking auto/manual
	80	01010000	50	search -
	82	01010010	52	search +
	84	01010100	54	TV/VTR
	86	01010110	56	
	88	01011000	58	
	90	01011010	5A	VTR
	91	01011011	5B	date search / photo search / photo scan
	92	01011100	5C	
	94	01011110	5E	power off
	96	01100000	60	rev frame
	98	01100010	62	fwd frame
	100	01100100	64	
	101	01100101	65	edit-search -
	102	01100110	66	x1
	103	01100111	67	edit-search +
	104	01101000	68	
	105	01101001	69	rec-review (not i.e. TR-2200)
	106	01101010	6A	
	108	01101100	6C	sleep
	110	01101110	6E	tracking normal
	112	01110000	70	
	114	01110010	72	
	116	01110100	74	rew+play
	118	01110110	76	
	120	01111000	78	AUX
	122	01111010	7A	slow +
	123	01111011	7B	tape end search (HDV)
	124	01111100	7C	slow -
	126	01111110	7E	
	128	10000000	80	
	130	10000010	82	display mode
	132	10000100	84	menu up
	134	10000110	86	menu down
	136	10001000	88	tracking/fine +
	138	10001010	8A	tracking/fine -
	140	10001100	8C	counter reset
	142	10001110	8E	zero mem
	144	10010000	90	index mark
	146	10010010	92	index erase
	148	10010100	94	shuttle edit +
	150	10010110	96	shuttle edit -
	152	10011000	98	data code or goto
	153	10011001	99	data code or recording parameters
	154	10011010	9A	menu
	156	10011100	9C	
	158	10011110	9E	input select
	160	10100000	A0	
	162	10100010	A2	execute
	164	10100100	A4	quick timer
	166	10100110	A6	index
	168	10101000	A8	
	170	10101010	AA	
	172	10101100	AC	index search +, date search 01 (HDV)
	174	10101110	AE	index search -, date search -01 (HDV)
	176	10110000	B0	tape speed
	178	10110010	B2	goto zero / tape return (not DV)
	180	10110100	B4	counter display, data screen
	182	10110110	B6	open/close (SL-HF950), replay (FauHaEss)
	184	10111000	B8	timer display
	186	10111010	BA	
	188	10111100	BC	
	189	10111101	BD	date display off
	190	10111110	BE	
	191	10111111	BF	date display on
	192	11000000	C0	timer set
	194	11000010	C2	menu right, next
	196	11000100	C4	menu left
	198	11000110	C6	timer clear
	200	11001000	C8	timer check
	202	11001010	CA	timer record
	204	11001100	CC	
	206	11001110	CE	
	208	11010000	D0	audio dub
	210	11010010	D2	
	212	11010100	D4	edit assemble
	214	11010110	D6	edit mark
	216	11011000	D8	synchro edit
	218	11011010	DA	
	220	11011100	DC	digital off (VCR), print (DV)
	222	11011110	DE	speed +
	224	11100000	E0	speed -
	226	11100010	E2	stop motion
	228	11100100	E4	
	230	11100110	E6	
	232	11101000	E8	channel scan / flash motion
	234	11101010	EA	
	236	11101100	EC	voice boost
	238	11101110	EE	
	240	11110000	F0	
	242	11110010	F2	
	244	11110100	F4	
	246	11110110	F6	
	248	11111000	F8	digital scan
	250	11111010	FA	high-speed-rew
	252	11111100	FC	still/shuttle (EV-S880)
	254	11111110	FE	

Normal command to still video camera | Type:(BIN 00011110 HEX 1E DEC 30)

	DEC	BIN	HEX	CODE_NAME
	1	00000001	01	variable speed zoom Tele: slowest speed
	3	00000011	03	variable speed zoom Tele: faster than 01
	5	00000101	05	variable speed zoom Tele: faster than 03
	7	00000111	07	variable speed zoom Tele: faster than 05
	9	00001001	09	variable speed zoom Tele: faster than 07
	11	00001011	0B	variable speed zoom Tele: faster than 09
	13	00001101	0D	variable speed zoom Tele: faster than 0B
	15	00001111	0F	variable speed zoom Tele: fastest speed
	17	00010001	11	variable speed zoom Wide: slowest speed
	19	00010011	13	variable speed zoom Wide: faster than 11
	21	00010101	15	variable speed zoom Wide: faster than 13
	23	00010111	17	variable speed zoom Wide: faster than 15
	25	00011001	19	variable speed zoom Wide: faster than 17
	27	00011011	1B	variable speed zoom Wide: faster than 19
	29	00011101	1D	variable speed zoom Wide: faster than 1B
	31	00011111	1F	variable speed zoom Wide: fastest speed
	82	01010010	52	photo preview
	88	01011000	58	photo save (or in movie mode: start-stop)
	94	01011110	5E	power off
	148	10010100	94	Zoom Tele slow
	150	10010110	96	Zoom Wide slow
	152	10011000	98	Zoom Tele fast
	154	10011010	9A	Zoom Wide fast
				
				
				
				

Orig source code
http://www.next-zero.com/Lib/LANC-RemCon/001.html
