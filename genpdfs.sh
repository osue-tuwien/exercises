#!/bin/bash

START=$(pwd)

for file in $(find . -name "*.tex"); do
   cd $(dirname ${file})
   BASENAME=$(basename ${file})

   for  (( i = 0 ; i < 3 ; ++i )); do pdflatex ${BASENAME}; done
   # or the cooler latexmk
   #latexmk -pdf ${BASENAME}

   cd ${START}
done
