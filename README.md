# pandemic-simulation
 In this Project I have simulated a laboratory experiment as a life game. We have a habitat that contains randomly distributed entities. In this experiment our habitat will be a NxN square place. Each entity has 5 different gates which can be named from { A,B,C,D,E,F,G,H } set. The Spreading V can infect an entity if the entity has A or B gate. If the entity has 3 gates which are named as A,B,C,D than this entity will die after 14 turns otherwise it will recover and get immune to Spreading V. after 30 turns. Dead entities stay in habitat for five turns and be infectious. They can not move. Spreading V can infect from one entity to other if they are closer than 3 units (in square form). An entity becomes infectious after 3 turn. Our simulation will take the start information from input.txt file which is in the same file withour executable. This file include information about habitat constants, entities and their movements in turns. Thsimulation writes an output.txt file which will show the infected and died entities and last situation of the habitat. Also, after each turn I have filled another file “turns.txt”. This file shows a brief outcome for each turn. An example of the input and output files are in the file same with our executable. My application does not include any console input command. My app directly read the input file, generate output.txt and turns.txt files and close itself silently.

Example of Input File:

size 22
turn_count 51
entity 1 FADCG 10x20
entity 2 DDGCB 4x21
entity 3 FDDCG 15x22
entity 4 ABCAG 1x16 infected
entity 5 EBAED 9x8 infected
entity 6 BFCBA 16x14
entity 7 EBCAG 13x9
entity 8 FDEDG 10x15
entity 9 DDAFG 2x21 infected
entity 10 BDAAD 18x18 infected
entity 11 EAFEF 14x6
entity 12 EGEFD 7x8
entity 13 AAAGG 11x19
entity 14 AFECE 3x17 infected
entity 15 DEGFF 1x2
entity 16 BCEBC 5x13
entity 17 CEBBE 19x20 infected
entity 18 FCAEB 13x17 infected
entity 19 BGFCC 18x13 infected
entity 20 ABFDF 19x1 infected
entity 21 AEDFA 20x21
turn 1 9x20 5x21 14x22 1x16 9x9 17x14 12x9 10x14 2x20 18x17 14x5 7x7 11x18 2x17 2x2 5x12 19x19 13x16 18x12 19x1 21x21 
turn 2 10x20 4x21 15x22 1x15 8x9 16x14 13x9 9x14 3x20 19x17 13x5 8x7 11x17 2x16 2x3 5x13 19x18 13x15 18x13 19x1 21x21 
turn 3 10x21 4x21 16x22 1x16 9x9 17x14 13x10 9x13 2x20 18x17 14x5 9x7 10x17 1x16 1x3 4x13 20x18 12x15 18x14 20x1 21x20 
turn 4 10x21 4x20 15x22 1x17 9x8 17x13 13x11 10x13 2x21 17x17 14x6 10x7 10x16 2x16 1x3 3x13 20x19 12x16 17x14 21x1 21x20 
turn 5 9x21 5x20 16x22 1x16 9x9 17x14 13x12 9x13 2x21 18x17 14x7 10x8 10x17 1x16 1x4 2x13 20x20 13x16 17x15 20x1 21x21 
turn 6 9x21 6x20 17x22 1x15 8x9 16x14 13x11 9x12 1x21 18x16 14x6 10x7 10x18 2x16 2x4 1x13 20x19 13x15 18x15 20x1 21x21 
turn 7 9x21 6x21 17x22 1x14 9x9 16x13 13x12 8x12 1x20 17x16 13x6 10x8 11x18 2x15 2x5 1x14 20x20 14x15 19x15 21x1 21x21 
turn 8 9x20 6x20 18x22 1x13 9x10 16x12 14x12 9x12 1x20 17x15 12x6 9x8 11x19 2x14 3x5 1x15 20x19 15x15 18x15 21x2 21x20 
turn 9 9x19 6x19 18x21 1x13 8x10 15x12 14x13 8x12 1x21 16x15 12x7 10x8 10x19 1x14 4x5 1x16 20x18 15x16 18x14 21x3 21x21 
turn 10 8x19 5x19 18x21 2x13 8x9 14x12 14x12 9x12 1x21 16x14 12x6 11x8 11x19 1x14 3x5 1x15 19x18 15x15 18x15 20x3 21x21 
turn 11 7x19 5x20 19x21 2x14 8x8 15x12 14x13 10x12 1x21 15x14 11x6 11x7 10x19 1x14 3x6 2x15 19x19 16x15 17x15 19x3 21x21 
turn 12 6x19 5x19 18x21 2x15 7x8 14x12 14x14 10x11 1x21 16x14 10x6 10x7 11x19 1x14 3x7 3x15 20x19 16x14 17x14 19x2 21x20 
turn 13 6x18 4x19 19x21 1x15 8x8 15x12 14x13 10x12 1x20 16x13 10x5 9x7 12x19 1x15 3x8 3x14 20x20 15x14 18x14 19x3 21x19 
turn 14 5x18 4x20 19x20 2x15 7x8 15x11 13x13 10x11 1x20 17x13 11x5 8x7 12x20 2x15 4x8 3x13 20x21 15x15 17x14 20x3 20x19 
turn 15 5x19 4x21 18x20 3x15 6x8 14x11 13x12 9x11 1x20 17x12 11x4 8x6 13x20 3x15 5x8 4x13 21x21 14x15 17x15 21x3 20x18 
turn 16 5x18 4x20 18x19 4x15 6x7 14x12 13x13 9x12 1x20 16x12 11x5 8x5 12x20 3x14 5x9 4x12 20x21 14x14 17x16 21x4 20x17 
turn 17 6x18 5x20 18x18 3x15 5x7 13x12 13x12 9x13 1x19 16x11 11x6 8x6 13x20 3x15 6x9 4x13 20x21 13x14 17x17 20x4 19x17 
turn 18 6x19 5x21 18x19 2x15 4x7 14x12 13x11 9x12 1x19 16x10 11x7 7x6 13x19 4x15 6x10 3x13 20x21 14x14 16x17 20x5 19x16 
turn 19 7x19 5x20 17x19 2x16 5x7 13x12 13x10 9x13 2x19 16x11 11x8 7x7 13x18 3x15 5x10 3x12 19x21 13x14 16x16 21x5 20x16 
turn 20 7x20 5x19 18x19 1x16 4x7 12x12 13x9 9x12 1x19 15x11 11x7 8x7 13x17 2x15 6x10 4x12 19x20 14x14 15x16 21x4 21x16 
turn 21 8x20 4x19 18x20 1x17 4x6 12x13 14x9 9x13 1x20 15x12 10x7 7x7 13x18 2x14 6x9 5x12 19x19 14x13 14x16 21x4 20x16 
turn 22 8x19 5x19 18x21 1x17 4x5 13x13 13x9 8x13 1x19 15x11 10x6 8x7 14x18 3x14 7x9 6x12 19x20 14x14 13x16 20x4 21x16 
turn 23 8x20 6x19 19x21 1x17 4x4 12x13 13x8 8x14 2x19 16x11 9x6 9x7 14x17 4x14 6x9 6x11 20x20 14x13 14x16 20x5 21x16 
turn 24 8x19 6x20 18x21 1x16 3x4 13x13 12x8 9x14 2x18 16x10 10x6 9x6 14x16 5x14 5x9 6x10 20x21 13x13 15x16 19x5 21x15 
turn 25 8x18 7x20 17x21 2x16 4x4 14x13 13x8 8x14 2x19 15x10 10x7 9x5 13x16 5x15 6x9 6x9 20x21 12x13 16x16 20x5 20x15 
turn 26 7x18 8x20 17x21 3x16 4x3 13x13 14x8 9x14 2x20 14x10 10x6 9x4 13x17 5x16 6x8 6x10 20x20 13x13 16x15 20x6 19x15 
turn 27 6x18 9x20 17x21 3x15 5x3 13x12 14x7 9x15 3x20 15x10 10x7 9x3 12x17 4x16 5x8 7x10 20x19 13x14 17x15 20x5 19x14 
turn 28 7x18 9x21 17x20 3x16 4x3 12x12 14x6 8x15 2x20 15x11 11x7 8x3 12x18 5x16 5x9 7x11 19x19 13x15 17x16 20x4 19x15 
turn 29 7x17 9x20 17x19 3x15 4x4 12x11 14x5 8x16 2x21 15x10 11x8 9x3 13x18 4x16 5x10 7x12 19x20 14x15 16x16 20x5 19x16 
turn 30 6x17 9x21 16x19 4x15 3x4 11x11 15x5 9x16 2x20 16x10 11x7 9x2 14x18 5x16 5x11 8x12 20x20 15x15 16x17 20x6 19x15 
turn 31 7x17 9x21 17x19 4x14 4x4 11x12 16x5 9x15 2x21 16x9 11x6 10x2 15x18 4x16 4x11 9x12 20x19 14x15 17x17 19x6 18x15 
turn 32 8x17 9x20 17x20 4x15 5x4 11x13 16x4 9x16 2x20 16x8 10x6 11x2 14x18 4x17 3x11 8x12 19x19 15x15 17x16 19x7 19x15 
turn 33 7x17 9x21 18x20 3x15 6x4 10x13 16x3 8x16 2x19 16x9 9x6 11x1 14x17 4x18 3x10 7x12 18x19 14x15 18x16 18x7 19x16 
turn 34 8x17 8x21 18x21 4x15 7x4 10x14 16x4 7x16 3x19 16x8 8x6 11x1 14x18 5x18 3x9 6x12 18x20 13x15 18x17 17x7 20x16 
turn 35 9x17 9x21 18x21 4x14 6x4 10x13 17x4 7x17 4x19 17x8 8x7 10x1 13x18 4x18 4x9 6x11 17x20 13x16 17x17 17x6 20x15 
turn 36 8x17 9x21 19x21 4x15 5x4 10x12 17x5 8x17 5x19 16x8 8x8 10x2 12x18 3x18 3x9 6x10 16x20 14x16 18x17 16x6 20x14 
turn 37 9x17 9x21 19x20 3x15 5x5 10x13 18x5 7x17 6x19 16x7 9x8 10x3 11x18 2x18 4x9 7x10 16x21 14x17 18x18 15x6 21x14 
turn 38 8x17 9x20 20x20 3x14 4x5 11x13 18x6 6x17 5x19 16x6 10x8 10x2 11x19 2x17 5x9 7x9 16x21 13x17 18x17 15x5 21x14 
turn 39 7x17 9x21 19x20 4x14 5x5 12x13 19x6 5x17 5x20 16x5 9x8 10x1 11x18 2x18 4x9 7x10 16x21 13x16 18x18 16x5 21x15 
turn 40 6x17 10x21 19x21 3x14 6x5 12x14 19x7 5x18 6x20 16x6 9x7 10x2 11x19 1x18 3x9 8x10 17x21 13x17 18x17 15x5 21x15 
turn 41 5x17 10x20 19x21 4x14 6x4 13x14 20x7 6x18 7x20 15x6 9x6 10x1 11x18 1x18 2x9 8x11 16x21 13x18 17x17 15x4 21x15 
turn 42 5x16 10x21 19x21 4x15 5x4 13x15 20x8 6x17 8x20 14x6 9x7 10x1 11x19 2x18 2x8 9x11 16x20 13x19 16x17 15x5 20x15 
turn 43 6x16 10x21 19x20 4x14 6x4 13x16 19x8 6x16 9x20 13x6 9x8 11x1 11x18 2x19 3x8 9x10 15x20 14x19 15x17 14x5 20x14 
turn 44 6x17 11x21 19x21 4x15 6x5 14x16 20x8 7x16 8x20 12x6 9x7 11x2 10x18 1x19 4x8 10x10 16x20 15x19 16x17 14x6 20x15 
turn 45 6x16 11x21 20x21 3x15 6x6 14x15 19x8 7x15 9x20 11x6 9x6 11x1 10x17 1x20 4x9 10x9 17x20 15x20 16x18 14x7 21x15 
turn 46 7x16 11x21 20x21 4x15 5x6 14x16 20x8 7x16 8x20 11x5 9x7 12x1 10x18 1x20 5x9 11x9 17x21 15x21 16x17 13x7 21x15 
turn 47 7x17 11x20 19x21 4x16 4x6 15x16 21x8 7x17 9x20 11x6 10x7 12x2 10x19 1x19 4x9 10x9 17x21 14x21 16x18 13x8 21x14 
turn 48 6x17 10x20 19x20 4x15 4x5 16x16 21x7 8x17 9x19 12x6 10x6 12x3 11x19 1x20 4x8 11x9 17x20 14x20 16x17 13x9 21x15 
turn 49 7x17 10x19 19x19 3x15 4x4 17x16 20x7 9x17 8x19 13x6 10x7 12x4 10x19 1x21 5x8 11x10 17x19 14x21 16x16 12x9 21x15 
turn 50 6x17 11x19 19x18 2x15 5x4 16x16 19x7 9x18 7x19 14x6 10x8 12x5 10x18 1x21 6x8 11x9 17x18 13x21 15x16 12x8 21x16 
turn 51 7x17 11x18 20x18 1x15 4x4 15x16 20x7 9x17 7x18 14x5 10x9 12x6 9x18 2x21 6x7 10x9 17x19 12x21 16x16 13x8 21x15 


Example of Output File:

Normal    :12
Infected  :9
Dead      0
Recovered :0
entity 1 7x17 normal
entity 2 11x18 normal
entity 3 20x18 normal
entity 4 1x15 infected
entity 5 4x4 infected
entity 6 15x16 normal
entity 7 20x7 normal
entity 8 9x17 normal
entity 9 7x18 infected
entity 10 14x5 infected
entity 11 10x9 normal
entity 12 12x6 normal
entity 13 9x18 normal
entity 14 2x21 infected
entity 15 6x7 normal
entity 16 10x9 normal
entity 17 17x19 infected
entity 18 12x21 infected
entity 19 16x16 infected
entity 20 13x8 infected
entity 21 21x15 normal
