# pandemic-simulation
 In this Project I have simulated a laboratory experiment as a life game. We have a habitat that contains randomly distributed entities. In this experiment our habitat will be a NxN square place. Each entity has 5 different gates which can be named from { A,B,C,D,E,F,G,H } set. The Spreading V can infect an entity if the entity has A or B gate. If the entity has 3 gates which are named as A,B,C,D than this entity will die after 14 turns otherwise it will recover and get immune to Spreading V. after 30 turns. Dead entities stay in habitat for five turns and be infectious. They can not move. Spreading V can infect from one entity to other if they are closer than 3 units (in square form). An entity becomes infectious after 3 turn. Our simulation will take the start information from input.txt file which is in the same file withour executable. This file include information about habitat constants, entities and their movements in turns. Thsimulation writes an output.txt file which will show the infected and died entities and last situation of the habitat. Also, after each turn I have filled another file “turns.txt”. This file shows a brief outcome for each turn. An example of the input and output files are in the file same with our executable. My application does not include any console input command. My app directly read the input file, generate output.txt and turns.txt files and close itself silently.


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
