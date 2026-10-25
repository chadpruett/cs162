# CS162 Assignment 2: shared image starting point

Start with p1commented.cpp and test.ppm. Build and run in this directory:

    g++ -std=c++17 -Wall -Wextra p1commented.cpp -o p1-demo
    ./p1-demo

The historical filename test.ppm contains a P1 (black-and-white) image.
P1 uses 0 for white and 1 for black. The file's first token identifies its format.
The starter prints inverted pixels; it does not write a complete image file
and intentionally leaves memory cleanup unfinished.

pikachu.ppm is a P3 color image for the later stages of the assignment.
Keep the originals and write transformed images to different filenames.
Read the Assignment 2 instructions in D2L for the class and ownership requirements.

Source: shared CS161B P1 teaching example; Pikachu input from the saved CS162
course repository (commit 99f06c5505a191463116f5c0db01b3f5142d0fea, week1/pikachu.ppm).
