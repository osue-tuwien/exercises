# exercises

The pool of OSUE exercises. Assignments/specifications are maintained here.

Topics include (but are not limited to):
* C programming basics
* Sockets
* Process creation (fork, exec)
* Pipes
* Semaphores
* Shared memory

## building

To generate the pdf documents, a latex installation is required.
The script `genpdfs.sh` is provided for convenience. It runs latex
for all .tex files it finds in the current working directory and below
(changing into the respective directory).
