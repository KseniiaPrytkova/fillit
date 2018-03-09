Alexey Leonidovich Pajitnov created Tetris with the help of Dmitry Pavlovsky and Vadim Gerasimov in 1984. The game, first available in the Soviet Union, appeared in the West in 1986.

Fillit is not about recoding Tetris, even if it’s still a variant of this game. My program is taking a file as parameter, which contains a list of Tetriminos, and arrange them in order to create the smallest square possible.
Obviously, the main goal is to find the smallest square in the minimal amount of time, despite an exponentially growing number of possibilities each time a piece is added.

To explore how the program works follow this simple steps in your terminal (you should be in the folder with the project):
1. $> make
2. $> ./fillit valid_sample.fillit
and here is the result:
3. $> ABBBB.
	  ACCCEE
	  AFFCEE
	  A.FFGG
	  HHHDDG
	  .HDD.G

To identify each Tetrimino in the square solution, a capital letter was assigned to each Tetrimino, starting with ’A’ and increasing for each new Tetrimino.
In file 'Tetriminos' there are all variants of figures, that can enter the program. No rotation is possible on a Tetrimino.

If the file contains at least one error, the program will display error on the standard output followed by a newline and will exit properly.

Example:
$> cat test_1.fillit | cat -e
....$
##..$
.#..$
.#..$
$
....$
####$
....$
....$
$
#...$
###.$
....$
....$
$
....$
##..$
.##.$
....$
$> ./fillit test_1.fillit | cat -e
DDAA
CDDA
CCCA
BBBB
$>